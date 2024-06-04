#include<iostream>
using namespace std;
int i, j;
//selection sort = lay phan tu co gia tri nho nhat dat vao
//vi tri dau tien cua day
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[min_idx] > arr[j]) min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}
//insertion sort = tim vi tri thich hop chen a[i] vao day dc sap truoc do 
//tim i: day cac phan tu lon hon a[i] ra vi tri sau
void insertionSort(int arr[], int n){
    for( i=1; i<=n; i++){
        int key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}
//sap xep noi bot bubble sort
//doi cho 2 ptu lien ke chua sap xep
//giam so buoc lap 
void bubbleSort(int arr[], int n){
    for(i=0; i<n; i++){
        bool check = false;
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                check = true;
                swap(arr[j], arr[j+1]);
            }
        }
        if(!check) break;
    }
}
//sap xep nhanh quick sort
//devide and conquer ( chia de tri)
//chia day la cac ptu lon hon key va nho hon key
//counting sort
int cnt[1000000];

int main(){
    int a[1000];
    int n;
    cin>>n;
    int m = INT_MIN;
    for(int i=0; i<n; i++){
        cin>>a[i];
        cnt[a[i]]++;
        m = max(m, a[i]);
    }
    for(int i=0; i<=m; i++){
        if(cnt[i] != 0 ){
            for(int j=0; j<cnt[i]; j++){
                cout<<i<<" ";
            }
        }
    }
    return 0;
}