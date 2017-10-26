% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

close all; clc; clear;

load("grupoDados2");

[trainNorm, testNorm] = normal(grupoTrain, trainRots, grupoTest, 1);

k = 1;
rotuloPrevisto = meuKnn(trainNorm, trainRots, testNorm, k);

estaCorreto = rotuloPrevisto == testRots;
numCorreto = sum(estaCorreto);
totalNum = length(testRots);
precisao = numCorreto / totalNum;

disp("Q2.1: Aplique seu kNN a este problema. Qual é a sua precisão de classificação?");
disp(strcat("R: A precisao é:", num2str(precisao)))

disp("Q2.2: A precisão pode ser igual a 98pct com o kNN. Descubra por que o resultado atual é muito menor. Ajuste o conjunto de dados ou k de tal forma que a precisão se torne 98pct e explique o que você fez e por quê.");

k = 5;
rotuloPrevisto = meuKnn(trainNorm, trainRots, testNorm, k);

estaCorreto = rotuloPrevisto == testRots;
numCorreto = sum(estaCorreto);
totalNum = length(testRots);
precisao = numCorreto / totalNum;

disp("R: O resultado é nuito menor pois os dados estão normalizados.");

