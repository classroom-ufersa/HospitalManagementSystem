#include "hospital.c"

int main(void)
{
    char controle, volta;
    int quantidade = 0;
    char nome[MaxNome];
    Listapacientes *pacientetemp = (Listapacientes *)malloc(sizeof(Listapacientes));
    FILE *arquivo;
    char caminho[] = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\HospitalManagementSystem\\Hospital.c\\data\\pacientes.txt"; // caminho do arquivo txt(Varia de pc para pc)
    arquivo = fopen(caminho, "r");                                                                                           // abrindo arquivo
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!");
        exit(1);
    }
    Hospital *HealCare = hospital_cria();
    ler_arquivo(HealCare, caminho, &quantidade);
    dados_hospital(HealCare);
    while (controle != OPCAO8) // vai repetir ate o usuario digitar 8
    {
        printf("Menu:\n");
        printf("========================================\n");
        printf("[1] Cadastrar paciente\n");
        printf("[2] Excluir paciente\n");
        printf("[3] Listar pacientes\n");
        printf("[4] Buscar paciente\n");
        printf("[5] Editar cadastro de paciente\n");
        printf("[6] Consultar vagar disponiveis de leitos no hospital\n");
        printf("[7] Consultar quantidade de pacientes\n");
        printf("[8] Sair\n");
        printf("========================================\n");
        controle = LeOpcao(OPCAO1,'8');
        system("cls");
        switch (controle)
        {
        case OPCAO1:
            printf("Voce quer mesmo cadastrar um paciente? 1-(Sim) 2-(Nao)\n");
            volta = LeOpcao(OPCAO1,'2');
            if (volta == OPCAO1)
            {
                HealCare = cadastra_paciente(HealCare, &quantidade);
                arquivo = add_arquivo(HealCare, caminho);
            }
            else
            {
                break;
            }
            break;
        case OPCAO2:
            printf("Voce quer mesmo excluir um paciente? 1-(Sim) 2-(Nao)\n");
            volta = LeOpcao(OPCAO1,'2');
            if (volta == OPCAO1)
            {
                printf("Insira o nome do paciente que deseja excluir: ");
                scanf(" %[^\n]s", nome);
                LimpaBuffer();
                corrige_nome(nome);
                pacientetemp = busca_paciente(HealCare->lista, nome);
                if (pacientetemp != NULL)
                {
                    excluir_paciente(pacientetemp, HealCare);
                    add_arquivo(HealCare, caminho);
                }
                else
                {
                    printf("O paciente nao esta cadastrado!\n\n");
                }
            }
            else
            {
                break;
            }
            break;
        case OPCAO3:
            printf("Voce quer mesmo listar os pacientes? 1-(Sim) 2-(Nao)\n");
            volta = LeOpcao(OPCAO1,'2');
            if (volta == OPCAO1)
            {
                printf("\n");
                lista_imprime(HealCare->lista);
            }
            else
            {
                break;
            }
            break;
        case OPCAO4:
            printf("Voce quer mesmo buscar um paciente? 1-(Sim) 2-(Nao)\n");
            volta = LeOpcao(OPCAO1,'2');
            if (volta == OPCAO1)
            {
                printf("Insira o nome do paciente que deseja buscar: ");
                scanf(" %[^\n]s", nome);
                LimpaBuffer();
                corrige_nome(nome);
                pacientetemp = busca_paciente(HealCare->lista, nome);
                if (pacientetemp != NULL)
                {
                    printf("\nNome: %s\n", pacientetemp->pacientes->nome);
                    printf("Enfermidade: %s\n", pacientetemp->pacientes->enfermidade);
                    printf("Receita: %s\n", pacientetemp->pacientes->receita);
                    printf("Internado: %s\n", pacientetemp->pacientes->internado ? "Sim" : "Nao");
                    if (strlen(pacientetemp->pacientes->documento.cpf) == 14)
                    {
                        printf("CPF: %s\n\n", pacientetemp->pacientes->documento.cpf);
                    }
                    else
                    {
                        printf("RG: %s\n\n", pacientetemp->pacientes->documento.rg);
                    }
                }
                else
                {
                    printf("O paciente nao esta cadastrado!\n\n");
                }
            }
            else
            {
                break;
            }
            break;
        case OPCAO5:
            printf("Voce quer mesmo editar um paciente? 1-(Sim) 2-(Nao)\n");
            volta = LeOpcao(OPCAO1,'2');
            if (volta == OPCAO1)
            {
                printf("Insira o nome do paciente que deseja editar: ");
                scanf(" %[^\n]s", nome);
                LimpaBuffer();
                corrige_nome(nome);
                pacientetemp = busca_paciente(HealCare->lista, nome);
                if (pacientetemp != NULL)
                {
                    edita_paciente(pacientetemp);
                    add_arquivo(HealCare, caminho);
                }
                else
                {
                    printf("O paciente nao esta cadastrado!\n\n");
                }
            }
            else
            {
                break;
            }
            break;
        case OPCAO6:
            printf("Voce quer mesmo ver o total de leitos disponiveis? 1-(Sim) 2-(Nao)\n");
            volta = LeOpcao(OPCAO1,'2');
            if (volta == OPCAO1)
            {
                if (HealCare->leitos > 0)
                    printf("Existem %d leitos disponiveis no momento de um total de %d.\n\n", HealCare->leitos, Leitos);
                else
                    printf("Nao existem leitos disponiveis no momento todos os %d estao sendo utilizados!\n\n", Leitos);
            }
            else
            {
                break;
            }
            break;
        case OPCAO7:
            printf("Voce quer mesmo ver o total de pacientes cadastrados? 1-(Sim) 2-(Nao)\n");
            volta = LeOpcao(OPCAO1,'2');
            if (volta == OPCAO1)
            {
                if (quantidade > 0)
                {
                    printf("Existem um total de %d pacientes cadastrados!\n\n", quantidade);
                }
                else
                {
                    printf("Nao existem pacientes cadastrados!\n");
                }
            }
            else
            {
                break;
            }
            break;
        case OPCAO8:
            printf("Voce quer mesmo sair do programa? 1-(Sim) 2-(Nao)\n");
            volta = LeOpcao(OPCAO1,'2');
            if (volta == OPCAO1)
            {
                printf("Obrigado por utilizar meu programa!\n");
            }
            else
            {
                controle = 1;
                break;
            }
            break;
        default:
            printf("opcao invalida!\n");
            break;
        }
    }
    free(pacientetemp);
    lista_libera(HealCare->lista);
    free(HealCare);
    return 0;
}