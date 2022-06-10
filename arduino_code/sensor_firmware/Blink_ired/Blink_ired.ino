/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#define pIRED A3
#define pLED02 2
#define pLED03 3

boolean ired = false;
boolean led02 = true;
boolean led03 = true;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pIRED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if (ired) {
    digitalWrite(pIRED, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  if (led02) {
    digitalWrite(pLED02, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  if (led03) {
    digitalWrite(pLED03, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  
  delay(5000);                       // wait for a moment
  
  if (ired) {
    digitalWrite(pIRED, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  if (led02) {
    digitalWrite(pLED02, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  if (led03) {
    digitalWrite(pLED03, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(5000);                       // wait for a moment
}
