close all; clc; clear;

load("grupoDados1")

k = 11;
rotuloPrevisto = meuKnn(grupoTrain, trainRots, grupoTest, k);

estaCorreto = rotuloPrevisto == testRots;
numCorreto = sum(estaCorreto);
totalNum = length(testRots);

% % Esperado 0.96
precisao = numCorreto / totalNum

% k = 10;
% rotuloPrevisto = meuKnn(grupoTrain, trainRots, grupoTest, k);

% estaCorreto = rotuloPrevisto == testRots;
% numCorreto = sum(estaCorreto);
% totalNum = length(testRots);

% % Esperado 0.94
% precisao = numCorreto / totalNum