int buzzer = D5;             //Definisikan pin buzzerkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
int pir1 = D1;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(buzzer, OUTPUT); //Inisialisasi buzzer dengan tipe ouput
  pinMode(pir1, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(pir1);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    tone(buzzer, 100 ,500);  // menyalakan buzzer dengan frekuensi 6000 dan delay 500
    delay(200);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
