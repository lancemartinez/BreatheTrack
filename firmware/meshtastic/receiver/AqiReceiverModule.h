#pragma once

#include "SinglePortModule.h"
#include "Router.h"

#define PORTNUM_AQI_MODULE meshtastic_PortNum_PRIVATE_APP

class AqiReceiverModule : public SinglePortModule {
public:
    AqiReceiverModule();

protected:
    virtual ProcessMessage handleReceived(const meshtastic_MeshPacket &mp) override;
};