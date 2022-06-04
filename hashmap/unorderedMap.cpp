#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    unordered_map <string,int> m;
    m["gfg"] = 20;
    m["ide"] = 30;
    // if key is not present it will insert that key 
    // otherwise it will update the value at that key
    m.insert({"courses",15});

    // output can be in any order
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    // find function
    auto it = m.find("ide");
    if(it!=m.end()){
        cout << "Found :" << it->second << endl;
    }
    else{
        cout << "Not found " << endl;
    }

    // iterate the map
    cout << "printing the map " << endl;
    for(auto it = m.begin();it!=m.end();it++){
        cout << it->first << " " << it->second << endl;
    }

    // count function
    if(m.count("gfg")>0){
        cout << "Found \n";
    }
    else{
        cout << "Not found \n";
    }

    // size and erase function is same as the unordered_set
    cout << m.size() << endl;
    m.erase("ide");
    m.erase(m.begin(),m.end());
    cout << m.size() << endl;
    return 0;
}