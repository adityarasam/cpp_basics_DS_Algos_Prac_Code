
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

void swap(int *x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n){
    bool  swapped;

    for(int i=0;i<n-1;i++){
        swapped =false;
        for(int j=0;j<n-1-i;j++){
           if(arr[j]>arr[j+1]){
               swap(&arr[j],&arr[j+1]);
               swapped = true;
           }
        }

        if (!swapped){
            break;
            cout<<"bubblebreak";
        }
    }
}

void selectionSort(int arr[], int n){


    int min_indx;

    for(int i = 0; i<n-1;i++){
        min_indx = i;

        for(int j=i+1; j<n; j++){

            if(arr[j]<arr[min_indx]){
                min_indx = j;
            }

            
        }

        swap(&arr[min_indx],&arr[i]);

    }
}


void merge(int arr[], int l, int m,int r){
    int i,j;
    int index;

    int n_left = m-l+1;     //size of left
    int n_right = r-m;      //size of right

    int L[n_left], R[n_right];


    //fill arrays
    for(int i =0 ; i< n_left; i++){
        L[i] = arr[l+i];
    }

    for(int j =0 ; j< n_right; j++){
        R[j] = arr[1+m+j];
    }


    //initialize index
    index = l;
    i=0;
    j=0;
   
    while(i<n_left && j<n_right){
        if(L[i]<=R[j]){
            arr[index] = L[i];
            i++;
        }
        else{
            arr[index] = R[j];
            j++;
        }
        index++;
    }

    while(i<n_left){
        arr[index] = L[i];
        i++;
        index++;
    }
    
    while(j<n_right){
        arr[index] = R[j];
        j++;
        index++;
    }

}

void merge_sort(int arr[],  int l, int r){
    if(l<r){
        int m = (l+r)/2;
        merge_sort(arr, l, m);
        merge_sort(arr,m+1,r);

        merge(arr, l, m , r);


    }

}

void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
int main(){

    int arr[] = {1,5,4,3,2};  
    int n = sizeof(arr)/sizeof(arr[0]);  

    //selectionSort(arr, n);
    //bubbleSort(arr,n);
    merge_sort(arr, 0, n-1);

    printArray(arr,n);


    return 0;
}