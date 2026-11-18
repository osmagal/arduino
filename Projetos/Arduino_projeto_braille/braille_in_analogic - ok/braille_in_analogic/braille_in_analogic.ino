int bobsup[] = {8, 9, 10, 11, 12, 13};
int bobinf[] = {2, 3, 4, 5, 6, 7};
int botao[] = {A0, A1, A2, A3, A4};//inc,dec,alf,num,sim
int botaoPressionado[] = {0, 0, 0, 0, 0}; //inc,dec,alf,num,sim
int anterior[] = {0, 0, 0, 0, 0}; //inc,dec,alf,num,sim
boolean botLigado[] = {false, false, false}; //alf,num,sim
boolean zerou = false;
boolean mostrou = false;
int cont = 0;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(bobsup[i], OUTPUT);
    pinMode(bobinf[i], OUTPUT);
    if (i < 5) {
      pinMode(botao[i], INPUT);}
  }Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    botaoPressionado[i] = digitalRead(botao[i]);}
  ctrl_botoes();
  ctrl_bot_char();
  ctrl_alfenum();
  ctrl_sim();
}

void ctrl_botoes() {
  if ((anterior[0] == LOW) && (botaoPressionado[0] == HIGH)) {//controle do botao incrementa
    cont++;
    zerou = false;
    mostrou = false;
    Serial.print(cont);}
  anterior[0] = botaoPressionado[0];
  delay(50);
  if ((anterior[1] == LOW) && (botaoPressionado[1] == HIGH)) {//controle do botao decrementa
    cont--;
    zerou = false;
    mostrou = false;
    Serial.print(cont);}
  anterior[1] = botaoPressionado[1];
  delay(50);
}

void ctrl_bot_char() {
  if ((anterior[2] == LOW) && (botaoPressionado[2] == HIGH)) {//controle do botao alfabeto
    cont = 1;
    zerou = false;
    mostrou = false;
    Serial.print(cont);
    botLigado[0] = true;
    botLigado[1] = false;
    botLigado[2] = false;}
  anterior[2] = botaoPressionado[2];
  if ((anterior[3] == LOW) && (botaoPressionado[3] == HIGH)) {//controle do botao numero
    cont = 1;
    zerou = false;
    mostrou = false;
    Serial.print(cont);
    botLigado[0] = false;
    botLigado[1] = true;
    botLigado[2] = false;}
  anterior[3] = botaoPressionado[3];
  if ((anterior[4] == LOW) && (botaoPressionado[4] == HIGH)) {//controle do botao simbolo
    cont = 27;
    zerou = false;
    Serial.print(cont);
    botLigado[0] = false;
    botLigado[1] = false;
    botLigado[2] = true;}
  anterior[4] = botaoPressionado[4];
}

