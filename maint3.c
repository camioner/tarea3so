#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
//tamaño de procesos definido aca
int random_between(int memory_size,int  min, double max){ 
    srand(time(NULL));

    // 2. Definir el rango deseado
    //double min = 1.5;
    //double max = 2.2;

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
    int virtual_memory = random_between(memory_size,1.5,4.5);

    // tamaño de la pagina 
    int tam_page;
    printf("Ingrese el tamaño de la página: ");
    scanf("%d", &tam_page);

    //crear los procesos cada 2 segundos
    bool lleno = false;
    while (!lleno)
    {
        sleep(2);
        //puedo crear una variable y modificarla constantemente pero guardo el valor en un stack , aunq 
        //cmo uedo hacer para que el valor sea guardado y se pueda ocupar?
        int proceso_size = random_between(memory_size,0.1,(double)memory_size);
        stack procesos; 
        processos.push(proceso_size);

        

/*
        int proceso[];
        int i=0;i++;
        //tamaño del proceso no puede ser mayor a la ram fisica
        proceso[i]=crear_proceso();
*/        
        
    }
    

    

    return 0;
}