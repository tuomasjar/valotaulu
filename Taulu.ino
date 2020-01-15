
#define Led1 3
#define Led2 5
#define Led3 9
#define Led4 6
#define Led5 10
#define brightness 255
//int brightness;
int light;
boolean started,onoff;
long aika,aika2,aika3;
int leds[5]={3,5,9,6,10};
long tauko,tauko2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //for debugging reasons
pinMode(13,OUTPUT); //initialise led pins
pinMode(Led1,OUTPUT);
pinMode(Led2,OUTPUT);
pinMode(Led3,OUTPUT);
pinMode(Led4,OUTPUT);
pinMode(Led5,OUTPUT);
//brightness = analogRead(1)/4; //for brightness control add a potentiometer to A1 pin
started=false;
tauko=random(300000,600000); //first easter egg in 5-10 minutes
tauko2=random(3600000,7200000); //second easter egg between 1-2 hours
Serial.println("Begin"); //debugging
}

void loop() {
  // put your main code here, to run repeatedly:
light = analogRead(0); //read the brightness of the room where the painting is
//brightness=analogRead(1)/4;
Serial.println(String(light)); //more debugging
if(light<550)onoff=true;//if it is dark enough turn on the lights
if(light>600)onoff=false; //if it is light enough turn off the lights
//There should be a little difference in starting and stopping brighness so it won't turn on and off constantly, if brightness is near the limit.

if(onoff){
  if(!started){ //if starting up
    delay(5000); 
    for(int i=0;i<brightness;i+=5){ //light the leds slowly using pwm
      analogWrite(Led1,i);
      delay(100);
    }
    delay(random(1000,10000)); //random delay between the lights
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
    started=true; //the starting process is done. no need to do it again.
    aika=millis(); //reset timer.
  }else{ //if the starting has already been done keep an eye on timer to do the easter eggs
    if(millis()-aika>tauko){ //if timer1 has had enought time
      int i=random(0,4); //choose a led at random
      analogWrite(leds[i],0); //blink it randomly
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
      tauko=random(300000,600000); //new random time for the next one
      aika=millis(); //reset timer
    }else if(millis()-aika2>tauko2){ //if timer2 has had enought time
      for(int i=0;i<4;i++){ //blink all the leds in order
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
      tauko2=random(3600000,7200000); //new random time for the next one
      aika2=millis(); //reset timer
    }else{ //keep the lights on
      analogWrite(leds[0],brightness);
      analogWrite(leds[1],brightness);
      analogWrite(leds[2],brightness);
      analogWrite(leds[3],brightness);
      analogWrite(leds[4],brightness);
    }
   }
  }else{ 
    started=false; //turn off lights.
    analogWrite(Led1,0);
    analogWrite(Led2,0);
    analogWrite(Led3,0);
    analogWrite(Led4,0);
    analogWrite(Led5,0);
    aika=millis();
    aika2=millis();
  }
  
}
