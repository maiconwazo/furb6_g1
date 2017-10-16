% Alunos:
% - Guilherme Bacca
% - Maicon Santos
% - Mateus Clemer
% - Matheus Klauberg
% - Tamire Kistner

function R = correlacao(x, y)
  meanX = mean(x);
  meanY = mean(y);

  newX = x - meanX;
  newY = y - meanY;

  sXY = newX .* newY;

  top = sum(sXY);

  somaX = sum(newX .* newX);
  somaY = sum(newY .* newY);  

  bottom = sqrt( somaX .* somaY );

  R = top / bottom;
end