#ifndef MUONTRADOCGIA_H
#define MUONTRADOCGIA_H

#include <iostream>
#include <ctime>
#include "mylib.h"
#include "KhaiBao.h" 
#include "Define.h"
#include "GiaoDien.h"
#include "SaveLoadFile.h"


using namespace std;

bool KT_trung_DS(DocGia t, string ma)
{
	PTRMT p = t.dsmuon;
	for (p; p!= NULL; p = p->next)
	{
		if ((!p->mt.MaSach.compare(0,4,ma)) && (p->mt.TrangThai == 0)) return true;
	}
	return false;	
}

int KT_3_cuon(DocGia Dgia)
{
	PTRMT Mtra;
	int count = 0;
	if (Dgia.dsmuon != NULL)
	{
		for (Mtra = Dgia.dsmuon; Mtra != NULL; Mtra = Mtra->next)
		{
			if (Mtra->mt.TrangThai == 0)
			{
				count++;
			}
		}
	}
	return count;
}

void lay_ngay(Date &d)
{
	time_t t = time(0);
	tm *ltm = localtime(&t);
	d.ngay = ltm->tm_mday;
	d.thang = 1 + ltm->tm_mon;
	d.nam = 1900 + ltm->tm_year;
}

bool KT_nhuan(int y)
{
	if ((y%400 == 0) || ((y%4 == 0) && (y%100 != 0))) return true;
	return false; 
}

int ngaytudauthanh(int d)
{
	if (d == 1) return 1;
	else return d;
}

int songaythang(int m, int y)
{
	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			if (KT_nhuan(y)) return 29;
			else return 28;
			break;
	}
}

int songay_tudaunam(Date d)
{
	if (d.thang == 1){
		if (d.ngay == 1) return 0;
		else return d.ngay;
	}else{
		int count = 0;
		for (int i = 1; i < d.thang;i++)
		{
			count += songaythang(i, d.nam);
		}
		count += ngaytudauthanh(d.ngay);
		return count;
	}
}

int so_ngay_muon(Date d)
{
	int count = 0;
	Date now;
	lay_ngay(now);
	if (d.nam != now.nam){
		for (int i = d.nam; i < now.nam; i++)
		{
			if (KT_nhuan(i)) count += 366;
			else count += 365;
		}
		count += songay_tudaunam(now);
		if (KT_nhuan(d.nam))count += 366 - songay_tudaunam(d);
		else count += 365 - songay_tudaunam(d);
	}else{
		count = songay_tudaunam(now) - songay_tudaunam(d);
	}
	return count;
}

bool KT_Qua_Han(PTRMT dsmt)
{
	for (dsmt; dsmt != NULL; dsmt = dsmt->next)
	{
		if (so_ngay_muon(dsmt->mt.NgayMuon) >= 7 && dsmt->mt.TrangThai == 0) return true;
	}
	return false;
}

void Bang_DSM(int x, int y)
{
	Box(x, y, 6, 4, Doc1, Ngang1);
	Box(x+6, y, 12, 4, Doc1, Ngang1);
	Box(x+18, y, 40, 4, Doc1, Ngang1);
	Box(x+58, y, 12, 4, Doc1, Ngang1);
	Box(x, y+4, 6, 6, Doc1, Ngang1);
	Box(x+6, y+4, 12, 6, Doc1, Ngang1);
	Box(x+18, y+4, 40, 6, Doc1, Ngang1);
	Box(x+58, y+4, 12, 6, Doc1, Ngang1);
	
	for (int i = x; i <= x+70; i++)
	{
		gotoxy(i, y); cout <<char(Ngang2);
		gotoxy(i, y+10); cout <<char(Ngang2);
	}
	for (int i = y; i <= y+10; i++)
	{
		gotoxy(x, i); cout <<char(Doc2);
		gotoxy(x+70, i); cout <<char(Doc2);
	}
	gotoxy(x, y); cout <<char(201);
	gotoxy(x, y+10); cout <<char(200);
	gotoxy(x+70, y); cout <<char(187);
	gotoxy(x+70, y+10); cout <<char(188);
	
	gotoxy(x, y+4); cout <<char(199);
	gotoxy(x+70, y+4); cout <<char(182);
	gotoxy(x+6, y+4); cout <<char(197);
	gotoxy(x+18, y+4); cout <<char(197);
	gotoxy(x+58, y+4); cout <<char(197);
	
	gotoxy(x+6, y); cout <<char(209);
	gotoxy(x+18, y); cout <<char(209);
	gotoxy(x+58, y); cout <<char(209);
	gotoxy(x+6, y+10); cout <<char(207);
	gotoxy(x+18, y+10); cout <<char(207);
	gotoxy(x+58, y+10); cout <<char(207);
	
	SetColor(10);
	gotoxy(x+2, y+2); cout <<"STT";
	gotoxy(x+9, y+2); cout <<"MA SACH";
	gotoxy(x+34, y+2); cout <<"TEN SACH";
	gotoxy(x+61, y+2); cout <<"SO NGAY";
	gotoxy(x+62, y+3); cout <<"MUON";
}

void sort_ngaymuon(PTRMT &Mt)//Selection
{
	PTRMT p, q, pmax;
	MuonTra max;
	for (p = Mt; p->next != NULL; p = p->next)
	{
		max = p->mt;
		pmax = p;
		for (q = p->next; q != NULL; q = q->next)
		{
			if (so_ngay_muon(max.NgayMuon) < so_ngay_muon(q->mt.NgayMuon)){
				max = q->mt;
				pmax = q;
			}
		}
		pmax->mt = p->mt;
		p->mt = max;
	}
}

string Tim_tensach(string masach, List Dsach)
{
	for (int i = 0; i < Dsach.n; i++)
	{
		if (!masach.compare(0,4,Dsach.node[i]->ISBN))
		{
			return Dsach.node[i]->TenSach;
		}
	}
}

void sach_dang_muon(DocGia Dgia, List Ds)
{
	int x = 56, y = 18;
	PTRMT Mt;
	int i = 1;
	SetColor(0);
	Bang_DSM(x,y);
	SetColor(9);
	if (Dgia.dsmuon != NULL)
	{
		Mt = Dgia.dsmuon;
		sort_ngaymuon(Mt);
		for (Mt; Mt != NULL; Mt = Mt->next)
		{
			if (Mt->mt.TrangThai == 0)
			{
				gotoxy(x+3, y+(i*2) + 3);
				cout <<i;
				gotoxy(x+9, y+(i*2) + 3);
				cout <<Mt->mt.MaSach;
				gotoxy(x+19, y+(i*2) + 3);
				cout <<	Tim_tensach(Mt->mt.MaSach, Ds);
				gotoxy(x+63, y+(i*2) + 3);
				cout <<so_ngay_muon(Mt->mt.NgayMuon);
				i++;
			}
		}
	}
	SetColor(1);
	Box_mau(x+4, y+11, 18, 2, 11);
	gotoxy(x+6, y+12); cout <<"F2 - MUON SACH";
	Box_mau(x+27, y+11, 17, 2, 11);
	gotoxy(x+29, y+12); cout <<"F3 - TRA SACH";
	Box_mau(x+49, y+11, 16, 2, 11);
	gotoxy(x+51, y+12); cout <<"F4 - BAO MAT";
	Normal();
}  

void xoa_1_SDM(int vt)
{
	int x = 56, y = 18;
	SetColor(1); 
	for (int i = x+1; i < x+60; i++){
		gotoxy(i, y+(vt*2)+3);
		cout <<" ";
	}
	SetColor(0);
	gotoxy(x+6, y+(vt*2)+3); cout <<char(Doc1);
	gotoxy(x+18, y+(vt*2)+3); cout <<char(Doc1);
	gotoxy(x+58, y+(vt*2)+3); cout <<char(Doc1);
	SetColor(15);
}

void In_1_SDM(PTRMT p, List Ds, int vt)
{
	if (p == NULL) return;
	int x = 56, y = 18;
	gotoxy(x+3, y+(vt*2) + 3);
	cout <<vt;
	gotoxy(x+9, y+(vt*2) + 3);
	cout <<p->mt.MaSach;
	gotoxy(x+19, y+(vt*2) + 3);
	cout <<	Tim_tensach(p->mt.MaSach, Ds);
	gotoxy(x+63, y+(vt*2) + 3);
	cout <<so_ngay_muon(p->mt.NgayMuon);
}

int convert(char c)
{
	switch(c)
	{
		case  48:
			return 0;
		case 49:
			return 1;
		case 50:
			return 2;
		case 51:
			return 3;
		case 52:
			return 4;
		case 53:
			return 5;
		case 54:
			return 6;
		case 55:
			return 7;
		case 56:
			return 8;
		case 57:
			return 9;
	}
}

