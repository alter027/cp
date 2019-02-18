#include<bits/stdc++.h>
using namespace std;
int main(void){
	vector<int> vec;
	int n,tmp;
	int a,b,j=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
	b=vec[n-1];
	for(int i=1;i<=b;i++){
		if(b%i==0){
			while(i!=vec[j]) j++;
			vec[j]=0;
		}
	}
	sort(vec.begin(),vec.end());
	a=vec[n-1];
	printf("%d %d\n",a,b);
	return 0;
}
