# Unit Testing
1. use GPIO to drive 3 servos
2. TCP communication between server and client
3. threads
4. data from dht11 shown in ui
5. data from MPU6050 shown in ui
6. get video from camera in Raspberry Pi

# Server
Raspberry Pi is as the server. It creates the socket and send the data from sensors after connecting. 
The control of the servos are in the threads and they can be run and stop depends on different messages received from client.

# Client
Laptop is as the client. The ui is created based on QT. It connnects to server in the same WIFI, and recieve the data of sensors 
after connecting. The different buttoms have different functions, and each buttom can send different messages.
