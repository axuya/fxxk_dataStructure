#include<iostream>
using namespace std;

void insertion_sort(int * arr,int size){
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void PrintArray(int * arr,int size){
    for(int i = 0;i < size;i++){
        std::cout<< arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int arr[6] = {5,3,1,2,6,4};
    std::cout<< "original: \n";
    PrintArray(arr,6);

    insertion_sort(arr,6);

    std::cout << "sorted: \n";
    PrintArray(arr,6);
    return 0;
}


