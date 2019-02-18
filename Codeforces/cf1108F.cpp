#include<bits/stdc++.h>
using namespace std;
priority_queue<node> E;
int n,m;
struct node{
	int s,e;
	double dis;
	bool operator<(const node& b) const
    {
        return dis > b.dis;
    }
};
void tri(){
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
}
int main(void){
	scanf("%d%d",&n,&m);
	node tmp;
	for(int i=0;i<m;i++)
		tmp
	return 0;
}
