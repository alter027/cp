#include<bits/stdc++.h>
using namespace std;
int n,m,ans[25005];
int op,ind;
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
	while(count<n-1&&!E.empty()){
		pic=E.top();E.pop();
		if(vis[pic.a]==-1||vis[pic.b]==-1){
			if(vis[pic.a]!=-1)
				vis[pic.b]=anc(pic.a);
			else if(vis[pic.b]!=-1)
				vis[pic.a]=anc(pic.b);
			else
				vis[pic.a]=vis[pic.b]=pic.a;
			count++;
		}
		else{
			int a1=anc(pic.a),a2=anc(pic.b);
			if(a1!=a2){
				vis[a2]=a1;
				count++;
			}
			else
				ans[ind++]=pic.dis;
		}
	}
 }
void init(void){
	op=0;ind=0;
	for(int i=0;i<2000;i++)
		vis[i]=-1;
 }
void input(void){
	node temp;
	int w,p1,p2,i;
	int count=0;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&p1,&p2,&w);
		temp.a=p1;
		temp.b=p2;
		temp.dis=w;
		E.push(temp);
	}
 }
void output(void){
	int i;
	if(ind==0&&E.empty()){
		printf("forest\n");
		return;
	}
	if(ind!=0&&E.empty()){
		for(i=0;i<ind-1;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[ind-1]);
		return;
	}
	node temp;
  	while(!E.empty())
  	{
    	temp=E.top();E.pop();
    	ans[ind++]=temp.dis;
  	}
	for(i=0;i<ind-1;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[ind-1]);
 }
int main(void){
	while(scanf("%d%d",&n,&m)&&!(n==0&&m==0)){
		init();
		input();
		solve();
		output();
	}
	return 0;
 }
