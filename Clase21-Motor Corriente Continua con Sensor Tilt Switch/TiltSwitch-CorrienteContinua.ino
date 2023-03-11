//Tilt Switch con Motor Corriente continua
int pint=2;

#define SENSOR_PIN 14

void setup() {
  // sets the pins as outputs:
  pinMode(pint, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);

  Serial.begin(115200);
}

void loop() {
  // Move the DC motor forward at maximum speed
  digitalWrite(pint, digitalRead(SENSOR_PIN));
}