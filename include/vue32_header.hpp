// ARCHIVO DE CABECERA, AQUí SE DEFINEN PINES Y VARIABLES GLOBALES

//--------------------------------------------------------------------
// Se definen los puertos y leds
//--------------------------------------------------------------------
#define WIFILED 12                                  //GPIO 12 LED WIFI
#define MQTTLED 13                                  //GPIO 13 LED MQTT

//--------------------------------------------------------------------
// Calcular la capacidad del Json
// ArduinoJson v7
//--------------------------------------------------------------------
const size_t capacitySettings = 1536;

//--------------------------------------------------------------------
// Versión de firmware desde las variables de entorno plaformioio.ini
//--------------------------------------------------------------------
#define TEXTIFY(A) #A
#define ESCAPEQUOTE(A) TEXTIFY(A)
String device_fw_version = ESCAPEQUOTE(BUILD_TAG); // Se toma el build tag desde el archivo .ini

//--------------------------------------------------------------------
// Versión de hardware y de fabricante
//--------------------------------------------------------------------
#define device_hw_version "ADMINVUE32 v1 00000000"  // Version hardware
#define device_manufacturer "RicardoFerrel"         // Fabricante

//--------------------------------------------------------------------
// Zona configuración Dispositivo
//--------------------------------------------------------------------
boolean device_config_file;         // Identificador para archivo de configuración
char    device_config_serial[30];   // Número de serie de cada archivo de configuración único
char    device_id[30];              // ID del dispositivo
int     device_restart;             // Número de reinicios
char    device_old_user[15];        // Usuario de acceso al servidor Web
char    device_old_password[15];    // Contraseña de acceso al servidor Web
uint8_t ip[4];                      // Variable función convertir string a IP

//--------------------------------------------------------------------
// Zona configuración WIFI modo Cliente
//--------------------------------------------------------------------
boolean wifi_ip_static;             // Uso de IP estática DHCP
char    wifi_ssid[30];              // Nombre de la red WIFI
char    wifi_password[30];          // Contraseña de la red WIFI
char    wifi_ipv4[15];              // Dir IPv4 estático
char    wifi_gateway[15];           // Dir IPv4 Gateway
char    wifi_subnet[15];            // Dir IPv4 Subred
char    wifi_dns_primary[15];       // Dir IPv4 DNS primario
char    wifi_dns_secondary[15];     // Dir IPv4 DNS secundario

//--------------------------------------------------------------------
// Zona configuración WIFI modo AP
//--------------------------------------------------------------------
boolean ap_mode;            // Uso de Modo AP
char    ap_ssid[31];        // Nombre del SSID AP
char    ap_password[63];    // Contraseña del AP
int     ap_chanel;          // Canal AP
int     ap_visibility;      // Es visible o no el AP (0-Visible 1-Oculto)
int     ap_connect;         // Número de conexiones en el AP (máximo 8 en ESP32)

//--------------------------------------------------------------------
// Zona configuración MQTT
//--------------------------------------------------------------------
boolean mqtt_cloud_enable;          // Habilitar MQTT Broker
char    mqtt_cloud_id[30];          // Cliente ID MQTT Broker
char    mqtt_user[30];              // Usuario ID MQTT Broker
char    mqtt_password[39];          // Contraseña ID MQTT Broker
char    mqtt_server[39];            // Servidor ID MQTT Broker
int     mqtt_port;                  // Puerto servidor ID MQTT Broker
boolean mqtt_retain;                // Habilitar mensajes retenidos
int     mqtt_qos;                   // Calidad del servicio
boolean mqtt_time_send;             // Habilitar el envío de datos
int     mqtt_time_interval;         // Tiempo de envío por MQTT en segundos
boolean mqtt_status_send;           // Habilitar el envío de estados

//--------------------------------------------------------------------
// Zona Firmware Update TODO: Para la API REST
//--------------------------------------------------------------------
size_t  content_len;        // Determinar el tamaño del contenido del Firmware
#define U_PART U_SPIFFS     // Define para formatear el dispositivo en la parte de firmware y SPIFFS
//--------------------------------------------------------------------
// Zona EEPROM para contador de reinicios
//--------------------------------------------------------------------
#define Start_Address 0
#define Restart_Address Start_Address + sizeof(int)