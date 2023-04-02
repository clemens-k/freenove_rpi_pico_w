/**********************************************************************
  Filename    : FlowingLight
  Description : Using ledbar to demonstrate flowing lamp.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#include <vector>

using namespace std;

const vector<int> ledPins {16, 17, 18, 19, 20, 21, 22, 26, 27, 28};
const int PIN_REDLED {15};
const int PIN_BUTTON {13};

bool redLedState {false};

void setup() {
  pinMode(PIN_REDLED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  for (const auto& pin: ledPins) {
    pinMode(pin, OUTPUT);
  }

  // short LED pulse to indicate "setup OK"
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
}


void tableLamp_10ms() {
  static int debcnt {0};
  const int debmax {10};
  const int debthres {2}; 
  
  if (digitalRead(PIN_BUTTON) == LOW) {
    if (debcnt == debthres) {
      redLedState = !redLedState;
      digitalWrite(PIN_REDLED, redLedState);
    } 
    if (debcnt < debmax) 
      debcnt++;
  } else {
    debcnt = 0;
  }
}


void flowingLight_10ms(){
  static int cnt {0};
  const int cntmax {20};

  static size_t i {0};
  const size_t imax {ledPins.size()};

  static bool incr {true};

  if (cnt < cntmax)
    cnt++;
  else {
    digitalWrite(ledPins[i], LOW);
    if (incr) {
      i++;
      if (i == imax)
        incr = false;
    } else {
      i--;
      if (i == 0)
        incr = true;
    }
    digitalWrite(ledPins[i], HIGH);
    cnt = 0;
  }
}


void loop() {
  tableLamp_10ms();
  flowingLight_10ms();
  delay(10);
}
