#include<bits/stdc++.h>
using namespace std;

int find_me_pivot (vector<int> &ar , int low , int high)
{
    // consider last element to be the pivot and make all elements lesser than it to its left and greater element to its right
    int pivot = low-1;

    for (int i = low; i < high ; i++){
       if (ar[i] < ar[high]){
           swap(ar[++pivot] , ar[i]);
       }
    }

    swap(ar[++pivot] , ar[high]);
    return pivot;
}

void quick_sort(vector<int>&ar , int low , int high){

    if (low < high){
        int pivot = find_me_pivot(ar , low , high);
        quick_sort(ar , low , pivot-1);
        quick_sort(ar , pivot+1 , high);
    }
}

int main(){
    vector<int> ar = {2 , 3 , 6, 8, 2 , 7 ,8};
    quick_sort(ar , 0 , ar.size()-1);
    for (auto x : ar )
        cout << x << " ";
    cout << endl;
}

/*
 *    BEST - NLOGN
 *
 *    WORST - N^2
 *
 *    AVERAGE - NLOGN
 *
 * */
