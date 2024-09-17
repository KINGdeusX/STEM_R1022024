#include <Arduino.h>
#include <DRV8825.h>

#define STEPPER_0_D 5
#define STEPPER_0_S 4
#define STEPPER_1_D 0
#define STEPPER_1_S 2
#define STEPPER_2_D 14
#define STEPPER_2_S 12
#define STEPPER_3_D 13
#define STEPPER_3_S 15
#define laser1 10
#define sensor1 9

// setDirection
// DRV8825_CLOCK_WISE         = 0;  //  LOW
// DRV8825_COUNTERCLOCK_WISE  = 1;  //  HIGH

DRV8825 stepper1, stepper2, stepper3, stepper4; // Defined Stepper
int stepper_internal_delay = 10; // 10 ms for every step
int stppr_wingL_num_steps = 300; // Number of steps defined for the Wing left Extractor
int stppr_WingR_num_steps = 300; // Number of steps defined for the Wing right Extractor
int stppr_cntrl_gate = 200; // Control Gate number fo steps
int stppr_trash_puller = 400; // Trash net puller
 
void setup() {
	// Code Here
	Serial.begin(115200);
	stepper1.begin(STEPPER_0_D, STEPPER_0_S);
	stepper2.begin(STEPPER_1_D, STEPPER_1_S);
	stepper3.begin(STEPPER_2_D, STEPPER_2_S);
	stepper4.begin(STEPPER_3_D, STEPPER_3_S);
}

void wingL(const boolean direction, int steps) {
  	stepper1.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++){
		stepper1.step(); // Execute Step
		delay(stepper_internal_delay); 
	}
}
// void wingR() {}
// void Cntrl() {}
// void Puller() {}
 
void loop() {
	//MOD
	digitalWrite(laser1, HIGH);
	bool value = digitalRead(sensor1);

	if (value) {
		Serial.println("Laser Detected");
	}
	else {
		Serial.println("NO Laser");
	}
}