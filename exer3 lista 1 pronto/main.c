#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <unistd.h>//BIBLIOTECA SLEEP(LOADING)
#include <windows.h>//BIBLIOTECA SLEEP(LOADING)

int i;
FILE *antigo, *novo;
int main()
{
    setlocale(LC_ALL, "Portuguese");//imprimir com acentos
   //abrindo o arquivo
    antigo=fopen("Concessionaria.CAD","r");

    //verificando se o arquivo foi aberto
    if(!antigo)
    {
        printf("O Arquivo nao foi aberto");
        return 1;
    }
    //Segundo arquivo para auxiliar
    novo=fopen("Concessionaria_novo.CAD","w");

    inicio();
}

inicio()
{
    printf("\n|||||||||||||||||||||||||MENU|||||||||||||||||||||||||||||");
    printf("\n||||                 Ano Atual: 2011                  ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n                                                          ");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n||||             Oque vc deseja fazer?                ||||");
    printf("\n||||                                                  ||||");
    printf("\n||||      01-Atualizar preço dos carros?              ||||");
    printf("\n||||      02-Deseja imprimir catalogo?                ||||");
    printf("\n||||      03-Deseja fechar o programa?                ||||");
    printf("\n||||                                                  ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\nDigite a opção:");
    scanf("%d",&i);
    system("cls");
    switch(i)
    {
        case 1:
            AtualizaPreco();
            break;
        case 2:
            imprimir();
            break;
        case 3:
            fechar();
            break;
        default:
            printf("\nErro, tente novamente:");
            inicio();
    }

}

AtualizaPreco()//atualização no preço dos carros
{
    //LOADING..
    printf("A");
    Sleep(100);
    printf("T");
    Sleep(100);
    printf("U");
    Sleep(100);
    printf("A");
    Sleep(100);
    printf("L");
    Sleep(100);
    printf("I");
    Sleep(100);
    printf("Z");
    Sleep(100);
    printf("A");
    Sleep(100);
    printf("N");
    Sleep(100);
    printf("D");
    Sleep(100);
    printf("O");
    Sleep(100);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);

    system("cls");
    fclose(antigo);//FECHANDO ARQUIVO PARA ABRIR NOVAMENTE

    antigo=fopen("Concessionaria.CAD","r");

    //verificando se o arquivo foi aberto
    if(!antigo)
    {
        printf("O Arquivo nao foi aberto!!!");
        return 1;
    }

    float preco, a;
    int codigo, ano, portas, r;
    char vet [20]={0};

    while(!feof(antigo))
    {
        fscanf(antigo, "%d %s %f %d %d\n", &codigo,&vet,&preco,&ano,&portas);
        printf("\n%d %s %.2f %d %d",codigo,vet,preco,ano,portas);
        /*Vai olhar o ano do carro, modificar e passar para o arquivo novo*/
        r=2011 - ano;
        if(r<1)
        {
            printf("\nModelo do Carro:%s\tPreço Antigo:%.2f\t",vet,preco);
            a = (preco * 10)/100;
            preco=preco+a;
            printf("Preço Novo:%.2f",preco);
            fprintf(novo,"\n%d %s %.2f %d %d",codigo,vet,preco,ano,portas);
        }

        else
            if(r<3 && ano>=1)
            {
                printf("\nModelo do Carro:%s/\tPreço Antigo:%.2f\t",vet,preco);
                a = (preco * 7)/100;
                preco=preco+a;
                printf("Preço Novo:%.2f",preco);
                fprintf(novo,"\n%d %s %.2f %d %d",codigo,vet,preco,ano,portas);
            }
        else
            if(r<5 && ano>=3)
            {
               printf("\nModelo do Carro:%s\tPreço Antigo:%.2f\t",vet,preco);
                a = (preco * 5)/100;
                preco=preco+a;
                printf("Preço Novo:%.2f",preco);
                fprintf(novo,"\n%d %s %.2f %d %d",codigo,vet,preco,ano,portas);
            }
        else
             if(r>=5)
            {
                printf("\nModelo do Carro:%s\tPreço Antigo:%.2f\t",vet,preco);
                a = (preco * 2)/100;
                preco=preco+a;
                printf("Preço Novo:%.2f",preco);
                fprintf(novo,"\n%d %s %.2f %d %d",codigo,vet,preco,ano,portas);
            }
            printf("\n\n");
    }
    Sleep(1000);
    denovo();
}

imprimir()//função para imprimir o arquivo antigo
{
    fclose(antigo);//FECHANDO ARQUIVO PARA ABRIR NOVAMENTE

    antigo=fopen("Concessionaria.CAD","r");

    //verificando se o arquivo foi aberto
    if(!antigo)
    {
        printf("O Arquivo nao foi aberto!!!");
        return 1;
    }

    char vet1[50]={0};
    printf("\n");
    while(!feof(antigo))
    {
        fgets(vet1, 50, antigo);
        printf("%s",vet1);
    }
    printf("\n\n");
    Sleep(1000);
    inicio();
}

imprimir2()//funçao para imprimir novo arquivo
{
    fclose(novo);
    novo=fopen("Concessionaria_novo.CAD","r");
    if(!novo)
    {
        printf("\nNao foi possivel ser aberto");
        return;
    }

    char vet1[50]={0};
    printf("\n");
    while(!feof(novo))
    {
        fgets(vet1, 50, novo);
        printf("%s",vet1);
    }
    Sleep(1000);
    denovo();
}

imprimir3()//função para imprimir o arquivo antigo
{
    fclose(antigo);//FECHANDO ARQUIVO PARA ABRIR NOVAMENTE

    antigo=fopen("Concessionaria.CAD","r");

    //verificando se o arquivo foi aberto
    if(!antigo)
    {
        printf("O Arquivo nao foi aberto!!!");
        return 1;
    }

    char vet1[50]={0};
    printf("\n");
    while(!feof(antigo))
    {
        fgets(vet1, 50, antigo);
        printf("%s",vet1);
    }
    Sleep(1000);
    denovo();
}

denovo()
{
    printf("\n|||||||||||||||||||||||||MENU|||||||||||||||||||||||||||||");
    printf("\n||||                 Ano Atual: 2011                  ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n||||             Oque vc deseja fazer?                ||||");
    printf("\n||||                                                  ||||");
    printf("\n||||      01-Imprimir o novo catalogo atualizado?     ||||");
    printf("\n||||      02-Deseja imprimir catalogo antigo?         ||||");
    printf("\n||||      03-Deseja fechar o programa?                ||||");
    printf("\n||||                                                  ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\nDigite a opção:");
    scanf("%d",&i);

    system("cls");
    switch(i)
    {
        case 1:
            imprimir2();
            break;
        case 2:
            imprimir3();
            break;
        case 3:
            fechar();
            break;
        default:
            printf("\nErro, tente novamente:");
            denovo();
    }

}

fechar()
{
    //LOADING
    printf("Fechando Programa");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);

    fclose(novo);
    fclose(antigo);
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n||||              Programa Fechado!!!                 ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    return;
}
