%% COMPORTAMIENTO DEL ROBOT

% THETA = [Q1 Q2 Q3 Q4]

% Q1_REAL_QUE_EL_ROBOT_HACE = ANGULO_1_INTRODUCIDO * 270/180;
% Q2_REAL_QUE_EL_ROBOT_HACE = ANGULO_2_INTRODUCIDO;
% Q3_REAL_QUE_EL_ROBOT_HACE = (ANGULO_3_INTRODUCIDO * 270/180) - 180;

% CONSTANTE_GIRO = 270/180 = 1.5;

% ANGULO_A_INTRODUCIR_1 = Q1_REAL_QUE_SE_QUIERE_TENER / CONSTANTE_GIRO;
% ANGULO_A_INTRODUCIR_2 = Q2_REAL_QUE_SE_QUIERE_TENER;
% ANGULO_A_INTRODUCIR_3 = (Q3_REAL_QUE_SE_QUIERE_TENER + 180) / CONSTANTE_GIRO;

% QX_REAL_QUE_SE_QUIERE_TENER = Q1_EC*180/PI;

% ANGULO_A_INTRODUCIR_1 = (Q1_EC*180/PI) / CONSTANTE_GIRO;
% ANGULO_A_INTRODUCIR_2 = (Q2_EC*180/PI);
% ANGULO_A_INTRODUCIR_3 = ((Q3_EC*180/PI) + 180) / CONSTANTE_GIRO;


%% BUSCANDO CUADRANTES Y ANGULOS PERMISIBLES (LAS TRANSFORMACIONES YA HAN SIDO APLICADAS)

% LIMITES POR EL MOMENTO

% Q1 BASE
% EL MOTOR NO LLEGA HASTA EL CUADRANTE II EN EL PLANO 2D XY
% IF Q1 > 270 -> Q1 = 270
% EQUIVALENTE CON LA TRNASFORMACION:
%       Q1 > 180 -> Q1 = 180
%       Q1 < 0 -> Q1 = 0;

% Q2 HOMBRO
% EL MOTOR TRABAJA ENTRE 0 Y 180
% IF Q2 > 180 -> Q2 = 180
% IF Q2 < 0 -> Q2 = 0


% Q3 CODO
% EL MOTOR TRABAJA ENTRE 0 Y 180
% IF Q3 > 90 -> Q3 = 90
% IF Q3 < -180 -> Q3 = -180
% EQUIVALENTE CON LA TRANSFORMACION
%       Q1 > 90 -> Q1 = 90
%       Q1 < -180 -> Q1 = -180;

% BOT.plot([q1 q2 q3 0]);


%% GENERAR MATRICES

clc
clear

% GENERAR MATRICES A

syms Q1 Q2 Q3 Q4

L1 = 3.0;
L2 = 13.5;
L3 = 5.0+10.0;
L4 = 9;

THETA = [Q1, Q2, Q3, Q4];
d = [L1, 0, 0, -L4];
a = [0, L2, L3, 0];
ALPHA = [pi/2, pi, -pi/2, pi];

A = @(TH, AL, ax, dz) [cos(TH)        ,    -cos(AL)*sin(TH),       sin(AL)*sin(TH),    ax*(cos(TH));
                       sin(TH)        ,     cos(AL)*cos(TH),      -sin(AL)*cos(TH),    ax*(sin(TH));
                          0           ,     sin(AL)        ,       cos(AL)        ,        dz      ;
                          0           ,            0       ,               0      ,         1      ];


A01 = A(THETA(1), ALPHA(1), a(1), d(1))

A12 = A(THETA(2), ALPHA(2), a(2), d(2))

A23 = A(THETA(3), ALPHA(3), a(3), d(3))

A34 = A(THETA(4), ALPHA(4), a(4), d(4))

A02 = A01*A12;

A03 = A02*A23;

A04 = A03*A34;


%% CREAR UN MODELO CON X JOINS

% PARAMETROS

L1 = 3.0;
L2 = 13.5;
L3 = 6.50+10.0;
L4 = 9;
L5 = 3.5;


d = [L1, -L5, 0, L4];
a = [0, L2, L3, 0];
ALPHA = [pi/2, 0, pi/2, 0];


% LINKS

LK1 = Link('d', d(1), 'a', a(1), 'alpha', ALPHA(1));
LK2 = Link('d', d(2), 'a', a(2), 'alpha', ALPHA(2));
LK3 = Link('d', d(3), 'a', a(3), 'alpha', ALPHA(3));
LK4 = Link('d', d(4), 'a', a(4), 'alpha', ALPHA(4));


% EL MODELO

BOT = SerialLink([LK1 LK2, LK3, LK4], 'name', 'BINGOBOT');

% THETA = [pi/2, pi/4, pi/6, 0, pi/8, pi/2, pi/3, 0];

Q1 = deg2rad(0);
Q2 = deg2rad(90);
Q3 = deg2rad(40);

BOT.plot([Q1 Q2 Q3 0]);


%% BOT INVERSA

syms Q1     Q2      Q3      Q4
syms N_X    S_X     A_X     X 
syms N_Y    S_Y     A_Y     Y 
syms N_Z    S_Z     A_Z     Z


assume(X,'Real')
assume(Y,'Real')
assume(Z,'Real')


L1 = 3.0;
L2 = 13.5;
L3 = 10.0+5.0;
L4 = 9;

T_SYMBOL=[  N_X     S_X     A_X     X
            N_Y     S_Y     A_Y     Y
            N_Z     S_Z     A_Z     Z
            0       0       0       1   ];


