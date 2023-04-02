/**********************************************************************
* Filename    : Blink
* Description : Make an led blinking.
* Auther      : www.freenove.com
* Modification: 2021/10/13
**********************************************************************/
#define EXTRA_LED 15

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(EXTRA_LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(EXTRA_LED, HIGH);
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(EXTRA_LED, LOW);
  delay(500);                       // wait for a second
}
