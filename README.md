# ESP32 WiFi Access Point & Station Mode with OTA

Dit is een voorbeeldproject dat laat zien hoe je een ESP32 kunt configureren in zowel Access Point (AP) als Station (STA) WiFi-modi, met ondersteuning voor Over-The-Air (OTA) updates. Dit project is gebaseerd op ESP-IDF versie 4.4.5.

## Inleiding

Dit project demonstreert hoe je de ESP32 kunt instellen als WiFi Access Point (AP) en tegelijkertijd verbinding kunt maken met een bestaand WiFi-netwerk als Station (STA). Het biedt ook de mogelijkheid om firmware-updates uit te voeren via OTA, wat het gemakkelijker maakt om nieuwe code naar de ESP32 te distribueren zonder fysiek verbonden te zijn via een seriële kabel.

## Vereisten

- ESP-IDF versie 4.4.5 (of compatibel)
- ESP32 development board
- USB naar seriële adapter voor programmeren (alleen voor de eerste keer)
- Toegang tot een WiFi-netwerk voor OTA-updates

## Installatie

1. Installeer ESP-IDF versie 4.4.5 volgens de officiële documentatie: [ESP-IDF Installatiehandleiding](https://docs.espressif.com/projects/esp-idf/en/v4.4.5/get-started/index.html)

2. Clone dit repository naar je lokale machine:

   ```sh
   git clone https://github.com/De-Backer/ESP_ota_Acces_Point_and_STAtion_mode.git
   
3. Configureer WiFi SSID en wachtwoord via idf.py menuconfig. Navigeer naar Component config > App Configuration en stel de SSID en wachtwoord in.
4. Pas andere instellingen aan in main/main.cpp volgens je projectbehoeften.

## Gebruik

1. Compileer en flash de firmware naar de ESP32
2. Zodra de ESP32 is geflashed, zal deze starten in AP-modus met de geconfigureerde SSID. Je kunt verbinding maken met dit netwerk met het geconfigureerde wachtwoord.
3. De ESP32 zou ook automatisch verbinding moeten maken met het geconfigureerde WiFi-netwerk als STA zodra dit beschikbaar is.
4. Voor OTA-updates, zorg ervoor dat je verbonden bent met het WiFi-netwerk van de ESP32. [ip-adres]/update
