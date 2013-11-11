#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 5

struct dado {
	int id;
	char string[100];
	int num;
	struct dado *p;
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
	
struct dado *prim;
struct idx_id i_id[MAX];
struct idx_num i_num[MAX];
struct idx_string *raiz;

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
int Excluir_Registro (struct dado *x);
void realocar_no(struct dado *, struct dado *);

void inicializar()
{
		prim = (struct dado *) NULL;
		raiz = (struct idx_string *) NULL;

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
        printf(" \n(8) Recriar �ndice num�rico pelo M�todo Bubble Sort");
        printf(" \n(9) Recriar �ndice num�rico pelo M�todo Selection Sort");
        printf(" \n(10) Recriar �ndice num�rico pelo M�todo Insertion Sort");
        printf(" \n(11) Recriar �ndice num�rico pelo M�todo QuickSort");
        printf(" \n(12) Preenchimento Automatico");
        printf(" \n(0) Sair");
        printf(" \n-----\nSua opcao: [ ]\b\b");
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
				Listar_String();
				break;
			case '8':
				Ordernar_Bubble();
				break;
			case '9':
				Ordernar_Select();
				break;
			case '10':
				Ordenar_Insert();
				break;
			case '11':
				Ordernar_Quick();
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
void Alterar (){
	/*A fun��o Alterar deve permitir alterar os campos de um registro. A fun��o deve solicitar ao usu�rio a
digita��o do campo string e localizar o registro a ser alterado utilizando a fun��o Pesquisar_String e mostr�lo,
utilizando a fun��o Mostrar_Registro. Em seguida, a fun��o dever� solicitar ao usu�rio a digita��o dos
novos valores para os campos, e ent�o chamar a fun��o Alterar_Registro, passando como par�metro: o
endere�o do registro a ser alterado juntamente com os novos valores. A fun��o dever� informar ao usu�rio
se a altera��o foi feita com sucesso.*/
	struct dado * x;
    char * nome;
    char * data;
    printf("\nDigite o nome do projeto que deseja alterar");
    gets(*nome);
    *x = Pesquisar_String(*nome);   
   
    printf("\nDigite o novo Nome:");
    gets(*nome);
    printf("\nDigite a nova Data:");
    scanf("%d", &data);
   
    if(Alterar_Registro(x, *nome, *data) == 1){
		puts("Alteracao feita com sucesso!");
	}
	else {
		puts("Alteracao nao foi feita.");
	}
}
void Excluir (){
	/*
A fun��o Excluir deve permitir excluir um registro. A fun��o deve solicitar ao usu�rio a digita��o do campo
string e localizar o registro a ser exclu�do utilizando a fun��o Pesquisar_String e mostr�-lo, utilizando a
fun��o Mostrar_Registro. Em seguida, a fun��o dever� chamar a fun��o Excluir_Registro, passando como
par�metro o endere�o do registro a ser exclu�do. A fun��o dever� informar ao usu�rio se a exclus�o foi feita
com sucesso.*/
	
    struct dado * r;
    char * nome;
    printf("\nDigite o nome do projeto que deseja excluir.");
    gets(*nome);
	r = Pesquisar_String(*nome);
	
	if(r == (struct dado *)NULL) {
		puts("Nao foi possivel encontrar o projeto.");
	}
	else {
		Mostrar_Registr(r);
		Excluir_Registro(r);
	}
}
void Pesquisar (){
	/*
	A fun��o Pesquisar deve apresentar um submenu ao usu�rio com duas op��es de pesquisa: por id ou por
	string. O usu�rio ent�o preenche o id/string desejado para ser pesquisado e, atrav�s do uso concomitante
	das fun��es Pesquisar_String/Pesquisar_Id e MostrarRegistro, devem ser apresentados os dados do
	registro encontrado.
	*/
	int opcao;
	char string;
	int id;
	printf("\nDigite a opcao de pesquisa:"+
		   "\n(0) Pesquisar por id"+
		   "\n(1) Pesquisar por string");
    scanf("%d", &opcao);

	if(opcao == 0) {
		printf("\nDigite o nome do projeto que deseja pesquisar");
		gets(string);
		MostrarRegistro(Pesquisar_String(string));
	}
	else {
		printf("\nDigite o nome do projeto que deseja pesquisar");
		scanf("%d", &id);
		MostrarRegistro(Pesquisar_Id(id));
	}
}

struct dado * Incluir_Registro (char nome, int num){
	/*
	A fun��o Incluir_Registro deve receber como par�metro os campos da entidade e armazenar esses dados
	ao final da lista encadeada.
	- O campo string (cujo �ndice � armazenado na �rvore bin�ria) n�o pode se repetir no cadastro, sendo que
	essa consist�ncia deve ser feita mediante consulta ao referido �ndice;
	- O campo chave prim�ria deve ser gerado automaticamente, obtendo-se o maior c�digo armazenado no
	�ndice acrescido de 1 (um);
	- O endere�o de mem�ria do novo registro deve ser inclu�do nos tr�s �ndices.
	- A fun��o dever� retornar o endere�o onde o registro foi alocado.*/
	struct dado *novo, *aux, *pai;
	novo = (struct dado *)malloc(sizeof(struct dado));
	if(novo!=(struct dado*)NULL)
	{
		strcpy_s(novo->nome,nome);
		novo->num = num;
		novo->d=novo->e=(struct dado *)NULL;
		if(raiz==(struct dado *)NULL)
			raiz=novo;
		else
		{
			// A fun��o abaixo pode ser usada no lugar
			// dos comandos deste bloco do else
			// realocar_no(raiz,novo);
			aux=raiz;
			while(aux!=(struct dado *)NULL)
			{
				pai=aux;
				if(strcmp(novo->nome,aux->nome)>=0)
					aux=aux->d;
				else
					aux=aux->e;
			}
			if(strcmp(novo->nome,pai->nome)>=0)
				pai->d = novo;
			else
				pai->e = novo;
		}
	}
	return novo;
}

struct dado * Pesquisar_String (char *string){
	return (struct dado *)NULL;
}
struct dado * Pesquisar_Id (int id){
	return (struct dado *)NULL;
}

void Listar_Codigo (){
	/*A fun��o listar deve listar todos os registros, na ordem em que foram inclu�dos, percorrendo o �ndice de
chave prim�ria, e utilizando a fun��o Mostrar_Registro.*/
}

void Listar_String (struct idx_string *idx){
	/*A fun��o Listar_String deve listar todos os registros em ordem alfab�tica crescente, percorrendo o �ndice do
campo string e utilizando a fun��o Mostrar_Registro.*/
}

void Listar_Num (){
	/*A fun��o Listar_Num deve listar todos os registros, percorrendo o �ndice do campo num�rico e utilizando a
fun��o Mostrar_Registro*/
}

void Mostrar_Registro (struct dado *x){
	/*A fun��o Mostrar_Registro deve receber como par�metro um ponteiro para struct dado e apresentar em
	tela todos os campos da entidade, juntamente com o endere�o que foi passado como par�metro.*/
}

struct dado * Pesquisar_String (char *string){
	/*A fun��o Pesquisar_String deve receber o campo string como par�metro, realizar uma pesquisa no �ndice
	de �rvore bin�ria e retornar o endere�o correspondente ao nome pesquisado.*/
	return (struct dado *)NULL;
}

struct dado * Pesquisar_Id (int id){
	/*
	A fun��o Pesquisar_Id deve receber o campo chave prim�ria como par�metro, realizar uma pesquisa
	bin�ria no referido �ndice de vetor e retornar o endere�o correspondente ao id pesquisado.*/
	return (struct dado *)NULL;
}

int Alterar_Registro (struct dado *x, char *string, int num){
	/*A fun��o Alterar_Registro deve permitir alterar os campos de um registro da lista encadeada, recebidos
como par�metro. Depois de alterados os dados, os �ndices devem ser atualizados (com exce��o da chave
prim�ria) e a fun��o deve retornar 1 ou 0 indicando se a altera��o foi bem sucedida.
Aten��o: Alterar um n� de uma �rvore bin�ria significa remover o n� existente e incluir o novo n�,
para garantir a integridade da ordem!!!*/
	return 1;
}

int Excluir_Registro (struct dado *x){
	/*A fun��o Excluir_Registro deve permitir excluir um registro da lista encadeada, sendo que a busca pelo
registro a ser exclu�do deve ser feita pelo campo string, fazendo uso da fun��o Pesquisar_String. Depois de
exclu�do o registro, os tr�s �ndices devem ser atualizados e a fun��o deve retornar 1 ou 0 indicando se a
altera��o foi bem sucedida.*/

	struct no *aux, *pai, *exc;
	aux=raiz;
	while(aux!=(struct no*)NULL && strcmp(aux->nome,nome)!=0)
	{
		pai=aux;
		if(strcmp(nome,aux->nome)>0)
			aux=aux->d;
		else
			aux=aux->e;
	}
	exc=aux;
	// Como raiz n�o tem pai, o tratamento � diferente
	if(exc==raiz)
	{
		if(raiz->d!=(struct no*)NULL)
		{
			raiz=exc->d;
			if(exc->e!=(struct no*)NULL)
				realocar_no(raiz,exc->e);
		}
		else
			raiz=exc->e;
	}
	else
	{
		pai->d=exc->d;
		if(exc->e!=(struct no*)NULL)
			realocar_no(pai,exc->e);
	}
	//free(exc);
	return 1;
}

void realocar_no(struct no *origem, struct no *destino)
{
	struct no *aux, *pai;
	aux=origem;
	while(aux!=(struct no*)NULL)
	{
		pai=aux;
		if(strcmp(destino->nome,aux->nome)>=0)
			aux=aux->d;
		else
			aux=aux->e;
	}
	if(strcmp(destino->nome,pai->nome)>=0)
		pai->d = destino;
	else
		pai->e = destino;
}

void Incluir (){
	/*A fun��o Incluir deve solicitar ao usu�rio a digita��o dos campos da entidade e armazen�-los na lista,
	atrav�s do uso da fun��o Incluir_Registro.
	*/
}

/*Ordenar_Bubble, Ordenar_Selection, Ordenar_Insertion, Ordenar_Quick
Essas fun��es devem ordenar o �ndice num�rico pelo m�todo correspondente, sendo que, ao final do
processo de ordena��o, dever� ser informado ao usu�rio quantos milissegundos levou o processo de
ordena��o. O objetivo � comparar a efici�ncia dos m�todos.*/
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
	A fun��o PreencherAutomatico deve gerar MAX registros com valores aleat�rios para os campos da
entidade (com exce��o da chave prim�ria), e inseri-los na lista, fazendo uso da fun��o Incluir_Registro.
*/
}