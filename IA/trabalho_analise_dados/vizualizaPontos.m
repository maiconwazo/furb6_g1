% TODO
function visualizaPontos(dados, rotulos, d1, d2)
  figure; clf; hold on

  plot(dados(rotulos == 1, d1), dados(rotulos == 1, d2), 'r.');
  plot(dados(rotulos == 2, d1), dados(rotulos == 2, d2), 'b+');
  plot(dados(rotulos == 3, d1), dados(rotulos == 3, d2), 'go');
end