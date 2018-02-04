#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int maxOfBook = 20;
class kasa

{
public:
	void kasapara(int miktar);
	int getpara();
	void setpara(int miktar);
	void debit(double Kucret, double Epara);
	kasa(int miktar = 0);
private:
	int para;

};
kasa::kasa(int miktar)
{
	para = 0;
}
void kasa::setpara(int miktar)
{
	para = miktar;
}
int kasa::getpara()
{
	return para;
}
void kasa::kasapara(int miktar)
{
	para += miktar;
	cout << "KASADAKI PARA =  " << para << "  TL\n";

}
void kasa::debit(double Kucret, double Epara)
{
	double ek_para[20];  //alınan para yetersiz ise maksimum 20 kere ekleme yapılabilir.
	int i = 0;
	while (Epara < Kucret)
	{
		cout << "YETERSIZ BAKIYE LUTFEN EKLEME YAPINIZ :";
		cin >> ek_para[i];
		Epara += ek_para[i];
		i++;
	}
	if (Epara >= Kucret)
	{
		cout << "PARA USTU =	" << Epara - Kucret << " TL\n" << "ALLAH BEREKET VERSIN YINE BEKLERIZ.\n";
		kasapara(Kucret);
	}

}
class yazar
{
public:
	
	string getnameyazar();
	void setyazar(string yname);
	void baslikyaz();
	yazar(string yname = "");
	void yazarKitapSet(ifstream& inData);
private:
	string name;


};
void yazar::yazarKitapSet(ifstream& inData)
{

	inData >> name;

}

void yazar::baslikyaz()
{
	cout << left;
	cout << setw(4) << "NO" << setw(25) << "  YAZAR ISMI" << "\t" << setw(20) << "KITABIN ISMI" << "\t" << setw(10) << "KITABIN UCRETI" << endl;
	cout << setw(4) << "---" << setw(25) << " --------------" << "\t" << setw(20) << "-------------" << "\t" << "--------------" << endl;
}
void yazar::setyazar(string yname)
{
	name = yname;

}
yazar::yazar(string yname)
{
	name = yname;

}
string yazar::getnameyazar()
{
	return name;
}
class kitap : public yazar, kasa
{
public:
	void yazdir(kitap kitapList[], kitap kitapList2[], int toplam_kitap);
	void kitapAra(kitap kitapList[], kitap kitapList2[], int toplam_kitap, string aranan);
	void kitapSatis(kitap kitapList[], int toplam_kitap);
	void kitapUcret(ifstream& inData);
	void ucretSet(ifstream& inData);
private:
		double kitap_ucret;
};
void kitap::yazdir(kitap kitapList[], kitap kitapList2[], int toplam_kitap)
{
	for (int i = 0; i < toplam_kitap; i++)
	{
		cout << i + 1 << setw(3) << "-";
		cout <<setw(28)<< kitapList[i].getnameyazar();
		cout <<setw(30)<< kitapList2[i].getnameyazar();
		cout << kitapList[i].kitap_ucret<<endl;

	}

}
void kitap::ucretSet(ifstream& inData)
{
	inData >> kitap_ucret;
}
void kitap::kitapAra(kitap kitapList[], kitap kitapList2[], int toplam_kitap, string aranan)
{
	int k,p,q,j = 0;
	
	
	
	for (int i = 0; i < toplam_kitap; i++)
	{	
		p = kitapList[i].getnameyazar().find(aranan);
		q = kitapList2[i].getnameyazar().find(aranan);

		if (p>=0 || q>=0)
		{
			
			if (j == 0)
			{
				cout << "\n---------------------------ARADIGINIZ KITAP BULUNDU ----------------------------\n";
				baslikyaz(); 
				j++;
			}
			
			cout << i + 1 << setw(3) << "-";
			cout << setw(28) << kitapList[i].getnameyazar();
			cout << setw(30) << kitapList2[i].getnameyazar();
			cout << kitapList[i].kitap_ucret << endl;
		}
	
	}

	cout << "\nKITABI SATIN ALMAK ISTERMISINIZ EVET ICIN 1\nHAYIR ICIN 2\n";
	cin >> k;
	switch (k)
	{
	case 1:
		kitapSatis(kitapList, toplam_kitap);
			break;
	case 2:
		cout << "IYI GUNLER......\n";
		break;
	
	
	default:
		cout << "YANLIS TERCIH YAPTINIZ!!! PROGRAM TEKRAR BASLATILIYOR....\n";
		break;
	}



}
void kitap::kitapSatis(kitap kitapList[], int toplam_kitap)
{


	int num;
	double paraa, i, b;
	cout << "LUTFEN SATIN ALMAK ISTEDIGINIZ KITABIN NUMARASINI GIRINIZ :";
	cin >> num;
	if (num > 0 && num <= toplam_kitap)
	{
		
		cout << "SATIN ALMAK ISTEDIGINIZ KITABIN UCRETI : ";
		b = kitapList[num - 1].kitap_ucret;
		cout << b << " TL"; cout << endl;
		cout << "LUTFEN ODEME YAPINIZ : ";
		cin >> paraa;

		debit(b, paraa);
	}
	else
		cout << "YANLIS TERCIH PROGRAM TEKRAR BASLATILIYOR.... \n";
	
}
void kitap::kitapUcret(ifstream& inData)
{
	int i = 0;

	inData >> kitap_ucret;
	cout << kitap_ucret << "\n";


}
void set(ifstream& inData, kitap kitapList[], kitap kitapList2[], int elde_kitap)
{
	for (int i = 0; i < elde_kitap; i++)
	{

		kitapList[i].yazarKitapSet(inData);
		kitapList2[i].yazarKitapSet(inData);
		kitapList[i].ucretSet(inData);
	
	}
	
}
int main()
{

	int i=0, elde_kitap;
	ifstream inData;
	kitap kitapList[maxOfBook];
	kitap kitapList2[maxOfBook];
	kitap book;
	string aranan;
	
	inData.open("kitaplik.txt");
	inData >> elde_kitap;
	set(inData, kitapList, kitapList2, elde_kitap);


	while (i != 9)
	{
		cout << "KITAPLARIN HEPSINI GORMEK ICIN 1\nARAMA YAPMAK ICIN 2\nCIKIS ICIN 9 : " << endl;
		cin >> i;
	
	switch (i)
		{
		case 1:
			book.baslikyaz();
			book.yazdir(kitapList, kitapList2, elde_kitap);
			book.kitapSatis(kitapList, elde_kitap);
			cin.get();
			break;

		case 2:

			cout << "ARAMAK ISTEDIGINIZ KITABIN ADINI VEYA YAZARI GIRINIZ : ";
			cin >> aranan;
			book.kitapAra(kitapList, kitapList2, elde_kitap, aranan);
			cin.get();
			break;
		default:
			cout << "YANLIS TERCIH YAPTINIZ PROGRAM TEKRAR BASLATILIYOR....\n";
			break;
		}
	}
	inData.close();
	cin.get();

}

