from hospital import *
import os

# limpa o prompt
def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')
controle = 0
caminho = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\HospitalManagementSystem\\Hospital.py\\data\\pacientes.txt"
try:
    arquivo = open(caminho, "r")
except IOError:
    print("Erro ao abrir arquivo!")
    exit(1)

HealCare = lista_cria()
ler_arquivo(HealCare, caminho)
#dados_hospital(HealCare)

while controle != 8:
    print("Menu:")
    print("========================================")
    print("[1] Cadastrar paciente")
    print("[2] Excluir paciente")
    print("[3] Listar pacientes")
    print("[4] Buscar paciente")
    print("[5] Editar cadastro de paciente")
    print("[6] Consultar vagar disponiveis de leitos no hospital")
    print("[7] Consultar quantidade de pacientes")
    print("[8] Sair")
    print("========================================\n")
    controle = int(input("Digite o numero da opcao desejada: "))

    if controle == 1:
        HealCare = cadastra_paciente(HealCare, HealCare.num_pacientes)
        arquivo = add_arquivo(HealCare, caminho)
    elif controle == 2:
        nome = input("Insira o nome do paciente que deseja excluir: ")
        pacientetemp = busca_paciente(HealCare, nome)
        excluir_paciente(pacientetemp, HealCare)
        add_arquivo(HealCare, caminho)
    elif controle == 3:
        lista_imprime(HealCare)
    elif controle == 4:
        nome = input("Insira o nome do paciente que deseja buscar: ")
        pacientetemp = busca_paciente(HealCare, nome)
        print("\nNome: {}".format(pacientetemp.paciente.nome))
        print("Enfermidade: {}".format(pacientetemp.paciente.enfermidade))
        print("Receita: {}".format(pacientetemp.paciente.receita))
        print("Internado: {}".format("Sim" if pacientetemp.paciente.internado else "Nao"))
        print("Documento: {}".format(pacientetemp.paciente.documento.rg))
    elif controle == 5:
        nome = input("Insira o nome do paciente que deseja editar: ")
        pacientetemp = busca_paciente(HealCare, nome)
        if pacientetemp is not None:
            edita_paciente(pacientetemp.paciente)
            add_arquivo(HealCare, caminho)
        else:
            print("Paciente nao encontrado.")
    elif controle == 6:
        if HealCare.leitos > 0:
            print("Existem {} leitos disponiveis no momento de um total de 25.\n\n".format(HealCare.leitos))
        else:
            print("Nao existem leitos disponiveis no momento todos os 25 estao sendo utilizados!\n")
    elif controle == 7:
        print("Existem um total de {} pacientes cadastrados!\n".format(HealCare.num_pacientes))
    elif controle == 8:
        print("Obrigado por utilizar meu programa!\n")
    else:
        print("opcao invalida!\n")

