#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int count;
int arr[1005],vis[1005];
int n,m,ans,top,low;
vector<vector<int> > E;
int dfs(int k,int step){
	int i,flag;
	if(k==top||step==0)
		return k;
	for(i=0;i<E[k].size();i++){
		flag=dfs(E[k][i],step--);
		if(flag!=top)
			return flag;
	}
	return top;
}
int dfs_lvup(int k){
	int i,flag;
	if(vis[k]!=0)
		return 0;
	count++;
	vis[k]=1;
	for(i=0;i<E[k].size();i++){
		dfs_lvup
		(E[k][i]);
	}
	return 0;
}
int main(void){
	int a,b,i,j,T,input;
	scanf("%d",&T);
	while(T-->0){
		scanf("%d",&n);
		E.clear();
		E.resize(n,vector<int>());
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&input);
				if(input==1)
					E[j].push_back(i);
			}
		}
		top=0;
		low=dfs(top,1005);
		while(top!=low){
			top=low;
			low=dfs(low,1005);
		}
		for(i=0;i<1005;i++)
			vis[i]=0;
		count=0;
		dfs_lvup(low);
		printf("%d\n",count);
	}
	return 0;
}
