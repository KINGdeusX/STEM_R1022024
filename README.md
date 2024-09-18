# STEM\_R1022024

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

ESP8266 Based Multi operated sequential Canal Trash Extractor. Functions in 2 operation modes, Manual and Automatic.
* Automatic Mode - waits for the laser trigger to detect a certain level of trash in the canal. once detected (laser light obstructed) the system will begine squence of actions to raise or lower the trash extractor and collect the waste in the canal.
* Manual - the laser trigger will be disabled in this state and with the help of the web application GUI built in to the ESP8266 allows the actions of the rig to be controlled manually.

Written in C++ developed with PlatformIO.
Code can be viewed in [Here](./src/main.cpp)

## DOWNLOAD PROJECT
**REQUIREMENTS**
* [VS-Code](https://code.visualstudio.com/download)
* [PlatfromIO](https://platformio.org/install/ide?install=vscode)
* [Git](https://git-scm.com/downloads)
* bash / powershell

1. Open VS-Code then press `ctrl` + `~` on your keyboard
2. Enter the following
```
cd ./Desktop && mkdir EcoCanal && cd EcoCanal && git clone https://github.com/KINGdeusX/STEM_R1022024.git
```
This will automatically create the project files along its dependencies

3. Make sure your PlatformIO Extention is installed before proceding. Click on the PlatformIO icon in the lefthand side of VS-code
4. Select Folder then navigate over to the folder where you saved the project in this case its in the desktop
5. wait for everything to finish initializing the project.
6. On the directory panel in the left hand side of VS-code navigate over to `src` and click main.cpp this is the Arduino based source code.

## HARDWARES

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

## MICROCONTROLLER

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

## WIRING DIAGRAM

![wire.jpg](.media/img_0.jpeg)

## UPDATE NOTES

<span style="margin: 5px; padding: 10px; background-color: gold; color: white; max-width: 60px;">**09172024**</span>

> Nema 17 4500g Stepper motor and along its driver DRV8825 module may experience heating during long operations. But, this is considered normal. Would advice better cooling options

<span style="margin: 5px; padding: 10px; background-color: gold; color: white; max-width: 60px;">**09182024**</span>

> * On the documentations and diagrams it shows that the power supply Step-Down Converter was used is LM2595, But the one used is XL4015, Whats the difference? On paper XL4015 should deliver the needed power for all the devices. LM2595 can supply 3A at 150KHz While the XL4015 can deliver 5A at 180KHz [Refferences](https://www.reddit.com/r/AskElectronics/comments/u7nzyt/lm2596_vs_xl4015_demonstrably_different_one/). Considering The Nema 17 Stepper specified it can draw 1.2A per step, mentioned on the Nema 17 [Datasheet](https://grobotronics.com/stepper-motor-42byghw804.html?sl=en&srsltid=AfmBOoob1S9VRoTaBIgixzCNw4r2lPHLdatZdNhg1EAL_pg9pJvKSeLj). Testing the current inventory.
> * Added the stepper sequence and laser sensor