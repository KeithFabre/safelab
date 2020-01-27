#include <SoftwareSerial.h>
SoftwareSerial SIM800L(2, 3); // RX | TX
// Connect the SIM800L TX to Arduino pin 2 RX. 
// Connect the SIM800L RX to Arduino pin 3 TX. 
void setup() {
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
  SIM800L.write("Teste testando");
  delay(1000);
   
  Serial.println("Enviar Char Ctrl + Z / ESC para sair do menu SMS");
  SIM800L.write((char)26);
  delay(1000);
     
  Serial.println("Envio completo de SMS!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
