#ifndef DEFINE_H
#define DEFINE_H
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream> 
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <windows.h>
#include <sstream>
#include <vector>
#include "KhaiBao.h"
#include "mylib.h"
#define CHU 5
#define NEN_GOC 2
#define NEN_CHON 4
#define KHUNG 3
#define TIEU_DE 12
#define	NOI_DUNG 6
#define NEN_PHIM 3
#define Ngang2 205
#define Doc2 186
#define Ngang1 196
#define Doc1 179

using namespace std;

const int Left=75;
const int Right=77; 
const int Up=72;
const int Down=80;
const int BackSpace=8;
const int Space=32;

const int F1=59;	//THEM - 0
string Them="F1  THEM";
const int F2=60;	//CAP NHAT - 0
string CapNhat="F2  CAP NHAT";
const int Delete=83;	//XOA - -32
string Xoa="DELETE  XOA";
const int F3=61;	//DMS - 0
string DanhMucSach="F3  DANH MUC SACH";
const int Esc=27;
string Thoat="ESC  THOAT";

const int GocX=0;
const int GocY=10;
int DieuKienKiTu=0; 
int DieuKienISBN=0;
string KhongCoThongTin="Khong Tim Thay Thong Tin Trong Danh Sach";
string Rong="Danh Sach Chua Co Thong Tin";
string LoiKhongHopLe="Thong Tin Khong Hop Le";
string LoiTrung="Thong Tin Da Co Trong Danh Sach";
string LoiTrong="Thong Tin Khong Duoc De Trong";
string QuyDinhNhapSo="Chi nhap cac ky tu 0 - 9";
string QuyDinhNhapChu="Chi nhap cac ky tu A - Z, Khong phan biet chu hoa va chu thuong";
string QuyDinhNhapChuSo="Nhap cac ky tu 0 - 9; A - Z (Khong phan biet chu hoa va chu thuong); Cac ky tu !, ?, &...";
string QuyDinhNhapISBN="Nhap du 4 ky tu, Gom cac ky tu A - Z";


string MenuThuVien[3]={"DAU SACH",
                       "DOC GIA",
                       "THOAT"};
int ViTriMenuThuVien[3][2]={
								{84,15},
								{84,21},
								{84,27}
						   }; 
						   
////	DAU SACH
string MenuDauSach[4]={"THEM/SUA/XOA",
					   "TIM DAU SACH",
					   "10 DAU SACH DUOC MUON NHIEU NHAT",
					   "QUAY LAI"
					  };
int ViTriMenuDauSach[4][2]={
								{3,5},
								{51,5},
								{99,5},
								{147,5}
						   }; 
string MenuDocGia[5]={"THEM/SUA/XOA",
					  "MUON/TRA SACH",
					  "CAC SACH 1 DOC GIA DANG MUON",
					  "DOC GIA MUON SACH QUA HAN",
					  "QUAY LAI"
					 };
int ViTriMenuDocGia[5][2]={
								{9,5},
								{44,5},
								{79,5},
								{114,5},
								{149,5}
						  };
						  
						  
								//////		DAU SACH	//////
string ThongTinDauSach[6]={"Ma ISBN",
						   "Ten Sach",
						   "So Trang",
						   "Tac Gia",
						   "NXB",
						   "The Loai"
						  };
int TongThongTinDauSach=6;


int ChieuDaiDauSach[6]={9,40,10,35,5,20};
int ChieuRongDauSach=20;
int TinhCDDauSach(){
	int a=1;
	for(int i=0; i<6; i++)
	{
		a+=ChieuDaiDauSach[i]+1;
	}
	return a;
}
int TongCDDauSach=TinhCDDauSach();


int XDauSach=GocX+1;
int YDauSach=GocY+3;


int CDKhungThongBaoDauSach=80;
int XThongBaoDauSach=GocX+17;
int YThongBaoDauSach=GocY+1;


int TongTrangDauSach=1;
int SoTrangDauSach=1;

								//////		DANH MUC SACH	//////
string ThongTinDanhMucSach[3]={"Ma Sach",
							   "Trang Thai",
							   "Vi Tri"
							  };
int TongThongTinDanhMucSach=3;


int ChieuDaiDanhMucSach[3]={15,15,25};
int ChieuRongDanhMucSach=20;
int TinhCDDanhMucSach(){
	int a=1;
	for(int i=0; i<TongThongTinDanhMucSach; i++)
	{
		a+=ChieuDaiDanhMucSach[i]+1;
	}
	return a;
}
int TongCDDanhMucSach=TinhCDDanhMucSach();


int XDanhMucSach=GocX+65;
int YDanhMucSach=GocY+3;

//// Chu va khung thong bao cach nhau 12 o
int CDKhungThongBaoDanhMucSach=80;
int XThongBaoDanhMucSach=GocX+62;
int YThongBaoDanhMucSach=GocY+1;

int TongTrangDanhMucSach=1;
int SoTrangDanhMucSach=1;


								//////		TIM DAU SACH	//////
string ThongTinTimDauSach[2]={"Ma Sach", "Trang Thai"};
int TongThongTinTimDauSach=2;

int ChieuDaiTimDauSach[2]={15,15};
int ChieuRongTimDauSach=20;
int TongCDTimDauSach=33;

int XTimDauSach=GocX+80;
int YTimDauSach=GocY+6;

int TongTrangTimDauSach=1;
int SoTrangTimDauSach=1;

int CDKhungThongBaoTimDauSach=80;
int XThongBaoTimDauSach=GocX+62;
int YThongBaoTimDauSach=GocY+10;


int SoTrangDocGia=1;
int TongTrangDocGia=1;
int chieudaiDG[5]={8,20,11,11,16};
int XDocGia=12;
int YDocGia=13;
int cd_td[5]={5,2,3,9,14};
int chieurongDG=20;
int TinhCD_DocGia(){
	int a=1;
	for(int i=0; i<5; i++)
	{
		a+=chieudaiDG[i]+1;
	}
	return a;
}
int TongCD_DG=TinhCD_DocGia();
string ThongTinDG[5]={"MA THE",
						"HO",
						"TEN",
						"GIOI TINH",
						"TRANG THAI THE"
};
int ViTriThongTinDG[5][2]={
								{9,5},
								{44,5},
								{79,5},
								{114,5},
								{149,5}
								
};
#endif

