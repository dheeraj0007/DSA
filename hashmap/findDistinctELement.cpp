#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int distinct(vector<vector<int>> M, int N){
    unordered_map <int,int> m;
    for(int i = 0;i<M[0].size();i++){
        m[M[0][i]]++;
    }
    for(int i =1;i<N;i++){
        for(int j =0;j<N;j++){
            if(m.find(M[i][j])!=m.end()){
                m[M[i][j]]++;
            }
        }
    }
    int count = 0;
    for(auto i:m){
        if(i.second>=4){
            count++;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> M = {{2,1,4,3},{1,2,3,2},{3,6,2,3},{5,2,5,3}};
    cout << distinct(M,4);
    return 0;
}