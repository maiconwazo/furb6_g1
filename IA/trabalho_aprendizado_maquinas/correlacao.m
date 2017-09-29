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

% Soma ((x – média de x) * (y – média de y))
% - Dividido -
% Raiz quadrada ( (soma de (x – média de x)2 ) * (soma de (y – média de y)2 ))