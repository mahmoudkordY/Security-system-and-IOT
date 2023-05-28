//Beni-seuf University(BSU) Projects Using 8051 microcontrller
//contacts:kordymahmoud00@gmail.com
#include <REGX51.H>
#include <stdio.h> 
#include <string.h>

#define keypad P1 //for port 1
#define LCD P2

sbit mrs_sensor=P3^2; //defrning pins 
sbit pir_sensor=P3^3;
sbit rs =P3^4;
sbit en =P3^5;
sbit door = P3^6;
sbit bzr_h = P3^7;
sbit alarm_led = P0^5;
sbit pir_led = P0^6;
sbit rs_led = P0^7;
sbit try = P0^4;

int count = 1; //integer value called count = 1 
unsigned int lcd_cursor; // An unsigned integer variable named lcd_cursor

char a = '1'; // a,b,c,d are charcters with values 1,2,5,8 and that is the password
char b = '2';
char c = '5';
char d = '8';
unsigned char e; // e,f,g,,h are charcters without values and will be compared to the a.b.c.d to make the password correct or not
unsigned char f;
unsigned char g;
unsigned char h;

void string(char *); //declring some functions and definening thier kinds
void dely(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);
char get_keypad_key(void);

void main(void)
{	
	char KeyVal =0;  //initialzing pins 
	alarm_led = 0;
	pir_led = 0;
	rs_led = 0;
	door = 1;
	bzr_h = 1;
	
lcd_cmd(0x38);      // Configure LCD
lcd_cmd(0x01);      // Clear LCD      // Clear LCD
lcd_cmd(0x10);      // Shift cursor to the left
lcd_cmd(0x0C);      // Turn on display, hide cursor
lcd_cmd(0x80);      // Set cursor to the beginning of the first line

lcd_cmd(0x38);      // Configure LCD
lcd_cmd(0x01);      // Clear LCD      // Clear LCD
lcd_cmd(0x10);      // Shift cursor to the left
lcd_cmd(0x0C);      // Turn on display, hide cursor
lcd_cmd(0x80);      // Set cursor to the beginning of the first line

string("Welcome  '_'      ");
dely(100);
lcd_cmd(0x01);      // Clear LCD     


string("How are you ");
lcd_cmd(0x01);      // Clear LCD     

string("Dr.Lila ");
lcd_cmd(0x01);      // Clear LCD     
string("Beni-Seuf");
lcd_cmd(0x01);      // Clear LCD     

string("University(BSU)");
lcd_cmd(0x01);      // Clear LCD      
//contacts:kordymahmoud00@gmail.com

	
	while(1)
	{	
		string("Enter Password: ");
		lcd_cmd(0x01);      // Clear LCD    
			
    while(1)
    {					
		alarm_led = 0;
		dely(100);

				
		if(lcd_cursor < 4)
		{
			lcd_cmd(0x88+lcd_cursor);
			if(lcd_cursor == 1)
				e = KeyVal;
			if(lcd_cursor == 2)
				f = KeyVal;
			if(lcd_cursor == 3)
				g = KeyVal;
		}
				
		if(lcd_cursor == 4)
		{	
			dely(100);
			h = KeyVal;
			lcd_cmd(0x88 + lcd_cursor);
			KeyVal = get_keypad_key();
			lcd_data(KeyVal);
			dely(100);
					
			if(KeyVal == '*')
			{
				dely(200);

							
					if(a == e && b == f && c == g && d == h) // that means the password is the values of a,b,c,d then press *
					{
						lcd_cmd(0x01);      // Clear LCD
						string("Correct");
						dely(200);
						lcd_cmd(0x01);      // Clear LCD
						string("Door is open Dr");
						
								
						while(count < 3)  //loop for 3 iterations
						{									
							alarm_led = 1;
							door = 0;
							dely(300);
							try = 1;
							door = 1;     //open the door 
							alarm_led = 0;
							dely(300);
							count++;  //if the loop is not comppleted add 1
						}
									
						e = 'x';   //make e,f,g,h in x varieble 
						f = 'x';
						g = 'x';
						h = 'x';								
						count = 0;
									
						while(pir_sensor == 0 && mrs_sensor == 0)
						{	
							alarm_led = 1;
							pir_led = 1;
							rs_led = 1;
							dely(200);
						}
								
						lcd_cmd(0x01);      // Clear LCD
						string("SECURITY VIOLATION");
						dely(500);
						lcd_cmd(0x01);      // Clear LCD
						lcd_cursor = 0;
								
						while(count < 1)
						{
							string("Enter Password: ");
							dely(50);
						    lcd_cmd(0x01);      // Clear LCD
									
							while(1)
							{	
								alarm_led = 0;
								pir_led = 0;
								rs_led = 0;
								door = 1;
								dely(50);
										
								if(lcd_cursor < 4)									
								{
									lcd_cmd(0x88+lcd_cursor);
									if(lcd_cursor == 1)
										e = KeyVal;
									if(lcd_cursor == 2)
										f = KeyVal;
									if(lcd_cursor == 3)
										g = KeyVal;
									dely(50);
									}						
											
								if(lcd_cursor == 4)
								{	
																			
									h = KeyVal;
									lcd_cmd(0x88 + lcd_cursor);
									KeyVal = get_keypad_key();
									lcd_data(KeyVal);
									
											
									if(KeyVal == '*')
									{	
										dely(200);
													
										if(a == e && b == f && c == g && d == h)
										{			
											lcd_cmd(0x01);      // Clear LCD
											string("correct Password ");
											dely(200);
											lcd_cmd(0x01);      // Clear LCD
											string("ALARM DISABLED");
														
											alarm_led = 0;
											pir_led = 0;
											rs_led = 0;
											door = 1;
														
											while(1)
											{
												
											}
										}
											
										else
										{	
											count = 0;
											lcd_cmd(0x01);      // Clear LCD
											string("SECURITY VIOLATION");
														
											while(count < 300)
											{
												alarm_led = 1;
												pir_led = 1;
												rs_led = 1;
												bzr_h = 1;
															
												SCON = 0X50;
												TMOD = 0X20;
												TH1 = -3;
												TR1 = 1;
												SBUF = '1';
															
												while(TI == 0);
												TI = 0;
															
												dely(300);														
												alarm_led = 0;
												pir_led = 0;
												rs_led = 0;
												bzr_h = 1;														
												dely(300);
											}
										}												
									}
												
									else
									{
										lcd_cmd(0x01);                  // Clear LCD
										lcd_cursor = 0;
										break;
									}												
								}
										
								alarm_led = 1;
								pir_led = 1;
								rs_led = 1;
								door = 0;									
								
										
								KeyVal = get_keypad_key();
								lcd_data(KeyVal);									
								
								count++;	
											
								if (lcd_cursor > 4 || KeyVal == '#')	
								{
									lcd_cmd(0x01);                             // Clear LCD
									lcd_cursor = 0;
									break;
								}
							}
						}
					}
							
				else
				{	
					lcd_cmd(0x01);                       // Clear LCD
					string("WRONG Password");
					dely(300);
					bzr_h = 1;	
					dely(300);
					bzr_h = 0;	
					dely(300);												
					alarm_led = 1;
					pir_led = 0;
					rs_led = 0;
					bzr_h = 1;														
					dely(300);
					break;
				}		
			}
						
			else
			{		
				lcd_cmd(0x01);      // Clear LCD
				lcd_cursor = 0;
				count = 0;
				break;
			}						
		}
				
		alarm_led = 1;
		
				
		KeyVal = get_keypad_key();
		lcd_data(KeyVal);
						
				
		if (lcd_cursor > 4 || KeyVal == '#')	
		{
			lcd_cmd(0x01);      // Clear LCD
			lcd_cursor = 0;
			count = 0;
			break;
		}
    }
	}	
}

