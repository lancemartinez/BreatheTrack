#include <WiFi.h>
#include <HTTPClient.h>

#define RED_PIN 4
#define GREEN_PIN 16
#define BLUE_PIN 17
#define ANALOG_PIN A0

#define PWM_FREQ 5000
#define PWM_RESOLUTION 8

const char* ssid = "";
const char* password = "";
const char* serverUrl = ""

int previousAnalogValue = 0;
int threshold = 100;
int red = 0;
int green = 255;
int blue = 255;

unsigned long lastSendTime = 0;
unsigned long sendInterval = 60000;

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) delay(500);
    ledcAttach(RED_PIN, PWM_FREQ, PWM_RESOLUTION);
    ledcAttach(GREEN_PIN, PWM_FREQ, PWM_RESOLUTION);
    ledcAttach(BLUE_PIN, PWM_FREQ, PWM_RESOLUTION);
}

void sendAnalog(int value) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverUrl);
        http.addHeader("Content-Type", "application/json");
        String json = "{\"analog_value\":" + String(value) + "}";
        http.POST(json);
        http.end();
    }
}

void loop() {
    int analogValue = analogRead(ANALOG_PIN);

    if (abs(analogValue - previousAnalogValue) > threshold) {
        for (int x = 0; x < 255; x++) {
            if (green > 0) green--;
            if (blue > 0) blue--;
            if (red < 255) red++;
            ledcWrite(RED_PIN, red);
            ledcWrite(GREEN_PIN, green);
            ledcWrite(BLUE_PIN, blue);
            delay(10);
        }
        sendAnalog(analogValue);
    } else {
        red = map(analogValue, 0, 4095, 0, 255);
        green = map(analogValue, 0, 4095, 255, 0);
        blue = map(analogValue, 0, 4095, 128, 255);
    }

    ledcWrite(RED_PIN, red);
    ledcWrite(GREEN_PIN, green);
    ledcWrite(BLUE_PIN, blue);

    if (millis() - lastSendTime >= sendInterval) {
        sendAnalog(analogValue);
        lastSendTime = millis();
    }

    previousAnalogValue = analogValue;
    delay(100);
}