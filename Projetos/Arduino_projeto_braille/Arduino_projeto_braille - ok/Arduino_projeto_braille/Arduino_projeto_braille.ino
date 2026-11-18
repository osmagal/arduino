int led[] = {8, 9, 10, 11, 12, 13};
int botaoInc = 2;
int botaoDec = 3;
int botaoAlf = 4;
int botaoNum = 5;
int botaoSim = 6;
int botaoIncPressionado = 0;
int botaoDecPressionado = 0;
int botaoAlfPressionado = 0;
int botaoNumPressionado = 0;
int botaoSimPressionado = 0;
int anteriorInc = 0;
int anteriorDec = 0;
int anteriorAlf = 0;
int anteriorNum = 0;
int anteriorSim = 0;
int cont = 0;
boolean zerou = false;
boolean alfLigado = false;
boolean numLigado = false;
boolean simLigado = false;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
  }
  pinMode(botaoInc, INPUT);
  pinMode(botaoDec, INPUT);
  pinMode(botaoAlf, INPUT);
  pinMode(botaoNum, INPUT);
  pinMode(botaoSim, INPUT);
  Serial.begin(9600);
}

void loop() {
  botaoIncPressionado = digitalRead(botaoInc);
  botaoDecPressionado = digitalRead(botaoDec);
  botaoAlfPressionado = digitalRead(botaoAlf);
  botaoNumPressionado = digitalRead(botaoNum);
  botaoSimPressionado = digitalRead(botaoSim);
  ctrl_botoes();
  ctrl_bot_char();
  ctrl_alf();
  ctrl_sim();
}

void ctrl_botoes() {
  //controle do botao incrementa
  if ((anteriorInc == LOW) && (botaoIncPressionado == HIGH)) {
    cont++;
    zerou = false;
    Serial.print(cont);
  }
  anteriorInc = botaoIncPressionado;
  delay(120);
  //controle do botao decrementa
  if ((anteriorDec == LOW) && (botaoDecPressionado == HIGH)) {
    cont--;
    zerou = false;
    Serial.print(cont);
  }
  anteriorDec = botaoDecPressionado;
  delay(120);
}
void ctrl_bot_char() {
  //controle do botao alfabeto
  if ((anteriorAlf == LOW) && (botaoAlfPressionado == HIGH)) {
    cont = 1;
    zerou = false;
    Serial.print(cont);
    alfLigado = true;
    numLigado = false;
    simLigado = false;
  }
  anteriorAlf = botaoAlfPressionado;

  //controle do botao numero
  if ((anteriorNum == LOW) && (botaoNumPressionado == HIGH)) {
    cont = 1;
    zerou = false;
    Serial.print(cont);
    alfLigado = false;
    numLigado = true;
    simLigado = false;
  }
  anteriorNum = botaoNumPressionado;

  //controle do botao simbolo
  if ((anteriorSim == LOW) && (botaoSimPressionado == HIGH)) {
    cont = 27;
    zerou = false;
    Serial.print(cont);
    alfLigado = false;
    numLigado = false;
    simLigado = true;
  }
  anteriorSim = botaoSimPressionado;
}

void ctrl_alf() {
  if (alfLigado || numLigado) {
    if (!zerou) {
      for (int i = 0; i < 6; i++) {
        digitalWrite(led[i], LOW);
      }
      zerou = true;
    }
    if (cont < 1 && alfLigado) {
      cont = 26;
    }
    if (cont > 26 && alfLigado) {
      cont = 1;
    }
    if (cont < 1 && numLigado) {
      cont = 10;
    }
    if (cont > 10 && numLigado) {
      cont = 1;
    }
    switch (cont) {
      case 1://a
        digitalWrite(led[0], HIGH);
        break;
      case 2://b
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        break;
      case 3://c
        digitalWrite(led[0], HIGH);
        digitalWrite(led[3], HIGH);
        break;
      case 4://d
        digitalWrite(led[0], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 5://e
        digitalWrite(led[0], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 6://f
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[3], HIGH);
        break;
      case 7://g
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 8://h
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 9://i
        digitalWrite(led[1], HIGH);
        digitalWrite(led[3], HIGH);
        break;
      case 10://j
        digitalWrite(led[1], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 11://k
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        break;
      case 12://l
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        break;
      case 13://m
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        break;
      case 14://n
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 15://o
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 16://p
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        break;
      case 17://q
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 18://r
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 19://s
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        break;
      case 20://t
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 21://u
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 22://v
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 23://w
        digitalWrite(led[1], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 24://x
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 25://y
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 26://z
        digitalWrite(led[0], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      default:
        cont = 0;
    }
  }
}

void ctrl_sim() {
  if (simLigado) {
    if (!zerou) {
      for (int i = 0; i < 6; i++) {
        digitalWrite(led[i], LOW);
      }
      zerou = true;
    }
    if (cont < 27) {
      cont = 50;
    }
    switch (cont) {
      case 27://.
        digitalWrite(led[1], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 28://,
        digitalWrite(led[1], HIGH);
        break;
      case 29://;
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        break;
      case 30://:
        digitalWrite(led[1], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 31:///
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        break;
      case 32://?
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 33://!
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 34://@
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 35://#
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 36://+
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 37://-
        digitalWrite(led[1], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 38://*
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 39://"(abre aspas)
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 40://"(fecha aspas)
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 41://'(plica)
        digitalWrite(led[2], HIGH);
        break;
      case 42://<
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 43://>
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        break;
      case 44://(
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 45://)
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 46://capital
        digitalWrite(led[5], HIGH);
        break;
      case 47://_
        digitalWrite(led[2], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 48://and
        digitalWrite(led[0], HIGH);
        digitalWrite(led[1], HIGH);
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 49://letra
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      case 50://numero
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
        digitalWrite(led[4], HIGH);
        digitalWrite(led[5], HIGH);
        break;
      default:
        cont = 27;
    }
  }
}
