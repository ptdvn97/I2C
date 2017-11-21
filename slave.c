#include <slave.h>




void main()
{
   output_d(0x00);
   enable_interrupts(INT_SSP);
   enable_interrupts(GLOBAL);
   while(TRUE)
   {}

}


#INT_SSP
void ngatSSP()
{
   int a;
   a = i2c_read();
   if(a==1)
   {
      output_bit(PIN_D0,1);
      delay_ms(1000);
      output_bit(PIN_D0,0);
   }
   
}
