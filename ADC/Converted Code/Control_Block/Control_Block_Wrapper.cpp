
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

double q_des[4]={};
double q[4]= {};
double omega_des[3]= {}; 
double omega[3]= {};
double T[3]={};

Control_Block_initialize();

string time;
string::size_type sz;

    while(1){

    cin >> q_des[0] >> q_des[1] >> q_des[2] >>q_des[3] >> omega_des[1] >> omega_des[2] >> omega_des[3] >> q[0] >> q[1] >> q[2] >> q[3] >> omega[0] >> omega[1] >> omega[2] >> time;
  
    Control_Block(omega, omega_des, q, q_des, T);
    
    cout << time << ',' << T << endl;
    cout << flush;
    
    Control_Block_terminate();

    }

return 0;
}
    
