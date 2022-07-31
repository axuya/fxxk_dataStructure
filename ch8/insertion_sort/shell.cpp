#include<iostream>
#include<vector>
using namespace std;

void shellSort(vector<int> vec){
    //shell_sort
    for(int gap = vec.size() / 2;gap > 0;gap /= 2){
        //insertion_sort
        for(int i = gap;i < vec.size();++i){
            int j = i;
            while(j-gap >= 0 && vec[j - gap] > vec[j]){
                vec[j - gap] = vec[j - gap] + vec[j];
                vec[j]       = vec[j - gap] - vec[j];
                vec[j - gap] = vec[j - gap] - vec[j];
                j = j - gap;
            }
        }
    }

    for(int i = 0; i < vec.size();++i){
        cout<<vec[i]<<endl;
    }
}

int main(){
    vector<int> vec = {8,9,1,7,2,3,5,4,6,0};
    shellSort(vec);
    return 0;
}

//vector用 clang++ -std=c++11 shell.cpp
