#include "arduino_secrets.h"
/* 
  
  The following variables are automatically generated and updated when changes are made to the Thing

  CloudPercentage moisture;

 
*/

#include "thingProperties.h"
int _moisture,sensor_analog;
const int sensor_pin = 6; 

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  sensor_analog = analogRead(sensor_pin);
  moisture = (  ( (sensor_analog/4095.00) * 100 ) );
  Serial.print("moisture = ");
  Serial.print( moisture);  /* Print Temperature on the serial window */
  Serial.println("%");
  delay(1000);     
  
  
}


/*
  Since Moisture is READ_WRITE variable, onMoistureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMoistureChange()  {
  // Add your code here to act upon Moisture change
}


