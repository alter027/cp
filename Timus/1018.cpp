#include<bits/stdc++.h>
using namespace std;
#define NUM 105
struct node{
	int s,e,w,num;
 };
int n,q,vis[NUM]={0},toh[NUM]={0};
int dp[NUM][NUM];
vector<node> E[NUM];
node leaf[NUM][2];
void init(void){
	int i,j,u,v,w;
	for(i=0;i<NUM;i++)
		for(j=0;j<NUM;j++)
			dp[i][j]=-1;
	node pic;
	scanf("%d%d",&n,&q);
	for(i=0;i<n-1;i++){
		scanf("%d%d%d",&u,&v,&w);
		pic.s=u;pic.e=v;pic.w=w;
		E[u].push_back(pic);
		pic.s=v;pic.e=u;
		E[v].push_back(pic);
	}
 }
int count_num(int k){
	if(vis[k]!=0)
		return 0;
	vis[k]=1;
	int i,j,ans=0;
	for(i=0,j=0;i<E[k].size();i++){
		E[k][i].num=count_num(E[k][i].e);
		if(E[k][i].num!=0)
			leaf[k][j++]=E[k][i];
		ans+=E[k][i].num;
	}
	toh[k]=j;
	return ans+1;
 }
int solve(int k,int m){
	if(dp[k][m]!=-1)
		return dp[k][m];
	if(m==1)
		return 0;
	m--;
	int i,j,tmp=0,cnt;
	if(toh[k]==2){
		for(i=leaf[k][0].num,j=m-i;j<=leaf[k][1].num;i--,j++){
			cnt=0;
			if(i<0||j<0)
				continue;
			if(i>0)
				cnt+=solve(leaf[k][0].e,i)+leaf[k][0].w;
			if(j>0)
				cnt+=solve(leaf[k][1].e,j)+leaf[k][1].w;
			tmp=max(tmp,cnt);
		}
	}
	else if(toh[k]==1){
		tmp=solve(leaf[k][0].e,m)+leaf[k][0].w;
	}
	return dp[k][m+1]=tmp;
 }
int main(void){
	int i,j;
	init();
	count_num(1);
	printf("%d\n",solve(1,q+1));
	return 0;
}