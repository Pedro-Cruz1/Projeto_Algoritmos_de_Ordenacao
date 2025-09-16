#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <locale.h>

//Fun��o particiona que divide o vetor em 2 partes, vai colocar 1 elemento na posi��o correta e dividir o resto (usada no quick)
int particionaETroca(int *v, int inicio, int fim){ //A fun��o � int pq precisa retornar o �ndice do elemento que foi colocado na posi��o correta

int pivo = (v[inicio] + v[fim] + v[(inicio+fim)/2])/3; //Piv� � a m�dia aritm�tica dos elementos inicial, central e final do vetor


while(inicio<fim){  //Enquanto o inicio for menor que o fim, as trocas ser�o executadas

    while(inicio<fim && v[inicio] <= pivo){ //Do in�cio para o meio, encontrar um elemento que seja maior que o piv�
        inicio = inicio + 1;
    }
    while(inicio<fim && v[fim] > pivo){ //Do meio para o fim, encontrar um elemento que seja menor que o piv�
        fim = fim - 1;
    }

    //Trocar os 2 elementos encontrados (menor e maior que o piv�)

    int aux = v[inicio]; //
    v[inicio] = v[fim];  // A troca � realizada
    v[fim] = aux;        //
}

//Quando o while falhar, o inicio � retornado e usado na fun��o do quick sort

return inicio; //O retorno vai acabar sendo o elemento do meio do vetor, que j� est� na posi��o correta
}

int particionaETroca_PI(int *v, int inicio, int fim) {

    int pivo = v[inicio]; //piv� definido como in�cio (primeiro elemento do vetor ou subvetor)

    int i = inicio + 1; //logo ap�s o piv�, procura elementos menores
    int j = fim;        //no final do subvetor, procura elementos maiores

    while (i <= j) {    //repeti��o enquanto i e j n�o se cruzarem (o cruzamento indicaria que a parti��o foi completa)
        while (i <= j && v[i] <= pivo) { //avan�a o i para a direita enquanto os elementos na posi��o i forem menores ou iguais ao piv�
            i = i + 1;
        }

        while (i <= j && v[j] > pivo) { //avan�a o j para a esquerda enquanto os elementos na posi��o j forem maiores ao piv�
            j = j - 1;
        }

        if (i < j) {    //verifica se ainda n�o h� cruzamento entre i e j
            int aux = v[i]; //
            v[i] = v[j];    // troca
            v[j] = aux;     //
        }
    }

//Reposicionando o piv�, pois depois que i e j se cruzam, os elementos � esquerda de j s�o menores e os � direita s�o maiores
    v[inicio] = v[j];  //O elemento na posi��o inicial do vetor (onde o piv� estava temporariamente) � movido para j
    v[j] = pivo;       //O elemento na posi��o inicial do vetor (onde o piv� estava temporariamente) � movido para j

    return j;   //�ndice final do piv� ap�s todas as trocas e ajustes, usado na recurs�o do quick
}

int particionaETroca_PR(int *v, int inicio, int fim){ //A fun��o � int pq precisa retornar o �ndice do elemento que foi colocado na posi��o correta


int posAleatoria = inicio + rand() % (fim - inicio + 1); //Gerar uma posi��o aleat�ria entre o inicio e o fim do vetor
//O int anterior s� � usado quando o pivo � uma posi��o aleat�ria

// Trocar o valor do piv� aleat�rio para o in�cio
int aux = v[inicio];
v[inicio] = v[posAleatoria];
v[posAleatoria] = aux;

int pivo = v[inicio]; //Piv� inicializado sempre como uma posi��o aleat�ria (usando a mesma forma do pivo no inicio)


//Em suma, o que vai acontecer �: o vetor vai ser inicializado, e um valor aleat�rio do vetor ser� escolhido como piv�
//Ent�o, este valor ser� movido para o in�cio, trocando os 2 valores de lugar, e ent�o o procedimento iniciar� propriamente
//Em ess�ncia, � o procedimento com piv� no in�cio, mas o valor do in�cio � gerado aleatoriamente


int i = inicio + 1; //Ser� usado para percorrer o vetor a partir do segundo elemento (inicio+1)
int j = fim; //Ser� usado para percorrer o vetor a partir do fim

while(i<=j){  //Enquanto o inicio for menor que o fim, as trocas ser�o executadas

    while(i<=j && v[i] <= pivo){ //Do in�cio para o meio, encontrar um elemento que seja maior que o piv�
        i = i + 1;
    }
    while(i<=j && v[j] > pivo){ //Do meio para o fim, encontrar um elemento que seja menor que o piv�
        j = j - 1;
    }

    //Trocar os 2 elementos encontrados (menor e maior que o piv�)

    if(i<j){    // Se i est� � esquerda de j, ambos os �ndices encontraram valores inconsistentes (v[i] � maior que o piv� e deveria estar � direita, e v[j] � menor que o piv�, e deveria estar � direita)

    int aux2 = v[i];    //
    v[i] = v[j];        // A troca � realizada
    v[j] = aux2;        //
    }
}

//Quando o while falhar, o j � retornado e usado na recurs�o

//Reposicionando o piv�, pois depois que i e j se cruzam, os elementos � esquerda de j s�o menores e os � direita s�o maiores
v[inicio] = v[j]; //O elemento na posi��o inicial do vetor (onde o piv� estava temporariamente) � movido para j
v[j] = pivo;    //O valor do piv� � colocado na posi��o correta (j)


return j; //O retorno vai acabar sendo a posi��o final do piv� no vetor
}

