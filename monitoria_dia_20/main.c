#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Esse código foi feito para fins de estudo na monitoria e quem usar ele em prova é bobão!
//Bom sempre lembrar que códigos sempre vão poder ser mais "limpos", mas, para facilitar a explicação, esse pode ser que seja um pouco mais "poluído"
int main()
{
    //declaração de variáveis
    float oposto, adjacente, hipotenusa;
    //float *o=&oposto, *a=&adjacente, *h=&hipotenusa;
    char faltante;
    int status_funcao;

    //pedindo e recebendo os valores
    printf("Calculando triangulo retangulo!\n\n");
    printf("Insira o valor do cateto oposto: ");
    scanf("%f", &oposto);
    printf("Insira o valor do cateto adjacente: ");
    scanf("%f", &adjacente);
    printf("Insira o valor da hipotenusa: ");
    scanf("%f", &hipotenusa);

    //teste para mostrar, ao final do código, somente o lado calculado (não precisa ser assim, mas aproveitei para inserir um pouco mais de coisa caso vcs sejam curiosos)
    if(oposto==0)
        faltante='o';
    if(adjacente==0)
        faltante='a';
    if(hipotenusa==0)
        faltante='h';

    //chamado da função de calculo do lado faltante
    status_funcao=triangulo_retangulo(&oposto, &adjacente, &hipotenusa);

    //teste de verificação de sucesso do cálculo
    if(status_funcao==0)
    {
        //switch case para mostrar somente o lado que foi calculado, caso não saibam o que é um switch case, sugiro pesquisar no Google ou mandar mensagem pra mim
        switch(faltante)
        {
        case 'o':
            printf("\nO valor do lado oposto calculado foi: %.2f\n", oposto);
            break;
        case 'a':
            printf("\nO valor do lado adjacente calculado foi: %.2f\n", adjacente);
            break;
        case 'h':
            printf("\nO valor da hipotenusa calculado foi: %.2f\n", hipotenusa);
            break;
        }
    }
    else
    {
        printf("Deu ruim!\nNenhum ou mais de um parâmetro é igual ou menor que zero!");
    }

    //assinatura de cria
    system("c:\signature\\signature.exe");
    return 0;
}

//função para calcular lado faltante no triângulo retângulo
int triangulo_retangulo(float *oposto, float *adjacente, float *hipotenusa)
{
    //teste de consistência dos valores passados
    if(*oposto<=0&&*adjacente<=0||*oposto<=0&&*hipotenusa<=0||*hipotenusa<=0&&*adjacente<=0||*adjacente>0&&*hipotenusa>0&&*oposto>0)
        return -1;
    else
    {
        //teste de qual variável é a faltante
        if(*oposto==0)
            *oposto=sqrt((pow(*hipotenusa, 2) - pow(*adjacente, 2)));
            //equivalencia funçao e gambiarra
            //pow(hipotenusa,2) = hipotenusa*hipotenusa
        if(*adjacente==0)
            *adjacente=sqrt((pow(*hipotenusa,2)-pow(*oposto,2)));

        if(*hipotenusa==0)
            *hipotenusa=sqrt((pow(*oposto,2)+pow(*adjacente,2)));

        return 0;
    }

}
