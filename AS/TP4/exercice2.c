#include <stdio.h>
#include <stdlib.h>


int** MatriceCrea(int lign, int col)
{
    int** M;
    M = (int**)malloc(lign* sizeof(int*));
    for(int i = 0; i <= lign-1; i++)
    {
        *(M+i) = (int*)malloc(col* sizeof(int));
    }
    return M;
}


void MatriceLigne(int lign, int col, int**matrice)
{
    int element;
     printf("[ligne %d][colonne %d]= ", lign, col);
     scanf("%d", &element);
     *(*(matrice+lign-1)+col-1) = element;
}

int** Creation(int lign, int col)
{
    int element;
    int** M;
    M = (int**)malloc(lign* sizeof(int*));
    for( int i = 0; i < lign; i++)
    {
        *(M+i) = (int*)malloc(col* sizeof(int));
        for(int j = 0; j < col; j++)
        {
            printf("[%d][%d]= ", i+1, j+1);
            scanf("%d", &element);
            *(*(M+i)+j) = element;
        }
    }
    printf("\n");
    return M;
}

void freeMatrice(int** matrice,int lign)
{
    for(int i = 0; i < lign; i++)
        free(*(matrice+i));
    free(matrice);
}

void afficherMatrice(int** matrice,int lign, int col)
{
    for(int i = 0; i < lign; i++)
    {
        printf("{ ");
        for(int j = 0; j < col; j++)
        {
            printf(" %d ",*(*(matrice+i)+j));
        }
        printf(" }\n");
    }
    printf("\n");

}

int** MatriceUnit(int n)
{
    int** Ide;
    Ide = (int**)malloc(n* sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        *(Ide+i) = (int*)malloc(n*sizeof(int));
        for(int j = 0; j < n; j++)
        {
            if (i == j)
                *(*(Ide+i)+i) = 1;
            else
                *(*(Ide+i)+j) = 0;
        }
    }
    return Ide;
}

int** Transpo(int** matrice, int lign, int col)
{
    int** tmatrice;
    tmatrice = (int**)malloc(col*sizeof(int*));
    for(int i = 0; i < col; i++)
    {
        *(tmatrice+i) = (int*)malloc(lign * sizeof(int));
        for(int j = 0; j < lign; j++)
        {
            *(*(tmatrice+i)+j) = *(*(matrice+j)+i);
        }
    }
    return tmatrice;
}

int** AddMat(int** A, int** B, int lign, int col)
{
    int **C;
    C = (int**)malloc(lign * sizeof(int*));
    {
        for(int i = 0; i < lign; i++)
        {
            *(C+i)=(int*)malloc(col*sizeof(int));
            for(int j = 0; j < col; j++)
            {
                *(*(C+i)+j) = *(*(A+i)+j) + *(*(B+i)+j);
            }
        }
    return C;
    }
}


int** MultMat(int**A, int**B, int lignA, int colA, int lignB, int colB)
{
    if (lignA == colB)
    {
        int s;
        int** res;
        res = (int**)malloc(lignA * sizeof(int*));
        for(int i = 0; i < lignA; i++)
        {
            *(res+i)=(int*)malloc(colB * sizeof(int));
            for(int j = 0; j < colB; j++)
            {
                s = 0;
                for(int k = 0; k < colA; k++)
                {
                    s = s + ((*(*(A+i)+k)) * (*(*(B+k)+j)));
                }
                *(*(res+i)+j) = s;
            }
        }
        return res;
    }
    return 0;
}


void main()
{
    int lign;
    int col;
    int** tab;
    int** tab2;
    int** Id;
    int** Ttab;
    int** C;
    int** M;
    printf("entrer le nombre de lignes :");
    scanf("%d", &lign);
    printf("entrer le nombre de colonnes :");
    scanf("%d", &col);
    tab = Creation(lign, col);
    MatriceLigne(lign,col,tab);
    tab2 = Creation(lign, col);
    printf("matrice tab = \n");
    afficherMatrice(tab, lign, col);
    printf("matrice tab2 = \n");
    afficherMatrice(tab2, lign, col);
    Id = MatriceUnit(lign);
    afficherMatrice(Id, lign, lign);
    Ttab = Transpo(tab, lign, col);
    afficherMatrice(Ttab, col, lign);
    C = AddMat(tab, tab2, lign, col);
    afficherMatrice(C, lign, col);
    M = MultMat(tab, tab2, lign, col, col, lign);
    printf("matrice M = \n");
    afficherMatrice(M, lign, col);
    freeMatrice(M, lign);
    freeMatrice(C, lign);
    freeMatrice(Ttab, lign);
    freeMatrice(tab2, lign);
    freeMatrice(tab, lign);
}
