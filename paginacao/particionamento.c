/*********
 * Simple simulation of fixed partitioning
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Computational Systems discipline
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned int bv;    /* 0 = partição ativa */
    char processo[5];
} particao;

int alocar_RAM(particao*);
void mostrar_RAM(particao*);
void encerrar_processo(char, particao*);

int main() {

    particao RAM[10];
    char i;

    /* Inicialização */
    for (i = 0; i < 10; i++)
        RAM[i].bv = 0;

    /* Alocacao. Será ideal transformar em função */
    if (!alocar_RAM(RAM)) goto finaliza;

    /* Simulação do processador encerrando execução de processo */
    encerrar_processo(3, RAM);
    encerrar_processo(9, RAM);

    /* Visualização da RAM simulada.*/
    mostrar_RAM(RAM);

    /* Nova alocação */
    if (!alocar_RAM(RAM)) goto finaliza;

    /* Nova visualização da RAM simulada.*/
    mostrar_RAM(RAM);

finaliza:
    printf("\n\n----- BYE\n\n");
    return 0;

}

int alocar_RAM(particao *RAM) {

    printf("\n\n");
    
    for (char i = 0; i < 10; i++) {
        particao *pRAM = (RAM + i);

        if (pRAM->bv == 0) {
            pRAM->bv = 1;
            printf("Digite um processo (x = fim): ");
            scanf("%s", pRAM->processo);
            if (pRAM->processo[0] == 'x' || pRAM->processo[0] == 'X')
                return 0;
        }
    }

    return 1;
}

void mostrar_RAM(particao *RAM) {

    printf("\nStatus da RAM\n");
    
    for (char i = 0; i < 10; i++) {
        particao *pRAM = (RAM + i);
        printf("%02da Particao da RAM: [%d][%s]\n", i + 1, pRAM->bv, pRAM->processo);
    }

}

void encerrar_processo(char numero, particao *RAM) {

    particao *pRAM = RAM + numero - 1;

    pRAM->bv = 0;
    strcpy(pRAM->processo, "");
    printf("\n%do Processo finalizado\n", (int) numero);
}
