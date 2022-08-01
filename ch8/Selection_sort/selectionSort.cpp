#include<iostream>

#define N 8
using namespace std;

void selectionSort(int list[N]){
    int min,temp;
    for (int i = 0; i < N - 1; i++)
    {
        min = i;//事先假定最小值为第i个元素
        //从第i+1个元素开始遍历，寻找真正的最小值
        for (int j = i + 1; j < N; j++)
        {
            if(list[j] < list[min]){
                min = j;
            }
        }
        //如果最小值位置不在i，交换最小值和i元素的位置
        if(min != i){
            temp = list[min];
            list[min] = list[i];
            list[i] = temp;
        }
        
    }
    
}

int main(){
    int list[N] = {14, 33, 27, 10, 35, 19, 42, 44};
    selectionSort(list);
    for(int i = 0;i < N;i++){
        cout << list[i] << " ";
    }
    cout << endl;
    return 0;
}