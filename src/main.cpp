#include <Arduino.h>
#include <DRV8825.h>

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
	stepper1.begin(5, 4);
	// stepper2.begin(5, 4);
	// stepper3.begin(5, 4);
	// stepper4.begin(5, 4);
}

void wingL(const boolean direction) {
  	stepper1.setDirection(direction); // Direction
	for(int i = 0; i <= stppr_wingL_num_steps; i++){
		stepper1.step(); // Execute Step
		delay(stepper_internal_delay); 
	}
}
// void wingR() {}
// void Cntrl() {}
// void Puller() {}
 
void loop() {
	wingL(0);
	delay(10000);
}