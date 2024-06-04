#include<iostream>
#include<algorithm>
using namespace std;
//nếu mà node char mà lớn hơn 2 node con thì là max_heap
//nếu mà node char mà nhở hơn 2 node con thì là min_heap
void heapify(int a[], int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l<n && a[l] > a[largest]){
        largest = l;
    }
    if(r<n && a[r] > a[largest]){
        largest = r;
    }
    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a,n,largest);
    }
}
void heapsort(int a[], int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(a,n,i);
    }
    for(int i=n-1; i>=0; i--){
        swap(a[i], a[0]);
        heapify(a,i,0);
    }
}
int main(){
    int n; cin>>n;
    int a[100];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    heapsort(a,n);
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
}
