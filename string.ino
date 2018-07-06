void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

    String stringname = "";
    char charactername;

  while(Serial.available()) {
      charactername = Serial.read();
      stringname.concat(charactername);
  }
delay (10); 
  if (stringname != "") {
    Serial.println(stringname);
  }

}
