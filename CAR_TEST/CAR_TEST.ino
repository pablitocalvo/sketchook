

#define PIN_DESTRA_EN 6
#define PIN_DESTRA_A 7
#define PIN_DESTRA_B 8

#define PIN_SINISTRA_EN 9
#define PIN_SINISTRA_A 10
#define PIN_SINISTRA_B 11



void motore_destra_indietro( )
{
}


void setup() {
  // put your setup code here, to run once:

    pinMode(PIN_DESTRA_A,OUTPUT);
    pinMode(PIN_DESTRA_B,OUTPUT);
    pinMode(PIN_DESTRA_EN,OUTPUT);
    
    pinMode(PIN_SINISTRA_A,OUTPUT);
    pinMode(PIN_SINISTRA_B,OUTPUT);
    pinMode(PIN_SINISTRA_EN,OUTPUT);

    
   analogWrite( PIN_SINISTRA_EN , 128);
   analogWrite( PIN_DESTRA_EN ,128);
    

}


void mot_destra_avanti()
{
      digitalWrite(PIN_DESTRA_A,LOW);
      digitalWrite(PIN_DESTRA_B,HIGH);
}
void mot_sinistra_avanti()
{
      digitalWrite(PIN_SINISTRA_A,LOW);
      digitalWrite(PIN_SINISTRA_B,HIGH);
}

void mot_destra_indietro()
{
    digitalWrite(PIN_DESTRA_A,HIGH);
    digitalWrite(PIN_DESTRA_B,LOW);
   
}
void mot_sinistra_indietro()
{
    digitalWrite(PIN_SINISTRA_A,HIGH);
    digitalWrite(PIN_SINISTRA_B,LOW);
   
}

void motore_destra_stop()
{
    digitalWrite(PIN_DESTRA_A,LOW);
    digitalWrite(PIN_DESTRA_B,LOW);
}

void motore_sinistra_stop()
{
    digitalWrite(PIN_SINISTRA_A,LOW);
    digitalWrite(PIN_SINISTRA_B,LOW);
   
}

void avanti()
{
      mot_destra_avanti();
      mot_sinistra_avanti();
      delay(300);
      motore_destra_stop();
      motore_sinistra_stop();
}

void indietro()
{     mot_destra_indietro();
      mot_sinistra_indietro();
      delay(300);
      motore_destra_stop();
      motore_sinistra_stop();
  
}

void gira_a_destra()
{     
    
}



void loop() {
  // put your main code here, to run repeatedly:
//mot_sinistra_indietro();

 avanti();
 delay (1000);
 indietro();
 delay (1000);




}
