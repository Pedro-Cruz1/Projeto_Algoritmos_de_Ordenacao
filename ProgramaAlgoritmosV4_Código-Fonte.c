#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <locale.h>

//Função particiona que divide o vetor em 2 partes, vai colocar 1 elemento na posição correta e dividir o resto (usada no quick)
int particionaETroca(int *v, int inicio, int fim){ //A função é int pq precisa retornar o índice do elemento que foi colocado na posição correta

int pivo = (v[inicio] + v[fim] + v[(inicio+fim)/2])/3; //Pivô é a média aritmética dos elementos inicial, central e final do vetor


while(inicio<fim){  //Enquanto o inicio for menor que o fim, as trocas serão executadas

    while(inicio<fim && v[inicio] <= pivo){ //Do início para o meio, encontrar um elemento que seja maior que o pivô
        inicio = inicio + 1;
    }
    while(inicio<fim && v[fim] > pivo){ //Do meio para o fim, encontrar um elemento que seja menor que o pivô
        fim = fim - 1;
    }

    //Trocar os 2 elementos encontrados (menor e maior que o pivô)

    int aux = v[inicio]; //
    v[inicio] = v[fim];  // A troca é realizada
    v[fim] = aux;        //
}

//Quando o while falhar, o inicio é retornado e usado na função do quick sort

return inicio; //O retorno vai acabar sendo o elemento do meio do vetor, que já está na posição correta
}

int particionaETroca_PI(int *v, int inicio, int fim) {

    int pivo = v[inicio]; //pivô definido como início (primeiro elemento do vetor ou subvetor)

    int i = inicio + 1; //logo após o pivô, procura elementos menores
    int j = fim;        //no final do subvetor, procura elementos maiores

    while (i <= j) {    //repetição enquanto i e j não se cruzarem (o cruzamento indicaria que a partição foi completa)
        while (i <= j && v[i] <= pivo) { //avança o i para a direita enquanto os elementos na posição i forem menores ou iguais ao pivô
            i = i + 1;
        }

        while (i <= j && v[j] > pivo) { //avança o j para a esquerda enquanto os elementos na posição j forem maiores ao pivô
            j = j - 1;
        }

        if (i < j) {    //verifica se ainda não há cruzamento entre i e j
            int aux = v[i]; //
            v[i] = v[j];    // troca
            v[j] = aux;     //
        }
    }

//Reposicionando o pivô, pois depois que i e j se cruzam, os elementos à esquerda de j são menores e os à direita são maiores
    v[inicio] = v[j];  //O elemento na posição inicial do vetor (onde o pivô estava temporariamente) é movido para j
    v[j] = pivo;       //O elemento na posição inicial do vetor (onde o pivô estava temporariamente) é movido para j

    return j;   //índice final do pivô após todas as trocas e ajustes, usado na recursão do quick
}