int parent(int i){ //usada apenas no increase key

return (i - 1) / 2;
}

void MIN_heapify(int *v, int tam, int i){

int menor = i; //�ndice do menor elemento (in�cio)
int L = (2*i + 1);  //Se considerar que um vetor come�a em 0, ent�o faz sentido ser 2*i + 1, e n�o apenas 2i
int R = (2*i + 2);

//verificando se o menor � o filho da esquerda
if(L < tam && v[L] < v[menor]){

    menor = L; //Se �, o menor item passa a ser o da esquerda
}

//verificando se o menor � o filho da direita
if(R < tam && v[R] < v[menor]){

    menor = R; //Se �, o menor item passa a ser o da direita
}

// Se o menor n�o for o pr�prio i, faz a troca e continua o processo recursivamente
if (menor != i) {

    int aux = v[i];  //
    v[i] = v[menor]; // troca usando aux
    v[menor] = aux;  //

    MIN_heapify(v, tam, menor); // Chamada recursiva
}
}

void build_heap_minimum(int *v, int tam){

// Come�a do �ltimo n� interno e aplica MIN-HEAPIFY at� a raiz
for (int i = (tam / 2) - 1; i >= 0; i--) { //Um n� interno � um n� que possui ao menos 1 filho, � (tam/2) - 1 pq, para encontrar
//o pai do �ltimo n� filho, pode-se usar a f�rmula inversa dos filhos, por exemplo, para o filho da esquerda, 2*i + 1 = tam - 1 -> i = (tam - 2)/2, notando-se o padr�o (tam/2) - 1
    MIN_heapify(v, tam, i); //Aplica��o do heapify para organizar a sub�rvore
    }
}

int heap_extract_min(int *v, int *tam){

//Se o heap for 0
if (*tam < 1) {
        printf("Erro: o heap est� vazio.\n");
        return 0;
    }
    //Menor elemento � a raiz do heap
    int min = v[0];

    v[0] = v[*tam - 1]; //Substitui a raiz pelo �ltimo elemento do heap

    *tam = *tam - 1; //Reduzir o tamanho do heap

    MIN_heapify(v, *tam, 0); //Reorganizar o heap


    // Retorna o menor elemento extra�do
    return min;
}

void heap_increase_key(int *v, int i, int chave){

 if (chave < v[i]) {
        printf("Erro: a nova chave %d � menor que a chave atual %d\n", chave, v[i]);
        return;
    }

    v[i] = chave;

    // Reorganiza o heap para cima
    while (i > 0 && v[parent(i)] < v[i]) {
        // Troca o elemento atual com seu pai
        int aux = v[i];
        v[i] = v[parent(i)];
        v[parent(i)] = aux;

        i = parent(i);
    }
}

void MAX_heap_insert(int *v, int *tam, int chave){

(*tam)++; //Aumentando o tamanho do heap em 1
v[*tam - 1] = -1; //Inicializando a nova posi��o com o valor -1, que nunca � usado
heap_increase_key(v, *tam - 1, chave); // Ajusta o novo elemento com a chave
}

void inS(int *v, int tam){          //Fun��o inS que recebe um vetor de inteiros (ponteiro) e o tamanho deste

    int i, j;                       //vari�veis de controle do loop
    for (i = 1; i < tam; i++){      // i � o n�mero da posi��o, que incrementa de 1 em 1, e considerando que come�a em 0, o tamanho de um vetor de 0 at� 19 � 20, ent�o i deve ser menor que o tamanho m�ximo
        // compara��o com o elemento anterior
        int aux, j = i;             //Armazena o valor atual em 'aux' e inicializa 'j' com o valor de 'i'
        aux = v[j];                 //c�pia do que estiver dentro da posi��o do vetor para aux
        while(j>0 && aux<v[j-1]){   //se aux for menor que o item no vetor atual, ele regrede posi��es at� encontrar um que n�o o seja

        // o while move os elementos maiores para a direita, criando espa�o para alocar o aux

            v[j] = v[j-1];  //Deslocando o maior valor para a direita
            j --;           //Decrementa j, fazendo com que compare com o elemento anterior
        }
        v[j] = aux;         //Valor de aux � inserido na posi��o correta
    }

}

