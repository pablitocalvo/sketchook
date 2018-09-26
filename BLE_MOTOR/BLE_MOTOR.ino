
#include <SoftwareSerial.h>
SoftwareSerial bt(2,3); // RX, TX


#define DISCONNESSO 0
#define CONNESSO 1

#define PIN_MODE 4
#define PIN_LED 13

#define PIN_MOT1_A 7
#define PIN_MOT1_B 8

#define PIN_MOT1_EN 6

#define MOT_FERMO 0
#define MOT_AVANTI 1
#define MOT_INDIETRO 2

#define STEP 8

int stato_motore= MOT_FERMO ;
int velocita_motore=4;

int stato= 0 ;


void stampa_stato()
{
    Serial.println( "stato ==============");
    Serial.print("connessione= ");
    Serial.println(stato);
    Serial.print("MOTORE = ");
    Serial.println( stato_motore);
    Serial.print("velocita= ");
    Serial.println(velocita_motore);
    
    
}

void incrementa_velocita()
{
    if ( velocita_motore < (STEP-1) )
       {  velocita_motore++ ; analogWrite( PIN_MOT1_EN , velocita_motore*(256/STEP) ) ; }
}
void decrementa_velocita()
{
    if ( velocita_motore > 0 )
       {  velocita_motore-- ; analogWrite( PIN_MOT1_EN , velocita_motore*(256/STEP) ) ; }
}



void set_motore_fermo()
{
    digitalWrite(PIN_MOT1_A,LOW);
    digitalWrite(PIN_MOT1_B,LOW);
    stato_motore= MOT_FERMO ;
}
void set_motore_avanti()
{
    digitalWrite(PIN_MOT1_A,LOW);
    digitalWrite(PIN_MOT1_B,HIGH);
    stato_motore= MOT_AVANTI;
}
void set_motore_indietro()
{
    digitalWrite(PIN_MOT1_A,HIGH);
    digitalWrite(PIN_MOT1_B,LOW);
    stato_motore= MOT_INDIETRO;
}


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    bt.begin(9600);
    
    pinMode(PIN_MODE, INPUT);
    stato= digitalRead( PIN_MODE );
    
    pinMode(PIN_MOT1_A,OUTPUT);
    pinMode(PIN_MOT1_B,OUTPUT);
    pinMode(PIN_MOT1_EN,OUTPUT);
    digitalWrite (PIN_MOT1_EN,HIGH);
    set_motore_fermo();
    
    
    

    set_motore_fermo();
    
    
   
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

               if (dati=="stop")
                { set_motore_fermo(); stampa_stato(); }
          else if (dati=="avanti")
                { set_motore_avanti(); stampa_stato(); }
          else if (dati=="indietro")
                { set_motore_indietro(); stampa_stato(); }
         else if (dati=="piu")
                { incrementa_velocita(); stampa_stato(); }
         else if (dati=="meno")
                { decrementa_velocita(); stampa_stato(); }
           
      }
  }

  int val13=digitalRead(PIN_MODE);
  if ( stato!= val13)
  {   stato=val13;
      stampa_stato();
  }
}
