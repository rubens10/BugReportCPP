void main() {
	/*
	A fun��o main (ou fun��o principal) deve contemplar apenas o trecho de c�digo necess�rio para
apresenta��o do menu das fun��es a serem executadas, conforme segue:
1) Incluir
2) Pesquisar
3) Alterar
4) Excluir
5) Listar por Ordem de Inclus�o (sem ordena��o, utilizando chave prim�ria - id)
6) Listar por Ordem de <<campo num�rico>> (ap�s ordena��o, utilizando �ndice de campo num�rico)
7) Listar por Ordem Alfab�tica de <<campo string>> (em ordem, utilizando �ndice de string)
8) Recriar �ndice num�rico pelo M�todo Bubble Sort
9) Recriar �ndice num�rico pelo M�todo Selection Sort
10) Recriar �ndice num�rico pelo M�todo Insertion Sort
11) Recriar �ndice num�rico pelo M�todo QuickSort
12) Preenchimento Autom�tico
0) Sair
*/
}
void Alterar (void){
	/*A fun��o Alterar deve permitir alterar os campos de um registro. A fun��o deve solicitar ao usu�rio a
digita��o do campo string e localizar o registro a ser alterado utilizando a fun��o Pesquisar_String e mostr�lo,
utilizando a fun��o Mostrar_Registro. Em seguida, a fun��o dever� solicitar ao usu�rio a digita��o dos
novos valores para os campos, e ent�o chamar a fun��o Alterar_Registro, passando como par�metro: o
endere�o do registro a ser alterado juntamente com os novos valores. A fun��o dever� informar ao usu�rio
se a altera��o foi feita com sucesso.*/
}
void Excluir (void){
	/*
A fun��o Excluir deve permitir excluir um registro. A fun��o deve solicitar ao usu�rio a digita��o do campo
string e localizar o registro a ser exclu�do utilizando a fun��o Pesquisar_String e mostr�-lo, utilizando a
fun��o Mostrar_Registro. Em seguida, a fun��o dever� chamar a fun��o Excluir_Registro, passando como
par�metro o endere�o do registro a ser exclu�do. A fun��o dever� informar ao usu�rio se a exclus�o foi feita
com sucesso.*/
}
/*Pesquisar
A fun��o Pesquisar deve apresentar um submenu ao usu�rio com duas op��es de pesquisa: por id ou por
string. O usu�rio ent�o preenche o id/string desejado para ser pesquisado e, atrav�s do uso concomitante
das fun��es Pesquisar_String/Pesquisar_Id e MostrarRegistro, devem ser apresentados os dados do
registro encontrado.
*/

/*
Incluir_Registro
A fun��o Incluir_Registro deve receber como par�metro os campos da entidade e armazenar esses dados
ao final da lista encadeada.
- O campo string (cujo �ndice � armazenado na �rvore bin�ria) n�o pode se repetir no cadastro, sendo que
essa consist�ncia deve ser feita mediante consulta ao referido �ndice;
- O campo chave prim�ria deve ser gerado automaticamente, obtendo-se o maior c�digo armazenado no
�ndice acrescido de 1 (um);
- O endere�o de mem�ria do novo registro deve ser inclu�do nos tr�s �ndices.
- A fun��o dever� retornar o endere�o onde o registro foi alocado.*/
void Listar_Codigo (void){
	/*A fun��o listar deve listar todos os registros, na ordem em que foram inclu�dos, percorrendo o �ndice de
chave prim�ria, e utilizando a fun��o Mostrar_Registro.*/
}
void Listar_String (struct idx_string *idx){
	/*A fun��o Listar_String deve listar todos os registros em ordem alfab�tica crescente, percorrendo o �ndice do
campo string e utilizando a fun��o Mostrar_Registro.*/
}
void Listar_Num (void){
	/*A fun��o Listar_Num deve listar todos os registros, percorrendo o �ndice do campo num�rico e utilizando a
fun��o Mostrar_Registro*/
}
/*
Mostrar_Registro
A fun��o Mostrar_Registro deve receber como par�metro um ponteiro para struct dado e apresentar em
tela todos os campos da entidade, juntamente com o endere�o que foi passado como par�metro.
*/
/*
Pesquisar_String
A fun��o Pesquisar_String deve receber o campo string como par�metro, realizar uma pesquisa no �ndice
de �rvore bin�ria e retornar o endere�o correspondente ao nome pesquisado.
Pesquisar_Id
A fun��o Pesquisar_Id deve receber o campo chave prim�ria como par�metro, realizar uma pesquisa
bin�ria no referido �ndice de vetor e retornar o endere�o correspondente ao id pesquisado.
Alterar_Registro
A fun��o Alterar_Registro deve permitir alterar os campos de um registro da lista encadeada, recebidos
como par�metro. Depois de alterados os dados, os �ndices devem ser atualizados (com exce��o da chave
prim�ria) e a fun��o deve retornar 1 ou 0 indicando se a altera��o foi bem sucedida.
Aten��o: Alterar um n� de uma �rvore bin�ria significa remover o n� existente e incluir o novo n�,
para garantir a integridade da ordem!!!
Excluir_Registro
A fun��o Excluir_Registro deve permitir excluir um registro da lista encadeada, sendo que a busca pelo
registro a ser exclu�do deve ser feita pelo campo string, fazendo uso da fun��o Pesquisar_String. Depois de
exclu�do o registro, os tr�s �ndices devem ser atualizados e a fun��o deve retornar 1 ou 0 indicando se a
altera��o foi bem sucedida.
Incluir
A fun��o Incluir deve solicitar ao usu�rio a digita��o dos campos da entidade e armazen�-los na lista,
atrav�s do uso da fun��o Incluir_Registro.
*/
/*Ordenar_Bubble, Ordenar_Selection, Ordenar_Insertion, Ordenar_Quick
Essas fun��es devem ordenar o �ndice num�rico pelo m�todo correspondente, sendo que, ao final do
processo de ordena��o, dever� ser informado ao usu�rio quantos milissegundos levou o processo de
ordena��o. O objetivo � comparar a efici�ncia dos m�todos.*/
void Ordenar_Bubble (void){
}
void Ordenar_Select (void){
}
void Ordenar_Insert (void){
}
void Ordenar_Quick (void){
}
void Preencher_Automatico (void){
	/*
	A fun��o PreencherAutomatico deve gerar MAX registros com valores aleat�rios para os campos da
entidade (com exce��o da chave prim�ria), e inseri-los na lista, fazendo uso da fun��o Incluir_Registro.
*/
}