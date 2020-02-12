# LPC2148-38-based-Elevator-system
LPC2148/38 microcontroller to control a 10 floor elevator system using P controller.
ADDIS ABABA UNIVERSITY
ADDIS ABABA INSTITUTE OF TECHNOLOGY
SCHOOL OF ELECTRICAL AND COMPUTER ENGINEERING

CONTROL STREAM
INTRODUCTION TO EMBEDDED SYSTEMS

Documentation of Automated Passenger Vehicle System for G+9 Buildings (10 floors). 
 
 
Team members:
•	Kidst Gobezay  - =  
•	Mohammed Abdulkadir  -= 		
DEC-2019
Introduction:
  Automated Passenger Vehicle System for Buildings system installed on buildings that serves for vertical transport of persons or goods.
  It consists of mechanical components like motors, pulleys and mechanical framework to support the vehicle.
  It also consists of electrical components. The electrical components are as essential as mechanical components because they are
  basically the main part behind the proper functioning of an elevator system. Microprocessors or other embedded electrical 
  components is usually the controlling engine behind this systems automation, and by being automated  it reduces the waiting time
  and increases traffic management efficiency in residential, commercial and other buildings. These embedded systems also increase
  the systems safety in many ways.  

Project abstract:
This project is the designing and implementation of an Automated Passenger Vehicle System for Buildings.
A safe, reliable and user friendly system is a one of the essence of our project and efficiency in every aspect of its working is 
tried to be implemented.

Features of our Automated Passenger Vehicle System:
	10 floors support with interactive seven segment display.
	Proportional based motor controller.
	Safety system enabled for various scenarios such as overweight, door jam, motor overheating…
	Smart queue management system for passenger pickup and drop off.


Components used:
I.	Outer cabin interface
	8 Bi directional buttons (up & down).
	2 unidirectional buttons (one Up and one down). A total of 18 button is used in the outer cabin interface.
	7 segment display.
	Speakers.

II.	Inner cabin interface
	10 buttons representing each floor
	Alarm button (x1)
	Door close/Door open buttons (x1 for each)
	7 segment display (x1).
	Speakers

III.	System interfaces and components:
	Motor:
o	 DC motor.
o	Shaft encoded Dc motor.
	LPC2148 processor.
	Display drives (BCD decoder).
	Multiplexer/Data selectors (74HC257).
	And/ Or gates. 
	Custom built H bridge motor drive.

IV.	Limitations

	Needs manual configuration of the motors(door and main) after an alarm interrupt occurs and during the start operation of the system. By default it is set to start at ground floor.

V.	Methodology:
---
 

Test done on Simulation
	We tried simulating most of real world scenarios. But in general we classified as follows:
o	Design Phase:
	Does the keypad work properly?
	Does the multiplexer/ data selector successfully connect the keypad to the LPC2148?
	Does the external interrupts of different sources work correctly?
	Can we drive the motor using PWM using our custom built H Bridge?
	Can we read the values of the keypad pressed during pressing?
o	After integration phase:
	Are the orders queues arranged in an expected way?
	Does the system drop off/ pick up the queue in arranged manner?
	Do the alarm cases for different scenarios work properly?  
	Does the system work in an expected way?(such as displaying current floor level and such)
 

Tools Used for Building this project
	Keil micro vision with C programming language.
	Proteus 8.0
	Debug tools in Proteus
	draw.io
References
	Lecture slides
	www.bsbasansor.com.tr
	https://www.schindler.com/nz/internet/en/schindler-new-zealand/safety-principles/new-elevator-norm.html
Project Page
	https://github.com/mamilaaw/LPC2149-38-based-Elevator-system
