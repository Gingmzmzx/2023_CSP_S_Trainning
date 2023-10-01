#include <bits/stdc++.h>
using namespace std;
stack<int> sta;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    
    sta.push(1);
    while(true){
        sta.push(sta.top() + 1);
        cout<<sta.top()<<endl;
    }

    return 0;
}