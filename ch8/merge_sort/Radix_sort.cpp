#include<iostream>
using namespace std;

#define N 7
#define MAX 100 //限制各个元素各位数上的值不能超过100

//计数排序算法，place 表示以指定数位为准，对序列中的元素进行排序
void countingSort(int array[], int place) {
    int i, output[N];
    //初始化一个数组,继续各个元素的出现次数
    int count[MAX] = { 0 };
    //假设第一个元素指定数位上的值最大
    int max = (array[0] / place) % 10;
    //找到真正数位上值最大的元素
    for (i = 1; i < N; i++) {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }
    //统计各个元素出现的次数
    for (i = 0; i < N; i++)
        count[(array[i] / place) % 10]++;
    //累加 count 数组中的出现次数
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    //根据 count 数组中的信息，找到各个元素排序后所在位置，存储在 output 数组中
    for (i = N - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    //将 output 数组中的数据原封不动地拷贝到 array 数组中
    for (i = 0; i < N; i++)
        array[i] = output[i];
}

//找到整个序列中的最大值
int getMax(int array[]) {
    int i, max = array[0];
    for (i = 1; i < N; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

//基数排序算法
void radixSort(int array[]) {
    //找到序列中的最大值
    int place, max = getMax(array);
    //根据最大值具有的位数，从低位依次调用计数排序算法
    for (place = 1; max / place > 0; place *= 10)
        countingSort(array, place);
}

//输出 array 数组中的数据
void printArray(int array[]) {
    int i;
    for (i = 0; i < N; ++i) {
        cout << array[i] <<" ";
        //printf("%d ", array[i]);
    }
    cout << endl;
}

int main() {
    int array[N] = { 121, 432, 564, 23, 1, 45, 788 };
    radixSort(array);
    printArray(array);
}