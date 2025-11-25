#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "estructuras.c"

// tamaño de procesos definido aca
int random_between(int memory_size, double min, double max)
{

    double numero_aleatorio = min + (rand() / (double)RAND_MAX) * (max - min);
    int random_memory = memory_size * numero_aleatorio;
    return random_memory;
}

int page_usage(int proceso, int tam_page)
{
    int page_usage = proceso / tam_page;
    return page_usage;
}

int main()
{
    // para el aleatorio
    srand(time(NULL));

    // tamaño de memoria a ram
    int memory_size;
    printf("Ingrese el tamaño de memoria a reservar: ");
    scanf("%d", &memory_size);

    // memoria virtual para el swap
    int virtual_memory = random_between(memory_size, 1.5, 4.5);

    // tamaño de la pagina
    int tam_page;
    printf("Ingrese el tamaño de la página: ");
    scanf("%d", &tam_page);

    // crear los procesos cada 2 segundos
    bool lleno = false;
    queue *procesos = create_queue();

    while (!lleno)
    {
        sleep(2);
        int proceso_size = random_between(memory_size, 0.05, 1.0);

        enqueue(procesos, proceso_size);

        printf("Proceso creado: %d MB | Procesos en cola: %d\n", proceso_size, procesos->size);
        /*
                int proceso[];
                int i=0;i++;
                //tamaño del proceso no puede ser mayor a la ram fisica
                proceso[i]=crear_proceso();
        */
    }

    return 0;
}