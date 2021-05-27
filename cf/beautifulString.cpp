#include<bits/stdc++.h>
using namespace std;


int main(){
	string word = "aeeeeeioooou";
	unordered_map<char, int> vowelFreq;
	for(int i=0; i<word.size(); i++){
		vowelFreq[word[i]] += 1;
	}
	for(auto u : vowelFreq){
		cout<<u.first<<" "<<u.second<<endl;
		
	}
	return 0;
}
