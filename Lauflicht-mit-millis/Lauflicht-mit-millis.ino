
/*
  Einfaches Lauflicht mit 8 LEDs und millis anstatt delay

  letzte Änderung:  15.10.2020
  Version:          0.2
  Hardware:         LEDs an Pin 2 - 9
*/

#include <OneButton.h>
OneButton button(10, false);


int ledPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
unsigned long letzteZeit;
int ledEinschaltDauer = 300;
int aktuelleLED = 0;                                     //Start Led
bool statusPower = false;

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(ledPins[i], OUTPUT);                        //Alle Pins auf Ausgang
  }
  button.attachClick(StatusPowerSetzen);
}

void loop()
{
  button.tick();
  if (statusPower == true)
  {
    if ((millis() - letzteZeit) > ledEinschaltDauer)   //Zeit abgelaufen?
    {
      if (aktuelleLED > -1)
      {
        digitalWrite(ledPins[aktuelleLED], LOW);
      }
      aktuelleLED++;
      if (aktuelleLED == 8)                            //Falls der Endwert erreicht worden ist
      {
        aktuelleLED = 0;                               //auf Startwert stellen
      }
      digitalWrite(ledPins[aktuelleLED], HIGH);
      letzteZeit = millis();
    }
  }
  else
  {
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(ledPins[i], LOW);
    }
    aktuelleLED = -1;
  }
  delay(10);
}

void StatusPowerSetzen()
{
  statusPower = !statusPower;
}
