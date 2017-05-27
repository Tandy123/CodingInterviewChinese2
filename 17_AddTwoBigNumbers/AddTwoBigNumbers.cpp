/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������17��չ����������������ӣ�����������Ƚ��鷳��,�����ڴ����й©
// ��Ŀ��

#include <cstdio>
#include <memory>

/**
      * �������������Ĭ��û�з���λ���Ҷ�Ϊ����
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
	//�жϽ������
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
	//��ʼ��������
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
// ====================���Դ���====================
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

