#include<bits/stdc++.h>
using namespace std;
int main(void){
	int T,n;
	long long q[100000],p[100000];
	scanf("%d",&T);
	int Q,i,pick,m;
	while(T-->0){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&p[i]);
		scanf("%d",&Q);
		for()
		while(Q-->0){
			long long ans=0;
			scanf("%d",&m);
			for(i=0;i<m;i++){
				scanf("%d",&pick);
				pick--;
				q[pick]=1;
			}
			if(q[0]==1)
				q[0]=q[1]=p[0];
			else
				q[0]=(p[0]>0)?p[0]:0,q[1]=(p[1]>0)?p[1]:0;
			for(i=2;i<n;i++){
				if(q[i]==1){
					q[i+1]=q[i]=q[i-2]+p[i];
					i++;
					ans=q[i];
				}
				else{
					q[i]=max(q[i-1],q[i-2]+p[i]);
					if(q[i]>ans)
						ans=q[i];
				}
			}
			printf("%lld\n",ans);
			for(i=0;i<n;i++)
				q[i]=0;
		}
	}
	return 0;
}