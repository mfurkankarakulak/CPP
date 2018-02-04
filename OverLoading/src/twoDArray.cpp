#include "twoDArray.h"
#include <iomanip>


twoDArray::twoDArray(int a,int b)
{

    satir=a;
    sutun=b;
    pDizi=new int*[satir];

    for(int i;i<satir;i++)
        pDizi[i]=new int[sutun];


     for(int k=0;k<satir;k++)
        for(int j=0;j<sutun;j++)
        {
            pDizi[k][j]=0;

        }

}
twoDArray::twoDArray()
{
    satir=3;
    sutun=3;

    pDizi=new int*[3];

    for(int i;i<3;i++)
        pDizi[i]=new int[3];

    for(int k=0;k<3;k++){
        for(int j=0;j<3;j++)
            pDizi[k][j]=0;
}

}
twoDArray operator<<(ostream& cikis ,twoDArray& yaz)
{
    int temp;
    for(int x=0;x<yaz.satir;x++)
    {
        for(int y=0;y<yaz.sutun;y++)
        {
            temp=yaz.pDizi[x][y];
            cikis<<setw(6)<<temp;
        }
        cikis<<endl;
    }


}
twoDArray operator>>(istream& giris ,twoDArray& oku)
{

    int temp=0;
      for(int x=0;x<oku.satir;x++)
        for(int y=0;y<oku.sutun;y++)
        {
            cin>>temp;
            oku.pDizi[x][y]=temp;
        }




}
int twoDArray::operator==(const twoDArray& sagEleman)const
{
    if(this->satir==sagEleman.satir && this->sutun==sagEleman.sutun)
    {
        for(int x=0;x<sagEleman.satir;x++)
            for(int y=0;y<sagEleman.sutun;y++)
                if(this->pDizi[x][y]!=sagEleman.pDizi[x][y])
                    return 0;
    }
    else return 0;

    return 1;

}
int twoDArray::operator!=(const twoDArray& sagEleman)const
{
    if(this->satir==sagEleman.satir && this->sutun==sagEleman.sutun)
    {
        for(int x=0;x<sagEleman.satir;x++)
            for(int y=0;y<sagEleman.sutun;y++)
                if(this->pDizi[x][y]!=sagEleman.pDizi[x][y])
                    return 1;
    }
    else return 1;

    return 0;

}
twoDArray& twoDArray::operator=(const twoDArray& sagEleman)
{
    if(this->satir==sagEleman.satir && this->sutun==sagEleman.sutun)
    {
         for(int x=0;x<sagEleman.satir;x++)
            for(int y=0;y<sagEleman.sutun;y++)
                this->pDizi[x][y]=sagEleman.pDizi[x][y];
        cout<<endl<<"Matris Kopyalandi"<<endl;
    }
    else
    {

        this->pDizi=new int*[sagEleman.satir];

        for(int i;i<sagEleman.satir;i++)
            this->pDizi[i]=new int[sagEleman.sutun];

         for(int k=0;k<sagEleman.satir;k++)
            for(int j=0;j<sagEleman.sutun;j++)
                this->pDizi[k][j]=sagEleman.pDizi[k][j];
        this->satir=sagEleman.satir;
        this->sutun=sagEleman.sutun;
          cout<<endl<<"Matris Kopyalandi"<<endl;
    }

}
int twoDArray::sayiGetir(int x,int y)
{
    int sonuc;
    sonuc=pDizi[x-1][y-1];
    return sonuc;
}
twoDArray::~twoDArray()
{

}

