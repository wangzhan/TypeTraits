// TypeTraits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// ������
template<typename T>
struct Iter
{
    typedef T ValueType;
    T *ptr;
    Iter(T *p) : ptr(p) {}

    T& operator * () { return *ptr; }
};

// ��ȡ�������е�����
template<typename I>
struct IterTraits
{
    typedef typename I::ValueType ValueType;
};

// ��ȡ��ָ�������
template<typename T>
struct IterTraits<T*>
{
    typedef T ValueType;
};

template<typename T>
struct IterTraits<const T*>
{
    typedef T ValueType;
};

// ͳһ����������ָ��Ĳ�����������ָ��Ķ���
template<typename I>
typename IterTraits<I>::ValueType func(I p)
{
    return *p;
}


int _tmain(int argc, _TCHAR* argv[])
{
    int *pI = new int();
    func(pI);

    Iter<int> i(pI);
    func(i);

    delete pI;
    pI = NULL;
	return 0;
}

