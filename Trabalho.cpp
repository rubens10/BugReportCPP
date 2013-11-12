#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 5

struct dado {
	int id;
	char string[100];
	int num;
	struct dado *d, *e;
};

struct idx_id {
	int id;
	struct dado *x;
};

struct idx_string {
	char string[100];
	struct dado *x;
	struct idx_string *e, *d;
};

struct idx_string *i_string;
	struct idx_num {
	int num;
	struct dado *x;
};
	
struct dado *raiz;
struct idx_id i_id[MAX];
struct idx_num i_num[MAX];
struct idx_string *prim;

void main ();
void Alterar ();
void Excluir ();
void Incluir ();
void Pesquisar ();
void Listar_Codigo ();
void Listar_String (struct idx_string *idx);
void Listar_Num ();
void Ordenar_Bubble ();
void Ordenar_Select ();
void Ordenar_Insert ();
void Ordenar_Quick ();
void Preencher_Automatico ();
struct dado * Incluir_Registro (char *string, int num);
struct dado * Pesquisar_String (char *string);
struct dado * Pesquisar_Id (int id);
void Mostrar_Registro (struct dado *x);
int Alterar_Registro (struct dado *x, char *string, int num);
int Excluir_Registro (struct dado *x, char *string);
void realocar_no(struct dado *, struct dado *);

void inicializar()
{
		raiz = (struct dado *) NULL;
		prim = (struct idx_string *) NULL;

		for (int i = 0; i < MAX; i++)
		{
			i_id[i].id = (int) NULL;
			i_id[i].x = (struct dado *) NULL;

			i_num[i].num = (int) NULL;
			i_num[i].x = (struct dado *) NULL;
		}
}

void main() {
	char opcao;
    do{
		//system("clear");
        printf("\nBug Report - Projeto\n--------------------\n");
        printf("\nEscolha a opcao:");
        printf(" \n(1) Incluir");
        printf(" \n(2) Pesquisar");
        printf(" \n(3) Alterar");
        printf(" \n(4) Excluir");
        printf(" \n(5) Listar por Ordem de Inclusao (sem ordenacao)");
        printf(" \n(6) Listar por Ordem de <<campo numerico>> (apos ordenacao)");
        printf(" \n(7) Listar por Ordem Alfabetica de <<campo string>> (em ordem, utilizando indice de string)");
        printf(" \n(8) Recriar indice numerico pelo Metodo Bubble Sort");
        printf(" \n(9) Recriar indice numerico pelo Metodo Selection Sort");
        printf(" \n(10) Recriar indice numerico pelo Metodo Insertion Sort");
        printf(" \n(11) Recriar indice numerico pelo Metodo QuickSort");
        printf(" \n(12) Preenchimento Automatico");
        printf(" \n(0) Sair");
        printf(" \n-----\nSua opcao: [ ]\b\b");
		fflush(stdin);
        opcao = getchar();
        switch(opcao) {
			case '1':
				Incluir();
				break;
			case '2':
				Pesquisar();
				break;
			case '3':
				Alterar();
				break;
			case '4':
				Excluir();
				break;
			case '5':
				Listar_Codigo();
				break;
			case '6':
				Listar_Num();
				break;
			case '7':
				Listar_String(prim);
				break;
			case '8':
				Ordenar_Bubble();
				break;
			case '9':
				Ordenar_Select();
				break;
			case '10':
				Ordenar_Insert();
				break;
			case '11':
				Ordenar_Quick();
				break;
			case '12':
				Preencher_Automatico();
				break;
			default:
	           exit(0);
			   break;
		}
    }
    while (1);
}