int particionaETroca_PR(int *v, int inicio, int fim){ //A função é int pq precisa retornar o índice do elemento que foi colocado na posição correta


int posAleatoria = inicio + rand() % (fim - inicio + 1); //Gerar uma posição aleatória entre o inicio e o fim do vetor
//O int anterior só é usado quando o pivo é uma posição aleatória

// Trocar o valor do pivô aleatório para o início
int aux = v[inicio];
v[inicio] = v[posAleatoria];
v[posAleatoria] = aux;

int pivo = v[inicio]; //Pivô inicializado sempre como uma posição aleatória (usando a mesma forma do pivo no inicio)


//Em suma, o que vai acontecer é: o vetor vai ser inicializado, e um valor aleatório do vetor será escolhido como pivô
//Então, este valor será movido para o início, trocando os 2 valores de lugar, e então o procedimento iniciará propriamente
//Em essência, é o procedimento com pivô no início, mas o valor do início é gerado aleatoriamente


int i = inicio + 1; //Será usado para percorrer o vetor a partir do segundo elemento (inicio+1)
int j = fim; //Será usado para percorrer o vetor a partir do fim

while(i<=j){  //Enquanto o inicio for menor que o fim, as trocas serão executadas

    while(i<=j && v[i] <= pivo){ //Do início para o meio, encontrar um elemento que seja maior que o pivô
        i = i + 1;
    }
    while(i<=j && v[j] > pivo){ //Do meio para o fim, encontrar um elemento que seja menor que o pivô
        j = j - 1;
    }

    //Trocar os 2 elementos encontrados (menor e maior que o pivô)

    if(i<j){    // Se i está à esquerda de j, ambos os índices encontraram valores inconsistentes (v[i] é maior que o pivô e deveria estar à direita, e v[j] é menor que o pivô, e deveria estar à direita)

    int aux2 = v[i];    //
    v[i] = v[j];        // A troca é realizada
    v[j] = aux2;        //
    }
}

//Quando o while falhar, o j é retornado e usado na recursão

//Reposicionando o pivô, pois depois que i e j se cruzam, os elementos à esquerda de j são menores e os à direita são maiores
v[inicio] = v[j]; //O elemento na posição inicial do vetor (onde o pivô estava temporariamente) é movido para j
v[j] = pivo;    //O valor do pivô é colocado na posição correta (j)


return j; //O retorno vai acabar sendo a posição final do pivô no vetor
}

int parent(int i){ //usada apenas no increase key

return (i - 1) / 2;
}

void MIN_heapify(int *v, int tam, int i){

int menor = i; //índice do menor elemento (início)
int L = (2*i + 1);  //Se considerar que um vetor começa em 0, então faz sentido ser 2*i + 1, e não apenas 2i
int R = (2*i + 2);

//verificando se o menor é o filho da esquerda
if(L < tam && v[L] < v[menor]){

    menor = L; //Se é, o menor item passa a ser o da esquerda
}

//verificando se o menor é o filho da direita
if(R < tam && v[R] < v[menor]){

    menor = R; //Se é, o menor item passa a ser o da direita
}

// Se o menor não for o próprio i, faz a troca e continua o processo recursivamente
if (menor != i) {

    int aux = v[i];  //
    v[i] = v[menor]; // troca usando aux
    v[menor] = aux;  //

    MIN_heapify(v, tam, menor); // Chamada recursiva
}
}

void build_heap_minimum(int *v, int tam){

// Começa do último nó interno e aplica MIN-HEAPIFY até a raiz
for (int i = (tam / 2) - 1; i >= 0; i--) { //Um nó interno é um nó que possui ao menos 1 filho, é (tam/2) - 1 pq, para encontrar
//o pai do último nó filho, pode-se usar a fórmula inversa dos filhos, por exemplo, para o filho da esquerda, 2*i + 1 = tam - 1 -> i = (tam - 2)/2, notando-se o padrão (tam/2) - 1
    MIN_heapify(v, tam, i); //Aplicação do heapify para organizar a subárvore
    }
}

int heap_extract_min(int *v, int *tam){

//Se o heap for 0
if (*tam < 1) {
        printf("Erro: o heap está vazio.\n");
        return 0;
    }
    //Menor elemento é a raiz do heap
    int min = v[0];

    v[0] = v[*tam - 1]; //Substitui a raiz pelo último elemento do heap

    *tam = *tam - 1; //Reduzir o tamanho do heap

    MIN_heapify(v, *tam, 0); //Reorganizar o heap


    // Retorna o menor elemento extraído
    return min;
}

