% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

function prev = meuKnn(dadosTrain, rotuloTrain, dadosTeste, k)
  distancia = ones(length(dadosTeste), length(dadosTrain));

  for indexTst = 1 : length(dadosTeste)
    for indexTr = 1 : length(dadosTrain)
      distancia(indexTst, indexTr) = dist(dadosTeste(indexTst, :), dadosTrain(indexTr, :));
    end

    [distanciaOrdenada ind] = sort(distancia(indexTst, :));

    prev(indexTst, 1) = mode(rotuloTrain(ind(1:k)));
  end

end