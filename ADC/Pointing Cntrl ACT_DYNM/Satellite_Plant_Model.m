clc
clear all
close all
syms w1 w2 w3 T1 T2 T3 J1 J2 J3

%% Rigid Body Differential Equations 
J = diag([J1 J2 J3]);
w = [w1; w2; w3];
w_tilde = [0 -w3 w2; w3 0 -w1; -w2 w1 0];
T = [T1; T2; T3];
w_dot = -inv(J)*w_tilde*J*w + inv(J)*T;
% w_dot =
%  
%  T1/J1 + (J2*w2*w3)/J1 - (J3*w2*w3)/J1
%  T2/J2 - (J1*w1*w3)/J2 + (J3*w1*w3)/J2
%  T3/J3 + (J1*w1*w2)/J3 - (J2*w1*w2)/J3

J1 = 777537e-9; % kg/m^2
J2 = 80652.2e-9; % kg/m^2
J3 = 343992.9e-9; % kg/m^2

% -----------------------------

%% Quaternion Kinematics Differential Equations 
clc
clear all
close all
syms w1 w2 w3 q1 q2 q3 q4

w = [w1; w2; w3];

Xi_q=[ q4   -q3    q2;
       q3    q4   -q1;
      -q2    q1    q4;
      -q1   -q2   -q3]; 
  
q_dot = 1/2*Xi_q*w;
% q_dot =
%  
%    (q2*w3)/2 - (q3*w2)/2 + (q4*w1)/2
%    (q3*w1)/2 - (q1*w3)/2 + (q4*w2)/2
%    (q1*w2)/2 - (q2*w1)/2 + (q4*w3)/2
%  - (q1*w1)/2 - (q2*w2)/2 - (q3*w3)/2
