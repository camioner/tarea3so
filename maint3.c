#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//tamaño de procesos definido aca
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

int page_usage(int proceso, int tam_page){
    int page_usage = proceso / tam_page;
    return page_usage;
}

int main(){
    //tamaño de memoria a ram
    int memory_size ;
    printf("Ingrese el tamaño de memoria a reservar: ");
    scanf("%d", &memory_size);

    //memoria virtual para el swap
    int virtual_memory = random_between(memory_size);

    // tamaño de la pagina 
    int tam_page;
    printf("Ingrese el tamaño de la página: ");
    scanf("%d", &tam_page);

    //crear los procesos cada 2 segundos
    bool lleno = false;
    while (!lleno)
    {
        sleep(2);
        //tamaño del proceso 
        
        
    }
    

    

    return 0;
}