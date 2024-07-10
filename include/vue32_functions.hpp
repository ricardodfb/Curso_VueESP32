// ARCHIVO DE FUNCIONES, AQUí SE DECLARAN FUNCIONES

#include "vue32_LedBlink.hpp"

// Imprimir en consola de manera mas sencilla
void log(String s){
    Serial.println(s);
}

// Leer número de serie del dispositivo
String deviceID(){
    return String(platform()) + hexStr(ESP.getEfuseMac()) + String(idUnique());
}

// Definir la plataforma
String platform(){
    // Se obtiene la plataforma del hardware
    #ifdef ARDUINO_ESP32_DEV
        return "ESP32";
    #endif
}

// Convertir de Hexadecimal a String
String hexStr(const unsigned long &h, const byte &l = 8){
    String s;
    s = String(h,HEX);
    s.toUpperCase();
    s = ("00000000" + s).substring(s.length() + 8 - l);
    return s;
}

// Crear ID unico con la direccion MAC
String idUnique(){
    // Retorna los ultimos 4 bytes del MAC rotados
    char idunique[15];
    uint64_t chipid = ESP.getEfuseMac();
    uint16_t chip = (uint16_t)(chipid >> 32);
    snprintf(idunique, 15, "%04X", chip);
    return idunique;
}

// Configurar los pines de los LEDs
void settingPines(){
    pinMode(WIFILED, OUTPUT);
    pinMode(MQTTLED, OUTPUT);
    setOffSingle(WIFILED);
    setOffSingle(MQTTLED);
}

