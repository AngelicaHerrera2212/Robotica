close all
clear
clc
warning off


% TIEMPO DE SIMULACION
tf = 10;
ts = 0.1;
t = 0:ts:tf;

% NUMERO DE MUESTRAS
N = length (t);

% OPEN SERIAL PORT
P = serialport('COM6',9600);

% NUMEROS PARA ENVIAR
X = [17.0 18.0];
Y = [-20.0 -22.0];
Z = [10.0 11.0];


% X = 17.0;
% Y = -20.0;
% Z = 5.0;

% PUNTO CERO
% 
% X = -20
% Y = 0
% Z = 24


% CUADRO PIEZA 1
% 2,12,-25,3

% CUADRO PIEZA 2
% 2,16,-24,6
% 2,15.5,-22.5,3

% CUADRO PIEZA 3
% 2,17.5,-21,3


% CUADRO PIEZA 4
% 2,20,-19,3 

% CUADRO PIEZA 5
% 2,21,-18,4

% VASO
% 2,19,-2,16

% PUNTO CERO EN LA TOMBOLA
% -2.5312,-19.2263, 18.0996, 2

% NUMEROS PARA RECIBIR
K_IN = zeros(1,2);
X_IN = zeros(1,2);
Y_IN = zeros(1,2);
Z_IN = zeros(1,2);

% TIEMPO QUE SE DEMORA EN RECIBIR LOS DATOS
TIME = zeros(1,2);

% ABRIR COMUNICACION
fopen(P);

% PAUSAR 3 SEGUNDOS
pause (3);

% AVISO
disp('PRENDIO, PRENDIO, PRENDIO, PRENDIO');

% ENVIAR DATOS
for k = 1:2
    tic     % EMPEZAR EL CONTEO DEL TIEMPO
    
    % MENSAJE A ENVIAR (NUM2STR DE NUMERO A CADENA DE CARACTERES)
    SEND = [num2str(k) ',' num2str(X(k)) ',' num2str(Y(k)) ',' num2str(Z(k)) ];
    
    % ENVIAR EL MENSAJE
    fprintf(P,'%s\n',SEND,'sync');

    % RECIBIR MENSAJES
    
    K_IN (k) = readline(P);
    X_IN (k) = readline(P);
    Y_IN (k) = readline(P);
    Z_IN (k) = readline(P);

    % GUARDAR TIEMPO
    TIME(k) = toc;   

end

disp('FIN...');

fclose (P);
delete (P);
