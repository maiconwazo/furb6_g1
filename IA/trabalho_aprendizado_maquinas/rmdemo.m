% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

% a) Baixe os dados do arquivo data.mat (para isso, você pode usar a função load).
% A primeira coluna é o tamanho da casa, a segunda coluna é o número de quartos, e a terceira coluna é o preço da casa.
data = load("data").data;

precos = data(:, 3);
quartos = data(:, 2);
tamanhos = data(:, 1);

% b) Gere uma matriz X para as variáveis independentes (que são o tamanho da casa e o número de quartos) e o vetor y da variável dependente (que é o preço).
matriz = [ones(rows(data), 1), tamanhos, quartos];

% c) Verifique a correlação e a regressão para Tamanho da casa e Preço e Número de quartos e Preço.
regm = regmultipla(matriz, precos)

y = matriz * regm;

correlacaoTamanhoxPreco = correlacao(tamanhos, precos);
correlacaoQuartosxPreco = correlacao(quartos, precos);

regressaoTamanhoxPreco = regressao(tamanhos, precos)
regressaooQuartosxPreco = regressao(quartos, precos)

% d) Faça o gráfico (diagrama) de dispersão dos dados. Neste caso iremos trabalhar com o espaço 3D
% (verifique a função scatter3).
scatter3(tamanhos, quartos, precos);
hold on

% e) Trace a linha da regressão no Gráfico de Dispersão (verifique a função plot3). Você pode girar este
% gráfico utilizando a seta de rotação.
plot3(tamanhos, quartos, y);

% f) Mostre na figura os coeficientes de correlação entre Tamanho da casa e Preço e Número de quartos e
% Preço.
title(strcat(strcat("Tamanho x Preco: ", num2str(correlacaoTamanhoxPreco)),strcat("      Quartos x Preco: ", num2str(correlacaoQuartosxPreco))));

% g) Calcule o preço de uma casa que tem tamanho de 1650 e 3 quartos. O resultado deve ser igual a
% 293081.
tamCasa = 1650;
qtQuartos = 3;

matriz2 = [1, 1650, 3];
y = matriz2 * regm;

% esperado = [293081];