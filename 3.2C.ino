#include <BH1750FVI.h>

BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);
#include "thingProperties.h"
#include <Arduino.h

void setup() {

  Serial.begin(9600);
    LightSensor.begin();
  delay(1500); 
  
  initProperties();
 
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
  
  float intensity;
  intensity = LightSensor.GetLightIntensity();
  Serial.println(test);
  
  if(intensity > 500)
  {
    message = "Sunlight present";
    delay(1000);
  }
  if(intensity < 500)
  {
    message = "Sunlight absent";
    delay(1000);
  }

}
