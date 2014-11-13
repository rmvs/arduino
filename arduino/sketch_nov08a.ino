
#include <SoftwareSerial.h>

SoftwareSerial con(0,1);
String dataRead = "";
int ledR = 7,
    ledG = 6,
    ledB = 5;
int rgb[3];
void setup()
{
  
  Serial.begin(9600);
  con.begin(38400);  
  Serial.println("Iniciado");
}

void loop()
{
  if(con.available())
  {    
    while(con.available())
    {
      dataRead += (char)con.read();
    }       
    Serial.println(dataRead);
    analogWrite(ledR,255 - dataRead.substring(0,4).toInt());
    analogWrite(ledG,255 - dataRead.substring(4,8).toInt());
    analogWrite(ledB,255 - dataRead.substring(8,12).toInt());  
    dataRead = "";
  }
  delay(100);
  
  
}
