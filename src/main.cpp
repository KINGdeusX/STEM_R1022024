#include <Arduino.h>
#include <DRV8825.h>

// setDirection
// DRV8825_CLOCK_WISE         = 0;  //  LOW
// DRV8825_COUNTERCLOCK_WISE  = 1;  //  HIGH



DRV8825 stepper; // Defined Stepper
 
void setup() {
	// Code Here
	Serial.begin(115200);
	stepper.begin(5, 4);  // direction + step pin
  	stepper.setDirection(DRV8825_CLOCK_WISE);
}
 
void loop() {
	for(int i = 0; i < 300; i++){
		stepper.step();
		delay(10000);
	}
}