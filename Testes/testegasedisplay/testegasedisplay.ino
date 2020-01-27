/*         OLED
SCL -------------- A5
SCA -------------- A4
VDD -------------- 5V
GND -------------- GND*/


/*   MQ 2 sensor de gás 
a0 -------- A0
gnd ------- GND
VCC -------- 5V
 */

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_Address 0x3C
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


#define sensorgas A0//sensor de gás no pino a0
#define buzzer 2 //buzzer no pino d2 
#define maxgas 500//valor max de gás normal 



void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  display.clearDisplay();
  display.display();
  delay(50);



pinMode(sensorgas, INPUT); 
pinMode(buzzer, OUTPUT); 
//Serial.begin(9600);

 
}

void loop() {

 int leituragas = analogRead(sensorgas); 
//Serial.print("Leitura: "); 
//Serial.println(leituragas);
delay(100); 

 if (leituragas > maxgas){
 //Serial.print("Vazamento de gás!");
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









  
  
  
  
  
  
  
  
