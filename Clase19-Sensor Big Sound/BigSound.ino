//BigSound
// Incluir librería de ESP32
#include <Arduino.h>

// Definir pin de entrada del sensor de sonido
#define SOUND_SENSOR_PIN 13

void setup() {
  // Inicializar puerto serial
  Serial.begin(9600);
  // Configurar pin de entrada del sensor de sonido
  pinMode(SOUND_SENSOR_PIN, INPUT);
}

void loop() {
  // Leer valor del sensor de sonido
  int soundValue = analogRead(SOUND_SENSOR_PIN);
  // Imprimir valor en el puerto serial
  Serial.print("Sound sensor value: ");
  Serial.println(soundValue);
  // Esperar 100ms antes de volver a leer el valor del sensor
  delay(100);
}