#include <16F877A.h>
#device ADC=10
#use delay(crystal=20000000)
#use i2c(Slave,Fast,sda=PIN_C4,scl=PIN_C3,address=0x10)

