% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

close all; clc; clear;

v1 = [10; 8; 13; 9; 11; 14; 6; 4; 12; 7; 5];
v2 = [8.04; 6.95; 7.58; 8.81; 8.33; 9.96; 7.24; 4.26; 10.84; 4.82; 5.68];

v3 = [10;8;13;9;11;14;6;4;12;7;5];
v4 = [9.14;8.14;8.47;8.77;9.26;8.10;6.13;3.10;9.13;7.26;4.74];

v5 = [8;8;8;8;8;8;8;8;8;8;19];
v6 = [6.58;5.76;7.71;8.84;8.47;7.04;5.25;5.56;7.91;6.89;12.50];

R1 = correlacao(v1, v2);

R1 = correlacao(v3, v4);

R1 = correlacao(v5, v6);

[b0, b1] = regressao(v1, v2);

[b0, b1] = regressao(v3, v4);

[b0, b1] = regressao(v5, v6);


scatter(v1,v2);
title(num2str(R1),num2str());
