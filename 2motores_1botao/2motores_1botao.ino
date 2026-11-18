int satura1 = 13;
int satura2 = 12;
int positivo = 11;
int botao = 10;
int anterior = LOW;
int botaoPressionado = LOW;
boolean botaoLigado = false;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(satura1, OUTPUT);
  pinMode(satura2, OUTPUT);
  pinMode(positivo, OUTPUT);
  pinMode(positivo, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  botaoPressionado = digitalRead(botao);
  if((anterior == LOW)&& (botaoPressionado == HIGH)){
    if(!botaoLigado)
      botaoLigado = true;
    else
      botaoLigado = false;
  }
  anterior = botaoPressionado;
  if(botaoLigado){
      digitalWrite(positivo, HIGH);
      digitalWrite(satura2, LOW);
      digitalWrite(satura1, HIGH);
      delay(3000);
      digitalWrite(satura1, LOW);
      digitalWrite(satura2, HIGH);
      delay(3000);
  }else{
      digitalWrite(satura1, LOW);
      digitalWrite(satura2, LOW);
      digitalWrite(positivo, LOW);
  }
}

