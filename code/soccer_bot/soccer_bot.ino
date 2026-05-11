// Soccer Bot — FS-GT2 + L298N + Arduino Uno
// Car-style mixing: throttle + steering

// Motor pins
const int LMP = 5;
const int LMN = 6;
const int RMP = 10;
const int RMN = 11;

// Receiver pins
const int CH1_STEER = 2;
const int CH2_THROTTLE = 3;

// Tuning
const int CENTER = 1500;     // neutral pulse (µs)
const int DEADZONE = 60;     // ignore tiny stick noise around center
const int MAX_PWM = 200;     // cap top speed for 8th graders (0–255)

void setup() {
  pinMode(LMP, OUTPUT); pinMode(LMN, OUTPUT);
  pinMode(RMP, OUTPUT); pinMode(RMN, OUTPUT);
  pinMode(CH1_STEER, INPUT);
  pinMode(CH2_THROTTLE, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read pulses (timeout 25 ms so a lost signal doesn't hang the bot)
  int steer    = pulseIn(CH1_STEER,    HIGH, 25000);
  int throttle = pulseIn(CH2_THROTTLE, HIGH, 25000);

  // Failsafe: no signal → stop
  if (steer == 0 || throttle == 0) {
    drive(0, 0);
    return;
  }

  // Convert pulses to -255..+255
  int t = map(throttle, 1000, 2000, -MAX_PWM, MAX_PWM);
  int s = map(steer,    1000, 2000, -MAX_PWM, MAX_PWM);

  // Apply deadzone around center
  if (abs(throttle - CENTER) < DEADZONE) t = 0;
  if (abs(steer    - CENTER) < DEADZONE) s = 0;

  // Mix: left = throttle + steer, right = throttle - steer
  int left  = constrain(t + s, -MAX_PWM, MAX_PWM);
  int right = constrain(t - s, -MAX_PWM, MAX_PWM);

  drive(left, right);

  // Debug — open Serial Monitor at 9600 to tune
  Serial.print("T="); Serial.print(throttle);
  Serial.print(" S="); Serial.print(steer);
  Serial.print(" L="); Serial.print(left);
  Serial.print(" R="); Serial.println(right);
}

void drive(int left, int right) {
  // Left motor
  if (left >= 0) {
    analogWrite(LMP, left);  analogWrite(LMN, 0);
  } else {
    analogWrite(LMP, 0);     analogWrite(LMN, -left);
  }
  // Right motor
  if (right >= 0) {
    analogWrite(RMP, right); analogWrite(RMN, 0);
  } else {
    analogWrite(RMP, 0);     analogWrite(RMN, -right);
  }
}
