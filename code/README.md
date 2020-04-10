# Unit Testing
1. use GPIO to drive 3 servos
2. TCP communication between server and client
3. threads
4. timer test in ui
5. data from dht11 shown in ui
6. data from MPU6050 shown in ui
7. function parameter passing and write socket in array
8. get video from camera in Raspberry Pi

# Robot_Server
* Raspberry Pi is as the server. It creates the socket and send the data from sensors after connecting. 
* The control of the servos are in the threads and they can be run and stop depends on different messages received from client.
* use QT Creator to build and run.

# Robot_Client
* Laptop is as the client. The ui is created based on QT. It connnects to server in the same WIFI, and recieve the data of sensors 
after connecting. 
* The different buttoms have different functions, and each buttom can send different messages.
* use QT Creator to build and run.  
  
#realtime video  
1、Install required modules  
sudo apt-get update  
sudo apt-get install subversion  
sudo apt-get install libjpeg8-dev  
sudo apt-get install imagemagick  
sudo apt-get install libv4l-dev  
sudo apt-get install cmake  
sudo apt-get install git  
2、sudo git clone github.com/jacksonliam/mjpg-streamer.git  
make all  
sudo make install  
3、open the raspicamera  
./mjpg_streamer -i "./input_raspicam.so" -o "./output_http.so -w ./www"  
4、Access the Raspberry Pi's IP address on port 8080.  
http://192.168.137.226:8080/javascript_simple.html
