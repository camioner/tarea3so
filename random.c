#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 1. Inicializar el generador de números aleatorios con la hora actual
    srand(time(NULL));

    // 2. Definir el rango deseado
    double min = 10.5;
    double max = 20.2;

    // 3. Generar un número aleatorio en el rango
    //  - rand() / RAND_MAX genera un número entre 0.0 y 1.0
    //  - Se multiplica por la diferencia entre max y min
    //  - Se suma el valor mínimo para desplazar el rango
    double numero_aleatorio = min + (rand() / (double)RAND_MAX) * (max - min);

    // 4. Imprimir el resultado
    printf("Número aleatorio entre %.2f y %.2f: %.2f\n", min, max, numero_aleatorio);

    return 0;
}
