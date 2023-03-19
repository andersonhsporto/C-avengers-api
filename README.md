# Avengers API

&emsp; Avengers API é uma API REST criada para própositos de estudo,
utilizando a linguagem C e o framework Mongoose.
Esta permite a consulta de dados sobre os personagens da Marvel Comics.

&emsp; Além da API, este projeto também possui um cliente em C denominado `Logviewer`, este cliente permite a consulta dos dados de log da api.

# Documentação

Avengers Api utiliza uma [versão simplificada](https://github.com/42sp/42labs-selection-process-v2-andersonhsporto/blob/main/utils/vingadores.csv) de alguns dados sobre os personagens da Marvel Comics compilado por [Walt Hickey](https://fivethirtyeight.com/contributors/walt-hickey/).

### Tecnologias

- [ANSI C ](https://www.ansi.org/) - Linguagem de programação
- [Mongoose](https://mongoose.ws/) - Framework para desenvolvimento de aplicações web
- [mJson](https://github.com/cesanta/mjson) - Biblioteca para manipulação de arquivos JSON
- [Mariadb](https://mariadb.org/) - Banco de dados relacional
- [Postman](https://www.postman.com/) - Ferramenta para testar e documentar APIs
- [Libft](https://github.com/andersonhsporto/ft-libft) - Biblioteca de funções em C

### Instalação

Para este projeto é necessario ter instalado o [mariadb](https://mariadb.org/), o [gcc](https://gcc.gnu.org/) e o [make](https://www.gnu.org/software/make/).


O usuário padrão está definido como `userStark` e a senha padrão como `strongpassword`,
estes estão predefinidos nas macros `USER` e `PASS` dentro do header `env.h`.
além destes a api utiliza um banco de dados denominado `api_vingadores` definido na macro `DB` no mesmo header.


Este projeto utiliza algumas bibliotecas externas, é recomendado que utilize
o pacote base-devel em sistemas Arch ou o equivalente para a sua distribuição linux.


Utilize o seguinte comando para instalar o pacote base-devel:
```
    $ sudo pacman -S base-devel
```

Para compilar o projeto utilize o `make` este irá gerar o arquivo denominado
`avengers_api`.

### Docker Compose

O docker compose automatiza a criação de containers, para utiliza-lo basta executar o comando:

```
	$ docker-compose up -d
```

### Dockerhub

Uma imagem docker da api está disponível no dockerhub no link [andersonhsporto/avengers_api](https://hub.docker.com/r/andersonhsporto/avengers_api)

Para executar a imagem utilize o comando:

```
    $ docker run -p 4242:4242 -d --name avengers_api andersonhsporto/avengers_api
```

Utilize o endereço `http://localhost:4242` para acessar a api.


### Criar imagem Docker

Para criar uma imagem local utilize o comando:

```
    $ docker build -t <NOME_DA_IMAGEM> .
```

e para executar a imagem utilize o comando:

```
	$ docker run -p 4242:4242 -d --name avengers_api <NOME_DA_IMAGEM>
```

### URI

A uri está prefixada em `http://localhost:4242`, este é definido pela macro `ADDRESS` no header `env.h`

### Dados

A versão completa dos dados utilizados pela api está disponível em: [avengers.csv](https://github.com/fivethirtyeight/data/tree/master/avengers)

Header | Definição
---|---------
`id`| ID exclusivo do personagem
`URL`| URL do personagem de quadrinhos na Marvel Wikia
`Name` | Nome completo do personagem
`Alias` | Apelido em inglês do personagem
`Alias-br` | Apelido em português do personagem
`Appearances` | Número de histórias em quadrinhos em que o personagem apareceu até 30 de abril 
`Current?` | Membro está atualmente ativo em uma equipe afiliada aos vingadores?
`Gender` | Gênero registrado do personagem
`Probationary` | Às vezes, o personagem recebeu status probatório como um Vingador, esta é a data em que aconteceu
`Full/Reserve` | Mês e ano em que o personagem foi apresentado como membro pleno ou reserva dos Vingadores
`Year` | Mês e ano em que o personagem foi apresentado como membro pleno ou reserva dos Vingadores
`Years since joining` | 2015 menos o ano
`Honorary` | Status do vingador, se eles receberam o status de "Vingador Honorário", se eles estão simplesmente na "Academia" ou "Full" caso contrário
`Death1` | Sim se o Vingador morreu, Não se não
`Return1` | Sim se o Vingador retornou de sua primeira morte, Não se não retornou, em branco se não aplicável
`Death2` | Sim se o Vingador morreu uma segunda vez após seu renascimento, Não se não morreu, em branco se não for aplicável
`Return2` | Sim se o Vingador retornou de sua segunda morte, Não se não retornou, em branco se não aplicável
`Notes` | Descrições de mortes e ressurreições

É atribuído um *id* (numero inteiro positivo) para cada personagem ao iniciar a api.

Este id pode ser utilizado no método `GET` para consultar as informações sobre o personagem.
Utilizando este id com `DELETE` é possível deletar o personagem do banco de dados.

Por exemplo: http://localhost:4242/id/7

```javascript
{
    "id": 7,
    "URL": www.marvel.wikia.com/Steven_Rogers_(Earth-616),
    "Name": Steven Rogers,
    "Alias": Captain America,
    "Alias-br": Capitao America,
    "Appearances": 3458,
    "Current": YES,
    "Gender": MALE,
    "Probationary": nul,
    "Full/Reserve Avengers Intro": Mar-64,
    "Year": 1964,
    "Year since joining": 51,
    "Honorary": Full,
    "Death 1": YES,
    "Return 1": YES,
    "Death 2": nul,
    "Return 2": nul,
    "Notes": Dies at the end of Civil War. Later comes back.
}
```
Também é possivel utilizar o *alias* com o método `GET` e com o método `DELETE`,
no caso de nomes compostos é necessário usar o sinal de `+` no lugar do espaço.
Por exemplo: http://localhost:4242/alias/Iron+Man

```javascript
{
    "id": 3,
    "URL": www.marvel.wikia.com/Anthony_Stark_(Earth-616),
    "Name": Anthony Edward Tony Stark,
    "Alias": Iron Man,
    "Alias-br": Homem de Ferro,
    "Appearances": 3068,
    "Current": YES,
    "Gender": MALE,
    "Probationary": nul,
    "Full/Reserve Avengers Intro": Sep-63,
    "Year": 1963,
    "Year since joining": 52,
    "Honorary": Full,
    "Death 1": YES,
    "Return 1": YES,
    "Death 2": nul,
    "Return 2": nul,
    "Notes": Death> Later while under the influence of Immortus Stark committed a number of horrible acts and was killed.  This set up young Tony. Franklin Richards later brought him back
}
```
Ao utilizar a api no `path /` com o método `GET` a api retorna as informações sobre algum personagem de forma aleátoria.
Por exemplo: http://localhost:4242/

```javascript
{
    "id": 16,
    "URL": www.marvel.wikia.com/Natalia_Romanova_(Earth-616)#,
    "Name": Natalia Alianovna Romanova,
    "Alias": Black Widow,
    "Alias-br": Viúva Negra,
    "Appearances": 1112,
    "Current": YES,
    "Gender": FEMALE,
    "Probationary": nul,
    "Full/Reserve Avengers Intro": May-73,
    "Year": 1973,
    "Year since joining": 42,
    "Honorary": Full,
    "Death 1": YES,
    "Return 1": YES,
    "Death 2": nul,
    "Return 2": nul,
    "Notes": Killed by The Hand. Later revived with The Stone of the Chaste
}
```
Está api retorna os seguintes "HTML status code"

STATUS CODE | Definição
---|---------
`200 - OK`| Tudo funcionou como esperado
`400 - Bad Request`| Falha na requisição


## CLI Logviewer (Visualizador de logs)

Logviewer é uma interface de linha de comando
que mostra um resumo das informações contidas no log da
avengers api.

logviwer utiliza a biblioteca [readline](https://wiki.archlinux.org/title/readline),
para realizar a instalação desta em sistemas Arch utilize o seguinte comando: 
```
    $ pamac install readline
```

Para compilar o projeto utilize o `make` este irá gerar o arquivo denominado
`logviewer`.

Para obter ajuda no terminal da logviewer utilize o comando `help`.

### Lista de Comandos
Comando | Definição
---|---------
`help`| Exibe a lista de comandos
`GET`| Mostra informações sobre o método GET
`DELETE`| Mostra informações sobre o método DELETE
`root`| Mostra informações sobre todos os métodos
`clear`|  Limpa a tela do terminal
`exit`|  Encerra o terminal

#### Exemplos:
Utilizando [Logviwer] >>  get
```bash
[Logviwer] >>  get

	Method:	GET
	*****************************
	*  PATH    * Total Requests *
	*****************************
	*    /     *       4       *
	*****************************
	*  /id/    *       8        *
	*****************************
	* /alias/  *       6        *
	*****************************
```
Utilizando [Logviwer] >>  delete
```bash
[Logviwer] >>  delete

	Method:	DELETE
	*****************************
	*  PATH    * Total Requests *
	*****************************
	*  /id/    *       1        *
	*****************************
	* /alias/  *       3        *
	*****************************
```
Utilizando [Logviwer] >>  root
```bash
[Logviwer] >>  root

	Method:	root
	******************************************
	*  METHOD    *  PATH    * Total Requests *
	******************************************
	*    GET     *    /     *       4       *
	******************************************
	*    GET     *  /id/    *       8        *
	******************************************
	*    GET     * /alias/  *       6        *
	******************************************
	*  DELETE    *  /id/    *       1        *
	******************************************
	*  DELETE    * /alias/  *       3        *
	******************************************
```

## Referências
* Informações adicionais - [C API mariadb](https://zetcode.com/db/mysqlc/)
* Informações adicionais - [mariadb](https://mariadb.org/)
* Informações adicionais - [C API readline](https://www.gnu.org/software/readline/)
* Informações adicionais - [readline](https://wiki.archlinux.org/title/readline)
* Informações adicionais - [C API curl](https://curl.se/libcurl/c/)
