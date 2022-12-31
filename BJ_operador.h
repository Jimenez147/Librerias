int num_primo(int X)
// Analiza un numero para saber si es primo
{
    int i, ress, R = 0;
    for (i = 1; i <= X; i++)
    {
        if (X % i == 0)
        {
            R += i;
        }
    }
    ress = (R == (X + 1)) ? 1 : 0;
    return ress;
}

int num_perfect(int X)
// Analiza un numero para saber si es perfecto
{
    int count = 0, ress, i;
    for (i = 1; i < X; i++)
    {
        if (X % i == 0)
        {
            count += i;
        }
    }
    ress = (count == X) ? 1 : 0;
    return ress;
}

int max_com_div_(int VEC[])
// Identifica cual es el maximo comun divisor entre los numeros de un arreglo
{
    int cant = 0, min, i = 0, j = 0, ress, aux = 0;
    while (VEC[i] != 0)
    {
        cant++;
        i++;
    }
    min = VEC[0];
    for (i = 1; i < cant; i++)
    {
        if (VEC[i] < min)
        {
            min = VEC[i];
        }
    }
    for (i = 1; i <= min; i++)
    {
        while (j < cant)
        {
            if (VEC[j] % i == 0)
            {
                aux++;
            }
            j++;
        }
        if (aux == cant)
        {
            ress = i;
        }
        aux = 0;
        j = 0;
    }
    return ress;
}

float min_com_mult(int VEC[])
// Identifica cual es el minimo comun multipo entre los numeros de un arreglo
// Utiliza los numeros primos hasta el 997
{
    int i = 0, l = 0, j = 0, k, primos[168] = {0}, factores[100] = {0}, cant = 0, bin = 0;
    float ress;
    while (VEC[i] != 0)
    {
        cant++;
        i++;
    }
    for ( i = 0; i < 1000; i++)
    {
        if (num_primo(i))
        {
            primos[j] = i;
            j++;
        }
    }
    
    for (i = 0; i < 168; i++)
    {
        do
        {
            bin = 0;
            for (k = 0; k < cant; k++)
            {
                if (VEC[k] % primos[i] == 0)
                {
                    VEC[k] /= primos[i];
                    bin = 1;
                }
            }
            if (bin)
            {
                factores[l] = primos[i];
                l++;
            }

        } while (bin);
        for (k = 0; k < cant; k++)
        {
            bin += VEC[k];
        }
        if (bin == cant)
        {
            break;
        }
        
    }
    ress = factores[0];
    for ( i = 1; i < l; i++)
    {
        ress *= factores[i];
    }
    return ress;
}