void Incluir (){
	/*A função Incluir deve solicitar ao usuário a digitação dos campos da entidade e armazená-los na lista, através do uso da função Incluir_Registro.
	*/

	struct dado * x;
    char nome[100];
    int data = 0;
    printf("\nDigite o nome do projeto que deseja incluir: ");
	fflush(stdin);
    gets(nome);
    if(Pesquisar_String(nome) == (struct dado *)NULL){
   
		printf("\nDigite a Data: ");
		fflush(stdin);
		scanf("%d", &data);
   
		if(Incluir_Registro(nome, data)){
			puts("Inclusao feita com sucesso!");
		}
		else {
			puts("Inclusao nao foi feita.");
		}
	}
	else {
		puts("Projeto ja existente!");
	}
}
void Alterar (){
	/*A função Alterar deve permitir alterar os campos de um registro. A função deve solicitar ao usuário a
digitação do campo string e localizar o registro a ser alterado utilizando a função Pesquisar_String e mostrálo,
utilizando a função Mostrar_Registro. Em seguida, a função deverá solicitar ao usuário a digitação dos
novos valores para os campos, e então chamar a função Alterar_Registro, passando como parâmetro: o
endereço do registro a ser alterado juntamente com os novos valores. A função deverá informar ao usuário
se a alteração foi feita com sucesso.*/
	struct dado * x;
    char nome[100];
    int data = 0;
    printf("\nDigite o nome do projeto que deseja alterar\n");
    fflush(stdin);
	gets(nome);
    x = Pesquisar_String(nome);   
   
    printf("\nDigite o novo Nome: ");
    fflush(stdin);
	gets(nome);
    printf("\nDigite a nova Data: ");
    fflush(stdin);
	scanf("%d", &data);
   
    if(Alterar_Registro(x, nome, data) == 1){
		puts("Alteracao feita com sucesso!");
	}
	else {
		puts("Alteracao nao foi feita.");
	}
}
void Excluir (){
	/*
A função Excluir deve permitir excluir um registro. A função deve solicitar ao usuário a digitação do campo
string e localizar o registro a ser excluído utilizando a função Pesquisar_String e mostrá-lo, utilizando a
função Mostrar_Registro. Em seguida, a função deverá chamar a função Excluir_Registro, passando como
parâmetro o endereço do registro a ser excluído. A função deverá informar ao usuário se a exclusão foi feita
com sucesso.*/
    struct dado * r;
    char nome[100];
    printf("\nDigite o nome do projeto que deseja excluir.\n");
    fflush(stdin);
	gets(nome);
	r = Pesquisar_String(nome);
	
	if(r == (struct dado *)NULL) {
		puts("Nao foi possivel encontrar o projeto.");
	}
	else {
		Mostrar_Registro(r);
		if(Excluir_Registro(r, nome) == 1) {
			puts("Projeto excluido com sucesso!");
		}
		else {
			puts("Nao foi possivel excluir o projeto.");
		}
	}
}
void Pesquisar (){
	/*
	A função Pesquisar deve apresentar um submenu ao usuário com duas opções de pesquisa: por id ou por
	string. O usuário então preenche o id/string desejado para ser pesquisado e, através do uso concomitante
	das funções Pesquisar_String/Pesquisar_Id e MostrarRegistro, devem ser apresentados os dados do
	registro encontrado.
	*/
	int opcao;
	char string[100];
	int id = 0;
	struct dado * r;
	printf("\nDigite a opcao de pesquisa:\n(0) Pesquisar por id\n(1) Pesquisar por string\n");
    fflush(stdin);
	scanf("%d", &opcao);

	if(opcao == 1) {
		printf("\nDigite o nome do projeto que deseja pesquisar: ");
		fflush(stdin);
		gets(string);
		r = Pesquisar_String(string);
		if(r != (struct dado *)NULL) {
			Mostrar_Registro(r);
		}
		else {
			puts("\nNao foi encontrado esse projeto.");
		}
	}
	else {
		printf("\nDigite o ID do projeto que deseja pesquisar: ");
		fflush(stdin);
		scanf("%d", &id);
		r = Pesquisar_Id(id);
		if(r != (struct dado *)NULL) {
			Mostrar_Registro(r);
		}
		else {
			puts("\nNao foi encontrado esse projeto.");
		}
	}
}

struct dado * Incluir_Registro (char * nome, int num){
	/*
	A função Incluir_Registro deve receber como parâmetro os campos da entidade e armazenar esses dados
	ao final da lista encadeada.
	- O campo string (cujo índice é armazenado na árvore binária) não pode se repetir no cadastro, sendo que
	essa consistência deve ser feita mediante consulta ao referido índice;
	- O campo chave primária deve ser gerado automaticamente, obtendo-se o maior código armazenado no
	índice acrescido de 1 (um);
	- O endereço de memória do novo registro deve ser incluído nos três índices.
	- A função deverá retornar o endereço onde o registro foi alocado.*/
	struct dado *novo, *aux, *pai;
	novo = (struct dado *)malloc(sizeof(struct dado));
	if(novo!=(struct dado*)NULL)
	{
		strcpy(novo->string,nome);
		novo->num = num;
		novo->d=novo->e=(struct dado *)NULL;
		if(raiz==(struct dado *)NULL)
			raiz=novo;
		else
		{
			// A função abaixo pode ser usada no lugar
			// dos comandos deste bloco do else
			// realocar_no(raiz,novo);
			aux=raiz;
			while(aux!=(struct dado *)NULL)
			{
				pai=aux;
				if(strcmp(novo->string,aux->string)>=0)
					aux=aux->d;
				else
					aux=aux->e;
			}
			if(strcmp(novo->string,pai->string)>=0)
				pai->d = novo;
			else
				pai->e = novo;
		}
	}
	return novo;
}

