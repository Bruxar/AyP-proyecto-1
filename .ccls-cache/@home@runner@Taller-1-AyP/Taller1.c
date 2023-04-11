#include <stdio.h>

// Función que cuenta la cantidad de dígitos impares en un número
int contarDigImpares(int numero) {
  int contador = 0;

  // Mientras haya dígitos en el número
  while (numero != 0) {
    int digito = numero % 10; // Tomamos el último dígito
    if (digito % 2 != 0) { // Si es impar
      contador++; // Aumentamos el contador
    }

    numero /= 10; // Eliminamos el último dígito
  }
  return contador;
}

// Función que cuenta la cantidad de dígitos pares en un número
int contarDigPares(int numero) {
  int contador = 0;

  // Mientras haya dígitos en el número
  while (numero != 0) {
    int digito = numero % 10; // Tomamos el último dígito
    if (digito % 2 == 0) { // Si es par
      contador++; // Aumentamos el contador
    }

    numero /= 10; // Eliminamos el último dígito
  }
  return contador;
}

// Función que cuenta la cantidad de números pares cuya cantidad de dígitos impares es también par
int cantidadPares(int a, int b) {
  int contador = 0;

  // Iteramos desde a hasta b
  for (int i = a; i <= b; i++) {
    if (i % 2 == 0 && contarDigImpares(i) % 2 == 0) {
      // Si i es par y la cantidad de dígitos impares es par, aumentamos el contador
      contador++;
    }
  }
  return contador;
}

// Función que suma los números impares cuya cantidad de dígitos pares es también impar
int sumaImpares(int a, int b) {
  int suma = 0;

  // Iteramos desde a hasta b
  for (int i = a; i <= b; i++) {
    if (i % 2 != 0 && contarDigPares(i) % 2 != 0) {
      // Si i es impar y la cantidad de dígitos pares es impar, sumamos i a la variable suma
      suma += i;
    }
  }
  return suma;
}

// Función que imprime los números cuya cantidad de dígitos pares es impar
void imprimirNumeros(int a, int b) {
  // Iteramos desde a hasta b
  for (int i = a; i <= b; i++) {
    if (contarDigPares(i) % 2 != 0) {
      // Si la cantidad de dígitos pares es impar, imprimimos i
      printf("%d\n", i);
    }
  }
}

int main() {
  int opcion, numero, a, b;

  do {
    printf("\033[0;0H\033[2J");
    printf("MENU\n");
    printf("1. Cantidad de dígitos impares.\n");
    printf("2. Cantidad de dígitos pares.\n");
    printf("3. Cantidad de números pares en [a, b] con cantidad par de dígitos impares\n");
    printf("4. Suma de numeros impares en [a, b] con cantidad impar de dígitos pares.\n");
    printf("5. Imprimir números en [a, b] con cantidad impar de dígitos pares.\n");
    printf("6. Salir.\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      printf("\033[0;0H\033[2J");
      printf("Ha seleccionado la opcion 1.\n");
      printf("Ingrese numero: ");
      scanf("%d", &numero);
      printf("Cantidad digitos impares: %d",contarDigImpares(numero));
      break;
    case 2:
      printf("\033[0;0H\033[2J");
      printf("Ha seleccionado la opcion 2.\n");
      printf("Ingrese numero: ");
      scanf("%d", &numero);
      printf("Cantidad digitos pares: %d",contarDigPares(numero));
      break;
    case 3:
      printf("\033[0;0H\033[2J");
      printf("Ha seleccionado la opcion 3.\n");
      printf("Ingrese intervalo a: ");
      scanf("%d", &a);
      printf("Ingrese intervalo b: ");
      scanf("%d", &b);
      printf("Cantidad de numeros: %d",cantidadPares(a, b));
      break;
    case 4:
      printf("\033[0;0H\033[2J");
      printf("Ha seleccionado la opcion 4.\n");
      printf("Ingrese intervalo a: ");
      scanf("%d", &a);
      printf("Ingrese intervalo b: ");
      scanf("%d", &b);
      printf("Suma de numeros: %d",sumaImpares(a, b));
      break;
    case 5:
      printf("\033[0;0H\033[2J");
      printf("Ha seleccionado la opcion 3.\n");
      printf("Ingrese intervalo a: ");
      scanf("%d", &a);
      printf("Ingrese intervalo b: ");
      scanf("%d", &b);
      imprimirNumeros(a, b);
      break;
    case 6:
      printf("Ha seleccionado salir. Adios!\n");
      break;
    default:
      printf("Opcion invalida. Por favor ingrese una opcion valida.\n");
      break;
    }
    getchar(); // esperamos a que el usuario presione enter para continuar
    getchar(); // usamos getchar() dos veces para asegurarnos de que se borre el buffer de entrada
  } while (opcion != 6);

  return 0;
}