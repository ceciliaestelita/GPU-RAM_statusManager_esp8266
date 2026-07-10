#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <LiquidCrystal.h>

// --- CONFIGURAÇÕES DO WI-FI (MUDE AQUI) ---
const char* ssid     = "REDE_WIFI";
const char* password = "SENHA_WIFI";

const unsigned int localUdpPort = 4210; 
char incomingPacket[255];  

// Configura os pinos do seu LCD: LiquidCrystal(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(D2, D3, D5, D6, D7, D8);
WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  
  // Inicializa o LCD clássico de 16 colunas e 2 linhas
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Conectando...");

  /*WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }*/

  // Mostra o IP gerado na tela do LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("IP do ESP8266:");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());

  udp.begin(localUdpPort);
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    int len = udp.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = 0;
    }
    
    String dados = String(incomingPacket);
    int espaco = dados.indexOf(' ');
    
    if (espaco != -1) {
      String cpuStr = dados.substring(0, espaco);
      String ramStr = dados.substring(espaco + 1);
      
      lcd.setCursor(0, 0);
      lcd.print("                "); // Limpa a linha 1
      lcd.setCursor(0, 0);
      lcd.print(cpuStr);
      
      lcd.setCursor(0, 1);
      lcd.print("                "); // Limpa a linha 2
      lcd.setCursor(0, 1);
      lcd.print(ramStr);
    }
  }
}
