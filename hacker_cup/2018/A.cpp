#include<bits/stdc++.h>
using namespace std;

int ans;

void solve(){
	long long K,N,V;
	int i,j;
	string str[55];
	scanf("%lld%lld%lld",&N,&K,&V);
	for(i=0;i<N;i++)
		cin >> str[i];
	int tmp=(K*(V-1)%N),cnt=0;
	if(tmp+K>=N){
		for(i=0;i<(tmp+K)%N;i++,cnt++)
			cout << str[i] << ' ';
	}
	for(i=tmp;i<tmp+K&&i<N;i++,cnt++){
		cout << str[i];
		if(cnt==K-1)
			cout<<'\n';
		else
			cout<<' ';
	}
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		printf("Case #%d: ",Case++);
		solve();
	}
	return 0;
 }