//#include <SoftwareSerial.h>
#include <dht11.h>

dht11 dht;

int iOldTemp=0;
int iOldHum=0;

void DHT_vInit(void){
	//pinMode(LED1, OUTPUT);
//	dht.begin();
}

void DHT_vHandleTask(void){
	// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
	dht.read(4);
  if( dht.temperature > 10 && dht.temperature < 100 ){
    if( dht.humidity > 5 && dht.humidity < 100 ){    
       if( iOldTemp != dht.temperature || iOldHum !=  dht.humidity ){
        iOldTemp = dht.temperature;
        iOldHum = dht.humidity;
        Serial.print("humidity ");
        Serial.println(dht.humidity);
        Serial.print("temperature ");
        Serial.println(dht.temperature);    
      }
    }
  }
}
