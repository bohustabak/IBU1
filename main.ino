
#include "relays.h"

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
  
}
