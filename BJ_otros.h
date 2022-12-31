#include <stdio.h>
#include <time.h>

void notac_cientf(double ress, int XX)
// Imprime una cantidad especificada en notacion cientifica
// Usa dos variable: N = cantidad deseada; XX = cantidad de decimales deseados
{
    int expo = 0, temp;
    if (!(ress < 1 && ress > -1))
    {
        while (ress > 10 || ress < -10)
        {
            ress /= 10;
            expo++;
        }
    }
    else
    {
        while (!(ress > 1 || ress < -1))
        {
            ress *= 10;
            expo++;
        }
        expo = -expo;
    }
    temp = ress;
    ress -= temp;
    for (size_t i = 0; i < XX; i++)
    {
        ress *= 10;
    }
    if (ress < 0)
    {
        ress -= ress * 2;
    }
    printf("\t%d.%.0lfx10^%i", temp, ress, expo);
}

void digit(int cant, int VEC[])
// Recive un numero y divide sus digitos en los espacios de un arreglo especificado
// Los digitos quedan ordenados en un orden contrario al intuitivo
{
    int i = 0;
    while (cant > 0)
    {
        VEC[i] = cant % 10;
        cant /= 10;
        i++;
    }
}

void hoy(int VEC[])
// Funcion que se encarga de la asignacion automatica de la fecha
{
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    VEC[0] = tlocal[0].tm_mday;
    VEC[1] = tlocal[0].tm_mon + 1;
    VEC[2] = tlocal[0].tm_year + 1900;
}

void ordena(int VEC[], int tam, char sig)
// Ordena un arreglo unidimencional de forma ascendente o descendente
/* Recibe el arreglo, el tamaño del arreglo y el signo que especifique el orden; 
de mayor a menor (>)  o de menor a mayor (<)*/
{
    int i, j, r;
    switch (sig)
    {
    case '>':
        for (i = 1; i < tam; i++)
        {
            r = i;
            j = VEC[i];
            while (r > 0 && j > VEC[r - 1]) 
            {
                VEC[r] = VEC[r - 1];
                r = r - 1;
            }
            VEC[r] = j;
        }

        break;
    case '<':
        for (i = 1; i < tam; i++)
        {
            r = i;
            j = VEC[i];
            while (r > 0 && j < VEC[r - 1])
            {
                VEC[r] = VEC[r - 1];
                r = r - 1;
            }
            VEC[r] = j;
        }
        break;
    default:
        printf("\nError en el signo colocado\n");
        break;
    }
}
