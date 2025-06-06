# GlobalSolution-EdgeComputing
Repositório referente a entrega da Global Solution - Edge Computing.


## **Alunos:**
- Arthur Berlofa RM564438
- Danilo Fernandes RM561657


## **Link's úteis**
1. [Link do Wokwi](https://wokwi.com/projects/432888167705070593)
2. [Link do Vídeo Demonstrativo](https://www.canva.com/design/DAGpitlOA9U/h1Tms38oJa4lg5fXB3HZiw/watch?utm_content=DAGpitlOA9U&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h4db21520fd)
3. [Acesso ao Código Principal](ProgramaArduino/ProgramaArduino.ino)  
4. [Acesso ao Código de Testes](ProgramaArduinoTestes/ProgramaArduinoTestes.ino)  


## **Descrição do problema:**

As enchentes representam um risco significativo para comunidades próximas a rios e áreas de drenagem inadequada. A falta de monitoramento eficiente pode resultar em perdas materiais, impactos ambientais e ameaças à segurança da população. O desafio reside na necessidade de uma solução acessível e automatizada para acompanhar as condições climáticas e pluviais em tempo real, permitindo uma resposta rápida diante de possíveis eventos críticos. Este projeto busca solucionar essa problemática ao integrar sensores ambientais e sistemas de alerta, fornecendo informações precisas que ajudam na tomada de decisão e na prevenção de desastres.


## **Visão Geral da Solução:**

A implementação utiliza sensores DHT22 e HCSR04 para coletar temperatura, umidade e nível do rio, respectivamente. Um display LCD é empregado para exibir os dados, garantindo uma interface visual intuitiva. O sistema opera em tempo real, respondendo a comandos enviados via comunicação serial para obtenção de medições ou ativação de alertas. A modularidade do código permite fácil integração com outras aplicações, como o programa Python que gerencia requisições e análise dos dados. 

![Screenshot 2025-06-01 043904](https://github.com/user-attachments/assets/b70dded8-79fc-4be9-982b-d010bca5498a)

Assim como mencionado, este projeto trata-se de uma solução integrada com o código Python. O Arduino desempenha o papel de coleta de dados, enquanto o programa Python encarrega-se de receber esses dados, tratá-los, documentar os horários e as medições em um arquivo .txt, além de identificar quando os valores se tornam perigosos. Em caso de alerta, o sistema gera notificações tanto para o microcontrolador quanto para o usuário que estiver com a interface aberta.

A comunicação entre Arduino e Python ocorre via Serial, garantindo que os dados sejam transmitidos somente quando solicitados. Esse mecanismo otimiza o processamento e evita sobrecarga, permitindo um fluxo de informações eficiente e preciso.


## **Guia para Simulação:**

Para simular o funcionamento do sistema, é necessário configurar os sensores e estabelecer a comunicação entre o microcontrolador e o código Python. O programa pode ser testado por meio do terminal serial, onde comandos como **'dados1', 'dados2' e 'dados3'** retornam as medições de **temperatura, umidade e nível do rio.** O comando **'alerta'** altera o estado do alerta, ativando ou desativando o buzzer. Para verificar a comunicação, o comando **'teste'** pode ser enviado, e o sistema retornará **"Sucesso"**, confirmando o funcionamento adequado.

![image](https://github.com/user-attachments/assets/16a06abb-c974-4a25-90ef-7edff47cbb0c)