void ctrl_alfenum() {
  if (botLigado[0] || botLigado[1]) {
    if (cont < 1 && botLigado[0]) {
      cont = 26;}
    if (cont > 26 && botLigado[0]) {
      cont = 1 ;}
    if (cont < 1 && botLigado[1]) {
      cont = 0;}
    if (cont > 0 && botLigado[1]) {
      cont = 1 ;}
    if (!zerou) {
      for (int i = 0; i < 6; i++) {
        digitalWrite(bobinf[i], HIGH);}
      delay(100);
      for (int i = 0; i < 6; i++) {
        digitalWrite(bobinf[i], LOW);}
      zerou = true;}
    if (!mostrou) {
      switch (cont) {
        case 1://a
          digitalWrite(bobsup[0], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          break;
        case 2://b
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          break;
        case 3://c
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[3], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[3], LOW);
          break;
        case 4://d
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 5://e
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 6://f
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[3], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[3], LOW);
          break;
        case 7://g
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 8://h
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 9://i
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[3], HIGH);
          delay(1000);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[3], LOW);
          break;
        case 10://j
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 11://k
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[2], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          break;
        case 12://l
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[2], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[2], LOW);
          break;
        case 13://m
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[3], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[3], LOW);
          break;
        case 14://n
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 15://o
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 16://p
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[3], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[3], LOW);
          break;
        case 17://q
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 18://r
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 19://s
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[3], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[3], LOW);
          break;
        case 20://t
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[4], HIGH);
          delay(1000);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[4], LOW);
          break;
        case 21://u
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[5], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[5], LOW);
          break;
        case 22://v
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[5], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[5], LOW);
          break;
        case 23://w
          digitalWrite(bobsup[1], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[4], HIGH);
          digitalWrite(bobsup[5], HIGH);
          delay(1000);
          digitalWrite(bobsup[1], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[4], LOW);
          digitalWrite(bobsup[5], LOW);
          break;
        case 24://x
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[5], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[5], LOW);
          break;
        case 25://y
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[3], HIGH);
          digitalWrite(bobsup[4], HIGH);
          digitalWrite(bobsup[5], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[3], LOW);
          digitalWrite(bobsup[4], LOW);
          digitalWrite(bobsup[5], LOW);
          break;
        case 26://z
          digitalWrite(bobsup[0], HIGH);
          digitalWrite(bobsup[2], HIGH);
          digitalWrite(bobsup[4], HIGH);
          digitalWrite(bobsup[5], HIGH);
          delay(1000);
          digitalWrite(bobsup[0], LOW);
          digitalWrite(bobsup[2], LOW);
          digitalWrite(bobsup[4], LOW);
          digitalWrite(bobsup[5], LOW);
          break;
        default:
          cont = 0;
      } mostrou = true;
    }
  }
}

void ctrl_sim() {
  if (botLigado[2] == true) {
    if (cont < 27) {
      cont = 50;}
    if (!zerou) {
      for (int i = 0; i < 6; i++) {
        digitalWrite(bobinf[i], HIGH);}
      delay(100);
      for (int i = 0; i < 6; i++) {
        digitalWrite(bobinf[i], LOW);}
      zerou = true;}
    switch (cont){
      case 27://.
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[4], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[4], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 28://,
        digitalWrite(bobsup[1], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        break;
      case 29://;
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[2], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[2], LOW);
        break;
      case 30://:
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[4], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[4], LOW);
        break;
      case 31:///
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[3], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[3], LOW);
        break;
      case 32://?
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 33://!
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[4], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[4], LOW);
        break;
      case 34://@
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[3], HIGH);
        digitalWrite(bobsup[4], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[3], LOW);
        digitalWrite(bobsup[4], LOW);
        break;
      case 35://#
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[3], HIGH);
        digitalWrite(bobsup[4], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[3], LOW);
        digitalWrite(bobsup[4], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 36://+
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[4], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[4], LOW);
        break;
      case 37://-
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[4], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[4], LOW);
        break;
      case 38://*
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[4], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[4], LOW);
        break;
      case 39://"(abre aspas)
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 40://"(fecha aspas)
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[4], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[4], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 41://'(plica)
        digitalWrite(bobsup[2], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        break;
      case 42://<
        digitalWrite(bobsup[0], HIGH);
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[0], LOW);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 43://>
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[3], HIGH);
        digitalWrite(bobsup[4], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[3], LOW);
        digitalWrite(bobsup[4], LOW);
        break;
      case 44://(
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[4], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[4], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 45://)
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[4], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[4], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 46://capital
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[5], LOW);
        break;
      case 47://_
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 48://and
        digitalWrite(bobsup[0], HIGH);
        digitalWrite(bobsup[1], HIGH);
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[3], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[0], LOW);
        digitalWrite(bobsup[1], LOW);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[3], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 49://letra
        digitalWrite(bobsup[4], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[4], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      case 50://numero
        digitalWrite(bobsup[2], HIGH);
        digitalWrite(bobsup[3], HIGH);
        digitalWrite(bobsup[4], HIGH);
        digitalWrite(bobsup[5], HIGH);
        delay(1000);
        digitalWrite(bobsup[2], LOW);
        digitalWrite(bobsup[3], LOW);
        digitalWrite(bobsup[4], LOW);
        digitalWrite(bobsup[5], LOW);
        break;
      default:
        cont = 27;
    }
  }
}
