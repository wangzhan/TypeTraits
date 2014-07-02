// TypeTraits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// 迭代器
template<typename T>
struct Iter
{
    typedef T ValueType;
    T *ptr;
    Iter(T *p) : ptr(p) {}

    T& operator * () { return *ptr; }
};

// 萃取迭代器中的类型
template<typename I>
struct IterTraits
{
    typedef typename I::ValueType ValueType;
};

// 萃取裸指针的类型
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

// 统一迭代器和裸指针的参数，返回其指向的对象
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

