#include <iostream>
using namespace std;

int binarySearch(int array[], int key, int low, int high){
    while(low<=high){
    int mid = (low + high)/2;

    if(key == array[mid]){
        return mid;
    }else if(key > array[mid]){
        low = mid+1;
    }else{
        high = mid-1;
    }
    }
    return -1;
}

int main(){
    int array[] = {1,2,3,4,5,6,7};
    int arrsize = sizeof(array)/sizeof(array[0]);
    cout<<binarySearch(array, 6, 0, arrsize-1)<<endl;
}                           