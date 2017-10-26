% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

close all; clc; clear;

load("grupoDados1");

k = 1;
rotuloPrevisto = meuKnn(grupoTrain, trainRots, grupoTest, k);

estaCorreto = rotuloPrevisto == testRots;
numCorreto = sum(estaCorreto);
totalNum = length(testRots);
precisao = numCorreto / totalNum;

% Esperado 0.96
precisaoString = num2str(precisao);
disp(strcat("Para K = 1, precisao = ", precisaoString));

k = 10;
rotuloPrevisto = meuKnn(grupoTrain, trainRots, grupoTest, k);

estaCorreto = rotuloPrevisto == testRots;
numCorreto = sum(estaCorreto);
totalNum = length(testRots);
precisao = numCorreto / totalNum;

% Esperado 0.94
precisaoString = num2str(precisao);
disp(strcat("Para K = 10, precisao = ", precisaoString));

% Grupo de dados 1 (Q1)

printf("Q1.1. Qual é a precisao maxima que voce consegue da classificacao?\n")
k = 3;
rotuloPrevisto = meuKnn(grupoTrain, trainRots, grupoTest, k);

estaCorreto = rotuloPrevisto == testRots;
numCorreto = sum(estaCorreto);
totalNum = length(testRots);
precisao = numCorreto / totalNum;

disp("R: A Precisao máxima é 0.98, com K = 3");

disp("Q1.2. É necessario ter todas as caracteristicas (atributos) para obter a precisao maxima para esta classificacao?");
disp("R: Sim. Devido a quantidade de atributos que a classificacao, pois com menos atributos o resultado poderia ser diferente devido a elementos com novas distancias.");



