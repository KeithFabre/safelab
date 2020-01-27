
//  SCL -------------- A5
//  SCA -------------- A4
//  VDD -------------- 5V
//  GND -------------- GND 


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_Address 0x3C
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
 
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_Address);

  // draw scrolling text  // texto em scroll
  testscrolltext();
  delay(2000);
  display.clearDisplay();
}
 
void loop() {
  
}
void testscrolltext(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(3,0);
  display.clearDisplay();
  display.println("oi :)");
  display.display();
 
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}
