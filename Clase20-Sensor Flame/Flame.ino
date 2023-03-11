 // Sensor: FLAME SENSOR

const int sensorPin = 9;
void setup()
{
   Serial.begin(115200);
   pinMode(sensorPin, INPUT);
}
void loop()
{
   int fuego = digitalRead(sensorPin);
   if (fuego == HIGH)
   {
      Serial.println("Fuego detectado");
   }
   delay(1000);
}