#include <iostream>
#include "twoDArray.h"

using namespace std;

int main()
{
    twoDArray dizi2(2,4);
    cout<<"1.Matrisi Giriniz:"<<endl;
    cin>>dizi2;
    cout<<dizi2;
    twoDArray dizi3;
    cout<<"2.Matrisi Giriniz:"<<endl;
    cin>>dizi3;
    cout<<dizi3;

    if(dizi2==dizi3)
    {
        cout<<"Matrisler eşit.";
    }
     if(dizi2!=dizi3)
    {
        cout<<"Matrisler eşit değil.";
        dizi2=dizi3;
        cout<<dizi2;
    }

    if(dizi2==dizi3)
    {
        cout<<"Matrisler eşit.";
    }

    return 0;
}
