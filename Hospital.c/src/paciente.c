#include "sistema.c"
#include "C:\Users\jhoan\Desktop\VScode\GitHub\HospitalManagementSystem\Hospital.c\include\paciente.h"

#define MaxNome 100
#define Leitos 25

union document
{
    char cpf[15];
    char rg[12];
};

struct pacientes
{
    char nome[MaxNome];
    Document documento;
    char enfermidade[50];
    char internado; // sim == 1, nao == 0
    char receita[100];
};

struct listapacientes
{
    Pacientes *pacientes;
    struct listapacientes *next;
    struct listapacientes *prev;
};

Listapacientes *lista_cria(void)
{
    Listapacientes *l = (Listapacientes *)malloc(sizeof(Listapacientes));
    return l;
}

Pacientes paciente_preenche(void)
{
    Pacientes paciente;
    char opcao_documento;
    // Ler o nome do paciente
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", paciente.nome);
    LimpaBuffer();
    corrige_nome(paciente.nome);
    printf("Digite a enfermidade do paciente: ");
    scanf(" %[^\n]s", paciente.enfermidade);
    LimpaBuffer();
    printf("Digite a receita para o paciente: ");
    scanf(" %[^\n]s", paciente.receita);
    LimpaBuffer();
    printf("Internado? (1-sim) (0-nao)\n");
    paciente.internado = LeOpcao('0', '1');
    // Pedir para o usuário escolher qual documento cadastrar
    printf("Digite '1' para cadastrar o CPF ou '2' para cadastrar o RG\n");
    opcao_documento = LeOpcao(OPCAO1, '2');
    // lendo documento
    if (opcao_documento == OPCAO1) {
        lerCPF(paciente.documento.cpf);
    } else if (opcao_documento == OPCAO2) {
        lerRG(paciente.documento.rg);
    }
    else
    {
        printf("Ocorreu um BUG\n");
        exit(1);
    }
    return paciente;
}

void paciente_add(Listapacientes *p, FILE *arquivo)
{
    Pacientes paciente = *(p->next->pacientes);
    fprintf(arquivo, "Nome: %s\n", paciente.nome);
    fprintf(arquivo, "Enfermidade: %s\n", paciente.enfermidade);
    fprintf(arquivo, "Receita: %s\n", paciente.receita);
    fprintf(arquivo, "Internado: %s\n", paciente.internado ? "Sim" : "Nao");
    if (strlen(paciente.documento.cpf) == 14)
    {
        fprintf(arquivo, "CPF: %s\n", paciente.documento.cpf);
    }
    else
    {
        fprintf(arquivo, "RG: %s\n", paciente.documento.rg);
    }
    fprintf(arquivo, "\n");
}

Listapacientes *lista_add(Listapacientes *l, Pacientes paciente)
{
    // Encontrar a posição correta para inserir o novo paciente
    Listapacientes *p = l;
    while (p->next != NULL && strcmp(p->next->pacientes->nome, paciente.nome) < 0)
    {
        p = p->next;
    }
    // Criar um novo nó para o novo paciente
    Listapacientes *novo_no = (Listapacientes *)malloc(sizeof(Listapacientes));
    if (novo_no == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }
    novo_no->pacientes = (Pacientes *)malloc(sizeof(Pacientes));
    if (novo_no->pacientes == NULL)
    {
        printf("Erro: memoria insuficiente.\n");
        exit(1);
    }
    *novo_no->pacientes = paciente;

    // Inserir o novo paciente na posição correta
    novo_no->next = p->next;
    novo_no->prev = p;
    if (p->next != NULL)
    {
        p->next->prev = novo_no;
    }
    p->next = novo_no;
    return l;
}

Listapacientes *busca_paciente(Listapacientes *l, char nome[])
{
    Listapacientes *p;
    for (p = l; p != NULL; p = p->next)
    {
        if (strcmp(p->pacientes->nome, nome) == 0)
        {
            return p;
        }
    }
    return NULL;
}

