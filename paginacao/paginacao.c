/*********
 * Simple simulation of pagination
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Computational Systems discipline
 */

#include <stdio.h>

typedef struct moldura {
    int bv;
    char contentRAM;
} frame;

typedef struct pagina {
    int bv;
    char contentDISCO;
    frame *pv;
} page;

int main() {

    page DISCO[20];
    frame RAM[2];
    char i, j;

    /* Inicialização da RAM */
    for (i = 0; i < 2; i++)
        RAM[i].bv = 0;

    /* Paginação */
    for (i = 0; i < 20; i++) {

        DISCO[i].contentDISCO = 'a' + i;    /* 97 + i */
        DISCO[i].bv = 1;
        DISCO[i].pv = NULL;

        /* simulação que a 5a e a 10a páginas são mais usadas, então sobe na RAM */
        if (DISCO[i].contentDISCO == 'e' || DISCO[i].contentDISCO == 'j') {
            for (j = 0; j < 2; j++) { /* aloca mais usado no 1o espaço da RAM disponível */
                if (RAM[j].bv == 0) {
                    RAM[j].bv = 1;
                    DISCO[i].pv = &RAM[j]; /* ponteiro do DISCO tem endereço da RAM que guarda a página */
                    RAM[j].contentRAM = DISCO[i].contentDISCO;
                    break;
                }
            }
        }

    }

    printf("\n\nvisualizacao DISCO\n");

    for (i = 0; i < 20; i++) {
        printf("%02d page [content:%c", i + 1, DISCO[i].contentDISCO);
        printf(" BV:%d", DISCO[i].bv);
        printf(" RAM:%d]\n", DISCO[i].pv);
    }

    printf("\nvisualizacao RAM\n");

    for (i = 0; i < 2; i++) {
        printf("%02d frame [content:%c", i + 1, RAM[i].contentRAM);
        printf(" BV:%d]\n", RAM[i].bv);
    }

    printf("\n\n");

    return 0;

}
