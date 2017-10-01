close all; clc; clear;

global iag x y
%% Configuracao Inicial
npar=20; % numero das variaveis para serem otimizadas (genes)
Nt=npar; % numero de colunas da matriz de populacao

x=rand(1,npar);
y=rand(1,npar); % cidades em (cidadeX, cidadeY)

tamPop = 20;
selecao=0.5; % fracao da populacao a ser mantida
manter=floor(selecao*tamPop); % numero de membros da populacao que sobrevivem
M=ceil((tamPop-manter)/2); % numero de cruzamentos

probab=1; %probabilidade
for ii=2:manter
    probab=[probab ii*ones(1,ii)];
end
Nprobab=length(probab);
probab=manter-probab+1; 

for i = 1:tamPop
  pais(i,:) = randperm(npar); % dicionario com os cromossomos (essa lista nao � ordenada, serve s� de dicionario)
  
  a.codigo = i;  % a lista populacao � ordenada por aptidao e armazena o codigo dos cromossomos (posi��o da matriz "pais"
  a.aptidao = 0;
  populacao(i,:) = a;
end


iag=0; % contador para iniciar a geracao
% calcular o custo da populacao utilizando a funcao de aptidao
maxit=10000;
while iag<maxit
    for i = 1:tamPop
        populacao(i,:).aptidao = cvfun(pais(populacao(i,:).codigo,:)); % calcula aptidao
    end

    populacao = bubble(populacao);  %ordena por aptidao menor
    
    iag=iag+1; % incrementa o contador de geracoes
    
    % Escolha do Pai1 e Pa2 que s�o escolhidos aleatoriamente do vetor
    % probab
    escolha1=ceil(Nprobab*rand(1,M)); % escolher aleatoriamente na roleta os indiv�duos
    escolha2=ceil(Nprobab*rand(1,M)); % escolher aleatoriamente na roleta os indiv�duos
    indPai1=probab(escolha1); % selecionar os indices escolhidos na roleta para o pai 1
    indPai2=probab(escolha2); % selecionar os indices escolhidos na roleta para o pai 2
    
    novaPos = 11;
    for ic=1:M        
        pai1 = pais(populacao(indPai1(ic),:).codigo,:);
        pai2 = pais(populacao(indPai2(ic),:).codigo,:);
        
        pais(populacao(novaPos).codigo,:) = pai1; % copia o pai um para depois fazer as altera��es
        pais(populacao(novaPos + 1).codigo,:) = pai2; % copia o pai dois para depois fazer as altera��es  
        
        repetido = randi(length(pai1));
        while repetido != 0                  % fica nesse loop ate n�o ter mais nenhum repetido
            temp = pais(populacao(novaPos).codigo,repetido);
            pais(populacao(novaPos).codigo,repetido) = pais(populacao(novaPos + 1).codigo,repetido);
            pais(populacao(novaPos + 1).codigo,repetido) = temp;  

            repetido = verificaGenteReptido(pais(populacao(novaPos).codigo,:), repetido);        % retorna posi��o do gene repetido  
        end
        
        mutacao1 = randi(20);
        mutacao2 = randi(20);
        
        temp_mut = pais(populacao(novaPos).codigo,mutacao1);
        pais(populacao(novaPos).codigo,mutacao1) = pais(populacao(novaPos).codigo,mutacao2);
        pais(populacao(novaPos).codigo,mutacao2) = temp_mut;
        % haviamos feito muta��o nos dois membros, mas retiramos, seguindo a parte do enunciado que diz:
        % "O operador de muta��o escolhe aleatoriamente dois n�meros inteiros em UM cromossomo da nova gera��o e os troca"
        
      %  temp_mut = pais(populacao(novaPos + 1).codigo,mutacao1);
      %  pais(populacao(novaPos + 1).codigo,mutacao1) = pais(populacao(novaPos + 1).codigo,mutacao2);
      %  pais(populacao(novaPos + 1).codigo,mutacao2) =temp_mut;
        
        novaPos = novaPos + 2;
    end    
end

populacao = bubble(populacao);
  
disp("Tamanho da populacao: ");
disp(length(populacao));  
disp("Taxa de mutacao: ");
disp("0,05");  
disp("Numero de cidades: ");
disp(npar);  
disp("Melhor custo: ");
disp(populacao(1).aptidao);
disp("Melhor solucao: ")
disp(pais(populacao(1).codigo,:));

