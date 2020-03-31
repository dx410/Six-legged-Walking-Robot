#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>

using namespace std;
#define pwm_right 1
#define pwm_left 4
#define pwm_tilt 6

void forward()
{
	 softPwmCreate(pwm_tilt,8,100);
	 delay(800);
	 softPwmCreate(pwm_left,20,100);
	 delay(800);
	 softPwmWrite(pwm_tilt,20);
	 delay(800);
	 softPwmCreate(pwm_right,8,100);
	 delay(800);
	 softPwmWrite(pwm_tilt,15);
	 delay(800);
	 softPwmWrite(pwm_left,15);
	 delay(800);
	 softPwmWrite(pwm_right,15);
	 delay(800);	 
	 exit(0);
}	

void backward()
{
	 softPwmCreate(pwm_tilt,8,100);
	 delay(800);
	 softPwmCreate(pwm_left,8,100);
	 delay(800);
	 softPwmWrite(pwm_tilt,20);
	 delay(800);
	 softPwmCreate(pwm_right,20,100);
	 delay(800);
	 softPwmWrite(pwm_tilt,15);
	 delay(800);
	 softPwmWrite(pwm_left,15);
	 delay(800);
	 softPwmWrite(pwm_right,15);
	 delay(800);	 
	 exit(0);
}

void left()
{ 
	 softPwmCreate(pwm_tilt,8,100);
	 delay(800);
	 softPwmCreate(pwm_left,20,100);
	 delay(800);
	 softPwmWrite(pwm_tilt,20);
	 delay(800);
	 softPwmCreate(pwm_right,20,100);
	 delay(800);
	 softPwmWrite(pwm_tilt,15);
	 delay(800);
	 softPwmWrite(pwm_left,15);
	 delay(800);
	 softPwmWrite(pwm_right,15);
	 delay(800);	 
	 exit(0);

}

void right()
{
	softPwmCreate(pwm_tilt,8,100);
	 delay(800);
	 softPwmCreate(pwm_left,8,100);
	 delay(800);
	 softPwmWrite(pwm_tilt,20);
	 delay(800);
	 softPwmCreate(pwm_right,8,100);
	 delay(800);
	 softPwmWrite(pwm_tilt,15);
	 delay(800);
	 softPwmWrite(pwm_left,15);
	 delay(800);
	 softPwmWrite(pwm_right,15);
	 delay(800);	 
	 exit(0);

	
}

int main()
{
	 wiringPiSetup();
	 forward();
       //backward();
       //left();
       //right();
}
