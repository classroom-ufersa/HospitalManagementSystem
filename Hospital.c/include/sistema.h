// funções para tratativas e falhas

// Lê e descarta caracteres encontrados na entrada
void LimpaBuffer(void);

// Lê e valida a opção digitada pelo usuário
int LeOpcao(int menorValor, int maiorValor);

// corrige o nome
void corrige_nome(char nome[]);

// verifica se o CPF é valido
int validarCPF(const char *cpf);

// verifica se o RG é valido
int validarRG(const char *rg);

// le o CPF
void lerCPF(char cpf[]);

// le o RG
void lerRG(char rg[]);