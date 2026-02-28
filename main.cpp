#include <iostream>
using namespace std;
#include "Node.h"
#include "LL.h"

int main(){
    LL *lista = new LL();

    lista->AddHead(5);
    lista->AddHead(4);
    lista->AddHead(3);
    lista->AddHead(2);
    lista->AddHead(1);

    lista->Print();
    cout<<"\n"<<endl;

    lista->AddMid(40,2);
    lista->Print();
    cout<<"\n"<<endl;

    lista->DeleteMid(2);
    lista->Print();

    return 0;
}