#include<bits/stdc++.h>
int main(void){
	int T,n,m,arr[20][20];
	int i,j,k;
	scanf("%d",&T);
	while(T-->0){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				scanf("%d",&arr[i][j]);
		}
		for(j=1;j<m;j++)
			arr[0][j]=arr[0][j-1]+arr[0][j];
		for(i=1;i<n;i++){
			arr[i][0]=arr[i-1][0]+arr[i][0];
//			printf("%d ",arr[i][0]);
			for(j=1;j<m;j++){
				arr[i][j]=std::min(arr[i-1][j],arr[i][j-1])+arr[i][j];	
//				printf("%d ",arr[i][j]);
			}
//			printf("\n");
		}
		printf("%d\n",arr[n-1][m-1]);
	}
	return 0;
}
