#include "simpletools.h"
#include "servo.h"
#include "servodiffdrive.h"
#include "fdserial.h"
#include "talk.h"
#include "wavplayer.h"
#include "ping.h"

#define PIN_SOUND       26 // pin for the speaker, default=26
#define PIN_XBEE_RX      0
#define PIN_XBEE_TX      1
#define PIN_SERVO_LEFT  14
#define PIN_SERVO_RIGHT 15
#define distance 125
#define SPEED1 50
#define SPEED2 100
int DO = 22, CLK = 23, DI = 24, CS = 25;        // SD I/O pins
const char *WAVfile[] = {"jagger.wav","somebody.wav","callme.wav","rolling.wav","origin.wav","techloop.wav"};       // Set up techloop string
char char2lowercase (char c);
fdserial *xbee;

void core1();
void music(int);
//int ch;
int cmDist;

int k=0;
int control2=0;
int main()                                    // Main function
{
  //print("________");
  
  xbee = fdserial_open(PIN_XBEE_RX, PIN_XBEE_TX, 0, 9600);
  drive_pins(PIN_SERVO_LEFT, PIN_SERVO_RIGHT);
  pause(1000);
	putchar(CLS);
	fdserial_rxFlush(xbee);
  while(1)                                    // Repeat indefinitely
  {
    /*
    ch = fdserial_rxChar(xbee);
    print("%d\n",ch);
	  ch = char2lowercase(ch);
	 fdserial_rxFlush(xbee); 
*/
    pause(200);   
    print("             Let's Start!!!!");                            // Wait 1/5 second
    int ch = fdserial_rxChar(xbee);
      print("We got command %d\n",ch);
	   ch = char2lowercase(ch);
	   fdserial_rxFlush(xbee);
    fdserial_txChar(xbee, ch);
	     fdserial_txFlush(xbee); 
    if(ch-48==1)
    core1();

  }
}

