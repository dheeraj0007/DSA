#include <bits/stdc++.h> 
using namespace std;

// Sort 0 1 2 in the array
void sort012(int *arr, int n)
{
   //   Write your code here
    map <int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    int k =0;
    for(auto i:m){
        for(int j=0;j<i.second;j++){
            arr[k] = i.first;
            k++;
        }
    }
}

void printArray(int *arr,int n){
    for(int i =0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,2,1,0,1,0};
    sort012(arr,7);
    printArray(arr,7);
    return 0;
}