PTRCNP Tim_DG(int mathe, PTRCNP t)
{
	while (t != NULL && mathe != t->dg.MaThe)
	{
		if (mathe < t->dg.MaThe){
			t = t->left;
		}else t = t->right;
	}
	return t;
} 

void thong_bao(int x, int y)
{
	SetColor(10);
	for (int i = x; i <= x+50; i++)
	{
		gotoxy(i, y); cout <<char(Ngang1);
		gotoxy(i, y+2); cout <<char(Ngang1);
	}
	for (int i = y; i <= y+2; i++)
	{
		gotoxy(x, i); cout <<char(Doc1);
		gotoxy(x+50, i); cout <<char(Doc1);
	}
	gotoxy(x, y); cout <<char(218);
	gotoxy(x, y+2); cout <<char(192);
	gotoxy(x+50, y); cout <<char(191);
	gotoxy(x+50, y+2); cout <<char(217);
	SetColor(10);
	gotoxy(x+1, y+1); cout <<"NOTIFICATION: ";//x = 56, y=10;
	SetColor(15);
}

void xoa_TB(int x, int y)
{
	SetBGColor(1);
	for(int i = x+16; i < x+50;i++)
	{
		gotoxy(i, y+1); cout <<" ";
	}
}

void Khung_Nhap(int x, int y, string nd)
{
	SetBGColor(13);
	for (int i = x; i <= x+33; i++)
	{
		for (int j = y; j <= y+6; j++)
		{
			gotoxy(i, j);
			cout <<" ";
		}
	}
	SetColor(9);
	gotoxy(x+(33-nd.length())/2,y+1); cout <<nd;
	for (int i = x+11; i <= x+22; i++)
	{
		gotoxy(i, y+2); cout <<"~";
	}
	
	SetBGColor(1);
	for (int i = x+2; i <= x+31; i++)
	{
		for (int j = y+3; j <= y+4; j++)
		{
			gotoxy(i, j); cout <<" ";
		}
	}
	gotoxy(x+14, y+4);
}

void InfoDG(DocGia Dg, int x, int y)
{ 
	SetColor(0);
	Box(x, y-3, 35, 2, Doc2, Ngang2);
	SetColor(9);
	gotoxy(x+9, y-2); cout <<"THONG TIN DOC GIA";
	SetColor(10);
	gotoxy(x+1, y+1); cout <<"Ma the";
	gotoxy(x+1, y+3); cout <<"Ho & Ten";
	gotoxy(x+1, y+5); cout <<"Gioi tinh";
	gotoxy(x+1, y+7); cout <<"Trang thai the";
	SetColor(9);
	gotoxy(x+17, y+1); cout <<":"<<Dg.MaThe;
	gotoxy(x+17, y+3); cout <<":"<<Dg.ho<<" "<<Dg.ten;
	gotoxy(x+17, y+5); cout <<":"<<Dg.phai;
	gotoxy(x+17, y+7); 
	if (Dg.TrangThaiThe == 1) cout <<":"<<"DANG HOAT DONG";
	else cout <<":"<<"BI KHOA";
}

int so_luot_muon(string ma, PTRCNP t)
{
	if (t == NULL){
		return 0;
	}else{
		int count = 0;
		if (t->dg.dsmuon != NULL){
			PTRMT dsmt = t->dg.dsmuon;
			for (dsmt; dsmt != NULL; dsmt = dsmt->next)
			{
				if(!dsmt->mt.MaSach.compare(0,4, ma)) count++;	
			}
		}
		return count + so_luot_muon(ma, t->left) + so_luot_muon(ma, t->right);
	}
}

char Uper(char a)
{
	if (a >= 97 && a <= 122)
	{
		return (a-32);
	}
}

void Bang_DS()
{
	SetColor(9);
	int x = 1, y = 12;
	Box(x, y, 6, 4, Doc1, Ngang1);
	Box(x+6, y, 10, 4, Doc1, Ngang1);
	Box(x+16, y, 40, 4, Doc1, Ngang1);
	Box(x+56, y, 36, 4, Doc1, Ngang1);
	Box(x+92, y, 21, 4, Doc1, Ngang1);
	Box(x+113, y, 11, 4, Doc1, Ngang1);
	Box(x+124, y, 10, 4, Doc1, Ngang1);
	
	Box(x, y+4, 6, 31, Doc1, Ngang1);
	Box(x+6, y+4, 10, 31, Doc1, Ngang1);
	Box(x+16, y+4, 40, 31, Doc1, Ngang1);
	Box(x+56, y+4, 36, 31, Doc1, Ngang1);
	Box(x+92, y+4, 21, 31, Doc1, Ngang1);
	Box(x+113, y+4, 11, 31, Doc1, Ngang1);
	Box(x+124, y+4, 10, 31, Doc1, Ngang1);
	
	for (int i = x; i <= x+134; i++)
	{
		gotoxy(i, y); cout <<char(Ngang2);
		gotoxy(i, y+35); cout <<char(Ngang2);
	}
	for (int i = y; i <= y+35; i++)
	{
		gotoxy(x, i); cout <<char(Doc2);
		gotoxy(x+134, i); cout <<char(Doc2);
	}
	gotoxy(x, y); cout <<char(201);
	gotoxy(x, y+35); cout <<char(200);
	gotoxy(x+134, y); cout <<char(187);
	gotoxy(x+134, y+35); cout <<char(188);
	
	gotoxy(x, y+4); cout <<char(199);
	gotoxy(x+134, y+4); cout <<char(182);
	
	gotoxy(x+6, y+4); cout <<char(197);
	gotoxy(x+16, y+4); cout <<char(197);
	gotoxy(x+56, y+4); cout <<char(197);
	gotoxy(x+92, y+4); cout <<char(197);
	gotoxy(x+113, y+4); cout <<char(197);
	gotoxy(x+124, y+4); cout <<char(197);
	
	gotoxy(x+6, y); cout <<char(209);
	gotoxy(x+16, y); cout <<char(209);
	gotoxy(x+56, y); cout <<char(209);
	gotoxy(x+92, y); cout <<char(209);
	gotoxy(x+113, y); cout <<char(209);
	gotoxy(x+124, y); cout <<char(209);

	gotoxy(x+6, y+35); cout <<char(207);
	gotoxy(x+16, y+35); cout <<char(207);
	gotoxy(x+56, y+35); cout <<char(207);
	gotoxy(x+92, y+35); cout <<char(207);
	gotoxy(x+113, y+35); cout <<char(207);
	gotoxy(x+124, y+35); cout <<char(207);
	SetColor(10);
	gotoxy(x+2, y+2); cout <<"STT";
	gotoxy(x+6+2, y+2); cout <<"MA ISBN";
	gotoxy(x+16+16, y+2); cout <<"TEN SACH";
	gotoxy(x+56+14, y+2); cout <<"TAC GIA";
	gotoxy(x+92+6, y+2); cout <<"THE LOAI";
	gotoxy(x+113+4, y+2); cout <<"NAM";
	gotoxy(x+113+2, y+3); cout <<"XUAT BAN";
	gotoxy(x+124+2, y+2); cout <<"SO LUOT";
	gotoxy(x+124+3, y+3); cout <<"MUON";	
	Normal();
}

void Quick_Sort_LM(List &DSach, PTRCNP t, int q, int r)
{
	DauSach *DS;
	int i = q, j = r, x = 0, a, b;
	x = so_luot_muon(DSach.node[(q+r)/2]->ISBN, t);
	do{
		while((a = so_luot_muon(DSach.node[i]->ISBN, t)) > x) i++;
		while ((b = so_luot_muon(DSach.node[j]->ISBN, t)) < x) j--;
		if (i <= j)
		{
			DS = DSach.node[i];
			DSach.node[i] = DSach.node[j];
			DSach.node[j] = DS; 
			i++; j--;
		}
	}while(i <= j);
	if (q < j) Quick_Sort_LM(DSach, t, q, j);
	if (i < r) Quick_Sort_LM(DSach, t, i, r);
}

void In_30_DS(List DSach, PTRCNP t, int sl, int st)
{
	SetColor(9);
	int x = 2, y =17;
	int slm;
	for (int i = 30*(st-1); i < sl; i++)
	{
		gotoxy(x+2, y+i-30*(st-1)); cout <<i+1;
		gotoxy(x+6+2, y+i-30*(st-1)); cout <<DSach.node[i]->ISBN;
		gotoxy(x+16, y+i-30*(st-1)); cout <<DSach.node[i]->TenSach;
		gotoxy(x+56, y+i-30*(st-1)); cout <<DSach.node[i]->TacGia;
		gotoxy(x+92, y+i-30*(st-1)); cout <<DSach.node[i]->TheLoai;
		gotoxy(x+113+3, y+i-30*(st-1)); cout <<DSach.node[i]->NamXuatBan;
		gotoxy(x+124+4, y+i-30*(st-1)); cout <<so_luot_muon(DSach.node[i]->ISBN, t);	
	}
}

