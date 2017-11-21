#include <master.h>

const int8 slave1 = 0x10;


void write_i2c(int8 value, int8 slave_addr) //write i2c
{
   i2c_start();            // start condition
   i2c_write(slave_addr);  // device address
   i2c_write(value);       // device data
   i2c_stop();             // stop condition 
}

void main()
{
   output_bit(PIN_D0,0);
   enable_interrupts(INT_EXT);
   enable_interrupts(INT_EXT_H2L);
   enable_interrupts(GLOBAL);
   while(TRUE)
   {}

}

#INT_EXT
void ngatNgoai()
{
   write_i2c(1,slave1);
}
