// TAD: Hospital

typedef struct hospital Hospital;

// adiciona pacientes ao arquivo;
FILE *add_arquivo(Hospital *h, char *caminho);

// cadastra o paciente
Hospital *cadastra_paciente(Hospital *h, int *qnt);

// cria o hospital
Hospital *hospital_cria(void);

// imprime os pacientes
void lista_imprime(Hospital *h);

// le o arquivo e armazena na lista encadeada dupla
void ler_arquivo(Hospital *h, char *caminho, int *qnt);

// busca um paciente na lista
Listapacientes *busca_paciente(Hospital *h, char nome[]);

// edita um paciente
void edita_paciente(Listapacientes *p);

// exclui um paciente
Hospital *excluir_paciente(Listapacientes *p, Hospital *h);

// libera a lista
void lista_libera(Hospital *h);