void HD_Bang_DS(int st, int so_trang)
{
	SetColor(9);
	int x = 1, y = 12;
	gotoxy(x+2, y+36); cout <<"Trang truoc  "<<char(60)<<char(196);
	gotoxy(x+2+16, y+36); cout <<char(196)<<char(62)<<"  Trang sau";
	gotoxy(x+113, y+36); cout <<"Trang "<<st<<" / "<<so_trang;
}

bool KT_Ma_DS(List DSach, string Ma)
{
	for (int i = 0; i < DSach.n; i++)
	{
		if (!Ma.compare(0, 4, DSach.node[i]->ISBN)) return true;
	}
	return false;
}

bool KT_Het_Sach(List DSach, string Masach)
{
	int i = 0;
	while (i < DSach.n)
	{
		if (!Masach.compare(DSach.node[i]->ISBN)) break;
		else i++;
	}
	PTRDMS p;
	if (DSach.node[i]->dms != NULL)
	{
		for (p = DSach.node[i]->dms; p != NULL; p = p->ptnext)
		{
			if(p->dm.TrangThaiSach == 0) return false;
		}
	}
	return true;
}

void In_DG(DocGia p, List DSach)
{
	sach_dang_muon(p,DSach);
    thong_bao(56, 14);
    ShowCur(0);
	InfoDG(p, 8, 21);
	Normal();
}

string NhapMaSach(int Mathe, List DSach, PTRCNP DGia)
{
	string Ma, tmp;
	int x = 146, y = 17;
	Bang_DS();
	Khung_Nhap(x, y, "NHAP MA SACH MUON MUON");
	thong_bao(x-9, y+8);
	Quick_Sort_LM(DSach, DGia, 0, DSach.n-1);
	int slm;
	float so_trang;
	if (DSach.n%30 != 0) so_trang = DSach.n/30 +1;
	else so_trang = DSach.n/30;
	if (DSach.n == 0){
		SetColor(10);
		gotoxy(x+16, y+5+1); cout <<"DANH SACH DAU SACH RONG!";
		Sleep(2000);
		XoaBangDanhSach();
		return Ma;
		SetColor(15);
	}
	if (so_trang == 1)
	{
		In_30_DS(DSach, DGia, DSach.n, 1);
		HD_Bang_DS(1,1);
	}else{
		In_30_DS(DSach, DGia, 30, 1);
		HD_Bang_DS(1,so_trang);
	}
	gotoxy(x+14, y+4);
	int count = 0;
	int st = 1;
	char c;
	PTRCNP p = Tim_DG(Mathe, DGia);
	ShowCur(1);
	while (true){
		while(_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 77)//->
				{
					XoaBangDanhSach();
					st++;
					Bang_DS();
					thong_bao(x-9, y+8);
					Khung_Nhap(x, y, "NHAP MA SACH MUON MUON");
					if (st <= so_trang)
					{
						HD_Bang_DS(st, so_trang);
						if (st == so_trang)
						{
							In_30_DS(DSach, DGia, DSach.n, st);
						}else{
							In_30_DS(DSach, DGia, 30*st, st);
						}
					}else{
						st = 1;
						HD_Bang_DS(1,1);
						In_30_DS(DSach, DGia, 30, st);
					}
					gotoxy(x+14, y+4);
				}else if (c == 75)//<-
				{
					XoaBangDanhSach();
					st--;
					Bang_DS();
					thong_bao(x-9, y+8);
					Khung_Nhap(x, y, "NHAP MA SACH MUON MUON");
					if (st >= 1){
						HD_Bang_DS(st, so_trang);
						In_30_DS(DSach, DGia, 30*st, st);
					}else{
						st = so_trang;
						HD_Bang_DS(st, so_trang);
						In_30_DS(DSach, DGia, DSach.n, st);
					}
					gotoxy(x+14, y+4);
				}else break;
			}else{
				if (((c <= 122 && c >= 97) || (c <= 90 && c >= 65)) && count < 4)
				{
					c = Uper(c);
					cout <<c;
					Ma += c;
					count ++;
				}else if (c == 8 && count != 0) //backspace
				{
					cout <<"\b \b"; 
					count --;
					tmp = "";
					for (int i = 0; i < count; i++)
					{
						tmp += Ma[i];
					}
					Ma = tmp;
				}else if (c == 27) {//escape
					XoaBangDanhSach();
					In_DG(p->dg, DSach);
					return Ma;
				}else if (c == 13 && count == 4) {//enter
					if (KT_trung_DS(p->dg, Ma)){
						ShowCur(0); SetColor(10);
						gotoxy(x-9+16, y+8+1); cout <<"MA SACH BI TRUNG!";
						Sleep(2000); xoa_TB(x-9,y+8);
						SetColor(9); ShowCur(1);
						gotoxy(x+14+4, y+4);
						break;
					}else if(!KT_Ma_DS(DSach, Ma)){
						ShowCur(0); SetColor(10);
						gotoxy(x-9+16, y+8+1); cout <<"MA SACH KHONG TON TAI!";
						Sleep(2000); xoa_TB(x-9, y+8);
						SetColor(9); ShowCur(1);
						gotoxy(x+14+4, y+4);
						break;
					}else if (KT_Het_Sach(DSach, Ma)){
						ShowCur(0); SetColor(10);
						gotoxy(x-9+16, y+8+1); cout <<"SACH MUON MUON DA HET!";
						Sleep(2000); xoa_TB(x-9,y+8);
						SetColor(9); ShowCur(1);
						gotoxy(x+14+4, y+4);
					}else return Ma;
				}
			}
		}
	}
}

void Muon_Sach(int Mathe, string Ma, List &DSach, PTRCNP &DGia)
{
	int i = 0;
	while (i < DSach.n)
	{
		if (!Ma.compare(DSach.node[i]->ISBN)) break;
		else i++;
	}
	string a = "SACH BAN MUON MUON DANG O ";
	PTRCNP p = Tim_DG(Mathe, DGia);
	MuonTra dsmt;
	PTRDMS dmsach;
	if (DSach.node[i]->dms != NULL){
		for (dmsach = DSach.node[i]->dms; dmsach != NULL; dmsach = dmsach->ptnext)
		{
			if (dmsach->dm.TrangThaiSach == 0)
			{
				dsmt.MaSach = dmsach->dm.MaSach;
				lay_ngay(dsmt.NgayMuon);
				dsmt.NgayTra.ngay = 0;
				dsmt.NgayTra.thang = 0;
				dsmt.NgayTra.nam = 0;
				dsmt.TrangThai = 0;//dang muon
				Insert_First_MT(p->dg.dsmuon, dsmt);
				DSach.node[i]->dms->dm.TrangThaiSach = 1; //da cho muon
				dmsach = DSach.node[i]->dms;
				save_DanhMuc(DSach);
				save_MuonTra(DGia);
				ShowCur(0);
				SetColor(9);
				gotoxy(137+16, 25+1); cout <<"MUON SACH THANH CONG!";
				Sleep(1500);
				int w = 50-16-1;
				a += dmsach->dm.ViTri;
				a += ". Nhan ENTER de tiep tuc!               ";
				chayChu(a, 137+16, 25+1, 9, 1, w);
				XoaBangDanhSach();
				In_DG(p->dg, DSach);
				return;
			}
		}
	}
}

bool KT_Khong_SDM(DocGia p)
{
	PTRMT dsmt;
	int count = 0;
	if (p.dsmuon != NULL)
	{
		dsmt = p.dsmuon;
		for (dsmt; dsmt != NULL; dsmt = dsmt->next)
		{
			if (dsmt->mt.TrangThai == 0) count++;
		}
	}
	if (count == 0) return true;
	else return false;
}

void Xu_Ly_TS(PTRMT &dsmt, PTRMT dsdm, List &DSach)
{
	for (PTRMT q = dsmt; q != NULL; q = q->next)
	{
		if (!dsdm->mt.MaSach.compare(q->mt.MaSach))
		{
			lay_ngay(q->mt.NgayTra);//Cap nhat ngay tra
			q->mt.TrangThai = 1; //Da tra
		}
	}
	
	int i = 0;
	while(i < DSach.n)
	{
		if (!dsdm->mt.MaSach.compare(0,4,DSach.node[i]->ISBN)) break;
		else i++;
	}
	PTRDMS p;
	if (DSach.node[i]->dms != NULL)
	{
		for (p = DSach.node[i]->dms; p != NULL; p = p->ptnext)
		{
			if (!dsdm->mt.MaSach.compare(p->dm.MaSach)) p->dm.TrangThaiSach = 0;//Cho muon duoc
		}
	}
	p = DSach.node[i]->dms;
}

PTRMT thong_tin_MT(int vt, PTRMT p)
{
	switch(vt)
	{
		case 1:
			return p;
			break;
		case 2:
			return p->next;
			break;
		case 3:
			for (p; p->next != NULL; p = p->next);
			return p;
			break;
	}
}

void Cac_SDM(PTRMT dsdm[], DocGia p, int &so_SDM)
{
	PTRMT q;
	if (p.dsmuon == NULL) return;
	else {
		for (q = p.dsmuon; q != NULL; q = q->next)
		{
			if (q->mt.TrangThai == 0)
			{
				dsdm[so_SDM] = q;
				so_SDM++;
			}
		}
	}
	if (so_SDM == 0) return;
	for (int i = 0; i < so_SDM; i++)
	{
		for (int j = i+1; j <so_SDM; j++)
		{
			if (so_ngay_muon(dsdm[i]->mt.NgayMuon) < so_ngay_muon(dsdm[j]->mt.NgayMuon))
			{
				q = dsdm[i];
				dsdm[i] = dsdm[j];
				dsdm[j] = q;
			}
		}
	}
}

void Tra_Sach(int Mathe, List &DSach, PTRCNP &DGia)
{
	PTRCNP p = Tim_DG(Mathe, DGia);
	int so_SDM = 0;
	PTRMT dsdm[3];
	Cac_SDM(dsdm, p->dg, so_SDM);
	In_DG(p->dg, DSach);
	int vt = 1;
	PTRMT q;
	q = dsdm[vt-1];
	xoa_1_SDM(vt);
	SetColor(10); In_1_SDM(q, DSach, vt);
	char c;
	while(true)
	{
		while(_kbhit())
		{
			c = _getch(); 
			if (c == -32)
			{
				c = _getch();
				if (c == 72)//up
				{
					xoa_1_SDM(vt);
					SetColor(9); In_1_SDM(q, DSach, vt);
					vt--;
					if (vt < 1) vt = so_SDM;
					q = dsdm[vt-1]; 
					xoa_1_SDM(vt);
					SetColor(10); In_1_SDM(q, DSach, vt);	
				}else if (c == 80)//down
				{
					xoa_1_SDM(vt);
					SetColor(9); In_1_SDM(q, DSach, vt);
					vt++;
					if (vt > so_SDM) vt = 1;
					q = dsdm[vt-1]; 
					xoa_1_SDM(vt);
					SetColor(10); In_1_SDM(q, DSach, vt);
				}
			}else if (c == 13)//Enter
			{
				if (!KT_Qua_Han(p->dg.dsmuon)) p->dg.TrangThaiThe = 1;
				Xu_Ly_TS(p->dg.dsmuon, dsdm[vt-1], DSach);
				for (int i = vt-1; i < so_SDM-1; i++)
				{
					dsdm[i] = dsdm[i+1];
				}
				so_SDM--;
				XoaBangDanhSach(); 
				In_DG(p->dg, DSach);
				save_file(DSach, DGia);
				SetColor(9);
				gotoxy(56+16, 14+1); cout <<"TRA SACH THANH CONG!";
				if (so_ngay_muon(q->mt.NgayMuon) >= 7)
				{
					SetColor(10);
					Sleep(2000); xoa_TB(40, 9);
					string tb = "SACH BAN MUON TRA DA QUA HAN. VUI LONG DONG PHAT CHO THU THU! NHAN SPACE DE TIEP TUC.           ";
					chayChu(tb, 56+16, 14+1, 10, 1, 50-16-1);
					xoa_TB(56, 14);
				}
				if(so_SDM == 0){
					SetColor(9);
					gotoxy(56+16, 14+1); cout <<"BAN KHONG CO SACH DANG MUON!";
					Sleep(2000); xoa_TB(56, 14);
					gotoxy(56+16, 14+1); cout <<"NHAN ESC DE THOAT!";
				}else{
					vt = 1; q = dsdm[vt-1];
					xoa_1_SDM(vt);
					SetColor(10); In_1_SDM(q, DSach, vt);
				}
				break;
			}else if (c == 27)
			{
				XoaBangDanhSach();
				thong_bao(56, 14);
				In_DG(p->dg, DSach);
				return;
			}
		}
	}
}

void Xu_Ly_BM(PTRMT &dsmt, PTRMT dsdm, List &DSach)
{
	for (PTRMT q = dsmt; q != NULL; q = q->next)
	{
		if (!dsdm->mt.MaSach.compare(q->mt.MaSach))
		{
			lay_ngay(q->mt.NgayTra);//Cap nhat ngay mat
			q->mt.TrangThai = 2; //Lam mat
		}
	}
	int i = 0;
	while(i < DSach.n)
	{
		if (!dsdm->mt.MaSach.compare(0,4,DSach.node[i]->ISBN)) break;
		else i++;
	}
	PTRDMS p;
	if (DSach.node[i]->dms != NULL)
	{
		for (p = DSach.node[i]->dms; p != NULL; p = p->ptnext)
		{
			if (!dsdm->mt.MaSach.compare(p->dm.MaSach)) p->dm.TrangThaiSach = 2;//Da thanh ly
		}
	}
	p = DSach.node[i]->dms;
}

void Bao_Mat(int Mathe, List &DSach, PTRCNP &DGia)
{
	PTRCNP p = Tim_DG(Mathe, DGia);
	PTRMT q;
	PTRMT dsdm[3];
	int so_SDM = 0;
	if (p->dg.dsmuon == NULL) return;
	else {
		for (q = p->dg.dsmuon; q != NULL; q = q->next)
		{
			if (q->mt.TrangThai == 0)
			{
				dsdm[so_SDM] = q;
				so_SDM++;
			}
		}
	}
	if (so_SDM == 0) return;
	for (int i = 0; i < so_SDM; i++)
	{
		for (int j = i+1; j <so_SDM; j++)
		{
			if (so_ngay_muon(dsdm[i]->mt.NgayMuon) < so_ngay_muon(dsdm[j]->mt.NgayMuon))
			{
				q = dsdm[i];
				dsdm[i] = dsdm[j];
				dsdm[j] = q;
			}
		}
	}
	In_DG(p->dg, DSach);
	int vt = 1;
	q = dsdm[vt-1];
	xoa_1_SDM(vt);
	SetColor(10); In_1_SDM(q, DSach, vt);
	char c;
	while(true)
	{
		while(_kbhit())
		{
			c = _getch(); 
			if (c == -32)
			{
				c = _getch();
				if (c == 72)//up
				{
					xoa_1_SDM(vt);
					SetColor(9); In_1_SDM(q, DSach, vt);
					vt--;
					if (vt < 1) vt = so_SDM;
					q = dsdm[vt-1]; 
					xoa_1_SDM(vt);
					SetColor(10); In_1_SDM(q, DSach, vt);
				}else if (c == 80)//down
				{
					xoa_1_SDM(vt);
					SetColor(9); In_1_SDM(q, DSach, vt);
					vt++;
					if (vt > so_SDM) vt = 1;
					q = dsdm[vt-1]; 
					xoa_1_SDM(vt);
					SetColor(10); In_1_SDM(q, DSach, vt);
				}
			}else if (c == 13)//Enter
			{
				Xu_Ly_BM(p->dg.dsmuon, dsdm[vt-1], DSach);
				for (int i = vt-1; i < so_SDM-1; i++)
				{
					dsdm[i] = dsdm[i+1];
				}
				so_SDM--;
				save_file(DSach, DGia);
				XoaBangDanhSach();
				In_DG(p->dg, DSach);
				SetColor(9);
				gotoxy(56+16, 14+1); cout <<"BAO MAT THANH CONG!";
				Sleep(2000); xoa_TB(56, 14);
				SetColor(10);
				string tb = "VUI LONG DONG PHAT CHO THU THU! NHAN SPACE DE TIEP TUC.           ";
				chayChu(tb, 56+16, 14+1, 10, 1, 50-16-1);
				xoa_TB(56, 14);
				if (so_SDM == 0){
					SetColor(9);
					gotoxy(56+16, 14+1); cout <<"BAN KHONG CO SACH DANG MUON!";
					Sleep(2000); xoa_TB(56, 14);
					gotoxy(56+16, 14+1); cout <<"NHAN ESC DE THOAT!";
				}else{
					vt = 1; q = dsdm[vt-1];
					xoa_1_SDM(vt);
					SetColor(10); In_1_SDM(q, DSach, vt);
				}
			}else if (c == 27)//ESC
			{
				XoaBangDanhSach();
				thong_bao(56, 14);
				In_DG(p->dg, DSach);
				return;
			}	
		}	
	}
}

