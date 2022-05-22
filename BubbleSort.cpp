/*
 *    next element chota hai swap krdo
 *    bade ko bubble bna do
 *
 *    TC - WORST / AVERAGE O(N^2)
 *         BEST -> O(N)
 * */
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {10 , 9 , 11 , 6 , 15 , 2};
    int n = arr.size();

    // n = 6 we need 5 iterations to sort the given array in worst case //
    // it can be stopped if the inner loop is not performing any further change to the given array //
  
    for (int i = 0; i < n-1 ; i++){
        for (int j = 0 ; j < n - i - 1 ; j++){
            if (arr[j] > arr[j+1])
                swap(arr[j] , arr[j+1]);
        }
    }

    for (auto x : arr)
        cout << x << " ";
}
