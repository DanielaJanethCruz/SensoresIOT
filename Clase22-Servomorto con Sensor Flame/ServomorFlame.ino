//Servomotor con Sensor Flame

#include <Servo.h>

Servo servo_1;
int valorSensor = 0; 


void setup()
{
  
  servo_1.attach(13);
  Serial.begin(9600);
}

void loop()
{
  valorSensor = analogRead(4);

  if(valorSensor<500){
  servo_1.write(90);
  delay(1000);
  servo_1.write(0);
  delay(1000);
  }
}