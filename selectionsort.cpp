#include<bits/stdc++.h>
using namespace std;

/*
 *
 *   har position par jao or udhar se lekr end tak ka minimum element
 *   dhundo or us particular position par place krdo
 *
 *   BEST CASE : O(N^2)
 *
 *   WORST CASE : O(N^2)
 *
 * */

int main() {

    vector<int> arr = {4 , 5 , 2 , 3 ,4 , 1 ,2 , 6};
    int n = arr.size();
    for (int i = 0 ; i < n-1 ; i++){
        int minimum_element_index = i;
        for (int j = i ; j < n ; j++){
            if (arr[minimum_element_index] > arr[j]){
                minimum_element_index = j;
            }
        }
        swap(arr[i] , arr[minimum_element_index]);
    }

    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}



