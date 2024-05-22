#ifndef DOCGIA_H
#define DOCGIA_H
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "mylib.h"
#include "Define.h" 
#include "KhaiBao.h"
#include "LenhNhap.h"
#include "SaveLoadFile.h"
#include <iomanip>
using namespace std;
int dem,sl_dg;
void Khoitao(PTRCNP &t){
    t=NULL;
    int  cp=0;
}
int sapxep(PTRCNP a[],int l,int r){
	char max=a[r]->dg.ten[0];
	PTRCNP tmp;
	int i=l-1;
	for(int j=l;j<r;j++){
		if(a[j]->dg.ten[0]<=max){
			i++;
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}	
	}
	i++;
	tmp=a[i];
	a[i]=a[r];
	a[r]=tmp;
	return i;
}
void quick_sort(PTRCNP a[],int l,int r){
	if(l>r) return;
		int p=sapxep(a,l,r);
		quick_sort(a,l,p-1);
		quick_sort(a,p+1,r);
}
//xu ly ma the
void luu_MT_vao_mang(int* &maDG, int &n)
{
	fstream ifs;
	ifs.open("MaDocGia.txt",ios::in);
	if (!ifs.is_open())
	{
		cout <<"Khong mo duoc file";
		return;
	}
	ifs >>n;
	maDG = new int[n];
	for (int i = 0; i < n; i++)
	{
		ifs >>maDG[i];
	}
	ifs.close();
}

void xoa_MT_trong_mang(int* &ma,int &dem_ma){
	dem_ma--;
	int* tmp= new int[dem_ma];
	for(int i=0;i<dem_ma;i++)
	{
		tmp[i]=ma[i];
	}
	delete []ma;
	ma=tmp;
}


void them_MT_trong_mang(int* &ma,int &dem_ma,int x){
	dem_ma++;
	int* tmp=new int[dem_ma];
	for(int i=0;i<dem_ma-1;i++)
	{
		tmp[i]=ma[i];
	}
	tmp[dem_ma-1]=x;
	delete []ma;
	ma=tmp;
}

void ghi_MT_vao_file(int *maDG, int n)
{
	ofstream of;
	of.open("MaDocGia.txt");
	if(!of.is_open())
	{
		cout <<"Khong mo duoc file!";
		return;
	}
	of <<n<<endl;
	for (int i = 0; i < n; i++)
	{
		if (i%10 == 0 && i != 0)
        {
        	of <<endl;
		}
		of <<setw(10)<<maDG[i];
	}
	of.close();
}
//
string ChuanHoaChuoi(string x){
	stringstream ss(x);
	string tmp="",tmt;
	while(ss>>tmt)
	{
		tmp+=toupper(tmt[0]);
		for(int j=1;j<tmt.size();j++)
		{
			tmp+=tolower(tmt[j]);
		}
		tmp+=" ";	
	}
	tmp.pop_back();
	if(tmp[tmp.length()-1]==' ') tmp.pop_back();
	return tmp;
	}

string CapNhatKiTuKhongSo1(string Goc, int ChieuDaiChuoi, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
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
		if(a.length()>0 && a[a.length()-1]!=' ' || a.length()==0)
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
			}
			else if(b==Space && a.length()==0)
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
				}else if((a.length()==0 && Goc.length()>0) || (a.length()>0 && Goc.length()>0) || (a.length()>0 && Goc.length()==0))
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
	else
	{
		gotoxy(wherex()-1, wherey());
		cout<<" "; 
		cout<<"\b";
		a.pop_back();
	}
	}
}

int NhapSo1(int ChieuDaiChuoi, int DiemX, int DiemY, int MauChu, int ChieuDaiKhungThongBao){
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
					VeNoiDungThongBao(LoiTrong,24,11,12);
					Sleep(3000);
					XoaNoiDungThongBao(24,11,ChieuDaiKhungThongBao);
					ShowCur(1);
					gotoxy(x,y);
				} 
				else
				{
					DieuKienKiTu=0;
					a=stoi(s);
					ShowCur(0);
					return a;
				}
			}
			else if(b>=48 && b<=49)
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
			}else if(b==BackSpace && s.length()>0)
			{
				gotoxy(wherex()-1, wherey());
				cout<<" "; 
				cout<<"\b";
				s.pop_back();
			}
		}
	} 
}
PTRCNP* them_phan_tu_vao_mang(PTRCNP* z,int i){ 
  z=new PTRCNP[i];
  return z;
}

