#ifndef GIAODIENDAUSACH_H
#define GIAODIENDAUSACH_H
#include "GiaoDien.h"
using namespace std;

void VeQuyDinhNhapISBN(){
	string Dong1;
	string Dong2;
	Dong1=QuyDinhNhapISBN.substr(0,QuyDinhNhapISBN.find(","));
	Dong2=QuyDinhNhapISBN.substr(QuyDinhNhapISBN.find(",")+2);
	for(int i=0; i<5; i++)
	{
		gotoxy(TongCDDauSach+XDauSach+3,YDauSach+3+i);
		for(int j=0; j<40; j++)
		{
			SetBGColor(3);
			cout<<" ";
		} 
		if(i==1)
		{
			SetColor(5);
			gotoxy(TongCDDauSach+XDauSach+3+(40-Dong1.length())/2,YDauSach+3+i);
			cout<<Dong1;
		} 
		else if(i==3)
		{
			SetColor(5);
			gotoxy(TongCDDauSach+XDauSach+3+(40-Dong2.length())/2,YDauSach+3+i);
			cout<<Dong2;
		}
	}
	Nen();
}
void BangDauSach(){
	BangDanhSach(ThongTinDauSach, ChieuDaiDauSach, ChieuRongDauSach, TongThongTinDauSach, TIEU_DE, KHUNG, XDauSach, YDauSach);
}
void BangTimDauSach(){
	BangDanhSach(ThongTinTimDauSach,ChieuDaiTimDauSach,ChieuRongTimDauSach,TongThongTinTimDauSach,TIEU_DE,KHUNG,XTimDauSach,YTimDauSach);
}
void VePhimDauSach(){
	VePhim(Them, CHU ,NEN_PHIM ,XDauSach+10 ,YDauSach+3+ChieuRongDauSach+1); 
	VePhim(CapNhat, CHU, NEN_PHIM, wherex()+10, wherey()-2);
	VePhim(Xoa, CHU, NEN_PHIM, wherex()+10, wherey()-2);
	VePhim(DanhMucSach, CHU, NEN_PHIM, wherex()+10, wherey()-2);
	VePhim(Thoat, CHU, NEN_PHIM, wherex()+10, wherey()-2);
}
void VeNoiDungThongBaoDauSach(string s){
	VeNoiDungThongBao(s,XThongBaoDauSach,YThongBaoDauSach,TIEU_DE);
	Sleep(3000);
	XoaNoiDungThongBao(XThongBaoDauSach,YThongBaoDauSach,CDKhungThongBaoDauSach);
}
void VeKhungCapNhatDauSach(List &DSDS, int DiemX, int DiemY, int ThongTin){
	VeKhungCapNhat(ThongTinDauSach,DiemX, DiemY,55,TongThongTinDauSach*2+3,KHUNG,TIEU_DE,TIEU_DE);
	SetColor(NOI_DUNG);
	gotoxy(DiemX+13,DiemY+4);
	cout<<DSDS.node[ThongTin]->ISBN;
	gotoxy(DiemX+13,DiemY+6);
	cout<<DSDS.node[ThongTin]->TenSach;
	gotoxy(DiemX+13,DiemY+8);
	cout<<DSDS.node[ThongTin]->SoTrang;
	gotoxy(DiemX+13,DiemY+10);
	cout<<DSDS.node[ThongTin]->TacGia;
	gotoxy(DiemX+13,DiemY+12);
	cout<<DSDS.node[ThongTin]->NamXuatBan;
	gotoxy(DiemX+13,DiemY+14);
	cout<<DSDS.node[ThongTin]->TheLoai;
}
void VeKhungTimThongTin(int DiemX, int DiemY, int ChieuDai, int ChieuRong, int MauKhung, int MauChu, int Ma, int Ten, int TongThongTin){
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
	SetColor(MauChu);
	string TieuDe="DANH SACH DAU SACH TIM THAY";
	gotoxy(DiemX+1+((ChieuDai-TieuDe.length())/2),DiemY+2);
	cout<<TieuDe;
	
}
void VeTrangDauSach(){
	VeTrang(SoTrangDauSach,TongTrangDauSach,XDauSach+TongCDDauSach+1,YDauSach+3+ChieuRongDauSach-1,TIEU_DE);
}
void XoaPhimDauSach(){
	XoaPhim(XDauSach+TongCDDauSach+1,YDauSach+3+ChieuRongDauSach-1);
}
void XoaPhimTimDauSach(){
	XoaPhim(XTimDauSach+TongCDTimDauSach+1,YTimDauSach+3+ChieuRongTimDauSach-1);
}
void XoaThongTinDauSach(){
	XoaThongTin(ChieuDaiDauSach,6,XDauSach,wherey());
}

