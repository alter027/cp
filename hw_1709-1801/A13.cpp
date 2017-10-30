#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=30;
int head[N],deep[N],vist[N],group[N];
int fa[N][M],d1[N][M],d2[N][M];
int n,m,cnt,mn;
long long ans;
struct node{
	int a,b,w;
	bool operator<(const node& b) const
    {
        return w > b.w;
    }
 };
struct edge{
	int to,next,v;
 };
vector<edge>e;
priority_queue<node>ie;
priority_queue<node>ue;
void init(void){
	e.clear();
	e.resize(m*3);
	cnt=0;mn=1e9;ans=0;
	int i,j;
	for(i=0;i<n+5;i++)
		for(j=0;j<M+1;j++)
			fa[i][j]=0,d1[i][j]=0;
	for(i=0;i<=n+5;i++)
		head[i]=0,deep[i]=0,vist[i]=0,group[i]=i;
 }
int anc(int k){
	return k==group[k]?k:group[k]=anc(group[k]);
 }
int insert(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].v=w;
	head[u]=cnt;
 }
int InputAndMST(void){
	node tmp;
	int i;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&tmp.a,&tmp.b,&tmp.w);
		ie.push(tmp);
	}
	int count=0;
	while(!ie.empty()){
		tmp=ie.top();ie.pop();
		int p=anc(tmp.a),q=anc(tmp.b);
		if(p!=q){
			group[p]=q;
			insert(tmp.a,tmp.b,tmp.w);
			insert(tmp.b,tmp.a,tmp.w);
		}
		else
			ue.push(tmp);
	}
 }
void dfs(int x){
	vist[x]=1;
	int i,j;
	fa[x][0]=x;d1[x][0]=0;
	for(i=2,j=2;i<M;i++,j*=2){
		if(deep[x]<j)
			break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
        d1[x][i]=max(d1[x][i-1],d1[fa[x][i-1]][i-1]);
	}
	for(i=head[x];i!=0;i=e[i].next){
		if(vist[e[i].to]!=1){
			deep[e[i].to]=deep[x]+1;
			fa[e[i].to][1]=x;
			d1[e[i].to][1]=e[i].v;
			dfs(e[i].to);
		}
	}
 }
void cal(int x,int y,int f,int v){
	int mx1=0,mx2=0,i;
	int t=deep[x]-deep[f];
	for(i=0;i<M;i++){
		if(t&(1<<i)){
			if(d1[x][i+1]>mx1)
				mx1=d1[x][i+1];
			x=fa[x][i+1];
		}
	}
	t=deep[y]-deep[f];
	for(i=0;i<M;i++){
		if(t&(1<<i)){
			if(d1[y][i+1]>mx1)
				mx1=d1[y][i+1];
			y=fa[y][i+1];
		}
	}
	mn=min(mn,v-mx1);
 }
int lca(int x,int y){
	int i;
	if(deep[x]<deep[y])
		swap(x,y);
	int t=deep[x]-deep[y];
	for(i=0;i<M;i++)
		if(t&(1<<i))
			x=fa[x][i+1];
	for(i=16;i>=0;i--)
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	if(x!=y)
		return fa[x][1];
	else
		return x;
 }
void solve(void){
	int f;
	node tmp;
	while(!ue.empty()){
		tmp=ue.top();ue.pop();
		f=lca(tmp.a,tmp.b);
		cal(tmp.a,tmp.b,f,tmp.w);
	}
	printf("%d\n",mn);
 }
int main(void){
	int T;
	scanf("%d",&T);
	while(T-->0){
		int i,j;
		scanf("%d%d",&n,&m);
		init();
		InputAndMST();
 		dfs(0);
 		solve();
	}
	return 0;
 }