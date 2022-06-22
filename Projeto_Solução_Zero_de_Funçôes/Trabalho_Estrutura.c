#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               Informaçoes:
//Membros Grupo: Moises Nascimento Dearo e Gabriel Soleira Borges
//Curso: Bacharel em Ciencias da Computação - Noturco
//Materia: Calculo Numerico
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define log10(x) log(x)/log(10);


// 0 = Não | 1 = Sim

//Equações: 1 (x^3)+(x)-1000 ; 2 (3x^4)-(x)-1 ; 3 (Nao polinomial)

//Métodos: Bissecção, metodo de Newton(Derivada)

//////////////////////// Rotinas //////////////////////////////////////

float Bissecao(int f ,float a0, float b0, float eps, int inte);

float Derivada(int f, float x);

float Newton(int f, float erro, float mp, int inte);

//int interacoes(int a0, int b0, float eps);

//////////////////////// Calculo das Funçoes ///////////////////////////

float f1(float x) {
return pow(x,3)+x-1000; // Função cuja raiz deve ser determinada
}

float f2(float x) {
return pow(3*x,4)-x-1; // Função cuja raiz deve ser determinada
}

float f3(float x) {
return (4*cos(x)/x)-5; // Função cuja raiz deve ser determinada
}

//////////////////////// Variaveis de Controle ///////////////////////////////

int Met_Sol; //Metodo de solução


//////////////////////// Função Principal /////////////////////////////////////
int main()
{
int q_interacoes;
int p, op_equa; //p = coordena re-calculo | op_equa = oscolha da equação | a0, b0 = intervalo inicial
float e, a0, b0, result; //erro

do   
{
    printf("Qual Equação deseja resolver? \n");
    printf("(x^3)+(x)-1000 \n"); //Equação 1
    printf("(3x^4)-(x)-1 \n"); //Equação 2
    printf("4*cos(x)/x-5 \n"); //Equação 3
    scanf("%d", &op_equa);
    printf("///////////////////////////\n");
    printf("1 = Bisseccao\n");
    printf("2 = Metodo de Newton\n");
    printf("Qual metodo? \n");
    scanf("%d", &Met_Sol);
    switch (Met_Sol)  
    {
        case 1:
        {
            printf("Qual o desvio? ");
            scanf(" %f", &e);
            printf("Qual o intervalo?\n");   
            printf("inicio: ");
            scanf(" %f", &a0);
            printf("Fim: ");
            scanf(" %f", &b0);

            q_interacoes = log10(b0 - a0)-log10(e);
            q_interacoes -= log10(e);
            q_interacoes /= log10(2);

            result = Bissecao(op_equa, a0, b0, e, q_interacoes);
            if (result == 0)
            {
                printf("Nao foi encontrado raiz no intervalo [%d,%d]", a0,b0);
            }
            else
            {
                printf("\n");
                printf("A raiz da funcao é: %f", result);
            }
            
            break;
        }
        case 2:
        {
            printf("Qual o desvio? ");
            scanf("%f", &e);  
            printf("inicio(obs: !=0): ");
            scanf(" %f", &a0);
            result = Newton(op_equa, e, a0, q_interacoes);
            printf("A raiz da funcao é: %f", result);
            break;
        }
        default:
            break;
    }
    printf("\n");
    printf("\n");
    printf("Deseja continuar a calcular? 0 = Não|1 = Sim");

    scanf(" %d", &p);
} while (p!=0);
}

////////////// Bissecção ////////////// Bissecção ////////////// Bissecção ////////////// Bissecção ////////////// Bissecção //////////////////////////////////////////// 

float Bissecao(int f ,float a0, float b0, float eps, int inte) //Inserir ponteiro por referencia para alocar saidas (quantidade de interaçoes e raiz)
{
int tam, i=0;
float pm;

tam = b0- a0;

//if(f1(a0)*f1(b0) > 0)
//{
//    return 0;
//}

while(i<inte) 
{
    tam = b0-a0;
    pm = (a0+b0)/2; 

    if (f == 1)
    {
        if(f1(pm) == 0) 
        {
            return pm;
        }
        if(f1(a0)*f1(pm) < 0)
        {
            b0 = pm; // a solução está a esquerda
        }
        else
        {
            a0 = pm; // a solução está a direita
            i++;
        }
    }
    else if (f == 2)
    {
        if(f2(pm) == 0) 
        {
            return pm;
        }
        if(f2(a0)*f2(pm) < 0)
        {
            b0 = pm; // a solução está a esquerda
        }
        else
        {
            a0 = pm; // a solução está a direita
            i++;
        }
    }
    else if (f == 3)
    {
        if(f3(pm) == 0) 
        {
            return pm;
        }
        if(f3(a0)*f3(pm) < 0)
        {
            b0 = pm; // a solução está a esquerda
        }
        else
        {
            a0 = pm; // a solução está a direita
            i++;
        }
    }
}
    printf("A quantidade de interacoes feitas foi: %d\n", i);
    return pm;
}

////////////// Derivada  ////////////// Derivada  ////////////// Derivada  ////////////// Derivada  ////////////// Derivada /////////////////////////

float Derivada(int f, float x) //Utilizar metodo ja tendo suas derivadas.
{

if (f == 1)
{
    return 3*(x*x)+1;
}
else if (f == 2)
{
    return 324*(x*x*x)-1;
}
else if (f == 3)
{
    return -4*pow(x,-2)*(x*sin(x)+cos(x));
}
}

//////////////  Newton  //////////////  Newton  //////////////  Newton  //////////////  Newton  //////////////  Newton  //////////////  Newton  /////////////////////////////////

float Newton(int f, float erro, float mp, int inte)
{

int i=0;
float erro_local = 1, save;

if (f == 1)
{
    while (erro_local > erro)
    {
        save = mp;
        mp = save - (f1(mp)/Derivada(f, mp));
        erro_local = save - mp;
        if (erro_local<0)
        {
            erro_local = (-1)*erro_local;
        }
        i++;
    }
    printf("A quantidade de interacoes feitas foi: %d\n", i);
    return mp;
}

else if (f == 2)
{
    while (erro_local > erro)
    {                                    
        save = mp;
        mp = save - (f2(mp)/Derivada(f, mp));
        erro_local = save - mp;
        if (erro_local<0)
        {
            erro_local = (-1)*erro_local;
        }
        i++;
    }
    printf("A quantidade de interacoes feitas foi: %d\n", i);
    return mp;
}
else if (f == 3)
{
   while (erro_local > erro)
    {                                    
        save = mp;
        mp = save - (f3(mp)/Derivada(f, mp));
        erro_local = save - mp;
        if (erro_local<0)
        {
            erro_local = (-1)*erro_local;
        }
        i++;
    }
    printf("A quantidade de interacoes feitas foi: %d\n", i);
    return mp;
}
}
