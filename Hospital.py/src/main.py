from hospital import *
import os

controle = 0
caminho = "C:\\Users\\jhoan\\Desktop\\VScode\\GitHub\\HospitalManagementSystem\\Hospital.py\\data\\pacientes.txt"
try:
    arquivo = open(caminho, "r+")
except IOError:
    print("Erro ao abrir arquivo!")
    exit(1)
HealCare = Hospital()
ler_arquivo(HealCare, caminho)
dados_hospital(HealCare)

while controle != 8:
    print("Menu: ")
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
        HealCare = cadastra_paciente(HealCare)
        arquivo = arquivo_add(HealCare.lista, caminho)
    elif controle == 2:
        nome = input("Insira o nome do paciente que deseja excluir: ")
        pacientetemp = paciente_busca(HealCare.lista, corrige_nome(nome))
        paciente_exclui(pacientetemp, HealCare)
        arquivo_add(HealCare.lista, caminho)
    elif controle == 3:
        lista_imprime(HealCare.lista)
    elif controle == 4:
        nome = input("Insira o nome do paciente que deseja buscar: ")
        pacientetemp = paciente_busca(HealCare.lista, corrige_nome(nome))
        print("\nNome:", pacientetemp.paciente.nome)
        print("Enfermidade:", pacientetemp.paciente.enfermidade)
        print("Receita:", pacientetemp.paciente.receita)
        print("Internado:", "Sim" if pacientetemp.paciente.internado else "Nao")
        if pacientetemp.paciente.documento.cpf or pacientetemp.paciente.documento.rg:
            if pacientetemp.paciente.documento.cpf:
                print("CPF:", pacientetemp.paciente.documento.cpf)
            else:
                print("RG:", pacientetemp.paciente.documento.rg)
        print()
    elif controle == 5:
        nome = input("Insira o nome do paciente que deseja editar: ")
        pacientetemp = paciente_busca(HealCare.lista, corrige_nome(nome))
        if pacientetemp is not None:
            paciente_edita(pacientetemp.paciente)
            arquivo_add(HealCare.lista, caminho)
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