void duyetDG(PTRCNP t,PTRCNP* &z,int &j){
	PTRCNP* w;
	if(t==NULL) return;
	else
	{
		duyetDG(t->left,z,j);
		j++;
		w=them_phan_tu_vao_mang(w,j);
		int i=0;
		while(i<j-1)
		{
			if(z[0]==NULL)
			{
				z[0]=t;
				break;
			} 
			w[i]=z[i];
			i++;	
		}
		w[j-1]=t;
		delete []z;
		z=w;
		duyetDG(t->right,z,j);	
	}
}

PTRCNP* luu_dia_chi_vao_mang(PTRCNP t,int &sl_dg,int k){
	sl_dg=0;
	PTRCNP *z=new PTRCNP[sl_dg];
	duyetDG(t,z,sl_dg);
	if(k%2!=0) quick_sort(z,0,sl_dg-1);
	return z;
}	
void XoaThongTinDocGia(){
	XoaThongTin(chieudaiDG,1,XDocGia,wherey());
}
void XoaThongTinDocGia1(int x,int y,int i){
	XoaThongTin(chieudaiDG,5,x,y+i);
}
void XoaHetDG(){
	for(int t=0; t<chieurongDG; t++)
	{
		XoaThongTin(chieudaiDG,5,XDocGia,YDocGia+3+t);
	}
}

void nhap_DG(PTRCNP &t, DocGia x){
    PTRCNP p;
    p=new NodeCNP;
    p->dg=x;
    if(t==NULL){
        t=p;    
        t->left=NULL;
        t->right=NULL;
        t->dg.dsmuon = NULL;
    }
    if(t->dg.MaThe > p->dg.MaThe) {
        nhap_DG(t->left,x);
    }
    else if (t->dg.MaThe < p->dg.MaThe){
        nhap_DG(t->right,x);
    }
} 

void xuat_DG1(DocGia c,int dx,int dy,int i,int mauchu){	
	string s;
	int j;
		SetColor(mauchu);
		dy=dy+i;
		gotoxy(dx+1,dy);
		cout<<c.MaThe;
		dx=	dx+chieudaiDG[0]+1;				//int chieudaiDG[5]={8,20,11,11,16};
		gotoxy(dx,dy);						//dx=13,dy=16
		cout<<c.ho; 
		dx=dx+chieudaiDG[1]+1;
		gotoxy(dx,dy);
		cout<<c.ten;
		dx=dx+chieudaiDG[2]+1;
		gotoxy(dx,dy);
		cout<<c.phai;   
		dx=dx+chieudaiDG[3]+1;
		gotoxy(dx,dy);	
		if(c.TrangThaiThe==1) s="Hoat Dong";
		else s="Bi Khoa";
		cout<<s;
}
void VeTrangDocGia(){
	VeTrang(SoTrangDocGia,TongTrangDocGia,XDocGia+TongCD_DG+1,YDocGia+3+chieurongDG-1,TIEU_DE);
}
void xuat_DG(PTRCNP* z,int dx,int dy,int n,int st){
	int j=0,d;
	PTRCNP p;
	DocGia c;
	string s;
	if(n%chieurongDG!=0) TongTrangDocGia=n/chieurongDG+1;
	else TongTrangDocGia=n/chieurongDG;
	if(z[0]==NULL){
		 VeNoiDungThongBao("Khong co noi dung",24,11,14);
		 Sleep(3000);
		 XoaNoiDungThongBao(24,11,80);
	}
	if(n<=chieurongDG)
	{
		XoaHetDG();
		for(int i=st;i<n;i++)
		{		
			xuat_DG1(z[i]->dg,dx,dy,i,4);
		}
		SoTrangDocGia=st/chieurongDG+1;
		VeTrangDocGia();
	}
	else//n>chieurongDG
	{	
		if(st+chieurongDG<n)
		{
			XoaHetDG();
			for(int i=st;i<st+chieurongDG;i++)
			{
				xuat_DG1(z[i]->dg,dx,dy,i%chieurongDG,4);
			}
		}
		else
		{
			XoaHetDG();
			for(int i=st;i<n;i++)
			{
				xuat_DG1(z[i]->dg,dx,dy,i%chieurongDG,4);
			}
		}
	}
	SoTrangDocGia=st/chieurongDG +1;
	VeTrangDocGia();
}	
void TinhSoTrangDocGia(PTRCNP t,int sl_dg){
	if(t==NULL)
	{
		TongTrangDocGia=1;
	}
	else
	{
		if(sl_dg % chieurongDG == 0)
		{
			TongTrangDocGia=(sl_dg/chieurongDG)+1;
		}
	}
}

