#include <iostream>
#include <set>
using namespace std;

bool duplicateNumber(int array[], int size){
    set<int> a;
    int i = 0;
    for(int i = 0; i<=size ;i++){
        if(a.count(array[i])){
            return true;
        }else{
            a.insert(array[i]);
        }
        return false;
     
    }
}

int mian(){
    int array[] = {1,3,5,5,8,10,0};
    int size_array = sizeof(array)/sizeof(array[0]);
    cout<<duplicateNumber(array, size_array)<<endl;
}