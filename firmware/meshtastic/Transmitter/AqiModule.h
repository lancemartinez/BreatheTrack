#pragma once
#include "SinglePortModule.h"
#include "Router.h"
#include "concurrency/OSThread.h" 

#define PORTNUM_AQI_MODULE meshtastic_PortNum_PRIVATE_APP

class AqiModule : public SinglePortModule, private concurrency::OSThread
{
public:
    AqiModule();

protected:
    virtual int32_t runOnce() override; 
};
