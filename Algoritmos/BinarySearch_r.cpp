#include <iostream>
using namespace std;

int binarySearch(int array[], int key, int low, int high){
    if(low<=high){
    int mid = (low + high)/2;
    if(key == array[mid]){
        return mid;
    }else if(key > array[mid]){
        low = mid+1;
        binarySearch(array, key, low, high);
    }else{
        high = mid-1;
        binarySearch(array, key, low, high);
    }
    }else{
    return -1;
    }
}

int main(){
    int array[] = {10,11,49,70,100,101,200};
    int arrsize = sizeof(array)/sizeof(array[0]);
    cout<<binarySearch(array, 200, 0, arrsize-1)<<endl;
}