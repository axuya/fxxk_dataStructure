#include<iostream>

using namespace std;

int partition(int * arr,int p,int q){
    int temp = 0;

    int low = p;
    int high = q - 1;

    int pivot = arr[q];

    while (true)
    {
        while (arr[low] < pivot)
        {
            low++;
        }
        while (high > 0 && arr[high] > pivot)
        {
            high--;
        }
        if(low >= high){
            break;
        }
        else{
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
    temp = arr[low];
    arr[low] = pivot;
    arr[q] = temp;

    return low;
}

void quick_sort(int * arr,int p,int q){
    if(q - p <= 0) return;
    else{
        int par = partition(arr,p,q);
        quick_sort(arr,p,par - 1);
        quick_sort(arr,par + 1,q);
    }
}

int main(){
    int i = 0;
    int arr[10] = {35,33,42,10,14,19,27,44,26,31};
    quick_sort(arr,0,9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}