/*
    LÝ THUYẾT
#include<stack>
stack< kie_du_lieu > ten;
push: đẩy phần tử vào ngăn xếp 
pop: lấy phần tử ra khỏi ngăn xếp
top: lấy ra phần tử đỉnh ngăn xếp
size: số lượng phần tử
empty: kiểm tra rỗng 
LIFO: last in first out

*/
#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;
void solve(){
    string s; cin>>s;
    stack<char> t;
    for(char x : s){
        if(x == '('){
            t.push(x);
        }else {
            if(t.empty()){
                cout<<"invalid"<<endl;
            }
            else t.pop();
        }
    }
    if(t.empty()){
        cout<<"valid"<<endl;
    }else cout<<"invalid"<<endl;
}
int main(){
    /* số nhị phân 
    int n;
    cin>>n;
    stack<int> st;
    while(n != 0){
        st.push(n%2);
        n /=2;
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }cout<<endl;
    */
    /*  đảo ngược xâu dùng stack thay vector
    string s;
    cin.ignore();
    getline(cin, s);
    stringstream ss(s);
    string token;
    stack<string> t;
    while(ss >> token){
        t.push(token);
    }
    while(!t.empty()){
        cout<<t.top()<<" ";
        t.pop();
    }
    */
   /*
    kiểm tra dâu ngoặc
    int t;
    cin>>t;
    while(t--){
        solve();
    }
   */
  /*
    int n; cin>>n;
    int a[n];
    for(int &x : a){
        cin>>x;
    }
    // for(int i=0; i<n; i++){
    //     int res = -1;
    //     for(int j=i+1; j<n; j++){
    //         if(a[j] > a[i]){
    //             res = a[j];
    //             break;
    //         }
    //     }cout<<res<<" ";
    // } cách 1
    int b[n];
    stack<int> t;
    for(int i=0; i<n; i++){
        if(t.empty()){
            t.push(i);
        }
        else{
            while(!t.empty() && a[t.top()] < a[i]){
                b[t.top()] = a[i];
                t.pop();
            }
            t.push(i);
        }
    }
    while(!t.empty()){
        b[t.top()] = -1;
        t.pop();
    }
    for(int x : b){
        cout<<x<<" ";
    }
    */
    int n; cin>>n;
    int a[n];
    for(int &x:a){
        cin>>x;
    }
    stack<int> st;
    int res = INT_MIN;
    int i=0;
    while(i < n){
        if(st.empty() || a[i] > a[st.top()]){
            st.push(i);
            i++;
        }else{
            int idx = st.top();
            st.pop();
            if(st.empty()){
                res = max(res, i*a[idx]);
            }else{
                res = max(res, a[idx]*(i-st.top()-1));
            }
        }
    }
    while(!st.empty()){
        int idx = st.top();
        st.pop();
        if(st.empty()){
            res = max(res, i*a[idx]);
        }else{
            res = max(res, a[idx]*(i-st.top()-1));
        }   
    }
    cout<<res<<endl;
    return 0;
}