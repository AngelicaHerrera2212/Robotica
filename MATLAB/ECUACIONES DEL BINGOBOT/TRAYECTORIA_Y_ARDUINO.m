%% LIMPIEZA

close all
clear
clc
warning off

%% ----- % INICIALIZAR VALORES

% TIEMPO DE SIMULACION

tf = 10;
ts = 1;
t = 0:ts:tf;

% TAMAÑO DE LA MATRIZ DE TIEMPO

T_L = length(t);

% NUMERO DE MUESTRAS

N = length (t);

% CONSTANTE DE GIRO PARA LOS MOTORES QUE TRABAJAN A 270 Y NO 180

CONSTANTE_GIRO = 270/180;

% TAMAÑO DE LOS ESLAVONES

L1 = 3.0;
L2 = 13.5;
L3 = 5.0+10.0;
L4 = 8.3;

% POSICIONES ACTUAL Y SIGUIENTE EXPRESADAS EN FUNCION DE SUS ANGULOS

POSI = zeros(2,3);

% PARAMETROS DE D-H

d = [L1, 0, 0, -L4];
a = [0, L2, L3, 0];
ALPHA = [pi/2, pi, -pi/2, pi];

% DECLARACION DE VARIABLES PARA MATRIZ INVERSA

syms Q1     Q2      Q3      Q4
syms N_X    S_X     A_X     X 
syms N_Y    S_Y     A_Y     Y 
syms N_Z    S_Z     A_Z     Z

% MATRIZ DE VARIABLES SIMBOLICAS

T_SYMBOL=[  N_X     S_X     A_X     X
            N_Y     S_Y     A_Y     Y
            N_Z     S_Z     A_Z     Z
            0       0       0       1   ];

% MATRICES DE DENAVIT-HARTENBERG

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

% ASUNCIONES NECESARIAS PARA LA RESOLUCIÓN DE LAS ECUACIONES

assume(X,'Real')
assume(Y,'Real')
assume(Z,'Real')

% SIEMPRE ES CERO PORQUE NUESTRO GRIPPER NO GIRA

Q4 = 0;


%% CALCULO DE LAS ECUACIONES (PARA ENCONTRAR LOS ANGULOS)

% MATRIZ T (REPRESENTA LA TRANSFORMADA D-H SI CONOCIERAMOS LOS ANGULOS)

A04 = A01*A12*A23*A34;


% ALGEBRA LINEAL Y RESOLUCION DE LAS ECUACIONES

T1 = A01\T_SYMBOL == A12*A23*A34;
T2 = inv(A12)*inv(A01)*T_SYMBOL == A23*A34;

Q1_S = atan (Y/X);
% Q1_S = solve (T1(3,4));

ECU2 = subs(T2(1,4),Q1,Q1_S);

ECU3 = subs(T2(2,4),Q1,Q1_S);

ECU = [ECU2,ECU3];

[Q2_S,Q3_S] = solve(ECU, [Q2;Q3]);


% RESULTADO DEL CALCULO DE ECUACIONES

Q_1 = simplify(Q1_S);
Q_2 = simplify(Q2_S(1,1));
Q_3 = simplify(Q3_S(1,1));


% CALCULO DE LA RESPUESTA EN GRADOS PORQUE LOS SERVOS TRABAJAN EN GRADOS

Q1_DEGREE = Q_1*180/pi;
Q2_DEGREE = Q_2*180/pi;
Q3_DEGREE = Q_3*180/pi; 


% MASCARA PARA EL COMPORTAMEINTO QUE DEBE ENVIARSE AL ARDUINO
% REAL ARDUINO DEGREE #

R_A_1 = (Q1_DEGREE) / CONSTANTE_GIRO;
R_A_2 = Q2_DEGREE;
R_A_3 = (Q3_DEGREE + 180) / CONSTANTE_GIRO;


%% ---- % CREAR UN MODELO CON X JOINS

% LINKS DEL MODELO

LK1 = Link('d', d(1), 'a', a(1), 'alpha', ALPHA(1));
LK2 = Link('d', d(2), 'a', a(2), 'alpha', ALPHA(2));
LK3 = Link('d', d(3), 'a', a(3), 'alpha', ALPHA(3));
LK4 = Link('d', d(4), 'a', a(4), 'alpha', ALPHA(4));

% CREAR EL MODELO

BOT = SerialLink([LK1 LK2 LK3 LK4], 'name', 'BINGOBOT');

% GRAFICAR EL MODELO EN SU POSICIÓN 0

 BOT.plot([0 0 0 0]);


%% PARA QUE EL ROBOT TRABAJE CON EL CODO HACIA ARRIBA SIEMPRE

% POSICION INICIAL
% X = L2 + L3;
% Y = 0;
% Z = 0;

% POSICION FINAL
% X = 19.0;
% Y = -20.0;
% Z = 5.0;

% POSICION INICIAL Y FINAL
X_FI = [7 19];
Y_FI = [10 -10];
Z_FI = [8 5];

% CALCULO DE LOS ANGULOS
for j = 1:2
    if (X_FI(j) > 0)
        
        X = -X_FI(j);
        Y = -Y_FI(j);
        Z =  Z_FI(j);

        TQ1(j,1) = eval(R_A_1) + 180;
        TQ2(j,1) = eval(R_A_2);
        TQ3(j,1) = eval(R_A_3);
    
    else
        
        X = X_FI(j);
        Y = Y_FI(j);
        Z = Z_FI(j);

        TQ1(j,1) = eval(R_A_1);
        TQ2(j,1) = eval(R_A_2);
        TQ3(j,1) = eval(R_A_3);
        
    end
end


% TRAYECTORIA 

T1_TR = tpoly(TQ1(1), TQ1(2), t);
T2_TR = tpoly(TQ2(1), TQ2(2), t);
T3_TR = tpoly(TQ3(1), TQ3(2), t);


BOT.plot([T1_TR T3_TR T3_TR zeros(T_L,1)]);
pause(1);

%BOT.plot([zeros(T_L,1) T2_TR T3_TR zeros(T_L,1)]);


%% ----- % ENVIANDO LA TRAYECTORIA AL ARDUINO

% OPEN SERIAL PORT

P = serialport('COM6',9600);

% NUMEROS PARA ENVIAR
Q1_GO = T1_TR;
Q2_GO = T2_TR;
Q3_GO = T3_TR;

% NUMEROS PARA RECIBIR
Q1_IN = zeros(1,T_L);
Q2_IN = zeros(1,T_L);
Q3_IN = zeros(1,T_L);

% TIEMPO QUE SE DEMORA EN RECIBIR LOS DATOS
TIME = zeros(1,T_L);

% ABRIR COMUNICACION
fopen(P);

% PAUSAR 3 SEGUNDOS
pause (3);

% AVISO
disp('PRENDIO, PRENDIO, PRENDIO, PRENDIO');

% ENVIAR DATOS
for k = 1:T_L
    tic     % EMPEZAR EL CONTEO DEL TIEMPO
    
    % MENSAJE A ENVIAR (NUM2STR DE NUMERO A CADENA DE CARACTERES)
    SEND = [num2str(Q1_GO(k)) ',' num2str(Q2_GO(k)) ',' num2str(Q3_GO(k)) ];
    
    % ENVIAR EL MENSAJE
    fprintf(P,'%s\n',SEND,'sync');

    % RECIBIR MENSAJES
    Q1_IN (k) = readline(P);
    Q2_IN (k) = readline(P);
    Q3_IN (k) = readline(P);

    % GUARDAR TIEMPO
    TIME(k) = toc;

end

disp('FIN...');

fclose (P);
delete (P);
