#include "stdafx.h"
#include<malloc.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
template <class A>
struct stack {
	int i = 0;
	A* buf;

	stack(int initSize=10) {
		maxSize = initSize;
		//buf = new A[initSize];
		buf = (A*)malloc(sizeof(A) * initSize);
	};
	
	void push(A a) {
		if (i+1 > maxSize)
		{
			/*
			A*  p = new A[maxSize + 100];
			memcpy(p, buf, maxSize);
			delete[] buf;
			maxSize += 100;
			*/
			maxSize +=  10;
			buf = (A*)realloc(buf, sizeof(A) * maxSize);
		}
		buf[i++] = a;
	}
	A pop() {
		return buf[--i];
	}
	void show()
	{
		int b=i-1;
		while (b >= 0)
		{
			cout << buf[b]<<"\n";
			b--;
		}
	}
private:
	int maxSize;

};


int main()
{
	stack<int> a;
	for (int i = 1; i <= 11; i++)
	{
		a.push(i);
	}
	a.show();
	a.pop();
	//a.show();
	system("pause");
	/*

	//int myStack_int[256];
	//int myStack_i = 0;

	//入栈操作
	//myStack_int[myStack_i++]=123; //先写值再偏移

	//出栈操作
	//int out = myStack_int[--myStack_i];
	*/
	return 0;
}