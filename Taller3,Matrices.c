#include <stdio.h>
#define tamañoMax 16

typedef int matrizTriangular[tamañoMax][tamañoMax];  // Definición de tipo para la matriz triangular

void crearTII(matrizTriangular matriz, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            if (j > i) {
                matriz[i][j] = 0;  // Llena la matriz triangular superior izquierda con ceros
            }
            else {
                printf("Ingrese el elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);  // Solicita al usuario ingresar el valor del elemento
            }
        }
    }
}

void crearTSD(matrizTriangular matriz, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            if (j < i) {
                matriz[i][j] = 0;  // Llena la matriz triangular superior derecha con ceros
            }
            else {
                printf("Ingrese el elemento [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);  // Solicita al usuario ingresar el valor del elemento
            }
        }
    }
}

void traspuesta(matrizTriangular matriz, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        for (int j = i + 1; j < tamaño; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];  // Intercambia los elementos de la matriz en posición (i, j) y (j, i)
            matriz[j][i] = temp;
        }
    }
}

void generarMatriz(int tamaño, char tipo) {
    matrizTriangular matriz;

    if (tipo == 'I' || 'i') {
        crearTII(matriz, tamaño);  // Genera una matriz triangular superior izquierda
    }
    else if (tipo == 'D' || 'd') {
        crearTSD(matriz, tamaño);  // Genera una matriz triangular superior derecha
    }
    else {
        printf("Tipo de matriz inválido. Saliendo...\n");
        return;
    }

    printf("Matriz generada:\n");
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            printf("%d ", matriz[i][j]);  // Imprime los elementos de la matriz generada
        }
        printf("\n");
    }
}

void generarMatrizTraspuesta(int tamaño, char tipo) {
    matrizTriangular matriz;

    if (tipo == 'I' || 'i') {
        crearTII(matriz, tamaño);  // Genera una matriz triangular superior izquierda
    }
    else if (tipo == 'D' || 'd') {
        crearTSD(matriz, tamaño);  // Genera una matriz triangular superior derecha
    }
    else {
        printf("Tipo de matriz inválido. Saliendo...\n");
        return;
    }

    printf("Matriz original:\n");
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            printf("%d ", matriz[i][j]);  // Imprime los elementos de la matriz original
        }
        printf("\n");
    }

    traspuesta(matriz, tamaño);  // Obtiene la traspuesta de la matriz

    printf("Matriz traspuesta:\n");
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            printf("%d ", matriz[i][j]);  // Imprime los elementos de la matriz traspuesta
        }
        printf("\n");
    }
}

int main() {
    int opcion, tamaño;
    char tipo;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Generar Matriz Triangular\n");
        printf("2. Generar Matriz Triangular Traspuesta\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        printf("\033c");  // Limpia la pantalla

        switch (opcion) {
            case 1:
                printf("Ingrese el tamaño de la matriz: ");
                scanf("%d", &tamaño);
                printf("Ingrese el tipo de matriz (I para TII o D para TSD): ");
                scanf(" %c", &tipo);
                generarMatriz(tamaño, tipo);
                break;
            case 2:
                printf("Ingrese el tamaño de la matriz: ");
                scanf("%d", &tamaño);
                printf("Ingrese el tipo de matriz (I para TII o D para TSD): ");
                scanf(" %c", &tipo);
                generarMatrizTraspuesta(tamaño, tipo);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}

