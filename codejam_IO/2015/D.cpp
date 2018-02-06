#include<bits/stdc++.h>
using namespace std;

long long ans;
long long A[30][30]={0};

long long solve(int a,int b){
	if(A[a][b]!=0)
		return A[a][b];
	if(a==1||b==1)
		return A[a][b]=1;
	long long tmp=1;
	int i;
	for(i=2;i<=a;i++)
		tmp+=solve(b-1,i);
	return A[a][b]=tmp;
 }
int main(void){
	int T,Case=1;
	int a,b;
	scanf("%d",&T);
	while(T-->0){
		scanf("%d%d",&a,&b);
		ans=solve(a,b);
		printf("Case #%d: %lld\n",Case++,ans);
	}
	return 0;
}