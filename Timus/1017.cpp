#include<bits/stdc++.h>
using namespace std;
long long arr[505][505]={0};
long long solve(int sum,int mx){
	int i;
	if(sum==0)
		return 1;
	if(arr[sum][mx]!=-1)
		return arr[sum][mx];
	long long ans=0;
	for(i=min(sum,mx-1);i>=1;i--)
		ans+=solve(sum-i,i);
	return arr[sum][mx]=ans;
 }
int main(void){
	int i,j,k,n;
	long long ans=0;
	scanf("%d",&n);
	memset(arr,-1,sizeof(arr));
	for(i=1;i<n;i++)
		ans+=solve(n-i,i);
	printf("%lld\n",ans);
	return 0;
}