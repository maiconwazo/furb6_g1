% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

function [train, tests] = normal(dadosTrain, rotuloTrain, dadosTeste)
  sizes = size(dadosTrain);
  train = ones(sizes(1), sizes(2));

  for index1 = 1 : length(dadosTrain)
    for index2 = 1 : length(dadosTrain(index1, :))
      X = dadosTrain(index1, index2);
      train(index1, index2) = ( (X - min(dadosTrain(index1, :))) / max(dadosTrain(index1, :)));
    end
  end

  sizes = size(dadosTeste);
  tests = ones(sizes(1), sizes(2));

    for index1 = 1 : length(dadosTeste)
    for index2 = 1 : length(dadosTeste(index1, :))
      X = dadosTeste(index1, index2);
      tests(index1, index2) = ( (X - min(dadosTeste(index1, :))) / max(dadosTeste(index1, :)));
    end
  end
end