#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    getchar();  // 吸收掉换行符
    string s;
    getline(cin, s);
    int width = ceil(s.size() * 1.0 / n);
    // 建立一个 n 行 col 列的矩阵，初始化为空格
    vector<vector<char>> matrix(n, vector<char>(width, ' '));
    // 填充矩阵：按列填充，从右往左 (j 从 width-1 到 0)
    int k = 0; // 字符串的索引
    for (int j = width - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (k < s.size()) {
                matrix[i][j] = s[k++];
            }
        }
    }
    // 输出矩阵：按行输出
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < width; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}