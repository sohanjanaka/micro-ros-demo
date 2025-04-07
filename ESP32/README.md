# Arduino sketch for ATV Interface (ESP32)

## Install Arduino IDE
1. [Download the arduino-1.8.19-linuxaarch64.tar.xz, this is for Rasberry Pi and Jetsons which have linuxaarch64 architecture](https://downloads.arduino.cc/arduino-1.8.19-linuxaarch64.tar.xz)
2. The file is compressed and you have to extract it in a suitable folder, remembering that it will be executed from there.
3. Open the arduino-1.x.x folder just created by the extraction process and spot the install.sh file. Right click on it and choose Run in Terminal from the contextual menu. The installation process will quickly end and you should find a new icon on your desktop. 
4. If you don't find the option to run the script from the contextual menu, you have to open a Terminal window and move into the arduino-1.x.x root directory and run the following command:
``` bash
sudo sh install.sh
```
5. You should find a new icon on your desktop or application menu

## Configure Dialout for Arduino IDE
[Configure Dialout settings](https://docs.arduino.cc/software/ide-v1/tutorials/Linux/)

## Configure ESP32 in Arduino IDE

You can ignore this if you can upload code to ESP32 using Arduino IDE without any issue. 
1. File -> Preferences
2. Edit "Additional Board Manager URLs"
```
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
```
3. Tools -> Board -> Boards Manager. Install ESP32 (by Espressif Systems)
4. Tools -> Board -> esp32 -> Select ESP32 Dev Module
5. Install pip
``` bash
sudo apt install python3-pip
```
6. Install pyserial
``` bash
pip install pyserial
```
7. Now try to upload simple code to the ESP32 and test.

[reference](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)


## Arduino Micro ROS configuration 
You have to make following changes in Arduino IDE to make code work:

1. Download zip file from this git repository, branch humble [https://github.com/micro-ROS/micro_ros_arduino/tree/humble](https://github.com/micro-ROS/micro_ros_arduino/tree/humble)
2. **Sketsch -> add Zip Library -> Select the Downloaded zip file**

