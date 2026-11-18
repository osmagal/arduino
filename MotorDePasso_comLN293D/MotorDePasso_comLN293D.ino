#include <Stepper.h>  //Biblioteca já disponível na IDE do Arduino

const int steps = 100; //Número de passos para o motor

Stepper motor(steps, 5, 4); //Pinos 5 e 4 do Arduino

void setup()
{
  motor.setSpeed(100);    //Velocidade da rotação do motor (RPM)
  Serial.begin(115200);
  pinMode(13, OUTPUT);  //Enable do L293D
  digitalWrite(13, LOW);
}

void loop()
{
  if (Serial.read() == '1')  //Gira para um lado
  {
    digitalWrite(13, HIGH);
    Serial.println("botao");
    motor.step(steps);
  }
  else if (Serial.read() == '2') //Gira para o outro lado
  {
    digitalWrite(13, HIGH);
    Serial.println("botao 1");
    motor.step(-steps);
  }
  else if (Serial.read() == '0')  //Fica parado
  {
    digitalWrite(13, LOW);
    Serial.println("Parado");
    motor.step(0);

  }
}


