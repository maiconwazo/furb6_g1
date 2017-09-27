function indexGene = verificaGenteReptido(c, index)
  indexGene = 0;
  for i = 1 : length(c)
    if (i == index)
      continue;
    end;
      
    for j = 1 : length(c)
      if (i != j)
        if (c(i) == c(j))
          indexGene = i;
          break;
        end;     
       end; 
    end
    
    if indexGene
      break;
  end
end