int rightsensor = 2;
int leftsensor = 3;

int rightmotor1 = 4;
int rightmotor2 = 5;
int leftmotor1 = 6;
int leftmotor2 = 7;

void setup()
{
  pinMode(rightmotor1, OUTPUT);
  pinMode(rightmotor2, OUTPUT);
  pinMode(leftmotor1, OUTPUT);
  pinMode(leftmotor2, OUTPUT);
}

void forward()
{
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);  
}

void turnright()
{
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, HIGH);
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);  
}

void turnleft()
{
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, HIGH);
}

void Stop()
{
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, LOW);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, LOW);
}

void loop()
{
  int rs_value = read_rightsensor();
  int ls_value = read_leftsensor();
  if ((rs_value < 1000) && (ls_value < 1000)){forward();}
  if ((rs_value < 1000) && (ls_value > 1000)){turnleft();}
  if ((rs_value > 1000) && (ls_value < 1000)){turnright();}
  if ((rs_value > 1000) && (ls_value > 1000)){Stop();}
}

int read_rightsensor()
{
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  pinMode(2, INPUT);
  long time = micros();
  while (digitalRead(rightsensor) == HIGH && micros() - time < 3000);
  int diff = micros() - time;
  return diff;
}

int read_leftsensor()
{
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  pinMode(3, INPUT);
  long time = micros();
  while (digitalRead(leftsensor) == HIGH && micros() - time < 3000);
  int diff = micros() - time;
  return diff;
}



    
        
    