void bubS(int *v, int tam){

int i, j, aux;

for (j=0; j<tam; j++){ //O que este for faz � fazer com que o segundo seja executado um n�mero de vezes igual ao tamanho do vetor

    for(i=0; i<tam-1; i++){ //O motivo pela qual � at� "tam-1" � pq esse for para na pen�ltima posi��o, j� que ele vai ler a posi��o seguinte, e n�o h� nada ap�s a �ltima posi��o

            if(v[i] > v[i+1]){  //Se o dado de tal posi��o for maior que o da posi��o seguinte

                //As 3 linhas de c�digo a seguir s�o a troca em si
                int aux = v[i]; //Aux recebe o valor do vetor na posi��o i
                v[i] = v[i+1];  //O vetor na posi��o i recebe o valor da posi��o seguinte, que � menor
                v[i+1] = aux;   //O vetor na posi��o seguinte recebe o valor de aux, que estava na posi��o anterior
            }
    }
}tam--;  //Vai diminuir a quantia de casas a serem percorridas, � medida que o algoritmo for rodando, talvez d� um problema quando colocar o decrescente, ent�o vou deixar s� comentado

}

void selS(int *v, int tam){

int i, j, aux, menor; //A vari�vel menor vai armazenar o menor valor encontrado no vetor, e quando a hora chegar, vai trocar seu valor com outra posi��o do vetor

for(i=0; i<tam; i++){ //Vai percorrer o vetor e "fixar" a posi��o em que o menor valor encontrado ser� colocado

    menor = i; //menor vai estar sempre recebendo o valor da posi��o atual do vetor, j� que o valor de i � atualizado

    for(j=i+1; j<tam; j++){ //Busca o menor valor entre os elementos que ainda n�o foram ordenados

        if(v[j]< v[menor]){

            menor = j; //Quando encontra um valor menor, atualiza o valor de menor para j (o novo valor encontrado)
        }
    }
    aux = v[i];      //
    v[i] = v[menor]; // Troca
    v[menor] = aux;  //

}
}

void shS(int *v, int tam){

int i, j, aux;

//O shell sort existe a execu��o de um procedimento matem�tico mais complexo que envolve logaritmos, descrito a seguir
float k = log(tam+1)/log(3);    //C�lculo do n�mero de varreduras
k = floor(k+0.5); //Acrescenta 0,5 e faz o arredondamento para baixo

int h = (pow(3,k)-1)/2; //C�lculo da dist�ncia no vetor para a varredura

while (h>0){        //La�o de varreduras, inicia a varredura se a dist�ncia h for maior que zero

    for(i=0; i<tam-h; i++){ //La�o para percorrer, vai at� a posi��o anterior a tam-h

        if(v[i]>v[i+h]){    //Compara o item i com o item que est� a uma dist�ncia h

                aux = v[i+h];   //
                v[i+h] = v[i];  // Esse bloco realiza a troca do conte�do das posi��es do vetor
                v[i] = aux;     //

                j = i-h; // j recebe o �ndice do item anterior, para come�ar o la�o interno
                while(j>=0){    // Realiza a varredura no sentido contr�rio

                    if(aux<v[j]){ //Compara��o de aux com o item j, se for menor, faz a troca, se n�o, abandona o while

                        v[j+h] = v[j]; //
                        v[j] = aux;    // Substitui��es
                    }
                    else{

                        break;
                    }
                    j = j-h; //Caso uma troca tenha ocorrido, j ser� subtra�do pelo valor de h, para que aux seja comparado com o item anterior, dando continuidade � varredura contr�ria
                }
        }
    } h = (h-1)/3; // Ap�s a varredura do for, diminui a dist�ncia h para a pr�xima varredura. Se h for menor que 1, o processo ser� finalizado

}
}

