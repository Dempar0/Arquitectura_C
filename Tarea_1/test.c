// Programa de fibbonacci
#include <stdio.h>

void printFib(int n) {
  
  	// 
    if (n < 1) {
        printf("Cantidad de terminos invalidos\n");
        return;
    }
  
  	// Primeros terminos de la serie
    int b = 1;
    int a = 0;

    // Loop del fibonnacci
    for (int i = 1; i <= n; i++) {
      	
      	// Imprime los terminos del fibbonacci
        if (i > 2) {
            int c = b + a;
            a = b;
            b = c;
            printf("%d ", c);
        }
		else if (i == 1)
            printf("%d ", a);
        else if (i == 2)
            printf("%d ", b);
    }
}

int main() {
    int n = 9;
  
  	// Funcion del fibbonacci
    printFib(n);
    
    return 0;
}
