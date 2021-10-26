#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>

//79
//32
FILE *clientes, *vendas, *compras;
int i;

int main()
{
    setlocale(LC_ALL, "Portuguese");//imprimir com acentos
    menu();
}

menu()//FUNÇÃO MENU
{

    printf("\n||||||||||||||||||||||||MENU||||||||||||||||||||||||");
    printf("\n||||            O Que Deseja Fazer              ||||");
    printf("\n||||                                            ||||");
    printf("\n||||        1-Fazer Novo Arquivo?               ||||");
    printf("\n||||        2-Imprimir Arquivo de Clientes?     ||||");
    printf("\n||||        3-Imprimir Arquivo de Vendas?       ||||");
    printf("\n||||        4-Fechar Programa?                  ||||");
    printf("\n||||                                            ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\nDigite a opção:");
    scanf("%d",&i);
    system("cls");
    switch(i)
    {
        case 1:
            fazer();
            break;
        case 2:
            imprimir();
            break;
        case 3:
            imprimir2();
            break;
        case 4:
            fechar();
            break;
        default:
            printf("\nERRO NA LEITURA!!!.DIGITE NOVAMENTE\n");
            Sleep(1100);
            system("pause");
            system("cls");
            menu();
    }
}

fechar()//FUNÇÃO PARA FECHAR PROGRAMA
{
    printf("Fechando Programa");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    fclose(clientes);
    fclose(vendas);
    fclose(compras);
    return;
}

imprimir()//FUNÇÃO PARA IMPRIMIR O ARQUIVO "CLIENTES.CAD"
{
    char vet[80];

    fclose(clientes);//FECHAR SE O ARQUIVO ESTIVER ABERTO
    clientes=fopen("Clientes.CAD","r");//ABRIR NOVAMENTE
    if(!clientes)//VERIFICAR SE FOI ABERTO
    {
        printf("\nERRO AO ABRRIR O ARQUIVO");
        return;
    }
    printf("\n");
    while(!feof(clientes))
    {
        fgets(vet,80,clientes);
        printf("%s",vet);
    }
    printf("\n\n");
    Sleep(1000);
    system("pause");
    menu();
}

imprimir2()//FUNÇÃO PARA IMPRIMIR O ARQUIVO "VENDAS.CAD"
{
    char vet[33];

    fclose(vendas);//FECHAR PARA SE O ARQUIVO ESTIVER ABERTO
    vendas=fopen("Vendas.CAD","r");
     if(!vendas)//VERIFICAR SE FOI ABERTO
    {
        printf("\nERRO AO ABRRIR O ARQUIVO");
        return;
    }
    printf("\n\n");
    while(!feof(vendas))
    {
        fgets(vet,80,vendas);
        printf("%s",vet);
    }
    printf("\n\n");
    Sleep(1000);
    system("pause");
    menu();
}

fazer()
{
    char id[7]={},idc[7]={},id2[7]={};
    char nome[21]={}, pr[21]={};
    char ed[41]={};
    char nu[12]={};
    char se[2]={};
    int r;
    //LOADING
    printf("Carregando novo arquivo");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");
    Sleep(500);
    printf(".");

    fclose(clientes);//FECHAR SE O ARQUIVO ESTIVER ABERTO
    clientes=fopen("Clientes.CAD","r");//ABRIR NOVAMENTE
    if(!clientes)//VERIFICAR SE FOI ABERTO
    {
        printf("\nERRO AO ABRRIR O ARQUIVO");
        return;
    }

    fclose(compras);
    compras=fopen("Compras.CAD","w");

    while(!feof(clientes))
    {
        fgets(id,7,clientes);
        fgets(nome,21,clientes);
        fgets(ed,41,clientes);
        fgets(nu,12,clientes);
        fgets(se,2,clientes);
        fscanf(clientes,"\n");

        fclose(vendas);//FECHAR PARA SE O ARQUIVO ESTIVER ABERTO
        vendas=fopen("Vendas.CAD","r");
        if(!vendas)//VERIFICAR SE FOI ABERTO
        {
            printf("\nERRO AO ABRRIR O ARQUIVO");
            return;
        }
        while(!feof(vendas))
        {
            fgets(idc,7,vendas);
            fgets(id2,7,vendas);
            fgets(pr,21,vendas);
            fscanf(vendas,"\n");

            r=strncmp(id,id2,6);

            if(r==0)
            {
                fprintf(compras,"%s %s\n",nome,pr);
            }
        }

    }
    system("cls");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n||||          Arquivo Compras Feitas            ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    system("pause");

    menu2();
}

menu2()
{
    printf("\n||||||||||||||||||||||||MENU||||||||||||||||||||||||");
    printf("\n||||            O Que Deseja Fazer              ||||");
    printf("\n||||                                            ||||");
    printf("\n||||        1-Imprimir o novo arquivo?          ||||");
    printf("\n||||        2-Imprimir Arquivo de Clientes?     ||||");
    printf("\n||||        3-Imprimir Arquivo de Vendas?       ||||");
    printf("\n||||        4-Fechar Programa?                  ||||");
    printf("\n||||                                            ||||");
    printf("\n||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\nDigite a opção:");
    scanf("%d",&i);
    system("cls");
    switch(i)
    {
        case 1:
            imprimir3();
            break;
        case 2:
            imprimir();
            break;
        case 3:
            imprimir2();
            break;
        case 4:
            fechar();
            break;
        default:
            printf("\nERRO NA LEITURA!!!.DIGITE NOVAMENTE\n");
            Sleep(1100);
            system("pause");
            system("cls");
            menu();
    }
}

imprimir3()//IMPRIMIR ARQUIVO "COMPRAS.CAD"
{
    int r;
    char vet[42], vet1[42];
    fclose(compras);
    compras=fopen("Compras.CAD","r");
    if(!compras)
    {
        printf("O arquivo 'Compras.CAD' nao foi aberto");
        return;
    }
    while(!feof(compras))
    {
        fgets(vet,42,compras);
        printf("%s",vet);

    }
    printf("\n");
    Sleep(1000);
    system("\npause");
    menu2();
}



