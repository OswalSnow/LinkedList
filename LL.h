#pragma once
#include <iostream>
using namespace std;
#include "Node.h"

class LL{
private:
    Node *head;
    Node *tail;
    int size = 0;

public:
    LL();
    void Print();
    void AddHead(int data);
    void DeleteHead();
    void AddTail(int data);
    void DeleteTail();
    void AddMid(int data, int index);
    void DeleteMid(int index);
    void ReverseList();
    Node FindMid();
};