close all; clc; clear;

global iag x y
%% Configuracao Inicial
npar=20; % numero das variaveis para serem otimizadas (genes)
Nt=npar; % numero de colunas da matriz de populacao

x=rand(1,npar);
y=rand(1,npar); % cidades em (cidadeX, cidadeY)

% Adiciona o numero maximo de interacoes (Criterio de Parada)

% Parametros do AG
% tamanho da populacao
% taxa de mutacao (probabilidade de 0.05)
tamPop = 20;
selecao=0.5; % fracao da populacao a ser mantida
manter=floor(selecao*tamPop); % numero de membros da populacao que sobrevivem
M=ceil((tamPop-manter)/2); % numero de cruzamentos

% calculo da probabilidade para a selecao dos pais
probab=1; %probabilidade
for ii=2:manter
    probab=[probab ii*ones(1,ii)];
end
Nprobab=length(probab);
probab=manter-probab+1; 

% Gerar a populacao inicial
iag=0; % contador para iniciar a geracao
% gerar a populacao aleatoria (Veja funcao randperm)
% deve ser uma matriz 20x20 (cromossomo + n. da populacao)

for i = 1:tamPop
  pais(i,:) = randperm(npar);
  
  a.codigo = i;  
  a.aptidao = 0;
  populacao(i,:) = a;
endfor


% calcular o custo da populacao utilizando a funcao de aptidao
% colocar o custo minimo no elemento 1 (Veja funcao sort)
% organizar a populacao com o custo mais baixo primeiro
% calcula o custo minimo da populacao (veja funcao min)
% calcula a media aritmetica da populacao (veja funcao mean)

maxit=100;
%% Interacao pelas geracoes (LOOP PRINCIPAL)
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
    
    % Execucao da Recombinacao (crossover)
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
        
        novaPos = novaPos + 2;
    end    
        %seleciona o Pai 1
        %seleciona o Pai 2
       
        
        % Faz a t�cnica de recombina��o Cycle

    % Faz a Mutacao da populacao

   
    % Se calcula um novo custo para a nova popula��o
    
    
    %_______________________________________________________
    % Organiza em ordem crescente os custos e associa aos parametros
end
    
disp(pais);

%_______________________________________________________
% Mostrar os resultados

