#include "AqiReceiverModule.h"
#include <string.h>  

AqiReceiverModule::AqiReceiverModule()
    : SinglePortModule("aqi_receiver", PORTNUM_AQI_MODULE) {
}

ProcessMessage AqiReceiverModule::handleReceived(const meshtastic_MeshPacket &mp) {
    const char* payload = (const char*)mp.decoded.payload.bytes;
    int len = mp.decoded.payload.size;

    char buf[64];
    memcpy(buf, payload, len);
    buf[len] = '\0';  

    LOG_INFO("Received AQI: %s", buf);

    return ProcessMessage::STOP;  
}