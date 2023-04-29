//TAD: Pacientes

typedef union document Document;
typedef struct pacientes Pacientes;
typedef struct listapacientes Listapacientes;

//preenche os campos de dados do paciente
Pacientes paciente_preenche(void);

//adiciona o paciente a lista
Listapacientes *  lista_add(Listapacientes * l, Pacientes paciente);

//adiciona o paciente ao arquivo
void paciente_add(Listapacientes *p, FILE* arquivo);

// busca um paciente na lista
Listapacientes *busca_paciente(Hospital *h, char nome[]);