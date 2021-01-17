#include <Servo.h>


#include <PS2X_lib.h>
PS2X ps2x;

Servo Servo1;
Servo Servo2;
Servo Servo3;

 int error= 0;
 byte type= 0;
 byte vibrate= 0;

 #define BUTTON 1
 #define BUTTON 2
 #define BUTTON 3
 
void setup() 
{

Servo1.attach(5);
Servo2.attach(6);
Servo3.attach(7);
pinMode(BUTTON, INPUT_PULLUP);
Serial.begin(115200);


type = ps2x.readType();

error= ps2x.config_gamepad(10,11,12,13,false,false);
if (error==0){
  Serial.println("Found Controller");
  
}
else if(error==1)
Serial.println("No Controller Found");
else if(error==2)
Serial.println("Controller Found, Not Accepting Commands");
else if(error==3)
Serial.println("Controller Refusing to Enter Pressure Mode");

switch(type){
  case 0:
  Serial.println("Unknown Controller Type");
  break;
  case 1:
  Serial.println("Controller Type: Dual Shock");
  break;
  case 2:
  Serial.println("Controller Type: Guitar Hero");
  break;
  default: 
  break;
}
}



void loop() {
if(error==1)
  {
  Serial.println("Error");
  return;
  }

  ps2x.read_gamepad(false, vibrate);
if (ps2x.NewButtonState())
{
  if (ps2x.Button(PSB_GREEN))
  {
    Servo1.write(150);
    delay(10000);
  }
  else {
    Servo1.write(90);
    delay (500);
  }
}
  

  if (ps2x.NewButtonState())
{
  if (ps2x.Button(PSB_RED))
  {
    Servo2.write(150);
    delay(10000);
  }
  else {
    Servo2.write(90);
    delay (500);
  }
}
  if (ps2x.NewButtonState())
{
  if (ps2x.Button(PSB_PINK))
  {
    Servo3.write(150);
    delay(10000);
  }
    else {
    Servo3.write(90);
    delay (500);
  }
  

  
}
}
  // put your main code here, to run repeatedly:
