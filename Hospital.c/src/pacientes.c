#include <stdio.h>
#include <stdlib.h>
#include "pacientes.h"

#define MaxNome 100

union document
{
    char cpf[15];
    char rg[12];
};


struct pacientes
{
    char nome[MaxNome];
    Document documento;
    char enfermidade [50];
    int internado; //sim == 1, nao == 0
    char receita [50];
};

struct hospital
{
    int codigo;
    int leitos;
    char localizacao[20];
    char nome[15];
    Pacientes paciente;
};
