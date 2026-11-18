#include <AccelStepper.h>

// Define os motores.
// AccelStepper::DRIVER - seta o tipo de controladora, no caso um driver, SMC-U-PRO
AccelStepper stepperX(AccelStepper::DRIVER,5,16);

void setup()
{
// habilita os pinos de enable do motor
   stepperX.setEnablePin(4);

// seta a a velocidade máxima do motor
   stepperX.setMaxSpeed(100);
}

void loop()
{
// prepara o motore para girar em uma direção...
// "manda" girar o motor -2000 steps. O valor legativo significa giro no sentido contrário
// aos ponteiros do relógio.
// Obs: o comando não gira o motor, só diz que é para girar. O giro efetivo é no loop abaixo
    stepperX.moveTo(-2000);
    stepperX.setSpeed(100);// seta a velocidade de giro em passos/s.
    //stepperY.moveTo(-2000);
    //stepperY.setSpeed(1000);

// esse é o loop que move o motor até a posição 2000. Observe que a rotina não
// fica bloqueada no stepperX.runSpeed, ou seja, ele dá um passo e sai.
//Aí vc pode fazer outras coisas, como por exemplo acionar o giro de outros motores,
// como eu fiz.
// Mas o que quer que vc coloque dentro do while tem que ser rápido, porque
// senão vai atrasar o giro dos motores. Você pode colocar, por exemplo, um botão de
// parada imediata, a ser testado dentro do loop, ou um sensor de fim de curso.
while (stepperX.currentPosition() != -2000)
{
stepperX.runSpeed();
}

// o código abaixo é análogo, só que gira na direção contrária, agora.

    stepperX.moveTo(2000);
    stepperX.setSpeed(100);
// move os motores até a posição -2000
while (stepperX.currentPosition() != 2000)
{
    stepperX.runSpeed();
}
}
