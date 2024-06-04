#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//timf kiem nhi phan
bool bs(int a[], int n, int x){
    int l = 0; int r = n - 1;
    while(l<=r){
        int m = (l+r)/2;
        if(a[m] == x){
            return true;
        }else if(a[m] < x){
            l = m+1;
        }else {
            r = m - 1;
        }
    }
    return false;
}//de quy
bool Binary_search(int a[], int l, int r, int x){
    if(l>r) return false;
    int m = (l+r)/2;
    if(a[m] == x){
        return true;
    }else if(a[m] < x){
        return Binary_search(a, m+1, r, x);
    }else {
        return Binary_search(a, l, m-1, x);
    }
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<bs(a, n, 3);
}
