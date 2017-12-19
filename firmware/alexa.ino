
#include <FastLED.h>

#define NUM_LEDS 44
#define STRIP1 0
#define STRIP2 1
#define STRIP3 2
#define STRIP4 3
#define DELAY 50

FASTLED_USING_NAMESPACE

int testled = D7;
int counter = 0;

String flag = "";
String color = "off";

uint8_t rainbowDelay = 15;
uint8_t hue = 0;
uint8_t deltahue = 10;
uint8_t brightness = 175;

CRGB strip1[NUM_LEDS];
CRGB strip2[NUM_LEDS];
CRGB strip3[NUM_LEDS];
CRGB strip4[NUM_LEDS];

// Turn on/off LEDs
int controlled(String args){
    
    color = args;
    
    Serial.println();
    Serial.print("Color: ");
    Serial.print(color);

    setColor(color);
    Particle.variable("color", color);
    
    Particle.publish("controlled Called", args);

    return 1;
}

void setColor(String Color){
    if(color == "test"){
        flag = "test";
        fill_solid(strip1, NUM_LEDS, CRGB::Red);
        fill_solid(strip2, NUM_LEDS, CRGB::Green);
        fill_solid(strip3, NUM_LEDS, CRGB::White);
        fill_solid(strip4, NUM_LEDS, CRGB::Blue);
        FastLED.show();
    }
    else if(color == "red"){
        flag = "";
        fill_solid(strip1, NUM_LEDS, CRGB::Red);
        fill_solid(strip2, NUM_LEDS, CRGB::Red);
        fill_solid(strip3, NUM_LEDS, CRGB::Red);
        fill_solid(strip4, NUM_LEDS, CRGB::Red);
        FastLED.show();
    }
    else if(color == "green"){
        flag = "";
        fill_solid(strip1, NUM_LEDS, CRGB::Green);
        fill_solid(strip2, NUM_LEDS, CRGB::Green);
        fill_solid(strip3, NUM_LEDS, CRGB::Green);
        fill_solid(strip4, NUM_LEDS, CRGB::Green);
        FastLED.show();
    }
    else if(color == "blue"){
        flag = "";
        fill_solid(strip1, NUM_LEDS, CRGB::Blue);
        fill_solid(strip2, NUM_LEDS, CRGB::Blue);
        fill_solid(strip3, NUM_LEDS, CRGB::Blue);
        fill_solid(strip4, NUM_LEDS, CRGB::Blue);
        FastLED.show();
    }
    else if(color == "white"){
        flag = "";
        fill_solid(strip1, NUM_LEDS, CRGB::White);
        fill_solid(strip2, NUM_LEDS, CRGB::White);
        fill_solid(strip3, NUM_LEDS, CRGB::White);
        fill_solid(strip4, NUM_LEDS, CRGB::White);
        FastLED.show();
    }
    else if(color == "yellow"){
        flag = "";
        fill_solid(strip1, NUM_LEDS, CRGB::Yellow);
        fill_solid(strip2, NUM_LEDS, CRGB::Yellow);
        fill_solid(strip3, NUM_LEDS, CRGB::Yellow);
        fill_solid(strip4, NUM_LEDS, CRGB::Yellow);
        FastLED.show();
    }
    else if(color == "purple"){
        flag = "";
        fill_solid(strip1, NUM_LEDS, CRGB::Purple);
        fill_solid(strip2, NUM_LEDS, CRGB::Purple);
        fill_solid(strip3, NUM_LEDS, CRGB::Purple);
        fill_solid(strip4, NUM_LEDS, CRGB::Purple);
        FastLED.show();
    }
    else if(color == "rainbow"){
        flag = "rainbow";
        fill_solid(strip1, NUM_LEDS, CRGB::Black);
        fill_solid(strip2, NUM_LEDS, CRGB::Black);
        fill_solid(strip3, NUM_LEDS, CRGB::Black);
        fill_solid(strip4, NUM_LEDS, CRGB::Black);
        FastLED.show();
    }
     else if(color == "lamp" || color == "on"){
        flag = "";
        fill_solid(strip1, NUM_LEDS, CRGB::Black);
        fill_solid(strip2, NUM_LEDS, CRGB::White);
        fill_solid(strip3, NUM_LEDS, CRGB::White);
        fill_solid(strip4, NUM_LEDS, CRGB::Black);
        FastLED.show();
    }
    else{
        flag = "";
        fill_solid(strip1, NUM_LEDS, CRGB::Black);
        fill_solid(strip2, NUM_LEDS, CRGB::Black);
        fill_solid(strip3, NUM_LEDS, CRGB::Black);
        fill_solid(strip4, NUM_LEDS, CRGB::Black);
        FastLED.show();
    }
    
}

void rainbow() {
    hue++;
    fill_rainbow(strip1, NUM_LEDS, hue, deltahue);
    fill_rainbow(strip2, NUM_LEDS, hue, deltahue);
    fill_rainbow(strip3, NUM_LEDS, hue, deltahue);
    fill_rainbow(strip4, NUM_LEDS, hue, deltahue);
}

