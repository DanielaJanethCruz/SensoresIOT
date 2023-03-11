//Sensor Joystick
void setup() {
  Serial.begin(9600);
}

void loop() {
  //Detecta los Movimientos en el eje Y
  if (analogRead(12) == 0){
    Serial.println("Izquierda");
    delay(100);
  } else if(analogRead(12) == 4095){
    Serial.println("Derecha");
    delay(100);
  }
  //Detecta los Movimientos en el eje X
  if (analogRead(13) == 0){
    Serial.println("Arriba");
    delay(100);
  } else if(analogRead(13) == 4095){
    Serial.println("Agua");
    delay(100);
  }
  //Detecta las pulsaciones del JoyStick
  if (analogRead(14) <= 300){
    Serial.println("Abajo");
    delay(100);
  }
}