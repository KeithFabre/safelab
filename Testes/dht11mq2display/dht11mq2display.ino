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

#define sensorgas A0//sensor de gás no pino a0
#define buzzer 2 //buzzer no pino d2 
#define maxgas 500//valor max de gás normal 

//dht 11

#include <dht.h>
#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1
dht DHT; //Inicializa o sensor

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  display.clearDisplay();
  display.display();
  delay(50);


pinMode(sensorgas, INPUT); 
pinMode(buzzer, OUTPUT); 


 
 
}

void loop() {

 int leituragas = analogRead(sensorgas); 
//Serial.print("Leitura: "); 
//Serial.println(leituragas);
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

//exibindo estado do gás
 if (leituragas > maxgas){
 digitalWrite(buzzer, HIGH); 
 delay(1000);
 digitalWrite(buzzer, LOW);

 //exibindo situação do gás no display
 display.setTextSize(1);
 display.setTextColor(WHITE);
 display.setCursor(20,0);
 display.print("Vazamento de gas!");

 }
 else{ 
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









  
  
  
  
