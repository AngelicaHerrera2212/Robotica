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
Q1_GO = [5.0 2.0 7.0 8.0 5.0];
Q2_GO = [6.0 7.0 8.0 9.0 10.0];
Q3_GO = [11.0 12.0 13.0 14.0 15.0];

% NUMEROS PARA RECIBIR
Q1_IN = zeros(1,5);
Q2_IN = zeros(1,5);
Q3_IN = zeros(1,5);

% TIEMPO QUE SE DEMORA EN RECIBIR LOS DATOS
TIME = zeros(1,5);

% ABRIR COMUNICACION
fopen(P);

% PAUSAR 3 SEGUNDOS
pause (3);

% AVISO
disp('PRENDIO, PRENDIO, PRENDIO, PRENDIO');

% ENVIAR DATOS
for k = 1:5
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
