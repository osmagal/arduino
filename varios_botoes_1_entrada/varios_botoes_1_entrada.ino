int led = 13;
int botao = A0;
int valorLido = 0;
int cont = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
  valorLido = analogRead(botao) / 4;
  //Serial.println(valorLido);
  if (valorLido > 204 && valorLido <= 255) {
      delay(300);
      cont++;
      Serial.println(cont);
  }
  if((cont%2) == 0){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}
