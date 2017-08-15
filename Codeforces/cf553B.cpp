#include<bits/stdc++.h>
using namespace std;
int n;
long long int ans;
long long int dp[200100]={0},md[200100]={0};
int par[200100]={0},eft[200100]={0},sn[200100]={0};
int main(void){
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++){
		scanf("%d %d",&par[i],&eft[i]);
		par[i]--;
	}
	int tmp;ans=0;
	for(i=n-1;i>=0;i--){
		if(sn[i]%2==1){
			tmp=md[i];
			if(eft[i]>md[i]){
				dp[i]-=md[i];
				dp[i]+=eft[i];
				tmp=eft[i];
			}
		}
		else{
			dp[i]+=eft[i];
			tmp=eft[i];
		}
		if(dp[i]>ans)
			ans=dp[i];
		if(i>0){
			if(sn[par[i]]==0||md[par[i]]>tmp){
				md[par[i]]=tmp;
			}
			dp[par[i]]+=dp[i];
			sn[par[i]]++;
		}
	}
	printf("%I64d",ans);
	return 0;
} 
