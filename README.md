![](circuit%20(1).png)
Controller for a Horizon PEMFC 100W

This project, while not strictly a part of my senior design project, came about when one of my classmates fried parts of the fuel cell. With a new controller being hundreds of dollars and the ultimate functionality of the controller limiting I decided to make my own which would give the controller full access to all the functions of the fuel cell. With the list including short circuit functionality, air bleeder timing, fan speed/control, temperature, data acquisition, and an ability to start up using less power. This combined with less than $50 and how terrible the Horizon customer service is this is a no brainer. 

Tools needed:
Computer w/ arduino IDE
Multimeter
Wire stripper 
(Optional) Soldering Iron

Material needed:
Arduino Uno
Horizon PEMFC 
AD8495 Breakout- (thermocouple breakout)
	K-type Thermocouple
	12V Battery (5Ah)
	Jumpers with alligator clips
	Jumper wire 
	Wire
	Breadboard
	3x Mosfets
	Electric fan (either PWM or Not)
Instructions-
The first thing you must do is wire up the arduino as I have shown in the figure attached. 
Attach the Arduino to the computer and boot up Arduino IDE
Grab my PEMFC code from GitHub and upload it to the arduino uno
 Then run the code and make sure you open the serial monitor to see the data coming in
Once you press run the program will upload and then run with the start up procedure 

Word of Warning: This was done in the span of 3 straight days by a college student totaling 4 hours of sleep over his spring break with resources paid for by the student (AKA cheap). Even so this was done by an individual with great knowledge in fuel cells. Fuel cells are extremely dangerous and if misused then can cause damage to yourself and others. So use this with caution! This code is not 100% done and polished so use it as a template. Hopefully the documentation I have provided in the code will help those needing to produce their own code.
