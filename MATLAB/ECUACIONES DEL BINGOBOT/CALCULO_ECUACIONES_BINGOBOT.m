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

% Un serial Link manipulator comprende una serie de Links
% Cada Link se define los 4 parametros de Denavit-Hartenberg
% Por ejemplo, si creamos un modelos sencillo con 2 Links
% Se crea el primer link con los valores: L1 = Link('d', 0, 'a', 1, 'alpha', pi/2)
% L1 = Revolute(std): theta=q, d=0, a=1, alpha=1.5708, offset=0
% Se puede determinar la transformada del Link para un angulo por ejemplo
% si q= 0.2 entonces la trnasformada se calcula con L1.A(0.2)
% Ahora se unen con BOT = SerialLink([L1 L2], 'name', 'BINGOBOT')
% BOT.n dira el numero de juntas
% Para graficar usamos dos angulos q1=0.1 y q2=0.2 (en radianes) y se busca
% la kinematica directa con bot.fkine([q1 q2]) y se plotea como 
% bot.plot([0.1 0.2])

% PARAMETROS

L1 = 3.0;
L2 = 13.5;
L3 = 5.0+10.0;
L4 = 9;

d = [L1, 0, 0, -L4];
a = [0, L2, L3, 0];
ALPHA = [pi/2, pi, -pi/2, pi];


% LINKS

LK1 = Link('d', d(1), 'a', a(1), 'alpha', ALPHA(1));
LK2 = Link('d', d(2), 'a', a(2), 'alpha', ALPHA(2));
LK3 = Link('d', d(3), 'a', a(3), 'alpha', ALPHA(3));
LK4 = Link('d', d(4), 'a', a(4), 'alpha', ALPHA(4));


% EL MODELO

BOT = SerialLink([LK1 LK2 LK3 LK4], 'name', 'BINGOBOT');

THETA = [pi/2, pi/4, pi/6, 0, pi/8, pi/2, pi/3, 0];

% figure("Name","ROJO")


BOT.plot([0 0 0 0]);

%% BOT INVERSA

syms Q1     Q2      Q3      Q4
syms N_X    S_X     A_X     X 
syms N_Y    S_Y     A_Y     Y 
syms N_Z    S_Z     A_Z     Z


assume(X,'Real')
assume(Y,'Real')
assume(Z,'Real')

% RAD = pi/180;

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
        0       ,   0           ,  -1   ,  -83/10;
        0       ,   0           ,   0   ,       1];


A04 = A01*A12*A23*A34;


Q4 = 0;

T1 = A01\T_SYMBOL == A12*A23*A34;
T2 = inv(A12)*inv(A01)*T_SYMBOL == A23*A34;


Q1_S = atan (Y/X);
% Q1_S = solve (T1(3,4), Q1);

ECU2 = subs(T2(1,4),Q1,Q1_S);

ECU3 = subs(T2(2,4),Q1,Q1_S);

ECU = [ECU2,ECU3];

[Q2_S,Q3_S] = solve(ECU, [Q2;Q3]);

Q_1 = simplify(Q1_S);
Q_2 = simplify(Q2_S(1,1));
Q_3 = simplify(Q3_S(1,1));


%% PARA VALIDAR LOS CALCULOS

% CUANDO X ES NEGATIVO VA POR DEBAJO SIN LA CONDICIONAL

X = 10.0;
Y = 10.0;
Z = 10.0;

    q1 = eval(Q_1);
    DQ1 = q1*180/pi;
    
    q2 = eval(Q_2);
    DQ2 = q2*180/pi;
    
    q3 = eval(Q_3);
    DQ3 = q3*180/pi;


BOT.plot([q1 q2 q3 0]);

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
    DQ1 = q1*180/pi
    
    q2 = eval(Q_2);
    DQ2 = q2*180/pi 
    
    q3 = eval(Q_3);
    DQ3 = q3*180/pi 

    X = X_TEMP;
    Y = Y_TEMP;

else
    
    q1 = eval(Q_1);
    DQ1 = q1*180/pi
    
    q2 = eval(Q_2);
    DQ2 = q2*180/pi 
    
    q3 = eval(Q_3);
    DQ3 = q3*180/pi 
    
end


BOT.plot([q1 q2 q3 0]);


