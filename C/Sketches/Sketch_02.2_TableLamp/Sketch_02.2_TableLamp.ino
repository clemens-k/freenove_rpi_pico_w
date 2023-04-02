/**********************************************************************
  Filename    : TableLamp
  Description : Make a table lamp
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#define PIN_REDLED 15
#define PIN_BUTTON 13
bool ledState = false;

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
    delay(20);
    if (digitalRead(PIN_BUTTON) == LOW) {
      reverseGPIO(PIN_REDLED);
    }
    while (digitalRead(PIN_BUTTON) == LOW);
  }
}

void reverseGPIO(int pin) {
  ledState = !ledState;
  digitalWrite(pin, ledState);
}
