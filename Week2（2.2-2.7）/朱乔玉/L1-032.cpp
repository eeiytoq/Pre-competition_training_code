#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    char ch;
    cin >> n >> ch;
    getchar(); // 吸收掉换行符
    string s;
    getline(cin, s);
    int len = s.size();
    if (len >= n){
        // 长度超过或等于 N，截取后 N 位
        cout << s.substr(len - n) << endl;
    } 
    else {
        //长度不足，先输出填充字符，再输出原字符串
        int pad_len = n - len;
        for (int i = 0; i < pad_len; i++) {
            cout << ch;
        }
        cout << s << endl;
    }
    return 0;
}