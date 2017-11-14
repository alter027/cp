#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int arr[205],vis[205];
int n,m,count,total,pick;
vector<vector<int> > E;
int max(int a,int b){
	return a>b ? a : b;
}
int min(int a,int b){
	return a<b ? a : b;
}
int dfs(int k){
	int i,tmp;
	if(vis[k]!=0)
		return 0;
	vis[k]=1;
	for(i=0;i<E[k].size();i++){
			arr[E[k][i]]=pick;
		dfs(E[k][i]);
	}
	return 0;
}
int main(void){
	int a,b,d,i,j;
	scanf("%d%d",&n,&m);
	E.clear();
	E.resize(n*2+5,vector<int>());
	for(i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&d);
		if(d==1){
			E[b].push_back(a);
			E[a].push_back(b);
			E[a+n].push_back(b+n);
			E[b+n].push_back(a+n);
		}
		else{
			E[b].push_back(a+n);
			E[a].push_back(b+n);
			E[b+n].push_back(a);
			E[a+n].push_back(b);
		}
	}
	int c[205],flag=0,ans=0,spec=0;
	for(i=1;i<=n*2;i++)
		arr[i]=0,vis[i]=0;
	for(i=1;i<=n;i++){
		if(vis[i]==0&&vis[i+n]==0){//here form the backpack
			pick++;
			count=0;total=0;
			arr[i]=pick;
			flag=dfs(i);
//			printf("i=%d,ans=%d,count=%d,total=%d\n",i,ans,count,total);
		}
	}
//	for(i=1;i<=n*2;i++)
//		printf("%d ",arr[i]);
//	printf("\n");
//	for(i=0;i<spec;i++)
//		printf("%d ",c[i]);
//	printf("\n");
	for(i=1;i<=n;i++){
		if(arr[i])
			ans++;
		if(arr[i]==arr[i+n]){
			flag=-1;
			break;
		}
	}
	if(flag==0){
		printf("%d\n",ans);
		for(i=1;i<=n;i++)
			if(arr[i])
				printf("%d ",i);
		printf("\n");
	}
	else
		printf("Impossible\n");
	return 0;
}
