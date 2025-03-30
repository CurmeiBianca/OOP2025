#include "Number.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
    Number n1("20050218", 10);
    Number n2("1711", 8);
    Number n3("CB", 16);

    printf("n1 = 20050218");

    printf("\nn1 are %d caractere si este scris in baza %d\n", n1.GetDigitsCount(), n1.GetBase());
    for (int i = 0; i < n1.GetDigitsCount(); i ++)
    {
        printf("n1[%d]=%c\n", i, n1[i]);
    }
    n1.Print();

    printf("\n");

    printf("n2 = 1711\n");
    n2.Print();
    printf("\nn3 = CB\n");
    n3.Print();
    n1 = (n2 + n3 - n1) + n1; // dupa aceasta atribuire, n1 va fi in baza 16 = max (n1.base = 10, n2.base = 8, n3.base = 16)
    printf("\nn1 = (n2 + n3 - n1) + n1\n");
    n1.Print();
    n1.SwitchBase(2);
    n1.Print();

    if (n1 > n2) 
        printf("\nn1 este mai mare decat n2\n"); 
    else 
        printf("\nn2 este mai mare decat n1\n");

    Number n4 = 2468; // n4.base = 10
    n1 = 227; // n1 va fi 11 100 011 (valoarea lui 227 din baza 10 in baza 2)
    n4 = n4 + n1;
    printf("\nn4 = n4 + n1\n");
    n4.Print();

    n4 = "13579"; // n4 isi pastreaza baza 10, si va fi 13579
    printf("\nn4 = %s\n", "13579");
    n4.Print();

    --n4; // prima cifra din n4 va fi eliminata ==> n4 va deveni 3579
    printf("\n--n4\n");
    n4.Print();

    n4--; // ultima cifra din n4 va fi eliminata ==> n4 devine 357
    printf("\nn4--\n");
    n4.Print();

    ++n2; 
    printf("\n++n2\n");
    n2.Print();

    n2++;
    printf("\nn2++\n");
    n2.Print();

    return 0;
}
