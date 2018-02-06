#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
long long ans;
long long V[505],C[505];
int c,v,l;
void init(void){
	scanf("%d%d%d",&c,&v,&l);
 }
void solve(void){
	int i;
	C[0]=0;V[0]=v;
	for(i=1;i<l;i++){
		C[i]=V[i-1]*c;
		V[i]=(C[i-1]+V[i-1])*v;
		C[i]%=mod;V[i]%=mod;
	}
	ans=C[l-1]+V[l-1];
	ans%=mod;
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		init();
		solve();
		printf("Case #%d: %lld\n",Case++,ans);
	}
	return 0;
}