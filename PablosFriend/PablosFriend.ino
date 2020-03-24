const int right1[] = {A0, 2};// right 1
const int right2[] = {A1, 4};// left 1
const int left1[] = {A2, 7};//right 2
const int left2[] = {A3, 8};// left 2  direction A3, step 8;

int servoPin = 3;
int minP = 630; // right
int maxP = 2500; // left
int midP = (maxP + minP) / 2.; // mid
int whatnow = midP;

int byteIn = 0;

void setup() {

  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);

  pinMode(left1[0], OUTPUT);
  pinMode(left1[1], OUTPUT);
  digitalWrite(left1[0], LOW);
  digitalWrite(left1[1], LOW);

  pinMode(left2[0], OUTPUT);
  pinMode(left2[1], OUTPUT);
  digitalWrite(left2[0], LOW);
  digitalWrite(left2[1], HIGH);

  pinMode(right1[0], OUTPUT);
  pinMode(right1[1], OUTPUT);
  digitalWrite(right1[0], LOW);
  digitalWrite(right1[1], LOW);

  pinMode(right2[0], OUTPUT);
  pinMode(right2[1], OUTPUT);
  digitalWrite(right2[0], LOW);
  digitalWrite(right2[1], LOW);
}

void loop() {
  servoPulse(servoPin, whatnow);
  moveforward(600, 1000);
  //  control();
}


void control() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    byteIn = Serial.read();
    switch (byteIn) {
      case 's':
        Serial.println("backward recieved.");
        movebackward(600, 1000);
        break;
      case 'w':
        Serial.println("forward recieved.");
        moveforward(600, 1000);
        break;
      case 'a':
        Serial.println("left recieved.");
        moveleft(600, 1000);
        break;
      case 'd':
        Serial.println("right recieved.");
        moveright(600, 1000);
        break;
      default:
        break;
    }
  }
}

void moveforward(int steps, int sec) {
  digitalWrite(left1[1], LOW);
  digitalWrite(left2[1], HIGH);
  digitalWrite(right1[1], LOW);
  digitalWrite(right2[1], LOW);
  movin(steps, sec);
}

void movebackward(int steps, int sec) {
  digitalWrite(left1[1], HIGH);
  digitalWrite(left2[1], LOW);
  digitalWrite(right1[1], HIGH);
  digitalWrite(right2[1], HIGH);
  movin(steps, sec);
}

void moveleft(int steps, int sec) {
  digitalWrite(left1[1], LOW);
  digitalWrite(left2[1], HIGH);
  digitalWrite(right1[1], LOW);
  digitalWrite(right2[1], LOW);
  movinl(steps, sec);
}

void moveright(int steps, int sec) {
  digitalWrite(left1[1], LOW);
  digitalWrite(left2[1], HIGH);
  digitalWrite(right1[1], LOW);
  digitalWrite(right2[1], LOW);
  movinr(steps, sec);
}

void movin(int steps, int sec) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(left1[0], HIGH);
    digitalWrite(left2[0], HIGH);
    digitalWrite(right1[0], HIGH);
    digitalWrite(right2[0], HIGH);
    delayMicroseconds(sec);
    digitalWrite(left1[0], LOW);
    digitalWrite(left2[0], LOW);
    digitalWrite(right1[0], LOW);
    digitalWrite(right2[0], LOW);
    delayMicroseconds(sec);
  }
}

void movinr(int steps, int sec) {
  for (int i = 0; i < steps; i++) {
    if (i % 5 == 0)
    {
      digitalWrite(right2[0], HIGH);
      digitalWrite(right1[0], HIGH);
      digitalWrite(left2[0], HIGH);
      digitalWrite(left1[0], HIGH);
      delayMicroseconds(sec);
      digitalWrite(right2[0], LOW);
      digitalWrite(right1[0], LOW);
      digitalWrite(left2[0], LOW);
      digitalWrite(left1[0], LOW);
      delayMicroseconds(sec);
    } else {
      digitalWrite(right2[0], HIGH);
      digitalWrite(right1[0], HIGH);
      delayMicroseconds(sec);

      digitalWrite(right2[0], LOW);
      digitalWrite(right1[0], LOW);
      delayMicroseconds(sec);
    }
  }
}

void movinl(int steps, int sec) {
  for (int i = 0; i < steps; i++) {
    if (i % 5 == 0)
    {
      digitalWrite(right2[0], HIGH);
      digitalWrite(right1[0], HIGH);
      digitalWrite(left2[0], HIGH);
      digitalWrite(left1[0], HIGH);
      delayMicroseconds(sec);
      digitalWrite(right2[0], LOW);
      digitalWrite(right1[0], LOW);
      digitalWrite(left2[0], LOW);
      digitalWrite(left1[0], LOW);
      delayMicroseconds(sec);
    } else {
      digitalWrite(left2[0], HIGH);
      digitalWrite(left1[0], HIGH);
      delayMicroseconds(sec);

      digitalWrite(left2[0], LOW);
      digitalWrite(left1[0], LOW);
      delayMicroseconds(sec);
    }
  }
}

void servoPulse(int sPin, int p) {
  digitalWrite(sPin, HIGH);
  delayMicroseconds(p); // 600-2400
  digitalWrite(sPin, LOW);
  delay(20);
}
