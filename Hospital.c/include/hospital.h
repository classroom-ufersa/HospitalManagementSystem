// TAD: Hospital

typedef struct hospital Hospital;

// adiciona pacientes ao arquivo;
FILE *add_arquivo(Hospital *h, char *caminho);

// cadastra o paciente
Hospital *cadastra_paciente(Hospital *h, int *qnt);

// cria o hospital
Hospital *hospital_cria(void);



// le o arquivo e armazena na lista encadeada dupla
void ler_arquivo(Hospital *h, char *caminho, int *qnt);

// exclui um paciente
Hospital *excluir_paciente(Listapacientes *p, Hospital *h);

// libera a lista

