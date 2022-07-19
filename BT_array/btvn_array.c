#include <stdio.h>

void enterArray(int arr[], int n)
{
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

void display(int arr[], int n)
{
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    } 
    printf("\n");
}

void upSort(int arr[], int n)
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void downSort(int arr[], int n)
{
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] < arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int maxOfArray(int arr[], int n)
{
    int max;
    for (int i=0; i<n; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int minOfArray(int arr[], int n)
{
    int min;
    for (int i=0; i<n; i++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}


int main()
{
    int n;
    printf("Nhap so phan tu mang: ");
    scanf("%d", &n);

    int a[n];
    printf("Nhap phan tu mang: ");
    enterArray(a, n);

    printf("sx tang dan: ");
    upSort(a, n);
    display(a, n);

    printf("sx giam dan: ");
    downSort(a, n);
    display(a, n);

    printf("Max: %d\n", maxOfArray(a, n));
    printf("Min: %d\n", minOfArray(a, n));

    return 0;
}