
const int PIEZO = 8;
const int LDR = A0;
const int LASER = 7;

const int SOM_AGUDO = 1080;
const int SOM_GRAVE = 810;

const int LIMIAR = 100;

int luzAnterior = 0;
int luzAtual = 0;

void setup() {
  pinMode(PIEZO, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(LASER, OUTPUT);

  Serial.begin(9600);

  // Liga o laser
  digitalWrite(LASER, HIGH);

  delay(1000);
  luzAnterior = analogRead(LDR);
}

void loop() {
  luzAtual = analogRead(LDR);

  int diferenca = luzAnterior - luzAtual;

  Serial.print("Luz: ");
  Serial.print(luzAtual);
  Serial.print(" | Queda: ");
  Serial.println(diferenca);

  if (diferenca > LIMIAR) {
    tone(PIEZO, SOM_AGUDO);
    delay(300);

    tone(PIEZO, SOM_GRAVE);
    delay(300);

    noTone(PIEZO);
  }

  luzAnterior = analogRead(LDR);
  delay(50);
}
