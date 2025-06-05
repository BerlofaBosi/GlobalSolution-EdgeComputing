/*
--------------------------------------------------------------------------------------
FIAP GLOBAL SOLUTION 2025 Primeiro Semestre - Engenharia de Software

Projeto: Acompanhamento das condições climáticas / pluviais para detecção de enchente

Alunos: Arthur Berlofa RM 564438 || Danilo Fernandes RM 561657
--------------------------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------------------------
Códigos Serial para teste:
'teste'   - Utilizado para tester a comunicação serial. Retorna: Sucesso
'dados1'  - Retorna a temperatura
'dados2'  - Retorna a umidade
'dados3'  - Retorna o nível do rio
'alerta'  - Atualiza a variável bool alerta, mudando para o estado de emergência ou não. 
            Retorna o estado do alarme.

Para utilizar-os, copie o texto entre as aspas simples '' e cole no terminal Serial.
--------------------------------------------------------------------------------------
*/ 


// Inclusão das Bibliotecas ----------------------------------------------------------
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <HCSR04.h>

// Display LCD -----------------------------------------------------------------------
#define colunasDisplay 20
#define linhasDisplay 4
#define enderecoDisplay 0x27

LiquidCrystal_I2C lcd(enderecoDisplay, colunasDisplay, linhasDisplay);


// Sensor DHT ------------------------------------------------------------------------
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);


// Sensor HR-SR04 --------------------------------------------------------------------
#define trigPin 9
#define echoPin 10

UltraSonicDistanceSensor sensorDist(trigPin, echoPin);


// Buzzer ----------------------------------------------------------------------------
#define buzzerPin 3


// Declaração Variaveis Globais ------------------------------------------------------
float temperatura, umidade, nivelAgua;
bool alerta;


// Declaração Funções ----------------------------------------------------------------
void printDisplay(float _temp, float _humity, float _riverLevel, bool _alert); // Função que atualizará as informações no LCD, bem como ativar o buzzer.

// Programa Principal ----------------------------------------------------------------

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  dht.begin();

  Serial.begin(9600);

}

void loop() {
  // Realiza a leitura dos sensores
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();
  nivelAgua = sensorDist.measureDistanceCm() / 100; // Conversão para metros

  // Lógica para comunicação Serial com o código em Python
  if (Serial.available() > 0) {

    String enviar = Serial.readStringUntil('\n');
    enviar.trim();

    if (enviar == "dados1") {
      Serial.println(temperatura); // Envio da temperatura via Serial
    }

    if (enviar == "dados2") {
      Serial.println(umidade); // Envio da umidade via Serial
    }
    
    if (enviar == "dados3") {
      Serial.println(nivelAgua); // Envio do nível da água via Serial
    }

    if (enviar == "alerta") {
      alerta = !alerta; // Lógica para alterar o estado da variável alerta para o seu estado contrário
      if (alerta) {     // Teste lógico para printar na Serial o estado correto da variável
        Serial.println("ON");
      } else {
        Serial.println("OFF");
      } 
    }
    
    if (enviar == "teste") {
      Serial.println("Sucesso"); // Envio de mensagem padrão para realização de testes de comunicaçao
    }
  }

  printDisplay(temperatura, umidade, nivelAgua, alerta); // Atualiza o display com as medições mais atuais a cada ciclo

}


// Definição Funções -----------------------------------------------------------------
void printDisplay(float _temp, float _humity, float _riverLevel, bool _alert) {
  // Temperatura
  lcd.setCursor(0,0);
  lcd.print("Temperatura:");
  if (_temp >= 10) {
    lcd.setCursor(13, 0);
    lcd.print(" ");
    lcd.setCursor(14, 0);
    lcd.print(_temp, 1);
  } 
  else if (_temp > 0) {
    lcd.setCursor(13, 0);
    lcd.print("  ");
    lcd.setCursor(15, 0);
    lcd.print(_temp, 1);
  } 
  else {
    lcd.setCursor(13, 0);
    lcd.print(_temp, 2);
  }
  lcd.setCursor(18,0);
  lcd.print(" C");

  // Humidade
  lcd.setCursor(0,1);
  lcd.print("Humidade:");
  if (_humity < 10) {
    lcd.setCursor(14, 1);
    lcd.print(" ");
    lcd.setCursor(15, 1);
    lcd.print(_humity, 1);
  }
  else {
    lcd.setCursor(14, 1);
    lcd.print(_humity, 1);
  }
  lcd.setCursor(18, 1);
  lcd.print(" %");

  // Nível do Rio
  lcd.setCursor(0, 2);
  lcd.print("Nivel Rio:");
  lcd.setCursor(15, 2);
  lcd.print(_riverLevel, 1);
  lcd.setCursor(18, 2);
  lcd.print(" m");

  // Mensagem de alerta
  if (_alert) {
    tone(buzzerPin, 1000, 1000);
    lcd.setCursor(0, 3);
    lcd.print("ALERTA ALERTA ALERTA");
    delay(1000);
  }

  // Limpeza da mensagem de alerta
  lcd.setCursor(0, 3); lcd.print("                    ");
  delay(500);

}
