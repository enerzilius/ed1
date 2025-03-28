#include <stdio.h>

int main(){
    unsigned short int var = 0;
    short int var1 = 0;
    int var2 = 0;
    long int var3 = 0;
    printf("\n Size unsigned short int: %ld", sizeof(var));
    printf("\n Size short int: %ld", sizeof(var1));
    printf("\n Size int: %ld", sizeof(var2));
    printf("\n Size long int: %ld\n", sizeof(var3));
    
    return 0;
}
