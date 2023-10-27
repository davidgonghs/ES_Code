int a = 6; // Arduino pins connected with 7 segment pins
int b = 5;
int c = 2;
int d = 3;
int e = 4;
int f = 7;
int g = 8;

void setup() {
  // Declaring all the pins as output
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

// Function to display a character on the 7-segment display
void displayCharacter(byte character) {
  digitalWrite(a, !bitRead(character, 0));  // Inverted logic for common cathode
  digitalWrite(b, !bitRead(character, 1));
  digitalWrite(c, !bitRead(character, 2));
  digitalWrite(d, !bitRead(character, 3));
  digitalWrite(e, !bitRead(character, 4));
  digitalWrite(f, !bitRead(character, 5));
  digitalWrite(g, !bitRead(character, 6));
}

void loop() {
  byte characters[] = {
    B01000000, //D
    B00001000,//A
    B01000001, //V
    B01111001,// = I
    B01000000, //D
  };

  for (int i = 0; i < 5; i++) {
    displayCharacter(characters[i]);
    delay(1000);
  }
}
