#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,m,k,i,j;
	int arr[100][100];
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&arr[i][j]);
	for(i=1;i<n;i++){
		
	}
	int ans=0,del=0,count,space,pre,tok,pic;
	for(j=0;j<m;j++){
		pre=0,count=0,space=0,tok=0,pic=0;
		for(i=0;i<n;i++){
			if(arr[i][j]==0||count==k){
				pic+=count;
				if(count>pre){
					pre=pre>count?pre:count;
					tok=pic;
				}
				count=0;
			}
			else
				count++;
//			printf("pre=%d,count=%d,space=%d,tok=%d,pic=%d\n",pre,count,space,tok,pic);
			if(count==k)
				break;
		}
		pic+=count;
		if(count>pre){
			pre=pre>count?pre:count;
			tok=pic;
		}
		ans+=pre;
		del+=(tok-pre);
//		printf("%d %d\n",pre,tok);
	}
	printf("%d %d\n",ans,del);
	return 0;
}

