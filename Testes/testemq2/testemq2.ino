//Teste sensor mq02 

int sensorgas = A0;//sensor de gás no pino a0
int buzzer = 4; //buzzer no pino d2 
int maxgas = 400;//valor max de gás normal 
 
void setup(){

pinMode(sensorgas, INPUT); 
pinMode(buzzer, OUTPUT); 
Serial.begin(9600);
}
void loop(){

int leituragas = analogRead(sensorgas); 
Serial.print("Leitura: "); 
Serial.println(leituragas);
 
 if (leituragas > maxgas){
 Serial.print("Vazamento de gás!");
 digitalWrite(buzzer, HIGH); 
 delay(1000);
 digitalWrite(buzzer, LOW);
 }
 else{ 
 digitalWrite(buzzer, LOW);
 }
 delay(100); 
}
