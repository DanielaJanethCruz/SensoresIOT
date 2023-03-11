//Sensor Rotary Sconders
const int pinA = 12;
const int pinB = 13;

volatile int encoderPos = 0;
volatile int aSet = 0;
volatile int bSet = 0;

void setup() {
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinA), isr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pinB), isr, CHANGE);
}

void loop() {
  // Aquí se puede leer el valor actual del encoder
  Serial.println(encoderPos);
}

void isr() {
  // Manejador de interrupciones para el encoder
  aSet = digitalRead(pinA);
  bSet = digitalRead(pinB);
  
  if (aSet == bSet) {
    encoderPos++;
  } else {
    encoderPos--;
  }
}