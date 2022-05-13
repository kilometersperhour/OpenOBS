/*
  Test strings for serial monitor
  $OPENOBS*4A
  $SET,1616605996,10*7E
*/

/*TODO

*/

/*LIBRARIES
 *  The first three libraries are included in standard Arduino IDE installations
 *  The last three libraries should be be downloaded from github and installed manually.
 *  Additionally, the Adafruit_ADS1015 library requires the Adafruit_I2CDevice library, if you do not already have it.
 */
#include <Wire.h>               //standard library
#include <SPI.h>                //standard library
#include <Adafruit_ADS1X15.h>   //Version 2.2.0  https://github.com/adafruit/Adafruit_ADS1X15

/*
 *  CONFIGURATION SETTINGS
 */
 
//firmware data
#define pVoltageDivider 4    //voltage divider
#define pIRED A3             //IR emitter
#define pChipSelect 10       //chip select pin for SD card

//communications vars
const int MAX_CHAR = 60;            //max num character in messages
char messageBuffer[MAX_CHAR];       //buffer for sending and receiving comms

//time settings
unsigned long millisTime;
long currentTime = 0;

//ADC vars
Adafruit_ADS1115 ads;
int gain;

/* SETUP
 *  try to establish coms with GUI
 *  initiate components
 *  wait for settings or use default
 *  create text file
 */

void setup() {
  delay(100); //allow power to stabilize

  //if anything writes to these before started, it will crash.
  Serial.begin(115200);
  Serial.setTimeout(50);
  Wire.begin();
  
  //initialize the ADC
  ads.setGain(GAIN_ONE); //reset gain
  ads.begin(0x48);  // Initialize ads1115
  ads.setDataRate(RATE_ADS1115_860SPS); //set the sampling speed
  ads.readADC_SingleEnded(0); //throw one reading away. Seems to come up bad.
  bool adc_init = ads.readADC_SingleEnded(0) != -1;
}

/* LOOP
 *  read sensor
 */

void loop() {
  /*
  digitalWrite(pVoltageDivider,HIGH);

  millisTime = millis();
  //background measurements
  digitalWrite(pIRED,LOW);

  //illuminated measurements
  digitalWrite(pIRED, HIGH); //turn on the IRED
  for (int i = 0; i < NUM_SAMPLES; i++) {
    gain = 1; 
    readBuffer = ads.readADC_SingleEnded(0);
    
    //occassionally print some data for inspection and to blink the TX lights.
    if ((i+1)%100==0){
      sprintf(messageBuffer,"%04u,%05d",i+1,readBuffer);
      Serial.println(messageBuffer);
    }
  }
  digitalWrite(pIRED, LOW); //turn off the IRED
  
  ~~ Vestigial relevant code to model new code by ~~
  */

  digitalWrite(pVoltageDivider,HIGH);

  millisTime = millis();
  //background measurements
  digitalWrite(pIRED,LOW);
  
  for (int i = 0; i < NUM_SAMPLES; i++) {
    gain = 1; 
    readBuffer = ads.readADC_SingleEnded(0);
    
    //occassionally print some data for inspection and to blink the TX lights.
    if ((i+1)%100==0){
      sprintf(messageBuffer,"%04u,%05d",i+1,readBuffer);
      Serial.println(messageBuffer);
    }
  }
  
}
