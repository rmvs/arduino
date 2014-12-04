
/** https://github.com/rmvs/arduino.git
**
**  @author Elano Rolim
**  @author Felipe Feitosa
**  @author Douglas Cunha
**/

#include <SoftwareSerial.h>

// "Instancia" o módulo que manipula a comunicação serial (porta 0: RX, porta1: TX)
SoftwareSerial con(0,1);
String dataRead = "";
int ledR = 8,
    ledG = 9,
    ledB = 10,
    ledRV = 0,
    ledGV = 0,
    ledBV = 0;
int rgb[3];

void setup()
{
  // Inicializa a saída serial 
  Serial.begin(9600);
  // Inicializa a comunicação serial com o dispositivo bluetooth a 38400 bauds
  // varia conforme o dispositivo [HC07/05]
  con.begin(38400);  
  Serial.println("Iniciado");
}

void loop()
{
  /**
  ** Se existir entrada disponível
  **/
  if(con.available())
  { 
    /**
     ** Enquanto existir caractere no buffer para leitura,lê o caractere em formato ASCII,
     ** converte sua representação para char.
     ** A leitura é feita com o método read()
     **/   
    while(con.available())
    {
      dataRead += (char)con.read();
    }
    
    ledRV = 255 - dataRead.substring(0,4).toInt();
    ledGV = 255 - dataRead.substring(4,8).toInt();
    ledBV = 255 - dataRead.substring(8,12).toInt();
    
    analogWrite(ledR,ledRV);
    analogWrite(ledG,ledGV);
    analogWrite(ledB,ledBV);
    dataRead = "";
    /**
    **  Ascende o led RGB se a entrada for uma string numérica
    ** em formato XXXXXXXXX, três digítos da esquerda para a direita representam o padrão R G B
    **/
    //if(dataRead != "esq" || dataRead != "dir"){
      /*analogWrite(ledR,255 - dataRead.substring(0,4).toInt());
      analogWrite(ledG,255 - dataRead.substring(4,8).toInt());
      analogWrite(ledB,255 - dataRead.substring(8,12).toInt());*/     
      
      /*Serial.println("Vermelho: " + String(255 - dataRead.substring(0,4).toInt()));
      Serial.println("Verde: " + String(255 - dataRead.substring(4,8).toInt()));
      Serial.println("Azul: " + String(255 - dataRead.substring(8,12).toInt()));*/
    //}      
    //dataRead = "";
  }    
  delay(300);
}
