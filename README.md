# safelab
Projeto para monitoração de laboratórios com alarme via SMS, display e alarme sonoro com buzzer para evitar ocorrências com vazamentos de gás.

O sensor de gas MQ-2 detecta a presença de nível alarmante, conforme definido na lógica de programação e em seguida é enviado um alarme via SMS para a pessoa responsável pelo laboratório 1 vez.

O SMS é enviado somente uma vez devido a lógica implementada para evitar o envio de inúmeras mensagens, enviando, também, uma mensagem quando o sistema é inicializado alertando que o sistema está em funcionamento.

Simulou-se que haveria um display na frente de cada labratório informando sobre quantidades normais ou preocupantes de gás (vazamento) e também da temperatura e humidade do interior captadas através do sensor DHT11. Para enviar mensagens via SMS foi escolhido o módulo GSM SIM800L, e para controlar todo o processo utilizou-se o microcontrolador Arduino. Desta forma pretende-se evitar catástrofes envolvendo vazamentos de gás, alertando os responsáveis para tomar as medidas cabíveis.

Projeto desenvolvido em grupo para a disciplina de Introdução a Engenharia de Controle e Automação, buscando resolver problemas encontrados na universidade ou fora com automação. Grupo: Keith Fabre, Ana Luisa Rodrigues, Thiago Moutinho, Ney Rafael Guindane e Bismarck Brandi.

A apresentação do grupo com o funcionamento, testes utilizados, montagem no fritzing e o código oficial se encontram presentes.
