#include<stdio.h>
#include<string.h>
int alpha[26][26],visit[26];
void bfs(int n){
	if(visit[n]==1)
		return;
	visit[n]=1;
	int i;
	for(i=0;i<26;i++){
		if(alpha[n][i]==1)
			bfs(i);
	}
	printf("%c",n+97);
}
int main(void){
	char str[100][100];
	int n,i,j,k,l1,l2;
	scanf("%d",&n);
	for(i=0;i<26;i++){
		for(j=0;j<i;j++){
			alpha[i][j]=1;
		}
		for(;j<26;j++){
			alpha[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
		visit[i]=0;
	for(i=0;i<n;i++)
		scanf("%s",str[i]);
	for(i=1;i<n;i++){
		l1=strlen(str[i-1]);l2=strlen(str[i]);
		l1=l1<l2?l1:l2;
		for(j=0;j<l1;j++){
			if(str[i][j]!=str[i-1][j]&&str[i-1][j]>str[i][j]){
				str[(int)str[i-1][j]-97][(int)str[i][j]-97]=1;
			}
		}
	}
	for(i=0;i<n;i++)
		bfs(0);
	return 0;
}
