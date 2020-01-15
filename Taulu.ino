
#define Led1 3
#define Led2 5
#define Led3 9
#define Led4 6
#define Led5 10
#define brightness 255
//int brightness;
int light;
boolean started;
long aika,aika2,aika3;
int leds[5]={3,5,9,6,10};
long tauko,tauko2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(Led1,OUTPUT);
pinMode(Led2,OUTPUT);
pinMode(Led3,OUTPUT);
pinMode(Led4,OUTPUT);
pinMode(Led5,OUTPUT);
//brightness = analogRead(1)/4;
started=false;
tauko=random(300000,600000);
tauko2=random(3600000,7200000);
Serial.println("Begin");
}

void loop() {
  // put your main code here, to run repeatedly:
light = analogRead(0);
//brightness=analogRead(1)/4;
Serial.println(String(light));
if(light<550){
  if(!started){
    delay(5000);
    for(int i=0;i<brightness;i+=5){
      analogWrite(Led1,i);
      delay(100);
    }
    delay(random(1000,10000));
    for(int i=0;i<brightness;i+=5){
      analogWrite(Led2,i);
      delay(100);
    }
    delay(random(1000,10000));
    for(int i=0;i<brightness;i+=5){
      analogWrite(Led3,i);
      delay(100);
    }
    delay(random(1000,10000));
    for(int i=0;i<brightness;i+=5){
      analogWrite(Led4,i);
      delay(100);
    }
    delay(random(1000,10000));
    for(int i=0;i<brightness;i+=5){
      analogWrite(Led5,i);
      delay(100);
    }
    started=true;
    aika=millis();  
  }else{
    if(millis()-aika>tauko){
      int i=random(0,4);
      analogWrite(leds[i],0);
      delay(random(250,1000));
      analogWrite(leds[i],brightness);
      delay(random(250,1000));
      analogWrite(leds[i],0);
      delay(random(250,1000));
      analogWrite(leds[i],brightness);
      delay(random(250,1000));
      analogWrite(leds[i],0);
      delay(random(250,1000));
      analogWrite(leds[i],brightness);
      delay(random(250,1000));
      analogWrite(leds[i],0);
      delay(random(250,1000));
      analogWrite(leds[i],brightness);
      delay(random(250,1000));
      analogWrite(leds[i],0);
      delay(random(250,1000));
      analogWrite(leds[i],brightness);
      delay(random(250,1000));
      analogWrite(leds[i],0);
      delay(random(250,1000));
      analogWrite(leds[i],brightness);
      tauko=random(300000,600000);
      aika=millis();
    }else if(millis()-aika2>tauko2){
      for(int i=0;i<4;i++){
        analogWrite(leds[0],0);
        delay(500);
        analogWrite(leds[0],brightness);
        analogWrite(leds[1],0);
        delay(500);
        analogWrite(leds[1],brightness);
        analogWrite(leds[2],0);
        delay(500);
        analogWrite(leds[2],brightness);
        analogWrite(leds[3],0);
        delay(500);
        analogWrite(leds[3],brightness);
        analogWrite(leds[4],0);
        delay(500);
        analogWrite(leds[4],brightness);
        analogWrite(leds[5],0);
        delay(500);
        analogWrite(leds[5],brightness);
        analogWrite(leds[4],0);
        delay(500);
        analogWrite(leds[4],brightness);
        analogWrite(leds[3],0);
        delay(500);
        analogWrite(leds[3],brightness);
        analogWrite(leds[2],0);
        delay(500);
        analogWrite(leds[2],brightness);
        analogWrite(leds[1],0);
        delay(500);
        analogWrite(leds[1],brightness);
        analogWrite(leds[0],0);
        delay(500);
        analogWrite(leds[0],brightness);
      }
      tauko2=random(3600000,7200000);
      aika2=millis();
    }else{
      analogWrite(leds[0],brightness);
      analogWrite(leds[1],brightness);
      analogWrite(leds[2],brightness);
      analogWrite(leds[3],brightness);
      analogWrite(leds[4],brightness);
    }
   }
  }else  if(light>650){
    started=false;
    analogWrite(Led1,0);
    analogWrite(Led2,0);
    analogWrite(Led3,0);
    analogWrite(Led4,0);
    analogWrite(Led5,0);
  }
}
