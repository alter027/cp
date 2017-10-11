#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int count;
int arr[150];
int n,m,ans;
vector<vector<int> > E;
int bfs(int k){
	int i;
	if(arr[k]!=0)
		return 0;
	arr[k]=1;
	for(i=0;i<E[k].size();i++)
		bfs(E[k][i]);
	count++;
	if(count<n)
		printf("%d ",k+1);
	else
		ans=k+1;
	return 0;
}
int main(void){
	int a,b,i;
	while(scanf("%d%d",&n,&m)&&!(n==0&&m==0)){
		E.clear();
		E.resize(n,vector<int>());
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			a--;b--;
			E[b].push_back(a);
		}
		count=0;
		for(i=0;i<n;i++)
			arr[i]=0;
		for(i=0;i<n;i++)
			bfs(i);
		printf("%d\n",ans);
	}
	return 0;
}
