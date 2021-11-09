#include <SoftwareSerial.h>
#if defined(__AVR_ATmega2560__) 
  SoftwareSerial mySerial(10, 16); // RX, TX
#else
  SoftwareSerial mySerial(4, 2); // RX, TX
#endif

String command = ""; // Stores response of the HC-06 Bluetooth device


void setup() {
  // Open serial communications:
  Serial.begin(9600);
  Serial.println("Type AT commands!");
  
  // The HC-06 defaults to 9600 according to the datasheet.
  mySerial.begin(9600);
}

void loop() {
  // Read device output if available.
  if (mySerial.available()) {
    while(mySerial.available()) { // While there is more to be read, keep reading.
      command += (char)mySerial.read();

    }
    
    Serial.print(command);
    //Serial.write(command);
    command = ""; // No repeats
  }
  
  // Read user input if available.
  if (Serial.available()){
    delay(10); // The delay is necessary to get this working!
    mySerial.write(Serial.read());
  }
}
