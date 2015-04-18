%Test Kalman Filter: Noisy Voltmeter

clear all; close all; clc

%Need to know true voltage, but voltmeter generates random noise
%V_a=V_m+w_n

%State Matrix is simply 1
A=1;
%Measuring voltage directly, so H=1
H=1;
%B is the control matrix, constant input means B=0
B=0;
%Covariance Q is small because true voltage is known with a large degree of
%certainty
Q=.0001;
%Measurement covariance R is larger because of the random noise
R=.1;
%x_i is the initial guess for the voltage
V_i=3;
%P_i is initial guess for covariance
P_i=1;

%Now to set up kalman filter equations:

%True Voltage
V_a=5*ones(100);
%Generating random noise
a=.05;
b=-.05;
w_n= (a + (b-a).*rand(100,1));
%Setting up storage matrix:
V_hist=zeros(1,100);
V_m=zeros(1,100);

for i=1:100
   %Kalman filter equations
   V_p=A*V_i;
   P_p=P_i+Q;
   z_n=V_a(i)+w_n(i);
   y=z_n-V_p;
   S=P_p+R;
   K=P_p*1*(1/S);
   V=V_p+K*y;
   P=(1-(K*H))*P_p;
   
   %Storing the voltage:
   V_hist(i)=V;
   V_m(i)=z_n;
   k_hist(i)=K;
   
   %Setting the previous values as the initial guess for next iteration:
   V_i=V;
   P_i=P;

end

t=(1:100);
figure (1)
plot1=plot(t, V_a,'b', t, V_hist, 'r', t, V_m,'g.');
xlabel('Time');
ylabel('Voltage');


