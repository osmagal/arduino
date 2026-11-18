int ldr[] = {A0, A1, A2, A3, A4};
int vet[] = {5, 4, 3, 2};
int valorLDR1 = 0;
int valorLDR2 = 0;
int valorLDR3 = 0;
int valorLDR4 = 0;
int valorLDR5 = 0;

int maior = 0;
void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ldr[i], INPUT);
    if (i < 4)
      pinMode(vet[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorLDR1 = analogRead(ldr[0]);
  valorLDR2 = analogRead(ldr[1]);
  valorLDR3 = analogRead(ldr[2]);
  valorLDR4 = analogRead(ldr[3]);
  valorLDR5 = analogRead(ldr[4]);
  valorLDR1 = map(valorLDR1, 0, 1024, 255, 0);
  valorLDR2 = map(valorLDR2, 0, 1024, 255, 0);
  valorLDR3 = map(valorLDR3, 0, 1024, 255, 0);
  valorLDR4 = map(valorLDR4, 0, 1024, 255, 0);
  valorLDR5 = map(valorLDR5, 0, 1024, 255, 0);
  if (maior < valorLDR1) {
    maior = valorLDR1;
    Serial.println("Maior: LDR1");
  }
  if (maior < valorLDR2) {
    maior = valorLDR2;
    Serial.println("Maior: LDR2");
  }
  if (maior < valorLDR3) {
    maior = valorLDR3;
    Serial.println("Maior: LDR3");
  }
  if (maior < valorLDR4) {
    maior = valorLDR4;
    Serial.println("Maior: LDR4");
  }
  if (maior == valorLDR1 && maior== valorLDR4) {//pos 1
    digitalWrite(vet[0], HIGH);
    digitalWrite(vet[1], LOW);
    digitalWrite(vet[2], LOW);
    digitalWrite(vet[3], LOW);
    delay(100);
  }
  if (maior == valorLDR1 && maior != valorLDR4) {//pos 2
    digitalWrite(vet[0], HIGH);
    digitalWrite(vet[1], LOW);
    digitalWrite(vet[2], HIGH);
    digitalWrite(vet[3], LOW);
    delay(100);
  }
  if (maior == valorLDR2 && maior == valorLDR1) {//pos 3
    digitalWrite(vet[0], LOW);
    digitalWrite(vet[1], LOW);
    digitalWrite(vet[2], HIGH);
    digitalWrite(vet[3], LOW);
    delay(100);
  }
  
  if (maior == valorLDR2 && maior != valorLDR1) {//pos 4
    digitalWrite(vet[0], LOW);
    digitalWrite(vet[1], HIGH);
    digitalWrite(vet[2], HIGH);
    digitalWrite(vet[3], LOW);
    delay(100);
  }

  if (maior == valorLDR2 && maior == valorLDR3) {//pos 5
    digitalWrite(vet[0], LOW);
    digitalWrite(vet[1], HIGH);
    digitalWrite(vet[2], HIGH);
    digitalWrite(vet[3], HIGH);
    delay(100);
  }

  if (maior == valorLDR3 && maior != valorLDR3) {//pos 6
    digitalWrite(vet[0], LOW);
    digitalWrite(vet[1], HIGH);
    digitalWrite(vet[2], LOW);
    digitalWrite(vet[3], HIGH);
    delay(100);
  }
  if (maior == valorLDR3 && maior == valorLDR4) {//pos 7
    digitalWrite(vet[0], LOW);
    digitalWrite(vet[1], LOW);
    digitalWrite(vet[2], LOW);
    digitalWrite(vet[3], HIGH);
    delay(100);
  }
  if (maior == valorLDR4 && maior != valorLDR3) {//pos 8
    digitalWrite(vet[0], HIGH);
    digitalWrite(vet[1], LOW);
    digitalWrite(vet[2], LOW);
    digitalWrite(vet[3], HIGH);
    delay(100);
  }
}