void Xu_Ly_MTBT(PTRCNP &p, List &DSach, PTRCNP &DGia)
{
	char c;
	In_DG(p->dg, DSach);
	PTRMT dsmt;
	while(true)
	{
		while (_kbhit())
		{
			dsmt = p->dg.dsmuon;
			c = _getch();
			if (c == 60) //F2-MUON
			{
				if (p->dg.TrangThaiThe == 0){
					SetColor(10);
					gotoxy(56+16, 14+1); cout <<"THE CUA BAN DANG BI KHOA!";
					Sleep(2000);
					xoa_TB(56,14);
					break;
				}else if (KT_3_cuon(p->dg) == 3){
					SetColor(10);
					gotoxy(56+16, 14+1); cout <<"BAN DA MUON DU 3 CUON!";
					Sleep(2000);
					xoa_TB(56,14);
					break;
				}else if (KT_Qua_Han(dsmt))
				{
					SetColor(10);
					gotoxy(56+16, 14+1); cout <<"BAN CO SACH MUON QUA HAN!";
					Sleep(2000);
					xoa_TB(56, 14);
					break;
				}else{
					Normal();
					XoaBangDanhSach();
					string Masach;
					Masach = NhapMaSach(p->dg.MaThe, DSach, DGia);
					if (Masach != "") Muon_Sach(p->dg.MaThe, Masach, DSach, DGia);
				}
				break;
			}else if (c == 61)//F3-TRA
			{
				if ((p->dg.dsmuon == NULL) || KT_Khong_SDM(p->dg))
				{
					SetColor(9);
					gotoxy(56+16, 14+1); cout <<"BAN KHONG CO SACH DANG MUON!";
					Sleep(2000);
					xoa_TB(56,14);
					break;
				}else {
					Tra_Sach(p->dg.MaThe, DSach, DGia);
				}
				break;
			}else if (c == 62)//F4-BAO MAT
			{  
				if ((p->dg.dsmuon == NULL) || KT_Khong_SDM(p->dg))
				{
					SetColor(9);
					gotoxy(56+16, 14+1); cout <<"BAN KHONG CO SACH DANG MUON!";
					Sleep(2000);
					xoa_TB(56,14);
					break;
				}else{
					Bao_Mat(p->dg.MaThe, DSach, DGia);
				}
				break;
			}else if (c == 27) // ESC
			{
				XoaBangDanhSach();
				thong_bao(70, 14);
				ShowCur(1);
				Khung_Nhap(78,18, "NHAP VAO MA THE DOC GIA");
				gotoxy(78+14, 18+4); cout <<p->dg.MaThe;
				return;
			}
		}
	}
}

void MTBT(List &DSach, PTRCNP &DGia)
{
	SetBGColor(0);
	thong_bao(70, 14);
	ShowCur(1);
	Khung_Nhap(78,18, "NHAP VAO MA THE DOC GIA");
	int Mathe = 0;
	int count = 0;
	char c;
	while (true){
		while(_kbhit())
		{
			c = _getch();
			if ((c <= 57 && c >=48) && count < 6)
			{
				cout <<c;
				Mathe = Mathe*10 + convert(c);
				count ++;
			}else if (c == 8 && count != 0) //backspace
			{
				cout << "\b \b";
				Mathe /= 10;
				count --;
			}else if (c == 27) return; //escape
			if (c == 13 && count == 6) {//enter
				Normal();
				PTRCNP p = Tim_DG(Mathe, DGia);
				if (p == NULL)
				{
					ShowCur(0);
					SetBGColor(1);
					SetColor(10);
					gotoxy(70+16, 15); cout <<"DOC GIA KHONG TON TAI!";
					Sleep(1000);
					xoa_TB(70, 14);
					ShowCur(1);
					gotoxy(78+14+6, 18+4);
					break;
				}else {
					XoaBangDanhSach();
					Xu_Ly_MTBT(p, DSach, DGia);
					break;
				}
			}
		}
	}
}

int so_ngay_muon_I(PTRMT dsmt)
{
	int max = 0;
	if (dsmt != NULL)
	{
		for (dsmt; dsmt != NULL; dsmt = dsmt->next)
		{
			if (so_ngay_muon(dsmt->mt.NgayMuon) > max && dsmt->mt.TrangThai == 0) max = so_ngay_muon(dsmt->mt.NgayMuon);
		}
		return max;
	}
}

void Quick_Sort(PTRCNP* &dsqh, int q, int r)
{
	int i = q, j = r;
	PTRCNP tmp;
	PTRCNP x = dsqh[(q+r)/2];
	do{
		while(so_ngay_muon_I(dsqh[i]->dg.dsmuon) > so_ngay_muon_I(x->dg.dsmuon)) i++;
		while(so_ngay_muon_I(dsqh[j]->dg.dsmuon) < so_ngay_muon_I(x->dg.dsmuon)) j--;
		if (i<=j)
		{
			tmp = dsqh[i];
			dsqh[i] = dsqh[j];
			dsqh[j] = tmp;
			i++; j--;
		}
	}while(i<=j);
	if (q<j) Quick_Sort(dsqh, q, j);
	if (i<r) Quick_Sort(dsqh, i, r);
}

void Bang_SDM()
{
	SetColor(9);
	int x = 15, y = 12;
	Box(x, y, 6, 4, Doc1, Ngang1); Box(x, y+4, 6, 31, Doc1, Ngang1);
	Box(x+6, y, 9, 4, Doc1, Ngang1); Box(x+6, y+4, 9, 31, Doc1, Ngang1);
	Box(x+15, y, 37, 4, Doc1, Ngang1); Box(x+15, y+4, 37, 31, Doc1, Ngang1);
	Box(x+52, y, 12, 4, Doc1, Ngang1); Box(x+52, y+4, 12, 31, Doc1, Ngang1);
	Box(x+64, y, 17, 4, Doc1, Ngang1); Box(x+64, y+4, 17, 31, Doc1, Ngang1);
	
	for (int i = x; i <= x+81; i++)
	{
		gotoxy(i, y); cout <<char(Ngang2);
		gotoxy(i, y+35); cout <<char(Ngang2);
	}
	for (int i = y; i <= y+35; i++)
	{
		gotoxy(x, i); cout <<char(Doc2);
		gotoxy(x+81, i); cout <<char(Doc2);
	}
	gotoxy(x, y); cout <<char(201);
	gotoxy(x, y+35); cout <<char(200);
	gotoxy(x+81, y); cout <<char(187);
	gotoxy(x+81, y+35); cout <<char(188);
	
	gotoxy(x, y+4); cout <<char(199);
	gotoxy(x+81, y+4); cout <<char(182);
	
	gotoxy(x+6, y+4); cout <<char(197);
	gotoxy(x+15, y+4); cout <<char(197);
	gotoxy(x+52, y+4); cout <<char(197);
	gotoxy(x+64, y+4); cout <<char(197);
	
	gotoxy(x+6, y); cout <<char(209);
	gotoxy(x+15, y); cout <<char(209);
	gotoxy(x+52, y); cout <<char(209);
	gotoxy(x+64, y); cout <<char(209);
	
	gotoxy(x+6, y+35); cout <<char(207);
	gotoxy(x+15, y+35); cout <<char(207);
	gotoxy(x+52, y+35); cout <<char(207);
	gotoxy(x+64, y+35); cout <<char(207);
	 
	SetColor(10);
	gotoxy(x+2, y+2); cout <<"STT";
	gotoxy(x+6+2, y+2); cout <<"MA THE";
	gotoxy(x+15+14, y+2); cout <<"HO & TEN";
	gotoxy(x+52+2, y+2); cout <<"GIOI TINH";
	gotoxy(x+64+2, y+2); cout <<"TRANG THAI THE";
}

void HD_Bang_SDM(int st, int so_trang)
{
	SetColor(9);
	int x = 15, y = 12;
	gotoxy(x+2, y+36); cout <<"Trang truoc  "<<char(60)<<char(196);
	gotoxy(x+2+16, y+36); cout <<char(196)<<char(62)<<"  Trang sau";
	gotoxy(x+68, y+36); cout <<"Trang "<<st<<" / "<<so_trang;
	gotoxy(103, 27); cout <<"ESC - THOAT";
}

void DG_DMS(PTRCNP* &dsqh, PTRCNP DGia, int &so_DG)
{
	if (DGia == NULL) return;
	PTRMT q;
	if (DGia->dg.dsmuon != NULL)
	{
		for (q = DGia->dg.dsmuon; q != NULL; q = q->next)
		{
			if (q->mt.TrangThai == 0){
				if (dsqh[0] == NULL)
				{
					dsqh[0] = DGia;
				}else{
					PTRCNP *tmp = new PTRCNP[so_DG+1];
					for (int i = 0; i < so_DG; i++)
					{
						tmp[i] = dsqh[i];
					}
					tmp[so_DG] = DGia;
					delete[] dsqh;
					dsqh = tmp;
					so_DG++;
				}
				break;
			}
		}
	}
	DG_DMS(dsqh, DGia->left, so_DG);
	DG_DMS(dsqh, DGia->right, so_DG);
}

