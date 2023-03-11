//Sensor Tracker
int sensorPin = 2;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool value = digitalRead(sensorPin);
  
  if(value == 0){
    Serial.println("Blanco");
  } else {
    Serial.println("Negro");
  }
}