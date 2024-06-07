#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int variable;
    int *puntero;

    variable = 5;
    puntero = &variable;

    printf("Variable: %d\n", variable);
    printf("Puntero: %d\n", *puntero);

    *puntero = 8;
    printf("Variable: %d\n",variable);
    printf("Puntero: %d\n", *puntero);
    
    return 0;
}
