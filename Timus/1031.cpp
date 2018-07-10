#include<bits/stdc++.h>
using namespace std;
const long long INF = 1023456789;
int main(void){
	long long L[3],C[3],n,s,end;
	long long S[10004]={0},dp[10004]={0};
	int i,j,k;
	for(i=0;i<3;i++)
		scanf("%lld",&L[i]);
	for(i=0;i<3;i++)
		scanf("%lld",&C[i]);
	scanf("%lld%lld%lld",&n,&s,&end);
	for(i=2;i<=n;i++)
		scanf("%lld",&S[i]);
	if(s>end)
		i=s,s=end,end=i;
	long long t[3],ans;
	t[0]=s,t[1]=s,t[2]=s;
	dp[s]=0;
	for(i=s+1;i<=end;i++){
		ans=INF;
		for(j=0;j<3;j++){
			while((S[i]-S[t[j]])>L[j])
				t[j]++;
			if(t[j]<i)
				ans=min(ans,dp[t[j]]+C[j]);
		}
		dp[i]=ans;
		// printf("%d %d\n",i,dp[i]);
	}
	printf("%lld",dp[end]);
	return 0;
} 
