/*         OLED
SCL -------------- A5
SCA -------------- A4
VDD -------------- 5V
GND -------------- GND*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_Address 0x3C
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

/*   MQ 2 sensor de gás 
a0 -------- A0
gnd ------- GND
VCC -------- 5V
 */

int sensorgas = A0;//sensor de gás no pino a0
int buzzer = 7; //buzzer no pino d2 
int maxgas = 380;//valor max de gás normal 

//dht 11

#include <dht.h>
#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1
dht DHT; //Inicializa o sensor


//SIM 800L
#include <SoftwareSerial.h>
SoftwareSerial SIM800L(3, 4); // RX | TX
// Connect the SIM800L TX to Arduino pin 2 RX. 
// Connect the SIM800L RX to Arduino pin 3 TX.

int smsenviado = 0; //para enviar sms só uma vez

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  display.clearDisplay();
  display.display();
  delay(50);


pinMode(sensorgas, INPUT); 
pinMode(buzzer, OUTPUT); 

 SIM800L.begin(9600);  
 delay(1000);
 SIM800L.write("AT+CMGF=1\r\n");
 delay(1000);
 SIM800L.write("AT+CMGS=\"219********\"\r\n"); //mudar * por um número de telefone existente
 delay(1000);
 SIM800L.write("Sistema em funcionamento");
 delay(1000);
 SIM800L.write((char)26);
 delay(1000);
 
}

void loop() {

 int leituragas = analogRead(sensorgas); 
 
 delay(100); 

//exibindo temperatura e umidade vindas do sensor dht 11
DHT.read11(dht_dpin); //Lê as informações do sensor
display.setTextSize(1);
display.setTextColor(WHITE);


display.setCursor(0,15);
display.print("Temperatura ");
display.setCursor(0,25);
display.print(DHT.temperature);
display.print(" C");

display.setCursor(80,15);
display.println("Umidade");
display.setCursor(80,25);
display.print(DHT.humidity);
display.println(" %");

 if (leituragas > maxgas){
 digitalWrite(buzzer, HIGH); 
 delay(1000);
 digitalWrite(buzzer, LOW);

 //exibindo situação do gás no display
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(20,0);
 display.print("Vazamento de gas!");

  if (smsenviado==0){
  enviaSMS();
  smsenviado=1;
 }

  }

 
 else {
  digitalWrite(buzzer, LOW);

 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(30,0);
 display.print("Situacao ok");

 }

display.display();
delay(1000);
display.clearDisplay();


 }

void enviaSMS(){ //para enviar sms só 1 vez quando houver vazamento

  SIM800L.write("AT+CMGF=1\r\n");
  delay(500);
 
  //Serial.println("SIM800L Definir SMS para o número do destino");
  SIM800L.write("AT+CMGS=\"219********\"\r\n"); //mudar * por um número de telefone existente
  delay(500);
   
  //Serial.println("SIM800L Send SMS content");
  SIM800L.write("Vazamento de gas detectado no laboratorio!");
  delay(500);
  //Serial.println("Enviar Char Ctrl + Z / ESC para sair do menu SMS");
  SIM800L.write((char)26);
  delay(500);


}





  
  
  
