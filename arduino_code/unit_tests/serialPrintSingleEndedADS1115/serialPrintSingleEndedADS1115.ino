#include <Wire.h>
#include <Adafruit_ADS1X15.h>

#define pIRED A3
#define pLED02 2
#define pLED03 3


Adafruit_ADS1115 ads1115;

void setup(void)
{
  Serial.begin(115200);
  Serial.println("ADC0, ADC1, ADC2, ADC3, Single ended readings where ADC Range: +/- 6.144V (1 bit = 3mV)");
  // Serial.println("millis/6000, ADC0, ADC1, ADC2, ADC3, Single ended readings where ADC Range: +/- 6.144V (1 bit = 3mV)");
  ads1115.begin();
  pinMode(pLED02, INPUT); // for reading which LEDs are on inside the testbench
  pinMode(pLED03, INPUT); // these signals come as digital outputs from the other arduino's transistor toggling pin
}

void loop(void)
{
  char mySerialBuffer[31];
  int16_t adc0, adc1, adc2, adc3;
  byte led02status, led03status;
  

  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);
  adc2 = ads1115.readADC_SingleEnded(2);
  adc3 = ads1115.readADC_SingleEnded(3);
  led02status = digitalRead(pLED02);
  led03status = digitalRead(pLED03);
  
  sprintf(mySerialBuffer,"%05d,%05d,%05d,%05d,%05d",((led02status*1)|(led03status*2)),adc0,adc1,adc2,adc3);
  // sprintf(mySerialBuffer,"%05d,%05d,%05d,%05d,%05d",millis()/6000,adc0,adc1,adc2,adc3);
  Serial.println(mySerialBuffer); 
  Serial.print("For prev. message: LED02 status is "); Serial.print(led02status);Serial.print(". LED03 status is ");Serial.print(led03status); Serial.println("."); 
  
  delay(25);
}
