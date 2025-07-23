#include "AqiModule.h"
#include "MeshService.h"
#include <Arduino.h>  

AqiModule::AqiModule()
    : SinglePortModule("aqi", PORTNUM_AQI_MODULE), concurrency::OSThread("aqi")
{
    setIntervalFromNow(10 * 1000);  
}

int32_t AqiModule::runOnce()
{
    int aqiValue = analogRead(7);  
    char buf[32];
    snprintf(buf, sizeof(buf), "AQI: %d", aqiValue);

    meshtastic_MeshPacket *p = allocDataPacket();
    if (p) {
        p->to = NODENUM_BROADCAST;
        p->decoded.payload.size = strlen(buf);
        memcpy(p->decoded.payload.bytes, buf, p->decoded.payload.size);
        p->priority = meshtastic_MeshPacket_Priority_DEFAULT;

        service->sendToMesh(p);

        LOG_INFO("Sent AQI reading: %s", buf);
    }

    return 10 * 1000;  
}
