
//#include "dht.h"
#include "relays.h"
//#include "Switches.h"


void setup() {
  //enable serial monitor
  Serial.begin(9600);
  SWT_vInit();
  DHT_vInit();
  REL_vInit();
}
void loop() {
  SWT_vHandleTask();
  DHT_vHandleTask();
  REL_vSwitch( REL_L220_TOILET, 1 );
  STM_vHandleTask();
}


tTransition TransBulbOn[] = {
  {EV_BUT_P_01, &FSM_Always, DoNothing, &BulbOn},
}

tState BulbOn = {
  DoNothing,
  DoNothing,
  &TransBulbOn,
  NoOfElements(TransBulbOn),
  NULL
}
