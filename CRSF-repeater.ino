
#include "CRSF.h"


#define SERIAL_BAUDRATE                400000

CRSF crsf;

uint16_t currentChannels[CRSF_MAX_CHANNEL];

void setup() {
  crsf.begin(&Serial, SERIAL_BAUDRATE);

  crsf.onDataReceived([](const uint16_t channels[CRSF_MAX_CHANNEL]) {
    char buffer[100];
    memcpy(currentChannels, channels, CRSF_MAX_CHANNEL);
  });
}

void loop() {
  crsf.sendChannels(currentChannels);
}

void serialEvent() {
  crsf.readPacket();
}