#include <iostream>
#include <map>
using namespace std;

// this code is to find the frequency of each element in the array

void frequency(int arr[],int n){
    map <int,int> m;
    for(int i =0;i<n;i++){
        m[arr[i]]++;
    }
    map <int,int> :: iterator it = m.begin();
    while(it!=m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
}

int main(){
    int arr[] = {10,12,10,15,10,20,12,12};
    frequency(arr,8);
    return 0;
}