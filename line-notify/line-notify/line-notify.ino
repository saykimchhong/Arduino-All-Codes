#include <TridentTD_LineNotify.h>

#define SSID        "xxxx"
#define PASSWORD    "xxxx"
#define LINE_TOKEN  "xxxx"

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  

  // config Line Token
  LINE.setToken(LINE_TOKEN);

  // Example of sending text message
  LINE.notify("Temperature Overheat");

  // Example of sending message as number
  LINE.notify(2342);          // integer number
  LINE.notify(212.43434,5);   // flaot number with 5 digits behind 

  // Choose line sticker from this url: https://devdocs.line.me/files/sticker_list.pdf
  LINE.notifySticker(3,240);        // ส่ง Line Sticker ด้วย PackageID 3 , StickerID 240
  LINE.notifySticker("Hello",1,2);  // ส่ง Line Sticker ด้วย PackageID 1 , StickerID 2  พร้อมข้อความ

  // Send image by url
  LINE.notifyPicture("https://preview.ibb.co/j6G51n/capture25610417181915334.png");
  LINE.notifyPicture("จตุธาตุ","https://www.fotoaparat.cz/storage/pm/09/10/23/670915_a5351.jpg");
}

void loop() {
  delay(1);
}
