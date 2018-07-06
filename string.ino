void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

String stringname = "";

void loop() {
  
  // put your main code here, to run repeatedly:    
  char charactername = '\0';

  while(Serial.available()) {
      charactername = Serial.read();
      stringname.concat(charactername);
  }
  
  delay (10); 
  if (charactername!='\0') {
    Serial.println(stringname);
  }

}
