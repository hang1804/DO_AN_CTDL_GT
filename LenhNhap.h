#ifndef LENHNHAP_H
#define LENHNHAP_H
#include "GiaoDien.h"
using namespace std;
int LoaiNhap=0;
//	In hoa 
string Upper(string a){
	string ChuoiHoa; 
	int ChieuDai=a.length();
	for(int i=0; i<ChieuDai; i++)
	{
		if(a[i]>=97 && a[i]<=122)
		{
			a[i]-=32; 
		} 
		ChuoiHoa+=a[i]; 
	} 
	return ChuoiHoa; 
} 
//	In thuong
string Lower(string a){
	string ChuoiThuong; 
	int ChieuDai=a.length();
	for(int i=0; i<ChieuDai; i++)
	{
		if(a[i]>=65 && a[i]<=90)
		{
			a[i]+=32; 
		} 
		ChuoiThuong+=a[i]; 
	} 
	return ChuoiThuong; 
} 
//	Cac ky tu gom A-Z, 0-9, ky tu dac biet
string NhapKiTuCoSo(int ChieuDaiChuoi, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
	ShowCur(1);
	DieuKienKiTu=0;
	int x;
	int y;
	string a;
	x=wherex();
	y=wherey();
	SetColor(MauChu);
	while(1)
	{
		char b;
		b=getch();
		if(a.length()<ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if(b==BackSpace && a.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				a.pop_back();
			} 
			else if(b==13)
			{
				if(a.length()==0)
				{
					ShowCur(0);
					VeNoiDungThongBao(LoiTrong,DiemX,DiemY,12);
					Sleep(3000);
					XoaNoiDungThongBao(DiemX,DiemY,ChieuDaiKhungThongBao);
					ShowCur(1);
					gotoxy(x,y);
					SetColor(MauChu);
				}
				else
				{
					DieuKienKiTu=0;
					if(a.rfind(" ")==a.length()-1)
					{
						a.pop_back();
					}
					ShowCur(0);
					return a; 
				}
			} 
			else if(b==-32)
			{
				b=getch(); 
				if(b==Up || b==Down || b==Left || b==Right);
			}
			else if((b>=65 && b<=90) || (b>=97 && b<=122) || (b>=32 && b<=64))
			{
				if(a.rfind(" ")==a.length()-1 && b!=Space)
				{
					char k;
					k=toupper(b);
					cout<<k;
					a+=k;
				}
				else if(a.rfind(" ")!=a.length()-1 && b!=Space)
				{
					char k;
					k=tolower(b);
					cout<<k;
					a+=k;
				}
				else
				{	
					cout<<b;
					a+=b; 
				}
			} 
		}
		else if(a.length()>=ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if(a.length()==ChieuDaiChuoi && b==13)
			{
				DieuKienKiTu=0;
				if(a.rfind(" ")==a.length()-1)
				{
					a.pop_back();
				}
				ShowCur(0);
				return a; 
			}
			else if(b==BackSpace && a.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				a.pop_back();
			}
		}
	}
} 

//	Cac ky tu gom A-Z
string NhapKiTuKhongSo(int ChieuDaiChuoi, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
	ShowCur(1);
	DieuKienKiTu=0;
	int x;
	int y;
	string a;
	x=wherex();
	y=wherey();
	SetColor(MauChu);
	while(1)
	{
		char b;
		b=getch();
		if(a.length()<ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if(b==BackSpace && a.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				a.pop_back();
			} else if((b==Space && a[a.length()-1]==' ') || (b==Space && a.length()==0))
			{
			}
			else if(b==13)
			{
				if(a.length()==0)
				{
					ShowCur(0);
					VeNoiDungThongBao(LoiTrong,DiemX,DiemY,12);
					Sleep(3000);
					XoaNoiDungThongBao(DiemX,DiemY,ChieuDaiKhungThongBao);
					ShowCur(1);
					gotoxy(x,y);
					SetColor(MauChu);
				}
				else
				{
					DieuKienKiTu=0;
					if(a.rfind(" ")==a.length()-1)
					{
						a.pop_back();
					}
					ShowCur(0);
					return a; 
				}
			} 
			else if(b==-32)
			{
				b=getch(); 
				if(b==Up || b==Down || b==Left || b==Right);
			}
			else if((b>=65 && b<=90) || (b>=97 && b<=122) || b==32 || (b>=44 && b<=46) || b==38)
			{
				if(a.rfind(" ")==a.length()-1 && b!=Space)
				{
					char k;
					k=toupper(b);
					cout<<k;
					a+=k;
				}
				else if(a.rfind(" ")!=a.length()-1 && b!=Space)
				{
					char k;
					k=tolower(b);
					cout<<k;
					a+=k;
				}
				else
				{	
					cout<<b;
					a+=b; 
				}
			}
		}
		else if(a.length()>=ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break; 
			} 
			else if(a.length()==ChieuDaiChuoi && b==13)
			{
				DieuKienKiTu=0;
				if(a.rfind(" ")==a.length()-1)
				{
					a.pop_back();
				}
				ShowCur(0);
				return a; 
			}
			else if(b==BackSpace && a.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				a.pop_back();
			}
		}
	}
}

