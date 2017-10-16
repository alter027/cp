#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long f[2000000],visit[25];

int main(void){
	long long n,m,a,b;
	int T;
	scanf("%d",&T);
	while(T-->0){
		scanf("%d%d",&n,&m);
		long long i,j,t;
		for(i=0;i<(1<<n);i++){
			f[i]=0;
			visit[i]=0;
		}
		for(i=0;i<m;i++){
			cin>>a>>b;
			visit[a]+=1<<(b-1);
		}
		f[0]=1;
		for(i=1;i<(1<<n);i++){
			int num=0;
			for(j=i;j>0;j=j-(j&-j))
				num++;
			for(j=i;j>0;j=j-(j&-j)){
				if((visit[num]&(j&-j))==0)
					f[i]+=f[i&~(j&-j)];
			}
		}
		cout<<f[(1<<n)-1]<<endl;
	}
	return 0;
} 
