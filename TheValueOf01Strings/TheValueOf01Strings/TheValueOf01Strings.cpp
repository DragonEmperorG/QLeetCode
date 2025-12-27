// TheValueOf01Strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        //
        int head_0_index = 0;
        int tail_0_index = 0;
        int num_0_counter = 0;
        int head_1_index = 0;
        int tail_1_index = 0;
        int num_1_counter = 0;
        vector<int> input_vector;
        int x = b;
        int y = 0;
        // STEP1: 遍历输入的01串，找到最长的连续子串
        for (int i = 0; i < a; i++) {
            y = x % 10;
            x = x / 10;

            if (y == 0) {
                num_0_counter++;
                head_0_index = a - i;
                if (tail_0_index == 0) {
                    tail_0_index = a - i;
                }
            }
            else {
                num_1_counter++;
                head_1_index = a - i;
                if (tail_1_index == 0) {
                    tail_1_index = a - i;
                }
            }
        }

        long long max_value = a;
        if (num_0_counter > num_1_counter) {
            if (tail_0_index == a) {
                max_value = head_0_index * (head_0_index - 1) / 2
                    + (1 + num_0_counter) * num_0_counter / 2;
            }
            else {
                max_value = head_0_index * (head_0_index - 1) / 2
                    + (1 + num_0_counter) * num_0_counter / 2
                    + (1 + a - tail_0_index) * (a - tail_0_index) / 2;
            }
        }
        else {
            if (tail_1_index == a) {
                max_value = head_1_index * (head_1_index - 1) / 2
                    + (1 + num_1_counter) * num_1_counter / 2;
            }
            else {
                max_value = head_1_index * (head_1_index - 1) / 2
                    + (1 + num_1_counter) * num_1_counter / 2
                    + (1 + a - tail_1_index) * (a - tail_1_index) / 2;;
            }
        }

        // 提交结果
        printf("%lld", max_value);
    }
}
// 64 位输出请用 printf("%lld")
