function s = bubble(v)
  itemCount = length(v);
  do
    hasChanged = false;
    itemCount--;
    for i = 1:itemCount
      if ( v(i).aptidao > v(i+1).aptidao )
        v([i,i+1]) = v([i+1,i]);
        hasChanged = true;
      endif
    endfor
  until(hasChanged == false)
  s = v;
endfunction