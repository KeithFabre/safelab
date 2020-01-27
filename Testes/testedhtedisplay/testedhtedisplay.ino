//          OLED
//  SCL -------------- A5
//  SCA -------------- A4
//  VDD -------------- 5V
//  GND -------------- GND

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_Address 0x3C
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#include <dht.h>
#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1
dht DHT; //Inicializa o sensor


void setup() {
  
  
  display.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  display.clearDisplay();
  display.display();
  delay(50);
  
  

}

void loop() {

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

display.display();
delay(1000);
display.clearDisplay();
 
}
  
  
  
  
  
  
  
  



