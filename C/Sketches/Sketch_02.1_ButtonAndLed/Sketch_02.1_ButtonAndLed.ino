/**********************************************************************
* Filename    : ButtonAndLed
* Description : Use a button to control LED light
* Auther      : www.freenove.com
* Modification: 2021/10/13
**********************************************************************/

#define PIN_REDLED    15
#define PIN_BUTTON 13

void setup() {
  // initialize digital pin PIN_LED as an output.
  pinMode(PIN_REDLED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  
  
  // short LED pulse to indicate "setup OK"
  pinMode(LED_BUILTIN, OUTPUT);
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(PIN_BUTTON) == LOW) {
    digitalWrite(PIN_REDLED,HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(PIN_REDLED,LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
