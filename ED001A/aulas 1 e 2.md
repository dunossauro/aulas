# Aula 1 e 2

> 06/02/16

## Variáveis dinâmicas

### Introdução

Todas as estruuras de dados vistas anteriormente são estáticas. Isso é, as variáveis uma vez declaradas, implicam em alocação de memória fixo e pre-determinado.

Durante toda a execução do programa a quatidade de bytes alocados para as variáveis estáticas não pode ser modificada, mesmo que seja pouco utilizada.

É muito frequente, entretanto, a ocorrência de listas de dados que variam em tamanho:

Exemplo:
   - Relação de clientes

Por outro lado, se nem mesmo programa precisamos processar duas matrizes de ordem grande, pode não haver espaço de memória suficiente.

O ideal seria utlizar o espaço em mória para uma delas, fazer as aplicações desejadas e dispor desse espaço, liberando-o para outra estrutura.

As variáves dinâmicas que revemos a seguir, não são criadas em tempo de compilação. Isto significa que o compilador não faz alocação de memória para variáveis dinâmicas.

Durante a execução do programa podemos alocar o espaço desejado ou dispor dele quando não for mais necessário.

As variáveis dinâmicas não são declaradas explicitamente na parte de declaração do programa, nem tem nome.

A forma de se fazer referência a uma variável dinâmica é atraves de uma variável dinâmica que contenha um endereço de memória da estrutura dinâmica.

Essa variável é conhecida como ponteiro.

------------------------------

### Tipo Ponteiro

Os valores do tipo de ponteiro são endereço de memória da estrutura dinâmica.

Uma variável do tipo ponteiro é definida pelo símbolo \* seguido do tipo da variável dinâmica que pode ser referenciada por esse ponteiro.

#### Ponteiro - Struct

As variáveis Ponteiro podem ser associadas a um tipo de dado ou a um struct.

Quando uma variável do tipo ponteiro é definida a um tipo de dados, pouco pode ser desenvolvido, devido a sua limitação de dados.

Nas literaturas encontra-se muitos exemplos utilizando Struct.

Uma struct permite agregar todos os tipos de dados, o que facilita a operacionalização, bem como, o armazenamento de diversos dados em um único conjunto.

Exemplo:

      type def struct no{

         int codigo;
         string nome[30];
         int idade;
         float salario;

      } no;

      struct no * item;

A declaração acima faz o reconhecimento da existencia da varável item que é dotipo ponteiro.

Uma variável do tipo ponteiro ocupa 4 bytes de mamória.

Observe que na declaração do tipo ponteiro é especificado o tipo da estrutura que pode ser apontada por uma variável ponteiro.

No exemplo acima, uma variável do tipo item pode rerefenciar ou apontar para uma estrutura do tipo item.

- Struct - Item

| Código | Nome | Idade | Salário |
|--------|------|-------|---------|

> 22/02/16

A declaração da variável item não é inicializada. Isto é, nenhum valor é armazenado em item e na memória não existem ainda nenhuma estrutura do tipo item.

Para criar uma variável dinâmica, é preciso obter uma certa quantidade de espaço de memória. No exemplo a cima, o espaço necessário é o número de bytes que acomoda o tipo item. A alocação desse espaço e sua localização na memória são feitas pela execução de um procedimento prédefinido chamado `maloc`.

### O comando Malloc

O procedimento `maloc` têm com parâmetro uma variável ponteiro e, quando ativado, aloca espaço em memória para uma extrutura do tipo nó e faz com que o endereço dessa estrutura na memória deja armazenada na variável item.

Portanto, dizemos que item está apontado para um endereço de memória, conforme a figura a baixo.


![imagem](https://raw.githubusercontent.com/z4r4tu5tr4/aulas/master/ED001A/estrutura.-.aula.2.jpg)


A estrutura dinâmica não é inicializada, pois nada é armazenada em item.

A variável item contém o endereço de memória dessa estrutura, sendo possível a sua visualização via comando `printf`.

Para acessar a estrutura dinâmica, escrevemos o nome da variável ponteiro, seguido do simbolo `->`. O exemplo abaixo identifica a estrutura, bem como, o reconhecimento da variável dinâmica, através da concatenação entre ponteiro e identificador dos campos.

#### Exemplo

               Identificador
               |
               V

      Item -> código

        |
        V
        Variável Ponteiro


Uma variável dinâmica pode ser operacionaliza da mesma forma que as variáveis estátivas. Veremos:


      scanf("%i", &item->codigo);
      item -> contador ++;

      if (item -> idade >= 18){

         printf("Exibir o resultado do conteúdo do endereço", item -> idade')

      }

Podemos usar o comando de atribuição para as variáveis do tipo Ponteiro, desde que sejam de um mesmo tipo. Os operadores relacionais `=>`,`>`,`<`e`<=` também podem ser utilizados.

Em uma contrante predefinida para o tipo ponteiro, que é identificado por `NULL`. O valor `NULL` não é nenhum endereço válido e é compatível com qualquer variável ponteiro.

A técnica que veremos a seguir permite acompanhar os ponteiro e posterioramente visualizar os resultados gerados pelo código abaixo:

      type def struct no; {

         int codigo;
         string nome;

      } no;

      struct no *H, *P, *Z;

      H = NULL;
      P = NULL;
      Z = NULL;

      Z = (no*)malloc(sizeof(no));
      P = Z;
      H = Z;

      scanf("%i" &Z -> codigo);
      scanf("%s" &Z -> nome);

      printf("Os dados são %i", P -> codigo);
      printf("Os dados são %s", P -> nome);