//	Chi dung de nhap ISBN 
string NhapISBN(int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
	ShowCur(1);
	DieuKienISBN=0;
	int x;
	int y;
	string Ma;
	x=wherex();
	y=wherey();
	SetColor(MauChu);
	while(1)
	{
		char b;
		b=getch();
		if(Ma.length()<4)
		{
			if(b==Esc)
			{
				DieuKienISBN=1;
				ShowCur(0);
				break; 
			} 
			else if(b==13 && Ma.length()==0)
			{
				ShowCur(0);
				VeNoiDungThongBao(LoiTrong,DiemX,DiemY,12);
				Sleep(3000);
				XoaNoiDungThongBao(DiemX,DiemY,ChieuDaiKhungThongBao);
				ShowCur(1);
				gotoxy(x,y);
				SetColor(MauChu);
			}
			else if(b==BackSpace && Ma.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Ma.pop_back();
			}
			else if(b==-32)
			{
				b=getch(); 
				if(b==Up || b==Down || b==Left || b==Right);
			}
			else if((b>=65 && b<=90) || (b>=97 && b<=122))
			{
				char z;
				z=toupper(b);
				cout<<z;
				Ma+=z;
			} 
		} 
		else if(Ma.length()>=4)
		{ 
			if(b==Esc)
			{
				DieuKienISBN=1;
				ShowCur(0);
				break; 
			} 
			else if(Ma.length()==4 && b==13)
			{
				DieuKienISBN=0;
				ShowCur(0);
				return Ma; 
			}
			else if(b==BackSpace && Ma.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Ma.pop_back();
			}
		} 
	} 
} 
int NhapSo(int ChieuDaiChuoi, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
	ShowCur(1);
	DieuKienKiTu=0;
	int a;
	int x;
	int y;
	string s;
	x=wherex();
	y=wherey();
	SetColor(MauChu);
	while(1)
	{
		char b;
		b=getch();
		if(s.length()<ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if(b==BackSpace && s.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				s.pop_back();
			}
			else if(b==13)
			{
				if(s.length()==0)
				{
					ShowCur(0);
					VeNoiDungThongBao(LoiTrong,DiemX,DiemY,12);
					Sleep(3000);
					XoaNoiDungThongBao(DiemX,DiemY,ChieuDaiKhungThongBao);
					ShowCur(1);
					gotoxy(x,y);
					SetColor(MauChu);
				} 
				else
				{
					DieuKienKiTu=0;
					a=stoi(s);
					ShowCur(0);
					return a;
				}
			}
			else if(b==-32)
			{
				b=getch(); 
				if(b==Up || b==Down || b==Left || b==Right);
			}
			else if(b>=48 && b<=57)
			{
				s+=b;
				cout<<b;
			}
		}
		else if(s.length()>=ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break; 
			} 
			else if(s.length()==ChieuDaiChuoi && b==13)
			{
				DieuKienKiTu=0;
				a=stoi(s);
				ShowCur(0);
				return a; 
			}
			else if(b==BackSpace && s.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				s.pop_back();
			}
		}
	} 
}
string CapNhatKiTuCoSo(string Goc, int ChieuDaiChuoi, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
	ShowCur(1);
	DieuKienKiTu=0;
	string m=Goc;
	string a;
	char b;
	int x=wherex();
	int y=wherey();
	SetColor(MauChu);
	while(1)
	{
		b=getch();
		if(a.length()+Goc.length()<ChieuDaiChuoi)
		{
			if(b==BackSpace && a.length()==0 && Goc.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Goc.pop_back();
			}	
			else if(b==BackSpace && a.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				a.pop_back();
			}
			else if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			}
			else if(b==13)
			{
				if(a.length()==0 && Goc.length()==0)
				{
					ShowCur(0);
					VeNoiDungThongBao(LoiTrong,DiemX,DiemY,12);
					Sleep(3000);
					XoaNoiDungThongBao(DiemX,DiemY,ChieuDaiKhungThongBao);
					ShowCur(1);
					gotoxy(x,y);
					SetColor(MauChu);
				}
				else if((a.length()==0 && Goc.length()>0) || (a.length()>0 && Goc.length()>0) || (a.length()>0 && Goc.length()==0))
				{
					DieuKienKiTu=0;
					Goc+=a;
					if(Goc.rfind(" ")==Goc.length()-1)
					{
						Goc.pop_back();
					}
					ShowCur(0);
					return Goc; 
				}
			}
			else if(b==-32)
			{
				b=getch(); 
				if(b==Up || b==Down || b==Left || b==Right);
			}
			else if(a.length()==0 && b==32)
			{
				gotoxy(wherex()+1,wherey());
				a+=b;
			}
			else if((b>=65 && b<=90) || (b>=97 && b<=122) || (b>=32 && b<=64))
			{
				if(a.length()==0 && Goc.rfind(" ")==Goc.length()-1 && b!=32)
				{
					char k;
					k=toupper(b);
					cout<<k;
					a+=k;
				}
				else if(a.length()>0 && a.rfind(" ")==a.length()-1 && b!=32)
				{
					char k;
					k=toupper(b);
					cout<<k;
					a+=k;
				}
				else if(a.length()==0 && Goc.rfind(" ")!=Goc.length()-1 && b!=Space)
				{
					char k;
					k=tolower(b);
					cout<<k;
					a+=k;
				}
				else if(a.length()>0 && a.rfind(" ")!=a.length()-1 && b!=Space)
				{
					char k;
					k=tolower(b);
					cout<<k;
					a+=k;
				}
				else
				{	
					cout<<b;
					a+=b; 
				}
			} 
		}
		else if(a.length()+Goc.length()>=ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if((a.length()+Goc.length())==ChieuDaiChuoi && b==13)
			{
				DieuKienKiTu=0;
				Goc+=a;
				if(Goc.rfind(" ")==Goc.length()-1)
				{
					Goc.pop_back();
				}
				ShowCur(0);
				return Goc; 
			}
			else if(b==BackSpace && a.length()==0 && Goc.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Goc.pop_back();
			}	
			else if(b==BackSpace && a.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				a.pop_back();
			}
		}
	}
} 
string CapNhatKiTuKhongSo(string Goc, int ChieuDaiChuoi, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
	ShowCur(1);
	DieuKienKiTu=0;
	string m=Goc;
	string a;
	char b;
	int x=wherex();
	int y=wherey();
	SetColor(MauChu);
	while(1)
	{
		b=getch();
		if(a.length()+Goc.length()<ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if(b==BackSpace && a.length()==0 && Goc.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Goc.pop_back();
			}	
			else if(b==BackSpace && a.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				a.pop_back();
			}else if((b==Space && a[a.length()-1]==' ') || (b==Space && a.length()==0))
			{
			}
			else if(b==13)
			{
				if(a.length()==0 && Goc.length()==0)
				{
					ShowCur(0);
					VeNoiDungThongBao(LoiTrong,DiemX,DiemY,12);
					Sleep(3000);
					XoaNoiDungThongBao(DiemX,DiemY,ChieuDaiKhungThongBao);
					ShowCur(1);
					gotoxy(x,y);
					SetColor(MauChu);
				}
				else if((a.length()==0 && Goc.length()>0) || (a.length()>0 && Goc.length()>0) || (a.length()>0 && Goc.length()==0))
				{
					DieuKienKiTu=0;
					Goc+=a;
					if(Goc.rfind(" ")==Goc.length()-1)
					{
						Goc.pop_back();
					}
					ShowCur(0);
					return Goc; 
				}
			}
			else if(b==-32)
			{
				b=getch(); 
				if(b==Up || b==Down || b==Left || b==Right);
			}
			else if(a.length()==0 && b==32)
			{
				gotoxy(wherex()+1,wherey());
				a+=b;
			} 
			else if((b>=65 && b<=90) || (b>=97 && b<=122) || b==32 || (b>=44 && b<=46) || b==38)
			{
				if(a.length()==0 && Goc.rfind(" ")==Goc.length()-1 && b!=32)
				{
					char k;
					k=toupper(b);
					cout<<k;
					a+=k;
				}
				else if(a.length()>0 && a.rfind(" ")==a.length()-1 && b!=32)
				{
					char k;
					k=toupper(b);
					cout<<k;
					a+=k;
				}
				else if(a.length()==0 && Goc.rfind(" ")!=Goc.length()-1 && b!=Space)
				{
					char k;
					k=tolower(b);
					cout<<k;
					a+=k;
				}
				else if(a.length()>0 && a.rfind(" ")!=a.length()-1 && b!=Space)
				{
					char k;
					k=tolower(b);
					cout<<k;
					a+=k;
				}
				else
				{	
					cout<<b;
					a+=b; 
				}
			}
		}
		else if(a.length()+Goc.length()>=ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if((a.length()+Goc.length())==ChieuDaiChuoi && b==13)
			{
				DieuKienKiTu=0;
				Goc+=a;
				if(Goc.rfind(" ")==Goc.length()-1)
				{
					Goc.pop_back();
				}
				ShowCur(0);
				return Goc; 
			}
			else if(b==BackSpace && a.length()==0 && Goc.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Goc.pop_back();
			}	
			else if(b==BackSpace && a.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				a.pop_back();
			}
		}
	}
}
int CapNhatSo(int SoGoc, int ChieuDaiChuoi, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
	ShowCur(1);
	DieuKienKiTu=0;
	int m=SoGoc;
	int a;
	string Goc=to_string(SoGoc);
	string s;
	int x=wherex();
	int y=wherey();
	SetColor(MauChu);
	while(1)
	{
		char b;
		b=getch();
		if(s.length()+Goc.length()<ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if(b==BackSpace && s.length()==0 && Goc.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Goc.pop_back();
			}	
			else if(b==BackSpace && s.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				s.pop_back();
			}
			else if(b==13)
			{
				if(s.length()==0 && Goc.length()==0)
				{
					ShowCur(0);
					VeNoiDungThongBao(LoiTrong,DiemX,DiemY,12);
					Sleep(3000);
					XoaNoiDungThongBao(DiemX,DiemY,ChieuDaiKhungThongBao);
					ShowCur(1);
					gotoxy(x,y);
					SetColor(MauChu);
				}
				else if((s.length()==0 && Goc.length()>0) || (s.length()>0 && Goc.length()>0) || (s.length()>0 && Goc.length()==0))
				{
					DieuKienKiTu=0;
					Goc+=s;
					a=stoi(Goc);
					ShowCur(0);
					return a; 
				}
			}
			else if(b==-32)
			{
				b=getch(); 
				if(b==Up || b==Down || b==Left || b==Right);
			}
			else if(b>=48 && b<=57)
			{
				s+=b;
				cout<<b;
			}
		}
		else if(s.length()+Goc.length()>=ChieuDaiChuoi)
		{
			if(b==Esc)
			{
				DieuKienKiTu=1;
				ShowCur(0);
				break;
			} 
			else if((s.length()+Goc.length())==ChieuDaiChuoi && b==13)
			{
				DieuKienKiTu=0;
				Goc+=s;
				a=stoi(Goc);
				ShowCur(0);
				return a; 
			}
			else if(b==BackSpace && s.length()==0 && Goc.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Goc.pop_back();
			}	
			else if(b==BackSpace && s.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				s.pop_back();
			}
		}
	} 
}
string CapNhatISBN(string Goc, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
	ShowCur(1);
	DieuKienISBN=0;
	LoaiNhap=0;
	string m=Goc;
	string Ma;
	int x=wherex();
	int y=wherey();
	SetColor(MauChu);
	while(1)
	{
		char b;
		b=getch();
		if(Goc.length()+Ma.length()<4)
		{
			if(b==Esc)
			{
				DieuKienISBN=1;
				ShowCur(0);
				return m; 
			} 
			else if(b==13)
			{
				if(Ma.length()==0 && Goc.length()==0)
				{
					ShowCur(0);
					VeNoiDungThongBao(LoiTrong,DiemX,DiemY,12);
					Sleep(3000);
					XoaNoiDungThongBao(DiemX,DiemY,ChieuDaiKhungThongBao);
					ShowCur(1);
					gotoxy(x,y);
					SetColor(MauChu);
				}
				else if((Ma.length()==0 && Goc.length()>0) || (Ma.length()>0 && Goc.length()>0) || (Ma.length()>0 && Goc.length()==0))
				{
					DieuKienKiTu=0;
					Goc+=Ma;
					ShowCur(0);
					return Goc; 
				}
			}
			else if(b==BackSpace && Ma.length()==0 && Goc.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Goc.pop_back();
			}
			else if(b==BackSpace && Ma.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Ma.pop_back();
			}
			else if(b==-32)
			{
				b=getch(); 
				if(b==Up || b==Down || b==Left || b==Right);
			}
			else if((b>=65 && b<=90) || (b>=97 && b<=122))
			{
				char z;
				z=toupper(b);
				cout<<z;
				Ma+=z;
			} 
		} 
		else if(Ma.length()+Goc.length()>=4)
		{ 
			if(b==Esc)
			{
				DieuKienISBN=1;
				ShowCur(0);
				return m; 
			} 
			else if((Ma.length()+Goc.length())==4 && b==13)
			{
				DieuKienISBN=0;
				Goc+=Ma;
				ShowCur(0);
				return Goc; 
			}
			else if(b==BackSpace && Ma.length()==0 && Goc.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Goc.pop_back();
			}	
			else if(b==BackSpace && Ma.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				Ma.pop_back();
			}
		}
	} 
}
#endif
