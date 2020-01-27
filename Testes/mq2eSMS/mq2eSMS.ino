//MQ2 e SMS

//SIM 800L
#include <SoftwareSerial.h>
SoftwareSerial SIM800L(2, 3); // RX | TX
// Connect the SIM800L TX to Arduino pin 2 RX. 
// Connect the SIM800L RX to Arduino pin 3 TX.

//Sensor mq02 

int sensorgas = A0;//sensor de gás no pino a0
int buzzer = 7; //buzzer no pino d2 
int maxgas = 380;//valor max de gás normal 

int smsenviado = 0; //para enviar sms só uma vez
 
void setup(){

pinMode(sensorgas, INPUT); 
pinMode(buzzer, OUTPUT); 
Serial.begin(9600);

// start th serial communication with the host computer
    Serial.begin(9600);
    while(!Serial);
    Serial.println("Arduino with SIM800L is ready");
 
    // start communication with the SIM800L in 9600
    SIM800L.begin(9600);  
    Serial.println("SIM800L started at 9600");
    delay(1000);
    Serial.println("Setup Complete! SIM800L is Ready!");
   
  Serial.println("Definir o formato SMS para ASCII");
  SIM800L.write("AT+CMGF=1\r\n");
  delay(1000);
 
  Serial.println("SIM800L Definir SMS para o número do destino");
  SIM800L.write("AT+CMGS=\"219********\"\r\n"); //mudar * por número de telefone existente
  delay(1000);
   
  Serial.println("SIM800L Send SMS content");
  SIM800L.write("Sistema em funcionamento");
  delay(1000);
   
  //Serial.println("Enviar Char Ctrl + Z / ESC para sair do menu SMS");
  SIM800L.write((char)26);
  delay(1000);
     
  Serial.println("Envio completo de SMS!");
  

}


void loop(){

int leituragas = analogRead(sensorgas); 
Serial.print("Leitura: "); 
Serial.println(leituragas);
//int smsenviado = 0;

 if (leituragas > maxgas){

 digitalWrite(buzzer, HIGH); 
 delay(1000);
 digitalWrite(buzzer, LOW);

 if (smsenviado==0){
  enviaSMS();
  smsenviado=1;
 }


 }
 else{ 
 digitalWrite(buzzer, LOW);
 }
 delay(100); 

}

void enviaSMS(){ //para enviar sms só quando houver vazamento

  SIM800L.write("AT+CMGF=1\r\n");
  delay(500);
 
  //Serial.println("SIM800L Definir SMS para o número do destino");
  SIM800L.write("AT+CMGS=\"219********\"\r\n"); //mudar * por número de telefone existente
  delay(500);
   
  //Serial.println("SIM800L Send SMS content");
  SIM800L.write("Vazamento de gas detectado no laboratorio!");
  delay(500);
  //Serial.println("Enviar Char Ctrl + Z / ESC para sair do menu SMS");
  SIM800L.write((char)26);
  delay(500);


}
