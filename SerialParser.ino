
int incomingByte;
int byte_count;
char incoming[64];

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);

}

void loop() {

  // send data only when you receive data:
  bool data_incoming = false;
  
  if (Serial.available() > 0) {
    delay(100); //Serial needs a little time to update.
    int byte_count = Serial.available();
    for(int i=0;i<byte_count;i++){
      incoming[i] = Serial.read();
      Serial.println("At position: " + String(i) + " we have: " + incoming[i]);
    }
    data_incoming = true;
  }
  
  if (data_incoming) {
    const char *result = incoming;
    delay(10);
    Serial.println(result);
    String val1;
    int val2, val3;
    int scan = sscanf(result, "%s :%d", &val1, &val2);
    Serial.println(scan);
    if (scan==2) {
      Serial.println("Suddenly this is cool: " + val1+" , " + String(val2)+" , " + String(val3));
    }
    data_incoming=false;
    memset(&incoming[0], 0, sizeof(incoming));
  }
}
