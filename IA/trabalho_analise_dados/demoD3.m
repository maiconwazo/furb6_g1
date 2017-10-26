% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

close all; clc; clear;

load("grupoDados3");

k = 1;
rotuloPrevisto = meuKnn(grupoTrain, trainRots, grupoTest, k);

estaCorreto = rotuloPrevisto == testRots;
numCorreto = sum(estaCorreto);
totalNum = length(testRots);
precisao = numCorreto / totalNum;

precisaoString = num2str(precisao);
disp("Q3.1: Aplique o kNN ao problema usando k = 1. Qual é a precisão na classificação?");

disp(strcat("R: ", precisaoString));

disp("Q3.2: A precisão pode ser igual a 92pct com o kNN. Descubra por que o resultado atual é muito menor. Ajuste o conjunto de dados ou k de tal forma que a precisão se torne 92pct e explique o que você fez e por quê.");

k = 7;
rotuloPrevisto = meuKnn(grupoTrain, trainRots, grupoTest, k);

estaCorreto = rotuloPrevisto == testRots;
numCorreto = sum(estaCorreto);
totalNum = length(testRots);
precisao = numCorreto / totalNum;

precisaoString = num2str(precisao);

disp("R: O resultado atual é menor pois o número de vizinhos considerados pelo algoritmo é 1 e devido a isso, é obtida uma precisao menor devido a menor quantidade de vizinhos consultados.")

disp("Para obter uma precisao de 92pct, foi modificado o valor de k para 7, obtendo uma precisao de 0.92.");

disp("Para chegar ao valor 7, foi utilizado o método da tentiva-e-erro, utilizando sempre de valores impares, até chegar ao resultado esperado.");