#include <bits/stdc++.h>
using namespace std;

// 判断字符串是否为 [1, 1000] 内的正整数
bool isValid(string s) {
    if (s.empty()){
        return false;
    }
    // 检查是否全是数字
    for (char c : s) {
        if (!isdigit(c)){
            return false;
        }
    }
    int num = stoi(s);
    // 题目要求 A, B 在 [1, 1000]
    if (num < 1 || num > 1000){
        return false;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    
    // 找到第一个空格
    int pos = s.find(' ');
    string sa = s.substr(0, pos);
    string sb = s.substr(pos + 1);
    
    bool a_ok = isValid(sa);
    bool b_ok = isValid(sb);
    
    // 打印 A 部分
    if (a_ok){
        cout << sa;
    }
    else{
        cout << "?";
    }
    cout << " + ";
    // 打印 B 部分
    if (b_ok){
        cout << sb;
    }
    else{
        cout << "?";
    }
    cout << " = ";
    // 打印结果部分
    if (a_ok && b_ok) {
        cout << stoi(sa) + stoi(sb);
    }
    else {
        cout << "?";
    }
    cout << endl;
    return 0;
}