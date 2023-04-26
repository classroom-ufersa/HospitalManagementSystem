## HospitalManagementSystem
# Sistema Hospitalar < HealCare >

## INTRODUÇÃO

  O sistema foi desenvolvido na linguigem C, utilizando vários funções presentes na linguagem. O intuito desse projeto é criar um sistema que consiga gerenciar leitos de hospital, conseguindo cadastrar o paciente, exibir o leito disponíveis e exibir os dados do paciente. O nome do hospital < HealCare > foi gerado automaticamente por uma IA, a cidade na qual o hospital está localizado é a junção dos nomes das cidades dos contribuientes do projeto, sendo ela Umarigomes. Lembrando que este sistema é de um hospital ficticio sendo utilizado para uso acâdemico.
  
## PROBLEMÁTICA 

Criar um sistema é responsável por gerir pacientes de um hospital dando ao usuário uma grande diversidade de opções para realizar o cadastro, sendo elas:

- ### Cadastrar Paciente:
  Responsável por coletar os dados do paciente e formatar os nomes no padrão de busca.
  
- ### Excluir Paciente:
  Responsavel por apagar os dados do paciente do arquivo e liberar a memória ocupada por ele.
  
- ### Listar Paciente:
  Responsável por exibir ao usuário todos os pacientes que estão cadastrados no hospital.
  
- ### Buscar Paciente:
  Responsável por coletar o nome do paciente que o usuário está buscando e exibir os dados desse paciente.
  
- ### Editar cadastro de paciente:
  Responsável por atualizar um dado específico do paciente.
  
- ### Consultar vagar disponiveis de leitos no hospital:
  Exibe o número de leitos disponíveis, número total de leitos e o número de leitos ocupados.
  
- ### Consultar quantidade de pacientes:
  Exibe o número de pacientes cadastrados no hospital.


O projeto foi feito utilizando arquivos, listas duplamente encadeadas, alocação dinâmica. Mas o que são essas coisas?


- ### Arquivos:
  Arquivos são ferramentas que utilizamos para armazenar informações em midia digital. Usando a biblioteca <stdlib.h> para conseguir manipular o arquivo por meio de funções específicas. No nosso projeto estamos usando o arquivo para armazenar os dados dos pacientes, conseguindo salvar os dados fornecidos pelo usuário. 
  
- ### Lista duplamente encadeadas:
  Como o nome já sugere, é uma lista como as outras. A grande diferença é que agora podemos percorrer a lista nos dois sentidos, ajudando a acessar diversas posições da nossa lista. Isso ocorré porque nessa lista existem dois ponteiros. O primeiro aponta para o próximo elemento da lista, enquanto o segundo ponteiro aponta para o elemento anterior. 
  No nosso sistema, nós usamos a lista duplamente encadeada para conseguir acessar os pacientes armazenados no arquivo. 

- ### Alocação dinamica:

- ### Ponteiro:

- ### Tipos Estruturados:
