#include<bits/stdc++.h>
using namespace std;
int second_block(long long top,long long low){
	string str;
	long long mid;
	while(1){
		mid=(top+low+1)/2;
		// printf("second: ");
		printf("? %I64d %I64d\n",low,mid);
		cin>>str;
		if(str=="x") top=mid;
		else if(str=="y") low=mid;
		else
			return 1;
		if(low==top||low==top-1){
			printf("! %I64d\n",top);
			return 0;
		}
	}
	return 1;
}
int first_block(void){
	string str;
	long long top=2,low=1;
	while(1){
		// printf("first: ");
		printf("? %I64d %I64d\n",low,top);
		cin>>str;
		if(str=="x"){ 
			if(top==2&&low==1){
				printf("? %I64d %I64d\n",top,low);
				cin>>str;
				if(str=="x") printf("! 1\n");
				else printf("! 2\n");
				return 0;
			}
			if(second_block(top,low)) return 1;
			else return 0;
		}
		else if(str=="y") 
			low=top,top*=2;
		else return 1;
	}
	return 0;
}
int main(void){
	string str;
	while(1){
		cin>>str;
		if(str=="start"){
			if(first_block())
				return 0;
		}
		else return 0;
	}
	return 0;
}

