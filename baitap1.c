#include<stdio.h>

// bubble sort
void BubbleSort(int arr[], int n){
   for (int i = 0; i < n; i++){
        for (int j = n - 1; j > i; j--){
            if(arr[j] < arr[j - 1]){
                // hoan vi
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

//xuat
void printfArr(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void DemTanSuat(int arr[], int n){
    int index = 1;
    for (int i = 0; i < n; i++){
        if(arr[i] == arr[i+1]){
            index += 1;
        }
        else{
            printf("\n Phan tu %d xuat hien %d lan", arr[i], index);
        }
    }
}       

int main(int argc, char const *argv[])
{
    int array[] = {1,2,4,5,6,2,3,4,8,9,3,5,6};
    char string[] = {"mot hai ba mot bon nam mot hai hai ba"};
    int sizeArray = sizeof(array)/sizeof(int);
    BubbleSort(array, sizeArray);
    printfArr(array, sizeArray);
    DemTanSuat(array, sizeArray);
    return 0;
}
