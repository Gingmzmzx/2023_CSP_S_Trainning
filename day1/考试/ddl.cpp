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
//			cerr<<"��"<<x<<"��("<<task[x]<<")�����һ������"<<endl;
			if (task[x] >= 2){
				for(int j=x-1; j>=i; j--){
                    if(task[j] == 0){
                    	task[j] += 1;
                    	task[x] -= 1;
//                    	cerr<<"��"<<x<<"��("<<task[x]<<")������ת�Ƹ��˵�"<<j<<"��("<<task[j]<<")"<<endl;
                    	if (task[x] < 2){
                    		break;
						}
					}
				}
//				cerr<<"ת�ƽ�������"<<x<<"��ʣ��"<<task[x]<<"������"<<endl;
				if (task[x] >= 2){
					cnt += task[x] - 1;
//					cerr<<"��"<<x<<"��("<<task[x]<<")��"<<task[x]-1<<"���޷���ɵ�����cnt: "<<cnt<<endl;
					task[x] = 1;
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
