#include<stdio.h>
int ans;
char arr[105][105];
int m,n;
void visit(int i,int j){
	arr[i][j]='O';
	if(i<m-1&&arr[i+1][j]=='@')
		visit(i+1,j);
	if(i>0&&arr[i-1][j]=='@')
		visit(i-1,j);
	if(j<n-1&&arr[i][j+1]=='@')
		visit(i,j+1);
	if(j>0&&arr[i][j-1]=='@')
		visit(i,j-1);
		
	if(i<m-1&&j<n-1&&arr[i+1][j+1]=='@')
		visit(i+1,j+1);
	if(i<m-1&&j>0&&arr[i+1][j-1]=='@')
		visit(i+1,j-1);
	if(i>0&&j<n-1&&arr[i-1][j+1]=='@')
		visit(i-1,j+1);
	if(i>0&&j>0&&arr[i-1][j-1]=='@')
		visit(i-1,j-1);
}
int main(void){
	int i,j;
	while(scanf("%d%d",&m,&n)&&!(n==0&&m==0)){
		ans=0;
		for(i=0;i<m;i++){
			scanf("%s",&arr[i]);
		}
		ans=0;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(arr[i][j]=='@'){
					visit(i,j);
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
