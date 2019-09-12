//  Controlar los efectos del LED, con una pulsación corta cambiar el color del led girando
// y con una larga apaga o enciende el sistema.
//  Usar la funcion millis() para calcular el tiempo de pulsación para que no se bloquee el
// programa en la función PulseIn.
//  EJEMPLO DE MULTITAREA.

#include <Adafruit_NeoPixel.h>

#define PIN   D4
#define LED_NUM 7

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);

int velocidad = 200;

void setup() 
{
  leds.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600);
}

void loop() 
{
   for (int j = 0; j < 5; j++) 
  {
    for (int i = 1; i < LED_NUM; i++) 
    {
      leds.setPixelColor(i, leds.Color(0,0,10));
      leds.show();
      delay(velocidad);
      leds.setPixelColor(i, leds.Color(0,0,0));
    }
  }
  Serial.println(velocidad);
  velocidad -= 20;
  if (velocidad < 20)
    velocidad = 200;

}
