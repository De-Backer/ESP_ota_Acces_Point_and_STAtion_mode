#include "WiFi.h"
#include "Arduino.h"
#include <esp_log.h>

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "AsyncElegantOTA.h"

static const char *TAG = "MAIN";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

extern "C" void app_main(void)
{
    initArduino();
    Serial.begin(115200);
    // set WiFi station + soft-AP mode
    WiFi.mode(WIFI_AP_STA);
    // Begin Access Point
    // Set IP addresses
    const IPAddress local_IP(192, 168, 4, 50);
    const IPAddress gateway(192, 168, 4, 1);
    const IPAddress subnet(255, 255, 255, 0);
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(CONFIG_AP_SSID, CONFIG_AP_PASS);
    // Connect to Wi-Fi
    WiFi.begin(CONFIG_STA_SSID, CONFIG_STA_PASS);
    // Connecting to WiFi...
    Serial.print("Connecting to ");
    Serial.print(CONFIG_STA_SSID);
    while (WiFi.status() != WL_CONNECTED)
    {
        vTaskDelay(1000);
        Serial.print(".");
    }

    // Connected to WiFi
    Serial.println();
    Serial.println("Connected!");
    Serial.print("IP address for network ");
    Serial.print(CONFIG_STA_SSID);
    Serial.print(" : ");
    Serial.println(WiFi.localIP());
    Serial.print("IP address for network ");
    Serial.print(CONFIG_AP_SSID);
    Serial.print(" : ");
    Serial.print(WiFi.softAPIP());

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(200, "text/plain", "Hi! This is a sample response."); });
    AsyncElegantOTA.begin(&server); // Start AsyncElegantOTA
    server.begin();
    Serial.println("HTTP server started");

    for (;;)
    {
        Serial.println(WiFi.softAPgetStationNum());
        vTaskDelay(1000); // delay x RTOS tick
    }
}