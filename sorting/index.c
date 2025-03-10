#include <stdio.h>

void displayArr(int a[],int n){
  for(int i=0;i<n;i++){
    printf("%d\t",a[i]);
    }
}
void selectionSort(int a[], int n) {// i with j
    int i, j, temp,minIdx;
    for(i=0; i<n-1; i++) {
        minIdx=i;//index
        for(j=i+1; j<n; j++) {
            if(a[j] < a[minIdx]) {
                minIdx=j;
            }
        }
        if(minIdx!=i){
            temp=a[minIdx];// store small element
            a[minIdx]=a[i];// put large element in j index
            a[i]=temp;
        }
    }
}
//sort the greatest at last my comparing two consecutive element in each loop
void bubbleSort (int a[] ,int n){ // j with j
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){// minus i because after each iteration greater is sorted at last index
            if(a[j]>a[j+1]){
                temp= a[j+1];
                a[j+1]= a[j];
                a[j]=temp;
            }
        }
    }

}

int main (){
    int arr[]= {5,6,3,2,4,6,3,2,5,6,0};
    int size= sizeof arr/sizeof arr[0];
    printf("\nOrginal arr:\t");
    displayArr(arr,size);
    bubbleSort(arr,size);
    printf("\n Bubble sort:\t");
    displayArr(arr,size);
    printf("\nSelection sort:\t");
    selectionSort(arr,size);
    displayArr(arr,size);
    return 0;
}