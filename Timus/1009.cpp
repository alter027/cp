#include<bits/stdc++.h>
using namespace std;
int main(void){
	long long n;
	int k;
	long long arr[40];
	scanf("%d%lld",&k,&n);
	int i;
	arr[0]=0;arr[1]=n;arr[2]=n*(n-1);arr[3]=(arr[2]+arr[1]-1)*(n-1);
	for(i=4;i<=k;i++){
		arr[i]=(long long)(n-1)*(arr[i-1]+arr[i-2]);
	}
	printf("%lld\n",arr[k]);
	return 0;
}
