# Security-system-and-IOT


_____________________________________________________________________________________
That is a security system or access control system with a keypad and various sensors. Here are some observations based on the code:

•	The Project explanation 

Starting with Printing (“Welcome    ْ -  ْ  “ , then “How are you  Dr. Lila ”,then "Beni-Seuf University(BSU)" 
On LCD then asking you to Enter the Password which is (1258) is the correct one and you can change it to the password you want from the code by changing the values of a, b, c and D after Entering the correct Password you Click in (*) in Keypad to confirm the password and let the Program check if the password is correct or wrong 
If you click the Password correctly LCD will print "Correct" then	("Door is open Dr") then the Motor will
Turns which will be connected to the Door to open it and then the Motor will turns in the Other direction indicting that the Door has been closed again then asking to reconfirming the password if the password has entered right so everything is OK if you has entered it wrongly so the Message "SECURITY VIOLATION" and turns on the Animated LED(yellow and green) and asking you to Enter it again if it is right so "correct Password " and "ALARM DISABLED" and turns off the Animated LED(yellow and green)
If it was wrong so print "SECURITY VIOLATION" and 
that is a criminal 
if the User Entered, it Wrong for the first time so print "WRONG Password" and the LED 
there is a communication system (COMPIM) to connect the system with an application mobile 





•	The code explanation:

1.The code includes header files for the 8051 microcontroller and standard input/output operations.
2. It defines the connections of different components such as the LCD display, keypad, sensors, LEDs, and buzzer.
3. It declares and initializes variables for password checking and user input.
4. The `main` function contains the main logic of the project. It initializes the LCD, displays welcome messages, and prompts the user to enter a password.
5. It uses a function called “get_keypad_key” to read input from the keypad and determine which button was pressed.
6. The code implements password entry functionality where the user can enter a 4-digit password using the keypad.
7. If the entered password is correct, it opens the door (by controlling a connected device), activates LEDs, and triggers an alarm.
8. If an incorrect password is entered or a security violation occurs, appropriate messages are displayed, and the system reacts accordingly.

To fully understand the project's functionality and purpose, additional information or comments would be required. It would be helpful to have a description or requirements of the project and the specific features and behavior it is intended to exhibit.
