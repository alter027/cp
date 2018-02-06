#include<bits/stdc++.h>
using namespace std;

long long ans;
int n,k;
long long func(int i){
	long long tmp=0;
	if(i==0)
		tmp+=1;
	if(i>0)
		tmp+=6;
	if(i>1)
		tmp+=6*(i-1);
	return tmp;
}
void solve(void){
	ans=0;
	int i,t=1;
	for(i=k;i>=0;i--){
		ans+=func(i)*(n-i+1);
	//	printf("func = %lld, ans = %d\n",func(i),ans);
	}
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		scanf("%d%d",&n,&k);
		solve();
		printf("Case #%d: %lld\n",Case++,ans);
	}
	return 0;
}