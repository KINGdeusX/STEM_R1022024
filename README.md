# STEM\_R1022024

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
ESP8266 Based Multi operated sequential Canal Trash Extractor

### Hardwares

**Stepper Motor**: Nema 17 4500g

> * Model : 42BYGHW804
> * Keynotes : Coil1 (BLACK & GREEN) Coil2 (RED & BLUE)
> * Input Voltage: 3.6v
> * Input Current : 1.2 A/PHASE
> * [Datasheet](https://grobotronics.com/stepper-motor-42byghw804.html?sl=en&srsltid=AfmBOoob1S9VRoTaBIgixzCNw4r2lPHLdatZdNhg1EAL_pg9pJvKSeLj)

**Stepper Controller**: DRV8825

> | Pin | Designation |
> |:-|:-|
> | E | Enable |
> | S | Step |
> | D | Direction |
> 
> * Input Voltage: 9v
> * Input Current: 1.2A
> * [Library](https://github.com/RobTillaart/DRV8825)

**Laser Sensor**: DS18B20

> * Input Voltage: 5v
> * [Info](https://forum.arduino.cc/t/documents-about-laser-sensor-ds18b20/1090450) Arduino Post

**Laser Emitter**: KY-008

> * Input Voltage : 5v
> * [Datasheet](https://datasheet4u.com/datasheet-pdf/AZ-Delivery/KY-008/pdf.php?id=1415012) pdf

### Microcontroller

**REFERENCE**

![ESP8266 Pinout](https://lastminuteengineers.com/wp-content/uploads/iot/ESP8266-Pinout-NodeMCU.png)

**ESP8266 PIN DESIGNATORS**

| Label | GPIO | Location |
| :---- | :--- | :------- |
| D1 | 5 | (STEPPER\_0) - D |
| D2 | 4 | (STEPPER\_0) - S |
| D3 | 0 | (STEPPER\_1) - D |
| D4 | 2 | (STEPPER\_1) - S |
| D5 | 14 | (STEPPER\_2) - D |
| D6 | 12 | (STEPPER\_2) - S |
| D7 | 13 | (STEPPER\_3) - D |
| D8 | 15 | (STEPPER\_3) - S |
| D0 | 16 | laser\_sensor |

### WIRING DIAGRAM

![wire.jpg](.media/img_0.jpeg)

## DEV REMARKS

Nema 17 4500g Stepper motor and along its driver DRV8825 module may experience heating during long operations. But, this is considered normal.

Would advice better cooling options