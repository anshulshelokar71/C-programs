#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

void create(struct Poly *p)
{
    
    printf("Enter number of non zero terms:");
    scanf("%d", &p->n);
    p->t = (struct Term *)malloc(p->n * sizeof(struct Term));
    printf("Enter terms");
    for (int i = 0; i < p->n; i++)
    {
        scanf("%d %d", &p->t[i].coeff, &p->t[i].exp);
    }
}

void Display(struct Poly *p)
{
    for (int i = 0; i < p->n; i++)
    {
        if (i == 0)
        {
            printf("%dx^%d", p->t[i].coeff, p->t[i].exp);
        }
        else
        {
            (p->t[i].coeff >= 0) ? printf("+%dx^%d", p->t[i].coeff, p->t[i].exp) : printf("%dx^%d", p->t[i].coeff, p->t[i].exp);
        }
    }
    printf("\n");
}

int eval(struct Poly *p,int x){
    int sum = 0;
    for(int i = 0;i<p->n;i++){
        sum+=p->t[i].coeff*pow(x,p->t[i].exp);
    }
    return sum;
}

struct Poly* add(struct Poly p1,struct Poly p2){
    struct Poly *Sum;
    Sum = (struct Poly *)malloc(sizeof(struct Poly));
    Sum->t=(struct Term*)malloc((p1.n+p2.n)*sizeof(struct Term));
    int i,j,k;
    i=j=k=0;
    while(i<p1.n&&j<p2.n){
        if(p1.t[i].exp<p2.t[j].exp){
            Sum->t[k++]=p2.t[j++];
        }else if(p1.t[i].exp>p2.t[j].exp){
            Sum->t[k++]=p1.t[i++];
        }else{
            Sum->t[k]=p2.t[j];
            Sum->t[k++].coeff=p1.t[i++].coeff+p2.t[j++].coeff;
        }
    }
    for(;i<p1.n;i++)Sum->t[k++]=p1.t[i];
    for(;j<p2.n;j++)Sum->t[k++]=p2.t[j];
    Sum->n=k;
    return Sum;
}

int main()
{
    // struct Poly *p1;
    // p1=(struct Poly*)malloc(sizeof(struct Poly));
    struct Poly p1,p2,*addition;
    create(&p1);
    create(&p2);
    // printf("%d\n",eval(&p1,1));

    
    Display(&p1);
    Display(&p2);
    addition=add(p1,p2);
    Display(addition);
}