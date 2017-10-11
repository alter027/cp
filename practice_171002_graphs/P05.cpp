#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int damn_rhombi;
int arr[3000];
vector<vector<int> > E;
void visit(int k){
	int i;
	for(i=0;i<E[k].size();i++)
		arr[E[k][i]]++;
}
int main(void){
//	尋找每個點兩步可以走到的地方 	//n^2
	int i,j,n,m,a,b;
	damn_rhombi=0;
	scanf("%d%d",&n,&m);
	E.clear();
	E.resize(n,vector<int>());
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		a--;b--;
		E[a].push_back(b);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			arr[j]=0;
		for(j=0;j<E[i].size();j++)
			visit(E[i][j]);
		for(j=0;j<n;j++){
			if(arr[j]>1&&i!=j)
				damn_rhombi+=(arr[j]*(arr[j]-1)/2);
		}
	}
	printf("%d\n",damn_rhombi);
	return 0;
}
