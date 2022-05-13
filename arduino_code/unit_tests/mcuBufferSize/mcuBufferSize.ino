char buffer[64]; // messages may only be 64 characters long

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  if(Serial.availableForWrite() > 2) {
    sprintf(buffer, "%d %s|", Serial.availableForWrite(), buffer);
    Serial.println(buffer);
  }
}
