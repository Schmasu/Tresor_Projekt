#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

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

extern State_t state;

void stateMachine(Event_t event);

#endif  // STATE_MACHINE_H