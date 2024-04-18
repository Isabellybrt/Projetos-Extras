
from django.contrib import admin
from django.urls import path
from app_cadastro_cliente import views

urlpatterns = [
    #rota, view responsável, nome de referência
    # facebook.com
    path('', views.home, name='home'),
    path('clientes/', views.clientes, name='listagem_clientes'),
    # facebook.com/isabelly
    # path('isabelly/')
]
