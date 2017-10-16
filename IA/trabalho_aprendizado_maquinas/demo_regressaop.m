% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

% A) Baixe o arquivo data_preg.mat.
%    A primeira coluna representa os valores de x e a segunda coluna representa os valores de y.
data = load("data_preg").data;

x = data(:, 1);
y = data(:, 2);

% B) Faça o Gráfico de dispersão dos dados.
scatter(x, y);
hold on;  

% C) Use a função polyfit para gerar a linha de regressão para N = 1 e trace-o no gráfico de dispersão na cor vermelha (plot (x, y, 'r')).
%    (observe que nesta função a numeração coeficiente é invertida! β0=βN , β1=βN−1 , β2=βN−2 , ...βN=β0)

N = 1;
result1 = polyfit(x, y, N);
y1 = result1(:, 2) + (result1(:, 1) * x);
plot(x, y1, 'r');
hold on;

% D) Trace a linha de regressão para N = 2 no gráfico na cor verde.

N = 2;
result2 = polyfit(x, y, 2);
y2 = result2(:, 3) + (result2(:, 2) * x) + (result2(:, 1) * (x .^ 2));
plot(x, y2, 'g');
hold on;

% e) Trace a linha de regressão para N = 3 no gráfico na cor preta.

N = 3;
result3 = polyfit(x, y, N);
y3 = result3(:, 4) + (result3(:, 3) * x) + (result3(:, 2) * (x .^ 2)) + (result3(:, 1) * (x .^ 3));
plot(x, y3, 'k');
hold on;

% f) Trace a linha de regressão para N = 8 no gráfico na cor amarela.

N = 8;
result8 = polyfit(x, y, N);
y8 = result8(:, 9) + (result8(:, 8) * x) + (result8(:, 7) * (x .^ 2)) + (result8(:, 6) * (x .^ 3)) + (result8(:, 5) * (x .^ 4)) + (result8(:, 4) * (x .^ 5)) + (result8(:, 3) * (x .^ 6)) + (result8(:, 2) * (x .^ 7)) + (result8(:, 1) * (x .^ 8));
plot(x, y8, 'y');
hold on;

% g) Calcule o Erro Quadrático Médio (EQM) para cada linha de regressão. Qual é o mais preciso? 

% O mais preciso é R8 (Linha amarela);

res1 = (y - y1) .* (y - y1);
R1 = sum(res1) / size(y, 1);
% R1 = 0.26593

res2 = (y - y2) .* (y - y2);
R2 = sum(res2) / size(y, 1);
% R2 = 0.13853

res3 = (y - y3) .* (y - y3);
R3 = sum(res3) / size(y, 1);
% R3 = 0.078697

res8 = (y - y8) .* (y - y8);
R8 = sum(res8) / size(y, 1);
% R8 = 0.058710

% h) Para evitar o overfitting, divida os dados aleatoriamente em Dados de Treinamento e Dados de Teste. Use os primeiros 10% dos dados como conjunto de teste, e o resto como de treinamento.

testes = [x(1:ceil(length(x) * 0.1)), y(1:ceil(length(y) * 0.1))];

reverseData = flipud(data);
reverseX = reverseData(:, 1);
reverseY = reverseData(:, 2);

treinamento = flipud([reverseX(1:floor(length(reverseX) * 0.9)), reverseY(1:floor(length(reverseY) * 0.9))]);

% i) Repita os passos de c - f, mas agora use apenas os dados de treinamento para ajustar a linha de regressão.

treinamentoX = treinamento(:, 1);
treinamentoY = treinamento(:, 2);