void KiemTraDocGia(PTRCNP t,int j, int MauChu){
	SetColor(MauChu);int DiemX=90,DiemY=18;
	switch(j)
	{
		case 4:
			gotoxy(DiemX+5+cd_td[0],DiemY+4);
			cout<<t->dg.MaThe;
			break;
		case 6:
			gotoxy(DiemX+5+cd_td[1],DiemY+6);
			cout<<t->dg.ho;
			break;
		case 8:
			gotoxy(DiemX+5+cd_td[2],DiemY+8);
			cout<<t->dg.ten;
			break;
		case 10:
			gotoxy(DiemX+5+cd_td[3],DiemY+10);
			cout<<t->dg.phai;
			break;
		case 12:
			gotoxy(DiemX+5+cd_td[4],DiemY+12);
			cout<<t->dg.TrangThaiThe;
			break;
	}
}

int kiemtra_DG(DocGia x){
	if(x.dsmuon!=NULL) return 1;
	else return 0;
}
int tim_sua_DG(PTRCNP t,int ss){
	int DiemX=90,DiemY=18,j=6;
	DocGia Dg;
	int c,d;
	string s;
    if(t==NULL){
        VeNoiDungThongBao("Danh sach rong",24,11,14);
 		XoaNoiDungThongBao(24,11,80);
        XoaKhungCapNhat(90,18,13);
 //       return 0 ;
    }
    else{
        do{
            if(t->dg.MaThe==ss){
            			SetColor(NOI_DUNG);
            			XoaNoiDungThongBao(24,11,60);
            			VeNoiDungThongBao("Tim Thay Ma The",24,11,14);
            			Sleep(1000);
						VeKhungCapNhat(ThongTinDG,90,18,27,13,14,4,2);//84 x=90,18,13
            			XoaNoiDungThongBao(24,11,60);
						gotoxy(DiemX+6+cd_td[0],DiemY+4);
						cout<<t->dg.MaThe;
						gotoxy(DiemX+5+cd_td[1],DiemY+6);
						cout<<t->dg.ho;
						gotoxy(DiemX+5+cd_td[2],DiemY+8);
						cout<<t->dg.ten;
						gotoxy(DiemX+5+cd_td[3],DiemY+10);
						cout<<t->dg.phai;
						gotoxy(DiemX+5+cd_td[4],DiemY+12);
						cout<<t->dg.TrangThaiThe;
						SetColor(TIEU_DE);
						gotoxy(DiemX+5+cd_td[1],DiemY+6);
						cout<<t->dg.ho;
						while(1)
						{
							char a;
							a=getch();
							if(a==-32)
							{
								a=getch();
								if(a==Up)
								{
									if(j==6)
									{
										KiemTraDocGia(t,j,14);
										j=12;
										KiemTraDocGia(t,j,TIEU_DE);
									}
									else if(j>6 && j<=12)
									{
										KiemTraDocGia(t,j,14);
										j-=2;
										KiemTraDocGia(t,j,TIEU_DE);
									}
								}
								else if(a==Down)
								{
									if(j==12)
									{
										KiemTraDocGia(t,j,14);
										j=6;
										KiemTraDocGia(t,j,TIEU_DE);
									}
									else if(j>=6 && j<12)
									{
										KiemTraDocGia(t,j,14);
										j+=2;
										KiemTraDocGia(t,j,TIEU_DE);
									}
								}
							}
							else if(a==BackSpace)
							{
								c=wherex()-1;
								gotoxy(c,DiemY+j);
								cout<<" "; 
								cout<<"\b";
								switch(j)
								{
									case 4:
										
										break;
									case 6:
										t->dg.ho.pop_back();
										Dg.ho=CapNhatKiTuKhongSo(t->dg.ho,chieudaiDG[1],24,11,TIEU_DE,80);
										if(DieuKienKiTu!=1 && t->dg.ho!=Dg.ho)
										{
											t->dg.ho=ChuanHoaChuoi(Dg.ho);
										} 
										gotoxy(DiemX+5+cd_td[1],DiemY+j);
										cout<<"                   ";
										gotoxy(DiemX+5+cd_td[1],DiemY+j);
										cout<<t->dg.ho;
										break;
									case 8:
										t->dg.ten.pop_back();
										Dg.ten=CapNhatKiTuKhongSo1(t->dg.ten,chieudaiDG[2],24,11,TIEU_DE,80);if(DieuKienKiTu!=1 && t->dg.ten!=Dg.ten)
										{
											t->dg.ten=ChuanHoaChuoi(Dg.ten);
										} 
										gotoxy(DiemX+5+cd_td[2],DiemY+j);
										cout<<"                  ";
										gotoxy(DiemX+5+cd_td[2],DiemY+j);
										cout<<t->dg.ten;
										break;
									case 10:
										t->dg.phai.pop_back();
										while(1)
										{
											Dg.phai=CapNhatKiTuKhongSo(t->dg.phai,chieudaiDG[3],24,11,TIEU_DE,80);	
											ChuanHoaChuoi(Dg.phai);
											if(Dg.phai=="Nu") break;
											if(Dg.phai=="Nam") break;
											gotoxy(DiemX+5+cd_td[3],DiemY+j); cout<<"       ";
											gotoxy(DiemX+5+cd_td[3],DiemY+j);
										}
										if(DieuKienKiTu!=1 && t->dg.phai!=Dg.phai)
										{
											t->dg.phai=Dg.phai;
										} 
										gotoxy(DiemX+5+cd_td[3],DiemY+j);
										cout<<"     ";
										gotoxy(DiemX+5+cd_td[3],DiemY+j);
										cout<<t->dg.phai;
										break;
									case 12:
										char i;
										int k=0;
										while(1)
										{
											ShowCur(1);
											d=NhapSo1(1,DiemX+3+cd_td[4],DiemY+j,TIEU_DE,80);
											if(d!=0 && d!=1)
												{
													gotoxy(DiemX+5+cd_td[4],DiemY+j);
													cout<<" ";
													gotoxy(DiemX+5+cd_td[4],DiemY+j);
													k=0;	
												}	
											else
												{
													k=1;
													break;
												}	
										}
										t->dg.TrangThaiThe=d;
										gotoxy(DiemX+5+cd_td[4],DiemY+j);
										cout<<t->dg.TrangThaiThe;	
										break;
								}
							}
							else if(a==Esc)
							{
								VeNoiDungThongBao("Cap nhat thanh cong",24,11,4);
								Sleep(3000);
								XoaNoiDungThongBao(24,11,60);
        						XoaKhungCapNhat(90,18,13);
								break;
							}
			  			}
						
                return 1;//return 1 de kiem tra cap nhat tc
            }
            else if(t->dg.MaThe > ss) 	t=t->left;
            else	t=t->right;
		
        }while(t!=NULL);
        XoaNoiDungThongBao(24,11,60);
    	VeNoiDungThongBao("Khong Tim Thay Ma The",24,11,14);
        Sleep(1000);
        XoaNoiDungThongBao(24,11,60);
        XoaKhungCapNhat(90,18,13);
        return 0;
    }
}

