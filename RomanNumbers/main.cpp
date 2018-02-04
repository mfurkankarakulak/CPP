#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;

void girisEkrani(); 		    	 //+
void ArapRoma(int);				    //+
int kontrolRoma(string);		   //+
void RomaArap(string);			  //+
void rToplama(string,string); 	 //+
void rCikarma(string,string);	//+
void duzenliYaz(string);	   //+

int main(int argc, char** argv) {
	int islem,girilenSayi;
	string girilenRoma,rRakam1,rRakam2;
	system("Color F0");
	girisEkrani();
	
	cin>>islem;
	while(islem!=9){
		switch(islem){
			case 0:
				cout<<"0 ile 4000 arasi bir sayi giriniz:";
				cin>>girilenSayi;
				if(girilenSayi>0 and girilenSayi<4000)
					ArapRoma(girilenSayi);
				else{
					cout<<"Roma rakamlari ile gosterilebilecek en buyuk sayi 3999'dur."<<endl;
					}		
				break;
			case 1:
				cout<<"Bir roma rakami giriniz:";
				cin>>girilenRoma;
				if(kontrolRoma(girilenRoma)){
					RomaArap(girilenRoma);
				}
				else{
					cout<<"Yanlis Format"<<endl;
					}	
				break;
			case 2:	
				cout<<"Birinci roma rakamini giriniz:";
				cin>>rRakam1;
				cout<<"Ikinci roma rakamini giriniz:";
				cin>>rRakam2;
				if(kontrolRoma(rRakam1) and kontrolRoma(rRakam2) ){
					rToplama(rRakam1,rRakam2);
				}
				else{
					cout<<"Yanlis Format"<<endl;
					}	
				break;
			case 3:	
				cout<<"Birinci roma rakamini giriniz:";
				cin>>rRakam1;
				cout<<"Ikinci roma rakamini giriniz:";
				cin>>rRakam2;
				if(kontrolRoma(rRakam1) and kontrolRoma(rRakam2) ){
					rCikarma(rRakam1,rRakam2);
				}
				else{
					cout<<"Yanlis Format"<<endl;
					}	
				break;		
				
				
			default:				
            cout<<"Yanlis secim yaptiniz..."<<endl;
            break;	
		}
	girisEkrani();
	cin>>islem;	
	}
	
	return 0;
}
void girisEkrani(){
	cout<<"[0] Arap --> Roma"<<endl;
	cout<<"[1] Roma --> Arap"<<endl;
	cout<<"[2] Roma + Roma"<<endl;
	cout<<"[3] Roma - Roma"<<endl;
	cout<<"[9] Exit"<<endl;
}
void ArapRoma(int x){
	int basamaklar[4],i;
	string R1;
	for(int i=0;x>0;i++){
		basamaklar[i]=x%10;
		x-=basamaklar[i];
		x/=10;
		}
	cout<<basamaklar[3]<<"x1000 + "<<basamaklar[2]<<"x100 + "<<basamaklar[1]<<"x10 + "<<basamaklar[0]<<"x1"<<endl;
			
	for(i=0;i<basamaklar[3];i++){
		R1+="M";
	}
	switch(basamaklar[2]){
		case 0: case 1: case 2: case 3:
			for(i=0;i<basamaklar[2];i++)
				R1+="C";
			break;
		case 4:
			R1+="CD";
			break;
		case 5:
			R1+="D";
			break;	
		case 6: case 7: case 8:
			R1+="D";
			for(i=0;i<basamaklar[2]-5;i++)
				R1+="C";
			break;
		case 9:
			R1+="CM";
			break;
	}
	switch(basamaklar[1]){
		case 0: case 1: case 2: case 3:
			for(i=0;i<basamaklar[1];i++)
				R1+="X";
			break;
		case 4:
			R1+="XL";
			break;
		case 5:
			R1+="L";
			break;	
		case 6: case 7: case 8:
			R1+="L";
			for(i=0;i<basamaklar[1]-5;i++)
				R1+="X";
			break;
		case 9:
			R1+="XC";
			break;
	}
	
	switch(basamaklar[0]){
		case 0: case 1: case 2: case 3:
			for(i=0;i<basamaklar[0];i++)
				R1+="I";
			break;
		case 4:
			R1+="IV";
			break;
		case 5:
			R1+="V";
			break;	
		case 6: case 7: case 8:
			R1+="V";
			for(i=0;i<basamaklar[0]-5;i++)
				R1+="I";
			break;
		case 9:
			R1+="IX";
			break;
	}
	cout<<"Roma rakami karsiligi :"<<R1<<endl;	
}
int kontrolRoma(string gelen){
	int say=0,i=0,m=0,cm=0,d=0,cd=0,c=0,xc=0,l=0,xl=0,x=0,ix=0,v=0,iv=0,ii=0;
	while(gelen[i]!='\0')
		switch(gelen[i]){
			case 'M':case 'D':case 'C':case 'L':case 'X':case 'V':case'I':i++;break;
			default:return 0; break;
		}
		i=0;say=0;
	while(gelen[i]!='\0'){
		switch(gelen[i]){
			case 'M':
				for(say=0;say<=i;say++)
					switch(gelen[say]){
						case 'M':break;
						case 'C':
							cm++;
							if(cm>1)
								return 0;
							break;
						case 'I':case 'V':case 'X':case 'L':case 'D':return 0;break;
						default:return 0; break;
					}
					
				m++;
				if(m>3)
					return 0;
				break;
			case 'D':	
				for(say=0;say<=i;say++)
					switch(gelen[say]){
						case 'M':case 'D':break;
						case 'C':
							cd++;
							if(cd>1)
								return 0;
							break;
						case 'I':case 'V':case 'X':case 'L':return 0;break;
					}
				d++;
				if(d>1)
					return 0;
				break;
			case 'C':
				for(say=0;say<=i;say++)
					switch(gelen[say]){		
							case 'M':case 'D':case 'C':break;
							case 'X':
								xc++;
								if(xc>1)
									return 0;
								break;
							case 'I':case 'V':case 'L':return 0;break;
							
					}
				c++;
				if(c>3)
					return 0;
				break;
			case 'L':
				for(say=0;say<=i;say++)
					switch(gelen[say]){
						case 'M':case 'D':case 'C':case 'L':break;
						case 'X':
							xl++;
							if(xl>1)
								return 0;
							break;
						case 'I':case 'V':return 0;break;
					}
				l++;
				if(l>1)
					return 0;
				break;
			case 'X':
				for(say=0;say<=i;say++)
					switch(gelen[say]){		
							case 'M':case 'D':case 'C':case 'L':case 'X':break;
							case 'I':
								ix++;
								if(ix>1)
									return 0;
								break;
							case 'V':return 0;break;
							
					}
				x++;
				if(x>3)
					return 0;
				break;	
			case 'V':
				for(say=0;say<=i;say++)
					switch(gelen[say]){
						case 'M':case 'D':case 'C':case 'L':case 'X':case 'V':break;
						case 'I':
							iv++;
							if(iv>1)
								return 0;
							break;
					}
				v++;
				if(v>1)
					return 0;
				break;	
			case 'I':	
				ii++;
				if(ii>3)
					return 0;
				break;	
		}
		i++;
	}
	
	return 1;

}
void RomaArap(string gelen){
	int toplam=0,i=0;
	
	while(gelen[i]!='\0'){
			switch(gelen[i]){
				case 'M':
					toplam+=1000;
					i++;
					break;
				case 'D':
					toplam+=500;
					i++;
					break;
				case 'C':
					if(gelen[i+1]!='M' and gelen[i+1]!='D')
						toplam+=100;
					else
						toplam-=100;
					i++;
					break;
				case 'L':
					toplam+=50;
					i++;
					break;
				case 'X':
					if(gelen[i+1]!='C' and gelen[i+1]!='L')
						toplam+=10;
					else
						toplam-=10;
					i++;
					break;
				case 'V':
					toplam+=5;
					i++;
					break;
				case 'I':
					if(gelen[i+1]!='X' and gelen[i+1]!='V')
						toplam+=1;
					else
						toplam-=1;
					i++;
					break;
			}
}

cout<<"Normal rakam karsiligi:"<<toplam<<endl;
}
void rToplama(string R1,string R2){
	int i=0,j,k,konum;
	char silnecek;
	string toplam,negatifler;
	int sonuc=0;
	bool durum=0;
	while(R1[i]!='\0'){
			switch(R1[i]){
				case 'M':
					toplam+="+M";
					sonuc+=1000;
					break;
				case 'D':
					toplam+="+D";
					sonuc+=500;
					break;
				case 'C':
					if(R1[i+1]!='D' and R1[i+1]!='M'){
					
						toplam+="+C";
						sonuc+=100;
					}
					else{
						toplam+="-C";
						sonuc-=100;
						}
					break;
				case 'L':
					toplam+="+L";
					sonuc+=50;
					break;
				case 'X':
					if(R1[i+1]!='L' and R1[i+1]!='C'){
						toplam+="+X";
						sonuc+=10;
					}
					else{
						toplam+="-X";
						sonuc-=10;
					}
					break;
				case 'V':
					toplam+="+V";
					sonuc+=5;
					break;
				case 'I':
					if(R1[i+1]!='X' and R1[i+1]!='V'){
						toplam+="+I";
						sonuc+=1;
					}
					else{
						toplam+="-I";
						sonuc-=1;
					}
					break;
			}
		i++;
	}
	i=0;
	while(R2[i]!='\0'){
	
			switch(R2[i]){
				case 'M':
					toplam+="+M";
					sonuc+=1000;
					break;
				case 'D':
					toplam+="+D";
					sonuc+=500;
					break;
				case 'C':
					if(R2[i+1]!='D' and R2[i+1]!='M'){
						toplam+="+C";
						sonuc+=100;
					}
					else{
						toplam+="-C";
						sonuc-=100;
					}
					break;
				case 'L':
					toplam+="+L";
					sonuc+=50;
					break;
				case 'X':
					if(R2[i+1]!='L' and R2[i+1]!='C'){
						toplam+="+X";
						sonuc+=10;
					}
					else{
						toplam+="-X";
						sonuc-=10;
					}
					break;
				case 'V':
					toplam+="+V";
					sonuc+=5;
					break;
				case 'I':
					if(R2[i+1]!='X' and R2[i+1]!='V'){
						toplam+="+I";
						sonuc+=1;
					}
					else{
						toplam+="-I";
						sonuc-=1;
					}
					break;
			}
		i++;		
	}

	cout<<endl<<"R1+R2="<<toplam<<"="<<sonuc<<endl<<endl;
	i=0;
	while(toplam[i]!='\0'){
		if(toplam[i]=='-'){
			negatifler+=toplam.substr(i,2);	
			toplam.erase(i,2);
			i--;
		}
		i++;
	}
	cout<<"NEGTIFLER="<<negatifler<<endl;	
		
	while(negatifler[0]!='\0'){
		durum=0;
		for(i=0;i<=toplam.length();i++){
			if(toplam[i]==negatifler[1]){
				negatifler.erase(0,2);
				toplam.erase(i-1,2);
				durum=1;
				i=toplam.length();
			}
			
		}
		if(!durum){
			switch(negatifler[1]){
				case 'C':	
					konum=toplam.find("D",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+C+C+C+C+C";	
					}else if(toplam.find("M",0)!=-1){
						konum=toplam.find("M",0);
						toplam.erase(konum-1,2);
						toplam+="+C+C+C+C+C+D";
					}else{
						cout<<"Girilen degerlerde hata var.";
						exit(0);
					}		
					break;
				case 'X':
					konum=toplam.find("L",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+X+X+X+X+X";	
					}else if(toplam.find("C",0)!=-1){
						konum=toplam.find("C",0);
						toplam.erase(konum-1,2);
						toplam+="+X+X+X+X+X+L";
					}else if(toplam.find("D",0)!=-1){
						konum=toplam.find("D",0);
						toplam.erase(konum-1,2);
						toplam+="+X+X+X+X+X+L+C+C+C+C";
					}else{
						cout<<"Girilen degerlerde hata var.";
						exit(0);
					}		
					break;
				case 'I':
					konum=toplam.find("V",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I";	
					}else if(toplam.find("X",0)!=-1){
						konum=toplam.find("X",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V";
					}else if(toplam.find("L",0)!=-1){
						konum=toplam.find("L",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V+X+X+X+X";
					}else if(toplam.find("C",0)!=-1){
						konum=toplam.find("C",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V+X+X+X+X+L";
					}else if(toplam.find("D",0)!=-1){
						konum=toplam.find("D",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V+X+X+X+X+L+C+C+C+C";
					}else if(toplam.find("M",0)!=-1){
						konum=toplam.find("M",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V+X+X+X+X+L+C+C+C+C+D";
					}else{
						cout<<"Girilen deGerlerde hata var.";
						exit(0);
					}		
					break;
		}
		

}	
}
		cout<<endl<<"R1+R2="<<toplam<<"="<<sonuc<<endl<<endl;
		duzenliYaz(toplam);
}
void rCikarma(string R1,string R2){
	int i=0,konum,sonuc=0;
	char a;
	bool durum;
	string toplam,negatifler;
	while(R1[i]!='\0'){	
			switch(R1[i]){
				case 'M':
					toplam+="+M";
					sonuc+=1000;
					break;
				case 'D':
					toplam+="+D";
					sonuc+=500;
					break;
				case 'C':
					if(R1[i+1]!='D' and R1[i+1]!='M'){
						toplam+="+C";
						sonuc+=100;
					}
					else{
						toplam+="-C";
						sonuc-=100;
					}
					break;
				case 'L':
					toplam+="+L";
					sonuc+=50;
					break;
				case 'X':
					if(R1[i+1]!='L' and R1[i+1]!='C'){
						toplam+="+X";
						sonuc+=10;
					}
					else{
						toplam+="-X";
						sonuc-=10;
					}
					break;
				case 'V':
					toplam+="+V";
					sonuc+=5;
					break;
				case 'I':
					if(R1[i+1]!='X' and R1[i+1]!='V'){
						toplam+="+I";
						sonuc+=1;
					}
					else{
						toplam+="-I";
						sonuc-=1;
					}
					break;
			}
		i++;
	}
	i=0;
	while(R2[i]!='\0'){	
			switch(R2[i]){
				case 'M':
					toplam+="-M";
					sonuc-=1000;
					break;
				case 'D':
					toplam+="-D";
					sonuc-=500;
					break;
				case 'C':
					if(R2[i+1]!='D' and R2[i+1]!='M'){
						toplam+="-C";
						sonuc-=100;
					}
					else{
						toplam+="+C";
						sonuc+=100;
					}
					break;
				case 'L':
					toplam+="-L";
					sonuc-=50;
					break;
				case 'X':
					if(R2[i+1]!='L' and R2[i+1]!='C'){
						toplam+="-X";
						sonuc-=10;
					}
					else{
						toplam+="+X";
						sonuc+=10;
					}
					break;
				case 'V':
					toplam+="-V";
					sonuc-=5;
					break;
				case 'I':
					if(R2[i+1]!='X' and R2[i+1]!='V'){
						toplam+="-I";
						sonuc-=1;
					}
					else{
						toplam+="+I";
						sonuc+=1;
					}
					break;
			}
		i++;		
	}
	cout<<endl<<"R1-R2="<<toplam<<endl;
	i=0;
	while(toplam[i]!='\0'){
		if(toplam[i]=='-'){
			negatifler+=toplam.substr(i,2);	
			toplam.erase(i,2);
			i--;
		}
		i++;		
	}
	
	
		while(negatifler[0]!='\0'){
		durum=0;
		for(i=0;i<=toplam.length();i++){
			if(toplam[i]==negatifler[1]){
				negatifler.erase(0,2);
				toplam.erase(i-1,2);
				durum=1;
				i=toplam.length();
			}
		}	
		if(!durum){
			switch(negatifler[1]){
				case 'D':
					konum=toplam.find("M",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+D+D";
					}
					else{
						cout<<"Cikarma islemi yapýlamaz.";
					}
				case 'C':	
					konum=toplam.find("D",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+C+C+C+C+C";	
					}else if(toplam.find("M",0)!=-1){
						konum=toplam.find("M",0);
						toplam.erase(konum-1,2);
						toplam+="+C+C+C+C+C+D";
					}else{
						cout<<"Girilen deðerlerde hata var.";
						exit(0);
					}		
					break;
				case 'L':
					konum=toplam.find("C",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+L+L";
					}else if(toplam.find("D",0)!=-1){
						konum=toplam.find("D",0);
						toplam.erase(konum-1,2);
						toplam+="+L+L+C+C+C+C";	
					}else if(toplam.find("M",0)!=-1){
						konum=toplam.find("M",0);
						toplam.erase(konum-1,2);
						toplam+="+L+L+C+C+C+C+D";
					}else{
						cout<<"Girilen deðerlerde hata var.";
						exit(0);
					}
						
				case 'X':
					konum=toplam.find("L",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+X+X+X+X+X";	
					}else if(toplam.find("C",0)!=-1){
						konum=toplam.find("C",0);
						toplam.erase(konum-1,2);
						toplam+="+X+X+X+X+X+L";
					}else if(toplam.find("D",0)!=-1){
						konum=toplam.find("D",0);
						toplam.erase(konum-1,2);
						toplam+="+X+X+X+X+X+L+C+C+C+C";
					}else if(toplam.find("M",0)!=-1){
						konum=toplam.find("M",0);
						toplam.erase(konum-1,2);
						toplam+="+X+X+X+X+X+L+C+C+C+C+D";
					}else{
						cout<<"Girilen deðerlerde hata var.";
						exit(0);
					}		
					break;
				case 'V':
					konum=toplam.find("X",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+V+V";
					}else if(toplam.find("L",0)!=-1){
						konum=toplam.find("L",0);
						toplam.erase(konum-1,2);
						toplam+="+V+V+X+X+X+X";
					}else if(toplam.find("C",0)!=-1){
						konum=toplam.find("C",0);
						toplam.erase(konum-1,2);
						toplam+="+V+V+X+X+X+X+L";
					}else if(toplam.find("D",0)!=-1){
						konum=toplam.find("D",0);
						toplam.erase(konum-1,2);
						toplam+="+V+V+X+X+X+X+L+C+C+C+C";
					}else if(toplam.find("M",0)!=-1){
						konum=toplam.find("M",0);
						toplam.erase(konum-1,2);
						toplam+="+V+V+X+X+X+X+L+C+C+C+C+D";
					}else{
						cout<<"Girilen deðerlerde hata var.";
						exit(0);
					}		
					break;
				case 'I':
					konum=toplam.find("V",0);
					if(konum!=-1){
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I";	
					}else if(toplam.find("X",0)!=-1){
						konum=toplam.find("X",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V";
					}else if(toplam.find("L",0)!=-1){
						konum=toplam.find("L",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V+X+X+X+X";
					}else if(toplam.find("C",0)!=-1){
						konum=toplam.find("C",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V+X+X+X+X+L";
					}else if(toplam.find("D",0)!=-1){
						konum=toplam.find("D",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V+X+X+X+X+L+C+C+C+C";
					}else if(toplam.find("M",0)!=-1){
						konum=toplam.find("M",0);
						toplam.erase(konum-1,2);
						toplam+="+I+I+I+I+I+V+X+X+X+X+L+C+C+C+C+D";
					}else{
						cout<<"Girilen deðerlerde hata var.";
						exit(0);
					}		
					break;
		}
		

	}	
}
	cout<<endl<<"R1-R2="<<toplam<<"="<<sonuc<<endl<<endl;
	duzenliYaz(toplam);
}
void duzenliYaz(string gelen){
	int i=0,say=0;
	string yeni;
	//iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
	while(gelen[i]!='\0'){
		if(gelen[i]=='I'){
			say++;
		}
		i++;
	}
	switch(say){
		case 0:break;
		case 1:yeni="+I"+yeni;break;
		case 2:yeni="+I+I"+yeni;break;
		case 3:yeni="+I+I+I"+yeni;break;
		case 4:yeni="-I+V"+yeni;break;
		case 5:yeni="+V"+yeni;break;
		case 6:yeni="+V+I"+yeni;break;
		case 7 :yeni="+V+I+I"+yeni;break;
		case 8 :yeni="+V+I+I+I"+yeni;break;
		case 9 :yeni="-I+X"+yeni;break;
	}
	
	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
	say=0;
	i=0;
	while(gelen[i]!='\0'){
		if(gelen[i]=='V'){
			say++;
		}
		i++;
	}
	switch(say){
		case 0:break;
		case 1:yeni="+V"+yeni;break;
		case 2:yeni="+X"+yeni;break;
		case 3:yeni="+V+X"+yeni;break;
		case 4:yeni="+X+X"+yeni;break;
		case 5:yeni="+V+X+X"+yeni;break;
		case 6:yeni="+X+X+X"+yeni;break;
	}
	//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	say=0;
	i=0;
	while(gelen[i]!='\0'){
		if(gelen[i]=='X'){
			say++;
		}
		i++;
	}
	switch(say){
		case 0:break;
		case 1:yeni="+X"+yeni;break;
		case 2:yeni="+X+X"+yeni;break;
		case 3:yeni="+X+X+X"+yeni;break;
		case 4:yeni="-X+L"+yeni;break;
		case 5:yeni="+L"+yeni;break;
		case 6:yeni="+L+X"+yeni;break;
		case 7:yeni="+L+X+X"+yeni;break;
		case 8:yeni="+L+X+X+X"+yeni;break;
		case 9:yeni="-X+C"+yeni;break;
	}
	//llllllllllllllllllllllllllllllllllllllllllll
	say=0;
	i=0;
	
	while(gelen[i]!='\0'){
		if(gelen[i]=='L'){
			say++;
		}
		i++;
	}
	switch(say){
		case 0:break;
		case 1:yeni="+L"+yeni;break;
		case 2:yeni="+C"+yeni;break;
		case 3:yeni="+C+L"+yeni;break;
		case 4:yeni="+C+C"+yeni;break;
		case 5:yeni="+C+C+L"+yeni;break;
		case 6:yeni="+C+C+C"+yeni;break;
	}
	//cccccccccccccccccccccccccccccccccccccccccccccc
	say=0;
	i=0;
	
	while(gelen[i]!='\0'){
		if(gelen[i]=='C'){
			say++;
		}
		i++;
	}
	switch(say){
		case 0:break;
		case 1:yeni="+C"+yeni;break;
		case 2:yeni="+C+C"+yeni;break;
		case 3:yeni="+C+C+C"+yeni;break;
		case 4:yeni="-C+D"+yeni;break;
		case 5:yeni="+D"+yeni;break;
		case 6:yeni="+D+C"+yeni;break;
		case 7:yeni="+D+C+C"+yeni;break;
		case 8:yeni="+D+C+C+C"+yeni;break;
		case 9:yeni="-C+M"+yeni;break;
	}
	//dddddddddddddddddddddddddddddddddddddddddddddddd
	say=0;
	i=0;
	
	while(gelen[i]!='\0'){
		if(gelen[i]=='D'){
			say++;
		}
		i++;
	}
	switch(say){
		case 0:break;
		case 1:yeni="+D"+yeni;break;
		case 2:yeni="+M"+yeni;break;
		case 3:yeni="+M+D"+yeni;break;
		case 4:yeni="+M+M"+yeni;break;
		case 5:yeni="+M+M+D"+yeni;break;
		case 6:yeni="+M+M+M"+yeni;break;
		
	}
	
	say=0;
	i=0;
	while(gelen[i]!='\0'){
		if(gelen[i]=='M'){
			say++;
		}
		i++;
	}
	switch(say){
		case 0:break;
		case 1:yeni="+M"+yeni;break;
		case 2:yeni="+M+M"+yeni;break;
		case 3:yeni="+M+M+M"+yeni;break;
		case 4:yeni="+M+M+M+M"+yeni;
		cout<<"sayida tasma var.";
		break;
		case 5:yeni="+M+M+M+M+M"+yeni;
		cout<<"sayida tasma var.";
		break;
	}
	cout<<"Duzenli:"<<yeni<<endl<<endl;
}