void core1()
{
  print("____Core____");

  int control=0;

  while(1)
  {    
    
    do
    {
        cmDist = ping_cm(17);                 // Get cm distance from Ping)))
        print("cmDist = %d, k = %d\n", cmDist, k);           // Display distance
        k++;
        if(cmDist<10)
          control=1;    
        else
          control=0;
        servo_speed(14,50);
        servo_speed(15,-50);
        pause(50);
    }while(control==0&& k<distance);  
    
    
     servo_speed(14,0);
     servo_speed(15,0);
      
     int status=0;
     int kk=0;
     
     
    
  if(k<distance)
  {
      pause(3000);
      int ch = fdserial_rxChar(xbee);
      print("We got command %d\n",ch);
	   ch = char2lowercase(ch);
      fdserial_rxFlush(xbee);
      fdserial_txChar(xbee, ch);
      fdserial_txFlush(xbee); 
  //////////////////////////////////////////////////////////////////////////// 
      if(ch == '3')
      {
          break;
      }////////////////////////////////////////////////////////////////////
      else if(ch == '2')
      {
		    pause(500);
		    status =2;
		    while(1)
         {
            print("Please give the order:\n");
		        int ch = fdserial_rxChar(xbee);
		        print("We got command %d\n",ch-48);
		        ch = char2lowercase(ch);
		        fdserial_rxFlush(xbee);
             fdserial_txChar(xbee, ch);
		        fdserial_txFlush(xbee);
  //////////////////////////////////////////// 
		        if(ch == '1')
		        {
			 	     //break;
		        }
		        else if(ch == '2')
		        {
		          servo_speed(14,100);
		          servo_speed(15,100);
		          pause(2200);
               servo_speed(14,0);
		          servo_speed(15,0);
		         }///////////////////////////////////
		        else if(ch == '3')
		        {
		          freqout(8,500,1000);
		          freqout(8,500,1000);
		          freqout(8,500,1800);
		          freqout(8,500,1800);
		          freqout(8,500,2300);
		          freqout(8,500,2200);
		          freqout(8,1000,1500);
             } 
             else if(ch == '4')
		        {
               while(1){
               int ch = fdserial_rxChar(xbee);
		          print("We got command %d\n",ch-48);
		          ch = char2lowercase(ch);
		          fdserial_rxFlush(xbee);
               fdserial_txChar(xbee, ch);
		          fdserial_txFlush(xbee);
               if(ch == '3')
               {
                 break;
               }                 
               else if(ch == '4')
               {
                 servo_speed(14,-100);
                 high(26);
		            pause(200);
                 servo_speed(14,0);
                 low(26);
                 pause(50);
                 servo_speed(14,-100);
                 high(26);
		            pause(200);
                 low(26);
                 servo_speed(14,0);
		            servo_speed(15,100);
                 high(27);
                 pause(200);
                 low(27);
                 servo_speed(15,0);
                 pause(50);
                 servo_speed(15,100);
                 high(27);
                 pause(200);
                 low(27);
                 servo_speed(15,0);
                 
                 servo_speed(14,100);
                 high(26);
  		            pause(200);
                 servo_speed(14,0);
                 low(26);
                 pause(50);
                 servo_speed(14,100);
                 high(26);
  		            pause(200);
                 low(26);
                 servo_speed(14,0);
  		            servo_speed(15,-100);
                 high(27);
                 pause(200);
                 low(27);
                 servo_speed(15,0);
                 pause(50);
                 servo_speed(15,-100);
                 high(27);
                 pause(200);
                 low(27);
                 servo_speed(15,0);
               }                 
		          else if(ch == '5')
               {
                 servo_speed(16,100);
                 high(26);
                 freqout(8,100,2800);
                 pause(100);
                 low(26);
                 high(27);
                 servo_speed(16,-100);
                 freqout(8,100,1000);
                 pause(100);
                 low(27);
                 high(26);
                 servo_speed(16,100);
                 freqout(8,100,2800);
                 pause(100);
                 low(26);
                 high(27);
                 servo_speed(16,-100);
                 freqout(8,100,1000);
                 pause(100);
                 low(27);
                 servo_speed(16,0);
                 servo_speed(16,100);
                 high(26);
                 freqout(8,100,2800);
                 pause(100);
                 low(26);
                 high(27);
                 servo_speed(16,-100);
                 freqout(8,100,1000);
                 pause(100);
                 low(27);
                 high(26);
                 servo_speed(16,100);
                 freqout(8,100,2800);
                 pause(100);
                 low(26);
                 high(27);
                 servo_speed(16,-100);
                 freqout(8,100,1000);
                 pause(100);
                 low(27);
                 servo_speed(16,0);
               }                 
             }               
             } 
             else if(ch == '5')
             {
               break;
             }               
		        ch = '0';
         }         
      } //////////////////////////////////
      else
      {
        do
        {
           freqout(8,2000,3000);
           high(26);
           high(27);
	         int ch = fdserial_rxChar(xbee);
		      print("We got command %d\n",ch);
		      ch = char2lowercase(ch);
		      fdserial_rxFlush(xbee);   
           fdserial_txChar(xbee, ch);
		      fdserial_txFlush(xbee);        
	         if(ch == '2')
            {
              low(26);
              low(27);
               break;
            }
            servo_speed(14,-100);            
            servo_speed(15,100);
            pause(100);
            servo_speed(14,100);
            servo_speed(15,-100);
            pause(200);
            servo_speed(14,0);
            servo_speed(15,0);
           
        }while(1);          
        
      }//////////////////////////////////////////////////////////////////////    
  }   
     	
      if(k>=distance)
      {
      servo_speed(14,20);
      servo_speed(15,20);
      pause(3000);
      k=0;
      } 
  }  

}  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
char char2lowercase (char c) {
	return 'A'<=c && c<='Z' ? c+32 : c;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void music(int cho)
{
  print("YAAAAAAAAAAAAAAAAAA\n");
  print("%d\n",cho-(int)'1');
   wav_stop();
  	wav_play(WAVfile[cho-(int)'1']);                 // Pass the wavfile name to wav player (cost 2 core)
 	wav_volume(6);                                  // Adjust volume
}  
