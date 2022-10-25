#include <stdio.h>
#include <math.h>

int premier(int n) {
    if (n==1 || n%2==0)  return 0;
    for (int i=3;i<=sqrt(n);i+=2) {
        if (n%i==0) return 0; 
    }
    return 1;
}

void parfait2(long int n,int *bool) {
    long int somme=1;
    if (premier(n))  *bool=0;
    for (int i=2;i<=sqrt(n);++i) {
        if (n%i==0) {
            if (i==n/i) somme=somme+i;
            else somme=somme+(n/i)+i;
            if (somme>n) *bool=0;
        }
    }
    if (somme==n) *bool=1;
    else *bool=0;
}

void main() {
    long int n;
    int bool;
    printf("\nPROGRAMME IMPRIMANT LES NOMBRES PARFAITS INFERIEURS A N\n\nN : ");
    scanf("%ld",&n);
    parfait2(n,&bool);
    if (bool) printf("OUI");
}