void In_30_DG(PTRCNP *dsdm, int sl, int st)
{
	SetColor(9);
	int x = 16, y = 17;
	for (int i = 30*(st-1); i < sl; i++)
	{
		gotoxy(x+2, y+i-30*(st-1)); cout <<i+1;
		gotoxy(x+6+1, y+i-30*(st-1)); cout <<dsdm[i]->dg.MaThe;
		gotoxy(x+15+1, y+i-30*(st-1)); cout <<dsdm[i]->dg.ho<<" "<<dsdm[i]->dg.ten;
		gotoxy(x+52+4, y+i-30*(st-1)); cout <<dsdm[i]->dg.phai;
		gotoxy(x+64+1, y+i-30*(st-1));
		if (dsdm[i]->dg.TrangThaiThe == 1) cout <<"DANG HOAT DONG";
		else cout <<"DA BI KHOA";
	}
}

void xoa_1_DG(int vt)
{
	int x = 15, y = 16;
	SetColor(1);
	for (int i = x+1; i <= x+80; i++)
	{
		gotoxy(i, y+vt);
		cout <<" ";
	}
	SetColor(9);
	gotoxy(x+6, y+vt); cout <<char(Doc1);
	gotoxy(x+15, y+vt); cout <<char(Doc1);
	gotoxy(x+52, y+vt); cout <<char(Doc1);
	gotoxy(x+64, y+vt); cout <<char(Doc1);
	SetColor(15);
}

void In_1_DG(DocGia p, int vt, int st)
{
	int x = 16, y = 16;
	gotoxy(x+2, y+vt); cout <<vt + (st-1)*30;
	gotoxy(x+6+1, y+vt); cout <<p.MaThe;
	gotoxy(x+15+1, y+vt); cout <<p.ho<<" "<<p.ten;
	gotoxy(x+52+4, y+vt); cout <<p.phai;
	gotoxy(x+64+1, y+vt);
	if (p.TrangThaiThe == 1) cout <<"DANG HOAT DONG";
	else cout <<"DA BI KHOA";
}

void xoa_bang_SDM()
{
	int x = 102, y = 16;
	for (int i = x+1; i < x+67; i++)
	{
		for (int j = y+5; j < y+10; j++)
		{
			gotoxy(i, j); cout <<" ";
		}
	}
	SetColor(0);
	for (int i = y+5; i < y+10; i++)
	{
		gotoxy(x+6, i); cout <<char(Doc1);
		gotoxy(x+18, i); cout <<char(Doc1);
		gotoxy(x+58, i); cout <<char(Doc1);
	}
}

void In_SDM(DocGia p, List Ds)
{ 
	PTRMT dsdm[3];
	int so_SDM = 0;
	Cac_SDM(dsdm, p, so_SDM);
	int x = 102, y = 18;
	SetColor(9); 
	for (int i = 0; i < so_SDM;i++)
	{
		gotoxy(x+3, y+(i*2)+3); cout <<i+1;
		gotoxy(x+9, y+(i*2)+3); cout <<dsdm[i]->mt.MaSach;
		gotoxy(x+19, y+(i*2)+3); cout <<Tim_tensach(dsdm[i]->mt.MaSach, Ds);
		gotoxy(x+63, y+(i*2)+3); cout <<so_ngay_muon(dsdm[i]->mt.NgayMuon); 
	}	
}

void LK_SDM(List DSach, PTRCNP DGia)
{
	SetBGColor(0);
	ShowCur(0);
	if (DGia == NULL) return;
	Bang_SDM();
	int so_DG = 0;
	PTRCNP *dsdm = new PTRCNP[so_DG];
	DG_DMS(dsdm, DGia, so_DG);
	Quick_Sort(dsdm, 0, so_DG-1);
	
	if (so_DG == 0) return;
	int so_trang = 0;
	if (so_DG%30 != 0) so_trang = so_DG/30+1;
	else so_trang = so_DG/30;
	if (so_trang == 1)
	{
		In_30_DG(dsdm, so_DG, 1);
		HD_Bang_SDM(1,1);
	}else{
		In_30_DG(dsdm, 30, 1);
		HD_Bang_SDM(1,so_trang);
	}
	int vt = 1, st = 1;
	xoa_1_DG(vt); SetColor(10);
	In_1_DG(dsdm[(vt-1) + (st-1)*30]->dg, vt, st);
	SetColor(0);
	Bang_DSM(102, 12+4);
	In_SDM(dsdm[(vt-1) + (st-1)*30]->dg, DSach);
	char c;
	while(true)
	{
		while(_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72)
				{
					xoa_1_DG(vt); SetColor(9);
					In_1_DG(dsdm[(vt-1) + (st-1)*30]->dg, vt, st);
					xoa_bang_SDM();
					vt--;
					if (vt < 1)
					{
						if (st == so_trang) vt = so_DG - (st-1)*30;
						else vt = 30;					
					}
					In_SDM(dsdm[(vt-1) + (st-1)*30]->dg, DSach);
					xoa_1_DG(vt); SetColor(10);
					In_1_DG(dsdm[(vt-1) + (st-1)*30]->dg, vt, st);
				}else if (c == 80)
				{
					xoa_1_DG(vt); SetColor(9);
					In_1_DG(dsdm[(vt-1) + (st-1)*30]->dg, vt, st);
					xoa_bang_SDM();
					vt++;
					if (vt > 30 || (vt+(st-1)*30) > so_DG) vt = 1;
					
					In_SDM(dsdm[(vt-1) + (st-1)*30]->dg, DSach);
					xoa_1_DG(vt); SetColor(10);
					In_1_DG(dsdm[(vt-1) + (st-1)*30]->dg, vt, st);
				}else if (c == 77)
				{
					if (so_trang == 1) break;
					XoaBangDanhSach();
					st++;
					Bang_SDM(); SetColor(0);
					Bang_DSM(102, 12+4);
					if (st <= so_trang)
					{
						if (st == so_trang)
						{
							In_30_DG(dsdm, so_DG, st);
						}else{
							In_30_DG(dsdm, 30*st, st);
						}
						if (vt + (st-1)*30 > so_DG)
						{
							vt = so_DG - (st-1)*30;
						}
					}else {
						st = 1;
						In_30_DG(dsdm, 30, st);
					}
					HD_Bang_SDM(st, so_trang);
					In_SDM(dsdm[(vt-1) + (st-1)*30]->dg, DSach);
					xoa_1_DG(vt); SetColor(10);
					In_1_DG(dsdm[(vt-1) + (st-1)*30]->dg, vt, st);
				}else if (c == 75)
				{
					if (so_trang == 1) break;
					XoaBangDanhSach();
					Bang_SDM(); SetColor(0);
					Bang_DSM(102, 12+4);
					st--;
					if (so_trang >= 1)
					{
						if (st >= 1){
							In_30_DG(dsdm, 30*st, st);
						}else{
							st = so_trang;
							In_30_DG(dsdm, so_DG, st);
							if (vt + (st-1)*30 > so_DG)
							{
								vt = so_DG - (st-1)*30;
							}
						}
						HD_Bang_SDM(st, so_trang);
						In_SDM(dsdm[(vt-1) + (st-1)*30]->dg, DSach);
						xoa_1_DG(vt); SetColor(10);
						In_1_DG(dsdm[(vt-1) + (st-1)*30]->dg, vt, st);
					}else st = 1;
				}
			}else if (c == 27) return;
		}
	}
}

void Xu_Ly_QH(PTRCNP &DGia)
{
	if (DGia != NULL)
	{
		PTRCNP p = DGia;
		if (KT_Qua_Han(p->dg.dsmuon)){
			p->dg.TrangThaiThe = 0;
		}
		Xu_Ly_QH(p->left);
		Xu_Ly_QH(p->right);
	}
}

void Bang_QH()
{
    SetColor(9);
	int x = 20, y = 12;
	Box(x, y, 6, 35, Doc1, Ngang1); Box(x+6, y, 9, 35, Doc1, Ngang1); Box(x+15, y, 37, 35, Doc1, Ngang1);
	
	for (int i = x; i <= x+52; i++)
	{
		gotoxy(i, y); cout <<char(Ngang2);
		gotoxy(i, y+4); cout <<char(Ngang1);
		gotoxy(i, y+35); cout <<char(Ngang2);
	}
	for (int i = y; i <= y+35; i++)
	{
		gotoxy(x, i); cout <<char(Doc2);
		gotoxy(x+52, i); cout <<char(Doc2);
	}
	gotoxy(x, y); cout <<char(201);
	gotoxy(x, y+35); cout <<char(200);
	gotoxy(x+52, y); cout <<char(187);
	gotoxy(x+52, y+35); cout <<char(188);
	
	gotoxy(x, y+4); cout <<char(199);
	gotoxy(x+52, y+4); cout <<char(182);

	gotoxy(x+6, y+4); cout <<char(197); gotoxy(x+15, y+4); cout <<char(197);
	
	gotoxy(x+6, y); cout <<char(209); gotoxy(x+15, y); cout <<char(209);

	gotoxy(x+6, y+35); cout <<char(207); gotoxy(x+15, y+35); cout <<char(207);
	SetColor(10);
	gotoxy(x+2, y+2); cout <<"STT";
	gotoxy(x+6+2, y+2); cout <<"MA THE";
	gotoxy(x+15+14, y+2); cout <<"HO & TEN";
}

