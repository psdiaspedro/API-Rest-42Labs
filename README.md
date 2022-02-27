<h1 align="center">
	42-São Paulo: Labs
</h1>

<p align="center">
	<b><i>Documentação do Projeto</i></b><br>

## 🗣️ Resumo Desafio
- Criar uma API REST que retorna o LOG em um arquivo.
- Criar uma aplicação CLI que consome o arquivo com os logs mostre o resultado.

para mais detalhes sobre o desafio, acesse: https://github.com/42sp/42labs-selection-process-v2-psdiaspedro/blob/main/DESAFIO.md

As proximas duas sessões vão dar uma visão macro sobre as duas aplicações.

### 💎 API Rest
- A API trabalha com 3 métodos: GET, POST e DELETE e 3 rotas: a raiz /, /me e /database. 
- O resultado das requisições são armazenados em um arquivo de formato txt chamado logs.
- Dependendo do método e da rota usada consiguimos obter resultados diferentes que serão descritos a seguir. 

#### Rota raiz - /

Na rota raiz a API trabalha apenas com o método GET e faz uma requisição para uma outra API externa chamada Kanye REST (link em referencias) que retorna aleatóriamente em formato JSON pérolas ditas pelo famoso e polemico raper.

#### Rota sobre - /me

Nessa rota a API também trabalha apenas com o método GET e retorna em formato JSON informações sobre o seu criador.

#### Rota banco de dados - /database

Aqui é onde a API trabalha GET, POST e DELETE. Consumindo, adicionando e deletando dados de um banco de dados relacional MYSQL.

#### Arquivo logs.txt

O arquivo contém as seguintes informações sobre a requisição:
- Método Utilizado
- Hora da requisição
- Rota Utilizada
- Status Code da requisição.

### 👽 Aplicação CLI
- A aplicação consome o arquivo gerado pela API e as retorna no terminal.
- Essas informações podem ser exibidas em formatos diferentes de acordo com a solicitação. 

## 🔨 Ferramentas e Bibliotecas externas


## 🌀 Going deep inside the code
Ta bom, mas como tudo isso funciona embaixo dos panos?


