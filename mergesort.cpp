#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr , int start , int mid , int end){
    int i = start , j = mid+1;
    vector<int> temp;
    while (i <= mid and j <= end){
        if (arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }
        else
            temp.push_back(arr[j++]);
    }
     
    while (i <= mid){
       temp.push_back(arr[i++]);
    }
  
    while (j <= end){
      temp.push_back(arr[j++]);
    }
  
    for (int k = 0 ; k < temp.size() ; k++){
        arr[start+k] = temp[k];
    }
}

void merge_sort(vector<int>&arr , int s , int e){

    if (s >= e) return;

    int mid = (s+e)/2;

    merge_sort(arr , s , mid);
    merge_sort(arr , mid+1 , e);
    merge(arr , s , mid ,  e);
}



int main(){
    vector<int> arr = {2 , 3 , 5 , 4  , 1 , 7};
    merge_sort(arr , 0 , arr.size() - 1);
    for (int i = 0 ; i< arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*
 *  best time = nlogn
 *
 *  worst time = nlogn
 *
 *  average time = nlogn
 * */
