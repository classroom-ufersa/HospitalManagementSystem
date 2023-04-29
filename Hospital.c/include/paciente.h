//TAD: Pacientes

typedef union document Document;
typedef struct pacientes Pacientes;
typedef struct listapacientes Listapacientes;

//preenche os campos de dados do paciente
Pacientes paciente_preenche(void);

//adiciona o paciente a lista
Listapacientes *  lista_add(Listapacientes * l, Pacientes paciente);
