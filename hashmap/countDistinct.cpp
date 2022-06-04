#include <iostream>
#include <unordered_set>
using namespace std;


// This code is to find the count of distinct elements in an array

int countDistinct(int arr[],int n){
    unordered_set <int> s;
    for(int i =0;i<n;i++){
        s.insert(arr[i]);
    }
    return s.size();
}

//  this method is improved 
//  we directly add the array elements as the set

int countDistinct2(int arr[],int n){
    unordered_set <int> s(arr,arr+n);
    return s.size();
}

int main(){ 
    int arr[] = {10,20,10,20,30};
    cout << countDistinct2(arr,5);
    return 0;
}