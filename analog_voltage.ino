int redLED=9; // Declaring redLED as an int and setting it to 9
int yellowLED=10; // Declaring yellowLED as an int and setting it to 10

int redON=250; // This is the LED on time
int redOFF=250; // LED off time
int yellowON=250; // yellow on time
int yellowOFF=250; // yellow off time
int REDrepeat=3;
int YELLOWrepeat=3;
String redMessage="The red LED is blinking"; //Declaring a string variable
String yellowMessage="The yellow LED is blinking"; //Declaring a string variable
int writeValueRed; //declare variable for writeValue
int writeValueYellow;

void setup() {
  Serial.begin(115200);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  Serial.println("What voltage would you like to apply to the RED LED? (0-255) "); //prompt user for input
  while (Serial.available()==0){ } // Do not continue code until user has provided input I.E WAIT, == is asking
  writeValueRed=Serial.parseInt(); //read user input. If the type of global variable was float then type parseFloat, if was reading string then type Serial.readString
  
  Serial.println("What voltage would you like to apply to the YELLOW LED? (0-255)  "); //prompt user for input
  while (Serial.available()==0){ } // Do not continue code until user has provided input I.E WAIT, == is asking
  writeValueYellow=Serial.parseInt(); //if the type of global variable was float then type parseFloat, if was reading string then type Serial.readString
  Serial.println(yellowMessage);
  Serial.println(redMessage);
}

void loop() {
  Serial.println(redMessage);
  int i=1;
  while ( i<=REDrepeat ) {
 
    Serial.print("   You are on blink number ");
    Serial.println(i); // shows the number within the loop in the serial monitor
    analogWrite(redLED, writeValueRed); // apply analogue voltage to red LED
    delay(redON);               // Wait
    analogWrite(redLED, 0);  // Turn LED off
    delay(redOFF);
    i=i+1;
  }

  Serial.println(" ");
  Serial.println(yellowMessage);

for (int i=1; i<=YELLOWrepeat; i=i+1 ) {
  Serial.print("  You are on blink number ");
  Serial.println(i);
  analogWrite(yellowLED, writeValueYellow);
  delay(yellowON);
  analogWrite(yellowLED, 0);
  delay(yellowOFF);
  
}
  Serial.println(" ");

}

