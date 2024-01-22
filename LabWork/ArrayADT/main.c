#include<stdlib.h>
#include<stdio.h>
typedef struct Array{
    int size;
    int length;
    int *A;
}arr;

void init(arr *a,int n){
    a->length=0;
    a->size=n;
    a->A=(int*)malloc(n*sizeof(int));
}

void append(arr *a, int n){
    if(a->length<a->size){
        a->A[a->length++]=n;
    }
}


void display(arr arr){
	for(int i = 0 ; i < arr.length ; i++){
		printf(" %d ", arr.A[i]);
	}
	printf(" \n ");
	return;
}

void insert_at_index(arr *arr, int index, int elem){
	if(index < arr->length || index >= 0){
		for(int i = (arr->length-1) ; i >= index ; i--){
			arr->A[i+1] = arr->A[i];
		}
		arr->A[index] = elem;
		arr->length++;
	}
	return;
}

void remove_at_index(arr *arr, int index){
	if(index < arr->length || index >= 0){
		for(int i = index ; i < (arr->length-1) ; i++){
			arr->A[i] = arr->A[i+1];
		}
		arr->length--;
	}
	return;
}

void max(arr arr){
	int max;
	max = arr.A[0];
	for(int i = 0 ; i < arr.length ; i++){
		if(arr.A[i] > max){
			max = arr.A[i];
		}
	}
	printf("\nMaximum is : %d ", max);
}

void min(arr arr){
	int min;
	min = arr.A[0];
	for(int i = 0 ; i<arr.length ; i++){
		if(arr.A[i] < min){
			min = arr.A[i];
		}
	}
	printf("\nMinimum is : %d \n", min);
}

void reverse(arr *arr){
	int end = arr->length - 1;
    	int start = 0;
    	int temp;

    	while(start < end) {
    	    temp = arr->A[start];
    	    arr->A[start] = arr->A[end];
    	    arr->A[end] = temp;
    	    start++;
    	    end--;
    	}
    	return;
}

arr merge(arr a, arr b){
	arr merged;
	init(&merged, a.length + b.length);
	
	for(int i = 0 ; i< a.length ; i++){
		append(&merged, a.A[i]);
	} 
	for(int i = 0 ; i<b.length ; i++){
		append(&merged, b.A[i]);
	}
	display(merged);
	return merged;
}

int main(){
	arr A, B;
	int choice,size,index,index2;
	do{
		printf("\nMenu:\n");
        	printf("1. Init\n2. Append\n3. Insert_at_index\n");
        	printf("4. Remove_at_index\n5. Display\n6. Min/Max\n");
        	printf("7. Reverse\n");
        	printf("8. merge\n");
        	printf("9. Exit\n");
        	printf("Enter your choice : ");
        	scanf("%d", &choice);
        	
        	switch(choice){
        		case 1: 
        			
        			printf("Enter the size :");
        			scanf("%d", &size);
        			init(&A, size);
        			break;
        		case 2:
        			append(&A, rand());
        			break;
        		case 3:
        			// int index;
        			printf("Enter the index : ");
        			scanf("%d", &index);
        			insert_at_index(&A, index, rand());
        			break;
        		case 4:
        			// int index2;
        			printf("Enter the index : ");
        			scanf("%d", &index2);
        			remove_at_index(&A, index2);
        			break;
        		case 5:
        			display(A);
        			break;
        		case 6: 
        			min(A);
        			max(A);
        			break;
        		case 7:
        			reverse(&A);
        			display(A);
        			break;
        		default: 
        			printf("Invalid choice !");
        			
        	}	
	}while(choice != 9);
	return 0;
}
