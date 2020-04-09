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
