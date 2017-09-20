function indexGene = verificaGenteReptido(c, index)
  indexGene = 0;
  for i = 1 : length(c)
    if (i == index)
      continue;
    endif
      
    for j = i + 1 : length(c)
      if (c(i) == c(j))
        indexGene = i;
        break;
      endif;      
    end
  end
end