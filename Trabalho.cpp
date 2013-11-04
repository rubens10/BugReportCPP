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
        printf(" \n(8) Recriar Índice numérico pelo Método Bubble Sort");
        printf(" \n(9) Recriar Índice numérico pelo Método Selection Sort");
        printf(" \n(10) Recriar Índice numérico pelo Método Insertion Sort");
        printf(" \n(11) Recriar Índice numérico pelo Método QuickSort");
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
	/*A função Alterar deve permitir alterar os campos de um registro. A função deve solicitar ao usuário a
digitação do campo string e localizar o registro a ser alterado utilizando a função Pesquisar_String e mostrálo,
utilizando a função Mostrar_Registro. Em seguida, a função deverá solicitar ao usuário a digitação dos
novos valores para os campos, e então chamar a função Alterar_Registro, passando como parâmetro: o
endereço do registro a ser alterado juntamente com os novos valores. A função deverá informar ao usuário
se a alteração foi feita com sucesso.*/
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
A função Excluir deve permitir excluir um registro. A função deve solicitar ao usuário a digitação do campo
string e localizar o registro a ser excluído utilizando a função Pesquisar_String e mostrá-lo, utilizando a
função Mostrar_Registro. Em seguida, a função deverá chamar a função Excluir_Registro, passando como
parâmetro o endereço do registro a ser excluído. A função deverá informar ao usuário se a exclusão foi feita
com sucesso.*/

    char * nome;
    printf("\nDigite o nome do registro que deseja excluir");
    gets(*nome);
    ExcluirRegistro(PesquisarRegistroNome(*nome));
}
void Pesquisar (){
/*
A função Pesquisar deve apresentar um submenu ao usuário com duas opções de pesquisa: por id ou por
string. O usuário então preenche o id/string desejado para ser pesquisado e, através do uso concomitante
das funções Pesquisar_String/Pesquisar_Id e MostrarRegistro, devem ser apresentados os dados do
registro encontrado.
*/
}

struct dado * Incluir_Registro (char *string, int num){
	/*
	A função Incluir_Registro deve receber como parâmetro os campos da entidade e armazenar esses dados
	ao final da lista encadeada.
	- O campo string (cujo índice é armazenado na árvore binária) não pode se repetir no cadastro, sendo que
	essa consistência deve ser feita mediante consulta ao referido índice;
	- O campo chave primária deve ser gerado automaticamente, obtendo-se o maior código armazenado no
	índice acrescido de 1 (um);
	- O endereço de memória do novo registro deve ser incluído nos três índices.
	- A função deverá retornar o endereço onde o registro foi alocado.*/
	return (struct dado *)NULL;
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
	/*
	A função Mostrar_Registro deve receber como parâmetro um ponteiro para struct dado e apresentar em
	tela todos os campos da entidade, juntamente com o endereço que foi passado como parâmetro.
	*/
}

struct dado * Pesquisar_String (char *string){
/*
A função Pesquisar_String deve receber o campo string como parâmetro, realizar uma pesquisa no índice
de árvore binária e retornar o endereço correspondente ao nome pesquisado.*/
}

struct dado * Pesquisar_Id (int id){
/*
A função Pesquisar_Id deve receber o campo chave primária como parâmetro, realizar uma pesquisa
binária no referido índice de vetor e retornar o endereço correspondente ao id pesquisado.*/
}

int Alterar_Registro (struct dado *x, char *string, int num){
/*A função Alterar_Registro deve permitir alterar os campos de um registro da lista encadeada, recebidos
como parâmetro. Depois de alterados os dados, os índices devem ser atualizados (com exceção da chave
primária) e a função deve retornar 1 ou 0 indicando se a alteração foi bem sucedida.
Atenção: Alterar um nó de uma árvore binária significa remover o nó existente e incluir o novo nó,
para garantir a integridade da ordem!!!*/
}

int Excluir_Registro (struct dado *x); (valor: 1.5 pt)

/*A função Excluir_Registro deve permitir excluir um registro da lista encadeada, sendo que a busca pelo
registro a ser excluído deve ser feita pelo campo string, fazendo uso da função Pesquisar_String. Depois de
excluído o registro, os três índices devem ser atualizados e a função deve retornar 1 ou 0 indicando se a
alteração foi bem sucedida.*/
}

void Incluir (){
/*A função Incluir deve solicitar ao usuário a digitação dos campos da entidade e armazená-los na lista,
através do uso da função Incluir_Registro.
*/
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