% COMPROBANDO EL CALCULO DEL COMPORTAMIENTO DESEADO

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
ALPHA = [pi/2, 0, pi/2, pi];


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


%% CREAR UN MODELO CON X JOINS

% Un serial Link manipulator comprende una serie de Links
% Cada Link se define los 4 parametros de Denavit-Hartenberg
% Por ejemplo, si creamos un modelos sencillo con 2 Links
% Se crea el primer link con los valores: L1 = Link('d', 0, 'a', 1, 'alpha', pi/2)
% L1 = Revolute(std): theta=q, d=0, a=1, alpha=1.5708, offset=0
% Se puede determinar la transformada del Link para un angulo por ejemplo
% si q= 0.2 entonces la trnasformada se calcula con L1.A(0.2)
% Ahora se unen con BOT = SerialLink([L1 L2], 'name', 'BINGOBOT')
% BOT.n dira el numero de juntas
% Para graficar usamos dos angulos q1=0.1 y q2=0.2 (en radianes) y se busca
% la kinematica directa con bot.fkine([q1 q2]) y se plotea como 
% bot.plot([0.1 0.2])

% PARAMETROS

L1 = 3.0;
L2 = 13.5;
L3 = 5.0+10.0;
L4 = 9;

% THETA = [Q_1, Q_2, Q_3];
d = [L1, 0, 0, L4];
d2 = [L1, 0, 0, L4];
a = [0, L2, L3, 0];
ALPHA = [pi/2, 0, pi/2, 0];
ALPHA2 = [pi/2, 0, -pi/2, 0];


% LINKS
LK1 = Link('d', d(1), 'a', a(1), 'alpha', ALPHA(1));
LK2 = Link('d', d(2), 'a', a(2), 'alpha', ALPHA(2));
LK3 = Link('d', d(3), 'a', a(3), 'alpha', ALPHA(3));
LK4 = Link('d', d(4), 'a', a(4), 'alpha', ALPHA(4));

% LINKS

LK12 = Link('d', d2(1), 'a', a(1), 'alpha', ALPHA2(1));
LK22 = Link('d', d2(2), 'a', a(2), 'alpha', ALPHA2(2));
LK32 = Link('d', d2(3), 'a', a(3), 'alpha', ALPHA2(3));
LK42 = Link('d', d2(4), 'a', a(4), 'alpha', ALPHA2(4));



% EL MODELO

BOT = SerialLink([LK1 LK2 LK3 LK4], 'name', 'BINGOBOT');
BOT2 = SerialLink([LK1 LK2 LK3 LK4], 'name', 'BINGOBOT2', 'base', transl(-20, 20, 0));
BOT3 = SerialLink([LK12 LK22 LK32 LK42], 'name', 'BINGOBOT3', 'base', transl(20, -20, 0));

THETA = [pi/2, pi/4, pi/6, 0, pi/8, pi/2, pi/3, 0];

%figure("Name","ROJO")
BOT.plot([0 THETA(1) -pi/2 THETA(4)]);
%view([0 90 0])
hold on
%figure("Name","AZUL") 
BOT2.plot([0 THETA(1) -pi/2 THETA(4)]);
%view([0 90 0])

%figure("Name","GREEN")
BOT3.plot([0-pi 0 0-pi/2 THETA(4)]);
%view([0 90 0])

% THETA = [Q1+pi Q2 Q3-pi/2 Q4]

hold off



%% MATLAB Y ARDUINO




%% HACER DIRECT KINEMATICS

% COORDENADAS 0 DE LAS UNIONES
% fkine () para encontrar la trasformada al ultimo link
% cosa que tambien se puede usar con una secuencia de tiempo y trayectoria
    % GENERAR VECTOR DE TIEMPO
    % GENERAR TRAYECTORIA CON jtraj()
    % GENERAR LA TRNASFORMADA HOMOGENEA CON T = fkine()
    % SE SACA LA TRANSLACION CON p = T.transl

