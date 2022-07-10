#define step_X 2
#define step_Y 3
#define step_Z 4
#define dir_X 5
#define dir_Y 6
#define dir_Z 7
#define Enable 8
#define limit_X 9
#define limit_Y 12
#define limit_Z 11
#define led 13


void setup() {
  Serial.begin(9600);
  pinMode(step_X, OUTPUT); // Step
  pinMode(step_Y, OUTPUT); // Dir - chiều quay
  pinMode(step_Z, OUTPUT); // Dir - chiều quay
  pinMode(dir_X, OUTPUT); // Step
  pinMode(dir_Y, OUTPUT); // Dir - chiều quay
  pinMode(dir_Z, OUTPUT); // Dir - chiều quay
  pinMode(Enable, OUTPUT); // Enable
  pinMode(led, INPUT);
  pinMode(A0, INPUT); // Cảm biến NS04 (XOAY TRỤC Y)

  pinMode(limit_X, INPUT_PULLUP);
  //pinMode(limit_Y, INPUT);
  pinMode(limit_Z, INPUT_PULLUP);
  digitalWrite(Enable, HIGH); // Set Enable low - Enable mức thấp
}

void loop() {

  if (Serial.available() > 0) {
    String stringOne = Serial.readString(); // read the incoming data as string

    // you can also look for a substring in the middle of a string:
    String name_motor = stringOne.substring(0, 1);
    String str_step = stringOne.substring(1);
    int so_vong = str_step.toInt();

    Serial.println(stringOne);
    Serial.print("name_motor:");
    Serial.println(name_motor);
    Serial.print("count_step:");
    Serial.println(so_vong);
    if ((name_motor == "Y") && (so_vong != 0)) {
      _motorY(so_vong);
    }
    if ((name_motor == "Y") && (so_vong == 0)) {
      _resetY();
    }
    if ((name_motor == "Z") && (so_vong != 0)) {
      _motorZ(so_vong);
    }
    if ((name_motor == "Z") && (so_vong == 0)) {
      _resetZ();
    }
    if ((name_motor == "X") && (so_vong != 0)) {
      _motorX(so_vong);
    }
      if ((name_motor == "X") && (so_vong == 0)) {
      _resetX();
    }
    delay(500);
  }
}

void _motorX(int so_vong) {
  digitalWrite(Enable, LOW); //
  if (so_vong < 0) {
    Serial.println("Motor X quay lui");
    digitalWrite(dir_X, HIGH); // Set Dir high  - Set chiều quay mức cao
  } else {
    Serial.println("Motor X quay toi");
    digitalWrite(dir_X, LOW); // Set Dir high  - Set chiều quay mức cao
  }
  for (int j = 0; j < abs(so_vong); j++) {
    for (int x = 0; x < 100; x++) // lặp 4096 lần
    {
      digitalWrite(step_X, LOW); // Output high - xung mức cao
      delayMicroseconds(80); // Trễ 1ms
      digitalWrite(step_X, HIGH); // Output low - xung mức thấp
      delayMicroseconds(80); // Trễ 1ms
    }
  }
  Serial.println("Da xong!");
  delay(500);
}


void _resetX() {
  int vLimitx = digitalRead(limit_X);
  while (vLimitx != 0) {
    vLimitx = digitalRead(limit_X);
    int max_X = 80;
    digitalWrite(dir_X, HIGH); // Set Dir high  - Set chiều quay mức cao
    for (int x = 0; x < max_X; x++) // lặp 4096 lần
    {

      digitalWrite(step_X, LOW); // Output high - xung mức cao
      delayMicroseconds(80); // Trễ 1ms
      digitalWrite(step_X, HIGH); // Output low - xung mức thấp
      delayMicroseconds(80); // Trễ 1ms
    }

  }
  Serial.print(vLimitx);

  Serial.print("RESET X xong! ");
  delay(200);
}