void mS(int *v, int *aux, int inicio, int fim){

int meio, i, j, k;

if(inicio<fim){  //Chama a fun��o at� que o tamanho e o fim sejam iguais, ou seja, 0

    meio = ((inicio + fim)/2); //Calcula qual � a metade do vetor

    //Essa parte a seguir, basicamente divide os dados
    mS(v, aux, inicio, meio);    // Chama a fun��o para a primeira parte do vetor (in�cio at� o meio)
    mS(v, aux, meio+1, fim);     // Chama a fun��o para a segunda parte do vetor (meio+1 at� o final)

    //Aplica��o do merge (orgena��o das partes)


    i = inicio;     //�ndice para percorrer a primeira metade do vetor
    j = meio + 1;   //�ndice para percorrer a segunda metade do vetor
    k = inicio;     //�ndice para percorrer o vetor auxiliar

    //Combina��o das partes de maneira ordenada, em um vetor auxiliar
    while(i <= meio && j<= fim){ //Enquanto ainda tiver elementos nas partes

        if(v[i] < v[j]){ //Percorre a primeira metade

            aux[k] = v[i]; //Menor elemento � colocado no vetor auxiliar, se for um elemento da primeira metade
            i++;
            k++;
        }
        else{ //Percorre a segunda metade

            aux[k] = v[j]; //Menor elemento � colocado no vetor auxiliar, se for um elemento da segunda metade

            j++;
            k++;
    }

    } //Caso ainda haja elementos em quaisquer metades, eles ser�o copiados diretamente
    while(i <= meio){

        aux[k] = v[i];

        i++;
        k++;
    }

    while(j <= fim){

        aux[k] = v[j];

        j++;
        k++;
    }

    for(i=inicio; i<=fim; i++){ //O vetor original v ser� atualizado com os valores do vetor auxiliar aux

        v[i] = aux[i];
    }
}
}

void qS(int *v, int inicio, int fim){

    if(inicio<fim){

        int pos = particionaETroca(v, inicio, fim); //Int pos pq vai retornar a posi��o
        qS(v, inicio, pos-1); //Pega a metade da esquerda e realiza o quick
        qS(v, pos, fim);      //Pega a metade da direita e realiza o quick
    }

}

void qS_PI(int *v, int inicio, int fim) {

    while (inicio < fim) { //condi��o para evitar chamadas recursivas desnecess�rias e estouros de mem�ria (estava ocorrendo anteriormente)
        int pos = particionaETroca_PI(v, inicio, fim);  //fun��o de particionamento chamada (reorganizando um vetor em torno de um piv�)


        if (pos - inicio < fim - pos) { //comparar o tamanho das parti��es esquerda e direita, e ir alternando e priorizando as parti��es que tiverem menor tamanho (reduz recurs�o e evita estouro)
            qS_PI(v, inicio, pos - 1);  //quick na parte esquerda
            inicio = pos + 1;       //atualizando inicio para uma posi��o a mais � direita
        } else {
            qS_PI(v, pos + 1, fim);     //quick na parte direita
            fim = pos - 1;          //atualizando fim para uma posi��o a mais � esquerda
        }
    }
}

void qS_PR(int *v, int inicio, int fim){

    if(inicio<fim){

        int pos = particionaETroca_PR(v, inicio, fim); //Int pos pq vai retornar a posi��o
        qS_PR(v, inicio, pos-1); //Pega a metade da esquerda e realiza o quick
        qS_PR(v, pos+1, fim);      //Pega a metade da direita e realiza o quick
    }

}

void hS(int *v, int tam){

build_heap_minimum(v, tam); //Constru��o do heap m�nimo

//Extrai os elementos do heap m�nimo, um de cada vez
for(int i = tam - 1; i>0; i--){

    int aux = v[0]; //
    v[0] = v[i];    // troca a raiz(menor elemento) com o �ltimo elemento do heap
    v[i] = aux;  //

    tam--; //Redu��o do tamanho do heap, para fazer menos compara��es

    //Passa a fazer o min_heapify para o restante do array
    MIN_heapify(v, tam, 0);
}
}

//Fun��o para imprimir o vetor
void imprimir(int *v, int tam){  //Percorrer e imprimir os elementos do vetor, separado por v�rgulas

int i;

for(i=0; i<tam; i++){

    printf("Posi��o %d:%d\n", i, v[i]);
    }
printf("\n");
}

//Fun��o para gravar vetor em arquivo
void gravar_em_arquivo(int *v, int tam, const char *VetorArquivo){

    FILE *arquivo = fopen(VetorArquivo, "w");
    if(arquivo == NULL){

        printf("Erro ao abrir arquivo %s!\n", VetorArquivo);
        return;
    }

    fprintf(arquivo, "%d\n\n", tam); //gravando o tamanho da entrada/sa�da uma �nica vez
    for(int i = 0; i<tam; i++){

        fprintf(arquivo, "%d\n", v[i]);
    }
    fprintf(arquivo, "\n");
    fclose(arquivo);
    printf("Vetor gravado em %s com sucesso\n", VetorArquivo);
}

