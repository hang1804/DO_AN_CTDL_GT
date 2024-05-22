#ifndef GIAODIEN_H
#define GIAODIEN_H
#include "Define.h"
#include "SaveLoadFile.h"
using namespace std;
 
int chon=0;
void Nen(){
	SetColor(8);
	SetBGColor(1);
}
void XoaMenuThuVien(){
	Nen();
	for(int i=0; i<41; i++)
	{
		gotoxy(80,6+i);
		cout<<"                                             ";
	}
}
void XoaMenu(){
	Nen();
	for(int i=4; i<GocY; i++)
	{
		gotoxy(0,i);
		cout<<"                                                                                                                                                                                                                                               ";
	}
}
void XoaBangDanhSach(){
	Nen();
	for(int i=GocY; i<49; i++)
	{
		gotoxy(0,i);
		cout<<"                                                                                                                                                                                                                                               ";
	}
}
void VeLe(){
	Nen();
	for(int i=30; i<156; i++)
	{
		gotoxy(i,9);
		cout<<char(126);
	}
}
void XoaLe(){
	Nen();
	for(int i=0; i<189; i++)
	{
		gotoxy(i,9);
		cout<<" ";
	}
}
void XoaThongTin(int ChieuDai[], int SoThongTin, int ToaDoX, int ToaDoY){
	Nen();
	int DiemX;
	for(int i=0; i<ChieuDai[0]-1; i++)
	{
		gotoxy(ToaDoX+1+i,ToaDoY);
		cout<<" ";
	}
	DiemX=ToaDoX+1+ChieuDai[0]+1;
	for(int i=0; i<ChieuDai[1]-1; i++)
	{
		gotoxy(DiemX+i,ToaDoY);
		cout<<" ";
	}
	for(int i=2; i<SoThongTin; i++)
	{
		DiemX+=ChieuDai[i-1]+1;
		for(int j=0; j<ChieuDai[i]-1; j++)
		{
			gotoxy(DiemX+j,ToaDoY);
			cout<<" ";
		}
	}
	Nen();
}
void VeKhungCapNhat(string ThongTin[], int DiemX, int DiemY, int ChieuDai, int ChieuRong, int MauKhung, int MauChu, int MauTieuDe){
	SetBGColor(1);
	SetColor(MauKhung);
	for(int i=0; i<ChieuDai; i++)
	{
		gotoxy(DiemX+1+i,DiemY);
		cout<<char(196);
		gotoxy(DiemX+1+i,DiemY+ChieuRong+1);
		cout<<char(196);
	}
	for(int i=0; i<ChieuRong+1; i++)
	{
		gotoxy(DiemX,DiemY+i);
		cout<<char(179);
		gotoxy(DiemX+ChieuDai+1,DiemY+i);
		cout<<char(179);
	}
	gotoxy(DiemX,DiemY);
	cout<<char(218);
	gotoxy(DiemX+1+ChieuDai,DiemY);
	cout<<char(191);
	gotoxy(DiemX,DiemY+ChieuRong+1);
	cout<<char(192);
	gotoxy(DiemX+1+ChieuDai,DiemY+ChieuRong+1);
	cout<<char(217);
	SetColor(MauTieuDe);
	string TieuDe="THONG TIN DAU SACH CAP NHAT";
	gotoxy(DiemX+1+((ChieuDai-TieuDe.length())/2),DiemY+2);
	cout<<TieuDe;
	int j=0;
	SetColor(MauChu);
	for(int i=2; i<ChieuRong; i++)
	{
		if(i%2!=0)
		{
			gotoxy(DiemX+1+2,DiemY+1+i);
			cout<<ThongTin[j]<<":";
			j++;
		}
	}
}
void XoaKhungCapNhat(int DiemX, int DiemY, int ChieuRong){
	Nen();
	for(int i=0; i<ChieuRong+2; i++)
	{
		gotoxy(DiemX,DiemY+i);
		cout<<"                                                            ";
	}
}
void KhungMenu(string LuaChon, int MauChu, int MauNen, int ChieuDai, int ChieuRong, int DiemX, int DiemY){
	int m;
	int GiuaX;
	int GiuaY;
	for(int i=0; i<ChieuRong; i++)
	{
		gotoxy(DiemX,DiemY+i);
		for(int j=0; j<ChieuDai; j++)
		{
			SetBGColor(MauNen);
			cout<<" ";
		}
	}
	m=LuaChon.length();
	GiuaX=(ChieuDai-m)/2;
	GiuaY=ChieuRong/2;
	gotoxy(DiemX+GiuaX, DiemY+GiuaY);
	SetColor(MauChu);
	cout<<LuaChon;
}

