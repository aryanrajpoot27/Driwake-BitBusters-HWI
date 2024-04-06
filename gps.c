#include <SoftwareSerial.h>
#include <TinyGPS.h>

float lati, longi;

TinyGPS gps;
SoftwareSerial sgps(4, 5);
SoftwareSerial sgsm(2, 3);

void setup() {
  sgsm.begin(9600);
  sgps.begin(9600);
}
void loop() {
  sgps.listen();
  while (sgps.available()) {
    int c = sgps.read();
    if (gps.encode(c)) {
      gps.f_get_position(&lati, &longi);
    }
  }
  sgsm.listen();
  if (sgsm.available() > 0) {
    String c = sgsm.readString();
    c.trim();
    if (c.indexOf("GET-GPS") >= 0) {
      sgsm.print("\r");
      delay(1000);
      sgsm.print("AT+CMGF=1\r");
      delay(1000);
      sgsm.print("AT+CMGS=\"+919555963690\"\r"); /*Add your country code instead of ZZ and Add the phone number on which you want to send the SMS by removing XXXXXXXXXX */
      delay(1000);
      sgsm.print("Latitude :");
      sgsm.println(lati, 6);
      sgsm.print("Longitude:");
      sgsm.println(longi, 6);
      delay(1000);
      sgsm.write(0x1A);
      delay(1000);
    }
  }
}