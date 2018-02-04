#ifndef TWODARRAY_H
#define TWODARRAY_H
#include <iostream>

using namespace std;

class twoDArray
{

        friend twoDArray operator<<(ostream& , twoDArray&);
        friend twoDArray operator>>(istream& , twoDArray&);

    public:
        twoDArray(int,int);
        twoDArray();

        twoDArray operator<<(twoDArray&);
        twoDArray operator>>(twoDArray&);

        int operator==(const twoDArray&) const;
        int operator!=(const twoDArray&) const;

        twoDArray& operator=(const twoDArray&);

        int sayiGetir(int,int);

        int **pDizi;

        virtual ~twoDArray();

    private:
        int satir,sutun;


};

#endif // TWODARRAY_H