testeX = testes(:, 1);
testeY = testes(:, 2);

  % C) Use a função polyfit para gerar a linha de regressão para N = 1 e trace-o no gráfico de dispersão na cor vermelha (plot (x, y, 'r')).
  %    (observe que nesta função a numeração coeficiente é invertida! β0=βN , β1=βN−1 , β2=βN−2 , ...βN=β0)

  N = 1;
  result1Treinamento = polyfit(treinamentoX, treinamentoY, N);
  result1Teste = polyfit(testeX, testeY, N);
  y1Treinamento = result1Treinamento(:, 2) + (result1Treinamento(:, 1) * treinamentoX);
  y1Teste = result1Teste(:, 2) + (result1Teste(:, 1) * testeX);
  plot(treinamentoX, y1Treinamento, 'r');
  hold on;

  % D) Trace a linha de regressão para N = 2 no gráfico na cor verde.

  N = 2;
  result2Treinamento = polyfit(treinamentoX, treinamentoY, 2);
  result2Teste = polyfit(testeX, testeY, N);
  y2Treinamento = result2Treinamento(:, 3) + (result2Treinamento(:, 2) * treinamentoX) + (result2Treinamento(:, 1) * (treinamentoX .^ 2));
  y2Teste = result2Teste(:, 3) + (result2Teste(:, 2) * testeX) + (result2Teste(:, 1) * (testeX .^ 2));
  plot(treinamentoX, y2Treinamento, 'g');
  hold on;
  
  % e) Trace a linha de regressão para N = 3 no gráfico na cor preta.

  N = 3;
  result3Treinamento = polyfit(treinamentoX, treinamentoY, N);
  result3Teste = polyfit(testeX, testeY, N);
  y3Treinamento = result3Treinamento(:, 4) + (result3Treinamento(:, 3) * treinamentoX) + (result3Treinamento(:, 2) * (treinamentoX .^ 2)) + (result3Treinamento(:, 1) * (treinamentoX .^ 3));
  y3Teste = result3Teste(:, 4) + (result3Teste(:, 3) * testeX) + (result3Teste(:, 2) * (testeX .^ 2)) + (result3Teste(:, 1) * (testeX .^ 3));
  plot(treinamentoX, y3Treinamento, 'k');
  hold on;

  % f) Trace a linha de regressão para N = 8 no gráfico na cor amarela.

  N = 8;
  result8Treinamento = polyfit(treinamentoX, treinamentoY, N);
  result8Teste = polyfit(testeX, testeY, N);
  y8Treinamento = result8Treinamento(:, 9) + (result8Treinamento(:, 8) * treinamentoX) + (result8Treinamento(:, 7) * (treinamentoX .^ 2)) + (result8Treinamento(:, 6) * (treinamentoX .^ 3)) + (result8Treinamento(:, 5) * (treinamentoX .^ 4)) + (result8Treinamento(:, 4) * (treinamentoX .^ 5)) + (result8Treinamento(:, 3) * (treinamentoX .^ 6)) + (result8Treinamento(:, 2) * (treinamentoX .^ 7)) + (result8Treinamento(:, 1) * (treinamentoX .^ 8));
  y8Teste = result8Teste(:, 9) + (result8Teste(:, 8) * testeX) + (result8Teste(:, 7) * (testeX .^ 2)) + (result8Teste(:, 6) * (testeX .^ 3)) + (result8Teste(:, 5) * (testeX .^ 4)) + (result8Teste(:, 4) * (testeX .^ 5)) + (result8Teste(:, 3) * (testeX .^ 6)) + (result8Teste(:, 2) * (testeX .^ 7)) + (result8Teste(:, 1) * (testeX .^ 8));
  plot(treinamentoX, y8Treinamento, 'y');
  hold on;

% j) Repita o passo g, mas agora utilize somente os dados de Teste para calcular o erro.

res1 = (treinamentoY - y1Treinamento) .* (treinamentoY - y1Treinamento);
R1Treinamento = sum(res1) / size(treinamentoY, 1)
res1 = (testeY - y1Teste) .* (testeY - y1Teste);
R1Teste = sum(res1) / size(testeY, 1)

res2 = (treinamentoY - y2Treinamento) .* (treinamentoY - y2Treinamento);
R2Treinamento = sum(res2) / size(treinamentoY, 1)
res2 = (testeY - y2Teste) .* (testeY - y2Teste);
R2Teste = sum(res2) / size(testeY, 1)

res3 = (treinamentoY - y1Treinamento) .* (treinamentoY - y1Treinamento);
R3Treinamento = sum(res3) / size(treinamentoY, 1)
res3 = (testeY - y1Teste) .* (testeY - y1Teste);
R3Teste = sum(res3) / size(testeY, 1)

res8 = (treinamentoY - y8Treinamento) .* (treinamentoY - y8Treinamento);
R8Teinamento = sum(res8) / size(treinamentoY, 1)
res8 = (testeY - y8Teste) .* (testeY - y8Teste);
R8Teste = sum(res8) / size(testeY, 1)

% k) Que método é o mais preciso neste caso?
% O mais preciso é R8 (Linha amarela);