void gravar_tempo(double tempo, const char *TempoArquivo){

    FILE *arquivoTime = fopen(TempoArquivo, "w");
    if (arquivoTime == NULL){

        printf("Erro ao abrir arquivo de tempo %s!\n", TempoArquivo);
        return;
    }

    fprintf(arquivoTime, "%f\n Segundos", tempo);

    fclose(arquivoTime);
    printf("Tempo gravado em %s com sucesso\n", TempoArquivo);
}

int main(){

setlocale(LC_ALL, "Portuguese");

    int opcaoAlg;
    char opcao;
    int opcaoEntrada;


printf("Bem-vindo ao programa de algoritmos!\n"
       "\nOpcoes de algoritmo disponiveis:\n"
       "\n1 = Bubble Sort\n"
       "2 = Insertion Sort\n"
       "3 = Selection Sort\n"
       "4 = Shell Sort\n"
       "5 = Merge Sort\n"
       "6 = Quick Sort com piv� da m�dia\n"
       "7 = Quick Sort com piv� do in�cio\n"
       "8 = Quick Sort com piv� aleat�rio\n"
       "9 = Heap Sort\n"
       "\n0 = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%d", &opcaoAlg);

printf("\n------------------------------------------------------------------------------------------------------------------------\n");


switch(opcaoAlg){

case 1: //Bubble Sort
    {
CreateDirectory("Bubble-sort (principal)", NULL);

CreateDirectory("Bubble-sort (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Bubble-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Bubble-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Bubble-sort (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);



        printf("Bem-vindo ao programa de algoritmo Bubble-Sort!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

    case 'r':
    case 'R':

        printf("\nOpcao numeros aleatorios escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

        case 1:
        case 10:

            {
            int tam = 10;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10; //valores de 0 a 9
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }


        case 2:
        case 100:

            {
            int tam = 100;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100; //valores de 0 a 99
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 3:
        case 1000:

            {
            int tam = 1000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000; //valores de 0 a 999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 4:
        case 10000:

            {
            int tam = 10000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10000; //valores de 0 a 9999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 5:
        case 100000:

            {
            int tam = 100000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100000; //valores de 0 a 99999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 6:
        case 1000000:

            {
            int tam = 1000000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000000; //valores de 0 a 999999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'c':
    case 'C':

        printf("\nOpcao numeros crescentes escolhida!\n");

        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 2:
    case 100:
        {
            int tam = 100; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
        //algoritmo para 100 dados

            break;
        }
    case 3:
    case 1000:
        {
            int tam = 1000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 4:
    case 10000:
        {
            int tam = 10000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 5:
    case 100000:
        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'd':
    case 'D':

        printf("\nOpcao numeros decrescentes escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcaoEntrada);

        switch(opcaoEntrada){ //Decrescente

            case 1:
            case 10:
                {
                    int tam = 10; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 2:
            case 100:
                {
                 int tam = 100; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 3:
            case 1000:
                {
                 int tam = 1000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 4:
            case 10000:
                {
                 int tam = 10000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 5:
            case 100000:
                {
                 int tam = 100000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 6:
            case 1000000:
                {
                 int tam = 1000000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
        default:
            {


            printf("\nEntrada invalida!\n");
            }
        }


                break;

        break;

    case 'S':
    case 's':

        return 0;
        break;

    default:
        printf("\nOpcao invalida!\n");
        break;
}

        break;
    }
case 2: //Insertion Sort
    {

CreateDirectory("Insertion-sort (principal)", NULL);

CreateDirectory("Insertion-sort (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Insertion-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Insertion-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Insertion-sort (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);



    printf("Bem-vindo ao programa de algoritmo Insertion-Sort!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

    case 'r':
    case 'R':

        printf("\nOpcao numeros aleatorios escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

        case 1:
        case 10:

            {
            int tam = 10;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10; //valores de 0 a 9
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }


        case 2:
        case 100:

            {
            int tam = 100;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100; //valores de 0 a 99
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 3:
        case 1000:

            {
            int tam = 1000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000; //valores de 0 a 999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 4:
        case 10000:

            {
            int tam = 10000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10000; //valores de 0 a 9999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 5:
        case 100000:

            {
            int tam = 100000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100000; //valores de 0 a 99999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 6:
        case 1000000:

            {
            int tam = 1000000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000000; //valores de 0 a 999999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'c':
    case 'C':

        printf("\nOpcao numeros crescentes escolhida!\n");

        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 2:
    case 100:
        {
            int tam = 100; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
        //algoritmo para 100 dados

            break;
        }
    case 3:
    case 1000:
        {
            int tam = 1000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 4:
    case 10000:
        {
            int tam = 10000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 5:
    case 100000:
        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'd':
    case 'D':

        printf("\nOpcao numeros decrescentes escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcaoEntrada);

        switch(opcaoEntrada){ //Decrescente

            case 1:
            case 10:
                {
                    int tam = 10; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 2:
            case 100:
                {
                 int tam = 100; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 3:
            case 1000:
                {
                 int tam = 1000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 4:
            case 10000:
                {
                 int tam = 10000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 5:
            case 100000:
                {
                 int tam = 100000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 6:
            case 1000000:
                {
                 int tam = 1000000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
        default:
            {


            printf("\nEntrada invalida!\n");
            }
        }


                break;

        break;

    case 'S':
    case 's':

        return 0;
        break;

    default:
        printf("\nOpcao invalida!\n");
        break;
}



break;
}

case 3: //Selection Sort
    {

CreateDirectory("Selection-sort (principal)", NULL);

CreateDirectory("Selection-sort (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Selection-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Selection-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Selection-sort (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);


    printf("Bem-vindo ao programa de algoritmo Selection-Sort!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

    case 'r':
    case 'R':

        printf("\nOpcao numeros aleatorios escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

        case 1:
        case 10:

            {
            int tam = 10;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10; //valores de 0 a 9
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }


        case 2:
        case 100:

            {
            int tam = 100;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100; //valores de 0 a 99
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 3:
        case 1000:

            {
            int tam = 1000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000; //valores de 0 a 999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 4:
        case 10000:

            {
            int tam = 10000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10000; //valores de 0 a 9999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 5:
        case 100000:

            {
            int tam = 100000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100000; //valores de 0 a 99999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 6:
        case 1000000:

            {
            int tam = 1000000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000000; //valores de 0 a 999999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'c':
    case 'C':

        printf("\nOpcao numeros crescentes escolhida!\n");

        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 2:
    case 100:
        {
            int tam = 100; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
        //algoritmo para 100 dados

            break;
        }
    case 3:
    case 1000:
        {
            int tam = 1000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 4:
    case 10000:
        {
            int tam = 10000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 5:
    case 100000:
        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'd':
    case 'D':

        printf("\nOpcao numeros decrescentes escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcaoEntrada);

        switch(opcaoEntrada){ //Decrescente

            case 1:
            case 10:
                {
                    int tam = 10; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 2:
            case 100:
                {
                 int tam = 100; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 3:
            case 1000:
                {
                 int tam = 1000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 4:
            case 10000:
                {
                 int tam = 10000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 5:
            case 100000:
                {
                 int tam = 100000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 6:
            case 1000000:
                {
                 int tam = 1000000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
        default:
            {


            printf("\nEntrada invalida!\n");
            }
        }


                break;

        break;

    case 'S':
    case 's':

        return 0;
        break;

    default:
        printf("\nOpcao invalida!\n");
        break;
}

        break;
    }

case 4: //Shell Sort
    {

CreateDirectory("Shell-sort (principal)", NULL);

CreateDirectory("Shell-sort (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Shell-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Shell-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Shell-sort (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);



    printf("Bem-vindo ao programa de algoritmo Shell-Sort!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

    case 'r':
    case 'R':

        printf("\nOpcao numeros aleatorios escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

        case 1:
        case 10:

            {
            int tam = 10;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10; //valores de 0 a 9
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }


        case 2:
        case 100:

            {
            int tam = 100;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100; //valores de 0 a 99
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 3:
        case 1000:

            {
            int tam = 1000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000; //valores de 0 a 999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 4:
        case 10000:

            {
            int tam = 10000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10000; //valores de 0 a 9999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 5:
        case 100000:

            {
            int tam = 100000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100000; //valores de 0 a 99999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

        case 6:
        case 1000000:

            {
            int tam = 1000000;
            int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000000; //valores de 0 a 999999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);

            break;
            }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'c':
    case 'C':

        printf("\nOpcao numeros crescentes escolhida!\n");

        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 2:
    case 100:
        {
            int tam = 100; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
        //algoritmo para 100 dados

            break;
        }
    case 3:
    case 1000:
        {
            int tam = 1000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 4:
    case 10000:
        {
            int tam = 10000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 5:
    case 100000:
        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);

            break;
        }
default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'd':
    case 'D':

        printf("\nOpcao numeros decrescentes escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcaoEntrada);

        switch(opcaoEntrada){ //Decrescente

            case 1:
            case 10:
                {
                    int tam = 10; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 2:
            case 100:
                {
                 int tam = 100; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 3:
            case 1000:
                {
                 int tam = 1000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 4:
            case 10000:
                {
                 int tam = 10000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 5:
            case 100000:
                {
                 int tam = 100000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
            case 6:
            case 1000000:
                {
                 int tam = 1000000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);

                    break;
                }
        default:
            {


            printf("\nEntrada invalida!\n");
            }
        }


                break;

        break;

    case 'S':
    case 's':

        return 0;
        break;

    default:
        printf("\nOpcao invalida!\n");
        break;
}

        break;
    }

case 5: //Merge Sort
 {

CreateDirectory("Merge-sort (principal)", NULL);

CreateDirectory("Merge-sort (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Merge-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Merge-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Merge-sort (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);



    printf("Bem-vindo ao programa de algoritmo Merge-Sort!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

    case 'r':
    case 'R':

        printf("\nOpcao numeros aleatorios escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

        case 1:
        case 10:

            {
            int tam = 10;
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10; //valores de 0 a 9
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);
    free(aux);

            break;
            }


        case 2:
        case 100:

            {
            int tam = 100;
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100; //valores de 0 a 99
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);
    free(aux);

            break;
            }

        case 3:
        case 1000:

            {
            int tam = 1000;
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000; //valores de 0 a 999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);
    free(aux);

            break;
            }

        case 4:
        case 10000:

            {
            int tam = 10000;
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 10000; //valores de 0 a 9999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);
    free(aux);

            break;
            }

        case 5:
        case 100000:

            {
            int tam = 100000;
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 100000; //valores de 0 a 99999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);
    free(aux);

            break;
            }

        case 6:
        case 1000000:

            {
            int tam = 1000000;
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % 1000000; //valores de 0 a 999999
    }
    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

    free(vet);
    free(aux);

            break;
            }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'c':
    case 'C':

        printf("\nOpcao numeros crescentes escolhida!\n");

        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
   free(aux);

            break;
        }
    case 2:
    case 100:
        {
            int tam = 100; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
   free(aux);
        //algoritmo para 100 dados

            break;
        }
    case 3:
    case 1000:
        {
            int tam = 1000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
   free(aux);

            break;
        }
    case 4:
    case 10000:
        {
            int tam = 10000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
   free(aux);

            break;
        }
    case 5:
    case 100000:
        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
   free(aux);

            break;
        }
    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);
   free(aux);

            break;
        }
default:
    {


    printf("\nEntrada invalida!\n");
    }
}


        break;

    case 'd':
    case 'D':

        printf("\nOpcao numeros decrescentes escolhida!\n");


        printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

        printf("\nOpcao escolhida: ");
        scanf("%d", &opcaoEntrada);

        switch(opcaoEntrada){ //Decrescente

            case 1:
            case 10:
                {
                    int tam = 10; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);
           free(aux);

                    break;
                }
            case 2:
            case 100:
                {
                 int tam = 100; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);
           free(aux);

                    break;
                }
            case 3:
            case 1000:
                {
                 int tam = 1000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);
           free(aux);

                    break;
                }
            case 4:
            case 10000:
                {
                 int tam = 10000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);
           free(aux);

                    break;
                }
            case 5:
            case 100000:
                {
                 int tam = 100000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);
           free(aux);

                    break;
                }
            case 6:
            case 1000000:
                {
                 int tam = 1000000; //tam deve ser definido pelo usu�rio
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplica��o do algoritmo

            EndC = clock();
            tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

           gravar_em_arquivo(vet, tam, nomeSaida);
           gravar_tempo(tempo, nomeTempo);

           free(vet);
           free(aux);

                    break;
                }
        default:
            {


            printf("\nEntrada invalida!\n");
            }
        }


                break;

        break;

    case 'S':
    case 's':

        return 0;
        break;

    default:
        printf("\nOpcao invalida!\n");
        break;
}

        break;
    }

case 6: //Quick Sort M�dia
    {

CreateDirectory("Quick-sort (principal)", NULL);

CreateDirectory("Quick-sort (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Quick-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Quick-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Quick-sort (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);



    printf("Bem-vindo ao programa de algoritmo Quick-Sort!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

case 'r':
case 'R':

printf("\nOpcao numeros aleatorios escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % tam;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

case 'c':
case 'C':

printf("\nOpcao numeros crescentes escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

case 'd':
case 'D':

printf("\nOpcao numeros decrescentes escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Decrescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = (tam - 1) - i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

break;

case 'S':
case 's':

        return 0;
        break;


    default:
        printf("\nOpcao invalida!\n");
        break;
}

    break;
    }

case 7: //Quick Sort Piv� Inicial
    {

CreateDirectory("Quick-sort_V.I. (principal)", NULL);

CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);



    printf("Bem-vindo ao programa de algoritmo Quick-Sort (vers�o in�cio)!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

case 'r':
case 'R':

printf("\nOpcao numeros aleatorios escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % tam;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

case 'c':
case 'C':

printf("\nOpcao numeros crescentes escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

case 'd':
case 'D':

printf("\nOpcao numeros decrescentes escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Decrescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = (tam - 1) - i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

break;

case 'S':
case 's':

        return 0;
        break;


    default:
        printf("\nOpcao invalida!\n");
        break;
}

    break;
    }

case 8: //Quick Sort Piv� Aleat�rio
    {

CreateDirectory("Quick-sort_V.R. (principal)", NULL);

CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);



    printf("Bem-vindo ao programa de algoritmo Quick-Sort (vers�o aleat�rio)!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

case 'r':
case 'R':

printf("\nOpcao numeros aleatorios escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % tam;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

case 'c':
case 'C':

printf("\nOpcao numeros crescentes escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

case 'd':
case 'D':

printf("\nOpcao numeros decrescentes escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Decrescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = (tam - 1) - i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

break;

case 'S':
case 's':

        return 0;
        break;


    default:
        printf("\nOpcao invalida!\n");
        break;
}

    break;
    }

case 9: //Heap Sort
{

CreateDirectory("Heap-sort (principal)", NULL);

CreateDirectory("Heap-sort (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-sa�da",NULL);

CreateDirectory("Heap-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-entrada/Aleat�rio", NULL);

CreateDirectory("Heap-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-tempo/Aleat�rio", NULL);

CreateDirectory("Heap-sort (principal)/Arquivos-de-sa�da/Crescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-sa�da/Decrescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-sa�da/Aleat�rio", NULL);



    printf("Bem-vindo ao programa de algoritmo Heap-Sort!\n"
       "\nOpcoes disponiveis:\n"
       "\nC = Numeros em ordem crescente\n"
       "D = Numeros em ordem decrescente\n"
       "R = Numeros em ordem aleatoria\n"
       "S = Sair do programa\n");
printf("\nEscolha uma opcao: ");
scanf("%s", &opcao);

switch(opcao){

case 'r':
case 'R':

printf("\nOpcao numeros aleatorios escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Aleatorio

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % tam;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    hS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleat�rio/Entrada_Aleat�rio_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Aleat�rio/Sa�da_Aleat�rio_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleat�rio/Tempo_Aleat�rio_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

case 'c':
case 'C':

printf("\nOpcao numeros crescentes escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Crescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    hS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Crescente/Sa�da_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

case 'd':
case 'D':

printf("\nOpcao numeros decrescentes escolhida!\n");

printf("\n------------------------------------------------------------------------------------------------------------------------\n"
       "\nEscolha o tamanho da instancia (quantidade de numeros):\n"
       "1. 10 (DEZ)\n"
       "2. 100 (CEM)\n"
       "3. 1000 (MIL)\n"
       "4. 10000 (DEZ MIL)\n"
       "5. 100000 (CEM MIL)\n"
       "6. 1000000 (UM MILHAO)\n");

printf("\nOpcao escolhida: ");
scanf("%d", &opcaoEntrada);

switch(opcaoEntrada){ //Decrescente

    case 1:
    case 10:
        {
            int tam = 10; //tam deve ser definido pelo usu�rio
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = (tam - 1) - i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    hS(vet, tam);      // aplica��o do algoritmo

    EndC = clock();
    tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

    //Fim da cronometragem

   gravar_em_arquivo(vet, tam, nomeSaida);
   gravar_tempo(tempo, nomeTempo);

   free(vet);


            break;
        }

    case 2:
    case 100:

        {
        int tam = 100; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 3:
    case 1000:

        {
        int tam = 1000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 4:
    case 10000:

        {
        int tam = 10000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 5:
    case 100000:

        {
        int tam = 100000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

    case 6:
    case 1000000:
        {
        int tam = 1000000; //tam deve ser definido pelo usu�rio
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-sa�da/Decrescente/Sa�da_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplica��o do algoritmo

        EndC = clock();
        tempo = (EndC - StartC) / (double)CLOCKS_PER_SEC;

            //Fim da cronometragem

        gravar_em_arquivo(vet, tam, nomeSaida);
        gravar_tempo(tempo, nomeTempo);

        free(vet);


            break;
        }

default:
    {


    printf("\nEntrada invalida!\n");
    }
}

break;

break;

case 'S':
case 's':

        return 0;
        break;


    default:
        printf("\nOpcao invalida!\n");
        break;
}
//Logo ap�s, aparece o �ltimo break que fecha os cases do algoritmo escolhido


    break; //�ltimo break que fecha os cases do algoritmo escolhido
    }

    case 0:
    {
    return 0;

break;
}

default:
    printf("Opcao de algoritmo invalida!");
}



return 0;
}
