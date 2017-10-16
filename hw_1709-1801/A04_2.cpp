#include<cstdio>
const long long mod=1000000007;
long long P[10050];
void init(){
	P[0]=1;
	int i;
	for(i=1;i<10050;i++)
		P[i]=P[i-1]*i%mod;
}
long long fac(long long a,long long n){
	long long ans=1;
	while(n){
		if(n&1){
			ans*=a;
			ans%=mod;
		}
		n/=2;
		a*=a;
		a%=mod;
	}
	return ans;
}
long long comb(int n,int m){
	if(n<m)
		return 0;
	if(n==m)
		return 1;
	long long a=P[n];
	long long b=P[m]*P[n-m]%mod;
	long long p=fac(b,mod-2);
	return a*p%mod;
}
int main(void){
	int T;
	long long a,b,M;
	init();
	scanf("%d",&T);
	while(T-->0){
		scanf("%lld%lld%lld",&a,&b,&M);
		if(a>=b){
			long long ans=1;
			while(a!=0&&b!=0){
				ans*=comb(a%M,b%M);
				ans%=mod;
				a/=M;b/=M;
			}
			printf("%lld\n",ans);
		}
		else
			printf("0\n");
	}
	return 0;
}
