#include <iostream>
using namespace std;
#include "Node.h"
#include "LL.h"

int main(){
    LL *lista = new LL();
    LL *lista2 = new LL();

    lista->AddHead(0);
    lista->AddTail(5);
    lista->AddTail(10);

    lista2->AddHead(1);
    lista2->AddTail(3);
    lista2->AddTail(9);
    
    LL *lista3 = lista->OrderedMerge(lista2);
    lista3->Print();

    return 0;
}