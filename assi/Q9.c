#include<stdio.h>
#include<string.h>
#include<math.h>


int copy(char *string2, char *string1){
    while(*string1 != '\0'){
        *string2 = *string1;
        string1++;
        string2++;
    }
    *string2 = '\0';
    return 0;
}

int lenstr(char* string){
    int lenstr = 0;
    while(*string != '\0'){
        lenstr++;
        string++;
    }
    printf("Length of string is %d\n", lenstr);
    return 0;
}

int concat(char *string1, char *string2){
    while(*string1 != '\0'){;
        string1++;
    }
    while(*string2 != '\0'){
        *string1 = *string2;
        string1++;
        string2++;
    }
    return 0;
}

int compare(char *string1, char *string2){
    int isSame = 0;
    while(*string1 != '\0' && *string2 != '\0'){
        if(*string1 == *string2)
            isSame = 1;
        else
            break;
        string1++;
        string2++;
    }
    if (isSame == 0)
        printf("Strings are not same\n");
    else 
        printf("Strings are same\n");
    return 0;
}

int substr(char *string){
    char substr[10];
    int dec = 25;
    printf("Enter string to be searched : ");
    scanf("%s", substr);
    while(*string != '\0'){
        for(int i = 0; substr[i] != '\0'; i++, string++){
            if(substr[i] != *string){
                dec = 0;
                break;
            }
            else
                dec = 1;
        }
        string++;
        if (dec == 1)
            break;
    }
    if (dec==1){
        printf("Present\n");
    }
    else
        printf("Not present\n");
    return 0;
}

int print(char* string1, char *string2){
    while(*string1 != '\0'){
        printf("%c", *string1);
        string1++;
    }
    printf("\n");
    while(*string2 != '\0'){
        printf("%c", *string2);
        string2++;
    }
    printf("\n");
}



int main(){
//---------------------------------------------------------Using Library Functions----------------------------------------------
	char str1[] = "Anshul ";
	char str2[] = "Shelokar";
	char str3[20];
	int length = strlen(str1);
	strcat(str1,str2);
	printf("Length is %d \n",length);
	printf("str1 is %s \n",str1);
	strcpy(str3,str1);
	printf("str3 is %s \n",str3);
	printf("Two strings isEqual: %d \n",strcmp(str1,str2));
	//strrev(str3);
	//printf("Reverse string is %s \n",str3);
 //---------------------------------------------------------Without Using Library Function------------------------------------------
 	int opt;
    	char string1[20],string2[20];

	    printf("Enter string 1 : ");
	    scanf("%s", string1);
	    printf("Enter string 2 : ");
	    scanf("%s", string2);
	    do{
		printf("1. copy string 1 to string 2\n");
		printf("2. Length of string 1\n");
		printf("3. Length of string 2\n");
		printf("4. Concatenate string 1 and 2\n");
		printf("5. Compare string 1 and string 2\n");
		printf("6. Search string in string 1\n");
		printf("7. Search string in string 2\n");
		printf("8. Print strings\n");
		printf("Any other option to exit\n");
		printf("Enter option : ");
		scanf("%d", &opt);

		switch(opt){
		    case 1: copy(string2, string1);
		            break;
		    case 2: lenstr(string1);
		            break;
		    case 3: lenstr(string2);
		            break;
		    case 4: concat(string1, string2);
		            break;
		    case 5: compare(string1, string2);
		            break;
		    case 6: substr(string1);
		            break;
		    case 7: substr(string2);
		            break;
		    case 8: print(string1, string2);
		            break;
		    default: opt = 0;
		}
		
    		}while(opt);

	return 0;
}

