#ifndef GIAODIENDANHMUCSACH_H
#define GIAODIENDANHMUCSACH_H
#include "GiaoDien.h"
using namespace std;
void BangDanhMucSach(){
	BangDanhSach(ThongTinDanhMucSach, ChieuDaiDanhMucSach, ChieuRongDanhMucSach, TongThongTinDanhMucSach, TIEU_DE, KHUNG, XDanhMucSach, YDanhMucSach);
}
void VePhimDanhMucSach(){
	VePhim(Them, CHU, NEN_PHIM, XDanhMucSach-1, YDanhMucSach+3+ChieuRongDanhMucSach+1);
	VePhim(CapNhat, CHU, NEN_PHIM, wherex()+3, wherey()-2);
	VePhim(Xoa, CHU, NEN_PHIM, wherex()+3, wherey()-2);
	VePhim(Thoat, CHU, NEN_PHIM, wherex()+3, wherey()-2);
}
void XoaPhimDanhMucSach(){
	XoaPhim(XDanhMucSach-1, YDanhMucSach+3+ChieuRongDanhMucSach+1);
}
void TinhSoTrangDanhMucSach(List &DSDS, int n){
	if(DSDS.node[n]->SoLuong==0)
	{
		TongTrangDanhMucSach=1;
	}
	else if(DSDS.node[n]->SoLuong>0)
	{
			TongTrangDanhMucSach=(DSDS.node[n]->SoLuong/ChieuRongDanhMucSach)+1;
	}
}
void VeNoiDungThongBaoDanhMucSach(string s){
	VeNoiDungThongBao(s,XThongBaoDanhMucSach,YThongBaoDanhMucSach,TIEU_DE);
	Sleep(3000);
	XoaNoiDungThongBao(XThongBaoDanhMucSach,YThongBaoDanhMucSach,CDKhungThongBaoDanhMucSach);
}
void VeTrangDanhMucSach(){
	VeTrang(SoTrangDanhMucSach,TongTrangDanhMucSach,XDanhMucSach+TongCDDanhMucSach+1,YDanhMucSach+3+ChieuRongDanhMucSach-1,TIEU_DE);
}
void XoaThongTinDanhMucSach(){
	XoaThongTin(ChieuDaiDanhMucSach,3,XDanhMucSach,wherey());
}
void XoaHetDSDMS(){
	for(int i=0; i<ChieuRongDanhMucSach; i++)
	{
		XoaThongTin(ChieuDaiDanhMucSach,3,XDanhMucSach,YDanhMucSach+3+i);
	}
}
void DemSoLuong(List &DSDS, int n){
	if(DSDS.node[n]->dms==NULL)
	{
		return;
	}
	for(PTRDMS p=DSDS.node[n]->dms; p!=NULL; p=p->ptnext)
	{
		DSDS.node[n]->SoLuong++;
	}
}
void Xuat1DanhMucSach(List &DSDS, int n, int DiemY, int ThongTin, int MauChu){
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
			DiemX=XDanhMucSach+1;
			gotoxy(DiemX,YDanhMucSach+3+DiemY);
			cout<<p->dm.MaSach;
			
			DiemX+=ChieuDaiDanhMucSach[0]+1;
			gotoxy(DiemX,YDanhMucSach+3+DiemY);
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
			
			DiemX+=ChieuDaiDanhMucSach[1]+1;
			gotoxy(DiemX,YDanhMucSach+3+DiemY);
			cout<<p->dm.ViTri;
			break;
		}
		i++;
	}
}
void XuatDanhMucSach(List &DSDS, int n, int MauChu, int ThongTinDau, int ThongTinCuoi){
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
				DiemX=XDanhMucSach+1;
				gotoxy(DiemX,YDanhMucSach+3+i);
				cout<<p->dm.MaSach;
				
				DiemX+=ChieuDaiDanhMucSach[0]+1;
				gotoxy(DiemX,YDanhMucSach+3+i);
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
				
				DiemX+=ChieuDaiDanhMucSach[1]+1;
				gotoxy(DiemX,YDanhMucSach+3+i);
				cout<<p->dm.ViTri;
				
				i++;
				j++;
				p=p->ptnext;
			}
			break;
		}
		i++;
	}
}
#endif
