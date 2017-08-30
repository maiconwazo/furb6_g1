% Fun��o de agente reativo simples para o mundo 4 x 4 do aspirador de p� autom�tico
% que garante limpar toda a sala, independentemente da posi��o inicial. 
% A fun��o deve retornar um das 5 poss�veis a��es a��es do agente= {'acima', 'abaixo', 'esquerda', 'direita', 'aspirar'}
% A vari�vel "percepcao" dentro dos par�nteses � a entrada da fun��o.
function acao = agenteReativoSimples(percepcao)
acao = percepcao.acao_anterior

if percepcao.sujo == 1
  acao = 5
else    
  if acao == 3
    if (percepcao.x == 2) && (percepcao.y == 2)
      acao = 2
    end
  elseif (percepcao.x == 2) && (percepcao.y == 5)
    acao = 3
  elseif (percepcao.x == 5) || (percepcao.x == 2)
      if (percepcao.acao_anterior != 4)
        acao = 4
      elseif (percepcao.x == 5)
        acao = 1
      elseif (percepcao.x == 2)
        acao = 2
      end
end


% Para cada posi��o definir as a��es dispon�veis (funcaoMapear)
% a��es = {'acima', 'abaixo', 'esquerda', 'direita', 'aspirar'}
%            1         2          3           4          5

end