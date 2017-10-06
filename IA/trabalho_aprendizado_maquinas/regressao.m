function [y, b0, b1] = regressao(x, y)
  meanX = mean(x);
  meanY = mean(y);

  newX = x - meanX;
  newY = y - meanY;

  sXY = newX .* newY;

  top = sum(sXY);
  
  doubleX = newX .* newX;

  bottom = sum(doubleX);

  b1 = top / bottom;
  b0 = meanY - (b1 * meanX);
  y =  b0 + (b1 * x);
end