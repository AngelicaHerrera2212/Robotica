clc
clear
syms n_x s_x a_x x n_y s_y a_y y n_z s_z a_z z q1 q2 q3
syms sol_q1 sol_q2 sol_q3
assume(x,'Real')
assume(y,'Real')
assume(z,'Real')
T_syms=[n_x s_x a_x x
        n_y s_y a_y y
        n_z s_z a_z z
        0   0   0   1 ];

L1 = 11.68;
L2 = 9.08;
L3 = 16.3; %126.26, 87.32, 5.6

A1 = [cos(q1), 0, -sin(q1),  0
      sin(q1), 0,  cos(q1),  0
      0,      -1,      0,   L1
      0,       0,      0,    1];
  
A2 = [cos(q2), -sin(q2),0, L2*cos(q2)
      sin(q2), cos(q2), 0, L2*sin(q2)
      0,       0,       1, 0
      0,       0,       0, 1];
  
A3 = [cos(q3), 0, sin(q3),  L3*cos(q3)
      sin(q3), 0,-cos(q3),  L3*sin(q3)
      0,       1,       0,  0
      0,       0,       0,  1];

T = A1*A2*A3;
x_dir = simplify(T(1,4));
y_dir = simplify(T(2,4));
z_dir = simplify(T(3,4));

% Inverso  algo1\algo2 =  inv(algo1)*algo2
T1= A1\T_syms == A2*A3;
%q; % o atan(y/x)
%q1_e = q1_e(1,1);
q1_e = atan(y/x);
 
T2 = inv(A2)*inv(A1)*T_syms == A3;
eq2 = subs(T2(1,4),q1,q1_e);
eq3 = subs(T2(2,4),q1,q1_e);
eqs = [eq2,eq3];
[q2,q3] = solve(eqs,[q2;q3]);
%q1=solve(T1(3,4),q1);
q1 = atan(y/x);
%simplify(q1)
%simplify(q2)
%simplify(q3)
%  
% x = 18;
% y = 0;
% z = 17;
% q1 = eval(q1)
% rad2deg(q1)
% q2 = eval(q2)
% rad2deg(q2)
% q3 = eval(q3)
% rad2deg(q3)
% 
% eval(x_dir)
% eval(y_dir)
% eval(z_dir)
% 
% % 
% % 
% % 
% 
% 
% 
  