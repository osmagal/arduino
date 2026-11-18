#include <IRremote.h>

int RECV_PIN = 11;
float armazenavalor;
int motor_left[] = {3, 4};
int motor_right[] = {5, 6};

IRrecv irrecv(RECV_PIN);
decode_results results;

// ————————————————————————— Setup
void setup() {
  Serial.begin(9600);

  // Setup motors
  int i;
  for (i = 0; i < 2; i++) {
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
    irrecv.enableIRIn(); // Inicializa o receptor IR
  }

}

// ————————————————————————— Loop
void loop() {

  if (irrecv.decode(&results))
  {
    Serial.print("Valor lido : ");
    Serial.println(results.value, HEX);
    armazenavalor = (results.value);
    Serial.println(armazenavalor);
    if (armazenavalor == 0x1FE649B)
    {
      Serial.println("Frente");
      drive_forward();
    }
    if (armazenavalor == 0x1FE14EB)
    {
      Serial.println("Traz");
      drive_backward();
    }
    if (armazenavalor == 0x1FEE41B)
    {
      Serial.println("Esquerda");
      turn_left();
    }
    if (armazenavalor == 0x1FEA45B)
    {
      Serial.println("Direita");
      turn_right();
    }
    if (armazenavalor == 0x1FEB04F)
    {
      Serial.println("Para");
      motor_stop();
    }

    irrecv.resume(); //Le o próximo valor
  }

}

// ————————————————————————— Drive

void motor_stop() {
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], LOW);

  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], LOW);
  delay(25);
}

void drive_forward() {
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_left[1], LOW);

  digitalWrite(motor_right[0], HIGH);
  digitalWrite(motor_right[1], LOW);
}

void drive_backward() {
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], HIGH);

  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], HIGH);
}

void turn_left() {
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], HIGH);

  digitalWrite(motor_right[0], HIGH);
  digitalWrite(motor_right[1], LOW);
}

void turn_right() {
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_left[1], LOW);

  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], HIGH);
}


