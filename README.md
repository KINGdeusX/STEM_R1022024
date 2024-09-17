# STEM_R1022024
ESP8266 Based Multi operated sequential Canal Trash Extractor

### Hardwares
**Stepper Motor**: Nema 17  4500g 
> Model : 42BYGHW804
> Keynotes : Coil1 (BLACK & GREEN) Coil2 (RED & BLUE)
> Input Voltage : 3.6v
> Input Current : 1.2 A/PHASE 
> [FILES HERE](https://grobotronics.com/stepper-motor-42byghw804.html?sl=en&srsltid=AfmBOoob1S9VRoTaBIgixzCNw4r2lPHLdatZdNhg1EAL_pg9pJvKSeLj)

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


### Microcontroller
ESP8266 pin Designators
| Label | GPIO | Location |
|:-|:-|:-|
| D1 | 5 | (STEPPER_0) - D |
| D2 | 4 | (STEPPER_0) - S |