void TieuDe(){
	Nen();
	string s="CHUONG TRINH QUAN LY THU VIEN                     ";
	SetBGColor(12); 
	gotoxy(70,1);
	for(int i=0; i<50; i++)
	{
		cout<<" "; 
	} 
	gotoxy(70,3); 
	for(int i=0; i<50; i++)
	{
		cout<<" "; 
	} 
	SetColor(5); 
	gotoxy(70,2);
	cout<<s;
	while(!_kbhit()) 
	{
		char tmp=s[s.length()-1];
		for(int i=s.length()-1; i>=0; i--)
		{
			s[i]=s[i-1]; 
		} 
		s[0]=tmp;
		
		gotoxy(70,2); 
		cout<<s; 
		Sleep(80); 
	} 
	gotoxy(70,2); 
	for(int i=0; i<50; i++)
	{
		cout<<" "; 
	} 
	gotoxy(80,2);
	cout<<"CHUONG TRINH QUAN LY THU VIEN"; 
	Nen(); 
}

int UpDownMenu(string a[], int MauChu, int MauNen, int MauChon, int ChieuDai, int ChieuRong, int SoMuc, int ToaDo[][2]){
	while(1)
	{
		char c=getch();
		if(c==Up || c==Left)
		{
			if(chon==0)
			{
				KhungMenu(a[chon],MauChu,MauNen,ChieuDai,ChieuRong,ToaDo[chon][0],ToaDo[chon][1]);
				chon=SoMuc-1;
				KhungMenu(a[chon],MauChu,MauChon,ChieuDai,ChieuRong,ToaDo[chon][0],ToaDo[chon][1]); 
			} 
			else if(chon<SoMuc && chon>0)
			{
				KhungMenu(a[chon],MauChu,MauNen,ChieuDai,ChieuRong,ToaDo[chon][0],ToaDo[chon][1]);
				chon--;
				KhungMenu(a[chon],MauChu,MauChon,ChieuDai,ChieuRong,ToaDo[chon][0],ToaDo[chon][1]); 
			} 
		}
		else if(c==Down || c==Right)
		{
			if(chon==SoMuc-1)
			{
				KhungMenu(a[chon],MauChu,MauNen,ChieuDai,ChieuRong,ToaDo[chon][0],ToaDo[chon][1]);
				chon=0;
				KhungMenu(a[chon],MauChu,MauChon,ChieuDai,ChieuRong,ToaDo[chon][0],ToaDo[chon][1]); 
			}
			else if(chon>=0 && chon<SoMuc)
			{
				KhungMenu(a[chon],MauChu,MauNen,ChieuDai,ChieuRong,ToaDo[chon][0],ToaDo[chon][1]);
				chon++;
				KhungMenu(a[chon],MauChu,MauChon,ChieuDai,ChieuRong,ToaDo[chon][0],ToaDo[chon][1]); 
			}
		}
		else if(c==13)
		{
			return chon;
		}
	}
}
//	Diem Goc (0,9)
void BangDanhSach(string a[], int ChieuDai[], int ChieuRong, int SoThongTin, int MauChu, int MauKhung, int ToaDoX, int ToaDoY){
	SetColor(MauKhung);
	SetBGColor(1);
	
	int ViTriGiua;
	int DiemX=ToaDoX;
	int DiemY=ToaDoY;
	int ToaDoChu=ToaDoX;
	int x=ToaDoX;
	
	
//	Ve Goc Trai
	gotoxy(DiemX,DiemY+1);
	cout<<char(186);
	gotoxy(DiemX,DiemY);
	cout<<char(201);
	gotoxy(DiemX,DiemY+2);
	cout<<char(204);
	for(int i=0; i<ChieuRong; i++)
	{
		gotoxy(DiemX,DiemY+i+3);
		cout<<char(186);
	}
	gotoxy(DiemX,ChieuRong+DiemY+3);
	cout<<char(200);
	
	
//	Ve O Giua
	for(int i=0; i<SoThongTin-1; i++)
	{
////	Ve Duong Doc
		DiemX+=(ChieuDai[i]+1);
		gotoxy(DiemX,DiemY+1);
		cout<<char(179);
	}
	for(int i=0; i<SoThongTin; i++)
	{
		x++;
		for(int j=0; j<ChieuDai[i]; j++)
		{
////		Ve Duong Ngang Tren
			gotoxy(x,DiemY);
			cout<<char(205);
			
////		Ve Duong Ngang Duoi
			gotoxy(x,DiemY+2);
			cout<<char(205);
			
////		Ve Duong Ngang Cuoi Bang
			gotoxy(x,ChieuRong+DiemY+3);
			cout<<char(205);
			
			x++;
		}
////	Ve Nga Ba Tren
		gotoxy(x,DiemY);
		cout<<char(209);
		
////	Ve Nga Ba Duoi
		gotoxy(x,DiemY+2);
		cout<<char(216);
		
////	Ve Nga Ba Cuoi Bang
		gotoxy(x,ChieuRong+DiemY+3);
		cout<<char(207);
		
////	Ve Duong Doc O Giua
		for(int i=0; i<ChieuRong; i++)
		{
			gotoxy(x,DiemY+3+i);
			cout<<char(179);
		}
		
////	Ve Chu Tieu De
		SetColor(MauChu);
		ViTriGiua=(ChieuDai[i]-a[i].length())/2;
		gotoxy(ViTriGiua+ToaDoChu+1,DiemY+1);
		cout<<a[i];
		ToaDoChu+=ChieuDai[i]+1;
		SetColor(MauKhung);
	}
	
	
//	Ve Goc Phai
	gotoxy(DiemX+ChieuDai[SoThongTin-1]+1,DiemY+1);
	cout<<char(186);
	gotoxy(DiemX+ChieuDai[SoThongTin-1]+1,DiemY);
	cout<<char(187);
	gotoxy(DiemX+ChieuDai[SoThongTin-1]+1,DiemY+2);
	cout<<char(185);
	for(int i=0; i<ChieuRong; i++)
	{
		gotoxy(DiemX+ChieuDai[SoThongTin-1]+1,DiemY+i+3);
		cout<<char(186);
	}
	gotoxy(DiemX+ChieuDai[SoThongTin-1]+1,ChieuRong+DiemY+3);
	cout<<char(188);
}
void VePhim(string s, int MauChu, int MauNen, int DiemX, int DiemY){
	SetBGColor(MauNen);
	SetColor(MauChu); 
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<s.length()+2; j++)
		{
			gotoxy(DiemX+j,DiemY+i);
			cout<<" ";
			if(i==1)
			{
				gotoxy(DiemX+1,DiemY+i);
				cout<<s;
			}
		} 
	}
	Nen();
}
void XoaPhim(int DiemX, int DiemY){
	Nen();
	for(int i=0; i<3; i++)
	{
		gotoxy(DiemX,DiemY+i);
		cout<<"                                                                                                                                                                                                           ";
	}
}
void VeQuyDinhNhapChu(int DiemX, int DiemY){
	string Dong1;
	string Dong2;
	Dong1=QuyDinhNhapChu.substr(0,QuyDinhNhapChu.find(","));
	Dong2=QuyDinhNhapChu.substr(QuyDinhNhapChu.find(",")+2);
	for(int i=0; i<5; i++)
	{
		gotoxy(DiemX,DiemY+i);
		for(int j=0; j<40; j++)
		{
			SetBGColor(3);
			cout<<" ";
		} 
		if(i==1)
		{
			SetColor(5);
			gotoxy(DiemX+(40-Dong1.length())/2,DiemY+i);
			cout<<Dong1;
		} 
		else if(i==3)
		{
			SetColor(5);
			gotoxy(DiemX+(40-Dong2.length())/2,DiemY+i);
			cout<<Dong2;
		}
	}
	Nen();
}
void VeQuyDinhNhapSo(int DiemX, int DiemY){
	for(int i=0; i<3; i++)
	{
		gotoxy(DiemX,DiemY+i);
		for(int j=0; j<40; j++)
		{
			SetBGColor(3);
			cout<<" ";
		} 
		if(i==1)
		{
			SetColor(5);
			gotoxy(DiemX+(40-QuyDinhNhapSo.length())/2,DiemY+i);
			cout<<QuyDinhNhapSo;
		}
	}
	Nen();
}
void VeQuyDinhNhapChuSo(int DiemX, int DiemY){
	string Dong1;
	string Dong2;
	string Dong3;
	Dong1=QuyDinhNhapChuSo.substr(0,QuyDinhNhapChuSo.find(";"));
	Dong2=QuyDinhNhapChuSo.substr(QuyDinhNhapChuSo.find(";")+2, QuyDinhNhapChuSo.rfind(";")-(QuyDinhNhapChuSo.find(";")+2));
	Dong3=QuyDinhNhapChuSo.substr(QuyDinhNhapChuSo.rfind(";")+2);
	for(int i=0; i<7; i++)
	{
		gotoxy(DiemX,DiemY+i);
		for(int j=0; j<47; j++)
		{
			SetBGColor(3);
			cout<<" ";
		} 
		if(i==1)
		{
			SetColor(5);
			gotoxy(DiemX+(47-Dong1.length())/2,DiemY+i);
			cout<<Dong1;
		} 
		else if(i==3)
		{
			SetColor(5);
			gotoxy(DiemX+(47-Dong2.length())/2,DiemY+i);
			cout<<Dong2;
		}
		else if(i==5)
		{
			SetColor(5);
			gotoxy(DiemX+(47-Dong3.length())/2,DiemY+i);
			cout<<Dong3;
		}
	}
	Nen();
}
void XoaQuyDinh(int DiemX, int DiemY){
	Nen();
	for(int i=0; i<7; i++)
	{
		gotoxy(DiemX,DiemY+i);
		cout<<"                                                     ";
	}
}
void VeKhungChinhSua(string TieuDe, string s, int DiemX, int DiemY, int MauKhung, int MauChu, int ChieuDai){
	SetBGColor(1);
	SetColor(MauKhung);
	for(int i=0; i<7; i++)
	{
		gotoxy(DiemX,DiemY+i);
		cout<<char(179);
		gotoxy(DiemX+ChieuDai+1,DiemY+i);
		cout<<char(179);
	}
	for(int i=0; i<ChieuDai; i++)
	{
		gotoxy(DiemX+1+i,DiemY);
		cout<<char(196);
		gotoxy(DiemX+1+i,DiemY+6);
		cout<<char(196);
	}
	gotoxy(DiemX,DiemY);
	cout<<char(218);
	gotoxy(DiemX+ChieuDai+1,DiemY);
	cout<<char(191);
	gotoxy(DiemX,DiemY+6);
	cout<<char(192);
	gotoxy(DiemX+ChieuDai+1,DiemY+6);
	cout<<char(217);
	SetColor(MauChu);
	gotoxy(((ChieuDai-TieuDe.length())/2)+DiemX+1,DiemY+2);
	cout<<TieuDe;
	gotoxy(DiemX+2,DiemY+4);
	cout<<s;
}
void XoaKhungChinhSua(int DiemX, int DiemY){
	Nen();
	for(int i=0; i<8; i++)
	{
		gotoxy(DiemX,DiemY+i);
		cout<<"                                                                           ";
	}
}
void VeKhungThongBao(int DiemX, int DiemY, int MauChu, int ChieuDai){
	Nen();
	SetColor(MauChu);
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<ChieuDai; j++)
		{
			if(i==0 || i==2)
			{
				gotoxy(DiemX+j,DiemY+i);
				cout<<char(196);
			}
			if(j==0 && i==0)
			{
				gotoxy(DiemX+j,DiemY+i);
				cout<<char(218);
			}
			if(j==ChieuDai-1 && i==0)
			{
				gotoxy(DiemX+j,DiemY+i);
				cout<<char(191);
			}
			if(j==0 && i==2)
			{
				gotoxy(DiemX+j,DiemY+i);
				cout<<char(192);
			}
			if(j==ChieuDai-1 && i==2)
			{
				gotoxy(DiemX+j,DiemY+i);
				cout<<char(217);
			}
			if(i==1)
			{
				if(j==0 || j==ChieuDai-1)
				{
					gotoxy(DiemX+j,DiemY+i);
					cout<<char(179);
				}
				if(j==1)
				{
					gotoxy(DiemX+j,DiemY+i);
					cout<<"THONG BAO:";
				}
			}
		}
	}
}
void XoaKhungThongBao(int DiemX, int DiemY){
	Nen();
	for(int i=0; i<3; i++)
	{
		gotoxy(DiemX,DiemY+i);
		cout<<"                                                                                                         ";
	}
}
void VeNoiDungThongBao(string s, int DiemX, int DiemY, int MauChu){
	SetColor(MauChu);
	gotoxy(DiemX,DiemY);
	cout<<s;
}
void XoaNoiDungThongBao(int DiemX, int DiemY, int ChieuDai){
	SetBGColor(1);
	for(int i=0; i<ChieuDai-17; i++)
	{
		gotoxy(DiemX+i,DiemY);
		cout<<" ";
	}
}
void VeTrang(int SoTrang, int TongTrang, int DiemX, int DiemY, int MauChu){
	SetColor(MauChu);
	gotoxy(DiemX,DiemY);
	cout<<"Trang "<<SoTrang<<"/"<<TongTrang;
	Nen();
}
void VeMenuThuVien(){
	KhungMenu(MenuThuVien[0], CHU, NEN_CHON, 20, 3, ViTriMenuThuVien[0][0], ViTriMenuThuVien[0][1]);
	KhungMenu(MenuThuVien[1], CHU, NEN_GOC, 20, 3, ViTriMenuThuVien[1][0], ViTriMenuThuVien[1][1]);
	KhungMenu(MenuThuVien[2], CHU, NEN_GOC, 20, 3, ViTriMenuThuVien[2][0], ViTriMenuThuVien[2][1]);
}

