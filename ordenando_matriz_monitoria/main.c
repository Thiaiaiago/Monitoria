#include <stdio.h>
#include <stdlib.h>
#include <time.h> //biblioteca time para usar no srand
#include <locale.h> //biblioteca de idioma para usar acentos

//defines de variaveis fixas
#define LIN 4
#define COL 7

void Ordena_Matriz (int *p_matriz);
void Ordena_Linha_Matriz (int *p_matriz, int tamanho);
int  Numero_Triangular(int tamanho);

int main()
{
    //criação da matriz
    int matriz [LIN][COL];

    //selecionando idioma português
    setlocale(LC_ALL, "Portuguese");
    //gerando valores aleatórios variáveis
    srand(time(NULL));
    //primeiro for incrementa a variável "i" até o valor da variável "linha", porém, dentro dela, existe outro for que incrementa a
//variável "j" até o valor da variável "coluna" e adiciona um valor aleatório entre 1 e 100 (podendo se repetir graças ao srand).
    //O for externo (o primeiro, que usa "linha" como limite de "i") cria uma quebra de linha para que o for interno preencha todas
//as colunas de todas as linhas corretamente
    for (int i=0; i<LIN; i++)
    {
        for (int j=0; j<COL; j++)
        {
            matriz[i][j]=((rand()%100)+1);
        }
    }

    //mostra matriz
    printf("Matriz original:\n\n");
    for (int i=0; i<LIN; i++)
    {
        for (int j=0; j<COL; j++)
        {
            printf("%i\t", matriz[i][j]);
        }
        printf("\n\n");
    }

    //chamada da função que ordena matriz
    Ordena_Matriz(&matriz);

    //mostra matriz
    printf("Matriz ordenada:\n\n");
    for (int i=0; i<LIN; i++)
    {
        for (int j=0; j<COL; j++)
        {
            printf("%i\t", matriz[i][j]);
        }
        printf("\n\n");
    }

    //assinatura de cria
    system("c:\signature\\signature.exe");
    return 0;
}

void Ordena_Matriz (int *p_matriz)
{
    int aux; //variável de substituição para fazer a ordenação

    //ordenação da matriz
    for (int i=0; i<(LIN*COL-1); i++)
    {
        for (int j=0; j<(LIN*COL-i-1); j++)
        {
            if (*(p_matriz+j) > *(p_matriz+j+1))
            {
                //bubble sort
                aux = *(p_matriz+j);
                *(p_matriz+j) = *(p_matriz+j+1);
                *(p_matriz+j+1) = aux;
            }
        }
    }
}

//função pra gerar numero na sequência 1+2+3+4+5...
int  Numero_Triangular(int tamanho)
{
    return ((tamanho*(tamanho+1))/2);
}