void heap_increase_key(int *v, int i, int chave){

 if (chave < v[i]) {
        printf("Erro: a nova chave %d é menor que a chave atual %d\n", chave, v[i]);
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
v[*tam - 1] = -1; //Inicializando a nova posição com o valor -1, que nunca é usado
heap_increase_key(v, *tam - 1, chave); // Ajusta o novo elemento com a chave
}

void inS(int *v, int tam){          //Função inS que recebe um vetor de inteiros (ponteiro) e o tamanho deste

    int i, j;                       //variáveis de controle do loop
    for (i = 1; i < tam; i++){      // i é o número da posição, que incrementa de 1 em 1, e considerando que começa em 0, o tamanho de um vetor de 0 até 19 é 20, então i deve ser menor que o tamanho máximo
        // comparação com o elemento anterior
        int aux, j = i;             //Armazena o valor atual em 'aux' e inicializa 'j' com o valor de 'i'
        aux = v[j];                 //cópia do que estiver dentro da posição do vetor para aux
        while(j>0 && aux<v[j-1]){   //se aux for menor que o item no vetor atual, ele regrede posições até encontrar um que não o seja

        // o while move os elementos maiores para a direita, criando espaço para alocar o aux

            v[j] = v[j-1];  //Deslocando o maior valor para a direita
            j --;           //Decrementa j, fazendo com que compare com o elemento anterior
        }
        v[j] = aux;         //Valor de aux é inserido na posição correta
    }

}

void bubS(int *v, int tam){

int i, j, aux;

for (j=0; j<tam; j++){ //O que este for faz é fazer com que o segundo seja executado um número de vezes igual ao tamanho do vetor

    for(i=0; i<tam-1; i++){ //O motivo pela qual é até "tam-1" é pq esse for para na penúltima posição, já que ele vai ler a posição seguinte, e não há nada após a última posição

            if(v[i] > v[i+1]){  //Se o dado de tal posição for maior que o da posição seguinte

                //As 3 linhas de código a seguir são a troca em si
                int aux = v[i]; //Aux recebe o valor do vetor na posição i
                v[i] = v[i+1];  //O vetor na posição i recebe o valor da posição seguinte, que é menor
                v[i+1] = aux;   //O vetor na posição seguinte recebe o valor de aux, que estava na posição anterior
            }
    }
}tam--;  //Vai diminuir a quantia de casas a serem percorridas, à medida que o algoritmo for rodando, talvez dê um problema quando colocar o decrescente, então vou deixar só comentado

}

void selS(int *v, int tam){

int i, j, aux, menor; //A variável menor vai armazenar o menor valor encontrado no vetor, e quando a hora chegar, vai trocar seu valor com outra posição do vetor

for(i=0; i<tam; i++){ //Vai percorrer o vetor e "fixar" a posição em que o menor valor encontrado será colocado

    menor = i; //menor vai estar sempre recebendo o valor da posição atual do vetor, já que o valor de i é atualizado

    for(j=i+1; j<tam; j++){ //Busca o menor valor entre os elementos que ainda não foram ordenados

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

//O shell sort existe a execução de um procedimento matemático mais complexo que envolve logaritmos, descrito a seguir
float k = log(tam+1)/log(3);    //Cálculo do número de varreduras
k = floor(k+0.5); //Acrescenta 0,5 e faz o arredondamento para baixo

int h = (pow(3,k)-1)/2; //Cálculo da distância no vetor para a varredura

while (h>0){        //Laço de varreduras, inicia a varredura se a distância h for maior que zero

    for(i=0; i<tam-h; i++){ //Laço para percorrer, vai até a posição anterior a tam-h

        if(v[i]>v[i+h]){    //Compara o item i com o item que está a uma distância h

                aux = v[i+h];   //
                v[i+h] = v[i];  // Esse bloco realiza a troca do conteúdo das posições do vetor
                v[i] = aux;     //

                j = i-h; // j recebe o índice do item anterior, para começar o laço interno
                while(j>=0){    // Realiza a varredura no sentido contrário

                    if(aux<v[j]){ //Comparação de aux com o item j, se for menor, faz a troca, se não, abandona o while

                        v[j+h] = v[j]; //
                        v[j] = aux;    // Substituições
                    }
                    else{

                        break;
                    }
                    j = j-h; //Caso uma troca tenha ocorrido, j será subtraído pelo valor de h, para que aux seja comparado com o item anterior, dando continuidade à varredura contrária
                }
        }
    } h = (h-1)/3; // Após a varredura do for, diminui a distância h para a próxima varredura. Se h for menor que 1, o processo será finalizado

}
}

void mS(int *v, int *aux, int inicio, int fim){

int meio, i, j, k;

if(inicio<fim){  //Chama a função até que o tamanho e o fim sejam iguais, ou seja, 0

    meio = ((inicio + fim)/2); //Calcula qual é a metade do vetor

    //Essa parte a seguir, basicamente divide os dados
    mS(v, aux, inicio, meio);    // Chama a função para a primeira parte do vetor (início até o meio)
    mS(v, aux, meio+1, fim);     // Chama a função para a segunda parte do vetor (meio+1 até o final)

    //Aplicação do merge (orgenação das partes)


    i = inicio;     //índice para percorrer a primeira metade do vetor
    j = meio + 1;   //índice para percorrer a segunda metade do vetor
    k = inicio;     //índice para percorrer o vetor auxiliar

    //Combinação das partes de maneira ordenada, em um vetor auxiliar
    while(i <= meio && j<= fim){ //Enquanto ainda tiver elementos nas partes

        if(v[i] < v[j]){ //Percorre a primeira metade

            aux[k] = v[i]; //Menor elemento é colocado no vetor auxiliar, se for um elemento da primeira metade
            i++;
            k++;
        }
        else{ //Percorre a segunda metade

            aux[k] = v[j]; //Menor elemento é colocado no vetor auxiliar, se for um elemento da segunda metade

            j++;
            k++;
    }

    } //Caso ainda haja elementos em quaisquer metades, eles serão copiados diretamente
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

    for(i=inicio; i<=fim; i++){ //O vetor original v será atualizado com os valores do vetor auxiliar aux

        v[i] = aux[i];
    }
}
}

void qS(int *v, int inicio, int fim){

    if(inicio<fim){

        int pos = particionaETroca(v, inicio, fim); //Int pos pq vai retornar a posição
        qS(v, inicio, pos-1); //Pega a metade da esquerda e realiza o quick
        qS(v, pos, fim);      //Pega a metade da direita e realiza o quick
    }

}

void qS_PI(int *v, int inicio, int fim) {

    while (inicio < fim) { //condição para evitar chamadas recursivas desnecessárias e estouros de memória (estava ocorrendo anteriormente)
        int pos = particionaETroca_PI(v, inicio, fim);  //função de particionamento chamada (reorganizando um vetor em torno de um pivô)


        if (pos - inicio < fim - pos) { //comparar o tamanho das partições esquerda e direita, e ir alternando e priorizando as partições que tiverem menor tamanho (reduz recursão e evita estouro)
            qS_PI(v, inicio, pos - 1);  //quick na parte esquerda
            inicio = pos + 1;       //atualizando inicio para uma posição a mais à direita
        } else {
            qS_PI(v, pos + 1, fim);     //quick na parte direita
            fim = pos - 1;          //atualizando fim para uma posição a mais à esquerda
        }
    }
}

void qS_PR(int *v, int inicio, int fim){

    if(inicio<fim){

        int pos = particionaETroca_PR(v, inicio, fim); //Int pos pq vai retornar a posição
        qS_PR(v, inicio, pos-1); //Pega a metade da esquerda e realiza o quick
        qS_PR(v, pos+1, fim);      //Pega a metade da direita e realiza o quick
    }

}

void hS(int *v, int tam){

build_heap_minimum(v, tam); //Construção do heap mínimo

//Extrai os elementos do heap mínimo, um de cada vez
for(int i = tam - 1; i>0; i--){

    int aux = v[0]; //
    v[0] = v[i];    // troca a raiz(menor elemento) com o último elemento do heap
    v[i] = aux;  //

    tam--; //Redução do tamanho do heap, para fazer menos comparações

    //Passa a fazer o min_heapify para o restante do array
    MIN_heapify(v, tam, 0);
}
}

//Função para imprimir o vetor
void imprimir(int *v, int tam){  //Percorrer e imprimir os elementos do vetor, separado por vírgulas

int i;

for(i=0; i<tam; i++){

    printf("Posição %d:%d\n", i, v[i]);
    }
printf("\n");
}

//Função para gravar vetor em arquivo
void gravar_em_arquivo(int *v, int tam, const char *VetorArquivo){

    FILE *arquivo = fopen(VetorArquivo, "w");
    if(arquivo == NULL){

        printf("Erro ao abrir arquivo %s!\n", VetorArquivo);
        return;
    }

    fprintf(arquivo, "%d\n\n", tam); //gravando o tamanho da entrada/saída uma única vez
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
       "6 = Quick Sort com pivô da média\n"
       "7 = Quick Sort com pivô do início\n"
       "8 = Quick Sort com pivô aleatório\n"
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
CreateDirectory("Bubble-sort (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Bubble-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Bubble-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Bubble-sort (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Bubble-sort (principal)/Arquivos-de-saída/Aleatório", NULL);



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
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
            int tam = 100; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
            int tam = 1000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    bubS(vet, tam);      // aplicação do algoritmo

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
                    int tam = 10; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 100; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 1000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 10000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 100000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 1000000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Bubble-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Bubble-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Bubble-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            bubS(vet, tam);      // aplicação do algoritmo

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
CreateDirectory("Insertion-sort (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Insertion-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Insertion-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Insertion-sort (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Insertion-sort (principal)/Arquivos-de-saída/Aleatório", NULL);



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
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
            int tam = 100; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
            int tam = 1000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    inS(vet, tam);      // aplicação do algoritmo

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
                    int tam = 10; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 100; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 1000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 10000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 100000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 1000000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Insertion-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Insertion-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Insertion-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            inS(vet, tam);      // aplicação do algoritmo

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
CreateDirectory("Selection-sort (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Selection-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Selection-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Selection-sort (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Selection-sort (principal)/Arquivos-de-saída/Aleatório", NULL);


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
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
            int tam = 100; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
            int tam = 1000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    selS(vet, tam);      // aplicação do algoritmo

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
                    int tam = 10; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 100; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 1000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 10000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 100000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 1000000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Selection-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Selection-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Selection-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            selS(vet, tam);      // aplicação do algoritmo

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
CreateDirectory("Shell-sort (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Shell-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Shell-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Shell-sort (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Shell-sort (principal)/Arquivos-de-saída/Aleatório", NULL);



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
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
            int tam = 100; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
            int tam = 1000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    shS(vet, tam);      // aplicação do algoritmo

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
                    int tam = 10; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 100; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 1000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 10000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 100000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplicação do algoritmo

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
                 int tam = 1000000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Shell-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Shell-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Shell-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            shS(vet, tam);      // aplicação do algoritmo

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
CreateDirectory("Merge-sort (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Merge-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Merge-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Merge-sort (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Merge-sort (principal)/Arquivos-de-saída/Aleatório", NULL);



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
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 100; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 1000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 10000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));
    int *aux = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
                    int tam = 10; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
                 int tam = 100; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
                 int tam = 1000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
                 int tam = 10000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
                 int tam = 100000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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
                 int tam = 1000000; //tam deve ser definido pelo usuário
            int *vet = (int*)malloc(tam * sizeof(int));
            int *aux = (int*)malloc(tam * sizeof(int));

            for(int i = 0; i < tam; i++){
            vet[i] = (tam - 1) - i;
            }

            char nomeEntrada[100];
            sprintf(nomeEntrada, "Merge-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

            char nomeSaida[100];
            sprintf(nomeSaida, "Merge-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

            char nomeTempo[100];
            sprintf(nomeTempo, "Merge-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

            gravar_em_arquivo(vet, tam, nomeEntrada);

            //Cronometrar tempo

            double tempo;
            clock_t StartC, EndC;
            StartC = clock();

            mS(vet, aux, 0, (tam-1));      // aplicação do algoritmo

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

case 6: //Quick Sort Média
    {

CreateDirectory("Quick-sort (principal)", NULL);

CreateDirectory("Quick-sort (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Quick-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Quick-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Quick-sort (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Quick-sort (principal)/Arquivos-de-saída/Aleatório", NULL);



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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % tam;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = (tam - 1) - i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS(vet, 0, (tam-1));      // aplicação do algoritmo

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

case 7: //Quick Sort Pivô Inicial
    {

CreateDirectory("Quick-sort_V.I. (principal)", NULL);

CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Quick-sort_V.I. (principal)/Arquivos-de-saída/Aleatório", NULL);



    printf("Bem-vindo ao programa de algoritmo Quick-Sort (versão início)!\n"
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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % tam;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = (tam - 1) - i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.I. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.I. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.I. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PI(vet, 0, (tam-1));      // aplicação do algoritmo

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

case 8: //Quick Sort Pivô Aleatório
    {

CreateDirectory("Quick-sort_V.R. (principal)", NULL);

CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-entrada",NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-tempo",NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Quick-sort_V.R. (principal)/Arquivos-de-saída/Aleatório", NULL);



    printf("Bem-vindo ao programa de algoritmo Quick-Sort (versão aleatório)!\n"
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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % tam;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = (tam - 1) - i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Quick-sort_V.R. (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Quick-sort_V.R. (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Quick-sort_V.R. (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        qS_PR(vet, 0, (tam-1));      // aplicação do algoritmo

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
CreateDirectory("Heap-sort (principal)/Arquivos-de-saída",NULL);

CreateDirectory("Heap-sort (principal)/Arquivos-de-entrada/Crescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-entrada/Decrescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-entrada/Aleatório", NULL);

CreateDirectory("Heap-sort (principal)/Arquivos-de-tempo/Crescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-tempo/Decrescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-tempo/Aleatório", NULL);

CreateDirectory("Heap-sort (principal)/Arquivos-de-saída/Crescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-saída/Decrescente", NULL);
CreateDirectory("Heap-sort (principal)/Arquivos-de-saída/Aleatório", NULL);



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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = rand() % tam;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = rand() % tam;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Aleatório/Entrada_Aleatório_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Aleatório/Saída_Aleatório_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Aleatório/Tempo_Aleatório_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Crescente/Entrada_Crescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Crescente/Saída_Crescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Crescente/Tempo_Crescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
            int tam = 10; //tam deve ser definido pelo usuário
    int *vet = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
    vet[i] = (tam - 1) - i;
    }

    char nomeEntrada[100];
    sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

    char nomeSaida[100];
    sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

    char nomeTempo[100];
    sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

    gravar_em_arquivo(vet, tam, nomeEntrada);

    //Cronometrar tempo

    double tempo;
    clock_t StartC, EndC;
    StartC = clock();

    hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 10000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 100000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
        int tam = 1000000; //tam deve ser definido pelo usuário
        int *vet = (int*)malloc(tam * sizeof(int));

        for(int i = 0; i < tam; i++){
        vet[i] = (tam - 1) - i;
           }

        char nomeEntrada[100];
        sprintf(nomeEntrada, "Heap-sort (principal)/Arquivos-de-entrada/Decrescente/Entrada_Decrescente_%d.txt", tam);

        char nomeSaida[100];
        sprintf(nomeSaida, "Heap-sort (principal)/Arquivos-de-saída/Decrescente/Saída_Decrescente_%d.txt", tam);

        char nomeTempo[100];
        sprintf(nomeTempo, "Heap-sort (principal)/Arquivos-de-tempo/Decrescente/Tempo_Decrescente_%d.txt", tam);

        gravar_em_arquivo(vet, tam, nomeEntrada);

        //Cronometrar tempo

        double tempo;
        clock_t StartC, EndC;
        StartC = clock();

        hS(vet, tam);      // aplicação do algoritmo

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
//Logo após, aparece o último break que fecha os cases do algoritmo escolhido


    break; //Último break que fecha os cases do algoritmo escolhido
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
