//방향과 각도
int xPin= 0;
int yPin= 1;
int zPin= 2;
int x=0;
int y=0;
int z=0;
int angx=0;
int angy=0;
int angz=0;
int minVal = 265;
int maxVal = 402;
//버튼
int pushButton1 = 8;
int buttonState1 = 0;
//led1
int redLEDPin1 = 11;
int greenLEDPin1 = 10;
int blueLEDPin1 = 9;
//led2
int redLEDPin2 = 3;
int greenLEDPin2 = 5;
int blueLEDPin2 = 6;

void setup(){
Serial.begin(9600);
pinMode(pushButton1, INPUT);
pinMode(redLEDPin1,OUTPUT);
pinMode(greenLEDPin1,OUTPUT);
pinMode(blueLEDPin1,OUTPUT);
pinMode(redLEDPin2,OUTPUT);
pinMode(greenLEDPin2,OUTPUT);
pinMode(blueLEDPin2,OUTPUT);
}

void loop(){
 
//방향과각도  
x= analogRead(xPin);
y= analogRead(yPin);
z= analogRead(zPin);
int xAng = map(x, minVal, maxVal, -90, 90);
int yAng = map(y, minVal, maxVal, -90, 90);
int zAng = map(z, minVal, maxVal, -90, 90);
Serial.write("\n");
Serial.print("X= ");
Serial.print( x);
Serial.print("| Y= ");
Serial.print( y) ;
Serial.print("| Z= ");
Serial.println(z ) ;
Serial.print("angX= ");
Serial.print( angx);
Serial.print("| angY= ");
Serial.print( angy) ;
Serial.print("| angZ= ");
Serial.println(angz ) ;
Serial.write("\n");

//RAD_TO_DEG = Radius / moving (around 57.29) distance , PI = 3.14
angx = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
angy = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
angz = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

//버튼과 led
buttonState1 = digitalRead(pushButton1);
Serial.print("PushButton1= ");
Serial.print(buttonState1);

Serial.write("\n");
if (buttonState1 ==1) {
  setColor1(0,0,0);
  setColor2(0,0,0);
  Serial.write("led print : no");
  }
else {
  setColor1(255,255,255);
  setColor2(255,255,255);
  Serial.write("led print : yes");
  }
delay(1000);
}

//Color Function
void setColor1(int red, int green, int blue) {
analogWrite(redLEDPin1, 255-red);
analogWrite(greenLEDPin1, 255-green);
analogWrite(blueLEDPin1, 255-blue);
}
void setColor2(int red, int green, int blue) {
analogWrite(redLEDPin2, 255-red);
analogWrite(greenLEDPin2, 255-green);
analogWrite(blueLEDPin2, 255-blue);
}
