# PRiR_LAB5_2

Zadanie 2 z laboratoriów numer 5 z przedmiotu PRiR. Program pyta użytkownika o liczbę procesów a następnie dla każdego procesu ustawia orginalne ziarno losuje n z przedziału 
<100,5000> i przy pomocy tego n używając wzoru Leibniz'a oblicza przybliżenie pi.

Opis kodu:

Import potrzebych bibliotek

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

w main użytkownik pytany jest o liczbę procesów następnie dla każdego procesu sprawdzane jest czy fork() jest równe 0 ustawiane jest ziarno i losowana jest liczba n.
Następnie wywoływana jest funkcja licząca przybliżenie liczby pi i wyświetlającą ją z odpowiednim komunikatem.

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
    
Funckja Leibinz liczy na podstawie wzoru przybliżenie liczby pi

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
