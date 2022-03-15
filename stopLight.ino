#define RED 4
#define GREEN 2
#define YELLOW 3
#define BUTTON A0

unsigned int blinkTime = 500;
unsigned int timeWait = 3000;
unsigned int remainingTime = 5000;

void setup() {

  pinMode(BUTTON, INPUT);

  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  digitalWrite(RED, 0);
  digitalWrite(GREEN, 1);
  digitalWrite(YELLOW, 0);

}

void loop() {
  
  boolean button = digitalRead(BUTTON);
  
  if (button) stopLightCycle();

}

void stopLightCycle() {

  for (int i = 4; i != 0; i--) {
    digitalWrite(GREEN, 0);
    delay(500);
    digitalWrite(GREEN, 1);
    delay(500);
  }
    
  digitalWrite(GREEN, 0);
  digitalWrite(YELLOW, 1);
  delay(1000);
  digitalWrite(YELLOW, 0);
  delay(1000);
  digitalWrite(RED, 1);
  
  delay(timeWait);

  digitalWrite(YELLOW, 1);
  delay(1000);
  digitalWrite(YELLOW, 0);
  digitalWrite(RED, 0);
  digitalWrite(GREEN, 1);

  delay(remainingTime);
  
}