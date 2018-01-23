#include<bits/stdc++.h>
using namespace std;  
  
typedef long long ll;  
typedef unsigned int uint;  
typedef unsigned long long ull;  
const int maxn = 40004;  
const int INF = 0x7f7f7f7f;  
const int NUM = 40004;
struct Edge{  
    int from,to,cap,flow;  
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}  
 };  
struct dinic{  
    int n,m,s,t; //结点数，边数(包括反向弧)，源点，汇点  
    vector<Edge>edge;//边表。edge[e]和edge[e^1]互为反向弧  
    vector<int>G[maxn];//邻接表。G[i][j]表示结点i的第j条边在e数组的序号  
    bool vis[maxn]; //bfs用  
    int d[maxn]; //从起点到i的距离  
    int cur[maxn]; //当前弧下标  
    void init(int n,int s,int t){  
        this -> n = n;  
        this -> s = s;  
        this -> t = t;  
        for(int i=0;i<=n;i++) G[i].clear();  
        edge.clear();  
    }   
    void addEdge(int from,int to,int cap){  
        edge.push_back(Edge(from,to,cap,0));  
        edge.push_back(Edge(to,from,0,0));  
        m=edge.size();  
        G[from].push_back(m-2);  
        G[to].push_back(m-1);  
    }  
    bool bfs(){  
        memset(vis,false,sizeof(vis));  
        queue<int>q;  
        q.push(s);  
        d[s]=0;  
        vis[s]=true;  
        while(!q.empty()){  
            int x=q.front();q.pop();  
            for(int i=0;i<G[x].size();i++){  
                Edge& e=edge[G[x][i]];  
                if(!vis[e.to]&&e.cap>e.flow){ //只考虑残量网络中的弧  
                    vis[e.to]=true;  
                    d[e.to]=d[x]+1;  
                    q.push(e.to);  
                }  
            }  
        }  
        return vis[t];  
    }  
  
    int dfs(int x,int a){  
        if(x==t||a==0) return a;  
        int flow=0,f;  
        for(int& i=cur[x];i<G[x].size();i++){ // & -> 从上次考虑的弧  
            Edge& e=edge[G[x][i]];  
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){  
                e.flow+=f;  
                edge[G[x][i]^1].flow-=f;  
                flow+=f;  
                a-=f;  
                if(a==0) break;  
            }  
        }  
        return flow;  
    }  
  
    int maxflow(){  
        int flow=0;  
        while(bfs()){  
            memset(cur,0,sizeof(cur));  
            flow+=dfs(s,INF);  
        }  
        return flow;  
    }  
 };  
dinic dc;
map<int,int>m1;
map<double,int>m2;
int n;
void init(void){
    int s,t;
    scanf("%d",&n);
    dc.init(2*n+2,0,1);
    m1.clear();m2.clear();
 }
void input(void){
    int arr[2][NUM]={0},r,s,t,cnt=2;
    int i,u,v;
    double dev;
    for(i=0;i<n;i++){
        scanf("%d%d%d",&r,&s,&t);
        dev=(double)t/s;
        if(!m1[r])
            m1[r]=cnt++;
        u=m1[r];
        if(!m2[dev])
            m2[dev]=cnt++;
        v=m2[dev];
        dc.addEdge(u,v,1);
        arr[0][u]=1;arr[1][v]=1;
    }
    for(i=2;i<cnt;i++)
        if(arr[0][i])
            dc.addEdge(0,i,1);
    for(i=2;i<cnt;i++)
        if(arr[1][i])
            dc.addEdge(i,1,1);  
 }
int main(void){  
    int T;
    scanf("%d",&T);
    while(T-->0){
        init();
        input();  
        printf("%d\n",dc.maxflow());
    }
    return 0;  
}  