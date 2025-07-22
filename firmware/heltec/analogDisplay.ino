#include <Wire.h>               
#include "HT_SSD1306Wire.h"

static SSD1306Wire  display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED); 
const int analogPin = 7;
#define DEMO_DURATION 3000
typedef void (*Demo)(void);

int demoMode = 0;
int counter = 1;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  VextON();
  delay(100);
  display.init();
  display.setFont(ArialMT_Plain_24);
}

void VextON(void)
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
}

void VextOFF(void) 
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, HIGH);
}

void readDisplayAQI(){
  int analogValue = analogRead(analogPin);
  Serial.print("Analog Value: ");
  Serial.println(analogValue);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 26, String(analogValue)); 

}
Demo demos[] = {readDisplayAQI};
int demoLength = (sizeof(demos) / sizeof(Demo));
long timeSinceLastModeSwitch = 0;

void loop() {
  display.clear();
  demos[0]();
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(10, 128, String(millis()));
  display.display();
  delay(1000);

}

