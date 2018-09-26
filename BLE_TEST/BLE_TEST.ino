#include <SoftwareSerial.h>
SoftwareSerial bt(2,3); // RX, TX sul modulo !!

//SoftwareSerial bt(RX,TX); // RX, TX

// 

String command = ""; 
int mode=0;
void inviaComando( String comando)
{   
    Serial.print( "inviato comando=");
    Serial.println( comando );
     
    bt.println( comando );

    delay(100);

    String risposta="";
    while (bt.available()) 
    {
      risposta+= (char) bt.read();
    }
    Serial.println("risposta ");
    Serial.println(risposta);
    Serial.println("length risposta");
    Serial.println(risposta.length());
 
}

void setup() {
  // Open serial communications:
  Serial.begin(9600);
  Serial.println("Type AT commands!");
  bt.begin(9600);
  
  inviaComando( "AT+VERSION" );
  String prova="AT+VERSION";
  inviaComando( prova );

  pinMode(13, INPUT);

  mode= digitalRead(13); 
  
}

void loop() {
  
  String comando="";
  bool inseritoComando=false;

  while (Serial.available() )
  {   comando+= (char) Serial.read();
      inseritoComando= true;
      delay(10);
  }
  
  if (inseritoComando )
  {   comando= comando.substring (0,comando.length()-2);
      inseritoComando=false;
      inviaComando( comando );
      
  }
  
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
      
  }
  
  
  int val13=digitalRead(13);
  if ( mode!= val13)
  {   mode=val13;
      Serial.print("mode are changed now is=");
      Serial.println (mode);
  }
  

  

  
}
