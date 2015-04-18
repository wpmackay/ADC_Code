
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include "Control_Block.h"
#include "Control_Block_initialize.h"
#include "Control_Block_terminate.h"


using namespace std;

int main()  
{

  real_T const q_des[4]= {.4, .6, .1, -0.87};
  real_T const q[4]= {.1, .2, .3, -0.92736};
  real_T const omega_des[3]= {4,2,3}; 
  real_T const omega[3]= {0,0,0};
  real_T T[3]={0,0,0};

  Control_Block_initialize();

  Control_Block(omega, omega_des, q, q_des, T);

  Control_Block_terminate();

  printf("Torque= \n");
		       
  
  for (int i=0; i<3; i++){
       printf("%f\n",T[i]);
  }



return 0;
}
    
