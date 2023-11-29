#include<stdio.h>
#include<stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *s){
    printf("Enter the dimensions of matrix:");
    scanf("%d %d",&s->m,&s->n);
    printf("Enter number of non-zero elements:");
    scanf("%d",&s->num);
    s->e=(struct Element*)malloc(s->num*sizeof(struct Element));
    printf("Enter the elements:");
    for(int i  = 0;i<s->num;i++){
        scanf("%d %d %d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}

void Display(struct Sparse s){
    int k = 0;
    for(int i = 0;i<s.m;i++){
        for(int j = 0;j<s.n;j++){
            if(i==s.e[k].i&&j==s.e[k].j){
                printf("%d ",s.e[k++].x);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct Sparse* add(struct Sparse *s1,struct Sparse *s2){
    struct Sparse *add;
    add=(struct Sparse*)malloc(sizeof(struct Sparse));
    add->m=s1->m;
    add->n=s1->n;
    add->e=(struct Element*)malloc((s1->num+s2->num)*sizeof(struct Element));
    if(s1->m!=s2->m||s1->n!=s2->n){
        return NULL;
    }
    int i=0,j=0,k=0;
    while(i<s1->num&&j<s2->num){
        if(s1->e[i].i<s2->e[j].i){
            add->e[k++]=s1->e[i++];
        }else if(s1->e[i].i>s2->e[j].i){
            add->e[k++]=s2->e[j++];
        }else{
            if(s1->e[i].j<s2->e[j].j){
                add->e[k++]=s1->e[i++];
            }else if(s1->e[i].j>s2->e[j].j){
                add->e[k++]=s2->e[j++];
            }else{
                add->e[k]=s1->e[i];
                add->e[k++].x=s1->e[i++].x+s2->e[j++].x;
            }
        }
        
    }
    for(;i<s1->num;i++)add->e[k++]=s1->e[i++];
    for(;j<s2->num;j++)add->e[k++]=s2->e[j++];
    add->num=k;
    return add;
}

int main(){
    struct Sparse s1,s2,*sum;
    create(&s1);
    create(&s2);
    Display(s1);
    Display(s2);
    sum = add(&s1,&s2);
    Display(*sum);
    return 0;
}