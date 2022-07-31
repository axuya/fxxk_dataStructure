#include<iostream>
using namespace std;

#define N 5

void Bubble_sort(int list[N]){
    int i,j;
    int temp = 0;
    for(int i = 0;i < N - 1; i++){//遍历了N-1次
        for (int j = 0; j < N - 1; j++)
        {
            if(list[j] > list[j + 1]){
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                //swap(list[j],list[j+1]);
            }
        }     
    }
}

int main(){
    int i = 0;
    int list[N] = {14,33,27,35,10};
    Bubble_sort(list);
    for (int i = 0; i < N; i++)
    {
        cout << list[i] << ' ';
    }
    cout << endl;
    return 0;
}