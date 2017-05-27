/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题17拓展：任意两个正数相加（负数的情况比较麻烦）,代码内存存在泄漏
// 题目：

#include <cstdio>
#include <memory>

/**
      * 两个大数相减，默认没有符号位，且都为正数
      * @param a
      * @param b
      * @return
      */
char** SubTowBigNumbers(char * &number1, char * &number2)
{
	int nLength1 = strlen(number1);
	int nLength2 = strlen(number2);
	int nLength = nLength1 > nLength2 ? nLength1 : nLength2;
	char * number3 = new char[nLength + 1];
	memset(number3, '0', nLength);
	number3[nLength] = '\0';
	int nTakeOver = 0;
	//判断结果符号
	char sign = '+';
	if (nLength1 < nLength2)
		sign = '-';
	else if (nLength1 == nLength2) {
		int i = 0;
		while (i < nLength1 && number1[i] == number2[i])
			i++;
		if (number1[i] < number2[i])
			sign = '-';
	}
	//开始计算结果集
	for (int i = nLength1 - 1, j = nLength2 - 1, k = nLength - 1; k > -1; --k, --j, --i) {
		int sub1, sub2;
		if (i > -1 && j > -1) {
			sub1 = number1[i] - '0';
			sub2 = number2[j] - '0';
		}
		else {
			break;
		}
		int sub;
		if (sign == '-') {
			sub = sub2 - sub1 + nTakeOver;
		}
		else {
			sub = sub1 - sub2 + nTakeOver;
		}
		if (sub < 0) {
			sub += 10;
			nTakeOver = -1;
			number3[k] = '0' + sub;
		}
		else
		{
			number3[k] = '0' + sub;
			nTakeOver = 0;
		}
	}

	return &number3;
}

char **AddTowBigNumbers(char * &number1, char * &number2)
{
	int nLength1 = strlen(number1);
	int nLength2 = strlen(number2);
	int nLength = nLength1 > nLength2 ? nLength1 : nLength2;
	char *number3 = new char[nLength + 2];
	memset(number3, '0', nLength + 1);
	number3[nLength + 1] = '\0';
	int nTakeOver = 0;
	for (int i = nLength1 - 1, j = nLength2 - 1, k = nLength; k > -1; i--, j--, k--)
	{
		int add1, add2;
		if (i > -1)
		{
			add1 = number1[i] - '0';
		}
		else {
			add1 = 0;
		}
		if (j > -1)
		{
			add2 = number2[j] - '0';
		}
		else {
			add2 = 0;
		}

		int sum = add1 + add2 + nTakeOver;
		if (sum >= 10) {
			sum -= 10;
			nTakeOver = 1;
			number3[k] = '0' + sum;
		}
		else
		{
			number3[k] = '0' + abs(sum);
			nTakeOver = 0;
		}
	}

	return &number3;
}

//char **Operator(char *number1, char *number2) {
//	char sign = '+';
//	int nLength1 = strlen(number1);
//	int nLength2 = strlen(number2);
//	int nLength = nLength1 > nLength2 ? nLength1 : nLength2;
//	char res[] = "0";
//	if (number1[0] == '-' && number2[0] == '-')
//	{
//		res[0] = '-';
//		number1[0] = '0';
//		number2[0] = '0';
//		res = strcat(res,*AddTowBigNumbers(number1, number2));
//	}
//}
// ====================测试代码====================
void Test(char *number1, char *number2)
{
	char **res = AddTowBigNumbers(number1, number2);
	printf("%s\n", *res);
	res = SubTowBigNumbers(number1, number2);
	printf("%s\n", *res);
}
void Test1()
{
	char number1[] = "1";
	char number2[] = "2";
	//char number3[] = "3";
	Test(number1, number2);
}

void Test2()
{
	char number1[] = "999999999999999999999999999999999999999";
	char number2[] = "987";
	//char number3[] = "3";
	Test(number1, number2);
}

void Test3()
{
	char number1[] = "352";
	char number2[] = "373";
	//char number3[] = "3";
	Test(number1, number2);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}

