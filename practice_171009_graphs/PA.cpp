#include<iostream>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std; 
int x[200],y[200],vis[200];
struct node{
	int s,e;
	double dis;
	bool operator<(const node& b) const
    {
        return dis > b.dis;
    }
};
int main(void){
	int n,sec=0,i,p1,p2;
	node pic,tok;
	double ans;
	while(scanf("%d",&n)&&n!=0){
		for(i=0;i<200;i++)
			vis[i]=0;
		priority_queue<node> E;
		sec++;
		ans=0;
		for(i=0;i<n;i++){
			scanf("%d%d",&x[i],&y[i]);
		}
		pic.s=0;
		for(i=1;i<n;i++){
			pic.e=i;
			p1=x[0]-x[i],p2=y[0]-y[i];
			pic.dis=sqrt(p1*p1+p2*p2);
			E.push(pic);
		}
		vis[0]=1;
		while(vis[1]==0){
			pic=E.top();E.pop();
			if(pic.dis>ans)
				ans=pic.dis;
			vis[pic.e]=1;
			tok.s=pic.e;
			for(i=0;i<n;i++){
				if(!vis[i]){
					tok.e=i;
					p1=x[tok.e]-x[tok.s],p2=y[tok.e]-y[tok.s];
					tok.dis=sqrt(p1*p1+p2*p2);
					E.push(tok);
				}
			}
		}
		printf("Scenario #%d\n",sec);
		printf("Frog Distance = %.3lf\n\n",ans);
	}
	return 0;
}
