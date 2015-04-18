%Kalman filter example 2: Projectile Motion
clear all; close all; clc

x_o=0;
y_o=0;
v_ox=70;
v_oy=150;
g=9.81;
t=0;
j=1;

y=0;
x=0;
v_x=1;
v_y=1;

while y>=0
    x(j)=x_o+v_ox*t;
    v_x(j)=v_ox;
    y(j)=y_o+v_oy*t-.5*g*t^2;
    v_y(j)=v_oy-g*t;
    
    t=t+1;
    j=j+1;
end

a=60;
b=-60;
w_n=(a+(b-a).*rand(j-1,1));

for i=1:j-1
    x_m(i)=x(i)+w_n(i);
    vx_m(i)=v_x(i)+w_n(i);
    y_m(i)=y(i)+w_n(i);
    vy_m(i)=v_y(i)+w_n(i);
end
    
delta_t=1;

A=[1 delta_t 0       0 ;
   0      1  0       0 ;
   0      0  1 delta_t ;
   0      0  0       1];

B=[0 0 0 0 ;
   0 0 0 0 ;
   0 0 1 0 ;
   0 0 0 1];

u=[0;0;-.5*g*delta_t;-g*delta_t];

H=eye(4,4);

x_i=[0; 100*cos(pi/4); 500; 100*sin(pi/4)];

P_i=eye(4,4);

Q=zeros(4,4);

R=.2*eye(4,4);

for i=1:j-1
    
    x_p=A*x_i+B*u;
    P_p=A*P_i*A'+Q;
    z=[x_m(i); vx_m(i);y_m(i); vy_m(i)];
    yk=z-H*x_p;
    S=H*P_p*H'+R;
    K=P_p*H'/S;
    x_n=x_p+K*yk;
    P_n=(eye(4,4)-K*H)*P_p;
    
    x_hist(i)=x_n(1,1);
    vx_hist(i)=x_n(2,1);
    y_hist(i)=x_n(3,1);
    vy_hist(i)=x_n(4,1);
    
    x_i=x_n;
    P_i=P_n;
    
end

plot(x,y,x_hist,y_hist,'r--',x_m,y_m,'g.')
