
#include <SoftwareSerial.h>
SoftwareSerial bt(2,3); // RX, TX


#define DISCONNESSO 0
#define CONNESSO 1

#define PIN_MODE 4
#define PIN_LED 13

int stato= 0 ;

void stampa_stato()
{
    Serial.println( "stato ==============");
    Serial.print("connessione= ");
    Serial.println(stato);
    Serial.print("led = ");
    Serial.println(digitalRead(PIN_LED));
}
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    bt.begin(9600);
    
    pinMode(PIN_LED, OUTPUT);
    digitalWrite(PIN_LED,LOW);
    
    pinMode(PIN_MODE, INPUT);
    stato= digitalRead( PIN_MODE );

    stampa_stato();
    
}

void loop() {
  // put your main code here, to run repeatedly:

  if ( stato== CONNESSO)
  {
      bool inseritoDati=false;
      String dati="";
      while (bt.available() )
      {   dati+= (char) bt.read();
          inseritoDati= true;
          delay(10);
      }
      if (inseritoDati )
      {   
          Serial.println("arrivati dati");
          Serial.println(dati);
          inseritoDati=false;
          dati=dati.substring (0,dati.length()-2); //levo CR NL 

               if (dati=="ON")
                { digitalWrite(PIN_LED,HIGH); stampa_stato(); }
          else if (dati=="OFF")
                { digitalWrite(PIN_LED,LOW ); stampa_stato(); }
           
      }
  }

  int val13=digitalRead(12);
  if ( stato!= val13)
  {   stato=val13;
      stampa_stato();
  }
}