void Listar_Codigo (){
	/*A função listar deve listar todos os registros, na ordem em que foram incluídos, percorrendo o índice de
chave primária, e utilizando a função Mostrar_Registro.*/
}

void Listar_String (struct idx_string *idx){
	/*A função Listar_String deve listar todos os registros em ordem alfabética crescente, percorrendo o índice do
campo string e utilizando a função Mostrar_Registro.*/
}

void Listar_Num (){
	/*A função Listar_Num deve listar todos os registros, percorrendo o índice do campo numérico e utilizando a
função Mostrar_Registro*/
}

void Mostrar_Registro (struct dado *x){
	/*A função Mostrar_Registro deve receber como parâmetro um ponteiro para struct dado e apresentar em
	tela todos os campos da entidade, juntamente com o endereço que foi passado como parâmetro.*/

	puts("Nome: ");
	puts(x->string);
	puts("\nData: ");
	printf("%d", x->num);
	puts("\n");
}

struct dado * Pesquisar_String (char *string){
	/*A função Pesquisar_String deve receber o campo string como parâmetro, realizar uma pesquisa no índice
	de árvore binária e retornar o endereço correspondente ao nome pesquisado.*/
	return (struct dado *)NULL;
}

struct dado * Pesquisar_Id (int id){
	/*
	A função Pesquisar_Id deve receber o campo chave primária como parâmetro, realizar uma pesquisa
	binária no referido índice de vetor e retornar o endereço correspondente ao id pesquisado.*/
	return (struct dado *)NULL;
}

int Alterar_Registro (struct dado *x, char *string, int num){
	/*A função Alterar_Registro deve permitir alterar os campos de um registro da lista encadeada, recebidos
como parâmetro. Depois de alterados os dados, os índices devem ser atualizados (com exceção da chave
primária) e a função deve retornar 1 ou 0 indicando se a alteração foi bem sucedida.
Atenção: Alterar um nó de uma árvore binária significa remover o nó existente e incluir o novo nó,
para garantir a integridade da ordem!!!*/
	return 1;
}

int Excluir_Registro (struct dado *x, char * nome){
	/*A função Excluir_Registro deve permitir excluir um registro da lista encadeada, sendo que a busca pelo
registro a ser excluído deve ser feita pelo campo string, fazendo uso da função Pesquisar_String. Depois de
excluído o registro, os três índices devem ser atualizados e a função deve retornar 1 ou 0 indicando se a
alteração foi bem sucedida.*/

	struct dado *aux, *pai, *exc;
	aux=raiz;
	while(aux!=(struct dado*)NULL && strcmp(aux->string,nome)!=0)
	{
		pai=aux;
		if(strcmp(nome,aux->string)>0)
			aux=aux->d;
		else
			aux=aux->e;
	}
	exc=aux;
	// Como raiz não tem pai, o tratamento é diferente
	if(exc==raiz)
	{
		if(raiz->d!=(struct dado*)NULL)
		{
			raiz=exc->d;
			if(exc->e!=(struct dado*)NULL)
				realocar_no(raiz,exc->e);
		}
		else
			raiz=exc->e;
	}
	else
	{
		pai->d=exc->d;
		if(exc->e!=(struct dado*)NULL)
			realocar_no(pai,exc->e);
	}
	//free(exc);
	return 1;
}

void realocar_no(struct dado *origem, struct dado *destino)
{
	struct dado *aux, *pai;
	aux=origem;
	while(aux!=(struct dado*)NULL)
	{
		pai=aux;
		if(strcmp(destino->string,aux->string)>=0)
			aux=aux->d;
		else
			aux=aux->e;
	}
	if(strcmp(destino->string,pai->string)>=0)
		pai->d = destino;
	else
		pai->e = destino;
}

/*Ordenar_Bubble, Ordenar_Selection, Ordenar_Insertion, Ordenar_Quick
Essas funções devem ordenar o índice numérico pelo método correspondente, sendo que, ao final do
processo de ordenação, deverá ser informado ao usuário quantos milissegundos levou o processo de
ordenação. O objetivo é comparar a eficiência dos métodos.*/
void Ordenar_Bubble (){
}
void Ordenar_Select (){
}
void Ordenar_Insert (){
}
void Ordenar_Quick (){
}
void Preencher_Automatico (){
	/*
	A função PreencherAutomatico deve gerar MAX registros com valores aleatórios para os campos da
entidade (com exceção da chave primária), e inseri-los na lista, fazendo uso da função Incluir_Registro.
*/
}