DocGia  remove_case_3 ( PTRCNP &r,PTRCNP &rp )
{
  if (r->left != NULL)
     remove_case_3 (r->left,rp);
    else 
	{
	   rp->dg = r->dg;  	
	   rp = r;           	
	   r = r->right;
	}
	return rp->dg;
  }
int  tim_xoaDG( PTRCNP &t,int ss)
{
	int ktra=0;
	if (t == NULL) return ktra;
	else if(t->dg.dsmuon != NULL)
	{
		ktra=2;
		return ktra;
	}
	else
	{
		if (ss < t->dg.MaThe)   tim_xoaDG(t->left,ss);
	  	else if (ss > t->dg.MaThe) tim_xoaDG (t->right,ss);
	    else{
		    PTRCNP rp;
			rp = t;
	        if (rp->right == NULL)  t = rp->left;   
			else 	if (rp->left == NULL)
			t = rp->right; 
			else t->dg=remove_case_3 (rp->right,rp);
			delete rp;
			ktra=1;
			return ktra;
	    }
	}
}

//////////////////////////////// DO HOA
void XoaPhimDocGia(){
	XoaPhim(XDocGia-1, YDocGia+3+chieurongDG+1);
}void VePhimChucNang_DG(string x){
	XoaPhimDocGia();
	VePhim(Them, CHU, NEN_PHIM, XDocGia, YDocGia+3+chieurongDG+1);
	VePhim(CapNhat, CHU, NEN_PHIM, wherex()+3, wherey()-2);
	VePhim(Xoa, CHU, NEN_PHIM, wherex()+3, wherey()-2);
	VePhim(x, CHU, NEN_PHIM, wherex()+3, wherey()-2);
	VePhim(Thoat, CHU, NEN_PHIM, wherex()+3, wherey()-2);
	
}
DocGia NhapDocGia(int x,int y,int* ma,int dem_ma){
	DocGia c;
	int dx=x;
	string s;
	int a;
	SetColor(2);
	gotoxy(dx+1,y);
	c.MaThe=ma[dem_ma-1];
	cout<<c.MaThe;
	dx=	x+chieudaiDG[0]+1;				//int chieudaiDG[5]={8,20,11,11,16};
	gotoxy(dx,y);
	
	s=NhapKiTuKhongSo(18,24,11,2,50);
	if(DieuKienKiTu==1){
		XoaThongTinDocGia();
		return c; 
	}
	c.ho=ChuanHoaChuoi(s);
	dx=dx+chieudaiDG[1]+1;
	gotoxy(dx,y);
	
	s=NhapKiTuKhongSo(10,24,11,2,50);
	if(DieuKienKiTu==1){
		XoaThongTinDocGia();
		return c; 
	}
	c.ten=ChuanHoaChuoi(s);
	dx=dx+chieudaiDG[2]+1;
	gotoxy(dx,y);
	while(1){
		s=NhapKiTuKhongSo(3,24,11,2,50);
		s=ChuanHoaChuoi(s);
		if(DieuKienKiTu==1){
			XoaThongTinDocGia();
			return c; 
		}	
		if(s=="Nu") break;
		if(s=="Nam") break;
		for(int i=dx;i<dx+3;i++){
			gotoxy(i,y); cout<<"  ";
		}
		gotoxy(dx,y);
	//	XoaThongTinDanhMucSach();
	}
	c.phai=s;
	if(DieuKienKiTu==1){
		XoaThongTinDocGia();
		return c; 
	}
	dx=dx+chieudaiDG[3]+1;
	gotoxy(dx,y);	
	c.TrangThaiThe=1;
	cout<<"Hoat Dong";
	c.dsmuon=NULL;
	return c;	
}

