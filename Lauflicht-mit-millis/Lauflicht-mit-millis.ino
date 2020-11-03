
unsigned long intervall = 500;
unsigned long startpunkt;
unsigned long ende;

int zaehler = -1;

byte led[8] = {2, 3, 4, 5, 6, 7, 8, 9};

byte ledZustand[8][8] =
{
  {1, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 0, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 1},
};


void setup()
{
  Serial.begin(9600);
  {
    for (byte i = 0; i < 9; i++)
    {
      pinMode (led[i], OUTPUT);
    }
  }
}

void loop()
{
  ende = millis();                          //aktuelle Zeitmarke setzen
  if ((ende - startpunkt) >= intervall)     //wenn größer/gleich 500ms gezählt wurden dann..
  {
    Serial.println(millis());
    startpunkt = millis();                  //neuen Startzeitpunkt wählen
    {
      digitalWrite(led[zaehler], LOW);
      digitalWrite(led[zaehler + 1], HIGH);
      zaehler++;
      if (zaehler == 8)
      {
        zaehler = -1;
      }
    }
  }
}



/*
        Einfaches Lauflicht mit 8 LEDs und millis anstatt delay

        letzte Änderung:  15.10.2020
        Version:          0.2
        Hardware:         LEDs an Pin 2-9
        Lösung von Mora Motta


int ledPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
unsigned long letzteZeit;
int ledEinschaltDauer = 300;
int aktuelleLED = 0;  //Start Led

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(ledPins[i], OUTPUT);    //Alle Pins auf Ausgang
  }
}

void loop()
{
  if ((millis() - letzteZeit) > ledEinschaltDauer)   //Zeit abgelaufen?
  {
    digitalWrite(ledPins[aktuelleLED], LOW);
    aktuelleLED++;
    if (aktuelleLED == 8)  //Falls der Endwert erreicht worden ist
    {
      aktuelleLED = 0;     //auf Startwert stellen
    }
    digitalWrite(ledPins[aktuelleLED], HIGH);
    letzteZeit = millis();
  }
}
*/
