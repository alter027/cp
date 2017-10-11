#include<stdio.h>
long long gcd(long long a,long long b){
	while(a>0&&b>0){
		if(a>b)
			a-=b;
		else
			b-=a;
	}
	return a==0?b:a;
}
int main(void){
	int arr[250],idem[250];
	int n,i,j,k;
	long long ans=1,count;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		arr[i]--;
	}
	for(i=0;i<n;i++){
		count=1;
		k=arr[i];
		while(k!=i&&count<=n){
			k=arr[k];
			count++;
		}
		if(k==i){
			idem[i]=count;
			ans=ans*idem[i]/gcd(ans,idem[i]);
		}
		else
			idem[i]=0;
	}
	int lg=0;
	for(i=0;i<n;i++){
		if(idem[i]==0){
			count=1;
			k=arr[i];
			while(idem[k]==0){
				k=arr[k];
				count++;
			}
			if(count>lg)
				lg=count;
		}
	}
	if(lg!=0)
		ans=(lg+ans-1)/ans*ans;
	printf("%lld\n",ans);
	return 0;
}
