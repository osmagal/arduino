const int rodaVai = 16;
const int rodaVolta = 5;

void setup()
{
  pinMode(rodaVai , OUTPUT);
  pinMode(rodaVolta , OUTPUT);
}

void loop()
{
  motorVai(3000);
  para();
  motorVolta(3000);
  para();
}

void motorVai (int dist) {//1 ida e 2 volta
    analogWrite(rodaVolta, 1024);
    delay(dist);
}


void motorVolta (int dist) {//1 ida e 2 volta
    analogWrite(rodaVai, 1024);
    delay(dist);
}

void para() {
  analogWrite(rodaVai , 0);
  analogWrite(rodaVolta , 0);
  Serial.println("Parado");
}




