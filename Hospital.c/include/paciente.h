//TAD: Pacientes

typedef union document Document;
typedef struct pacientes Pacientes;
typedef struct listapacientes Listapacientes;

//preenche os campos de dados do paciente
Pacientes preenche_paciente(void);

//adiciona o paciente a lista
void lista_add(Listapacientes * l, Pacientes paciente);
