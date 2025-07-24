#include "AqiReceiverModule.h"
#include <string.h>  
#include <Arduino.h>  
#include <WiFi.h>
#include <HTTPClient.h>
#include "MeshService.h"

const char* ssid = "TANTRA";
const char* password = "SK0029101978";

const char* serverBaseUrl = "http://192.168.1.41:5000";

bool wifiConnected = false;
void sendToHTTP(String aqi, String deviceID) {
    if (!wifiConnected) {
        LOG_INFO("Not connected");
        return;
    }

    HTTPClient http;
    String url = String(serverBaseUrl) + "/" + aqi + "/" + deviceID;
    http.begin(url);

    int httpCode = http.GET();

    if (httpCode > 0) {
        LOG_INFO("HTTP GET successful, code: %d", httpCode);
    } else {
        LOG_INFO("HTTP GET failed, error: %s", http.errorToString(httpCode).c_str());
    }

    http.end();
}

void connectWiFi() {
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    int retries = 0;
    while (WiFi.status() != WL_CONNECTED && retries < 20) {
        delay(500);
        Serial.print(".");
        retries++;
    }
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi connected!");
        wifiConnected = true;
    } else {
        Serial.println("\nFailed to connect to WiFi");
        wifiConnected = false;
    }
}

AqiReceiverModule::AqiReceiverModule()
    : SinglePortModule("aqi_receiver", PORTNUM_AQI_MODULE) {
    connectWiFi();
}

ProcessMessage AqiReceiverModule::handleReceived(const meshtastic_MeshPacket &mp) {
    int len = mp.decoded.payload.size;
    char buf[64];
    if (len >= sizeof(buf)) len = sizeof(buf) - 1;  
    memcpy(buf, mp.decoded.payload.bytes, len);
    buf[len] = '\0';

    LOG_INFO("Received AQI: %s", buf);

    if (wifiConnected) {
        sendToHTTP(String(buf), String(mp.from));  
    } else {
        LOG_INFO("WiFi not connected. Skipping HTTP request.");
    }

    return ProcessMessage::STOP;
}


