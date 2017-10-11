#include<bits/stdc++.h>
#define INF 2000000000000000000
using namespace std;
int n,m,p[100050];
vector<pair<long long,int> >g[100050];
long long d[100050];

void find(int i){
	if(p[i]!=-1)
		find(p[i]);
	printf("%d ",i);
}
int main(void){
	int i,j,k,u,v,w,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(pair<long long,int>(v,w));
		g[v].push_back(pair<long long,int>(u,w));
	}
	fill(p,p+n+5,-1);
	fill(d,d+n+5,INF);
	d[1]=0;
	set<pair<long long,int> >s;
	s.insert(pair<long long,int>(d[1],1));
	while(!s.empty()){
		t=s.begin()->second;
		s.erase(s.begin());
		for(i=0;i<g[t].size();i++){
			if(d[g[t][i].first]>d[t]+g[t][i].second){
				d[g[t][i].first]=d[t]+g[t][i].second;
				p[g[t][i].first]=t;
				s.insert(pair<long long,int>(d[g[t][i].first],g[t][i].first));
			}
		}
	}
	if(d[n]==INF){
		printf("-1\n");
	}
	else{
		find(n);
		printf("\n");
	}
	return 0;
}

