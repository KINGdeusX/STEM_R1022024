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
#define sensor1 9

// setDirection
// DRV8825_CLOCK_WISE         = 0;  //  LOW
// DRV8825_COUNTERCLOCK_WISE  = 1;  //  HIGH

DRV8825 stepper1, stepper2, stepper3, stepper4; // Defined Stepper
int stepper_internal_delay = 10; // 10 ms for every step
int execution_delay = 1000;
int discarding_delay = 5000;

int stppr_wingL_num_steps = 300; // Number of steps defined for the Wing left Extractor
int stppr_WingR_num_steps = 300; // Number of steps defined for the Wing right Extractor
int stppr_cntrl_gate = 200; // Control Gate number fo steps
int stppr_trash_puller = 400; // Trash net puller

bool mode = 0; // 0 Automatic 1 Manual
bool exec = 0; // 0 noting happens 1 sequence begins
 
void setup() {
	// Code Here
	Serial.begin(115200);
	stepper1.begin(STEPPER_0_D, STEPPER_0_S);
	stepper2.begin(STEPPER_1_D, STEPPER_1_S);
	stepper3.begin(STEPPER_2_D, STEPPER_2_S);
	stepper4.begin(STEPPER_3_D, STEPPER_3_S);
	pinMode(sensor1, INPUT);
}

void wingL(const boolean direction, int steps) {
  	stepper1.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++){
		stepper1.step(); // Execute Step
		delay(stepper_internal_delay); 
	}
}
void wingR(const boolean direction, int steps) {
	stepper2.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++){
		stepper2.step(); // Execute Step
		delay(stepper_internal_delay); 
	}
}
void Cntrl(const boolean direction, int steps) {
	stepper3.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++) {
		stepper3.step(); // Execute Step
		delay(stepper_internal_delay); 
	}
}
void Puller(const boolean direction, int steps) {
	stepper4.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++){
		stepper4.step(); // Execute Step
		delay(stepper_internal_delay);
	}
}
 
void loop() {
	//Code Here
	bool sensor_value = digitalRead(sensor1); // Waits for the laser data

	if (sensor_value == true) {
		exec = 1;
		Serial.println("Laser Obstructed");
	}
	else {
		exec = 0;
		Serial.println("Laser Clear");
	}

	if (exec == 0) {
		// Standby
	}
	else if (exec == 1) {
		Serial.println("Executing");

		Serial.println("Raising Control Gate");
		Cntrl(0, stppr_cntrl_gate); // Raise the control gate
		Serial.println("Control Gate Raised");
		delay(execution_delay);

		Serial.println("Rolling Trash");
		Puller(0, stppr_trash_puller); // Rolls up the trash
		Serial.println("Trash Rolled");
		delay(execution_delay);
		
		Serial.println("Raising The Extractor");
		wingL(0, stppr_wingL_num_steps);
		Serial.println("Extractor Raised");
		delay(execution_delay);

		delay(discarding_delay); // delay for discarding the trash
		
		Serial.println("Lowering the Extractor");
		wingL(1, stppr_wingL_num_steps);
		Serial.println("Extractor Lowered");
		delay(execution_delay);
		
		Serial.println("Unrolling Trash");
		Puller(1, stppr_trash_puller); // Rolls up the trash
		Serial.println("Trash unrolled");
		delay(execution_delay);

		Serial.println("Lowering Control Gate");
		Cntrl(1, stppr_cntrl_gate); // Raise the control gate
		Serial.println("Control Gate Lowered");
		delay(execution_delay);

		Serial.println("Execution Finished");
		delay(5000); // Leveling Delay
	}
}