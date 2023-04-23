// TAD: Hospital

typedef union document Document;
typedef struct pacientes Pacientes;
typedef struct listapacientes Listapacientes;
typedef struct hospital Hospital;

// adiciona pacientes ao arquivo;
FILE *add_arquivo(Hospital *h, char *caminho);

// cadastra o paciente
Hospital *cadastra_paciente(Hospital *h, int *qnt);

// adiciona na lista
void lista_add(Hospital *h, Pacientes paciente);

// cria a lista duplamente encadeada
Hospital *lista_cria(void);

// imprime os pacientes
void lista_imprime(Hospital *h);

void ler_arquivo(Hospital *h, char *caminho, int *qnt);