void _resetY() {
  Serial.print("Thuc hien xoay reset Y");

  int vLimitY = analogRead(A0); // đọc cảm biến NS04
  Serial.println(vLimitY);

  while (vLimitY > 10) {
    vLimitY = analogRead(A0);
    Serial.print("SN04: ");

    Serial.println(vLimitY);

    int max_Y = 40;
    digitalWrite(Enable, LOW); //
    digitalWrite(dir_Y, HIGH); // Set Dir high  - Set chiều quay mức cao
    for (int j = 0; j < max_Y; j++) {

      for (int x = 0; x < 20; x++) // lặp 4096 lần
      {

        digitalWrite(step_Y, LOW); // Output high - xung mức cao
        delayMicroseconds(500); // Trễ 1ms
        digitalWrite(step_Y, HIGH); // Output low - xung mức thấp
        delayMicroseconds(500); // Trễ 1ms
      }
       vLimitY = analogRead(A0);
        Serial.println(vLimitY);

      if (vLimitY < 5) {
        break;
      }
    }
    delay(100);
    //delayMicroseconds(500); // Trễ 1ms

  }
  Serial.print(vLimitY);

  Serial.print("RESET Y xong! ");
  delay(200);
  /*
  //digitalWrite(Enable, LOW); //
  digitalWrite(dir_Y, LOW); // Set Dir high  - Set chiều quay mức cao
  for (int j = 0; j < 800; j++) {

    for (int x = 0; x < 5; x++) // lặp 4096 lần
    {

      digitalWrite(step_Y, LOW); // Output high - xung mức cao
      delayMicroseconds(240); // Trễ 1ms
      digitalWrite(step_Y, HIGH); // Output low - xung mức thấp
      delayMicroseconds(240); // Trễ 1ms
    }

    vLimitY = analogRead(A0);
    if (vLimitY == 0) {

      break;
    }
    delayMicroseconds(500); // Trễ 1ms

  }
  */
  Serial.print("QUAY THEM VE CHINH GIUA ");

  for (int x = 0; x < 2600; x++) // lặp 4096 lần
  {

    digitalWrite(step_Y, LOW); // Output high - xung mức cao
    delayMicroseconds(200); // Trễ 1ms
    digitalWrite(step_Y, HIGH); // Output low - xung mức thấp
    delayMicroseconds(200); // Trễ 1ms
  }
}
void _motorY(int so_vong) {
  digitalWrite(Enable, LOW); //
  if (so_vong < 0) {
    Serial.println("Motor Y quay lui");
    digitalWrite(dir_Y, HIGH); // Set Dir high  - Set chiều quay mức cao
  } else {
    Serial.println("Motor Y quay toi");
    digitalWrite(dir_Y, LOW); // Set Dir high  - Set chiều quay mức cao
  }
  for (int j = 0; j < abs(so_vong); j++) {
    for (int x = 0; x < 100; x++) // lặp 4096 lần
    {
      digitalWrite(step_Y, LOW); // Output high - xung mức cao
      delayMicroseconds(120); // Trễ 1ms
      digitalWrite(step_Y, HIGH); // Output low - xung mức thấp
      delayMicroseconds(120); // Trễ 1ms
    }
  }
  Serial.println("Da xong!");
  delay(500);

}

void _resetZ() {
  int vLimitz = digitalRead(limit_Z);
  while (vLimitz != 0) {
    vLimitz = digitalRead(limit_Z);
    int max_Y = 80;
    digitalWrite(dir_Z, LOW); // Set Dir high  - Set chiều quay mức cao
    for (int x = 0; x < max_Y; x++) // lặp 4096 lần
    {

      digitalWrite(step_Z, LOW); // Output high - xung mức cao
      delayMicroseconds(400); // Trễ 1ms
      digitalWrite(step_Z, HIGH); // Output low - xung mức thấp
      delayMicroseconds(400); // Trễ 1ms
    }

  }
  Serial.print(vLimitz);

  Serial.print("RESET Z xong! ");
  delay(200);
}

void _motorZ(int so_vong) {
  digitalWrite(Enable, LOW); //
  if (so_vong < 0) {
    Serial.println("Motor Z quay lui");
    digitalWrite(dir_Z, LOW); // Set Dir high  - Set chiều quay mức thap - Z QUAY XUONG 
  } else {
    Serial.println("Motor Z quay toi"); // 
    digitalWrite(dir_Z, HIGH); // Set Dir high  - Set chiều quay mức cao - Z QUAY LEN 
  }
  for (int j = 0; j < abs(so_vong); j++) {
    for (int x = 0; x < 80; x++) // lặp 4096 lần
    {
      digitalWrite(step_Z, LOW); // Output high - xung mức cao
      delayMicroseconds(400); // Trễ 1ms
      digitalWrite(step_Z, HIGH); // Output low - xung mức thấp
      delayMicroseconds(400); // Trễ 1ms
    }
  }
  Serial.println("Da xong!");
  delay(500);

}
