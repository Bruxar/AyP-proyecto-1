#include <stdio.h>
#include <math.h>

typedef int numEntero[16]; // Definir un typedef para el arreglo

void desplegarNumero(numEntero numArray) {
    int i, entero=0;
    
     for (i = 0; i < 16; i++) {
        entero += numArray[i] * pow(10, i);
    }
    
     printf("\nEl numero entero es: %d\n", entero);
    
}

void crearArray(numEntero num){
    
    int num_digitos = 0;
    char continuar;
    
    do {
        int digito;
        while (1) {  // Ciclo para asegurarse de que se ingrese un número válido
            printf("\nIngrese un digito: ");
            scanf("%d", &digito);
            
            if (digito < 10) {
                break;  // Salir del ciclo si se ingresa un número válido
            } else {
                printf("Numero invalido. Debe ser menor que 10.\n");
            }
        }
        
        num[num_digitos] = digito;
        num_digitos++;
        
        printf("Desea agregar otro digito? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    int i;
    
    printf("\nEl array a usar sera: ");
    for(i=0;i<num_digitos;i++){
        printf("%d  ",num[i]);
    }
    printf("\n");
    desplegarNumero(num);
}

void suma(numEntero a, numEntero b, numEntero resultado){
    int acarreo = 0;
    for (int i = 0; i < 16; i++) {
        int suma = a[i] + b[i] + acarreo;
        resultado[i] = suma % 10;
        acarreo = suma / 10;
    }
    
    desplegarNumero(resultado);
}

void mult(numEntero a, numEntero producto, int n){
    int acarreo = 0;
    for(int i = 0; i<16;i++){
        int prod = a[i] * n + acarreo;
        producto[i] = prod % 10;
        acarreo = prod / 10;
    }
    
    desplegarNumero(producto);
}

int main()
{
    int opcion;

    do
    {
        printf( "\n   1. Ingresar un numero en el arreglo.");
        printf( "\n   2. Calcular la suma de 2 arreglos.");
        printf( "\n   3. Calcular la multiplicacion de un arreglo y un digito decimal");
        printf( "\n   4. Salir." );
        printf( "\n\n   Introduzca opcion (1-4): ");
        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1: 
                    numEntero numInicial;
                    crearArray(numInicial);
                    break;

            case 2: 
                    numEntero a,b,result;
                    crearArray(a);
                    crearArray(b);
                    suma(a,b,result);
                    break;

            case 3: numEntero a2,b2,res;
                    int n;
                    crearArray(a2);
                    printf("Ingrese digito decimal: ");
                    scanf("%d",&n);
                    mult(a2,res,n);
         }

         /* Fin del anidamiento */

    } while ( opcion != 4 );

    return 0;
}




