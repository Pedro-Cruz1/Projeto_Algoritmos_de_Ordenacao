#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <locale.h>

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

//Função para imprimir o vetor
void imprimir(int *v, int tam){  //Percorrer e imprimir os elementos do vetor, separado por vírgulas

int i;

for(i=0; i<tam; i++){

    printf("%d,", v[i]);
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
