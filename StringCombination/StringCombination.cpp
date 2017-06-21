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

// ������38-2���ַ��������
// ��Ŀ������һ���ַ�������ӡ�����ַ������ַ���������ϡ����������ַ���abc��
// ���ӡ�����ַ�a��b��c������ϳ����������ַ���a��b��c��ab��ac��bc��abc��
#include <cstdio>
#include <vector>

using namespace std;

void Combination(char *string, int number, vector<char> &result);

void Combination(char *string)
{
	if (string == NULL) {
		return;
	}
	vector<char> result;
	int i, length = strlen(string);
	for (i = 1; i <= length; ++i)
		Combination(string, i, result);
}

void Combination(char *string, int number, vector<char> &result)
{
	//assert(string != NULL);
	if (number == 0)
	{
		static int num = 1;
		printf("��%d�����\t", num++);

		vector<char>::iterator iter = result.begin();
		for (; iter != result.end(); ++iter)
			printf("%c", *iter);
		printf("\n");
		return;
	}
	if (*string == '\0')
		return;
	result.push_back(*string);
	Combination(string + 1, number - 1, result);
	result.pop_back();
	Combination(string + 1, number, result);
}

// ====================���Դ���====================
void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

	Combination(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "abb";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    return 0;
}