void VeMenuDauSach(){
	KhungMenu(MenuDauSach[0], CHU, NEN_CHON, 38, 3, ViTriMenuDauSach[0][0], ViTriMenuDauSach[0][1]);
	KhungMenu(MenuDauSach[1], CHU, NEN_GOC, 38, 3, ViTriMenuDauSach[1][0], ViTriMenuDauSach[1][1]);
	KhungMenu(MenuDauSach[2], CHU, NEN_GOC, 38, 3, ViTriMenuDauSach[2][0], ViTriMenuDauSach[2][1]);	
	KhungMenu(MenuDauSach[3], CHU, NEN_GOC, 38, 3, ViTriMenuDauSach[3][0], ViTriMenuDauSach[3][1]);	
}

void VeMenuDocGia(){
	KhungMenu(MenuDocGia[0], CHU, NEN_CHON, 30, 3, ViTriMenuDocGia[0][0], ViTriMenuDocGia[0][1]);
	KhungMenu(MenuDocGia[1], CHU, NEN_GOC, 30, 3, ViTriMenuDocGia[1][0], ViTriMenuDocGia[1][1]);
	KhungMenu(MenuDocGia[2], CHU, NEN_GOC, 30, 3, ViTriMenuDocGia[2][0], ViTriMenuDocGia[2][1]);
	KhungMenu(MenuDocGia[3], CHU, NEN_GOC, 30, 3, ViTriMenuDocGia[3][0], ViTriMenuDocGia[3][1]);
	KhungMenu(MenuDocGia[4], CHU, NEN_GOC, 30, 3, ViTriMenuDocGia[4][0], ViTriMenuDocGia[4][1]);
}
void Normal()
{
	SetBGColor(1);
	SetColor(15);
}

