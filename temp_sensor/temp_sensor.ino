#include <Wire.h>
#include "Protocentral_MAX30205.h"
MAX30205 tempSensor;

void setup() {

  Serial.begin(9600);
  Wire.begin();

  //scan for temperature in every 3 sec untill a sensor is found. Scan for both addresses 0x48 and 0x49
  while(!tempSensor.scanAvailableSensors()){
    Serial.println("Couldn't find the temperature sensor, please connect the sensor." );
    delay(3000);  
  }

  tempSensor.begin();   // set continuos mode, active mode
} 

void loop() {

  float temp = tempSensor.getTemperature(); // read temperature for every 1000ms
  Serial.println(temp);
  delay(5000);
}
