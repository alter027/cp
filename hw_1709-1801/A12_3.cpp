#include<bits/stdc++.h>
using namespace std;
#define INF 1023456789
int n,m,ps,pt;
int h[5000];
int d[5000];
struct node{
	int s,e,dis;
 };
vector<vector<node> >g;
void input(void){
	int u,v,w,i;
	scanf("%d%d%d%d",&n,&m,&ps,&pt);
	ps--;pt--;
	for(i=0;i<n;i++)
		scanf("%d",&h[i]);
	g.clear();
	g.resize(5000,vector<node>());
	node temp;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		u--;v--;
		temp.dis=-w-(h[u]-h[v]);
		temp.s=u;
		temp.e=v;
		g[u].push_back(temp);
 //		printf("%d %d %d\n",temp.s,temp.e,temp.dis);
		temp.dis=-w-(h[v]-h[u]);
		temp.s=v;
		temp.e=u;
		g[v].push_back(temp);
 //		printf("%d %d %d\n",temp.s,temp.e,temp.dis);
	}
 }
void print_d(void){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",d[i]);
	printf("\n");
 }
void solve(void){
	node t,temp;
	int i,j;
	fill(d,d+5000,INF);
	set<node >s;
	d[pt]=0;
	int c=0;
	while(c==0){
		c=1;
 //		print_d();
		for(i=0;i<n;i++){
			if(d[i]==INF)
				continue;
			for(j=0;j<g[i].size();j++){
				if(d[g[i][j].e]==0);
				else if(d[g[i][j].e]>d[i]-g[i][j].dis){
					d[g[i][j].e]=d[i]-g[i][j].dis;
					if(d[g[i][j].e]<0)
						d[g[i][j].e]=0;
					c=0;
 //  					print_d();
				}
			}
		}
	}
	printf("%d\n",d[ps]);
 }
int main(void){
	int i,j,k,w,t,T;
	int count=0;
	int u,v;
	scanf("%d",&T);
	while(T-->0){
		input();
		solve();
	}
	return 0;
 }