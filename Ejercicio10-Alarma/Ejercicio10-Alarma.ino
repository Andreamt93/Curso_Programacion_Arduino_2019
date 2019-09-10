//  Sistema de alarma que haga sonar el buzzer cuando la temperatura suba de 24º
//  Definir constante UMBRAL
//  Encender leds cuando supere la temperatura,24º el primer LED, 25º el segundo LED...hasta 4
//  Mandar por el puerto y la LCD la temperatura en la primera línea y mensaje de ALARMA
// o NORMAL en la segunda línea cuando supere el umbral.
//  Variable global alarma_temperatura que se actualice.

//Librería DHT11
#include <SimpleDHT.h>

#define PIN_LED_1 4
#define PIN_LED_2 5 //PWM
#define PIN_LED_3 6 //PWM
#define PIN_LED_4 7
#define PIN_DHT11 11
#define PIN_BUZZER 8
#define NOTE_C5  523  //Frecuencia de sonido del buzzer

#define UMBRAL 24;
boolean alarma_temperatura;

//Objeto DHT11
SimpleDHT11 dht11(PIN_DHT11);

void setup()
{
  //Inicializo puerto serie
  Serial.begin(9600);

  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);

  if (temperatura () > UMBRAL)
  {
    alarma_temperatura = true;
    tone(PIN_BUZZER, NOTE_C5);
    Serial.println("¡ALARMA!");
  }
  else
  {
    alarma_temperatura = false;
    noTone(PIN_BUZZER);
  }

}

void loop()
{
  float temperatura ()
  {
    byte temperature = 0;
    byte humidity = 0;
    int err = dht11.read(&temperature, &humidity, NULL);

    if (err != SimpleDHTErrSuccess)
    {
      Serial.print("Read DHT11 failed, err=");
      temperature = 0;
    }
    else
    {
      Serial.print("Temperatura: ");
      Serial.print(temperature);
      Serial.print(", Humedad:");
      Serial.println(humidity);
    }
    return temperature;
  }

}
