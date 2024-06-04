#include <WiFi.h>

// Ganti dengan SSID dan password WiFi Anda
const char* ssid = "METINDO-DOJO";
const char* password = "Metindo@Dojo";

// Definisikan pin LED dan buzzer
const int greenLedPin = 4;
const int yellowLedPin = 2;
const int redLedPin = 5;
const int buzzerPin = 18;

void setup() {
  // Memulai komunikasi serial untuk debug
  Serial.begin(115200);

  // Mengatur pin LED dan buzzer sebagai output
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Memulai koneksi ke WiFi
  Serial.println("Menghubungkan ke WiFi...");
  WiFi.begin(ssid, password);

  // Tunggu hingga terhubung
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Menghubungkan...");
  }

  // Jika terhubung, tampilkan alamat IP dan nyalakan LED hijau
  Serial.println("Terhubung ke WiFi!");
  Serial.print("Alamat IP: ");
  Serial.println(WiFi.localIP());
  
  digitalWrite(greenLedPin, HIGH); // Menyalakan LED hijau sebagai indikasi koneksi WiFi
}

void loop() {
  // Contoh logika untuk menyalakan LED dan buzzer
  digitalWrite(yellowLedPin, HIGH); // Menyalakan LED kuning
  delay(1000);                      // Tunggu 1 detik
  digitalWrite(yellowLedPin, LOW);  // Mematikan LED kuning

  digitalWrite(redLedPin, HIGH);    // Menyalakan LED merah
  digitalWrite(buzzerPin, HIGH);    // Menyalakan buzzer
  delay(2000);                      // Tunggu 2 detik
  digitalWrite(buzzerPin, LOW);     // Mematikan buzzer
  digitalWrite(redLedPin, LOW);     // Mematikan LED merah

  delay(1000); // Tunggu 1 detik sebelum mengulang siklus
}
