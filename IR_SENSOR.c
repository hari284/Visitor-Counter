#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTC
#include<mamalib/lcd.h>

void main()
{
  DDRA=0b11111100;
  //DDRB=0b11111111;
  DDRC=0b11111111;
  DDRD=0xff;
  lcd_init();
  unsigned long int i=0;
  lcd_command(0x80);
  lcd_string("VISITOR COUNTER:");
  while(1)
  {  
		 if(PINA==0x01)
		 {
		  start:
	  
		   //while(PINA&0x01==0x01);
	   
		   while(!(PINA&0x02));
		   while(PINA&0x02==0x02);
		   while(PINA);
		   i++;
		   lcd_command(0xcf);
		   lcd_infinity_number(i);
		   if(i>0)
			 {
			   PORTD=0b00000010;
			 }
			 else
			    PORTD=0x00;
		  while(!(PINA));
	  
		   if((PINA&0x2)==0)
		   {while((PINA&0x02));
	   
		  	     goto start;
			 
		   }
		 else
		 {
	   
		  end:
		    //while(PINA&0x02==0x02);
		
			while(!(PINA&0x01));
	
			while(PINA&0x01==0x01);
			i--;
			lcd_command(0xcf);
			lcd_infinity_number(i);
			if(i>0)
			 {
			   PORTD=0b00000010;
			 }
			 else
			   PORTD=0x00;
			while(!(PINA));
		
			if((PINA&0x01)==0)
			{while((PINA&0x01));
			  goto end;
			}
  		 }
	   }	 
 	 
	  
	 
  }
}
