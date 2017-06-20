#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;
int main(void){
	long long int til,count,total;
	int n,k,num;
	map<long long int,int>sum;
	map<long long int,int>::iterator iter;
	while(scanf("%d",&n)!=EOF&&n!=0){
		sum.clear();
//		sum.insert(pair<long long int,int>(0,0));
		sum[0]=0;
		til=0;
		for(k=1;k<=n;k++){
			cin>>num;
			til=til+num;
			iter=sum.find((long long int)til);
			if(iter!=sum.end())
				iter->second++;
			else{
				sum[(long long int)til]=0;
			}
		}
		total=0;
		for(iter=sum.begin();iter!=sum.end();iter++){
//				printf("%lld,%d\n",iter->first,iter->second);
				count=iter->second;
				if(count>0)
					while(count>0){
						total=total+count;
						count--;
					}
		}
//		printf("sum.begin()=%d,sum.end()=%d\n",sum.begin(),sum.end());
		cout<<total<<"\n";
	}
	return 0;
}