void TinhSoTrangDauSach(List &DSDS){
	if(DSDS.n==0)
	{
		TongTrangDauSach=1;
	}
	else if(DSDS.n>0)
	{
			TongTrangDauSach=(DSDS.n/ChieuRongDauSach)+1;
	}
}
void XoaHetDSDS(){
	for(int t=0; t<ChieuRongDauSach; t++)
	{
		XoaThongTin(ChieuDaiDauSach,6,XDauSach,YDauSach+3+t);
	}
}
void Xuat1DauSach(List &DSDS, int DiemY, int ThongTin, int MauChu){
	if(DSDS.n==0)
	{
		return;
	}
	SetColor(MauChu);
	int DiemX;
	gotoxy(XDauSach+1,YDauSach+3+DiemY);
	cout<<DSDS.node[ThongTin]->ISBN;
			
	DiemX=XDauSach+1+ChieuDaiDauSach[0]+1;
	gotoxy(DiemX,YDauSach+3+DiemY);
	cout<<DSDS.node[ThongTin]->TenSach;
	
	DiemX+=ChieuDaiDauSach[1]+1;
	gotoxy(DiemX,YDauSach+3+DiemY);
	cout<<DSDS.node[ThongTin]->SoTrang;
	
	DiemX+=ChieuDaiDauSach[2]+1;
	gotoxy(DiemX,YDauSach+3+DiemY);
	cout<<DSDS.node[ThongTin]->TacGia;
	
	DiemX+=ChieuDaiDauSach[3]+1;
	gotoxy(DiemX,YDauSach+3+DiemY);
	cout<<DSDS.node[ThongTin]->NamXuatBan;
	
	DiemX+=ChieuDaiDauSach[4]+1;
	gotoxy(DiemX,YDauSach+3+DiemY);
	cout<<DSDS.node[ThongTin]->TheLoai; 
}
void XuatDauSach(List &DSDS, int MauChu, int ThongTinDau, int ThongTinCuoi){
	if(DSDS.n==0)
	{
		return;
	}
	int DiemX;
	int i=0;
	int j=ThongTinDau;
	TinhSoTrangDauSach(DSDS);
	VeTrangDauSach();
	SetColor(MauChu);
	while(j<ThongTinCuoi)
	{
		gotoxy(XDauSach+1,YDauSach+3+i);
		cout<<DSDS.node[j]->ISBN;
		
		DiemX=XDauSach+1+ChieuDaiDauSach[0]+1;
		gotoxy(DiemX,YDauSach+3+i);
		cout<<DSDS.node[j]->TenSach;
		
		DiemX+=ChieuDaiDauSach[1]+1;
		gotoxy(DiemX,YDauSach+3+i);
		cout<<DSDS.node[j]->SoTrang;
		
		DiemX+=ChieuDaiDauSach[2]+1;
		gotoxy(DiemX,YDauSach+3+i);
		cout<<DSDS.node[j]->TacGia;
		
		DiemX+=ChieuDaiDauSach[3]+1;
		gotoxy(DiemX,YDauSach+3+i);
		cout<<DSDS.node[j]->NamXuatBan;
		
		DiemX+=ChieuDaiDauSach[4]+1;
		gotoxy(DiemX,YDauSach+3+i);
		cout<<DSDS.node[j]->TheLoai; 
		j++;	
		i++;
	}
	Nen();
}
void VeKhungDauSachTimDuoc(int ChieuDai, int ChieuRong, int DiemX, int DiemY, int MauTieuDe, int MauKhung){
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
	string TieuDe="THONG TIN DAU SACH TIM THAY";
	gotoxy(DiemX+1+((ChieuDai-TieuDe.length())/2),DiemY+2);
	cout<<TieuDe;
}
void XuatDauSachTimDuoc(List &DSDS, int MangDauSach[], int SoDauSach, int MauChu){
	int k=0;
	int h=0;
	SetColor(MauChu);
	while(k<SoDauSach)
	{
		gotoxy((189-60)/2+1+3,GocY+(31-SoDauSach*2+3)/2-3+4+h);
		cout<<DSDS.node[MangDauSach[k]]->ISBN;
		gotoxy((189-60)/2+1+3+4+5,GocY+(31-SoDauSach*2+3)/2-3+4+h);
		cout<<DSDS.node[MangDauSach[k]]->TenSach;
		
		k++;
		h+=2;
	}
}
void Xuat1DauSachTimDuoc(List &DSDS, int n, int SoDauSach, int DiemY, int MauChu){
	SetColor(MauChu);
	gotoxy((189-60)/2+1+3,GocY+(31-SoDauSach*2+3)/2-3+4+DiemY);
	cout<<DSDS.node[n]->ISBN;
	gotoxy((189-60)/2+1+3+4+5,GocY+(31-SoDauSach*2+3)/2-3+4+DiemY);
	cout<<DSDS.node[n]->TenSach;
}
void VeTrangTimDauSach(){
	VeTrang(SoTrangTimDauSach,TongTrangTimDauSach,40+50+10+TongCDTimDauSach+1,GocY+4+3+ChieuRongTimDauSach-1,TIEU_DE);
}
void XoaHetDSTDS(){
	for(int t=0; t<ChieuRongTimDauSach; t++)
	{
		XoaThongTin(ChieuDaiTimDauSach,TongThongTinTimDauSach,40+50+10,GocY+4+3+t);
	}
}
void Xuat1TimDauSach(List &DSDS, int n, int DiemY, int ThongTin, int MauChu){
	if(DSDS.node[n]->dms==NULL)
	{
		return;
	}
	SetColor(MauChu);
	PTRDMS p;
	int DiemX;
	int i=0;
	for(p=DSDS.node[n]->dms; p!=NULL; p=p->ptnext)
	{
		if(i==ThongTin)
		{
			DiemX=40+50+10+1;
			gotoxy(DiemX,GocY+4+3+DiemY);
			cout<<p->dm.MaSach;
			
			DiemX+=ChieuDaiTimDauSach[0]+1;
			gotoxy(DiemX,GocY+4+3+DiemY);
			switch(p->dm.TrangThaiSach)
			{
				case 0:
					cout<<"Cho Muon Duoc";
					break;
				case 1:
					cout<<"Da Cho Muon";
					break;
				case 2:
					cout<<"Da Thanh Ly";
					break;
			}
			
			break;
		}
		i++;
	}
}
void XuatTimDauSach(List &DSDS, int n, int MauChu, int ThongTinDau, int ThongTinCuoi){
	if(DSDS.node[n]->dms==NULL)
	{
		return;
	}
	SetColor(MauChu);
	PTRDMS p;
	int DiemX;
	int i=0;
	int j=ThongTinDau;
	SetColor(MauChu);
	for(p=DSDS.node[n]->dms; p!=NULL; p=p->ptnext)
	{
		if(i==ThongTinDau)
		{
			i=0;
			while(j<ThongTinCuoi)
			{
				DiemX=40+50+10+1;
				gotoxy(DiemX,GocY+4+3+i);
				cout<<p->dm.MaSach;
				
				DiemX+=ChieuDaiTimDauSach[0]+1;
				gotoxy(DiemX,GocY+4+3+i);
				switch(p->dm.TrangThaiSach)
				{
					case 0:
						cout<<"Cho Muon Duoc";
						break;
					case 1:
						cout<<"Da Cho Muon";
						break;
					case 2:
						cout<<"Da Thanh Ly";
						break;
				}
				
				i++;
				j++;
				p=p->ptnext;
			}
			break;
		}
		i++;
	}
}
void UpDownTimDauSach(List &DSDS, int n){
	int i=0;
	char b;
	while(1)
	{
		b=getch();
		if(b==-32)
		{
			b=getch();
			if(b==Up && DSDS.node[n]->SoLuong>0)
			{
				if(DSDS.node[n]->SoLuong>ChieuRongTimDauSach)
				{
					if(i==0 && SoTrangTimDauSach==1)
					{
						XoaHetDSTDS();
						XuatTimDauSach(DSDS,n,NOI_DUNG,TongTrangTimDauSach*ChieuRongTimDauSach-ChieuRongTimDauSach,DSDS.node[n]->SoLuong);
						i=(DSDS.node[n]->SoLuong-1)%ChieuRongTimDauSach;
						Xuat1TimDauSach(DSDS,n,i,DSDS.node[n]->SoLuong-1,TIEU_DE);
						SoTrangTimDauSach=TongTrangTimDauSach;
						VeTrangTimDauSach();
					}
					else if(i==0 && SoTrangTimDauSach!=1)
					{
						SoTrangTimDauSach--;
						XoaHetDSTDS();
						XuatTimDauSach(DSDS,n,NOI_DUNG,SoTrangTimDauSach*ChieuRongTimDauSach-ChieuRongTimDauSach,SoTrangTimDauSach*ChieuRongTimDauSach);
						i=ChieuRongTimDauSach-1;
						Xuat1TimDauSach(DSDS,n,i,SoTrangTimDauSach*ChieuRongTimDauSach-1,TIEU_DE);
						VeTrangTimDauSach(); 
					}	
					else if(i>0 && i<ChieuRongTimDauSach)
					{
						Xuat1TimDauSach(DSDS,n,i,(SoTrangTimDauSach*ChieuRongTimDauSach)-(ChieuRongTimDauSach-i),NOI_DUNG);
						i--;
						Xuat1TimDauSach(DSDS,n,i,(SoTrangTimDauSach*ChieuRongTimDauSach)-(ChieuRongTimDauSach-i),TIEU_DE);
					}
				}
				else if(DSDS.node[n]->SoLuong<=ChieuRongTimDauSach)
				{
					TongTrangTimDauSach=1;
					SoTrangTimDauSach=1;
					VeTrangTimDauSach();
					if(i==0)
					{
						Xuat1TimDauSach(DSDS,n,i,i,NOI_DUNG);
						i=DSDS.node[n]->SoLuong-1;
						Xuat1TimDauSach(DSDS,n,i,i,TIEU_DE);
					}
					else if(i>0 && i<DSDS.node[n]->SoLuong)
					{
						Xuat1TimDauSach(DSDS,n,i,i,NOI_DUNG);
						i--;
						Xuat1TimDauSach(DSDS,n,i,i,TIEU_DE);
					}
				} 
			}
			else if(b==Down && DSDS.node[n]->SoLuong>0)
			{
				if(DSDS.node[n]->SoLuong>ChieuRongTimDauSach)
				{
					if(i==(DSDS.node[n]->SoLuong-1)%ChieuRongTimDauSach && SoTrangTimDauSach==TongTrangTimDauSach)
					{
						XoaHetDSTDS();
						XuatTimDauSach(DSDS,n,NOI_DUNG,0,ChieuRongTimDauSach);
						i=0;
						Xuat1TimDauSach(DSDS,n,i,0,TIEU_DE);
						SoTrangTimDauSach=1;
						VeTrangTimDauSach();
					}
					else if(i==ChieuRongTimDauSach-1 && SoTrangTimDauSach!=TongTrangTimDauSach)
					{
						SoTrangTimDauSach++;
						XoaHetDSTDS();
						if(SoTrangTimDauSach==TongTrangTimDauSach)
						{
							XuatTimDauSach(DSDS,n,NOI_DUNG,SoTrangTimDauSach*ChieuRongTimDauSach-ChieuRongTimDauSach,DSDS.node[n]->SoLuong);
						}
						else if(SoTrangTimDauSach!=TongTrangTimDauSach)
						{
							XuatTimDauSach(DSDS,n,NOI_DUNG,SoTrangTimDauSach*ChieuRongTimDauSach-ChieuRongTimDauSach,SoTrangTimDauSach*ChieuRongTimDauSach);
						}
						i=0;
						Xuat1TimDauSach(DSDS,n,i,(SoTrangTimDauSach*ChieuRongTimDauSach)-(ChieuRongTimDauSach-i),TIEU_DE);
						VeTrangTimDauSach();
					}
					else if(i<ChieuRongTimDauSach && i>=0)
					{
						Xuat1TimDauSach(DSDS,n,i,(SoTrangTimDauSach*ChieuRongTimDauSach)-(ChieuRongTimDauSach-i),NOI_DUNG);
						i++;
						Xuat1TimDauSach(DSDS,n,i,(SoTrangTimDauSach*ChieuRongTimDauSach)-(ChieuRongTimDauSach-i),TIEU_DE);
					}
				}
				else if(DSDS.node[n]->SoLuong<=ChieuRongTimDauSach)
				{	
					TongTrangTimDauSach=1;
					SoTrangTimDauSach=1;
					VeTrangTimDauSach();
					if(i==DSDS.node[n]->SoLuong-1)
					{
						Xuat1TimDauSach(DSDS,n,i,i,NOI_DUNG);
						i=0;
						Xuat1TimDauSach(DSDS,n,i,i,TIEU_DE);
					}
					else if(i<DSDS.node[n]->SoLuong && i>=0)
					{
						Xuat1TimDauSach(DSDS,n,i,i,NOI_DUNG);
						i++;
						Xuat1TimDauSach(DSDS,n,i,i,TIEU_DE);
					}
				}
			}
		}
		else if(b==Esc)
		{
			break;
		}
	}
}
int SortTheLoai(List &DSDS, int left, int right){
	DauSach *DS;
	string s=DSDS.node[right]->TheLoai;
	int i=left-1;
	for(int j=left; j<right; j++)
	{
		if(DSDS.node[j]->TheLoai<=s)
		{
			i++;
			DS=DSDS.node[i];
			DSDS.node[i]=DSDS.node[j];
			DSDS.node[j]=DS;
		}
	}
	i++;
	DS=DSDS.node[i];
	DSDS.node[i]=DSDS.node[right];
	DSDS.node[right]=DS;
	return i;
}
void QuickSortTheLoai(List &DSDS, int left, int right){
	if(left>=right)
	{
		return;
	}
	else
	{
		int p=SortTheLoai(DSDS,left,right);
		QuickSortTheLoai(DSDS,left,p-1);
		QuickSortTheLoai(DSDS,p+1,right);
	}
}
int SortTen(List &DSDS, int left, int right){
	DauSach *DS;
	string s=DSDS.node[right]->TenSach;
	int i=left-1;
	for(int j=left; j<right; j++)
	{
		if(DSDS.node[j]->TenSach<=s)
		{
			i++;
			DS=DSDS.node[i];
			DSDS.node[i]=DSDS.node[j];
			DSDS.node[j]=DS;
		}
	}
	i++;
	DS=DSDS.node[i];
	DSDS.node[i]=DSDS.node[right];
	DSDS.node[right]=DS;
	return i;
}
void QuickSortTen(List &DSDS, int left, int right){
	if(left>=right)
	{
		return;
	}
	else
	{
		int p=SortTen(DSDS,left,right);
		QuickSortTen(DSDS,left,p-1);
		QuickSortTen(DSDS,p+1,right);
	}
}
#endif

