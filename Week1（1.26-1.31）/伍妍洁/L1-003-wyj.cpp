#include<iostream>
#include<vector>
using namespace std;
int main() {
	string a;
	cin >> a;
	//10个数字，b[i]记录i出现次数
	vector<int> b(10,0);
	for (int i = 0; i < a.size(); i++) {
		b[a[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (b[i])
			cout << i << ":" << b[i] << endl;
	}
	
}