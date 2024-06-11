#include "stateMachine.h"

// globale Variablen
State_t state = SAFE_LOCKED;

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