char get_keypad_key(void)
{
    char key_val = 0;
    
    keypad = 0xFE;
    if (keypad == 0xEE) // button 1
    {
        key_val = '*';
        lcd_cursor++;
    }
    if (keypad == 0xDE) // button 2
    {
        key_val = '0';
        lcd_cursor++;
    }
    if (keypad == 0xBE) // button 3
    {
        key_val = '#';
        lcd_cursor++;
    }
    
    keypad = 0xFD;
    if (keypad == 0xED) // button 4
    {
        key_val = '7';
        lcd_cursor++;
    }
    if (keypad == 0xDD) // button 5
    {
        key_val = '8';
        lcd_cursor++;
    }
    if (keypad == 0xBD) // button 6
    {
        key_val = '9';
        lcd_cursor++;
    }
    
    keypad = 0xFB;
    if (keypad == 0xEB) // button 7
    {
        key_val = '4';
        lcd_cursor++;
    }
    if (keypad == 0xDB) // button 8
    {
        key_val = '5';
        lcd_cursor++;
    }
    if (keypad == 0xBB) // button 9
    {
        key_val = '6';
        lcd_cursor++;
    }
    
    keypad = 0xF7;
    if (keypad == 0xE7) // button *
    {
        key_val = '1';
        lcd_cursor++;
    }
    if (keypad == 0xD7) // button 0
    {
        key_val = '2';
        lcd_cursor++;
    }
    if (keypad == 0xB7) // button #
    {
        key_val = '3';
        lcd_cursor++;
    }
    
    return key_val;
}
//contacts:kordymahmoud00@gmail.com


void lcd_str(unsigned char *str)
{
	unsigned int loop =0;
	for(loop =0; str[loop]!= '\0'; loop++)
	{
		lcd_data(str[loop]);
	}
}

void lcd_data(unsigned char ch)
{
	LCD = ch;
	rs = 1;
	en = 1;
	dely(10);
	en = 0;
}

void lcd_cmd(unsigned char ch)
{
	LCD = ch;
	rs = 0;
	en = 1;
	dely(10);
	en = 0;
}

void string(char *p)
{
	while(*p)
	{
		lcd_data(*p++);
	}
}

void dely(unsigned int dly)
{
	unsigned int loop =0;
	unsigned int delay_gen =0;
	for(loop =0; loop < dly; loop++)
	for(delay_gen =0; delay_gen < 1000; delay_gen++);
}
//contacts:kordymahmoud00@gmail.com
