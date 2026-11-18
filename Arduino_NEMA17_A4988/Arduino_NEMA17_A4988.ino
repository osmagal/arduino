// define números de pinos
const int stepPin = 5 ; 
const int dirPin = 16 ; 
 
void setup ( ) {  
  // Define os dois pinos como Saídas
  pinMode ( stepPin, OUTPUT ) ;
  pinMode ( dirPin, OUTPUT ) ;
  Serial.begin(115200);
  digitalWrite(dirPin, HIGH); 
}

void loop() {
    // permite que o motor se mova em uma direção particular
    
    
    // faz 200 pulsos para fazer uma rotação de ciclo completo
    //for(int x = 0; x < 200; x++) 
    {
        //Serial.println(x);
        digitalWrite(stepPin,HIGH); 
        delay(500);
        digitalWrite(stepPin,LOW); 
        delay(500);
        
    }/*
    delay(1000); //1 segundo de delay para inverter a direção
    //Muda a direção da rotação
    digitalWrite(dirPin,LOW); 
    
    // faz 400 pulsos para fazer duas rotações de ciclo completo 
    for(int x = 0; x < 70; x++) {
        digitalWrite(stepPin,HIGH);
        delayMicroseconds(500);
        digitalWrite(stepPin,LOW);
        delayMicroseconds(500);
    }
    delay(1000); //1 segundo de delay para inverter a direção*/
}


