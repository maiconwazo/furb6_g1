clear all;
clc;
close all;

sala = geraAmbiente() 
mostraAmbiente(sala) 
posicaoAspirador(2, 2)
hold off;

percepcao.x = 2
percepcao.y = 2
percepcao.acao_anterior = 4

while 1
  percepcao.sujo = sala(percepcao.x, percepcao.y)
  acao = agenteReativoSimples(percepcao)
  
  if acao != 5
    percepcao.acao_anterior = acao
  end
  
  [sala, percepcao.x, percepcao.y] = atualizaAmbiente(sala, acao, percepcao.x, percepcao.y)     
  mostraAmbiente(sala)
  hold on
  posicaoAspirador(percepcao.x,percepcao.y)
  hold off
   
  pause(0.3)   
end

