#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int arr[1005],vis[1005];
int n,m,count[3];
vector<vector<int> > E;
int max(int a,int b){
	return a>b ? a : b;
}
int min(int a,int b){
	return a<b ? a : b;
}
int bfs(int k){
	int i,tmp;
	if(vis[k]!=0)
		return 0;
	vis[k]=1;
	if(arr[k]==2){
		tmp=1;
	}
	else
		arr[k]=1,tmp=2;
	for(i=0;i<E[k].size();i++){
		if(arr[E[k][i]]!=2&&arr[E[k][i]]!=1){
			count[tmp]++;
			arr[E[k][i]]=tmp;
		}
		if(arr[E[k][i]]!=tmp){
			return -1;
		}
		int flag=bfs(E[k][i]);
		if(flag==-1)
			return -1;
	}
	return 0;
}
int main(void){
	int a,b,i,T;
	scanf("%d",&T);
	while(T-->0){
		scanf("%d%d",&n,&m);
		E.clear();
		E.resize(n,vector<int>());
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			a--;b--;
			E[b].push_back(a);
			E[a].push_back(b);
		}
		int dp[1005],c[1005],pick=0,flag=0,ans=0;
		for(i=0;i<n;i++)
			arr[i]=0,vis[i]=0;
		for(i=0;i<n;i++){
			if(vis[i]==0){//here form the backpack
				count[1]=1;count[2]=0;
				arr[i]=1;
				flag=bfs(i);
//				printf("c1=%d,c2=%d\n",count[1],count[2]);
				ans+=min(count[1],count[2]);
				dp[pick++]=max(count[1]-count[2],count[2]-count[1]);
			}
			if(flag==-1){
//				printf("-1 here %d\n",i);
				break;
			}
		}
//		for(i=0;i<n;i++)
//			printf("%d ",arr[i]);
//		printf("\n");
		if(flag==0){
			for(i=0;i<=1000;i++)
				c[i]=0;
			c[0]=1;
			int V=n-ans*2,j; 
			for(i=0;i<pick;i++){
				for(j=V;j>=0;j--){
					if(c[j]){
						if(j+dp[i]<=1000)
							c[j+dp[i]]=1;
					}
				}
			}
//			printf("V=%d,V/2=%d",V,V/2);
			for(i=V/2;i<=V;i++){
				if(c[i]!=0)
					break;
			}
			printf("%d\n",max(ans+i,n-ans-i));
		}
		else
			printf("-1\n");
		
	}
	return 0;
}
