
#include <Servo.h>
// Renomeamos cada servo para o aplicativo de controle
Servo myservo1; // Pra cima e Pra baixo (porta 5)
Servo myservo2; // Garra (porta 6)
Servo myservo3; // Gira para esquerda e direita (porta 7)
Servo myservo4; // Esticar Braço


char unChar;


// Vamos obter um fluxo de variáveis ​​para ser lido pelo arduino a partir do aplicativo de controle
String readString;

void setup() {
  // Esses pinos devem ser pinos PWM para que os servos funcionem corretamente
  myservo1.attach(5); // Pra cima e Pra baixo (porta 5)
  myservo2.attach(6); // Garra (porta 6)
  myservo3.attach(7); // Gira para esquerda e direita (porta 7)
  myservo4.attach(3); // Esticar Braço (porta 3)
  Serial.begin(9600); // Porta serial
}
void loop() {
  if (Serial.available()) {  // identifica o primeiro caractere na porta serial
    unChar = Serial.read();

    if (unChar == 'A') { // Enviamos a letra "A" pelo bluetooth, tipo ligue o motor 1
      motor1();
    }

    if (unChar == 'B') { // Enviamos a letra "B pelo bluetooth, tipo ligue o motor 2
      motor2();
    }

    if (unChar == 'C') { // Enviamos a letra "C" pelo bluetooth, tipo ligue o motor 3
      motor3();
    }
    if (unChar == 'D') { // Enviamos a letra "D" pelo bluetooth, tipo ligue o motor 4
      motor4();
    }

  }
}

void motor1() {
  delay(5);
  while (Serial.available()) { //Agora os dados numéricos do ângulo do servomotor são recebidos
    //delayMicroseconds(100);
    char c = Serial.read();  // Letras gravadas na porta serial
    readString += c;         // Cada letra preenche uma variável
  }
  if (readString.length() > 0) {  //O comprimento da variável "string" (texto) é verificado:
    Serial.println(readString.toInt());  //Agora enviamos dados para a  porta serial e servos motores
    myservo1.write(readString.toInt());
    readString = ""; // Apagar conteúdo da variável tipo "string" (texto)
  }
}

void motor2() {
  delay(5);
  while (Serial.available()) {
    //delayMicroseconds(100);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    myservo2.write(readString.toInt());
    readString = "";
  }
}

void motor3() {
  delay(5);
  while (Serial.available()) {
    //delayMicroseconds(100);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    myservo3.write(readString.toInt());
    readString = "";
  }
}
void motor4() {
  delay(5);
  while (Serial.available()) {
    //delayMicroseconds(100);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    myservo4.write(readString.toInt());
    readString = "";
  }
}
