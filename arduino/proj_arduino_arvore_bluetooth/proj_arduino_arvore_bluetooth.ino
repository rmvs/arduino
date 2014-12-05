
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
const int          ledA_r = 4;
const int          ledA_g = 3;
const int          ledA_b = 2;
const int          ledB_r = 7;
const int          ledB_g = 6;
const int          ledB_b = 5;
const int          ledC_r = 10;
const int          ledC_g = 9;
const int          ledC_b = 8;
int rgb[3];

int red = 0;
int green = 0;
int blue = 0;
int delay_ = 500; 
void setup()
{
  /*for(int i = 2; i <= 10;i++){
     pinMode(i,OUTPUT);
  }*/
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
    if(dataRead.equals("0R")){
      ascendeCorVermelha();
      delay(2000);
    }else if(dataRead.equals("all")){
      ascendeTodos();
      delay(2000);
    }else if(dataRead.substring(0,1).equals("V")){
      delay_ = dataRead.substring(1,dataRead.length()).toInt();
      Serial.println("velocidade alterada: " + String(delay_));
    }else if(dataRead.equals("0G")){
      ascendeCorVerde();
      delay(2000);
    }else if(dataRead.equals("0B")){
      ascendeCorAzul();
      delay(2000);
    }else{    
      red = 255 - dataRead.substring(0,4).toInt();
      green = 255 - dataRead.substring(4,8).toInt();
      blue = 255 - dataRead.substring(8,12).toInt();
    }
    Serial.println(dataRead);
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
  
  efeitoRGB();
  delay(300);
}

void efeitoRGB(){
  
  int r = ledC_r,g = ledC_g,b = ledC_b;
  for(int i = 1; i <= 3 ; i++){
    _efeitoRGB(r,g,b);
    r -= 3;
    g -= 3;
    b -= 3;
  }
}
void _efeitoRGB(int r,int g,int b){
  
  analogWrite(r,red);
  delay(delay_);
  analogWrite(r,255);
  
  analogWrite(g,green);
  delay(delay_);
  analogWrite(g,255);
  
  analogWrite(b,blue);
  delay(delay_);
  analogWrite(b,255);  
}

void ascendeCorVermelha(){
   analogWrite(ledA_r,0);
   analogWrite(ledA_g,255);
   analogWrite(ledA_b,255);
   
   analogWrite(ledB_r,0);
   analogWrite(ledB_g,255);
   analogWrite(ledB_b,255);
   
   analogWrite(ledC_r,0);
   analogWrite(ledC_g,255);
   analogWrite(ledC_b,255);
}
void ascendeCorVerde(){
   analogWrite(ledA_g,0);
   analogWrite(ledB_g,0);
   analogWrite(ledC_g,0);
}
void ascendeCorAzul(){
   analogWrite(ledA_b,0);
   analogWrite(ledB_b,0);
   analogWrite(ledC_b,0);
}
void ascendeCorPersonalizada(int r,int g,int b){
  analogWrite(ledA_r,r);
  analogWrite(ledA_g,g);
  analogWrite(ledA_b,b);
  
  analogWrite(ledB_r,r);
  analogWrite(ledB_g,g);
  analogWrite(ledB_b,b);
  
  analogWrite(ledC_r,r);
  analogWrite(ledC_g,g);
  analogWrite(ledC_g,b);
}
void ascendeTodos(){
  analogWrite(ledA_r,red);
  analogWrite(ledA_g,green);
  analogWrite(ledA_b,blue);
  
  analogWrite(ledB_r,red);
  analogWrite(ledB_g,green);
  analogWrite(ledB_b,blue);
  
  analogWrite(ledC_r,red);
  analogWrite(ledC_g,green);
  analogWrite(ledC_b,blue);
}
  
