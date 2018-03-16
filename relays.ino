#include <SoftwareSerial.h>


SoftwareSerial myRelay(10, 11);

unsigned char ucBitPattern = 0xFF; //off is 1

void REL_vSwitch( unsigned char ucBit, unsigned char ucState){
  myRelay.write( (byte) 0x51 );
  if( ucState == 0 ){
    ucBitPattern = bitSet ( ucBitPattern, ucBit );
  }else{
    ucBitPattern = bitClear( ucBitPattern, ucBit );
  }
  myRelay.write( (byte) ucBitPattern );
}

void REL_vInit(){
  myRelay.begin(9600);
  myRelay.write((byte)0x50);
}

void REL_vHandleTask(){
  
}

