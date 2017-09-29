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

iag=0; % contador para iniciar a geracao
for i = 1:tamPop
  pais(i,:) = randperm(npar);
  
  a.codigo = i;  
  a.aptidao = 0;
  populacao(i,:) = a;
endfor


% calcular o custo da populacao utilizando a funcao de aptidao
maxit=10000;
while iag<maxit
    for i = 1:tamPop
        populacao(i,:).aptidao = cvfun(pais(populacao(i,:).codigo,:));
    end

    populacao = bubble(populacao);
    
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
        
        pais(populacao(novaPos).codigo,:) = pai1;
        pais(populacao(novaPos + 1).codigo,:) = pai2;   
        
        repetido = randi(length(pai1));
        while repetido != 0                  
            temp = pais(populacao(novaPos).codigo,repetido);
            pais(populacao(novaPos).codigo,repetido) = pais(populacao(novaPos + 1).codigo,repetido);
            pais(populacao(novaPos + 1).codigo,repetido) = temp;  

            repetido = verificaGenteReptido(pais(populacao(novaPos).codigo,:), repetido);          
        end
        
        mutacao1 = randi(20);
        mutacao2 = randi(20);
        
        temp_mut = pais(populacao(novaPos).codigo,mutacao1);
        pais(populacao(novaPos).codigo,mutacao1) = pais(populacao(novaPos).codigo,mutacao2);
        pais(populacao(novaPos).codigo,mutacao2) = temp_mut;
        
        temp_mut = pais(populacao(novaPos + 1).codigo,mutacao1);
        pais(populacao(novaPos + 1).codigo,mutacao1) = pais(populacao(novaPos + 1).codigo,mutacao2);
        pais(populacao(novaPos + 1).codigo,mutacao2) =temp_mut;
        
        novaPos = novaPos + 2;
    end    
end
    
disp(pais);

