
// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。

// leetcode 003

#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int lengthOfLongestSubstring(string s) {
    if (s.empty())
        return 0;
    int ans = 0, j = 0;
    int chr[128] = {0};
    for (int i = 0; i < s.size(); i++) {
        unsigned int index = (unsigned int)s[i];
        if (chr[index] == 0 || chr[index] < j) {
            ans = max(ans, i - j + 1);
        } else {
            j = chr[index];
        }
        chr[index] = i + 1;
    }
    return ans;
}

// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
    int output = lengthOfLongestSubstring(input);
    if(output == expected)
        std::cout << "passed, with input: " << input << std::endl;
    else
        std::cout << "FAILED, with input: " << input << std::endl;
}


void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}