#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
string s;
int main() {
  cin>>s;
  if (s[0] == s.back()) {
  	if (s.size()%2 > 0) {
    	cout<<"Second"<<endl;
    } else {
    	cout<<"First"<<endl;
    }
  } else {
  	if (s.size()%2 == 0) {
    	cout<<"Second"<<endl;
    } else {
    	cout<<"First"<<endl;
    }
  }
	return 0;
}
