#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;

// Implementing chaining

struct MyHash{
    int BUCKET;
    list <int> *table;
    MyHash(int b){
        BUCKET = b;
        table = new list<int>[b];
    }
    void insert(int key){
        int i = key%BUCKET;
        table[i].push_back(key);
    }
    bool search(int key){
        int i = key%BUCKET;
        for(auto x:table[i]){
            if(x==key){
                return true;
            }
        }
        return false;
    }
    void remove(int key){
        int i = key%BUCKET;
        table[i].remove(key);
    }
};

int main(){
    map <int,int> m;
    int arr[] = {1,2,2,1,1,3};
    for(int i =0;i<6;i++){
        m[arr[i]]++;
    }
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}