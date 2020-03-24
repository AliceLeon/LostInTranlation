#include <Servo.h>
const int left1[] = {A1, 4};
const int left2[] = {A3, 8};
const int right1[] = {A0, 2};
const int right2[] = {A2, 7};// step A2, direction 8;

const int head1_ = 5;
const int head2_ = 6;
const int waist_ = 3;

//int servoPin = 6;
int minP = 630; // right
int maxP = 2500; // left
int midP = (maxP + minP) / 2.; // mid
int whatnow = midP;

Servo waist;
Servo head1;
Servo head2;

int byteIn = 0;

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;

boolean movingservo1 = false;
boolean movingservo2 = false;
boolean movingservo3 = false;

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

  waist.attach(waist_);
  head1.attach(head1_);
  head2.attach(head2_);

}

void loop() {
//  servoPulse(servoPin, whatnow);
  control();
  if (movingservo1) {
    moveWaist();
  }
  if (movingservo2) {
    moveHead1();
  }
  if (movingservo3) {
    moveHead2();
  }
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
      case 'i':
        Serial.println("moving waist");
        movingservo1 = !movingservo1;
        break;
      case 'o':
        Serial.println("moving head1");
        movingservo2 = !movingservo2;
        break;
      case 'p':
        Serial.println("right head2");
        movingservo3 = !movingservo3;
        break;
      default:
        break;
    }
  }
}

void moveWaist() {
  for (pos1 = 45; pos1 <= 135; pos1 += 1) {
    waist.write(pos1);
    delay(15);
  }
  for (pos1 = 135; pos1 <= 45; pos1 -= 1) {
    waist.write(pos1);
    delay(15);
  }
}
void moveHead1() {
  for (pos2 = 45; pos2 <= 135; pos2 += 1) {
    head1.write(pos2);
    delay(5);
  }
  for (pos2 = 135; pos2 <= 45; pos2 -= 1) {
    head1.write(pos2);
    delay(5);
  }
}
void moveHead2() {
  for (pos3 = 45; pos3 <= 135; pos3 += 1) {
    head2.write(pos3);
    delay(15);
  }
  for (pos3 = 45; pos3 <= 135; pos3 -= 1) {
    head2.write(pos3);
    delay(15);
  }
}
void moveforward(int steps, int sec) {
  digitalWrite(left1[1], LOW);
  digitalWrite(left2[1], LOW);
  digitalWrite(right1[1], LOW);
  digitalWrite(right2[1], LOW);
  movin(steps, sec);
}

void movebackward(int steps, int sec) {
  digitalWrite(left1[1], HIGH);
  digitalWrite(left2[1], HIGH);
  digitalWrite(right1[1], HIGH);
  digitalWrite(right2[1], HIGH);
  movin(steps, sec);
}

void moveleft(int steps, int sec) {
  digitalWrite(left1[1], LOW);
  digitalWrite(left2[1], LOW);
  digitalWrite(right1[1], LOW);
  digitalWrite(right2[1], LOW);
  movinl(steps, sec);
}

void moveright(int steps, int sec) {
  digitalWrite(left1[1], LOW);
  digitalWrite(left2[1], LOW);
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
