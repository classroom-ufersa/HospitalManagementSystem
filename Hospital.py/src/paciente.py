import re

class Document:
    def __init__(self, cpf="", rg=""):
        self.cpf = cpf
        self.rg = rg

class Paciente:
    def __init__(self, nome="", documento=None, enfermidade="", internado=0, receita=""):
        self.nome = nome
        self.documento = documento if documento is not None else Document()
        self.enfermidade = enfermidade
        self.internado = internado
        self.receita = receita

class ListaPacientes:
    def __init__(self, paciente=Paciente()):
        self.paciente = paciente
        self.next = None
        self.prev = None


def corrige_nome(nome):
    # Verificar se o nome contém apenas letras e espaços
    nome_corrigido = ""
    palavras = nome.split()  # converter a string para uma lista de palavras

    # corrigir cada palavra e juntar de volta em uma única string
    for i in range(len(palavras)):
        palavra = palavras[i]
        palavra_corrigida = ""
        for j in range(len(palavra)):
            if j == 0:
                palavra_corrigida += palavra[j].upper()
            elif palavra[j-1] == " ":
                palavra_corrigida += palavra[j].upper()
            else:
                palavra_corrigida += palavra[j].lower()
        nome_corrigido += palavra_corrigida + " "

    return nome_corrigido.strip()  # remover espaços em branco no início e fim da string

def paciente_preenche():
    paciente = Paciente()
    nome = input("Digite o nome do paciente: ")
    paciente.nome = corrige_nome(nome)
    paciente.enfermidade = input("Digite a enfermidade do paciente: ")
    paciente.receita = input("Digite a receita para o paciente: ")
    while True:
        try:
            paciente.internado = int(input("Internado? (1-sim) (0-nao): "))
            if paciente.internado not in [0, 1]:
                raise ValueError
            break
        except ValueError:
            print("Opção inválida. Digite 1 para sim e 0 para não.")
    while True:
        try:
            opcao_documento = input("Digite '1' para cadastrar o CPF ou '2' para cadastrar o RG: ")
            if opcao_documento not in ['1', '2']:
                raise ValueError
            break
        except ValueError:
            print("Opção inválida. Digite 1 para CPF e 2 para RG.")
    if opcao_documento == '1':
        while True:
            cpf = input("Digite o CPF do paciente (XXX.YYY.ZZZ-SS): ")
            if re.match(r'^\d{3}\.\d{3}\.\d{3}-\d{2}$', cpf):
                paciente.documento.cpf = cpf
                break
            else:
                print("CPF inválido. Digite no formato XXX.YYY.ZZZ-SS.")

    elif opcao_documento == '2':
        while True:
            rg = input("Digite o RG do paciente (XXX.YYY.ZZZ): ")
            if re.match(r'^\d{3}\.\d{3}\.\d{3}$', rg):
                paciente.documento.rg = rg
                break
            else:
                print("RG inválido. Digite no formato XXX.YYY.ZZZ.")
        return paciente
        
def lista_add(self, paciente):
    # Encontrar a posição correta para inserir o novo paciente
    p = self.lista
    while p.next is not None and p.next.paciente.nome < paciente.nome:
        p = p.next

    # Criar um novo nó para o novo paciente
    novo_no = ListaPacientes(Paciente())
    novo_no.paciente = paciente

    # Inserir o novo paciente na posição correta
    novo_no.next = p.next
    novo_no.prev = p
    if p.next is not None:
        p.next.prev = novo_no
    p.next = novo_no
    
def lista_imprime(lista):
    p = lista.next
    while p != None:
        print("Nome:", p.paciente.nome)
        print("Enfermidade:", p.paciente.enfermidade)
        print("Receita:", p.paciente.receita)
        print("Internado:", "Sim" if p.paciente.internado else "Nao")
        if p.paciente.documento.cpf or p.paciente.documento.rg:
            if p.paciente.documento.cpf:
                print("CPF:", p.paciente.documento.cpf)
            else:
                print("RG:", p.paciente.documento.rg)
        print()
        p = p.next

def arquivo_add(lista, caminho):
    arquivo = open(caminho, "w")
    if arquivo == None:
        print("Erro ao abrir o arquivo.\n")
        exit(1)

    p = lista
    while p.next != None:
        paciente = p.next.paciente
        arquivo.write(f"Nome: {paciente.nome}\n")
        arquivo.write(f"Enfermidade: {paciente.enfermidade}\n")
        arquivo.write(f"Receita: {paciente.receita}\n")
        arquivo.write(f"Internado: {'Sim' if paciente.internado else 'Nao'}\n")
        if len(paciente.documento.cpf) == 14:
            arquivo.write(f"CPF: {paciente.documento.cpf}\n")
        else:
            arquivo.write(f"RG: {paciente.documento.rg}\n")
        arquivo.write("\n")
        p = p.next

    arquivo.close()
    return arquivo

def paciente_busca(lista, nome):
    p = lista
    while p != None:
        if p.paciente.nome == nome:
            return p
        p = p.next
    print(f"Paciente {nome} não encontrado na lista.")
    return None

def paciente_edita(p):
    print(f"\nNome: {p.nome}")
    print(f"Enfermidade: {p.enfermidade}")
    print(f"Receita: {p.receita}")
    print(f"Internado: {'Sim' if p.internado else 'Nao'}")
    if p.documento.cpf or p.documento.rg:
        if p.documento.cpf:
            print("CPF:", p.documento.cpf)
        else:
            print("RG:", p.documento.rg)
    while True:
                try:
                    cont = int(input("Deseja mesmo editar o paciente acima? (1-sim)(2-nao)\n"))
                    if cont not in [1, 2]:
                        raise ValueError
                    break
                except ValueError:
                    print("Opção inválida. Digite 1 para sim e 2 para não.")
    print()
    if cont == 1:
        opcao = int(input("\nO que voce deseja editar?\n1 - Nome\n2 - Enfermidade\n3 - Receita\n4 - Internado\n5 - Documento\nOpcao: "))
        if opcao == 1:
            nome = input("\nDigite o novo nome: ")
            p.nome = corrige_nome(nome)
        elif opcao == 2:
            p.enfermidade = input("\nDigite a nova enfermidade: ")
        elif opcao == 3:
            p.receita = input("\nDigite a nova receita: ")
        elif opcao == 4:
            p.internado = int(input("\nO paciente esta internado? (1-sim / 0-nao): "))
            while True:
                try:
                    p.internado = int(input("Internado? (1-sim) (0-nao): "))
                    if p.internado not in [0, 1]:
                        raise ValueError
                    break
                except ValueError:
                    print("Opção inválida. Digite 1 para sim e 0 para não.")
        elif opcao == 5:
            if p.documento.cpf or p.documento.rg:
                if p.documento.cpf:
                    while True:
                        cpf = input("Digite o novo CPF do paciente (XXX.YYY.ZZZ-SS): ")
                        if re.match(r'^\d{3}\.\d{3}\.\d{3}-\d{2}$', cpf):
                            p.documento.cpf = cpf
                            break
                        else:
                            print("CPF inválido. Digite no formato XXX.YYY.ZZZ-SS.")
                else:
                    while True:
                        rg = input("Digite o RG do pacientee (XXX.YYY.ZZZ): ")
                        if re.match(r'^\d{3}\.\d{3}\.\d{3}$', rg):
                            p.documento.rg = rg
                            break
                        else:
                            print("RG inválido. Digite no formato XXX.YYY.ZZZ.")     
        else:
            print("Opcao invalida!")
            return
    print("Paciente editado com sucesso!")