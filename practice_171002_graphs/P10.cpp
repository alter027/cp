#include<stdio.h>
int main(void){
	int arr[200],idem[200];
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		arr[i]--;
	}
	for(i=0;i<n;i++){
		j=1;k=i;
		while(f[k]!=i){
			k=f[k];j++
		}
		idem[i]=j;
	}
	int ans=idem[0];
	for(i=1;i<n;i++){
		ans=ans*idem[i]/gcd(ans,idem[i]);
	}
	printf("")
	return 0;
}
