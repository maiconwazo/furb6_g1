function acao = agenteObjetivo(percepcao, ObjObtido)

objetivo = checkObj(ObjObtido)
if objetivo == 1
  acao = 6
else
  acao = agenteReativoSimples(percepcao)
end


end