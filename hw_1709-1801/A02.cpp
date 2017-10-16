#include<bits/stdc++.h> 
using namespace std;
list<pair <char,int> >::iterator it,tk,ot,lt;
void printlist(list<pair <char,int> >A){
	for(ot=A.begin();ot!=A.end();ot++){
		cout<<ot->first<<" "<<ot->second<<endl;
	}
	cout<<endl;
}
int main(void){
	list< pair <char,int> >L;
	int T;
	scanf("%d",&T);
	int N;
	while(T-->0){
		scanf("%d",&N);
		int i,input,nb;
		char str[5];
		L.clear();
		for(i=0;i<N;i++){
			scanf("%s",str);
			scanf("%d",&input);
			L.push_back(make_pair(str[0],input));
		}
		int j=0;
		it=L.begin();
		while(it!=L.end()){
			nb=it->second/3;
			if(nb!=0){
				lt=L.end();lt--;
				if(lt->first==it->first){
					lt->second+=nb;
				}
				else
					L.push_back(make_pair(it->first,nb));
			}
//			cout<<it->first<<endl;
			if(it->second%3!=0){
				it->second%=3;
				++it;
			}
			else{
				if(it==L.begin()){
					tk=it;
					it++;
					L.erase(tk);
				}
				else{
					tk=it;
					--it;
					L.erase(tk);
					tk=it;tk++;
					if(it->first==tk->first){
						it->second+=tk->second;
						L.erase(tk);	
					}
					else{
						++it;
					}
				}
			}
//			printlist(L);
		}
		long long ans=0;
		for(it=L.begin();it!=L.end();it++){
			ans+=(long long)it->second;
		}
		cout<<ans<<endl;
	}
	return 0;
}
