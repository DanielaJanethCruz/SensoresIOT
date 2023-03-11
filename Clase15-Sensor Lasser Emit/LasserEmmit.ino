//Lasser Emmit
int laserPin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(laserPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(laserPin, HIGH);
}