function b = regmultipla(X, y)
  Xtranspose = ctranspose(X);

  transposeResult = (Xtranspose * X);

  powResult = transposeResult ^ -1

  temp = powResult * Xtranspose

  b = temp * y;
end