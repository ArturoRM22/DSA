#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        vector<long long int> res(high - low + 1);
        int i = low;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= high) {
            if (a[i] <= a[j]) {
                res[k] = a[i];
                i += 1;
            }
            else {
                res[k] = a[j];
                j += 1;
            }
            k += 1;
        }
        while (i <= mid) {
            res[k] = a[i];
            i += 1;
            k += 1;
        }
        while (j <= high) {
            res[k] = a[j];
            j += 1;
            k += 1;
        }
        for (int h = 0; h <= high - low; h++) {
            a[low + h] = res[h];
        }
    }
}  




int main(){
    vector<int> vector = {4,3,6,9};
    mergeSort(vector, 0, vector.size()-1);
}