void Bang_SQH()
{
	int x = 72+5, y = 16;
	SetColor(9);
	Box(x, y, 6, 10, Doc1, Ngang1); Box(x+6, y, 12, 10, Doc1, Ngang1);
	Box(x+18, y, 40, 10, Doc1, Ngang1); Box(x+58, y, 13, 10, Doc1, Ngang1); Box(x+71, y, 10, 10, Doc1, Ngang1);
	
	for (int i = x; i <= x+81; i++)
	{
		gotoxy(i, y); cout <<char(Ngang2);
		gotoxy(i, y+4); cout <<char(Ngang1);
		gotoxy(i, y+10); cout <<char(Ngang2);
	}
	for(int i = y; i <= y+10; i++)
	{
		gotoxy(x, i); cout <<char(Doc2);
		gotoxy(x+81, i); cout <<char(Doc2);
	}
	gotoxy(x, y); cout <<char(201);
	gotoxy(x, y+10); cout <<char(200);
	gotoxy(x+81, y); cout <<char(187);
	gotoxy(x+81, y+10); cout <<char(188);
	
	gotoxy(x, y+4); cout <<char(199);
	gotoxy(x+81, y+4); cout <<char(182);
	
	gotoxy(x+6, y+4); cout <<char(197);
	gotoxy(x+18, y+4); cout <<char(197);
	gotoxy(x+58, y+4); cout <<char(197);
	gotoxy(x+71, y+4); cout <<char(197);
	
	gotoxy(x+6, y); cout <<char(209);
	gotoxy(x+18, y); cout <<char(209);
	gotoxy(x+58, y); cout <<char(209);
	gotoxy(x+71, y); cout <<char(209);
	gotoxy(x+6, y+10); cout <<char(207);
	gotoxy(x+18, y+10); cout <<char(207);
	gotoxy(x+58, y+10); cout <<char(207);
	gotoxy(x+71, y+10); cout <<char(207);
	
	SetColor(10);
	gotoxy(x+2, y+2); cout <<"STT";
	gotoxy(x+9, y+2); cout <<"MA SACH";
	gotoxy(x+34, y+2); cout <<"TEN SACH";
	gotoxy(x+60, y+2); cout <<"NGAY MUON";
	gotoxy(x+73, y+2); cout <<"SO NGAY";
	gotoxy(x+73, y+3); cout <<"QUA HAN";
}

void Cac_DG_QH(PTRCNP* &dsqh, PTRCNP DGia, int &so_DG)
{
	if (DGia == NULL) return;
	PTRMT q;
	if (DGia->dg.dsmuon != NULL)
	{
		for (q = DGia->dg.dsmuon; q != NULL; q = q->next)
		{
			if (so_ngay_muon(q->mt.NgayMuon) >= 7 && q->mt.TrangThai == 0)
			{
				if (dsqh[0] == NULL)
				{
					dsqh[0] = DGia;
				}else{
					PTRCNP *tmp = new PTRCNP[so_DG+1];
					for (int i = 0; i < so_DG; i++)
					{
						tmp[i] = dsqh[i];
					}
					tmp[so_DG] = DGia;
					delete[] dsqh;
					dsqh = tmp;
					so_DG++;
				}
				break;
			}
		}
	}
	Cac_DG_QH(dsqh, DGia->left, so_DG);
	Cac_DG_QH(dsqh, DGia->right, so_DG);
}

int so_SDMQH(PTRMT dsmt)
{
	int count = 0;
	for (dsmt; dsmt != NULL;dsmt = dsmt->next)
	{
		if (so_ngay_muon(dsmt->mt.NgayMuon) >= 7 && dsmt->mt.TrangThai == 0) count ++;
	}
	return count;
}

void InDate(Date date)
{
	cout <<setfill('0')<<setw(2)<<date.ngay<<"/"<<setfill('0')<<setw(2)<<date.thang<<setfill(' ')<<"/"<<date.nam;
}

void Cac_SQH(PTRMT sachqh[], PTRMT dsmt, int &so_SQH)
{
	if (dsmt == NULL) return;
	for (dsmt; dsmt != NULL; dsmt = dsmt->next)
	{
		if ((so_ngay_muon(dsmt->mt.NgayMuon) >= 7) && (dsmt->mt.TrangThai == 0))
		{
			sachqh[so_SQH] = dsmt;
			so_SQH++;
		}
	}
	PTRMT MT;
	for (int i = 0; i < so_SQH; i++)
	{
		for (int j = i+1; j < so_SQH; j++)
		{
			if (so_ngay_muon(sachqh[i]->mt.NgayMuon) < so_ngay_muon(sachqh[j]->mt.NgayMuon))
			{
				MT = sachqh[i];
				sachqh[i] = sachqh[j];
				sachqh[j] = MT;
			}
		}
	}
}

void HD_Bang_SQH(int st, int so_trang)
{
	SetColor(9);
	int x = 107, y = 28;
	gotoxy(64, 48); cout <<"Trang "<<st<<" / "<<so_trang;
	Box(x, y, 20, 8, Doc2, Ngang2);
	for (int i = x; i <= x+20; i++)
	{
		gotoxy(i, y+2); cout <<char(Ngang2);
	}
	gotoxy(x, y+2); cout <<char(204);
	gotoxy(x+20, y+2); cout <<char(185);
	SetColor(10);
	gotoxy(x+6, y+1); cout <<"HUONG DAN";
	SetColor(9);
	gotoxy(x+3, y+3); cout <<char(60)<<char(Ngang1)<<": Trang truoc";
	gotoxy(x+3, y+5); cout <<char(Ngang1)<<char(62)<<": Trang sau";
	gotoxy(x+3, y+7); cout <<"ESC - THOAT";
}

void In_30_QH(PTRCNP *dsqh, int sl, int st)
{
	SetColor(9);
	int x = 21, y = 17;
	for (int i = 30*(st-1); i < sl; i++)
	{
		gotoxy(x+2, y+i-30*(st-1)); cout <<i+1;
		gotoxy(x+6+1, y+i-30*(st-1)); cout <<dsqh[i]->dg.MaThe;
		gotoxy(x+15+1, y+i-30*(st-1)); cout <<dsqh[i]->dg.ho<<" "<<dsqh[i]->dg.ten;
	}
}

void xoa_1_QH(int vt)
{
	int x = 20, y = 16;
	SetColor(1);
	for (int i = x+1; i < x+52; i++)
	{
		gotoxy(i, y+vt);
		cout <<" ";
	}
	SetColor(9);
	gotoxy(x+6, y+vt); cout <<char(Doc1);
	gotoxy(x+15, y+vt); cout <<char(Doc1);
	SetColor(15);
}

void In_1_QH(DocGia p, int vt, int st)
{
	int x = 21, y = 16;
	gotoxy(x+2, y+vt); cout <<vt + (st-1)*30;
	gotoxy(x+6+1, y+vt); cout <<p.MaThe;
	gotoxy(x+15+1, y+vt); cout <<p.ho<<" "<<p.ten;
}

void In_SQH(DocGia p, List Ds)
{
	PTRMT sachqh[3];
	int so_SQH = 0;
	Cac_SQH(sachqh, p.dsmuon, so_SQH);
	int x = 77, y = 18;
	SetColor(9);
	for (int i = 0; i < so_SQH; i++)
	{
		gotoxy(x+3, y+(i*2)+3); cout <<i+1;
		gotoxy(x+8, y+(i*2)+3); cout <<sachqh[i]->mt.MaSach;
		gotoxy(x+19, y+(i*2)+3); cout <<Tim_tensach(sachqh[i]->mt.MaSach, Ds);
		gotoxy(x+60, y+(i*2)+3); 
		InDate(sachqh[i]->mt.NgayMuon);
		gotoxy(x+74, y+(i*2)+3); cout <<so_ngay_muon(sachqh[i]->mt.NgayMuon) - 6;
	}
}

void xoa_bang_SQH()
{
	int x = 77, y = 16;
	for (int i = x+1; i < x+81; i++)
	{
		for (int j = y+5; j < y+10; j++)
		{
			gotoxy(i, j); cout <<" ";
		}
	}
	SetColor(0);
	for (int i = y+5; i < y+10; i++)
	{
		gotoxy(x+6, i); cout <<char(Doc1);
		gotoxy(x+18, i); cout <<char(Doc1);
		gotoxy(x+58, i); cout <<char(Doc1);
		gotoxy(x+71, i); cout <<char(Doc1);
	}
}

