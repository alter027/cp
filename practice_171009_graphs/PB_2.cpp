#include<iostream>
#include<vector>
#include<set>
#include<cstdio>
#define INF 20000000000000000
using namespace std;
int n,m;
vector<vector<int> >g;
long long d[100050];
long long get_ans(long long a){
	long long tmp,ans;
	tmp=a/20+a%20;
	ans=(a/20)*20;
//	printf("tmp=%lld,ans=%lld\n",tmp,ans);
	while(tmp>19){
		ans+=(tmp/20)*20;
		tmp=tmp/20+tmp%20;
//		printf("tmp=%lld,ans=%lld\n",tmp,ans);
	}
	ans+=tmp;
	if(tmp!=0)
		ans++;
	return ans;
}
int main(void){
	int i,j,k,w,t;
	int count=0;
	char u[5],v[5];
	while(scanf("%d",&n)&&n!=-1){
		count++;
		g.clear();
		g.resize(257,vector<int>());
		for(i=0;i<n;i++){
			scanf("%s%s",u,v);
			g[(int)v[0]].push_back((int)u[0]);
			g[(int)u[0]].push_back((int)v[0]);
		}
		long long carry;char a[5],b[5];long long tmp;
		scanf("%lld%s%s",&carry,a,b);
		fill(d,d+257,INF);
		d[(int)b[0]]=carry;
		set<int >s;
		s.insert((int)b[0]);
		while(!s.empty()){
			t=*s.begin();
			s.erase(s.begin());
			if(t>96)
				tmp=d[t]+1;
			else
				tmp=get_ans(d[t]);
			for(i=0;i<g[t].size();i++){
				if(d[g[t][i]]>tmp){
					d[g[t][i]]=tmp;
					s.insert(g[t][i]);
				}
//				printf("%c d[g[t][i]]=%d\n",(char)g[t][i],d[g[t][i]]);
			}
		}
		printf("Case %d: %lld\n",count,d[(int)a[0]]);
	}
	return 0;
}

