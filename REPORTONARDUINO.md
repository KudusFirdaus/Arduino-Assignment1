REPORT ON ARDUINO
TASK 1:
1.	What is the difference between int and float? Give one example of when you would use each.
ANSWER: int is a data type used to store whole numbers e.g.: 4, 5, 234, 1000. Float is a data type that stores decimal numbers with low precision e.g.: 6.90, 3.14, 0.00012.

2.	 What happens if you forget to write Serial.begin(9600) in setup()? Try it and explain what you observe. 
ANSWER: I observed the serial monitor opens but was blank since it was not able receive valid data.

3.	Why does the output appear only once and not over and over.
ANSWER: Because the code was written in the void setup which is set to run once.

TASK 2:
1.	Why do we put pinMode(ledPin, OUTPUT); inside setup() and not inside loop()? 
ANSWER: pinMode is put inside setup( because it needs to be configured once when the Arduino starts.

2.	 What would happen if we removed both delay() calls? Predict first, then try it and describe what you actually see.
ANSWER: I observed that the light was on even thought the code was working. The Arduino executes the loop() extremely fast that the human eye cannot witness the on and off of the led.

3.	If you wanted the LED to be ON for 3 seconds and OFF for half a second, which values would you change and to what
ANSWER: You change the delay for the HIGH to 3000 and change the delay for the LOW to 500

TASK 3:
1.	In your own words, explain what a parameter is. (Hint: waitTime in our example)
ANSWER: A parameter is a variable listed in a function’s definition which acts as a placeholder for the value that will be passed into the function.

2.	Why is it useful to put repeating code into a function instead of writing it three times in loop()? 
ANSWER: It makes the program shorter, easier to read, and easier to reuse.

3.	 Could you write blinkOnce without taking any parameter at all? If yes, how would you make it blink at different speeds without parameters
ANSWER: Yes, you can. Global variable can be used to control the speed of blinking.

TASK 4:
1.	What is the role of the line counter = counter - 1; ? What would happen without it? 
ANSWER: The counter = counter – 1 is to decreased the counter by one each time the program runs. Without it the counter would never change and the condition while(counter > 0) would always remain true.
2.	Rewrite the countdown to start from 7 instead of 5. (Paste just the changed lines in your report.) 
  int counter = 7;

3.	In your own words, what is the difference between setup() and a while loop? They both run code — what makes them different?
ANSWER: setup() id a function that runs a program once when the board powers on or resets, while loop is a control structure that runs a block of code repeatedly as long as a condition is true.

TASK 5:
1.	Paste your final, working code.
   int ledPin = 13;
int startValue = 5;

void flashLED(int times){
  for(int i=0; i<times; i++){
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
  }
}
void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("===Smart Countdown Starting===");

  while(startValue>0){
    Serial.print("Count: ");
    Serial.println(startValue);
    flashLED(3);
    delay(1000);
    startValue = startValue - 1;
  }
  Serial.println("===Countdown Complete===");
  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);

}

void loop(){

}

3.	Describe one bug or mistake you ran into while writing this program and how you fixed it. (Be honest. Everyone runs into bugs.) 
ANSWER: The LED continues to run in the next count. It was fixed by adding thedelay(1000) after calling the function  flashLED();

4.	If you wanted the program to count DOWN by 2 each step (5, 3, 1) instead of by 1, what would you change? 
ANSWER:  I would change the startValue = startValue – 1; to startValue = startValue – 2;

5.	If you wanted the LED to also stay ON for a final 5 seconds after the countdown completes, where in the code would you add this and what would the code look like
ANSWER:  I would add it after the Serial.println(“===Countdown Complete===”);
And the code will look like:
Serial.println("===Countdown Complete===");
digitalWrite(ledPin, HIGH);
delay(5000);
digitalWrite(ledPin, LOW);
