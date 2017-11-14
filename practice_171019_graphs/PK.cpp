#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int arr[250][4];
vector<vector<int> >g;
void dfs(int k){
	int t0=0,t1=1,t2=1,t3=1,i;
	//  t0 nop here
	//  t1 down sum
	//  t2 rely t1
	//  t3 rely t2
	for(i=0;i<g[k].size();i++){
		int tmp=g[k][i];
		dfs(tmp);
		t1+=arr[tmp][0];
		t3&=arr[tmp][2];
		t0+=max(arr[tmp][0],arr[tmp][1]);
		if(arr[tmp][0]==arr[tmp][1])
			t2=0;
		else{
			if(arr[tmp][0]>arr[tmp][1])
				t2&=arr[tmp][2];
			else
				t2&=arr[tmp][3];
		}
	}
	arr[k][0]=t0;
	arr[k][1]=t1;
	arr[k][2]=t2;
	arr[k][3]=t3;
 }
void init(void){
	g.clear();
	g.resize(250,vector<int>());
 }
void input(void){
	string str1,str2;
	map<string,int>point;
	map<string,int>::iterator iter;
	int w,p1,p2;
	int count=1;
	m=n-1;
	cin>>str1;
	point[str1]=0;
	while(m-->0){
		cin>>str1>>str2;
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
		g[p2].push_back(p1);
	}
 }
void output(void){
	printf("%d ",max(arr[0][0],arr[0][1]));
	if(arr[0][0]>arr[0][1]){
		if(arr[0][2])
			printf("Yes\n");
		else
			printf("No\n");
	}
	else if(arr[0][1]>arr[0][0]){
		if(arr[0][3])
			printf("Yes\n");
		else
			printf("No\n");
	}
	else
		printf("No\n");
 }
int main(void){
	int T,w;
	while(scanf("%d",&n)&&n!=0){
		init();
		input();
		dfs(0);
		output();
	}
	return 0;
 }
