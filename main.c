//mdoify the oq for the external input int irq
//bugg on 2 to 1 mnamen

#include<LPC214x.h>

#define OC1 (1<<16)
#define OC2 (1<<17)
#define OC3 (1<<18)

#define IC1 (1<<27)
#define IC2 (1<<28)

#define OR1 (1<<19)
#define OR2 (1<<20)
#define OR3 (1<<21)
#define OR4 (1<<22)
#define OR5 (1<<23)
#define OR6 (1<<24)
 
#define OSEL (1<<25)
#define ISEL (1<<26)


unsigned short currentFloor=0;// we assume the elevator starting position to be ground floor
char tripDxn='N';
unsigned short OQ[10]={0};//order que containg both the pick up and drop off que
unsigned short NOQ[10]={0};//next order que containing both the pick up and drop off que for the next round of trip



void keypad_delay(void)
   {
        unsigned int t1,t2;
        for(t1=0;t1<300;t1++)                 
                for(t2=0;t2<1275;t2++);
   }
 
 
 
unsigned int  outerInput(void){
				
				IOSET1|= OSEL;///after int happend set this to high so the UP could connect to the switch array...set to 1 to deselect after finishing int 
				
				short cmd;//to hold the place of floor called and  dxt of intendded travel
        
				IOCLR1|=(OR1|OR2|OR3|OR4|OR5|OR6|OC1|OC2|OC3);
				
       
		// while(1) {
          
                IOCLR1|=OR1;
                IOSET1|=(OR2|OR3|OR3|OR4|OR5|OR6);                     // first ROW = 0
                
                if((IOPIN1&OC1)==0)
                   {
                        cmd=90; //9th floor down button
                        keypad_delay();
												IOCLR1 |= OSEL;	
                        return cmd;
                   }
                else if((IOPIN1&OC2)==0)
                  {
                        cmd=80;//8th floor down button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
                else if((IOPIN1&OC3)==0)
                  {
                        cmd=81;//8th floor up button
                        keypad_delay();
                       IOCLR1 |= OSEL;	
                        return cmd;
                  }
                
                IOCLR1|=OR2;
                IOSET1|=(OR1|OR3|OR4|OR5|OR6);                     //second ROW = 0
                
                 if((IOPIN1&OC1)==0)
                   {
                        cmd=70; //7th floor down button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                   }
                else if((IOPIN1&OC2)==0)
                  {
                        cmd=71;//7th floor UP button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
                else if((IOPIN1&OC3)==0)
                  {
                        cmd=60;//6TH floor DOWN button
                        keypad_delay();
                       IOCLR1 |= OSEL;	
                        return cmd;
                  }
                
                 IOCLR1|=OR3;
                IOSET1|=(OR1|OR2|OR4|OR5|OR6);                     //3RD ROW = 0
                
                 if((IOPIN1&OC1)==0)
                   {
                        cmd=61; //6th floor UP button
                        keypad_delay();
                       IOCLR1 |= OSEL;	
                        return cmd;
                   }
                else if((IOPIN1&OC2)==0)
                  {
                        cmd=50;//5th floor down button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
                else if((IOPIN1&OC3)==0)
                  {
                        cmd=51;//5th floor up button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
                
                IOCLR1|=OR4;
                IOSET1|=(OR1|OR2|OR3|OR5|OR6);                     //second column = 0
                
                 if((IOPIN1&OC1)==0)
                   {
                        cmd=40; //4th floor down button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                   }
                else if((IOPIN1&OC2)==0)
                  {
                        cmd=41;//4th floor UP button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
                else if((IOPIN1&OC3)==0)
                  {
                        cmd=30;//3th floor DOWN button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
									
									 IOCLR1|=OR5;
                IOSET1|=(OR1|OR2|OR3|OR4|OR6);                     
                
                 if((IOPIN1&OC1)==0)
                   {
                        cmd=31; //3RD floor UP button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                   }
                else if((IOPIN1&OC2)==0)
                  {
                        cmd=20;//2ND floor down button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
                else if((IOPIN1&OC3)==0)
                  {
                        cmd=21;//2ND floor up button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
									 
									
								IOCLR1|=OR6;
                IOSET1|=(OR1|OR3|OR4|OR5|OR2);                     
                
                 if((IOPIN1&OC1)==0)
                   {
                        cmd=10; //1ST floor down button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                   }
                else if((IOPIN1&OC2)==0)
                  {
                        cmd=11; //1ST floor UP button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
                else if((IOPIN1&OC3)==0)
                  {
                        cmd=01;//0th floor up button
                        keypad_delay();
                        IOCLR1 |= OSEL;	
                        return cmd;
                  }
         // }
			IOCLR1 |= OSEL;
			return 00; //if all buttons not pressed then do this
   }
unsigned int  innerInput (void) {  //done 
		 
	
				IOSET1|= ISEL;  //after int happend set this to high so the UP could connect to the switch array...set to 1 to deselect after finishing int 
			
				int cmd;//to hold the place of floor called and  dxt of intendded travel
      
				IOCLR1|=(OR1|OR2|OR3|OR4|OR5|OR6|IC1|IC2);
   
		 //while(1)
          // {
                IOCLR1|=OR1;
                IOSET1|=(OR2|OR3|OR3|OR4|OR5|OR6);                     // first ROW = 0
                
                if((IOPIN1&IC1)==0)
                   {
                        cmd=9; //9th floor down button
                        keypad_delay();
												IOCLR1 |= ISEL;
                        return cmd;
                   }
                else if((IOPIN1&IC2)==0)
                  {
                        cmd=8;//8th floor down button
                        keypad_delay();
												IOCLR1 |= ISEL;
                        return cmd;
                  }
                
                IOCLR1|=OR2;
                IOSET1|=(OR1|OR3|OR4|OR5|OR6);                     //second ROW = 0
                
                 if((IOPIN1&IC1)==0)
                   {
                        cmd=7; //7th floor down button
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                   }
                else if((IOPIN1&IC2)==0)
                  {
                        cmd=6;
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                  }
                
                
								IOCLR1|=OR3;
                IOSET1|=(OR1|OR2|OR4|OR5|OR6);                     //3RD ROW = 0
                
                 if((IOPIN1&IC1)==0)
                   {
                        cmd=5; 
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                   }
                else if((IOPIN1&IC2)==0)
                  {
                        cmd=4;//4th floor 
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                  }
                
                IOCLR1|=OR4;
                IOSET1|=(OR1|OR2|OR3|OR5|OR6);                    
                
                 if((IOPIN1&IC1)==0)
                   {
                        cmd=3; 
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                   }
                else if((IOPIN1&IC2)==0)
                  {
                        cmd=2;
                        keypad_delay();
												IOCLR1 |= ISEL;
												return cmd;
                  }
            
									
								IOCLR1|=OR5;
                IOSET1|=(OR1|OR2|OR3|OR4|OR6);                     
                
                 if((IOPIN1&IC1)==0)
                   {
                        cmd=1; 
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                   }
                else if((IOPIN1&IC2)==0)
                  {
                        cmd=0;//GROUND floor
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                  }
									 
									
								IOCLR1|=OR6;
                IOSET1|=(OR1|OR3|OR4|OR5|OR2);                     
                
                 if((IOPIN1&IC1)==0)
                   {
                        cmd=11; //door open
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                   }
                else if((IOPIN1&IC2)==0)
                  {
                        cmd=22; //door close
                        keypad_delay();
                        IOCLR1 |= ISEL;
                        return cmd;
                  }	
         // }	
					IOCLR1 |= ISEL;
				return 33;//code for error or no button is pressd from the input and was called in false interrupt
}
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void delay_ms(short j)  {
	
    short x,i,l;
	for(i=0;i<j;i++)
	{
    for(x=0; x<1000; x++)/* loop to generate 1 milisecond delay with Pclk=12MHz */
			{l=i;}//do something otherwise compiler optimizes and jumps the loop heheeeeheheh
	}
}
void PWM_init(){

PINSEL1 |=01<<10;
PWMPCR=1<<13;
PWMMR0=150000;//full cycle time
PWMTCR=0x09;
PWMMCR=0x02;
	
}
void motor(char dxn,short diff){
	unsigned int speed[10]={0,16666,33332,49998,66664,83330,99996,116662,133328,149994};
	IODIR1 |=1<<29;
	
	if(dxn=='U'){
		IOSET1 |= 1<<29;
		PWMMR5=speed[diff];
	
	}else if(dxn=='D'){
		diff=diff*-1; //since diff is negative..
		IOCLR1 |= 1<<29;
		PWMMR5=speed[diff];
	}else if(dxn=='N'||dxn=='S'){
		PWMMR5=speed[0];
	}	
PWMLER=1<<5;
}

void openDoor(){
IO1DIR |=1<<30;
IODIR1 |=1<<31;//==8000 0000

IOSET1 |=1<<30;
IOCLR1 |=1<<31;
 delay_ms(5000); //6 sec delay
IOCLR1 |=1<<30;
}
void closeDoor(){
IODIR1 |=1<<30;
IODIR1 |=1<<31;

IOSET1 |= 1<<31;
IOCLR1 |= 1<<30;
delay_ms(5000); //6 sec delay
IOCLR1 |=1<<31;
}
void display(short number){
IODIR0 |=1<<12 | 1<<13 | 1<<14 | 1<<15;
//bit 0 at 12 and bit 3 at 15
	switch (number){
		case 0:
			 IOCLR0 |= 1<<12 | 1<<13 | 1<<14 | 1<<15;
			break;
		case 1:
			 IOCLR0 |= 1<<13 | 1<<14 | 1<<15;
			 IOSET0 |= 1<<12;
			break;
		case 2:
			 IOCLR0 |= 1<<12 | 1<<14 | 1<<15;
			 IOSET0 |= 1<<13;
			break;
		case 3:
			 IOCLR0 |= 1<<14 | 1<<15;
			 IOSET0 |= 1<<12 | 1<<13;
			break;
		case 4:
			 IOCLR0 |= 1<<12 | 1<<13 | 1<<15;
			 IOSET0 |= 1<<14;
			break;
		case 5:
			 IOCLR0 |= 1<<13 | 1<<15;
			 IOSET0 |= 1<<12 | 1<<14;
			break;
		case 6:
			 IOCLR0 |= 1<<12 | 1<<15;
			 IOSET0 |= 1<<13 | 1<<14;
			break;
		case 7:
			 IOCLR0 |= 1<<15;
			 IOSET0 |= 1<<12 | 1<<13|1<<14;
			break;
		case 8:
			 IOCLR0 |= 1<<12 | 1<<13|1<<14;
			 IOSET0 |= 1<<15;
			break;
		case 9:
			 IOCLR0 |= 1<<13 | 1<<14;
			 IOSET0 |= 1<<15 | 1<<12 ;
			break;
			case 11://display error
			 IOCLR0 |= 1<<12;
			 IOSET0 |= 1<<15| 1<<13 | 1<<14 ;
			break;
		default:
			 IOCLR0 |= 1<<12 | 1<<13 | 1<<14 | 1<<15;
			break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

__irq void alarm(void){

		display(11);
		motor('S',0);//immediately stop the motor
		openDoor();
		delay_ms(10000);//
		closeDoor();	
	
		EXTINT |= 1; //Clear the MR0 Interrupt EXTINT |= 0x4; 
	VICVectAddr =0;
	
}

void enableAlarmInterrupt(){
	EXTMODE  |=1<<0;//enable external interrupt on EXT 0 pin
	EXTPOLAR |=1<<0; //rising edge 
	
	PINSEL0  |= 0x3<<2; //PIN0.1 as interrupt 

	
	VICIntSelect &= ~(1<<14); //IRQ
	VICVectAddr4 = (unsigned int)alarm;//ISR
	
	//VICDefVectAddr =(unsigned int)DefInterrupt; //
	VICVectCntl4 =  (1<<5)|14;//IRQslot_en,for interrupt 14
	VICIntEnable |= (1<<14);//EXT0 interrupt 
	
	EXTINT |= 1; 
	//EXTINT &= ~(0x1);
}
__irq void internalInput(void){

	unsigned short cmd = innerInput();
	if (cmd==33){
		EXTINT |= 1<<1; //Clear the MR0 Interrupt 
		VICVectAddr =0;
	}else{
		 if(cmd==11){//open door
		//check motor speed then use that to determine if to open the door or not
		motor('S',0);//stops the motor
			openDoor();
				delay_ms(2000);//loading and unloading  time
			closeDoor();
		}else if(cmd==22){//close door may need more condition
		closeDoor();
		}else{ //might need other cases tooo 
			if( (cmd>currentFloor) && (tripDxn=='U'||tripDxn=='N'))
					OQ[cmd]=1;
			else if( (cmd<currentFloor) && (tripDxn=='D'||tripDxn=='N'))
					OQ[cmd]=1;
			else if( (cmd>=currentFloor) && (tripDxn=='D'||tripDxn!='N'))
					NOQ[cmd]=1;//if cmd is equal the motor couldnt stop quickly
			else if( (cmd<=currentFloor) && (tripDxn=='U'||tripDxn!='N'))
					NOQ[cmd]=1;
		}
	
	EXTINT |= 1<<1; //Clear the MR0 Interrupt 
	VICVectAddr =0;
	}
}

void enableInternalInputInterrupt(){
	EXTMODE |= 0x2;//enable  edge trig external interrupt on EXT 1 pin
	EXTPOLAR |= 0<<1; //falling edge 
	
	PINSEL0 |= 0x3<<6; //PIN0.3 as interrupt eint1 

	
	VICIntSelect &= ~(1<<15); //IRQ may need some mod to use |=
	VICVectAddr6 = (unsigned int)internalInput;//ISR
	
	//VICDefVectAddr =(unsigned int)DefInterrupt; //
	VICVectCntl6 =  (1<<5)|15;//IRQslot_en,for interrupt 15
	VICIntEnable |= (1<<15);//EXT1 interrupt 
	
		EXTINT |= 1<<1;
	//EXTINT &= ~(0x2);
}


__irq void externalInput(void){

	unsigned short ecmd=outerInput ();
	if(ecmd==0){//interrupt happens at the beging and if the interruput is raised without any key being pressed do this.
	EXTINT = 1<<2; //Clear the MR0 Interrupt EXTINT |= 0x4; 
	VICVectAddr =0;
	}else{
	unsigned short edxn=ecmd%10;//encoded at the keypad interface like this(81..8th floor up dxn)
	char cedxn;
		if(edxn==0)
			cedxn='D';
		else
			cedxn='U';
	unsigned short floor=ecmd/10; //91/10=9 for short data type(auto casting)
		 if( (floor>currentFloor) && (tripDxn==cedxn||tripDxn=='N'))
					OQ[floor]=1;
		 else if( (floor<currentFloor) && (tripDxn==cedxn||tripDxn=='N'))
					OQ[floor]=1;
		 else if( (floor>=currentFloor) && (tripDxn!=cedxn||tripDxn!='N'))
					NOQ[floor]=1;
		 else if( (floor<=currentFloor) && (tripDxn!=cedxn||tripDxn!='N'))
					NOQ[floor]=1;
		 
	
	EXTINT = 1<<2; //Clear the MR0 Interrupt EXTINT |= 0x4; 
	VICVectAddr =0;
	}
}

void enableExternalInputInterrupt(){
	EXTMODE |=1<<2; ;//enable external interrupt on EXT 2 pin 0100
	EXTPOLAR |= 0<<2; //rising edge 
	PINSEL0 |= 0x3<<14; //PIN0.7 as interrupt eint2

	
	VICIntSelect &= ~(1<<16); //IRQ
	VICVectAddr7 = (unsigned int)externalInput;//ISR
	
	//VICDefVectAddr =(unsigned int)DefInterrupt; //
	VICVectCntl7 =  (1<<5)|16;//IRQslot_en,for interrupt 14
	VICIntEnable |= (1<<16);//EXT2 interrupt 
	EXTINT |=1<<2;
	//EXTINT &= ~(0x4);
}
__irq void motorposition(void){

			if(tripDxn=='U')
				currentFloor++;
			else if(tripDxn=='D')
				currentFloor--;
	
	EXTINT |= 1<<3; //Clear the MR0 Interrupt EXTINT |= 0x4; 
	VICVectAddr =0;
}

void enableMotorInterrupt(){
	EXTMODE  |=1<<3; ;//enable external interrupt on EXT 3 pin 1000
	EXTPOLAR |= 1<<3; //falling edge 
	
	PINSEL0 |= 0x3<<18; //PIN0.9 as interrupt eint2

	
	VICIntSelect &= ~(1<<17); //IRQ
	VICVectAddr8 = (unsigned int)motorposition;//ISR
	
	//VICDefVectAddr =(unsigned int)DefInterrupt; //
	VICVectCntl8 =  (1<<5)|17;//IRQslot_en,for interrupt 14
	VICIntEnable |= (1<<17);//EXT0 interrupt 
	EXTINT |= 1<<3;
	//EXTINT &= ~(0x8);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void copyQue(){
	for(int i=0;i<=9;i++){
	OQ[i]=NOQ[i];
	NOQ[i]=0;
	}
tripDxn='N';
}
short nextDestination(){
	top:
			if(tripDxn=='U'){
				for(int i=0;i<=9;i++){
						if(OQ[i]==1){
								return i;
						}
					}
				copyQue();
				goto top;//maybe put the elevator in idle mode if the loop is over some number of times
			}else if(tripDxn=='D'){
					for(int i=9;i>=0;i--){
						if(OQ[i]==1){
						return i;
						}
					}
					copyQue();
					goto top;
			}else if(tripDxn=='N'){
				short temp;
				for(int cmd=0;cmd<=9;cmd++){
						if(OQ[cmd]==1){
						temp=cmd-currentFloor;
							if(temp>0){
								tripDxn='U';
								goto top;
							}
							else if(temp<=0){
								tripDxn='D';
								goto top;
							}
						}
					}
			}
	return 0;//if in case all of the above coditions and stuff didnt workout 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void elevatorTravel(){
		
	short next= nextDestination();
	
				while((next-currentFloor)!=0){//while((toFloor-currentFloor)!=0)i
						motor(tripDxn,(next-currentFloor));
						display(currentFloor);
						next=nextDestination();
				}
				display(currentFloor);
				motor('S',0);
				openDoor();
				delay_ms(2000);//loading and unloading  time
				closeDoor();
				OQ[next]=0;//set to zero to show that the order is completed properly
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
			PINSEL1 = 0x00000000;
      IODIR1 = 0x07F80000;//111 1111 1000 0000 0000 0000 0000 as op 19 upto 26 where 19-24 for ORB and 25,16 for sel
			
			IOCLR1 |= OSEL;	//to close the outer button from connecting to the LPC2148
			IOCLR1 |= ISEL;	//to close the inner button from connecting to the LPC2148
	//To configure the motor to some specific position during the start
	IODIR0 |=1<<21;
	IOSET0 |=1<<21;
	delay_ms(800);
	IOCLR0 |=1<<21;

	enableAlarmInterrupt();
	enableExternalInputInterrupt();
	enableInternalInputInterrupt();
	enableMotorInterrupt();

	PWM_init();
	
	while(1){
		
		while(nextDestination())
		{
				elevatorTravel();
		}
		//motor('D',-currentFloor);//to make it go to the ground floor and stop it there with the door open 
		
	
	}	

}