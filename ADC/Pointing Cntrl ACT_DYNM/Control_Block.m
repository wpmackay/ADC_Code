function T = Control_Block(omega, omega_des, q, q_des)
%This is a function that emulates the Controller Block of the simulink
%pointing controller.

kw=1;
kq=1;

omega_gain=(-kw)*(omega-omega_des);

q1_des=q_des(1);
q2_des=q_des(2);
q3_des=q_des(3);
q4_des=q_des(4);

Xi_qtilde=[q4_des  -q3_des   q2_des;
           q3_des   q4_des  -q1_des;
          -q2_des   q1_des   q4_des;
          -q1_des  -q2_des  -q3_des]; 
      
Xi_qtilde_trans=transpose(Xi_qtilde);

q_prod=Xi_qtilde_trans*q;
q_gain=(-kq)*q_prod;

T=omega_gain+q_gain;

end

