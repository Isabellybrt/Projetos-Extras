from django.db import models

class Cliente(models.Model):
    cpf = models.TextField(primary_key=True, max_length=15)
    nome = models.TextField(max_length=255)
    rua = models.TextField(max_length=255)
    cidade = models.TextField(max_length=60)
    numero = models.TextField(max_length=5)
    estado = models.TextField(max_length=20)
