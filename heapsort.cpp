#include <bits/stdc++.h>

using namespace std;

/* left = 2*i
 * right = 2*i+1d
 * parent = (i/2)
 *
 * insert -> tc (log(n))
 *
 * deletion -> tc (log(n))
 *
 * heapify -> (n/2 +1 ----------> n) already heap hoti hi hai yaad rakhna (log(n))
 *
 * heap sort is nlog(n)
 * */

class heap {

public :
    int arr[100];
    int size = 0;

    void insert(int val) {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
               return;
            }
        }
    }

    void Delete(){
        if (size == 0) return;

        // put last element in first index
        swap(arr[1] , arr[size]);
        size--;

        // take root node to its correct position
        int index = 1;
        while (index < size){

            int left_index = 2*index;
            int right_index = 2*index+1;

            if (left_index < size and arr[index] < arr[left_index]){
                swap(arr[index] , arr[left_index]);
                index = left_index;
            }
            else if (right_index < size and arr[index] < arr[right_index]){
                swap(arr[index] , arr[right_index]);
                index = right_index;
            }
            else
                return;
        }
    }
    void print(){
        for (int i = 1 ; i <= size ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify (int arr[] , int n , int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if (left <= n and arr[largest] < arr[left]){
        largest = left;
    }
    if (right <= n and arr[largest] < arr[right]){
        largest = right;
    }

    if (largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr , n , largest);
    }
}

void heapsort(int arr[] ,int n){
    int size = n;

    while (size > 1){
        // step1
        swap(arr[size] , arr[1]);
        size--;
        // step 2
        heapify(arr , size , 1);
    }
}



int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(52);
    h.insert(60);
    h.print();
    h.Delete();
    h.print();
    int arr[6] = {-1 , 54 , 52 , 55 , 52 , 50};
    int n = 5;
    for (int i = n/2 ; i > 0 ; i--){
        heapify(arr , n , i);
    }
    for (int i = 1 ; i <= n ; i++)
        cout << arr[i] << " ";
    cout << endl;
    heapsort(arr , n);
    for (int i = 1 ; i <= n ; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
