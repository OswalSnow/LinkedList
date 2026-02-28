#include <iostream>
using namespace std;
#include "Node.h"
#include "LL.h"

int main(){
    LL *lista = new LL();

    for(int i = 0; i < 5; i++)
        lista->AddTail(i);

    lista->Print();
    cout<<"\n"<<endl;

    cout<<lista->FindMid().data<<endl;

    return 0;
}