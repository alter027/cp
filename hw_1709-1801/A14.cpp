#include<bits/stdc++.h>
using namespace std;
int n,vis[20005];
int anc(int i){
	if(vis[i]!=i){
		return anc(vis[i]);
	}
	return i;
 }
void solve(void){
	int a,b;
	char str[5];
	scanf("%s",str);
	if(str[0]=='C'){
		scanf("%d",&a);
		a--;
		vis[a]=a;
	}
	else{
		scanf("%d%d",&a,&b);
		a--;b--;
		if(anc(a)==anc(b))
			printf("YES\n");
		else
			printf("NO\n");
	}
 }
void input(void){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&vis[i]);
		vis[i]--;
		if(vis[i]==-1)
			vis[i]=i;
	}
 }
int main(void){
	int i,T,m;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		printf("Case #%d:\n",i);
		scanf("%d%d",&n,&m);
		input();
		while(m-->0)
			solve();
	}
	return 0;
 }
