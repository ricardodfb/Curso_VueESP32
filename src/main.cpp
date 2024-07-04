// Librerías
#include <Arduino.h>
#include <ArduinoJson.h> // libreria ArduinoJson declarada en platformio.ini
#include <SPIFFS.h> // libreria necesaria para trabajar con SPIFFS
#include <EEPROM.h> // librería para trabajar con la memoria EEPROM

// Archivos .hpp para fragmentar el código
#include "vue32_header.hpp" // se incluye el archivo que se creó en la carpeta include (aquí se definen variables)
#include "vue32_functions.hpp" // se incluye el archivo que se creó en la carpeta include (aquí se declaran funciones)
#include "vue32_settings.hpp" // se incluye el archivo que se creó en la carpeta include (aquí se tienen configuraciones)

// Funciones
void setup() {
  Serial.begin(115200);
  setCpuFrequencyMhz(240);

  // Inicializar memoria EEPROM para contar los reinicios
  EEPROM.begin(256);
  // Obtener el conteo de reinicios y aumentarlo en 1
  EEPROM.get(Restart_Address, device_restart);
  device_restart++;
  // Guardar nuevo conteo de reinicios en memoria EEPROM
  EEPROM.put(Restart_Address, device_restart);\
  EEPROM.commit();
  EEPROM.end();

  log("\n[ INFO ] Iniciando Setup");
  log("[ INFO ] Reinicios: " + String(device_restart));
  log("[ INFO ] Setup corriendo en el core " + String(xPortGetCoreID()));
  // Incializar el SPIFFS
  if(!SPIFFS.begin(true)){
    log("\n[ ERROR ] Falló la inicialización del SPIFFS");
    //while(true);
  }
  // Leer el archivo settings.json
  if(!settingRead()){
    settingSave();
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

//cambio realizado