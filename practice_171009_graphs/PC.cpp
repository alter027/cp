#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
int count;
int arr[10005];
int n,m;
long long ans;
vector<pair<int,long long> >E[10050];
int dfs(int k){
	if(arr[k]!=0)
		return 0;
	arr[k]=1;
	int i,j;
	long long lst=0,sec=0,flag;
	for(i=0;i<E[k].size();i++){
		if(arr[E[k][i].first]!=0)
			continue;
		flag=dfs(E[k][i].first)+E[k][i].second;
		if(flag>lst&&flag>sec){
			sec=lst;lst=flag;
		}
		else if(flag>sec){
			sec=flag;
		}
	}
//	printf("k=%d,lst=%d,sec=%d\n",k,lst,sec);
	if(i==0)
		return 0;
	if(lst+sec>ans)
		ans=lst+sec;
	return lst;
}
int work(void){
	int i;
	ans=0;
	dfs(0);
	printf("%lld\n",ans);
}
int main(void){
	char str[100];
	int a,b,i,tmp;
	int w;
    while(fgets(str, 100, stdin)){
        if(strlen(str)<3){
        	work();
			for(i=0;i<10005;i++){
				E[i].clear();
				arr[i]=0;
			}
            fgets(str, 100, stdin);
        }
        sscanf(str,"%d%d%d",&a,&b,&w);
		a--;b--;
//		printf("%d %d\n",a,b);
		E[a].push_back(pair<int,long long>(b,w));
		E[b].push_back(pair<int,long long>(a,w));
    }
    work();
	return 0;
}