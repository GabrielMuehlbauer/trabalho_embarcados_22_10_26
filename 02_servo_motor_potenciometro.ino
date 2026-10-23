
#include <Servo.h>

int pos = 0;
int sensorValue = 0;
int velocidadeValue = 0;
int tempo = 0;
int i = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9);

  pinMode(A5, INPUT);
  pinMode(A4, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // Potenciômetro 1: controla o ângulo
  sensorValue = analogRead(A5);
  pos = map(sensorValue, 0, 1023, 0, 180);

  // Movimento de ida
  for (i = 0; i <= pos; i++) {
    velocidadeValue = analogRead(A4);
    tempo = map(velocidadeValue, 0, 1023, 100, 15);

    servo_9.write(i);
    delay(tempo);
  }

  // Movimento de volta
  for (i = pos; i >= 0; i--) {
    velocidadeValue = analogRead(A4);
    tempo = map(velocidadeValue, 0, 1023, 100, 15);

    servo_9.write(i);
    delay(tempo);
  }

  Serial.print("Angulo: ");
  Serial.println(pos);

  Serial.print("Potenciometro velocidade: ");
  Serial.println(velocidadeValue);

  Serial.print("Delay: ");
  Serial.println(tempo);
}
