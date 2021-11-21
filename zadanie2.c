#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Leibniz(int n) {
    float wynik = 0;
	int licznik = 0, mianownik = 0;
	
	int i;
    for(i = 1; i <= n; i++) {
		licznik = powf(-1, i - 1);
		mianownik = (2 * i) - 1;
        wynik += licznik / mianownik;
    }
	
    return wynik * 4;
}

int main() {
	int liczbaProcesow, n;
    printf("Podaj ile ma byc procesow:");
    scanf("%d", &liczbaProcesow);

	int p;
    for(p = 0; p < liczbaProcesow; p++) {
        if(fork() == 0) {
            srand(p + 1);
            n = 100 + rand() % 4901;
			
            printf("n = %d | PI = %f | numer procesu = %d\n", n, Leibniz(n), p);
            exit(0);
        }
    }
}
