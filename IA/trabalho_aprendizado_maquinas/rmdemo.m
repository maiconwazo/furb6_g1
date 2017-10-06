data = load("data").data;

precos = data(:, 3);
quartos = data(:, 2);
tamanhos = data(:, 1);

matriz = [ones(rows(data), 1), tamanhos, quartos];

regm = regmultipla(matriz, precos)

y = matriz * regm;

correlacaoTamanhoxPreco = correlacao(tamanhos, precos);
correlacaoQuartosxPreco = correlacao(quartos, precos);

regressaoTamanhoxPreco = regressao(tamanhos, precos);
regressaooQuartosxPreco = regressao(quartos, precos);

scatter3(tamanhos, quartos, precos);
hold on
plot3(tamanhos, quartos, y);
