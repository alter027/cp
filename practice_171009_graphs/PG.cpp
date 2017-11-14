#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
int a[105],b[105],arr[205];
int n,m,pans,nans;
vector<vector<int> > E;
queue<int> q;
void dfs(int k){
	if(arr[k]<2)
		return;
	arr[k]=0;
	int i;
	for(i=0;i<E[k].size();i++){
		if(arr[E[k][i]]>1){
			dfs(E[k][i]);
			if(E[k][i]<100)
				nans++;
			else
				pans++;
		}
	}
//	printf("%d ",k);
}
int main(void){
	int i,j,T;
	int v,ans,t,u;
	scanf("%d",&T);
	for(v=1;v<=T;v++){
		E.clear();
		E.resize(205,vector<int>());
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&b[i]);
		for(i=0;i<=200;i++){
			arr[i]=0;
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				if(b[j]==0||(a[i]!=0&&b[j]%a[i]==0)){
//					printf("%d %d\n",a[i],b[j]);
					E[j+100].push_back(i);
					E[i].push_back(j+100);
					arr[j+100]++;arr[i]++;
				}
		}
		for(i=0;i<200;i++){
			if(arr[i]==1)
				q.push(i);
		}
		ans=0;pans=0;nans=0;
		while(!q.empty()){
			t=q.front();
			q.pop();
			if(arr[t]==0) continue;
			for(i=0;i<E[t].size();i++){
				if(arr[E[t][i]]>0)
					u=E[t][i];
			}
			for(i=0;i<E[u].size();i++){
				if(arr[E[u][i]]>0){
					arr[E[u][i]]--;
					if(arr[E[u][i]]==1)
						q.push(E[u][i]);
				}
			}
			arr[t]=0;arr[u]=0;
/*			if(t<100)
				printf("%d %d\n",a[t],b[u-100]);
			else
				printf("%d %d\n",a[u],b[t-100]);
*/			ans++;
		}
		printf("ans=%d\n",ans);
		for(i=0;i<100;i++){
			if(arr[i]>1){
				pans=0;nans=0;
				if(i<100)
					nans++;
				else
					pans++;
				dfs(i);
//				printf("\n\n");
//				printf("nans=%d,pans=%d\n\n",nans,pans);
				ans+=(pans>nans?nans:pans);
			}
		}
		printf("Case %d: %d\n",v,ans);
	}
	return 0;
}