void edita_paciente(Listapacientes *p)
{
    char opcao_documento;
    char cont;
    printf("\nNome: %s\n", p->pacientes->nome);
    printf("Enfermidade: %s\n", p->pacientes->enfermidade);
    printf("Receita: %s\n", p->pacientes->receita);
    printf("Internado: %s\n", p->pacientes->internado ? "Sim" : "Nao");
    if (strlen(p->pacientes->documento.cpf) == 14)
    {
        printf("CPF: %s\n", p->pacientes->documento.cpf);
    }
    else
    {
        printf("RG: %s\n", p->pacientes->documento.rg);
    }
    printf("Deseja mesmo editar o paciente acima? (1-sim)(2-nao)\n");
    cont = LeOpcao('1', '2');
    if (cont == '2')
    {
        printf("\n");
    }
    else if (cont == '1')
    {

        char opcao;
        printf("\nO que voce deseja editar?\n");
        printf("1 - Nome\n");
        printf("2 - Enfermidade\n");
        printf("3 - Receita\n");
        printf("4 - Internado\n");
        printf("5 - Documento\n");
        opcao = LeOpcao('1', '5');
        switch (opcao)
        {
        case OPCAO1:
            printf("\nDigite o novo nome: ");
            scanf(" %[^\n]s", p->pacientes->nome);
            LimpaBuffer();
            corrige_nome(p->pacientes->nome);
            printf("Paciente atualizado!\n");
            break;
        case OPCAO2:
            printf("\nDigite a nova enfermidade: ");
            scanf(" %[^\n]s", p->pacientes->enfermidade);
            LimpaBuffer();
            printf("Paciente atualizado!\n");
            break;
        case OPCAO3:
            printf("\nDigite a nova receita: ");
            scanf(" %[^\n]s", p->pacientes->receita);
            LimpaBuffer();
            printf("Paciente atualizado!\n");
            break;
        case OPCAO4:
            printf("Internado? (1-sim) (0-nao)\n");
            p->pacientes->internado = LeOpcao('0', '1');
            printf("Paciente atualizado!\n");
            break;
        case OPCAO5:
            printf("Digite '1' para editar o CPF ou '2' para editar o RG\n");
            opcao_documento = LeOpcao(OPCAO1, '2');
            if (opcao_documento == OPCAO1)
            {
                do
                {
                    printf("Digite o CPF do paciente (XXX.YYY.ZZZ-SS): ");
                    scanf(" %[^\n]s", p->pacientes->documento.cpf);
                    LimpaBuffer();
                    if (strlen(p->pacientes->documento.cpf) != 14)
                        printf("Erro: entrada invalida. Digite um CPF válido.\n");
                } while (strlen(p->pacientes->documento.cpf) != 14);
            }
            else if (opcao_documento == OPCAO2)
            {
                do
                {
                    printf("Digite o RG do paciente (XXX.YYY.ZZZ): ");
                    scanf(" %[^\n]s", p->pacientes->documento.rg);
                    LimpaBuffer();
                    if (strlen(p->pacientes->documento.rg) != 11)
                        printf("Erro: entrada invalida. Digite um RG válido.\n");
                } while (strlen(p->pacientes->documento.rg) != 11);
            }
            break;
        default:
            printf("erro!\n");
            exit(1);
            break;
        }
    }
    else
    {
        printf("erro!\n");
        exit(1);
    }
    printf("\n");
}

void lista_libera(Listapacientes *l)
{
    Listapacientes *p = l;
    while (p != NULL)
    {
        Listapacientes *t = p->next;
        free(p);
        p = t;
    }
}

void lista_imprime(Listapacientes *l)
{
    Listapacientes *p = l->next;
    while (p != NULL)
    {
        printf("Nome: %s\n", p->pacientes->nome);
        printf("Enfermidade: %s\n", p->pacientes->enfermidade);
        printf("Receita: %s\n", p->pacientes->receita);
        printf("Internado: %s\n", p->pacientes->internado ? "Sim" : "Nao");
        if (strlen(p->pacientes->documento.cpf) == 14)
        {
            printf("CPF: %s\n", p->pacientes->documento.cpf);
        }
        else
        {
            printf("RG: %s\n", p->pacientes->documento.rg);
        }
        printf("\n");
        p = p->next;
    }
}