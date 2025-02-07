const int LED_PIN = 13;  // Pin de la LED
int nbrPas = 256;
int time = 2048 / nbrPas;
int delai = 2000;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}
void allume() {
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
  Serial.println("Allume -2349185");
  digitalWrite(LED_PIN, LOW);
  delay(150);
}
void clignote() {
  for (int i = 0; i < 5; i++) {
    // Allumage de la LED
    digitalWrite(LED_PIN, HIGH);
    // Attente de 250 millisecondes
    delay(250);
    // Extinction de la LED
    digitalWrite(LED_PIN, LOW);
    // Attente de 250 millisecondes
    delay(250);
  }
  Serial.println("Clignote -2349185");
}

void variation() {
  for (int i = nbrPas; i >= 0; i--) {
    analogWrite(LED_PIN, i);
    delay(time);
  }
}

void arret() {
  digitalWrite(LED_PIN, LOW);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  allume();
  clignote();
  variation();
  arret();
}
