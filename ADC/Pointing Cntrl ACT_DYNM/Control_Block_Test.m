clear all
close all
clc

q=[.1 .2 .3 -0.92736]';

q_des=[.4 .6 .1 -0.87]';

omega=[0 0 0]';

omega_des=[4 2 3]';

T=Control_Block(omega, omega_des, q, q_des)


