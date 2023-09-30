#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
long long n, k, x, cnt;
map<int, int> task;
int main(){
	freopen("ddl.in", "r", stdin);
	freopen("ddl.out", "w", stdout);
//	freopen("ddl.err", "w", stderr);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>k;
		for(int l=0; l<k; l++){
			cin>>x;
			task[x] += 1;
//			cerr<<"第"<<x<<"天("<<task[x]<<")添加了一个任务"<<endl;
			if (task[x] >= 2){
				for(int j=x-1; j>=i; j--){
                    if(task[j] == 0){
                    	task[j] += 1;
                    	task[x] -= 1;
//                    	cerr<<"第"<<x<<"天("<<task[x]<<")的任务转移给了第"<<j<<"天("<<task[j]<<")"<<endl;
                    	if (task[x] < 2){
                    		break;
						}
					}
				}
//				cerr<<"转移结束，第"<<x<<"天剩余"<<task[x]<<"个任务"<<endl;
				if (task[x] >= 2){
					cnt += task[x] - 1;
//					cerr<<"第"<<x<<"天("<<task[x]<<")有"<<task[x]-1<<"个无法完成的任务，cnt: "<<cnt<<endl;
					task[x] = 1;
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
