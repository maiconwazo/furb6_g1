function objObtido = checkObj(sala)

objObtido = 1;
for (i = [1,2,3,4,5])
  for (j = [1,2,3,4,5])
    if (sala(i,j) == 1)
      objObtido = 0
      break
    endif
  endfor
     if (objObtido == 0)
        break
     endif
endfor

end