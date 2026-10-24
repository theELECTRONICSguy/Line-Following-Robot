const int L=2,R=3,ENA=5,ENB=6,IN1=7,IN2=8,IN3=9,IN4=10;
void motors(int left,int right){
  digitalWrite(IN1,left>=0); digitalWrite(IN2,left<0);
  digitalWrite(IN3,right>=0); digitalWrite(IN4,right<0);
  analogWrite(ENA,constrain(abs(left),0,255));
  analogWrite(ENB,constrain(abs(right),0,255));
}
void setup(){
  pinMode(L,INPUT);pinMode(R,INPUT);
  pinMode(ENA,OUTPUT);pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);pinMode(IN2,OUTPUT);pinMode(IN3,OUTPUT);pinMode(IN4,OUTPUT);
}
void loop(){
  bool left=digitalRead(L)==LOW, right=digitalRead(R)==LOW;
  if(!left&&!right) motors(150,150);
  else if(left&&!right) motors(-130,130);
  else if(!left&&right) motors(130,-130);
  else motors(0,0);
  delay(10);
}