% mdl_puma560
% qz = [0 0 0 0 0]
% qr = [0 pi/2 [i/4 0 0]
% p560.fkine(qz)
% t = [0:.056:2];
% q = jtraj(qz, qr, t);
% about q
% T = p560.fkine(q);
% about T
% p = T.transl;


Theta_0 = [pi/2, pi/4, pi/6, 0];
Theta_1 = [pi/8, pi/2, pi/3, 0];

qz = [0 0 0 0];

t = [0:0.05:2];

qz = [Theta_0(1) Theta_0(2) Theta_0(3) Theta_0(4)];
qr = [Theta_1(1) Theta_1(2) Theta_1(3) Theta_1(4)];

q = jtraj(qz, qr,t);



T = BOT.fkine(q);

p = T.transl;



%% DIRECT KINEMATICS CON LA TRAJECTORIA

% BINGOBOT DIRECTA CALCULOS

Theta_0 = [pi/2, pi/4, pi/6, 0];
Theta_1 = [pi/8, pi/2, pi/3, 0];

qz = [0 0 0 0];

t = [0:0.05:2]; % T ES UN VECTOR CUYO VALOR NO IMPORTA SINO EL TAMAÑO

qz = [Theta_0(1) Theta_0(2) Theta_0(3) Theta_0(4)];
qr = [Theta_1(1) Theta_1(2) Theta_1(3) Theta_1(4)];

q = jtraj(qz, qr,t);

T = BOT.fkine(q);

p = T.transl;

BOT.plot(q);



%% HACER INVERSE KINEMATICS

% PRIMERO ELEGIR UNA POSICION CERO DEL ROBOT [EN TERMINO DE LOS ANGULOS]
% GENERAR LA TRANSFORMDA CON RESPECTO A ESO [T = ROB.kfine()]
% ELEGIR LA POSE POR DEFAULT [qi = ROB.ikine(T, 'pinv') |  qi = ROB.ikines6s(T)]
% ROB.fkine(qi)
% Definir la trasformada para una posicion Inicial
% Definir la trasformada para una posicion Final
% Definir una trayectoria cartesiana T = ctraj(T1, T2, 50);
% Aplicar cinematica inversa a la T trayectoria (q = ROB.ikine6s(T))
% ROB.plot(q) lo simula


%% BINGOBOT DIRECTA CALCULOS

% syms Q1 Q2 Q3 Q4
% syms Q_1 Q_2 Q_3 Q_4
  Q1 = 90;
  Q2 = 45;
  Q3 = 30;
  Q4 = 0;

 RAD = pi/180;
 Q_1 = Q1*RAD;
 Q_2 = Q2*RAD;
 Q_3 = Q3*RAD;
 Q_4 = Q4*RAD;

L1 = 3.0;
L2 = 13.5;
L3 = 5.0+10.0;
L4 = 9;

 THETA = [Q_1, Q_2, Q_3, Q_4];
% THETA = [Q1, Q2, Q3, Q4];
% THETA = [pi/2, pi/4, pi/6, 0];

d = [L1, 0, 0, L4];
a = [0, L2, L3, 0];
ALPHA = [pi/2, 0, pi/2, 0];

A = @(TH, AL, ax, dz) [cos(TH)        ,    -cos(AL)*sin(TH),       sin(AL)*sin(TH),    ax*(cos(TH));
                       sin(TH)        ,     cos(AL)*cos(TH),      -sin(AL)*cos(TH),    ax*(sin(TH));
                          0           ,     sin(AL)        ,       cos(AL)        ,        dz      ;
                          0           ,            0       ,               0      ,         1      ];


A01 = A(THETA(1), ALPHA(1), a(1), d(1));

A12 = A(THETA(2), ALPHA(2), a(2), d(2));

A23 = A(THETA(3), ALPHA(3), a(3), d(3));

A34 = A(THETA(4), ALPHA(4), a(4), d(4));

A02 = A01*A12;

A03 = A02*A23;

A04 = A03*A34;

X = A04(1, 4);
Y = A04(2, 4);
Z = A04(3, 4);


% X = L4*sin(Q_3)*cos(Q_1)*cos(Q_2) + L4*sin(Q_2)*cos(Q_1)*cos(Q_3) + cos(Q_1) * ( (L3*cos(Q_3)*cos(Q_2)) - (L3*sin(Q_3)*sin(Q_2)) + L2*cos(Q_2));
%  
% Y = L4*sin(Q_3)*sin(Q_1)*cos(Q_2) + L4*sin(Q_2)*sin(Q_1)*cos(Q_3) + L3*cos(Q_3)*cos(Q_2)*sin(Q_1) - L3*sin(Q_3)*sin(Q_2)*sin(Q_1) + L2*sin(Q_1)*cos(Q_2);
%  
% Z = L4*sin(Q_3)*sin(Q_2) - L4*cos(Q_3)*cos(Q_2) + L3*cos(Q_3)*sin(Q_2) + L3*cos(Q_2)*sin(Q_3) + L2*sin(Q_2) + L1;

%% BOT INVERSA

% clc
% clear

syms Q1     Q2      Q3      Q4
syms N_X    S_X     A_X     X 
syms N_Y    S_Y     A_Y     Y 
syms N_Z    S_Z     A_Z     Z


assume(X,'Real')
assume(Y,'Real')
assume(Z,'Real')

% RAD = pi/180;

L1 = 3.0;
L2 = 13.5;
L3 = 10.0+5.0;
L4 = 9;

T_SYMBOL=[  N_X     S_X     A_X     X
            N_Y     S_Y     A_Y     Y
            N_Z     S_Z     A_Z     Z
            0       0       0       1   ];

% d = [L1, 0, 0, L4];
% a = [0, L2, L3, 0];
% ALPHA = [pi/2, 0, pi/2, 0];
% THETA = [Q1 Q2 Q3 Q4];
% 
% A = @(TH, AL, ax, dz) [cos(TH)        ,    -cos(AL)*sin(TH),       sin(AL)*sin(TH),    ax*(cos(TH));
%                        sin(TH)        ,     cos(AL)*cos(TH),      -sin(AL)*cos(TH),    ax*(sin(TH));
%                           0           ,     sin(AL)        ,       cos(AL)        ,        dz      ;
%                           0           ,            0       ,               0      ,         1      ];
% 
% 
% A01 = A(THETA(1), ALPHA(1), a(1), d(1));
% A12 = A(THETA(2), ALPHA(2), a(2), d(2));
% A23 = A(THETA(3), ALPHA(3), a(3), d(3));
% A34 = A(THETA(4), ALPHA(4), a(4), d(4));


A01 = [ cos(Q1) ,   0   ,   sin(Q1)     , 0;
        sin(Q1) ,   0   ,   -cos(Q1)    , 0;
        0       ,   1   ,   0           , 3;
        0       ,   0   ,   0           , 1];
 

A12 = [ cos(Q2) ,  -sin(Q2)     , 0     , (27*cos(Q2))/2;
        sin(Q2) ,  cos(Q2)      , 0     , (27*sin(Q2))/2;
        0       ,        0      , 1     ,              0;
        0       ,        0      , 0     ,              1];

A23 = [ cos(Q3),    0,      sin(Q3),    15*cos(Q3);
        sin(Q3),    0,      -cos(Q3),   15*sin(Q3);
        0,          1,      0,          0;
        0,          0,      0,          1 ];

A34 = [ cos(Q4) ,   -sin(Q4)    , 0     ,     0;
        sin(Q4) ,   cos(Q4)     , 0     ,     0;
        0,          0           , 1     , 83/10;
        0,          0           , 0     ,     1];


A04 = A01*A12*A23*A34;


% X0 = simplify(A04(1,4));
% Y0 = simplify(A04(2,4));
% Z0 = simplify(A04(3,4));

% T = A1*A2*A3*A4  --->  T/A1 = A2*A3*A4

% Inverso  algo1\algo2 =  inv(algo1)*algo2

Q4 = 0;

T1 = A01\T_SYMBOL == A12*A23*A34;
% E1_Q1 = solve(T1(3,4), Q1);
% E_Q1 = atan(Y0/X0);
% Q1 = solve(T1(3,4), Q1);


T2 = inv(A12)*inv(A01)*T_SYMBOL == A23*A34;


Q1_S = atan (Y/X);

ECU2 = subs(T2(1,4),Q1,Q1_S);

ECU3 = subs(T2(2,4),Q1,Q1_S);

ECU = [ECU2,ECU3];

[Q2_S,Q3_S] = solve(ECU, [Q2;Q3]);


Q_1 = simplify(Q1_S);

Q_2 = simplify(Q2_S(1,1));
Q2_2 = simplify(Q2_S(2,1));

Q_3 = simplify(Q3_S(1,1)) - pi/2;
Q3_3 = simplify(Q3_S(1,1));
