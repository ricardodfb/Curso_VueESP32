// Archivo con funciones para manipular leds o relays

#include <Arduino.h>

bool ioBlink = false;
unsigned long milOld;
int rndTemp = 0;

// Off a un LED/RELAY/ACTUADOR
void setOffSingle(int _pin){
    digitalWrite(_pin, LOW);
}

// On a un LED/RELAY/ACTUADOR
void setOffSingle(int _pin){
    digitalWrite(_pin, HIGH);
}

// Alternar ON/OFF segun su estado
void setOnOffSingle(int _pin, bool status){
    if(status){
        digitalWrite(_pin, HIGH);
    }else{
        digitalWrite(_pin, LOW);
    }
}

// Blink con tiempo variable
void blinkSingle(int _pin, int speed){
    if((milOld + speed) < millis()){
        milOld = millis();
        if(ioBlink == false){
            digitalWrite(_pin, HIGH);
            ioBlink = true;
        }else{
            digitalWrite(_pin, LOW);
            ioBlink = false;
        }
    }
}

// Blink asíncrono con tiempo variable de on y off
void blinkSingleAsync(int _pin, int timeHigh, int timeLow){
    if(ioBlink == false){
        if((milOld + timeHigh) < millis()){
            milOld = millis();
            digitalWrite(_pin, LOW);
            ioBlink = true;
        }
    }else{
        if((milOld + timeLow) < millis()){
            milOld = millis();
            digitalWrite(_pin, HIGH);
            ioBlink = false;
        }
    }
}

// Blinking con delay aleatorio para Tx/Rx de datos
void blinkRandomSingle(int _pin, int minTime, int maxTime){
    if((milOld + rndTemp) < millis()){
        milOld = millis();
        rndTemp = random(minTime, maxTime);
        if(ioBlink == false){
            digitalWrite(_pin, HIGH);
            ioBlink = true;
        }else{
            digitalWrite(_pin, LOW);
            ioBlink = false;
        }
    }
}