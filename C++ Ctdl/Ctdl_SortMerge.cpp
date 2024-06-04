#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i=0, j=0;
    while(i<x.size() && j<y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i]; ++l; ++i;
        }else{
            a[l] = y[j]; ++l; ++j;
        }
    }
    while( i< x.size()){
        a[l] = x[i]; ++l; ++i;
    }
    while(j < y.size()){
        a[l] = y[j]; ++l; ++j;
    }
}
void mergeSort(int a[], int l, int r){
    if(l >= r){
        return;
    }
    int m = (l+r)/2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}
//đếm số cặp nghịch thể trong mảng tăng dần a[i] > a[j] và i < j;
int mergeNghichThe(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);
    int i=0, j=0;
    int cnt = 0;
    while(i<x.size() && j<y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i]; ++l; ++i;
        }else{
            cnt += x.size() - i;
            a[l] = y[j]; ++l; ++j;
        }
    }
    while( i< x.size()){
        a[l] = x[i]; ++l; ++i;
    }
    while(j < y.size()){
        a[l] = y[j]; ++l; ++j;
    }
    return cnt;
}
int mergeSortghichthe(int a[], int l, int r){
    int dem = 0;
    if(l < r){
        int m = (l+r)/2;
        dem+=mergeSortghichthe(a, l, m);
        dem+=mergeSortghichthe(a, m+1, r);
        dem+=mergeNghichThe(a, l, m, r);
    }
    return dem;
}
int main(){
    // int n = 100;
    // int a[100];
    // srand(time(NULL));
    // for(int i=0; i<n; i++){
    //     a[i] = rand() % 1000;
    // }
    // mergeSort(a, 0, n - 1);
    // for(int x : a){
    //     cout<<x<<" ";
    // }
    int a[6] = {8, 7, 1, 9, 2, 3};
    cout<<mergeSortghichthe(a, 0, 5)<<endl;
    return 0;
}