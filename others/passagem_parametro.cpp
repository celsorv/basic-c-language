/*
  Passagem de parâmetro por valor e por referência
*/

#include <iostream>
using namespace std;

int* por_valor(int* p) {
    printf("por_valor: endereço= %d, conteúdo= %d **antes**\n", &p, *p);      // o valor de p é outro, recebeu o endereço de uma CÓPIA da variável no chamador
    p = new int;
    *p = 7;
    printf("por_valor: endereço= %d, conteúdo= %d **depois**\n\n", &p, *p);   // o valor de p é outro, recebeu o endereço de uma CÓPIA da variável no chamador
    return p;
}

int* por_referencia(int*& p) {
    printf("por_refer: endereço= %d, conteúdo= %d **antes**\n", &p, *p);      // o valor de p é o mesmo, recebeu o mesmo endereço da variável no chamador
    p = new int;
    *p = 7;
    printf("por_refer: endereço= %d, conteúdo= %d **depois**\n\n", &p, *p);   // o valor de p é o mesmo, recebeu o mesmo endereço da variável no chamador
    return p;
}


int main() {

    int a = 1;
    int *p1 = &a;

    printf("__main__: endereço= %d, conteúdo= %d **antes**\n\n", &p1, *p1);
    
    printf(">> %d\n\n", *por_referencia(p1));

    printf("__main__: endereço= %d, conteúdo= %d **depois**\n", &p1, *p1);

    return 0;
}
