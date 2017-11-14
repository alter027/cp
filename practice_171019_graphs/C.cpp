#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,k,i;
	scanf("%d %d",&n,&k);
	if(n<k||k==0)
		printf("-1\n");
	else{
		for(i=n;i>k;i--)
			printf("%d ",i);
		for(i=1;i<=k;i++)
			printf("%d ",i);
		printf("\n");
		for(i=1;i<=n;i++)
			printf("%d ",i);
		printf("\n");
	}
	return 0;
}