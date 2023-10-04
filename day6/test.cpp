#include<bits/stdc++.h>
using namespace std;
int i, j, k, n, m, s, ans, f[10010], p1, p2, p3;
int find(int k){
    if(f[k]==k)return k;
    return f[k]=find(f[k]);
}
int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++) f[i]=i;
    for(i=1;i<=m;i++){
        cin>>p1>>p2>>p3;
        if(p1==1) f[find(p2)]=find(p3);
        else
            if(find(p2)==find(p3))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
    }
    return 0;
}