#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int random_between(int memory_size){ 
    srand(time(NULL));

    // 2. Definir el rango deseado
    double min = 10.5;
    double max = 20.2;

    // 3. Generar un número aleatorio en el rango
    //  - rand() / RAND_MAX genera un número entre 0.0 y 1.0
    //  - Se multiplica por la diferencia entre max y min
    //  - Se suma el valor mínimo para desplazar el rango
    double numero_aleatorio = min + (rand() / (double)RAND_MAX) * (max - min);
    int random_memory = memory_size * numero_aleatorio ;
    return random_memory;
}   

int main(){
    int memory_size ;
    printf("Ingrese el tamaño de memoria a reservar: ");
    scanf("%d", &memory_size);
    int virtual_memory = random_between(memory_size);
    printf("Tamaño de memoria virtual asignada: %d\n", virtual_memory);
    

    return 0;
}