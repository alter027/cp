#include<bits/stdc++.h>
using namespace std;
int vis[20005][2];
int arr[6000][3],ans[6000];
int n,m;
int anc(int i){
	if(vis[i][0]>0){
		return vis[i][0]=anc(vis[i][0]);
	}
	return i;
 }
void solve(void){
	int a,b;
	int i,j;
	for(i=m-1;i>=0;i--){
		if(arr[i][0]==0){
			if(vis[arr[i][1]][0]==0)
				continue;
			vis[arr[i][1]][1]--;
			if(vis[arr[i][1]][1]==0)
				vis[arr[i][1]][0]=-1-vis[arr[i][1]][0];
		}
		else{
			if(anc(arr[i][1])==anc(arr[i][2]))
				ans[i]=1;
			else
				ans[i]=0;
		}
	}
 }
void input(void){
	int i;
	char str[5];
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&vis[i][0]);
		vis[i][1]=0;
	}
	for(i=0;i<m;i++){
		scanf("%s",str);
		if(str[0]=='C'){
			arr[i][0]=0;
			scanf("%d",&arr[i][1]);
			if(vis[arr[i][1]][0]==0)
				continue;
			if(vis[arr[i][1]][1]==0)
				vis[arr[i][1]][0]=-1-vis[arr[i][1]][0];
			vis[arr[i][1]][1]++;
		}
		else{
			arr[i][0]=1;
			scanf("%d%d",&arr[i][1],&arr[i][2]);
		}
	}
 }
int main(void){
	int i,j,T;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		printf("Case #%d:\n",i);
		input();
		solve();
		for(j=0;j<m;j++){
			if(arr[j][0]==0)
				continue;
			if(ans[j]==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
 }