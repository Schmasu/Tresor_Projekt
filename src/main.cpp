#include <Arduino.h>

// put function declarations here:
typedef enum{
  SAFE_LOCKED,
  LEVEL1_UNLOCKED,
  LEVEL2_UNLOCKED,
  LEVEL3_UNLOCKED,
  SAFE_OPEN,
}State_t;

typedef enum{
  INPUT1_ACCEPTED,
  INPUT2_ACCEPTED,
  INPUT3_ACCEPTED,
  INPUT_REFUSED,
  OPEN_DOOR,
  CLOSE_DOOR,
}Event_t;

State_t state;
Event_t event;

void stateMachine(Event_t event);

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  State_t state = SAFE_LOCKED;
  stateMachine(event);
}

// put function definitions here:
void stateMachine(Event_t event) {
  switch(state){
    case SAFE_LOCKED:
    if(INPUT1_ACCEPTED == event){
      state = LEVEL1_UNLOCKED;
    }
    else if(INPUT_REFUSED == event){
      state = SAFE_LOCKED;
    }
    break;
    case LEVEL1_UNLOCKED:
    if(INPUT2_ACCEPTED == event){
      state = LEVEL2_UNLOCKED;
    }
    else if(INPUT_REFUSED == event){
      state = SAFE_LOCKED;
    }
    break;
    case LEVEL2_UNLOCKED:
    if(INPUT3_ACCEPTED == event){
      state = LEVEL3_UNLOCKED;
    }
    else if(INPUT_REFUSED == event){
      state = SAFE_LOCKED;
    }
    break;
    case LEVEL3_UNLOCKED:
    if(OPEN_DOOR == event){
      state = SAFE_OPEN;
    }
    break;
    case SAFE_OPEN:
    if(CLOSE_DOOR == event){
      state = SAFE_LOCKED;
    }
    break;
  }
}