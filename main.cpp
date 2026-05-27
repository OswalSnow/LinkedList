#include <iostream>
using namespace std;
#include "Node.h"
#include "LL.h"

int main(){
    LL *lista = new LL();

    lista->AddTail(1);
    lista->AddTail(3);
    lista->AddTail(5);
    lista->AddTail(7);

    cout<<"========== Lista Original =========="<<endl;
    lista->Print();
    
    LL *lista2 = lista->CumulativeSum();
    cout<<"========== Lista AccSum =========="<<endl;
    lista2->Print();

    return 0;
}