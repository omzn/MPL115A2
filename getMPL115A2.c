#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <wiringPiI2C.h>

#define DEV_ID 0x60

int swap16(int x) {
  return ( ((x&0x00FF)<<8) + ((x&0xFF00)>>8));
}

double conv_frac(int x,int fbits,int zero) {
  int valsign = 1;
  double valfrac = 0;
  int valint = 0;
  int mask = 0x0001;
  int i;

  if (x & 0x8000) {
    valsign = -1; 
    x = ~x + 1;
  }
  if (zero > 0) {
    x = x >> zero ;
  }
  for (i=fbits;i>0;i--) {
    if (x & mask) {
      valfrac += 1/(pow(2,i));
    }
    mask <<= 1;
  }
  valint = (x & 0x7fff) >> fbits;
  
  return valsign * (valint + valfrac);
}

int get_reg(int fd, int reg) {
  unsigned int data;
  do {
    data = wiringPiI2CReadReg16(fd,reg);
  } while (data < 0);
  return data;
}

int main(void)
{
  unsigned int i2c;
  unsigned int data;
  double padc,tadc;
  double a0,b1,b2,c12,p_comp,p_hpa;

  i2c = wiringPiI2CSetup(DEV_ID) ;
  if (i2c < 0) {
    return -1;
  }
  wiringPiI2CWrite(i2c, 0x12);
  wiringPiI2CWrite(i2c, 0x01);
  usleep(100000);

  padc = swap16(get_reg(i2c,0x00)) >> 6;
  tadc = swap16(get_reg(i2c,0x02)) >> 6;
  a0 = conv_frac(swap16(get_reg(i2c,0x04)),3,0);
  b1 = conv_frac(swap16(get_reg(i2c,0x06)),13,0);
  b2 = conv_frac(swap16(get_reg(i2c,0x08)),14,0);
  c12 = conv_frac(swap16(get_reg(i2c,0x0a)),22,2);
  p_comp = a0 + (b1 + c12 * tadc) * padc + b2 * tadc;
  p_hpa = ((65.0/1023.0) * p_comp + 50) * 10;
  printf("%6.1f\n",p_hpa);

  return 0 ;
}
