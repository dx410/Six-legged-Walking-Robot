# Bionic crawling robot
Access to certain small and dangerous areas for detection  
![image](https://github.com/dx410/Six-legged-Walking-Robot/blob/master/images/background.PNG)
# Remote control possible
Obtain some physical values through the sensor and camera and display it on the controller in real time
![image](https://github.com/dx410/Six-legged-Walking-Robot/blob/master/images/design.PNG)
# Hardware
SG5010 servo * 3   
Robot's legs made of aluminum and body made of Acrylic  
Raspberry Pi exclusive camera    
Temperature and humidity sensor dht11  
space movement sensor MPU6050 
# Software 
QT Creator
# Implementation method: 
1. use TCP to communicate with Raspberry Pi and laptop
2. laptop can send command to control the servos to make robot move
3. robot could recieve sensors data and send to the laptop, showing on GUI
4. laptop can get the video from camera on the Raspberry Pi
# GUI interface
![image](https://github.com/dx410/Six-legged-Walking-Robot/blob/master/images/Gui.PNG)
# Project video on twitter  
https://twitter.com/SLrobot
# Contributors
dx410 - Xiao Deng - entire code integration ; unit testing ( except sensors and video )  
Lei5218- Lei Zhao - Hardware parts (include PCB and Machine building）；sensor code parts;  
YuXiang Tong - Help with coding and Manufacturing of mechanical parts; Realize real-time video function; 
