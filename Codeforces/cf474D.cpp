#include<iostream>
#define md 1000000007
using namespace std;
int f[100050]={0},s[100050]={0};
int main(void){
	int t,k;
	int i,j;
	cin>>t>>k;
	for(i=0;i<k;i++){
		f[i]=1;
		s[i]=s[i-1]+f[i];

	}
	for(i=k;i<100040;i++){
		f[i]=f[i-1]+f[i-k];
		f[i]%=md;
		s[i]=s[i-1]+f[i];
		s[i]%=md;
	}
	int ans;
	int a,b;
	while(t-->0){
		cin>>a>>b;
		ans=s[b]-s[a-1];
		ans=(ans+md)%md;
		cout<<ans<<endl;
	}
	return 0;
}
