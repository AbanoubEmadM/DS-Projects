#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsNode
{
public:
    T value;
    clsNode* next;
    clsNode* prev;
};
