#include<bits/stdc++.h>
void dfs(int i,int n,int k){
	if(n==1){
		printf("%d ",i);
		return;
	}
	k--;
	if(k==0){
		int j;
		for(j=0;j<n;j++)
			printf("%d ",i+j);
		return;
	}
	else if((k/2)%2){
		dfs(i+n-n/2,n/2,k/2);
		dfs(i,n-n/2,k/2);
	}
	else{
		dfs(i+n-n/2,n/2,k/2-1);
		dfs(i,n-n/2,k/2+1);
	}
}
int main(void){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k<=2*n-1&&k>=0&&k%2){
		dfs(1,n,k);
		printf("\n");
	}
	else
		printf("-1\n");
}