void DocGia_QuaHan(List DSach, PTRCNP DGia)
{
	SetBGColor(0);
	ShowCur(0);
	if (DGia == NULL) return;
	int so_DG = 0;
	PTRCNP *dsqh = new PTRCNP[so_DG];
	Cac_DG_QH(dsqh, DGia, so_DG);
	if (so_DG == 0) return;
	Quick_Sort(dsqh, 0, so_DG-1);
	Bang_QH();
	int so_trang = 0;
	if (so_DG%30 != 0) so_trang = so_DG/30+1;
	else so_trang = so_DG/30;
	if (so_trang == 1)
	{
		In_30_QH(dsqh, so_DG, 1);
		HD_Bang_SQH(1,1);
	}else{
		In_30_QH(dsqh, 30, 1);
		HD_Bang_SQH(1,so_trang);
	}
	int vt = 1, st = 1;
	xoa_1_QH(vt); SetColor(10);
	In_1_QH(dsqh[(vt-1) + (st-1)*30]->dg, vt, st);
	SetColor(0);
	Bang_SQH(); In_SQH(dsqh[(vt-1) + (st-1)*30]->dg, DSach);
	char c;
	while(true)
	{
		while(_kbhit())
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72)
				{
					xoa_1_QH(vt); SetColor(9);
					In_1_QH(dsqh[(vt-1) + (st-1)*30]->dg, vt, st);
					xoa_bang_SQH();
					vt--;
					if (vt < 1)
					{
						if (st == so_trang) vt = so_DG - (st-1)*30;
						else vt = 30;					
					}
					In_SQH(dsqh[(vt-1) + (st-1)*30]->dg, DSach);
					xoa_1_QH(vt); SetColor(10);
					In_1_QH(dsqh[(vt-1) + (st-1)*30]->dg, vt, st);
				}else if (c == 80)
				{
					xoa_1_QH(vt); SetColor(9);
					In_1_QH(dsqh[(vt-1) + (st-1)*30]->dg, vt, st);
					xoa_bang_SQH();
					vt++;
					if (vt > 30 || (vt+(st-1)*30) > so_DG) vt = 1;
						
					In_SQH(dsqh[(vt-1) + (st-1)*30]->dg, DSach);
					xoa_1_QH(vt); SetColor(10);
					In_1_QH(dsqh[(vt-1) + (st-1)*30]->dg, vt, st);
				}else if (c == 77)
				{
					if (so_trang == 1) break;
					XoaBangDanhSach();
					st++;
					Bang_QH(); SetColor(0);
					Bang_SQH();
					if (st <= so_trang)
					{
						if (st == so_trang)
						{
							In_30_QH(dsqh, so_DG, st);
						}else{
							In_30_QH(dsqh, 30*st, st);
						}
						if (vt + (st-1)*30 > so_DG)
						{
							vt = so_DG - (st-1)*30;
						}
					}else {
						st = 1;
						In_30_QH(dsqh, 30, st);
					}
					HD_Bang_SQH(st, so_trang);
					In_SQH(dsqh[(vt-1) + (st-1)*30]->dg, DSach);
					xoa_1_QH(vt); SetColor(10);
					In_1_QH(dsqh[(vt-1) + (st-1)*30]->dg, vt, st);
				}else if (c == 75)
				{
					if (so_trang == 1) break;
					XoaBangDanhSach();
					Bang_QH(); SetColor(0);
					Bang_SQH();
					st--;
					if (so_trang >= 1)
					{
						if (st >= 1){
							In_30_QH(dsqh, 30*st, st);
						}else{
							st = so_trang;
							In_30_QH(dsqh, so_DG, st);
							if (vt + (st-1)*30 > so_DG)
							{
								vt = so_DG - (st-1)*30;
							}
						}
						HD_Bang_SQH(st, so_trang);
						In_SQH(dsqh[(vt-1) + (st-1)*30]->dg, DSach);
						xoa_1_QH(vt); SetColor(10);
						In_1_QH(dsqh[(vt-1) + (st-1)*30]->dg, vt, st);
					}else st = 1;
				}
			}else if (c == 27) return;
		}
	}
}

void Sach_Muon_Nhieu_Nhat(List DSach, PTRCNP DGia)
{
	ShowCur(0); 
	SetBGColor(0);
	SetColor(9); Box(70, 12, 50, 2, Doc2, Ngang2); SetColor(10);
    gotoxy(70+10, 13); cout <<"DANH SACH 10 SACH MUON NHIEU NHAT";
    int x = 24, y = 16; SetColor(9);
    Box(x, y, 6, 24, Doc1, Ngang1); Box(x+6, y, 7, 24, Doc1, Ngang1); Box(x+13, y, 31, 24, Doc1, Ngang1); 
    Box(x+44, y, 11, 24, Doc1, Ngang1); Box(x+55, y, 31, 24, Doc1, Ngang1); Box(x+86, y, 11, 24, Doc1, Ngang1);
    Box(x+97, y, 21, 24, Doc1, Ngang1); Box(x+118, y, 12, 24, Doc1, Ngang1);
    
    for (int i = x; i <= x+130; i++)
    {
    	gotoxy(i, y); cout <<char(Ngang2);
    	gotoxy(i, y+4); cout <<char(Ngang1);
    	gotoxy(i, y+24); cout <<char(Ngang2);
	}
	for (int i = y; i <= y+24; i++)
	{
		gotoxy(x, i); cout <<char(Doc2);
		gotoxy(x+130, i); cout <<char(Doc2);
	}
	gotoxy(x, y); cout <<char(201); gotoxy(x, y+24); cout <<char(200);
	gotoxy(x+130, y); cout <<char(187); gotoxy(x+130, y+24); cout <<char(188);
	gotoxy(x, y+4); cout <<char(199); gotoxy(x+130, y+4); cout <<char(182);
	gotoxy(x+6, y+4); cout <<char(197); gotoxy(x+13, y+4); cout <<char(197);
	gotoxy(x+44, y+4); cout <<char(197); gotoxy(x+55, y+4); cout <<char(197);
    gotoxy(x+86, y+4); cout <<char(197); gotoxy(x+97, y+4); cout <<char(197);
    gotoxy(x+118, y+4); cout <<char(197);
    gotoxy(x+6, y); cout <<char(209); gotoxy(x+6, y+24); cout <<char(207);
    gotoxy(x+13, y); cout <<char(209); gotoxy(x+13, y+24); cout <<char(207);
    gotoxy(x+44, y); cout <<char(209); gotoxy(x+44, y+24); cout <<char(207);
    gotoxy(x+55, y); cout <<char(209); gotoxy(x+55, y+24); cout <<char(207);
    gotoxy(x+86, y); cout <<char(209); gotoxy(x+86, y+24); cout <<char(207);
    gotoxy(x+97, y); cout <<char(209); gotoxy(x+97, y+24); cout <<char(207);
    gotoxy(x+118, y); cout <<char(209); gotoxy(x+118, y+24); cout <<char(207);
    
    SetColor(10);
    gotoxy(x+2, y+2); cout <<"STT";
    gotoxy(x+6+2, y+2); cout <<"ISBN";
    gotoxy(x+13+11, y+2); cout <<"TEN SACH";
    gotoxy(x+44+2, y+2); cout<<"SO TRANG";
    gotoxy(x+55+11, y+2); cout <<"TAC GIA";
    gotoxy(x+86+4, y+2); cout <<"NAM"; gotoxy(x+86+2, y+3); cout <<"XUAT BAN";
    gotoxy(x+97+6, y+2); cout <<"THE LOAI";
    gotoxy(x+118+5, y+2); cout <<"SO"; gotoxy(x+118+2, y+3); cout<<"LUOT MUON";
    SetColor(9);
    gotoxy(x+2, y+26); cout <<"ESC - THOAT";
    Quick_Sort_LM(DSach, DGia, 0, DSach.n-1);
    y += 4;
    int slm;
    for (int i = 0; i < 10; i++)
    {
    	slm = so_luot_muon(DSach.node[i]->ISBN, DGia);
    	if (slm == 0) break;
    	gotoxy(x+3, y+(2*i)+1); cout <<i+1;
    	gotoxy(x+6+2, y+(2*i)+1); cout <<DSach.node[i]->ISBN;
    	gotoxy(x+13+1, y+(2*i)+1); cout <<DSach.node[i]->TenSach;
    	gotoxy(x+44+4, y+(2*i)+1); cout <<DSach.node[i]->SoTrang;
    	gotoxy(x+55+1, y+(2*i)+1); cout <<DSach.node[i]->TacGia;
    	gotoxy(x+86+4, y+(2*i)+1); cout <<DSach.node[i]->NamXuatBan;
    	gotoxy(x+97+1, y+(2*i)+1); cout <<DSach.node[i]->TheLoai;
    	gotoxy(x+118+5, y+(2*i)+1); cout <<slm;
	}
	char c;
    while (true)
    {
    	while(_kbhit())
    	{
    		c = _getch();
    		if(c == 27)
    		{
    			return;
			}
		}
	}
}

#endif

