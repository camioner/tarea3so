#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "./estructuras.c"


// tamaño de procesos definido aca
int random_between(int memory_size, double min, double max)
{
    double x = min + (rand() / (double)RAND_MAX) * (max - min);
    return memory_size * x;
}

int page_usage(int proceso, int tam_page)
{
    if (tam_page == 0) return 0;
    return (proceso + tam_page - 1) / tam_page;  // redondeo hacia arriba
}

int main()
{
    srand(time(NULL));

    // memoria física
    int memory_size;
    printf("Ingrese el tamaño de memoria a reservar: ");
    scanf("%d", &memory_size);

    // memoria virtual
    int virtual_memory = random_between(memory_size, 1.5, 4.5);

    // tamaño de página
    int page_size;
    printf("Ingrese el tamaño de la página: ");
    scanf("%d", &page_size);

    int frames = memory_size / page_size;   // RAM
    int pages  = virtual_memory / page_size; // SWAP

    int ram[frames];
    int swap[pages];

    // inicializar memoria
    for (int i = 0; i < frames; i++) ram[i] = -1;
    for (int i = 0; i < pages; i++)  swap[i] = -1;

    queue *procesos = create_queue();

    int tiempo_simulacion = 0;
    int next_free_ram = 0;
    int next_free_swap = 0;
    int pid_counter = 0;

    while (1)
    {
        sleep(1);
        tiempo_simulacion++;
        printf("\n[Tiempo: %d s] ", tiempo_simulacion);

        if (tiempo_simulacion % 2 == 0)
        {
            int proceso_size = random_between(memory_size, 0.05, 1.0);

            Proceso *p = crear_proceso(pid_counter, proceso_size, page_size);
            enqueue(procesos, p);

            printf("Proceso creado PID %d | Tamaño %d MB | Paginas %d\n",
                   p->pid, p->size, p->paginas);

            // asignar sus páginas
            for (int i = 0; i < p->paginas; i++)
            {
                if (next_free_ram < frames)
                {
                    ram[next_free_ram] = p->pid;
                    p->tabla_paginas[i].frame = next_free_ram;
                    p->tabla_paginas[i].en_ram = 1;

                    printf("  Página %d → RAM[%d]\n", i, next_free_ram);
                    next_free_ram++;
                }
                else if (next_free_swap < pages)
                {
                    swap[next_free_swap] = p->pid;
                    p->tabla_paginas[i].frame = next_free_swap;
                    p->tabla_paginas[i].en_ram = 0;

                    printf("  Página %d → SWAP[%d]\n", i, next_free_swap);
                    next_free_swap++;
                }
                else
                {
                    printf("\nMEMORIA LLENA.\n");
                    return 0;
                }
            }

            pid_counter++;
        }


       if (tiempo_simulacion > 30 && tiempo_simulacion % 5 == 0)
        {
            // MATAR PROCESO
            Proceso *kill = dequeue(procesos);
            if (kill != NULL)
            {
                printf("Terminando proceso PID %d\n", kill->pid);

                // liberar memoria
                for (int i = 0; i < kill->paginas; i++)
                {
                    if (kill->tabla_paginas[i].en_ram)
                    {
                        ram[kill->tabla_paginas[i].frame] = -1;
                    }
                    else
                    {
                        swap[kill->tabla_paginas[i].frame] = -1;
                    }
                }
            }

            // 2) ACCESO A UNA DIRECCIÓN VIRTUAL RANDOM
            int acceso = rand() % (virtual_memory);
            int pagina_accedida = acceso / page_size;

            printf("Acceso virtual %d → página %d\n", acceso, pagina_accedida);

            // page fault simple (revisamos si página está en RAM)
            bool found_in_ram = false;
            for (int i = 0; i < frames; i++)
            {
                if (ram[i] != -1) {
                    found_in_ram = true;
                    break;
                }
            }

            if (!found_in_ram)
            {
                printf("PAGE FAULT página de SWAP a RAM\n");

                int pos = -1;
                for (int i = 0; i < frames; i++)
                {
                    if (ram[i] == -1)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1)
                {
                    printf("Reemplazo en RAM[0]\n");
                    pos = 0;
                }

                ram[pos] = 999; // PID falso solo para mostrar movimiento
            }
        }
    }

    return 0;
}

