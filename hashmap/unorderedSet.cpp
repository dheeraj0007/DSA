#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set <int> s;
    s.insert(10);    
    s.insert(20);    
    s.insert(30);    
    s.insert(40);
    for(int x:s){
        cout << x << endl;
    }   

    // output can be in any order
    //  it is the permutation of (10,20,30,40)

    cout << "Printing the set using iterator " <<endl;
    for(auto it = s.begin();it!=s.end();it++){
        cout << (*it) << endl;
    } 
    cout << "The size of the set is " << s.size() << endl;

    // this will clear the set 
    // s.clear();
    // cout << "The size of the set is " << s.size() << endl;

    // Find function on set
    // if element is not found in the set then it returns s.end()
    if(s.find(30)!=s.end()){
        cout << "The element is found . " << *(s.find(30)) << endl;
    }
    else{
        cout << "The element is not found ." << endl;
    }

    // count function - > can be used as a substitute for the find function
    // count returns either 1 or 0
    if(s.count(30)){
        cout << "Element is found " << s.count(30) << endl;
    }
    else{
        cout << "Not found " << endl;
    }

    // erase function -> to remove an item or a range of items

    s.erase(30);
    cout << "The size of the set is " << s.size() << endl;

    // it can also be used to remove a set of elements
    s.erase(s.begin(),s.end()); // end is not included
    //  end points to the element beyond the last element
    cout << s.size() << " is the size after erasing" << endl;
    return 0;
}