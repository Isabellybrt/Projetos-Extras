// Código de um labirinto feito com arduino e sensores sonar

#include <Servo.h>

Servo servoSuperior;  
Servo servoInferior;

int minimo = 85;
int maximo = 100;
int pos = 0; 
int fim = 0;
int posicaoServoInferior = 92; 
int posicaoServoSuperior = 92; 

void setup() {
  servoSuperior.attach(9);
  servoInferior.attach(8);

}

void loop() {
  posicaoInicial();
  if(fim == 0){
    caminhoDireitaTras(500);
    fim = 1;
    posicaoInicial();
  }
}

void posicaoInicial(){
  posicionarServoSuperior(92);
  posicionarServoInferior(92);
}

void caminhoDireitaTras(int tempoDeEspera){
  paraTras(0);
  paraDireita(0);
  delay(5000);
  paraEsquerda(tempoDeEspera);
  paraFrente(tempoDeEspera);
  paraDireita(tempoDeEspera);
  paraEsquerda(tempoDeEspera);
  paraTras(tempoDeEspera);
  paraFrente(tempoDeEspera);
  paraDireita(tempoDeEspera);
  paraEsquerda(tempoDeEspera);
  paraDireita(tempoDeEspera);
}

void caminhoDireitaFrente(int tempoDeEspera){
  paraFrente(0);
  paraDireita(0);
  delay(5000);
  paraEsquerda(tempoDeEspera);
  paraTras(tempoDeEspera);
  paraDireita(tempoDeEspera);
  paraEsquerda(tempoDeEspera);
  paraDireita(tempoDeEspera);
  paraFrente(tempoDeEspera);
  paraTras(tempoDeEspera);
  paraEsquerda(tempoDeEspera);
  caminhoDireitaTras(tempoDeEspera);
}


void paraTras(int tempoDeEspera){  
  posicionarServoSuperior(maximo);
  delay(tempoDeEspera);
}

void paraFrente(int tempoDeEspera){
  posicionarServoSuperior(minimo);
  delay(tempoDeEspera);
}

void paraDireita(int tempoDeEspera){
  posicionarServoInferior(maximo);
  delay(tempoDeEspera);
}

void paraEsquerda(int tempoDeEspera){
  posicionarServoInferior(minimo);
  delay(tempoDeEspera);
}

void posicionarServoInferior(int posicao){
  int passo;
  int tempoDeEspera = 200;
  if(posicaoServoInferior < posicao){
    for (passo = posicaoServoInferior; passo <= posicao; passo += 1) {
      servoInferior.write(passo);              
      delay(tempoDeEspera);
    }
  }else{
    for (passo = posicaoServoInferior; passo >= posicao; passo -= 1) {
      servoInferior.write(passo);              
      delay(tempoDeEspera);
    }
  }
}

void posicionarServoSuperior(int posicao){
  int passo;
  int tempoDeEspera = 200;
  if(posicaoServoSuperior < posicao){
    for (passo = posicaoServoSuperior; passo <= posicao; passo += 1) {
      servoSuperior.write(passo);              
      delay(tempoDeEspera);
    }
  }else{
    for (passo = posicaoServoSuperior; passo >= posicao; passo -= 1) {
      servoSuperior.write(passo);              
      delay(tempoDeEspera);
    }
  }
}
