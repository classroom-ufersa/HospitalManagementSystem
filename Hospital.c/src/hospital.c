#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"

#define MaxNome 100
#define Leitos 25
#define codigohospital 77

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
    const int codigo;
    int leitos;
    const char localizacao[20];
    const char nome[15];
    Pacientes paciente;
};