void notify(String color){
    for(int j = 0; j < 3;j++){
        fill_solid(strip1, NUM_LEDS, CRGB::Black);
        fill_solid(strip2, NUM_LEDS, CRGB::Black);
        fill_solid(strip3, NUM_LEDS, CRGB::Black);
        fill_solid(strip4, NUM_LEDS, CRGB::Black);
        FastLED.show();
        for(int i = 0; i < NUM_LEDS; i++) {
            if(color == "purple"){
                strip1[i] = CRGB::Purple;
                strip2[i] = CRGB::Purple;
                strip3[i] = CRGB::Purple;
                strip4[i] = CRGB::Purple;
            }
            else if(color == "red"){
                strip1[i] = CRGB::Red;
                strip2[i] = CRGB::Red;
                strip3[i] = CRGB::Red;
                strip4[i] = CRGB::Red;
            }
            else if(color == "blue"){
                strip1[i] = CRGB::Blue;
                strip2[i] = CRGB::Blue;
                strip3[i] = CRGB::Blue;
                strip4[i] = CRGB::Blue;
            }
            FastLED.show();
            delay(5);
        }
    }
    setColor("off");
}

void bounce(){
    fill_solid(strip1, NUM_LEDS, CRGB::Black);
    fill_solid(strip2, NUM_LEDS, CRGB::Black);
    fill_solid(strip3, NUM_LEDS, CRGB::Black);
    fill_solid(strip4, NUM_LEDS, CRGB::Black);
    FastLED.show();
    flag = "bounce";
}
int setBright(String args){
    brightness = args.toInt();
    brightness = brightness * (255/10);
    
    FastLED.setBrightness(brightness);
    FastLED.show();
    return 1;
}
int notification(String args){
    if(args == "twitch"){
        notify("purple");
    }
    else if(args == "gmail"){
        notify("red");
    }
    else{
        for(int i = 0; i < 3; i++) {
            setColor("red");
            delay(50);
            setColor("off");
            return -1;
        }
    }
    return 1;
}
void setup() {
    Serial.begin(115200);


    // Particle Functions
    Spark.function("ctrlled", controlled);
    Spark.function("setBright", setBright);
    Particle.variable("color", color);
    Spark.function("Notification", notification);
    
    //LED's Setup
    FastLED.addLeds<WS2812B, STRIP1, GRB>(strip1, NUM_LEDS);
    FastLED.addLeds<WS2812B, STRIP2, GRB>(strip2, NUM_LEDS);
    FastLED.addLeds<WS2812B, STRIP3, GRB>(strip3, NUM_LEDS);
    FastLED.addLeds<WS2812B, STRIP4, GRB>(strip4, NUM_LEDS);
    
    FastLED.setBrightness(brightness);
    
    //Initaly set LEDs to off
    fill_solid(strip1, NUM_LEDS, CRGB::Black);
    fill_solid(strip2, NUM_LEDS, CRGB::Black);
    fill_solid(strip4, NUM_LEDS, CRGB::Black);
    fill_solid(strip4, NUM_LEDS, CRGB::Black);
    FastLED.show();
    
    // notify of start up
    notify("blue");
}

void loop() {

    //Particle.variable("random", counter);
    
    if(flag == "rainbow"){
        EVERY_N_MILLISECONDS(rainbowDelay) {
            rainbow();
        }
        FastLED.show();
    }
    else if(flag == "bounce"){
        for(int i = 0; i < NUM_LEDS; i++) {
            strip1[i] = CRGB::DeepPink;
            strip2[i] = CRGB::DeepPink;
            strip3[i] = CRGB::DeepPink;
            strip4[i] = CRGB::DeepPink;
            FastLED.show();
            delay(8);
            strip1[i] = CRGB::Black;
            strip2[i] = CRGB::Black;
            strip3[i] = CRGB::Black;
            strip4[i] = CRGB::Black;
            FastLED.show();
        }
        for(int i = NUM_LEDS; i > 0; i--) {
            strip1[i] = CRGB::DeepPink;
            strip2[i] = CRGB::DeepPink;
            strip3[i] = CRGB::DeepPink;
            strip4[i] = CRGB::DeepPink;
            FastLED.show();
            delay(8);
            strip1[i] = CRGB::Black;
            strip2[i] = CRGB::Black;
            strip3[i] = CRGB::Black;
            strip4[i] = CRGB::Black;
            FastLED.show();
        }

    }
    else if(flag == "spiral"){
        
        fill_solid(strip1, NUM_LEDS, CRGB::Black);
        fill_solid(strip2, NUM_LEDS, CRGB::Black);
        fill_solid(strip3, NUM_LEDS, CRGB::Black);
        fill_solid(strip4, NUM_LEDS, CRGB::Black);
        for(int i = 0; i < NUM_LEDS; i=i+2) {
            strip1[i] = CRGB::Green;
            FastLED.show();
            delay(20);
            strip2[i] = CRGB::Green;
            FastLED.show();
            delay(20);
            strip3[i+1] = CRGB::Green;
            FastLED.show();
            delay(20);
            strip4[i+1] = CRGB::Green;
            FastLED.show();
            delay(20);
            if(i>2){
                strip1[i-4] = CRGB::Black;
                strip2[i-4] = CRGB::Black;
            }
            strip3[i-3] = CRGB::Black;
            strip4[i-3] = CRGB::Black;
            
            
        }
        
    }
    else{
        
    }
    
    //delay(DELAY);
}