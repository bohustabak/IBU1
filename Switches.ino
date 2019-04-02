/*
  Example for receiving 433MHz codes from Chacon & Zap remotes using rc-switch library.
  /!\ Open your serial monitor and press any key of your RF Remote. 
  
  | Receiver   | Arduino
  |------------|---------
  | VCC        | 5V
  | GND        | GND
  | DATA       | 2 (digital)
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void SWT_vInit( void ){
  // Receiver on interrupt 0 => pin 3 on leonardo, pin 2 on Mega2560
  mySwitch.enableReceive(0); 
  // Optional set pulse length.
  mySwitch.setPulseLength(300);
  // Optional set number of transmission repetitions.
  mySwitch.setRepeatTransmit(5);
}

void SWT_vHandleTask( void ){
  unsigned long Prijem;
  if (mySwitch.available()) {
    Prijem = mySwitch.getReceivedValue();
    Serial.print(mySwitch.getReceivedValue(), HEX);
    Serial.println();
    Serial.print( mySwitch.getReceivedBitlength());
    Serial.println();
    if( Prijem == 0x005B7734 ){
        Serial.print( "Trada");   Serial.println();
    }
//    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
 }
}


