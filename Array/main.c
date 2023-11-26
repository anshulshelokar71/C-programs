#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int A[50];
    int size;
    int length;
};

// void init(struct Array *arr,int n)
// {
//     arr->A = (int*)malloc(n*sizeof(struct Array));
//     arr->size = n;
//     arr->length = 0;
//     return;
// }

void Display(struct Array arr)
{
    printf("Elements are\n[ ");
    for(int i = 0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
    printf("]");
    
}

void Append(struct Array *arr,int x)
{
   if(arr->length<arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr,int index,int x)
{
    if(index>=0 && index<=arr->length){
        for(int i = arr->length;i>index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr,int index)
{
    if(index>=0 &&index<arr->length){
        int x = arr->A[index];
        for(int i = index;i<=arr->length-2;i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int linearSearch(struct Array *arr,int val)
{
    for(int i = 0; i<arr->length; i++){
        if(arr->A[i]==val){
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinSearch(struct Array arr,int key)
{
    int l,mid,h;
    l = 0; h = arr.length-1;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid]){
            return mid;
        }else if(key<arr.A[mid]){
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return -1;
}

int RBinSearch(int arr[],int l,int h,int key)
{
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(key == arr[mid]){
            return mid;
        }else if(key<arr[mid]){
           return RBinSearch(arr,l,mid-1,key);
        }else{
            return RBinSearch(arr,mid+1,h,key);
        }
    }
    return -1;
}

int get(struct Array arr,int index)
{
    if(index>=0&&index<arr.length){
        return arr.A[index];
    }
    return -1;
}

void set(struct Array *arr,int index,int val)
{
    if(index>=0&&index<arr->length){
        arr->A[index] = val;
    }
}

int Sum(struct Array arr)
{
    int total = 0;
    for(int i = 0; i<arr.length;i++){
        total+=arr.A[i];
    }
    return total;
}

float Avg(struct Array arr)
{
   
    return (float)Sum(arr)/arr.length;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
    }
    return min;
}


void reverse(struct Array *arr)
{
    for(int i = 0; i<(arr->length)/2;i++){
        swap(&arr->A[i],&arr->A[arr->length-1-i]);
    }
}

int isSorted(struct Array arr)
{
    for(int i = 0; i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}


void SortedInsert(struct Array *arr,int x)
{
    if(arr->length==arr->size){
        return;
    }
    int i = arr->length-1;
    while(i>=0&&x<arr->A[i]){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

void signedArr(struct Array *arr)
{
    int j = 0;
    int i = arr->length-1;
    while(i>j){
        while(arr->A[i]>0){
            i--;
        }
        while (arr->A[j]<0)
        {
            j++;
        }
        swap(&arr->A[i],&arr->A[j]);
    }
}


struct Array* mergeSort(struct Array *arr1,struct Array *arr2)
{
    struct Array *arr;
    arr = (struct Array*)malloc(sizeof(struct Array));
    arr->size = arr1->size+arr2->size;
    arr->length = arr1->length+arr2->length;
    int i=0,j=0,k=0;
    while (i<arr1->length&&j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j]){
            arr->A[k++] = arr1->A[i++];
        }else{
            arr->A[k++] = arr2->A[j++];
        }
    }
    for(;i<arr1->length;i++){
        arr->A[k++] = arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr->A[k++] = arr2->A[j];
    }
    return arr;
    
}

struct Array* SortedUnion(struct Array* arr1,struct Array *arr2)
{
    struct Array *arr = (struct Array*)malloc(sizeof(struct Array));
    
    arr->size = arr1->size+arr2->size;
    int i,j,k,rep;
    i=j=k=rep=0;
    while(i<arr1->length&&j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr->A[k++] = arr1->A[i++];
        }else if(arr1->A[i]>arr2->A[j]){
            arr->A[k++] = arr2->A[j++];
        }else{
            arr->A[k++] = arr1->A[i++];
            j++;
            rep++;
        }
    }
    for(;i<arr1->length;i++){
        arr->A[k++] = arr1->A[i];
    }
    for(;j<arr2->length;j++){
        arr->A[k++] = arr2->A[j];
    }
    arr->length = (arr1->length+arr2->length)-rep;
    return arr;
}

struct Array* SortedIntersection(struct Array* arr1,struct Array *arr2)
{
    struct Array *arr = (struct Array*)malloc(sizeof(struct Array));
    
    arr->size = arr1->size+arr2->size;
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length&&j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }else if(arr1->A[i]>arr2->A[j]){
            j++;
        }else{
            arr->A[k++] = arr1->A[i++];
            j++;
        }
    }
    
    arr->length = k;
    return arr;
}

struct Array* SortedDifference(struct Array* arr1,struct Array *arr2)
{
    struct Array *arr = (struct Array*)malloc(sizeof(struct Array));
    
    arr->size = arr1->size+arr2->size;
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length&&j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr->A[k++] = arr1->A[i++];
        }else if(arr1->A[i]>arr2->A[j]){
            j++;
        }else{
            i++;
            j++;
        }
    }
     for(;i<arr1->length;i++){
        arr->A[k++] = arr1->A[i];
    }
    
    arr->length = k;
    return arr;
}



int main()
{
    struct Array arr1={{2,3,4,15,26},10,5};
    struct Array arr2={{2,5,7,11,15,16},10,6};
    struct Array *arr;
    arr = Difference(&arr2,&arr1);
    // arr = mergeSort(&arr1,&arr2);
    // struct Array arr,*Arr;
    // Arr = &arr;
    // init(Arr,10);
    // Append(Arr,-2);
    // Append(Arr,6);
    // Append(Arr,-10); 
    // Append(Arr,10);
    // SortedInsert(Arr,1);
    // signedArr(Arr);
    // reverse(Arr);
    // printf("%d\n",isSorted(arr));
    // int n,i;
    // printf("Enter size of an array");
    // scanf("%d", &arr.size);
    // arr.A = (int *)malloc(arr.size*sizeof(int));
    // arr.length = 0;
    
    // printf("Enter number of numbers");
    // scanf("%d",&n);
    // printf("Enter all elements\n");
    // for(i = 0;i<n;i++)
    //     scanf("%d",&arr.A[i]);
    // arr.length = n;
    // Append(&arr,10);
    // Insert(&arr,4,7);
    // printf("%d",Delete(&arr,4));
    // printf("%d\n",linearSearch(&arr,5));
    // printf("%d\n",RBinSearch(arr.A,0,arr.length-1,5));
    // printf("%d\n",BinSearch(arr,5));

    Display(*arr);
    return 0;
}