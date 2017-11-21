#include <master.h>

//Cau hinh Keypad
#define COT_1 PIN_D4
#define COT_2 PIN_D5
#define COT_3 PIN_D6
#define HANG_1 input(PIN_D0)
#define HANG_2 input(PIN_D1)
#define HANG_3 input(PIN_D2)
#define HANG_4 input(PIN_D3)
int8 value[4] = {0,0,0,0};
char phimnhan[12]=
               {
                  '1','2','3', 
                  '4','5','6',
                  '7','8','9',
                  '*','0','#',
               };
               
void controlCol(int cot, int state)
{
   switch(cot)
   {
      case 1:
      {
         output_bit(COT_1,state);
         break;
      }
      case 2:
      {
         output_bit(COT_2,state);
         break;
      }
      case 3:
      {
         output_bit(COT_3,state);
         break;
      }
      
   }
}

void scanCol()
{
   int i;
   for(i==1;i<=3;i++)
   {
      controlCol(i,0);
   }
}

char scanKey()
{
   int8 Key = 0;
   controlCol(1,1);
   if(HANG_1==1)
   {
      Key = 1;
   }
   if(HANG_2==1)
   {
      Key = 4;
   }
   if(HANG_3==1)
   {
      Key = 7;
   }
   if(HANG_4==1)
   {
      Key = 10;
   }
   controlCol(1,0);
   controlCol(2,1);
   if(HANG_1==1)
   {
      Key = 2;
   }
   if(HANG_2==1)
   {
      Key = 5;
   }
   if(HANG_3==1)
   {
      Key = 8;
   }
   if(HANG_4==1)
   {
      Key = 11;
   }
   controlCol(2,0);
   controlCol(3,1);
   if(HANG_1==1)
   {
      Key = 3;
   }
   if(HANG_2==1)
   {
      Key = 6;
   }
   if(HANG_3==1)
   {
      Key = 9;
   }
   if(HANG_4==1)
   {
      Key = 12;
   }
   controlCol(3,0);
   return Key;
}

void outputNumb(int16 number)
{
   unsigned int16 temp;
   
   temp = number;  // ex: number = 1234 
   value[3] = temp %10;  //  4
   
   temp = temp/10;
   value[2] = temp%10;  // 3
   
   temp = temp/10; 
   value[1] = temp%10; //  2
   
   temp = temp/10;
   value[0] = temp; //  1
}

const int8 slave1 = 0x10;


void write_i2c(int8 value, int8 slave_addr) //write i2c
{
   i2c_start();            // start condition
   i2c_write(slave_addr);  // device address
   i2c_write(value);       // device data
   i2c_stop();             // stop condition 
}

void enterNumb()
{
   int key=0,temp=0;
   char signal;
   while(1)
   {
      key = scanKey();
      if(key!=0)
      {
         temp=key;
         signal = phimnhan[temp-1];
         switch(signal)
         {
            case '1':
            {
               write_i2c(1,slave1);
               break;
            }
            case '2':
            {
               write_i2c(2,slave1);
               break;
            }
            case '3':
            {
               write_i2c(3,slave1);
               break;
            }
            case '4':
            {
               write_i2c(4,slave1);
               break;
            }
            case '5':
            {
               write_i2c(5,slave1);
               break;
            }
            case '6':
            {
               write_i2c(6,slave1);
               break;
            }
            case '7':
            {
               write_i2c(7,slave1);
               break;
            }
            case '8':
            {
               write_i2c(8,slave1);
               break;
            }
            case '9':
            {
               write_i2c(9,slave1);
               break;
            }
            case '0':
            {
               write_i2c(0,slave1);
               break;
            }
            case '*':
            {
               write_i2c(10,slave1);
               break;
            }
            case '#':
            {
               write_i2c(11,slave1);
               break;
            }
            default:
            {
               write_i2c(99,slave1);
               break;
            }
         }
         while(scanKey()!=0)
         {delay_ms(5);}
      }
   }
}

void main()
{
   scanCol();
   enable_interrupts(INT_EXT);
   enable_interrupts(INT_EXT_H2L);
   enable_interrupts(GLOBAL);
}

#INT_EXT
void ngatNgoai()
{
   enterNumb();
}
