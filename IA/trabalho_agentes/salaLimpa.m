function estaLimpa = salaLimpa(sala)

estaLimpa = 1;
for (i = [1,2,3,4,5])
  for (j = [1,2,3,4,5])
    if (sala(i,j) == 2)
      estaLimpa = 0
      break
    endif
  endfor
     if (estaLimpa == 0)
        break
     endif
 endfor

end

