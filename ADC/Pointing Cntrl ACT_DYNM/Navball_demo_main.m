%   Navball Demo Parser
%   Written by Andrew Harris, December 14th 2014

%This code is intended to be run after "RUNCODE_Pointing_CntrlACT.m" and
%will not work without it. It reads the angular rates produced by
%'Pointing_Cntrl_Act.slx' and sends them to three seperate serial ports,
%each of which corresponds to a motor which drives a navball. 

load('rates.mat')

sx = serial('COM6');
set(sx,'BaudRate',9600);
set(sx,'DataBits',8);
set(sx,'StopBits',1);
fopen(sx);

sy = serial('COM7');
set(sy,'BaudRate',9600);
set(sy,'DataBits',8);
set(sy,'StopBits',1);
fopen(sy);

sz = serial('COM8');
set(sz,'BaudRate',9600);
set(sz,'DataBits',8);
set(sz,'StopBits',1);
fopen(sz);

