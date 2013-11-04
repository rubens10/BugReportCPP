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

void main (void);
void Alterar (void);
void Excluir (void);
void Pesquisar (void);
void Listar_Codigo (void);
void Listar_String (struct idx_string *idx);
void Listar_Num (void);
void Incluir (void);
void Ordenar_Bubble (void);
void Ordenar_Select (void);
void Ordenar_Insert (void);
void Ordenar_Quick (void);
void Preencher_Automatico (void);
struct dado * Incluir_Registro (char *string, int num);
struct dado * Pesquisar_String (char *string);
struct dado * Pesquisar_Id (int id);
void Mostrar_Registro (struct dado *x);
int Alterar_Registro (struct dado *x, char *string, int num);
int Excluir_Registro (struct dado *x);

void inicializar()
{
		prim = (struct dado *) NULL;
		raiz = (struct idx_string *) NULL;

		for (int i = 0; i < MAX; i++)
		{
			i_id[i].id = (int) NULL;
			i_id[~i].x = (struct dado *) NULL;

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
        printf(" \n(6) Listar por Ordem de <<campo numerico>> (apos ordenacao");
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
		}
        if(opcao == '0')
            exit(0);
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
	no * x;
    char * nome;
    char * telefone;
    printf("\nDigite o nome do registro que deseja alterar");
    gets(*nome);
    *x = Pesquisar_String(*nome);   
   
    printf("\nDigite o novo Nome:");
    gets(*nome);
    printf("\nDigite o novo Telefone:");
    scanf("%d", &telefone);
   
    Alterar_Registro(x, *nome, * telefone);
}
void Excluir (){
	/*
A fun��o Excluir deve permitir excluir um registro. A fun��o deve solicitar ao usu�rio a digita��o do campo
string e localizar o registro a ser exclu�do utilizando a fun��o Pesquisar_String e mostr�-lo, utilizando a
fun��o Mostrar_Registro. Em seguida, a fun��o dever� chamar a fun��o Excluir_Registro, passando como
par�metro o endere�o do registro a ser exclu�do. A fun��o dever� informar ao usu�rio se a exclus�o foi feita
com sucesso.*/

    char * nome;
    printf("\nDigite o nome do registro que deseja excluir");
    gets(*nome);
    ExcluirRegistro(PesquisarRegistroNome(*nome));
}
void Pesquisar (){
/*
A fun��o Pesquisar deve apresentar um submenu ao usu�rio com duas op��es de pesquisa: por id ou por
string. O usu�rio ent�o preenche o id/string desejado para ser pesquisado e, atrav�s do uso concomitante
das fun��es Pesquisar_String/Pesquisar_Id e MostrarRegistro, devem ser apresentados os dados do
registro encontrado.
*/
}

struct dado * Incluir_Registro (char *string, int num){
	/*
	A fun��o Incluir_Registro deve receber como par�metro os campos da entidade e armazenar esses dados
	ao final da lista encadeada.
	- O campo string (cujo �ndice � armazenado na �rvore bin�ria) n�o pode se repetir no cadastro, sendo que
	essa consist�ncia deve ser feita mediante consulta ao referido �ndice;
	- O campo chave prim�ria deve ser gerado automaticamente, obtendo-se o maior c�digo armazenado no
	�ndice acrescido de 1 (um);
	- O endere�o de mem�ria do novo registro deve ser inclu�do nos tr�s �ndices.
	- A fun��o dever� retornar o endere�o onde o registro foi alocado.*/
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
	/*
	A fun��o Mostrar_Registro deve receber como par�metro um ponteiro para struct dado e apresentar em
	tela todos os campos da entidade, juntamente com o endere�o que foi passado como par�metro.
	*/
}

struct dado * Pesquisar_String (char *string){
/*
A fun��o Pesquisar_String deve receber o campo string como par�metro, realizar uma pesquisa no �ndice
de �rvore bin�ria e retornar o endere�o correspondente ao nome pesquisado.*/
}

struct dado * Pesquisar_Id (int id){
/*
A fun��o Pesquisar_Id deve receber o campo chave prim�ria como par�metro, realizar uma pesquisa
bin�ria no referido �ndice de vetor e retornar o endere�o correspondente ao id pesquisado.*/
}

int Alterar_Registro (struct dado *x, char *string, int num){
/*A fun��o Alterar_Registro deve permitir alterar os campos de um registro da lista encadeada, recebidos
como par�metro. Depois de alterados os dados, os �ndices devem ser atualizados (com exce��o da chave
prim�ria) e a fun��o deve retornar 1 ou 0 indicando se a altera��o foi bem sucedida.
Aten��o: Alterar um n� de uma �rvore bin�ria significa remover o n� existente e incluir o novo n�,
para garantir a integridade da ordem!!!*/
}

int Excluir_Registro (struct dado *x); (valor: 1.5 pt)

/*A fun��o Excluir_Registro deve permitir excluir um registro da lista encadeada, sendo que a busca pelo
registro a ser exclu�do deve ser feita pelo campo string, fazendo uso da fun��o Pesquisar_String. Depois de
exclu�do o registro, os tr�s �ndices devem ser atualizados e a fun��o deve retornar 1 ou 0 indicando se a
altera��o foi bem sucedida.*/
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