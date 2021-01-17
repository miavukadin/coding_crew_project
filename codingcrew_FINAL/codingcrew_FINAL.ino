#include <Servo.h>


#include <PS2X_lib.h>
PS2X ps2x;

Servo Servo1;
Servo Servo2;
Servo Servo3;

 int error= 0;
 byte type= 0;
 byte vibrate= 0;



 
void setup() 
{

Servo1.attach(5);
Servo2.attach(6);
Servo3.attach(7);

Serial.begin(115200);


type = ps2x.readType();

error= ps2x.config_gamepad(10,12,11,13,false,false);
if (error==0){
  Serial.println("Found Controller");

type = ps2x.readType();
  
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
if(error == 1)
  {
  Serial.println("Error");
  return;
  }

 ps2x.read_gamepad(false, vibrate);
if (ps2x.NewButtonState())
{
  if (ps2x.Button(PSB_GREEN))
  {
    Serial.println("Green Pressed");
    Servo1.write(160);
    delay(1000);
  }
  if (ps2x.Button(PSB_PINK))
  {
    Serial.println("Pink Pressed");
    Servo2.write(160);
    delay(1000);
  }
  if (ps2x.Button(PSB_RED))
  {
    Serial.println("Red Pressed");
    Servo3.write(160);
    delay(1000);
  }
   if (ps2x.Button(PSB_PAD_UP))
  {
    Serial.println("UP Pressed");
    Servo1.write(90);
    delay(1000);
  }
  if (ps2x.Button(PSB_PAD_LEFT))
  {
    Serial.println("LEFT Pressed");
    Servo2.write(90);
    delay(1000);
  }
  if (ps2x.Button(PSB_PAD_RIGHT))
  {
    Serial.println("RIGHT Pressed");
    Servo3.write(90);
    delay(1000);
  }
  
}

delay(50);
}


  

  
