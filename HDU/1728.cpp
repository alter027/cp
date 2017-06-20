#include<iostream>
#include<cstdio>
using namespace std;
int turns,x1,x2,y1,y2,m,n;
int dir[10000];
int maze[100][100];
int print_map(void){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	printf("-----\n");
}
int go_to(int x,int y,int turn,int step){
//	printf("now at (%d,%d),turn=%d\n",x,y,turn);
	if(turn>turns){
		return 0;
	}
	if(x==x2&&y==y2){
		return 1;
	}
	if(maze[x][y]==1||maze[x][y]==2)
		return 0;
	else{
		maze[x][y]=2;
	}
//	print_map();
	int i;
	for(i=1;i<5;i++){
		dir[step]=i;
		if(5-i==dir[step-1]) continue;
		if(i!=dir[step-1])turn++;
		if(i==1&&x>0){
			if(go_to(x-1,y,turn,step+1)) return 1;
		}
		else if(i==2&&y<n){
			if(go_to(x,y+1,turn,step+1)) return 1;
		}
		else if(i==3&&x<m){
			if(go_to(x+1,y,turn,step+1)) return 1;
		}
		else if(i==4&&y>0){
			if(go_to(x,y-1,turn,step+1)) return 1;	
		}
		if(i!=dir[step])turn--;
//		printf("i=%d\n",i);
	}
	maze[x][y]=0;
	return 0;
}
int main(void){
	int ncase;
	scanf("%d",&ncase);
	while(ncase-->0){
		int i,j;
		char input;
		scanf("%d %d%c",&m,&n,&input);
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%c",&input);
				if(input=='*'){
					maze[i][j]=1;
				} 
				if(input=='.'){
					maze[i][j]=0;
				}
//				printf("%d\n",maze[m][n]);
			}
			scanf("%c",&input);
		}
//		print_map();
		scanf("%d%d%d%d%d",&turns,&x1,&y1,&x2,&y2);
		x1-=1;x2-=1;y1-=1;y2-=1;
		dir[0]=0;
		int ans=go_to(x1,y1,-1,1);
		if(ans) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
