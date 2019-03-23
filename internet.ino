#include <ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>

const char* ssid     = "INTERNET";
const char* password = "passcode";


String data = "", lastdata = "";
int set = 0, lastset = 0;

//1=forward
//2=backward
//3=right
//4=left
//5=stop
//6=1on
//7=1off
//8=2on
//9=2off
//10=3on
//11=3off

#define m11 12
#define m12 13
#define m21 4
#define m22 14



void setup()
{
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);

  pinMode(16, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(5, OUTPUT);

  stop1();
  Serial.begin(115200);
  WiFi.begin(ssid, password); // add ssid and password here
  Serial.println("Waiting for connection");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  delay(1000);
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Wi-Fi Connected!");
  }

}

void loop()
{
  data = receivelastmessage();
  if (data != lastdata && lastdata != "") {
    if (data == "forward")
      set = 1;
    else if (data == "backward")
      set = 2;
    else if (data == "right")
      set = 3;
    else if (data == "left")
      set = 4;
    else if (data == "stop")
      set = 5;
    else if (data == "switch1on")
      set = 6;
    else if (data == "switch1off")
      set = 7;
    else if (data == "switch2on")
      set = 8;
    else if (data == "switch2off")
      set = 9;
    else if (data == "switch3on")
      set = 10;
    else if (data == "switch3off")
      set = 11;
  }

  if (set != lastset) {
    switch (set) {
      case 1: forward(); break;
      case 2: backward(); break;
      case 3: right(); break;
      case 4: left(); break;
      case 5: stop1(); break;
      case 6: switch1on(); break;
      case 7: switch1off(); break;
      case 8: switch2on(); break;
      case 9: switch2off(); break;
      case 10: switch3on(); break;
      case 11: switch3off(); break;
    }
  }

  lastdata = data;
  lastset = set;

}

String receivelastmessage()
{
  String lastmessage = "";
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    String url = "http://trskncoe.000webhostapp.com/datastorage.txt";
    http.begin(url);
    http.addHeader("Content-Type", "text/plain");
    int httpCode = http.GET();
    String data = http.getString();
    lastmessage = getlastline(data);
    http.end();
  }
  else
  {
    lastmessage = "";
  }
  return lastmessage;
}

String getlastline(String str)
{
  String s = "";
  int len = str.length();
  for (int i = len - 1; i >= 0; i--)
  {
    if (str[i] == '\n')
    {
      break;
    }
    else
    {
      s = s + str[i];
    }
  }
  String rs = "";
  for (int i = s.length() - 1; i >= 0; i--)
  {
    rs = rs + s[i];
  }
  return rs;
}