void Box(int x, int y, int w, int h, int Doc, int Ngang)
{
    if((h <= 1) || (w <= 1)) return;
    for (int i = x; i <= x+w; i++)
    {
        gotoxy(i, y);
        cout <<char(Ngang);
        gotoxy(i, y+h);
        cout <<char(Ngang);
    }
    for (int i = y; i <= y+h; i++)
    {
        gotoxy(x, i);
        cout <<char(Doc);
        gotoxy(x+w, i);
        cout <<char(Doc);
    }
    gotoxy(x, y); cout <<char((Doc == Doc2) ? 201 : 218);
    gotoxy(x+w, y); cout <<char((Doc == Doc2) ? 187 : 191);
    gotoxy(x, y+h); cout <<char((Doc == Doc2) ? 200 : 192);
    gotoxy(x+w, y+h); cout <<char((Doc == Doc2) ? 188 : 217);
}

void Box_mau(int x, int y, int w, int h, int b_color)
{
	SetBGColor(b_color);
	for (int iy = y; iy <= y+h; iy++)
	{
		for (int ix = x; ix <= x+w; ix++)
		{
			gotoxy(ix, iy); cout <<" ";
		}
	}
}

void chayChu(string dongChu, int x, int y, int t_color, int b_color, int w)
{
	SetBGColor(b_color);
	SetColor(t_color);
	gotoxy(x, y);
	for (int i = 0; i < w; i++)
	{
		cout <<dongChu[i];
	}
	char tmp;
	int length = dongChu.length();
	while(!_kbhit())
	{
		tmp = dongChu[length - 1];
		for (int i = length - 1; i > 0; i--)
		{
			dongChu[i] = dongChu[i-1];
		}
		dongChu[0] = tmp;
		SetColor(t_color);
		gotoxy(x, y);
		for (int i = 0; i < w; i++)
		{
			cout <<dongChu[i];
		}
		Sleep(100);
	}
	Normal();
}
#endif
