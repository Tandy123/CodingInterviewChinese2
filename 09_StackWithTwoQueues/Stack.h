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

// ������9��չ������������ʵ��ջ
// ��Ŀ������������ʵ��һ��ջ��ջ���������£���ʵ��������������appendTail
// ��deleteTail���ֱ������ջβ�����������ջβ��ɾ�����Ĺ��ܡ�

#pragma once
#include <queue>
#include <exception>

using namespace std;

template <typename T> class CStack
{
public:
	CStack(void);
	~CStack(void);

	// �ڶ���ĩβ���һ�����
	void appendTail(const T& node);

	// ɾ�����е�ͷ���
	T deleteTail();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template <typename T> CStack<T>::CStack(void)
{
}

template <typename T> CStack<T>::~CStack(void)
{
}

template<typename T> void CStack<T>::appendTail(const T& element)
{
	if (queue2.size() == 0)
	{
		queue1.push(element);
	}
	else
	{
		queue2.push(element);
	}
}

template<typename T> T CStack<T>::deleteTail()
{
	T tail;
	if (queue2.size() == 0)
	{
		while (queue1.size()>1)
		{
			T& data = queue1.front();
			queue1.pop();
			queue2.push(data);
		}
		if (queue1.size() == 0)
			throw new exception("stack is empty");

		tail = queue1.front();
		queue1.pop();
	}
	else if (queue1.size() == 0)
	{
		while (queue2.size()>1)
		{
			T& data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}
		if (queue2.size() == 0)
			throw new exception("stack is empty");

		tail = queue2.front();
		queue2.pop();
	}
	return tail;
}
