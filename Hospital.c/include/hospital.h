// TAD: Hospital

typedef union document Document;
typedef struct pacientes Pacientes;
typedef struct listapacientes Listapacientes;
typedef struct hospital Hospital;

// cadastra no arquivo
FILE *cadastra_paciente(FILE *arquivo, char *caminho);

//cria a lista duplamente encadeada
Hospital *lista_cria(Hospital *h);
