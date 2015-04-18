% Pointing Controller Run Code:
clc
clear all

%% Inertia Matrix 
J1 = 4.2946e-2; % kg/m^2
J2 = 5.7648e-2; % kg/m^2
J3 = 1.9229e-2; % kg/m^2
J = diag([J1 J2 J3]); % kg/m^2

%% Initial Conditions 
omega1_IC = 0; % rad/s
omega2_IC = 0; % rad/s
omega3_IC = 0; % rad/s
q1_IC = 0.1;
q2_IC = 0.2;
q3_IC = 0.3;
q4_IC = 0.92736;

%% Desired Attitude in Euler Angles in deg
phi_des = 30; % deg (converted to radians in the Simulink file!)
theta_des = 120; % deg (converted to radians in the Simulink file!)
psi_des = 90; % deg (converted to radians in the Simulink file!)

%% Desired Euler Rates in deg/s
phi_dot_des = 0; % rad/s
theta_dot_des = 0; % rad/s
psi_dot_des = 0; % rad/s

%% Crassidis Control Gains 
kq = 1;
kw = 1;

%% Time Step
ts = 0.01; % sec

%% Plots

figure()
subplot(3,1,1)
plot(omega_actual)
title('Actual Angular Rates')
xlabel('Time (sec)')
ylabel('Angular Rate \omega (rad/s)')
legend('\omega_1', '\omega_2', '\omega_3', 'Location','NorthEast')
axis([0 350 -4 4])
subplot(3,1,2)
plot(omega_des)
title('Desired Angular Rates')
xlabel('Time (sec)')
ylabel('Angular Rate \omega (rad/s)')
legend('\omega_1', '\omega_2', '\omega_3', 'Location','NorthEast')
axis([0 350 -4 4])
subplot(3,1,3)
plot(omega_error)
title('Error Between Desired and Actual Angular Rates')
xlabel('Time (sec)')
ylabel('Angular Rate Error \omega (rad/s)')
legend('\omega_1', '\omega_2', '\omega_3', 'Location','NorthEast')
axis([0 350 -4 4])

figure()
subplot(3,1,1)
plot(q_actual)
title('Actual Quaternions')
xlabel('Time (sec)')
ylabel('Quaternion')
legend('q_1', 'q_2', 'q_3','q_4','Location','NorthEast')
axis([0 350 -1 1])
subplot(3,1,2)
plot(q_des)
title('Desired Quaternions')
xlabel('Time (sec)')
ylabel('Quaternion')
legend('q_1', 'q_2', 'q_3','q_4','Location','NorthEast')
axis([0 350 -1 1])
subplot(3,1,3)
plot(q_error)
title('Error Between Desired and Actual Quaternions')
xlabel('Time (sec)')
ylabel('Quaternion')
legend('q_1', 'q_2', 'q_3','q_4','Location','NorthEast')
axis([0 350 -1 1])
