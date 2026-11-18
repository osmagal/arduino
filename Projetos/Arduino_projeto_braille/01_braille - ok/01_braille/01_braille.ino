int led[] = {8, 9, 10, 11, 12, 13};
int botao[] = {2, 3, 4, 5, 6};//inc,dec,alf,num,sim
int botaoPressionado[] = {0, 0, 0, 0, 0}; //inc,dec,alf,num,sim
int anterior[] = {0, 0, 0, 0, 0}; //inc,dec,alf,num,sim
boolean botLigado[] = {false, false, false}; //alf,num,sim
boolean zerou = false;
int cont = 0;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(led[i], OUTPUT);
    if (i < 5) {
      pinMode(botao[i], INPUT);
    }
  }

  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    botaoPressionado[i] = digitalRead(botao[i]);
  }
  ctrl_botoes();
  ctrl_bot_char();
  ctrl_alf();
  ctrl_sim();
}

void ctrl_botoes() {
  //controle do botao incrementa
  if ((anterior[0] == LOW) && (botaoPressionado[0] == HIGH)) {
    cont++;
    zerou = false;
    Serial.print(cont);
  }
  anterior[0] = botaoPressionado[0];
  delay(120);

  //controle do botao decrementa
  if ((anterior[1] == LOW) && (botaoPressionado[1] == HIGH)) {
    cont--;
    zerou = false;
    Serial.print(cont);
  }
  anterior[1] = botaoPressionado[1];
  delay(120);
}
void ctrl_bot_char() {
  //controle do botao alfabeto
  if ((anterior[2] == LOW) && (botaoPressionado[2] == HIGH)) {
    cont = 1;
    zerou = false;
    Serial.print(cont);
    botLigado[0] = true;
    botLigado[1] = false;
    botLigado[2] = false;
  }
  anterior[2] = botaoPressionado[2];

  //controle do botao numero
  if ((anterior[3] == LOW) && (botaoPressionado[3] == HIGH)) {
    cont = 1;
    zerou = false;
    Serial.print(cont);
    botLigado[0] = false;
    botLigado[1] = true;
    botLigado[2] = false;
  }
  anterior[3] = botaoPressionado[3];

  //controle do botao simbolo
  if ((anterior[4] == LOW) && (botaoPressionado[4] == HIGH)) {
    cont = 27;
    zerou = false;
    Serial.print(cont);
    botLigado[0] = false;
    botLigado[1] = false;
    botLigado[2] = true;
  }
  anterior[4] = botaoPressionado[4];
}

void ctrl_alf() {
  if (botLigado[0] || botLigado[1]) {
    if (!zerou) {
      for (int i = 0; i < 6; i++) {
        digitalWrite(led[i], LOW);
      }
      zerou = true;
    }
    if (cont < 1 && botLigado[0]) {
      cont = 26;
    }
    if (cont > 26 && botLigado[0]) {
      cont = 1;
    }
    if (cont < 1 && botLigado[1]) {
      cont = 10;
    }
    if (cont > 10 && botLigado[1]) {
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
  if (botLigado[2] == true) {
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


