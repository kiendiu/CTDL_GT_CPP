#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
bool nguyento(int n) {
    if (n <= 1)
        return false;
    for(int i=2; i<=n; i++){
        int d= 0;
        for(int j=2; j<i; j++){
            if(i%j == 0){
                d++;
            }
        }
        if(d == 0){
            return true;
        }
    }
    return true;
}
int main(){
    int n;
    cout << "Nhap vao so nguyen n: ";
    cin >> n;
    stack<int> st;
    for(int i=2;i<=n;i++){
        while (n%i == 0 && nguyento(i) ) {
            st.push(i);
            n /= i;
        }
    }
    int x = st.size();
    int i = 1;
    while(!st.empty()){
        if(i<x){
            cout<<st.top()<<"*";
            i++;
        }else cout<<st.top()<<" ";
        st.pop();
    }
    system("pause");
    return 0; 
}