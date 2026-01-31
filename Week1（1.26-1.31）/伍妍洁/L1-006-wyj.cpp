#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int a;
	cin >> a;
	//穷举
	int maxlength = 0;
	int maxs = 0;
	for (int s = 2; s <= sqrt(a); s++) {
		int now = s;//现乘积
		int length = 0;
		int begin = s;
		while (a % now == 0 && now <= a) {
			begin++;
			length++;
			now *= begin;
		}
		if (length > maxlength) {
			maxs = s;
			maxlength = length;
		}
	}
	//质数情况
	if (maxs == 0) {
		cout << 1 << endl;
		cout << a;
	}
	else {
		cout << maxlength << endl;
		for (int i = 0; i < maxlength; i++) {
			cout << maxs + i;
			if (i < maxlength - 1)
				cout << "*";
		}
	}
}