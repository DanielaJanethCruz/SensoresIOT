//TFT Display con Sensor Magnetico
#include <IRremote.h>  //Librería para el control remoto infrarrojo

#include "TM1651.h"  //Librería para el display de batería
#define CLK 14  //definición de los pines para TM1651 y se pueden cambiar a otros puertos
#define DIO 4
int cont = 1;  //variable para controlar la cantidad de veces que se pulsa el botón del control remoto
int RECV_PIN = 5;  //pin de entrada para el control remoto infrarrojo
IRrecv irrecv(RECV_PIN);  //instancia del receptor de control remoto
decode_results results;  //variable para almacenar los resultados del control remoto
bool on = LOW;  //variable para almacenar el estado de encendido/apagado del dispositivo

TM1651 batteryDisplay(CLK, DIO);  //instancia del display de batería

void setup() {
  irrecv.enableIRIn();  //habilita la recepción de señales del control remoto
  Serial.begin(9600);  //inicia la comunicación serial con una velocidad de 9600 baudios
  batteryDisplay.init();  //inicializa el display de batería
  batteryDisplay.set(1);           //ajusta el brillo del display (0~7, siendo 0 el más bajo y 7 el más alto)
  batteryDisplay.frame(FRAME_ON);  //enciende el marco del display de batería (o FRAME_OFF para apagarlo)
}

void loop() {
  results.value = 0;  //reinicia los resultados del control remoto
  if (irrecv.decode() && cont != 6) {  //si se recibe una señal del control remoto y no se han pulsado más de 5 veces los botones
    if (cont >= 6) {  //si se han pulsado 6 veces, reinicia el contador
      cont = 0;
    } else {  //de lo contrario, no hace nada con el contador
      cont;
    }
    Serial.println(results.value, HEX);  //imprime en la consola el valor recibido del control remoto en hexadecimal
    irrecv.resume();  //reinicia el receptor de señales del control remoto para recibir la siguiente señal
  }
  delay(300);  //espera 300ms antes de continuar
  
  charging();  //función para mostrar la animación de carga del display de batería
}

void charging() {
  for (uint8_t level = 0; level < 6; level++) {  //repite el siguiente bloque de código 6 veces
    batteryDisplay.displayLevel(level);  //muestra en el display de batería el nivel de carga correspondiente
    delay(500);  //espera 500ms antes de continuar
  }
}