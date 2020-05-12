# :microscope:safelab
Project for monitoring labs with alarms via SMS, display and buzzer to avoid gas leak ocurrences.

## :open_file_folder:This repo. contains:
<ul>
  <li> Code of the functioning project ("sensoresdisplaysms" folder)
  <li> Circuit and components chosen ("Funcionamento" folder)
  <li> Code used to test components ("Testes" folder)
  <li> Presentation given by the group
</ul>

## :star2:Goals
This project aims to prevent catastrophes involving gas leaks inside laboratories, warning who is responsible for the lab with SMS messages and who is around it with sonore alarms and a display with informations about the room (gas situation, temperature and humidity). 

## :books:Motivation
The motivation for creating this project was given by the discipline of Introduction on Controll and Automation Engeneering at UFRJ, where the group (Keith, Ana Luisa Rodrigues, Bismarck Brandi, Ney Rafael Guindane and Thiago Moutinho) was challenged to create soluctions for known problems at the university. 

## :mag_right:Components
<ol>
  <li> MQ-2 Gas sensor 
  <li> DHT11 Temperature and humidity sensor 
  <li> SIM800L GSM Module
  <li> 128x64 Oled Display
  <li> Arduino Uno
 </ol>
  The following picture contains the circuit simulated on fritzing.
 
 ![safelabfzz](https://user-images.githubusercontent.com/55497871/81624919-d5a28c80-93cd-11ea-83c1-85fc057065dc.png)
 
 ## :sound:Operation
 
 MQ-2 gas sensor detects the presence of gas on an alarming level, previously defined on the programing logic, and then sends an SMS message alarming the responsible of the laboratory only once, due to the logic implemented to prevent sending countless messages while there is a gas leak. A text message is also sent when the system is initiated alerting that the system is functioning and ready to detect.
 A display was used to simulate a screen in front of the lab informing normal or preoccupying amounts of gas and also the temperature and humidity inside the room, beeing also capable to identify fires with little changes on the code. 
The following pictures ilustrate the system operating on regular situations ("Situacao ok") and gas leak ("Vazamento de gas")

Normal Situation:
![funciona](https://user-images.githubusercontent.com/55497871/81625075-3df16e00-93ce-11ea-8414-4ac2b68ef26f.png)

Gas leak: 
![alarme](https://user-images.githubusercontent.com/55497871/81625069-3a5de700-93ce-11ea-8401-c0cb193be49e.png)