//////////////////////////////////
void Docgia(PTRCNP t){
	PTRCNP *v;
	Khoitao(t);
	char j;
	string s;
	int sl_dg,x=13,y=16,dy,i=0,ss,dem=0,sort=0,dem_ma=0,kt;//vi tri dau tien cua bang
	int* ma;
	luu_MT_vao_mang(ma,dem_ma);
	VeKhungThongBao(12,10,14,72);// toa do noi dung thong bao x=24;y=11
	BangDanhSach(ThongTinDG,chieudaiDG,chieurongDG,5,2,4,12,13);//x=13,y=17
	load_DocGia(t);
	load_MuonTra(t);
	v=luu_dia_chi_vao_mang(t,sl_dg,sort);
	if(sl_dg!=0)
	{
		xuat_DG(v,x,y,sl_dg,dem);
		xuat_DG1(v[0]->dg,x,y,0,2);
	}
	VePhimChucNang_DG("F3 SORT TEN"); 
	DocGia c;
	while(1){
		ShowCur(0);
		j=getch();
		if(j==0)
		{
			j=getch();
			if(j==F1)
			{
				if(sl_dg>chieurongDG){
					XoaHetDG();
					xuat_DG(v,x,y,sl_dg,(sl_dg)/chieurongDG*chieurongDG);	
				}
				while(1)
				{
					if(sl_dg<chieurongDG) dy=y+sl_dg%chieurongDG;
					else if(sl_dg>=chieurongDG)
					{
						if(sl_dg%chieurongDG==0)
						{
							XoaHetDG();
							xuat_DG(v,x,y,sl_dg,(sl_dg)/chieurongDG*chieurongDG);	
							TongTrangDocGia=(sl_dg+1)/chieurongDG+1;
							VeTrangDocGia();
						}	
						dy=y+sl_dg%chieurongDG;
					}
					c=NhapDocGia(x,dy,ma,dem_ma);
					if(DieuKienKiTu==0)
					{
						sl_dg++;
						xoa_MT_trong_mang(ma,dem_ma);
						nhap_DG(t,c);//sl_dg	
						ghi_MT_vao_file(ma,dem_ma);
					}
					else
					{	
						XoaHetDG();
						v=luu_dia_chi_vao_mang(t,sl_dg,sort);
						xuat_DG(v,x,y,sl_dg,dem);
						dem=0;
						xuat_DG(v,x,y,sl_dg,dem);
						xuat_DG1(v[dem]->dg,x,y,dem,2);
						break;
					} 	
				}
				XoaHetDG();
				dem=0;
				xuat_DG(v,x,y,sl_dg,dem);
				save_DocGia(t);
				save_MuonTra(t);			
			}
			else if(j==F2)
			{
				if(sl_dg==0)
				{VeNoiDungThongBao("CHUA CO DU LIEU DOC GIA DE CAP NHAT",24,11,2);
					Sleep(1000);
					XoaNoiDungThongBao(24,11,60);
				}
				else
				{
					VeKhungChinhSua("CHINH SUA DOC GIA", "Ma The: ",90,18,14,2,20);
					ss=NhapSo(6,24,11,4,50);
					XoaKhungChinhSua(90,18);
					i=0,kt=0;
					while(i<sl_dg)
					{
						if(v[i]->dg.MaThe==ss)
						{
							kt=1;
							break;
						} 
						i++;
					}
					if(kt)
					{
						if(((dem/chieurongDG*chieurongDG)<=i) && (i<(dem/chieurongDG*chieurongDG+chieurongDG)))
						{
							xuat_DG1(v[dem]->dg,x,y,dem%chieurongDG,4);
							xuat_DG1(v[i]->dg,x,y,i%chieurongDG,2);
						}
						else
						{
							XoaHetDG();
							xuat_DG(v,x,y,sl_dg,i/chieurongDG*chieurongDG);
							xuat_DG1(v[i]->dg,x,y,i%chieurongDG,2);
						}
						dem=i;
					}
					i=tim_sua_DG(t,ss);
					if(i)
					{
						XoaThongTinDocGia1(x,y,dem%chieurongDG);
						xuat_DG1(v[dem]->dg,x,y,dem%chieurongDG,2);
					}
					else
					{
					}
					save_DocGia(t);
					save_MuonTra(t);
				}	
			}
			else if(j==F3)
			{
				if(sl_dg==0)
				{
					VeNoiDungThongBao("CHUA CO DU LIEU DOC GIA DE SAP XEP",24,11,2);
					Sleep(1000);
					XoaNoiDungThongBao(24,11,60);
				}
				else
				{
					sort++;
					v=luu_dia_chi_vao_mang(t,sl_dg,sort);
					dem=0;
					xuat_DG(v,x,y,sl_dg,dem);
					dem=0;
					xuat_DG(v,x,y,sl_dg,dem);
					if(sort%2==0)
					{
						VePhimChucNang_DG("F3 SORT TEN");
					}
					else VePhimChucNang_DG("F3 SORT MA");
				}
				
			}
		}
		if(j==-32)
		{
			j=getch();
			if(j==Delete)
			{
				if(sl_dg==0)
				{
					VeNoiDungThongBao("CHUA CO DU LIEU DOC GIA DE XOA",24,11,2);
					Sleep(1000);
					XoaNoiDungThongBao(24,11,60);
				}
				else
				{
					VeKhungChinhSua("XOA DOC GIA", "Ma The: ",90,18,14,2,20);
					ss=NhapSo(6,24,11,4,50);
					XoaKhungChinhSua(90,18);
					kt=0;
					i=0;
					while(i<sl_dg-1)
					{
						if(v[i]->dg.MaThe==ss)
						{
							kt=1;
							break;
						} 
						i++;
					}
					if(kt==1)
					{
						if(dem/chieurongDG*chieurongDG<=i && i<dem/chieurongDG*chieurongDG+chieurongDG)
						{
							xuat_DG1(v[dem]->dg,x,y,dem%chieurongDG,4);
							xuat_DG1(v[i]->dg,x,y,i%chieurongDG,2);
						}
						else
						{
							XoaHetDG();
							xuat_DG(v,x,y,sl_dg,i/chieurongDG*chieurongDG);
							xuat_DG1(v[i]->dg,x,y,i%chieurongDG,2);
						}
						dem=i;
					}
					kt=tim_xoaDG(t,ss);
					if(kt==0)
					{
						VeNoiDungThongBao("MA THE KHONG TON TAI",24,11,2);
						Sleep(1000);
						XoaNoiDungThongBao(24,11,50);
					}
					else if(kt==2)
					{
						VeNoiDungThongBao("KHONG THE XOA DOC GIA DA MUON SACH",24,11,2);
						Sleep(2000);
						XoaNoiDungThongBao(24,11,60);
					}
					else if(kt==1) 
					{
						VeNoiDungThongBao("XOA MA THE THANH CONG",24,11,2);
						them_MT_trong_mang(ma,dem_ma,ss);
						ghi_MT_vao_file(ma,dem_ma);	
						Sleep(1000);
						XoaNoiDungThongBao(24,11,50);
						XoaHetDG();
						sl_dg--;v=luu_dia_chi_vao_mang(t,sl_dg,sort);
						if(dem>sl_dg) dem=sl_dg;
						xuat_DG(v,x,y,sl_dg,(dem)/chieurongDG*chieurongDG);
						xuat_DG1(v[dem]->dg,x,y,dem,2);
					}
					save_DocGia(t);	
					save_MuonTra(t);
				}	
			}
			else if(j==Up)
			{
			dem--;
			if(sl_dg<=chieurongDG)
			{
				if(dem<0)
				{
					dem=sl_dg;
					xuat_DG1(v[0]->dg,x,y,0,4);
					xuat_DG1(v[dem-1]->dg,x,y,dem-1,2);
				}
				else if(dem==sl_dg-1){
					dem--;
					xuat_DG1(v[dem]->dg,x,y,dem,2);
					xuat_DG1(v[dem+1]->dg,x,y,dem+1,4);
				}
				else
				{
					xuat_DG1(v[dem]->dg,x,y,dem,2);
					xuat_DG1(v[dem+1]->dg,x,y,dem+1,4);
				}
			}
			else
			{
				TongTrangDocGia=sl_dg/chieurongDG;
				if(dem<0)
				{	
					xuat_DG(v,x,y,sl_dg,TongTrangDocGia*chieurongDG);
					dem=sl_dg-1;
					xuat_DG1(v[dem]->dg,x,y,dem%chieurongDG,2);
				}
				else if(dem%chieurongDG==19)
				{		
				int k=dem-chieurongDG+1;
					XoaHetDG();
					xuat_DG(v,x,y,sl_dg,k);
					xuat_DG1(v[dem]->dg,x,y,dem%chieurongDG,2);
				}
				else if(dem%chieurongDG!=19)
				{
					xuat_DG1(v[dem]->dg,x,y,dem%chieurongDG,2);
					xuat_DG1(v[dem+1]->dg,x,y,(dem+1)%chieurongDG,4);	
				}
			}
			}
			else if(j==Down)
			{
				if(dem==0)
				{
					xuat_DG1(v[dem]->dg,x,y,dem,2);
				}
				dem++;
				if(sl_dg<=chieurongDG)
				{
					if(dem==0)
					{
						xuat_DG1(v[dem]->dg,x,y,dem,2);
						xuat_DG1(v[sl_dg-1]->dg,x,y,sl_dg-1,4);
					}
					else if(dem>sl_dg-1)
					{
						dem=0;
						xuat_DG1(v[dem]->dg,x,y,dem,2);
						xuat_DG1(v[sl_dg-1]->dg,x,y,sl_dg-1,4);
					}
					else
					{
						xuat_DG1(v[dem]->dg,x,y,dem,2);
						xuat_DG1(v[dem-1]->dg,x,y,dem-1,4);
					}
				}
				else
				{
					if(dem%chieurongDG==0)
					{
						xuat_DG(v,x,y,sl_dg,dem);
						xuat_DG1(v[dem]->dg,x,y,(dem)%chieurongDG,2);
					}
					else if(dem>sl_dg-1)
					{
						dem=0;
						xuat_DG(v,x,y,sl_dg,dem);
						xuat_DG1(v[0]->dg,x,y,0,2);
					}
					else 
					{
						xuat_DG1(v[dem-1]->dg,x,y,(dem-1)%chieurongDG,4);
						xuat_DG1(v[dem]->dg,x,y,(dem)%chieurongDG,2);
					}
				}
			}
	}
		if(j==27)
		{
			XoaBangDanhSach();
			delete []v;
			save_DocGia(t);
			return;
		} 
	}
}
#endif
