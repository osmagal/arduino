//int led = 13;
int botao = 0;
int botaoPressionado = 0;
int anterior = 0;
boolean botaoLigado = false;

void setup() {
  // put your setup code here, to run once:
  //pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
 debounce(botao);
 Serial.print("Botao: ");
 Serial.println(botaoLigado);
 Serial.print("Botao Pressionado: ");
 Serial.println(botaoPressionado);
}

void debounce(int b){
   botaoPressionado = digitalRead(b);//leitura do botao incrementa

  //verificar se o botao Incrementa esta pressionado
  if ((anterior == LOW) && (botaoPressionado == HIGH)) {
    if (botaoLigado == false) {
      botaoLigado = true;
    }else{
      botaoLigado = false;
    }
  }
  anterior = botaoPressionado;
}

void aLed(int estado){
  if(estado){
    Serial.println("Led Ligado");
  }else{
    Serial.println("Led Desligado");
  }
}

