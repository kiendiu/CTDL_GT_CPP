#include<iostream>
using namespace std;

/*
    -phân hoạch lomuto
       +nếu mà là dãy tăng dần thì sẽ phải swap rất nhiều
*/
int partition(int a[], int l, int r){
    int x = a[r];
    int i = l-1;
    for(int j = l; j<r; j++){
        if(a[j] <= x){
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[r]);
    return i;
}
int partitionHoare(int a[], int l, int r){
    int x = a[l];
    int i = l-1;
    int j = r+1;
    while(true){
        do{
            i++;
        }while(a[i]<x);
        do{
            j--;
        }while(a[j]>x);
        if(i<j){
            swap(a[i], a[j]);
        }else return j;
    }
}
void quickSort(int a[], int l, int r){
    if(l>=r) return;
    int p = partitionHoare(a, l, r);
    quickSort(a, l, p-1);
    quickSort(a, p+1, r);
}
int main(){
    int a[1000], n;
    cin>>n;
    // for(int i=0; i<n; i++){
    //     a[i] = rand()%1000;
    // }
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    quickSort(a, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
}