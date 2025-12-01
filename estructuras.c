#include <stdio.h>
#include <stdlib.h>

typedef struct Pagina {
    int frame;      // número de frame donde está alojada la página
    int en_ram;     // 1 si está en RAM, 0 si está en SWAP
} Pagina;

// estructura del proceso
typedef struct Proceso {
    int pid;            // identificador de proceso
    int size;           // tamaño del proceso
    int paginas;        // cantidad de pagina que ocupa
    Pagina *tabla_paginas; // arreglo de pagina
    struct Proceso *next;
} Proceso;

// cola simple
typedef struct queue {
    Proceso *front;
    Proceso *rear;
    int size;
} queue;

// crear cola
queue *create_queue() {
    queue *q = malloc(sizeof(queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// crear proceso con tabla de pagina inicializada
Proceso *crear_proceso(int pid, int size, int page_size) {

    Proceso *nuevo = malloc(sizeof(Proceso));
    nuevo->pid = pid;
    nuevo->size = size;

    // calculo simple de pagina: ceil(size/page_size)
    nuevo->paginas = (size + page_size - 1) / page_size;

    // tabla de pagina vacía
    nuevo->tabla_paginas = malloc(sizeof(Pagina) * nuevo->paginas);
    for (int i = 0; i < nuevo->paginas; i++) {
        nuevo->tabla_paginas[i].frame = -1; // sin asignar
        nuevo->tabla_paginas[i].en_ram = 0; // por defecto en swap
    }

    nuevo->next = NULL;
    return nuevo;
}

// encolar proceso
void enqueue(queue *q, Proceso *p) {
    if (q->rear == NULL) {
        q->front = q->rear = p;
        q->size++;
        return;
    }
    q->rear->next = p;
    q->rear = p;
    q->size++;
}

// desencolar proceso
Proceso *dequeue(queue *q) {
    if (q->front == NULL) {
        return NULL;
    }
    Proceso *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    q->size--;
    return temp;
}