A01 = [ cos(Q1)  ,   0   ,      sin(Q1)    ,   0;
        sin(Q1)  ,   0   ,      -cos(Q1)   ,   0;
        0        ,   1   ,      0          ,   3;
        0        ,   0   ,      0          ,   1];
 

A12 = [ cos(Q2) ,  sin(Q2)      ,   0   ,   (27*cos(Q2))/2;
        sin(Q2) ,  -cos(Q2)     ,   0   ,   (27*sin(Q2))/2;
        0       ,  0            ,  -1   ,                0;
        0       ,  0            ,   0   ,                1];

A23 = [ cos(Q3)     ,   0   ,     -sin(Q3)      ,   15*cos(Q3);
        sin(Q3)     ,   0   ,      cos(Q3)      ,   15*sin(Q3);
        0           ,  -1   ,      0            ,            0;
        0           ,   0   ,      0            ,            1 ];


A34 = [ cos(Q4) ,   sin(Q4)     ,   0   ,       0;
        sin(Q4) ,  -cos(Q4)     ,   0   ,       0;
        0       ,   0           ,  -1   ,      -9;
        0       ,   0           ,   0   ,       1];


A04 = A01*A12*A23*A34;


Q4 = 0;

T1 = A01\T_SYMBOL == A12*A23*A34;
T2 = inv(A12)*inv(A01)*T_SYMBOL == A23*A34;


Q1_S = atan (Y/X);
% Q1_S = solve (T1(3,4));

ECU2 = subs(T2(1,4),Q1,Q1_S);

ECU3 = subs(T2(2,4),Q1,Q1_S);

ECU = [ECU2,ECU3];

[Q2_S,Q3_S] = solve(ECU, [Q2;Q3]);

Q_1 = simplify(Q1_S);
Q_2 = simplify(Q2_S(1,1));
Q_3 = simplify(Q3_S(1,1));



%% PARA QUE EL ROBOT TRABAJE CON EL CODO HACIA ARRIBA SIEMPRE

X = 19.0;
Y = -20.0;
Z = 5.0;


if (X > 0)

    X_TEMP = X;
    Y_TEMP = Y;
    
    X = -X;
    Y = -Y;

    q1 = eval(Q_1) + pi;
    q2 = eval(Q_2);
    q3 = eval(Q_3);

    X = X_TEMP;
    Y = Y_TEMP;

else
    
    q1 = eval(Q_1);
    q2 = eval(Q_2);
    q3 = eval(Q_3);
    
end


DQ1 = q1*180/pi;
DQ2 = q2*180/pi;
DQ3 = q3*180/pi; 


BOT.plot([q1 q2 q3 0]);


%% COMPROBANDO EL CALCULO DEL COMPORTAMIENTO DESEADO

% ECUACION EN ARDUINO

CONSTANTE_GIRO = 270/180;

G1 = (DQ1) / CONSTANTE_GIRO;
G2 = DQ2;
G3 = (DQ3 + 180) / CONSTANTE_GIRO;


% AGREGAR COMPORTAMIENTO DEL ROBOT A LA ECUACION QUE SE PONE EN ARDUINO

ROB_DQ1 = G1 * 270/180;
ROB_DQ2 = G2;
ROB_DQ3 = (G3 * 270/180) - 180;


% OBSERVAR EFECTOS DE LA ECUACION

PRUEBA = [  DQ1         DQ2         DQ3     ;
            G1          G2          G3      ;      
            ROB_DQ1     ROB_DQ2     ROB_DQ3 ]


%% BINGOBOT DIRECTA CON TRAYECTORIA

% MATRICES

T_1(1:41) = SE3();


% POSICIONES INICIALES

Theta_0 = [pi/2+pi, pi/4, pi/6+pi/2, 0];
Theta_1 = [pi/8+pi, pi/2, pi/3+pi/2, 0];


% TRAYECTORIA

p_1(:,1) = tpoly(Theta_0(1), Theta_1(1), 41);
p_1(:,2) = tpoly(Theta_0(2), Theta_1(2), 41);
p_1(:,3) = tpoly(Theta_0(3), Theta_1(3), 41);
p_1(:,4) = tpoly(Theta_0(4), Theta_1(4), 41);


% MODELO Y TRANSFORMADA

L1 = 3.0;
L2 = 13.5;
L3 = 5.0+10.0;
L4 = 9;

t = [1:1:41];

d = [L1, 0, 0, -L4];
a = [0, L2, L3, 0];
ALPHA = [pi/2, pi, -pi/2, pi];


A = @(TH, AL, ax, dz) [cos(TH)        ,    -cos(AL)*sin(TH),       sin(AL)*sin(TH),    ax*(cos(TH));
                       sin(TH)        ,     cos(AL)*cos(TH),      -sin(AL)*cos(TH),    ax*(sin(TH));
                          0           ,     sin(AL)        ,       cos(AL)        ,        dz      ;
                          0           ,            0       ,               0      ,         1      ];


for i= t

    A01 = A(p_1(i,1), ALPHA(1), a(1), d(1));
    A12 = A(p_1(i,2), ALPHA(2), a(2), d(2));
    A23 = A(p_1(i,3), ALPHA(3), a(3), d(3));
    A34 = A(p_1(i,4), ALPHA(4), a(4), d(4));
    
    A02 = A01*A12;
    A03 = A02*A23;
    A04 = A03*A34;
        
    T_1(1,i) = A04;

end

