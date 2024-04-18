from django.shortcuts import render
from .models import Cliente

def home(request):
    return render(request, 'clientes/home.html')

def clientes(request):
    # Salvar os dados da tela para o banco de dados
    novo_cliente = Cliente()
    novo_cliente.cpf = request.POST.get('cpf')
    novo_cliente.nome = request.POST.get('nome')
    novo_cliente.rua = request.POST.get('rua')
    novo_cliente.cidade = request.POST.get('cidade')
    novo_cliente.numero = request.POST.get('numero')
    novo_cliente.estado = request.POST.get('estado')
    novo_cliente.save()

    # Exibir todos os clientes ja cadastrados em uma nova pagina

    clientes={
        'clientes': Cliente.objects.all()
    }

    # Retornar os dados para a pagina de listagem de clientes
    return render(request, 'clientes/clientes.html', clientes)