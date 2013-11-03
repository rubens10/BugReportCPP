void main() {
	/*
	A função main (ou função principal) deve contemplar apenas o trecho de código necessário para
apresentação do menu das funções a serem executadas, conforme segue:
1) Incluir
2) Pesquisar
3) Alterar
4) Excluir
5) Listar por Ordem de Inclusão (sem ordenação, utilizando chave primária - id)
6) Listar por Ordem de <<campo numérico>> (após ordenação, utilizando índice de campo numérico)
7) Listar por Ordem Alfabética de <<campo string>> (em ordem, utilizando índice de string)
8) Recriar Índice numérico pelo Método Bubble Sort
9) Recriar Índice numérico pelo Método Selection Sort
10) Recriar Índice numérico pelo Método Insertion Sort
11) Recriar Índice numérico pelo Método QuickSort
12) Preenchimento Automático
0) Sair
*/
}
void Alterar (void){
	/*A função Alterar deve permitir alterar os campos de um registro. A função deve solicitar ao usuário a
digitação do campo string e localizar o registro a ser alterado utilizando a função Pesquisar_String e mostrálo,
utilizando a função Mostrar_Registro. Em seguida, a função deverá solicitar ao usuário a digitação dos
novos valores para os campos, e então chamar a função Alterar_Registro, passando como parâmetro: o
endereço do registro a ser alterado juntamente com os novos valores. A função deverá informar ao usuário
se a alteração foi feita com sucesso.*/
}
void Excluir (void){
	/*
A função Excluir deve permitir excluir um registro. A função deve solicitar ao usuário a digitação do campo
string e localizar o registro a ser excluído utilizando a função Pesquisar_String e mostrá-lo, utilizando a
função Mostrar_Registro. Em seguida, a função deverá chamar a função Excluir_Registro, passando como
parâmetro o endereço do registro a ser excluído. A função deverá informar ao usuário se a exclusão foi feita
com sucesso.*/
}
/*Pesquisar
A função Pesquisar deve apresentar um submenu ao usuário com duas opções de pesquisa: por id ou por
string. O usuário então preenche o id/string desejado para ser pesquisado e, através do uso concomitante
das funções Pesquisar_String/Pesquisar_Id e MostrarRegistro, devem ser apresentados os dados do
registro encontrado.
*/

/*
Incluir_Registro
A função Incluir_Registro deve receber como parâmetro os campos da entidade e armazenar esses dados
ao final da lista encadeada.
- O campo string (cujo índice é armazenado na árvore binária) não pode se repetir no cadastro, sendo que
essa consistência deve ser feita mediante consulta ao referido índice;
- O campo chave primária deve ser gerado automaticamente, obtendo-se o maior código armazenado no
índice acrescido de 1 (um);
- O endereço de memória do novo registro deve ser incluído nos três índices.
- A função deverá retornar o endereço onde o registro foi alocado.*/
void Listar_Codigo (void){
	/*A função listar deve listar todos os registros, na ordem em que foram incluídos, percorrendo o índice de
chave primária, e utilizando a função Mostrar_Registro.*/
}
void Listar_String (struct idx_string *idx){
	/*A função Listar_String deve listar todos os registros em ordem alfabética crescente, percorrendo o índice do
campo string e utilizando a função Mostrar_Registro.*/
}
void Listar_Num (void){
	/*A função Listar_Num deve listar todos os registros, percorrendo o índice do campo numérico e utilizando a
função Mostrar_Registro*/
}
/*
Mostrar_Registro
A função Mostrar_Registro deve receber como parâmetro um ponteiro para struct dado e apresentar em
tela todos os campos da entidade, juntamente com o endereço que foi passado como parâmetro.
*/
/*
Pesquisar_String
A função Pesquisar_String deve receber o campo string como parâmetro, realizar uma pesquisa no índice
de árvore binária e retornar o endereço correspondente ao nome pesquisado.
Pesquisar_Id
A função Pesquisar_Id deve receber o campo chave primária como parâmetro, realizar uma pesquisa
binária no referido índice de vetor e retornar o endereço correspondente ao id pesquisado.
Alterar_Registro
A função Alterar_Registro deve permitir alterar os campos de um registro da lista encadeada, recebidos
como parâmetro. Depois de alterados os dados, os índices devem ser atualizados (com exceção da chave
primária) e a função deve retornar 1 ou 0 indicando se a alteração foi bem sucedida.
Atenção: Alterar um nó de uma árvore binária significa remover o nó existente e incluir o novo nó,
para garantir a integridade da ordem!!!
Excluir_Registro
A função Excluir_Registro deve permitir excluir um registro da lista encadeada, sendo que a busca pelo
registro a ser excluído deve ser feita pelo campo string, fazendo uso da função Pesquisar_String. Depois de
excluído o registro, os três índices devem ser atualizados e a função deve retornar 1 ou 0 indicando se a
alteração foi bem sucedida.
Incluir
A função Incluir deve solicitar ao usuário a digitação dos campos da entidade e armazená-los na lista,
através do uso da função Incluir_Registro.
*/
/*Ordenar_Bubble, Ordenar_Selection, Ordenar_Insertion, Ordenar_Quick
Essas funções devem ordenar o índice numérico pelo método correspondente, sendo que, ao final do
processo de ordenação, deverá ser informado ao usuário quantos milissegundos levou o processo de
ordenação. O objetivo é comparar a eficiência dos métodos.*/
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
	A função PreencherAutomatico deve gerar MAX registros com valores aleatórios para os campos da
entidade (com exceção da chave primária), e inseri-los na lista, fazendo uso da função Incluir_Registro.
*/
}