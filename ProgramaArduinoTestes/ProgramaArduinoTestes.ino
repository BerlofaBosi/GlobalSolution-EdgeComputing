/*
--------------------------------------------------------------------------------------
FIAP GLOBAL SOLUTION 2025 Primeiro Semestre - Engenharia de Software

Projeto: Acompanhamento das condições climáticas / pluviais para detecção de enchente

Alunos: Arthur Berlofa RM 564438 || Danilo Fernandes RM 561657
--------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------
Este programa tem a finalidade de servir como teste para o código em Python,
portanto, ele não retorna valores medidos em tempo real, apenas valores aleatórios
afins de simulação da comunicação Serial entre Arduino e Python.
--------------------------------------------------------------------------------------
*/ 


// Variavel Global -------------------------------------------------------------------
bool alerta = false;
float temperatura = 57.5;
float umidade = 56.5;
float nivelRio = 2.09;


// Programa Principal ----------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    String enviar = Serial.readStringUntil('\n');
    enviar.trim();
    if (enviar == "dados1") {
      Serial.println(temperatura);
    }

    if (enviar == "dados2") {
      Serial.println(umidade);
    }

    if (enviar == "dados3") {
      Serial.println(nivelRio);
    }

    if (enviar == "alerta") {
      alerta = !alerta;
      if (alerta) {
        Serial.println("ON");
      } else {
        Serial.println("OFF");
      } 
    }
    
    if (enviar == "teste") {
      Serial.println("Sucesso");
    }

  }

  digitalWrite(13, alerta);
  
}