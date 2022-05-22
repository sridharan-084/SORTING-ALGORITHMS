#include<bits/stdc++.h>
using namespace std;

/*
 *
 *    put every element step by step to its correct position starting from the first position
 *
 *    BEST CASE : O(N)
 *
 *    WORST CASE : O(N^2)
 *
 *    AVERAGE CASE : O(N^2)
 *
 *    INPLACE , STABLE
 * */

int main() {

    vector<int> arr = {2 , 3 , 5,7 , 10 , 6 , 11 , 3 ,  9};

    for (int i = 2 ; i < arr.size() ; i++){
        int j = i-1 , k = i;
        while (j > 0 and arr[j] > arr[k]){
            swap(arr[j] , arr[k]);
            k = j;
            j--;
        }
    }

    for (auto x : arr)
        cout << x << " ";
    return 0;
}



