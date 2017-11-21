#include <slave.h>
#include <lcd.h>

int signal=99,index1=7,index2=1;

#INT_SSP
void ngatSSP()
{
   signal = i2c_read();
}

void showNumb()
{
   if(signal!=99)
   {
      lcd_gotoxy(index1,index2);
      printf(lcd_putc,"%d",signal);
      index1++;
      if(index1==16)
      {
         index2++;
         index1 = 1;
      }
      signal = 99;
   }
}

void main()
{
   lcd_init();
   lcd_putc('\f');
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Value:");
   enable_interrupts(INT_SSP);
   enable_interrupts(GLOBAL);
   while(1)
   {
      showNumb();
   }
}



