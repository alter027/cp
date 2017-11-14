#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int vis[2005];
struct node{
	int a,b;
	int dis;
	bool operator<(const node& b) const
    {
        return dis > b.dis;
    }
 };
priority_queue<node> E;
int anc(int i){
	if(vis[i]!=i){
		return vis[i]=anc(vis[i]);
	}
	return i;
 }
void solve(void){
	node pic;
	int count=0;//++ while add a new edge, until count = n-1
	while(count<n-1){
		pic=E.top();E.pop();
		if(vis[pic.a]==-1||vis[pic.b]==-1){
			if(vis[pic.a]!=-1)
				vis[pic.b]=anc(pic.a);
			else if(vis[pic.b]!=-1)
				vis[pic.a]=anc(pic.b);
			else
				vis[pic.a]=vis[pic.b]=pic.a;
			ans+=pic.dis;
			count++;
		}
		else{
			int a1=anc(pic.a),a2=anc(pic.b);
			if(a1!=a2){
				vis[a2]=a1;
				ans+=pic.dis;
				count++;
			}
		}
//		cout<<count<<endl;
	}
 }
void init(void){
	ans=0;
	for(int i=0;i<2000;i++)
		vis[i]=-1;
  	while(!E.empty())
  	{
    	E.pop();
  	}
 }
void input(void){
	string str1,str2;
	map<string,int>point;
	map<string,int>::iterator iter;
	scanf("%d%d",&n,&m);
	node temp;
	int w,p1,p2;
	int count=0;
	while(m-->0){
		cin>>str1>>str2>>w;
		iter=point.find(str1);
		if(iter!=point.end())
			p1=iter->second;
		else{
			p1=count;
			point[str1]=count++;
		}
		iter=point.find(str2);
		if(iter!=point.end())
			p2=iter->second;
		else{
			p2=count;
			point[str2]=count++;
		}
		temp.a=p1;
		temp.b=p2;
		temp.dis=w;
		E.push(temp);
//		cout<<temp.a<<" "<<temp.b<<" "<<temp.dis<<endl;
	}
 }
int main(void){
	int T,w;
	scanf("%d",&T);
	while(T-->0){
		init();
		input();
		solve();
		printf("%d\n",ans);
		if(T!=0)
			printf("\n");
	}
	return 0;
 }
