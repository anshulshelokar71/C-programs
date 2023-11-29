#include <stdio.h>
#include<stdlib.h>

int main(){

    FILE *fp =NULL;
    char ch = 'a';
    char str[10];
    fp=fopen("matrix.txt","w");
    // fputc(ch,fp);
    printf("Enter string:");
    fgets(str,10,stdin);
    // fprintf(fp,"\n%s",str);
    fputs(str,fp);
    fclose(fp);

    return 0;
}