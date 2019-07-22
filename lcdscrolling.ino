/ Display your name and your favorite quote appear on the 16x2 display, 
// name on first line and quote on the second line. 
// The quote should not all fit on the screen and so should scroll across the screen. 
// Your name should not scroll across the screen, only the quote should scroll. 
// include the library
#include <LiquidCrystal.h>

// use the LiquidCrystal and initialize all the pins according to your circuit
// pin 12: RS
// pin 11: Enable
// pin 5: D4
// pin 4: D5
// pin 3: D6
// pin 2: D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Initializing the two lines to display on screen
// 1st line should be the name and should not scroll
String line1 = "Harsh Gupta";
// 2nd line should be the quote and should scroll
String line2 = "I want to put a ding in the universe. - Steve Jobs";

// initialize the LCD size (16x2)
int screenWidth = 16;
int screenHeight = 2;


// initializing integers to stop string and scrolling
int stringStart = 0;
int stringStop = 0;
int scrollCursor = screenWidth;

void setup() {
  // initialize the LCD in the Setup
  lcd.begin(screenWidth,screenHeight);
  
}

void loop() {
  lcd.print(line1);               // print line 1
  lcd.setCursor(scrollCursor, 0); // Scroll the cursor to 0
  //lcd.print(line1);               // print line 1
  lcd.setCursor(0, 1);            // Set it to be constant
  lcd.print(line2.substring(stringStart,stringStop)); // start scrolling
  delay(500);                     // Delay it for 500 seconds
  lcd.clear();                    // Clear the output
  
  if(stringStart == 0 && scrollCursor > 0){ // Compare where is the cursor and the string
    
    scrollCursor--;
    stringStop++;
    
  }
  else if (stringStart == stringStop){ // if the start of the string is at the end then change the cursor
    
    stringStart = stringStop = 0;
    scrollCursor = screenWidth;
    
  }
  else if (stringStop == line2.length() && scrollCursor == 0) { // if the length is equal to end of the string change the cursor
    
    stringStart++;
    
  }
  else { // if none is compared then just increment it
    
    stringStart++;
    stringStop++;
  }
  
}//end loop
