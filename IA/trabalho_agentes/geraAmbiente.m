%Fun��o que cria o ambiente 4x4 (sala) e cria tamb�m paredes para a sala 
function sala = geraAmbiente()

dim = 6;
parede = 2; 
sujeira = 1; 

sala = (rand(dim, dim)>0.7)*sujeira;
sala(1, :) = parede; 
sala(end, :) = parede;
sala(:, 1) = parede;
sala(:, end) = parede;

end