#include <WiFi.h>
#include <PubSubClient.h>

// ----------- WiFi Credentials -----------
const char* ssid = "__";
const char* password = "9___4";

// ----------- MQTT Broker -----------
const char* mqtt_server = "broker.emqx.io";

WiFiClient espClient;
PubSubClient client(espClient);

// Relay pins (Bulbs)
#define BULB1  5   // Relay 1
#define BULB2  18  // Relay 2

// MQTT callback
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);

  String msg = "";
  for (int i = 0; i < length; i++) {
    msg += (char)message[i];
  }

  Serial.print("Message: ");
  Serial.println(msg);

  // ----- Bulb 1 Control -----
  if (String(topic) == "home/bulb1") {
    if (msg == "ON") {
      digitalWrite(BULB1, LOW);   // Active LOW Relay
    } 
    else if (msg == "OFF") {
      digitalWrite(BULB1, HIGH);
    }
  }

  // ----- Bulb 2 Control -----
  if (String(topic) == "home/bulb2") {
    if (msg == "ON") {
      digitalWrite(BULB2, LOW);   // Active LOW Relay
    } 
    else if (msg == "OFF") {
      digitalWrite(BULB2, HIGH);
    }
  }
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    if (client.connect("ESP32_Client")) {
      Serial.println("connected");

      // Subscribe to both bulb topics
      client.subscribe("home/bulb1");
      client.subscribe("home/bulb2");

    } else {
      Serial.print("Failed. Error: ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(BULB1, OUTPUT);
  pinMode(BULB2, OUTPUT);

  // Set OFF initially (active LOW relay)
  digitalWrite(BULB1, HIGH);
  digitalWrite(BULB2, HIGH);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
