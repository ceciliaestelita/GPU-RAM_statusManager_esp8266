# 📊 GPU & RAM Status Manager (ESP8266)

![Status](https://img.shields.io/badge/Status-In_Development-yellow)
![Platform](https://img.shields.io/badge/Platform-ESP8266-blue)
![Framework](https://img.shields.io/badge/Framework-PlatformIO-orange)
![Interface](https://img.shields.io/badge/Display-LCD%2016x2%20I2C-red)

Um gerenciador de status de hardware utilizando o ESP8266 para monitorar em tempo real o uso de CPU, GPU e memória RAM do computador. Os dados são enviados via comunicação serial (ou Wi-Fi) e exibidos diretamente em um display LCD 16x2 com módulo I2C, permitindo um monitoramento externo e limpo do sistema.

## ✨ Funcionalidades

* **Monitoramento em Tempo Real:** Exibição das métricas de uso de hardware do PC (CPU, GPU, RAM) diretamente na bancada.
* **Comunicação Otimizada:** Integração serial estável entre o script de monitoramento no computador e o microcontrolador.
* **Conexão Simplificada:** Uso do barramento I2C para controlar o display LCD utilizando apenas 2 pinos de dados.
* **Interface Scannable:** Organização das informações divididas entre as linhas do display para leitura rápida.
* **Ecossistema PlatformIO:** Código estruturado profissionalmente usando o gerenciamento de dependências do PlatformIO.

## 🛠️ Lista de Materiais (Hardware)

| Componente | Detalhes |
| :--- | :--- |
| **Microcontrolador** | NodeMCU ESP8266 (ou similar) |
| **Display** | LCD 16x2 (Fundo azul ou verde) |
| **Módulo de Dados** | Adaptador I2C para LCD (PCF8574) |
| **Comunicação** | Cabo Micro-USB de boa qualidade (para dados e alimentação) |
| **Conexões** | Jumpers fêmea-fêmea |

## 🔌 Esquema de Ligação (I2C)

### Pinagem no ESP8266 (NodeMCU)

| Pino ESP8266 | Pino LCD I2C | Descrição |
| :--- | :--- | :--- |
| **D2 (GPIO4)** | **SDA** | Linha de Dados do Barramento I2C |
| **D1 (GPIO5)** | **SCL** | Linha de Clock do Barramento I2C |
| **VIN (ou 5V)** | **VCC** | Alimentação do Display (5V recomendado para melhor contraste) |
| **GND** | **GND** | Terra comum do circuito |

> **⚠️ Atenção:** Se o seu LCD apresentar apenas quadrados pretos acesos na primeira linha, ajuste cuidadosamente o pequeno potenciômetro azul localizado na parte traseira do módulo I2C para calibrar o contraste.

## 💻 Configuração do Ambiente (Software)

O projeto foi desenvolvido utilizando o **PlatformIO** dentro do VS Code. Certifique-se de configurar a velocidade de comunicação (`monitor_speed`) corretamente para evitar caracteres corrompidos.

### Configuração do `platformio.ini`

```ini
[env:nodemcuv2]
platform = espressif8266
board = nodemcuv2
framework = arduino

; Velocidade do Monitor Serial (Deve ser a mesma do Serial.begin no seu código)
monitor_speed = 115200

lib_deps =
    marcoschwartz/LiquidCrystal_I2C @ ^1.1.4
