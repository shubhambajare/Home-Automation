
void forward() {
  digitalWrite(m11, 1);
  digitalWrite(m12, 0);
  digitalWrite(m21, 1);
  digitalWrite(m22, 0);

  Serial.println ("forward");
}

void backward() {
  digitalWrite(m11, 0);
  digitalWrite(m12, 1);
  digitalWrite(m21, 0);
  digitalWrite(m22, 1);
  Serial.println("backward");
}

void left() {
  digitalWrite(m11, 1);
  digitalWrite(m12, 0);
  digitalWrite(m21, 0);
  digitalWrite(m22, 0);
  Serial.println("left");
}
void right() {
  digitalWrite(m11, 0);
  digitalWrite(m12, 0);
  digitalWrite(m21, 1);
  digitalWrite(m22, 0);
  Serial.println("right");
}
void stop1() {
  digitalWrite(m11, 0);
  digitalWrite(m12, 0);
  digitalWrite(m21, 0);
  digitalWrite(m22, 0);
  Serial.println("stop");
}

void switch1on() {
  digitalWrite(16, 1);
  Serial.println("switch1on");
}
void switch1off() {
  digitalWrite(16, 0);
  Serial.println("switch1off");
}
void switch2on() {
  digitalWrite(5, 1);
  Serial.println("switch2on");
}
void switch2off() {
  digitalWrite(5, 0);
  Serial.println("switch2off");
}
void switch3on() {
  digitalWrite(15, 1);
  Serial.println("switch3on");
}
void switch3off() {

  digitalWrite(15, 0);
  Serial.println("switch3off");
}
