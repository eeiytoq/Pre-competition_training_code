#include<iostream>
using namespace std;
int main() {
	int n;
	int num = 1;
	cin >> n;
	//¡Á2
	for (int i = 0; i < n; i++)
		num *= 2;
	cout << "2^"<<n<<" = " << num;
	return 0;
}
