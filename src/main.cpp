#include <Arduino.h>

// Definisikan variabel
int button1Pin = 2; // Pin digital tempat tombol 1 terhubung.
int ledRedPin = 8;  // Pin digital tempat LED merah terhubung.

int button2Pin = 4; // Pin digital tempat tombol 2 terhubung.
int ledGreenPin = 10; // Pin digital tempat LED hijau terhubung.

// Variabel untuk menyimpan status tombol
bool buttonState1 = false;
bool buttonState2 = false;

void setup() {

  pinMode(ledRedPin, OUTPUT);    // Atur pin LED merah sebagai output.
  pinMode(button1Pin, INPUT);    // Atur pin tombol 1 sebagai input.

  pinMode(ledGreenPin, OUTPUT);  // Atur pin LED hijau sebagai output.
  pinMode(button2Pin, INPUT);    // Atur pin tombol 2 sebagai input.

  // Mulai komunikasi serial pada baud rate 9600
  Serial.begin(9600);
  Serial.println("Program push button dimulai.");

}

void loop() {

  // Baca status tombol
  buttonState1 = digitalRead(button1Pin);
  buttonState2 = digitalRead(button2Pin);

  // Periksa apakah tombol 1 ditekan
  if (buttonState1 == HIGH){

    Serial.println("LED Merah Menyala");

    // Nyalakan LED Merah.
    digitalWrite(ledRedPin, HIGH);

    // Tunda sebentar untuk menghindari pembacaan ganda
    delay(1000);

  } else {

    Serial.println("LED Merah Mati");

    // Matikan LED Merah.
    digitalWrite(ledRedPin, LOW);

    // Tunda sebentar untuk menghindari pembacaan ganda
    delay(200);
  }

  // Periksa apakah tombol 2 ditekan
  if (buttonState2 == HIGH){

    Serial.println("LED Hijau Menyala");

    // Nyalakan LED Hijau.
    digitalWrite(ledGreenPin, HIGH);

    // Tunda sebentar untuk menghindari pembacaan ganda
    delay(1000);

  } else {

    Serial.println("LED Hijau Mati");

    // Matikan LED Hijau.
    digitalWrite(ledGreenPin, LOW);

    // Tunda sebentar untuk menghindari pembacaan ganda
    delay(200);
  }
}
