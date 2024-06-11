#include <Arduino.h>
#include "stateMachine.h"

// defines
#define LED_RED_PIN PA7
#define LED_ORANGE_PIN PA6
#define LED_GREEN_PIN PA5

#define BTN_1_PIN PC7
#define BTN_2_PIN PA9
#define BTN_3_PIN PA8
#define BTN_4_PIN PB10

void pin_setup();
void check_button();
void check_state();

void setup() {
  // put your setup code here, to run once:
  pin_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  check_button();
  check_state();
}

// put function definitions here:
void pin_setup(){
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_ORANGE_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);

  pinMode(BTN_1_PIN, INPUT);
  pinMode(BTN_2_PIN, INPUT);
  pinMode(BTN_3_PIN, INPUT);
  pinMode(BTN_4_PIN, INPUT);
}

void check_button(){
  if (LOW == digitalRead(BTN_1_PIN))
  {
    stateMachine(INPUT1_ACCEPTED);
  }

  if (LOW == digitalRead(BTN_2_PIN))
  {
    stateMachine(INPUT2_ACCEPTED);
  }

  if (LOW == digitalRead(BTN_3_PIN))
  {
    stateMachine(INPUT3_ACCEPTED);
  }

  if (LOW == digitalRead(BTN_4_PIN))
  {
    stateMachine(INPUT_REFUSED);
  }
}

void check_state(){
  switch (state)
  {
  case SAFE_LOCKED:
    digitalWrite(LED_RED_PIN,HIGH);
    digitalWrite(LED_ORANGE_PIN, LOW);
    digitalWrite(LED_GREEN_PIN, LOW);
    break;
  case LEVEL1_UNLOCKED:
    digitalWrite(LED_RED_PIN,LOW);
    digitalWrite(LED_ORANGE_PIN, HIGH);
    digitalWrite(LED_GREEN_PIN, LOW);
    break;
  case LEVEL2_UNLOCKED:
    digitalWrite(LED_RED_PIN,LOW);
    digitalWrite(LED_ORANGE_PIN, HIGH);
    digitalWrite(LED_GREEN_PIN, HIGH);
    break;
  default:
    break;
  }
}