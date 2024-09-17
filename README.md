# STEM_R1022024
ESP8266 Based Multi operated sequential Canal Trash Extractor

### Hardwares
**Stepper Motor**: Nema 17  4500g 
> Model : 42BYGHW804
> Keynotes : Coil1 (BLACK & GREEN) Coil2 (RED & BLUE)
> Input Voltage : 3.6v
> Input Current : 1.2 A/PHASE 
> Full [Datasheet](https://grobotronics.com/stepper-motor-42byghw804.html?sl=en&srsltid=AfmBOoob1S9VRoTaBIgixzCNw4r2lPHLdatZdNhg1EAL_pg9pJvKSeLj)

**Stepper Controller**: DRV8825
> Keynotes : 
> | Pin | Designation |
> |:-|:-|
> | E | Enable |
> | S | Step |
> | D | Direction |
>
> Input Voltage : 9v
> Input Current : 1.2A
> [Library](https://github.com/RobTillaart/DRV8825)


### Microcontroller
**REFERENCE**
![ESP8266 Pinout](https://lastminuteengineers.com/wp-content/uploads/iot/ESP8266-Pinout-NodeMCU.png)

**ESP8266 PIN DESIGNATORS**
| Label | GPIO | Location |
|:-|:-|:-|
| D1 | 5 | (STEPPER_0) - D |
| D2 | 4 | (STEPPER_0) - S |
| D3 | 0 | (STEPPER_1) - D |
| D4 | 2 | (STEPPER_1) - S |
| D5 | 14 | (STEPPER_2) - D |
| D6 | 12 | (STEPPER_2) - S |
| D7 | 13 | (STEPPER_3) - D |
| D8 | 15 | (STEPPER_3) - S |