#include<bits/stdc++.h>
using namespace std;
int main(void){
	string str;
	cin>>str;
	int c1=0,c2=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='0'){
			if(c1) printf("3 1\n"),c1--;
			else printf("1 1\n"),c1++;
		}
		else{
			if(c2) printf("4 1\n"),c2--;
			else printf("4 3\n"),c2++;
		}
	}
	return 0;
}
