/*
利用STL的stack，可以利用辗转相除法求的n的m进制数。这里只要是34进制以内都可以使用（因为大写英文字母只有24个）
这个链接有用C语言实现的类似算法，没有使用STL，用的是自写的栈：
    https://github.com/1065077057/data-structure/blob/master/十进制转M进制-栈--C
*/


#include <iostream>
#include <string>
#include <stack>

using namespace std;

void transform(int n,int m){
	stack<int> st;
	if(n < 0){
		n = -n;
		cout << "-";
	}
	while(n){
		st.push(n%m);
		n /= m;
	}
	while(!st.empty()){
		int elem = st.top();
		st.pop();
		if(elem >= 10){
			cout << (char)(elem-10+'A');
		}else{
			cout << elem;
		}
	}
}

int main(){
	int m,n;
	cin >> n >> m;
	transform(n,m);

	system("pause");
	return 0;
}
