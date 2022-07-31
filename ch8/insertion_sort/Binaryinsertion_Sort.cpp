#include <iostream>
using namespace std;
 
const int maxSize = 20;
 
template <class T>
void BinInsertSort(T arr[], const int left, const int right) {
    int i, j, low, high, mid;
    T temp;
    
    for(i = left+1; i <= right; i++) {
        temp = arr[i]; // 暂存arr[i]
        low = left;
        high = i-1; // low、high作为折半查找的上、下界
        while(low <= high) { // 用折半查找的方法，查找arr[i]的插入位置
            mid = (low + high) / 2;
            if(temp < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } // while
        for(j = i-1; j >= low; j--)
            arr[j+1] = arr[j]; // 顺序后移
        arr[low] = temp; // 回填
    } // for
} // BinInsertSort
 
int main(int argc, const char * argv[]) {
    int i, n, arr[maxSize];
    
    cout << "请输入要排序的数的个数：";
    cin >> n;
    cout << "请输入要排序的数：";
    for(i = 0; i < n; i++)
        cin >> arr[i];
    cout << "排序前：" << endl;
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    BinInsertSort(arr, 0, n-1);
    cout << "排序后：" << endl;
    for(i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}