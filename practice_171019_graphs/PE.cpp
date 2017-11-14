#include<cstdio>
#include<queue>
using namespace std;
int main(void){
	int i,n;
	priority_queue<long long,vector<long long>,greater<long long> > sheep;
	long long ans=0,input;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&input);
		sheep.push(input);
	}
	long long p1,p2;
	while(1){
		p1=sheep.top();sheep.pop();
		if(sheep.empty())
			break;
		p2=sheep.top();sheep.pop();
		ans+=p1+p2;
		sheep.push(p1+p2);
	}
	printf("%lld\n",ans);
	return 0;
}
