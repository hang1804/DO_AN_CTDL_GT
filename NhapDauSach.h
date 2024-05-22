#ifndef NHAPDAUSACH_H
#define NHAPDAUSACH_H
#include "GiaoDienDauSach.h"
#include "NhapDanhMucSach.h"
using namespace std;
string TenTam;
int ViTriDauDauSach;
int DiemYDauSach;
//	Nhap Dau Sach 
void NhapDSDS(List &DSDS, int MauChu){
	ShowCur(1);
	time_t HienTai=time(0);
	tm *Date=localtime(&HienTai);
	int Nam=1900+Date->tm_year;
	string MaISBN;
	DauSach DS;
	int count;
	int DiemX; 
	if(DSDS.n == MAXLIST)
	{
		string s="Danh Sach Da Day";
		VeNoiDungThongBaoDauSach(s);
		return; 
	} 
	else
	{
		if(DSDS.n>0)
		{
			QuickSortTen(DSDS,0,DSDS.n-1);
		}
		TinhSoTrangDauSach(DSDS);
		SoTrangDauSach=TongTrangDauSach;
		VeTrangDauSach();
		if(DSDS.n%ChieuRongDauSach==0)
		{
			DiemYDauSach=0;
		}
		else
		{
			DiemYDauSach=DSDS.n%ChieuRongDauSach;
		}
		if(TongTrangDauSach>1)
		{
			XoaHetDSDS();
			XuatDauSach(DSDS,NOI_DUNG,TongTrangDauSach*ChieuRongDauSach-ChieuRongDauSach,DSDS.n);
			DiemYDauSach=((DSDS.n-1)%ChieuRongDauSach)+1;
		}
		while(DSDS.n != MAXLIST)
		{
			if(DiemYDauSach==ChieuRongDauSach)
			{
				TinhSoTrangDauSach(DSDS);
				SoTrangDauSach=TongTrangDauSach;
				DiemYDauSach=0;
				XoaHetDSDS();
				VeTrangDauSach();
			}
//			NHAP ISBN
			VeQuyDinhNhapISBN();
			while(1)
			{
				count=0; 
				gotoxy(XDauSach+1,YDauSach+3+DiemYDauSach);
				MaISBN=NhapISBN(XThongBaoDauSach,YThongBaoDauSach,MauChu,CDKhungThongBaoDauSach);
				if(DieuKienISBN==1)
				{
					if(DSDS.n!=0 && DiemYDauSach==0)
					{
						DiemYDauSach=ChieuRongDauSach;
						TongTrangDauSach--;
						VeTrangDauSach();
					}
					XoaThongTinDauSach();
					XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
					return; 
				} 	
				for(int i=0; i<DSDS.n; i++)
				{
					if(Upper(MaISBN)==DSDS.node[i]->ISBN)
					{
						count=1;
						VeNoiDungThongBaoDauSach(LoiTrung);
						gotoxy(XDauSach+1,YDauSach+3+DiemYDauSach);
						XoaThongTinDauSach();
						break; 
					}
				}
				if(count==0)
				{
					break; 
				} 
			}
			DS.ISBN=Upper(MaISBN);
			XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
			
//			NHAP TEN SACH
			DiemX=XDauSach+1+ChieuDaiDauSach[0]+1;
			VeQuyDinhNhapChuSo(TongCDDauSach+XDauSach+3,YDauSach+3);
			gotoxy(DiemX,YDauSach+3+DiemYDauSach);
			DS.TenSach=NhapKiTuCoSo(ChieuDaiDauSach[1],XThongBaoDauSach,YThongBaoDauSach,MauChu,CDKhungThongBaoDauSach);
			if(DieuKienKiTu==1)
			{
				if(DSDS.n!=0 && DiemYDauSach==0)
				{
					DiemYDauSach=ChieuRongDauSach;
					TongTrangDauSach--;
					VeTrangDauSach();
				}
				XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
				XoaThongTinDauSach();
				return; 
			} 	
			XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
			
//			NHAP SO TRANG
			DiemX+=ChieuDaiDauSach[1]+1;
			VeQuyDinhNhapSo(TongCDDauSach+XDauSach+3,YDauSach+3);
			gotoxy(DiemX,YDauSach+3+DiemYDauSach);
			DS.SoTrang=NhapSo(ChieuDaiDauSach[2],XThongBaoDauSach,YThongBaoDauSach,MauChu,CDKhungThongBaoDauSach);
			if(DieuKienKiTu==1)
			{
				if(DSDS.n!=0 && DiemYDauSach==0)
				{
					DiemYDauSach=ChieuRongDauSach;
					TongTrangDauSach--;
					VeTrangDauSach();
				}
				XoaThongTinDauSach();
				XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
				return; 
			} 
			XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
			
//			NHAP TAC GIA
			DiemX+=ChieuDaiDauSach[2]+1;
			VeQuyDinhNhapChu(TongCDDauSach+XDauSach+3,YDauSach+3);
			gotoxy(DiemX,YDauSach+3+DiemYDauSach);
			DS.TacGia=NhapKiTuKhongSo(ChieuDaiDauSach[3],XThongBaoDauSach,YThongBaoDauSach,MauChu,CDKhungThongBaoDauSach);
			if(DieuKienKiTu==1)
			{
				if(DSDS.n!=0 && DiemYDauSach==0)
				{
					DiemYDauSach=ChieuRongDauSach;
					TongTrangDauSach--;
					VeTrangDauSach();
				}
				XoaThongTinDauSach();
				XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
				return; 
			} 
			XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
			
//			NHAP NAM XUAT BAN
			long long nxb;
			DiemX+=ChieuDaiDauSach[3]+1;
			VeQuyDinhNhapSo(TongCDDauSach+XDauSach+3,YDauSach+3);
			while(1)
			{
				count=0;
				gotoxy(DiemX,YDauSach+3+DiemYDauSach);
				nxb=NhapSo(ChieuDaiDauSach[4],XThongBaoDauSach,YThongBaoDauSach,MauChu,CDKhungThongBaoDauSach);
				if(DieuKienKiTu==1)
				{
					if(DSDS.n!=0 && DiemYDauSach==0)
					{
						DiemYDauSach=ChieuRongDauSach;
						TongTrangDauSach--;
						VeTrangDauSach();
					}
					XoaThongTinDauSach();
					XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
					return; 
				}
				if(nxb>Nam || nxb<1582)
				{
					count=1;
					Nen();
					VeNoiDungThongBaoDauSach(LoiKhongHopLe);
					gotoxy(DiemX,YDauSach+3+DiemYDauSach);
					for(int i=0; i<ChieuDaiDauSach[4]; i++)
					{
						cout<<" ";
					}
				} 
				if(count==0)
				{
					DS.NamXuatBan=nxb;
					break;
				}
			} 
			XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3); 
			
//			NHAP THE LOAI
			DiemX+=ChieuDaiDauSach[4]+1;
			VeQuyDinhNhapChu(TongCDDauSach+XDauSach+3,YDauSach+3);
			gotoxy(DiemX,YDauSach+3+DiemYDauSach);
			DS.TheLoai=NhapKiTuKhongSo(ChieuDaiDauSach[5],XThongBaoDauSach,YThongBaoDauSach,MauChu,CDKhungThongBaoDauSach);
			gotoxy(DiemX,YDauSach+3+DSDS.n);
			if(DieuKienKiTu==1)
			{
				if(DSDS.n!=0 && DiemYDauSach==0)
				{
					DiemYDauSach=ChieuRongDauSach;
					TongTrangDauSach--;
					VeTrangDauSach();
				}
				XoaThongTinDauSach();
				XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
				return; 
			} 
			XoaQuyDinh(TongCDDauSach+XDauSach+3,YDauSach+3);
			
			
			int x;
			int y; 
			for(x=0; x<DSDS.n && DSDS.node[x]->TenSach < DS.TenSach; x++);
			for(y=DSDS.n-1; y>=x; y--)
			{
				DSDS.node[y+1]=DSDS.node[y];
			} 
			DSDS.node[x]=new DauSach;	
			*DSDS.node[x]=DS;
			DSDS.n++; 
			DiemYDauSach++;
		} 
	} 
}
void TimDauSach(List &DSDS){
	if(DSDS.n==0)
	{
		ShowCur(0);
		string ThongBao="Danh Sach Chua Co Thong Tin";
		SetBGColor(1);
		SetColor(TIEU_DE);
		gotoxy((189-ThongBao.length())/2,GocY+18);
		cout<<ThongBao;
		Sleep(3000);
		gotoxy((189-ThongBao.length())/2,GocY+18);
		cout<<"                                                  ";
		return;
	}
	PTRDMS p;
	string Ten; 
	string TieuDe="TIM THONG TIN DAU SACH";
	string s="Nhap Ten Dau Sach:";
	int SoDauSach=0; 
	VeKhungThongBao(GocX+50,GocY+9,TIEU_DE,CDKhungThongBaoTimDauSach);
	VeKhungChinhSua(TieuDe,s,60,GocY+13,KHUNG,TIEU_DE,60);
	gotoxy(wherex()+1,wherey());
	Ten=NhapKiTuCoSo(40,XThongBaoTimDauSach,YThongBaoTimDauSach,TIEU_DE,CDKhungThongBaoTimDauSach);
	if(DieuKienKiTu==1)
	{
		string s="Tim Khong Thanh Cong";
		VeNoiDungThongBao(s,XThongBaoTimDauSach,YThongBaoTimDauSach,TIEU_DE);
		Sleep(3000);
		XoaNoiDungThongBao(XThongBaoTimDauSach,YThongBaoTimDauSach,CDKhungThongBaoTimDauSach);
		XoaBangDanhSach();
		return;
	}
	int *MangDauSach=new int[100]; 
	for(int i=0; i<DSDS.n; i++)
	{
		if(Upper(DSDS.node[i]->TenSach).find(Upper(Ten))<1000000)
		{
			MangDauSach[SoDauSach]=i;
			SoDauSach++;
		} 
	}
	if(SoDauSach==0)
	{
		string s="Khong Co Du Lieu";
		VeNoiDungThongBao(s,XThongBaoTimDauSach,YThongBaoTimDauSach,TIEU_DE);
		Sleep(3000);
		XoaNoiDungThongBao(XThongBaoTimDauSach,YThongBaoTimDauSach,CDKhungThongBaoTimDauSach);
		XoaBangDanhSach();
		return;
	} 
	else if(SoDauSach==1)
	{
		VeNoiDungThongBao("Tim Thanh Cong",XThongBaoTimDauSach,YThongBaoTimDauSach,TIEU_DE);
		Sleep(3000);
		XoaNoiDungThongBao(XThongBaoTimDauSach,YThongBaoTimDauSach,CDKhungThongBaoTimDauSach);
		for(int z=0; z<11; z++)
		{
			gotoxy(50,GocY+9+z);
			cout<<"                                                                                                                                  ";
		}
		VeKhungCapNhatDauSach(DSDS,40,GocY+8,MangDauSach[0]);
		BangDanhSach(ThongTinTimDauSach,ChieuDaiTimDauSach,ChieuRongTimDauSach,TongThongTinTimDauSach,TIEU_DE,KHUNG,40+50+10,GocY+4);
		SoTrangTimDauSach=1;
		TinhSoTrangDanhMucSach(DSDS,MangDauSach[0]);
		TongTrangTimDauSach=TongTrangDanhMucSach;
		VeTrangTimDauSach();
		if(DSDS.node[MangDauSach[0]]->SoLuong>ChieuRongTimDauSach)
		{
			XuatTimDauSach(DSDS,MangDauSach[0],NOI_DUNG,0,ChieuRongTimDauSach);
		}
		else if(DSDS.node[MangDauSach[0]]->SoLuong<=ChieuRongTimDauSach)
		{
			XuatTimDauSach(DSDS,MangDauSach[0],NOI_DUNG,0,DSDS.node[MangDauSach[0]]->SoLuong);
			TongTrangDanhMucSach=1;
		}
		Xuat1TimDauSach(DSDS,MangDauSach[0],0,0,TIEU_DE);\
		UpDownTimDauSach(DSDS,MangDauSach[0]);
		XoaBangDanhSach();
	}
	else if(SoDauSach>1)
	{
		int x=0;
		VeNoiDungThongBao("Tim Thanh Cong",XThongBaoTimDauSach,YThongBaoTimDauSach,TIEU_DE);
		Sleep(3000);
		XoaNoiDungThongBao(XThongBaoTimDauSach,YThongBaoTimDauSach,CDKhungThongBaoTimDauSach);
		for(int z=0; z<11; z++)
		{
			gotoxy(50,GocY+9+z);
			cout<<"                                                                                                                                  ";
		}
		VeKhungDauSachTimDuoc(60,SoDauSach*2+3,(189-60)/2,GocY+(31-SoDauSach*2+3)/2-3,TIEU_DE,KHUNG);
		XuatDauSachTimDuoc(DSDS,MangDauSach,SoDauSach,NOI_DUNG);
		Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,TIEU_DE);
		char b;
		while(1)
		{
			b=getch();
			if(b==-32)
			{
				b=getch();
				if(b==Up)
				{
					if(x==0)
					{
						Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,NOI_DUNG);
						x=SoDauSach-1;
						Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,TIEU_DE);
					}
					else if(x>0 && x<SoDauSach)
					{
						Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,NOI_DUNG);
						x--;
						Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,TIEU_DE);
					}
				}
				else if(b==Down)
				{
					if(x==SoDauSach-1)
					{
						Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,NOI_DUNG);
						x=0;
						Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,TIEU_DE);
					}
					else if(x>=0 && x<SoDauSach)
					{
						Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,NOI_DUNG);
						x++;
						Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,TIEU_DE);
					}
				}
			}
			else if(b==13)
			{
				XoaBangDanhSach();
				VeKhungCapNhatDauSach(DSDS,40,GocY+8,MangDauSach[x]);
				BangDanhSach(ThongTinTimDauSach,ChieuDaiTimDauSach,ChieuRongTimDauSach,TongThongTinTimDauSach,TIEU_DE,KHUNG,40+50+10,GocY+4);
				SoTrangTimDauSach=1;
				TinhSoTrangDanhMucSach(DSDS,MangDauSach[x]);
				TongTrangTimDauSach=TongTrangDanhMucSach;
				VeTrangTimDauSach();
				if(DSDS.node[MangDauSach[x]]->SoLuong>ChieuRongTimDauSach)
				{
					XuatTimDauSach(DSDS,MangDauSach[x],NOI_DUNG,0,ChieuRongTimDauSach);
				}
				else if(DSDS.node[MangDauSach[x]]->SoLuong<=ChieuRongTimDauSach)
				{
					XuatTimDauSach(DSDS,MangDauSach[x],NOI_DUNG,0,DSDS.node[MangDauSach[x]]->SoLuong);
					TongTrangDanhMucSach=1;
				}
				Xuat1TimDauSach(DSDS,MangDauSach[x],0,0,TIEU_DE);
				UpDownTimDauSach(DSDS,MangDauSach[x]);
				XoaBangDanhSach();
				VeKhungDauSachTimDuoc(60,SoDauSach*2+3,(189-60)/2,GocY+(31-SoDauSach*2+3)/2-3,TIEU_DE,KHUNG);
				XuatDauSachTimDuoc(DSDS,MangDauSach,SoDauSach,NOI_DUNG);
				x=0;
				Xuat1DauSachTimDuoc(DSDS,MangDauSach[x],SoDauSach,x*2,TIEU_DE);
			}
			else if(b==Esc)
			{
				XoaBangDanhSach();
				break;
			}
		}
	}
	delete[] MangDauSach;
}
	
void KiemTraThongTinDauSach(List &DSDS, int i, int j, int MauChu){
	SetColor(MauChu);
	switch(j)
	{
		case 4:
			gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
			cout<<DSDS.node[i]->ISBN;
			break;
		case 6:
			gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
			cout<<TenTam;
			break;
		case 8:
			gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
			cout<<DSDS.node[i]->SoTrang;
			break;
		case 10:
			gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
			cout<<DSDS.node[i]->TacGia;
			break;
		case 12:
			gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
			cout<<DSDS.node[i]->NamXuatBan;
			break;
		case 14:
			gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
			cout<<DSDS.node[i]->TheLoai;
			break;
	}
}
int XoaDauSach(List &DSDS){
	ShowCur(0);
	if(DSDS.n==0)
	{
		VeNoiDungThongBaoDauSach(Rong);
		return -1;
	}
	string TieuDe="XOA THONG TIN DAU SACH";
	string s="Nhap ISBN:";
	int find=0;
	int SoTrang;
	string Ma;
	PTRDMS p;
	VeKhungChinhSua(TieuDe, s, XDauSach+TongCDDauSach+3, YDauSach+2, KHUNG, TIEU_DE, TieuDe.length()+4);
	gotoxy(wherex()+1,wherey());
	Ma=NhapISBN(XThongBaoDauSach, YThongBaoDauSach, NOI_DUNG, CDKhungThongBaoDauSach);
	if(DieuKienISBN==1)
	{
		return find;
	}
	for(int i=0; i<DSDS.n; i++)
	{
		if(Upper(Ma)==DSDS.node[i]->ISBN)
		{
			if(TongTrangDauSach>1)
			{
				Xuat1DauSach(DSDS,ViTriDauDauSach,ChieuRongDauSach*(SoTrangDauSach-1)+ViTriDauDauSach,NOI_DUNG);
			}
			else
			{
				Xuat1DauSach(DSDS,ViTriDauDauSach,ViTriDauDauSach,NOI_DUNG);
			}
			find=i+1;
			if(TongTrangDauSach>1)
			{
				SoTrang=SoTrangDauSach;
				SoTrangDauSach=(find-1)/ChieuRongDauSach+1;
				if(SoTrang==SoTrangDauSach)
				{
					Xuat1DauSach(DSDS,(find-1)-ChieuRongDauSach*(SoTrangDauSach-1),find-1,TIEU_DE);
				}
				else
				{
					XoaHetDSDS();
					if(SoTrangDauSach==TongTrangDauSach)
					{
						XuatDauSach(DSDS,NOI_DUNG,ChieuRongDauSach*(SoTrangDauSach-1),DSDS.n);
					}
					else
					{
						XuatDauSach(DSDS,NOI_DUNG,ChieuRongDauSach*(SoTrangDauSach-1),ChieuRongDauSach*SoTrangDauSach);
					}
					Xuat1DauSach(DSDS,(find-1)-ChieuRongDauSach*(SoTrangDauSach-1),find-1,TIEU_DE);
					VeTrangDauSach();
				}
			}
			else
			{
				SoTrangDauSach=1;
				Xuat1DauSach(DSDS,find-1,find-1,TIEU_DE);
				VeTrangDauSach();
			}
			for(p=DSDS.node[i]->dms; p!=NULL; p=p->ptnext)
			{
				if(p->dm.TrangThaiSach==1 || p->dm.TrangThaiSach==2)
				{
					ViTriDauDauSach=find;
					find=-1;
					return find;
				}
			}
			delete DSDS.node[i];
			for(int j=i+1; j<DSDS.n; j++)
			{
				DSDS.node[j-1]=DSDS.node[j];
			}
			DSDS.n--;
			DiemYDauSach--;
			return find;
		}
	}
	return find;
}
int CapNhatDauSach(List &DSDS){
	ShowCur(0);
	DauSach DS;
	if(DSDS.n==0)
	{
		VeNoiDungThongBaoDauSach(Rong);
		return -1;
	}
	string TieuDe="CAP NHAT THONG TIN DAU SACH";
	string s="Nhap ISBN:";
	int find=0;
	int SoTrang;
	int count;
	int j=4;
	time_t HienTai=time(0);
	tm *Date=localtime(&HienTai);
	int Nam=1900+Date->tm_year;
	string Ma;
	string Ten;
	int c;
	VeKhungChinhSua(TieuDe, s, XDauSach+TongCDDauSach+3, YDauSach+2, KHUNG, TIEU_DE, TieuDe.length()+4);
	gotoxy(wherex()+1,wherey());
	Ma=NhapISBN(XThongBaoDauSach, YThongBaoDauSach, NOI_DUNG, CDKhungThongBaoDauSach);
	if(DieuKienISBN==1)
	{
		return find;
	}
	for(int i=0; i<DSDS.n; i++)
	{
		if(Upper(Ma)==DSDS.node[i]->ISBN)
		{
			if(TongTrangDauSach>1)
			{
				Xuat1DauSach(DSDS,ViTriDauDauSach,ChieuRongDauSach*(SoTrangDauSach-1)+ViTriDauDauSach,NOI_DUNG);
			}
			else
			{
				Xuat1DauSach(DSDS,ViTriDauDauSach,ViTriDauDauSach,NOI_DUNG);
			}	
			find=i+1;
			if(TongTrangDauSach>1)
			{
				SoTrang=SoTrangDauSach;
				SoTrangDauSach=(find-1)/ChieuRongDauSach+1;
				if(SoTrang==SoTrangDauSach)
				{
					Xuat1DauSach(DSDS,(find-1)-ChieuRongDauSach*(SoTrangDauSach-1),find-1,TIEU_DE);
				}
				else
				{
					XoaHetDSDS();
					if(SoTrangDauSach==TongTrangDauSach)
					{
						XuatDauSach(DSDS,NOI_DUNG,ChieuRongDauSach*(SoTrangDauSach-1),DSDS.n);
					}
					else
					{
						XuatDauSach(DSDS,NOI_DUNG,ChieuRongDauSach*(SoTrangDauSach-1),ChieuRongDauSach*SoTrangDauSach);
					}
					Xuat1DauSach(DSDS,(find-1)-ChieuRongDauSach*(SoTrangDauSach-1),find-1,TIEU_DE);
					VeTrangDauSach();
				}
			}
			else
			{
				SoTrangDauSach=1;
				Xuat1DauSach(DSDS,find-1,find-1,TIEU_DE);
				VeTrangDauSach();
			}
			TenTam=DSDS.node[i]->TenSach;
			XoaKhungChinhSua(XDauSach+TongCDDauSach+3, YDauSach+2);
			VeKhungCapNhatDauSach(DSDS,XDauSach+TongCDDauSach+3,YDauSach+2,i);
			SetColor(TIEU_DE);
			gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+4);
			cout<<DSDS.node[i]->ISBN;
			while(1)
			{
				char a;
				a=getch();
				if(a==-32)
				{
					a=getch();
					if(a==Up)
					{
						if(j==4)
						{
							KiemTraThongTinDauSach(DSDS,i,j,NOI_DUNG);
							j=14;
							KiemTraThongTinDauSach(DSDS,i,j,TIEU_DE);
						}
						else if(j>4 && j<=14)
						{
							KiemTraThongTinDauSach(DSDS,i,j,NOI_DUNG);
							j-=2;
							KiemTraThongTinDauSach(DSDS,i,j,TIEU_DE);
						}
					}
					else if(a==Down)
					{
						if(j==14)
						{
							KiemTraThongTinDauSach(DSDS,i,j,NOI_DUNG);
							j=4;
							KiemTraThongTinDauSach(DSDS,i,j,TIEU_DE);
						}
						else if(j>=4 && j<14)
						{
							KiemTraThongTinDauSach(DSDS,i,j,NOI_DUNG);
							j+=2;
							KiemTraThongTinDauSach(DSDS,i,j,TIEU_DE);
						}
					}
				}
				else if(a==BackSpace)
				{
					string ChuoiBanDau;
					int SoBanDau;
					c=wherex();
					gotoxy(c-1,YDauSach+2+j);
					cout<<" "; 
					cout<<"\b";
					switch(j)
					{
						case 4:
							while(1)
							{	
								ChuoiBanDau=DSDS.node[i]->ISBN;
								count=0;
								DSDS.node[i]->ISBN.pop_back();
								Ma=CapNhatISBN(DSDS.node[i]->ISBN,XThongBaoDauSach,YThongBaoDauSach,TIEU_DE,CDKhungThongBaoDauSach);
								if(DieuKienISBN==1)
								{
									DSDS.node[i]->ISBN=ChuoiBanDau;
									gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
									cout<<"                              ";
									gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
									cout<<DSDS.node[i]->ISBN;
									break;
								} 	
								for(int z=0; z<DSDS.n; z++)
								{
									if(Upper(Ma)==DSDS.node[z]->ISBN && Upper(Ma)!=ChuoiBanDau)
									{
										DSDS.node[i]->ISBN=ChuoiBanDau;
										count=1;
										VeNoiDungThongBaoDauSach(LoiTrung);
										gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
										cout<<"                              ";
										gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
										cout<<DSDS.node[i]->ISBN;
										break; 
									}
								}
								if(count==0)
								{
									DSDS.node[i]->ISBN=Upper(Ma);
									for(PTRDMS p=DSDS.node[i]->dms; p!=NULL; p=p->ptnext)
									{
										p->dm.MaSach.replace(0,4,DSDS.node[i]->ISBN);
									}
									break; 
								} 
								else if(count==1 || Upper(Ma)==DSDS.node[i]->ISBN)
								{
									break;
								}
							}
							break;
						case 6:
							if(count!=6)
							{
								TenTam=DSDS.node[i]->TenSach;
							}
							TenTam.pop_back();
							DS.TenSach=CapNhatKiTuCoSo(TenTam,ChieuDaiDauSach[1],XThongBaoDauSach,YThongBaoDauSach,TIEU_DE,CDKhungThongBaoDauSach);
							if(DieuKienKiTu!=1)
							{
								count=6;
								TenTam=DS.TenSach;
							}
							else
							{
								TenTam=DSDS.node[i]->TenSach;
							}
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<"                              ";
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<TenTam;
							break;
						case 8:
							SoBanDau=DSDS.node[i]->SoTrang;
							DSDS.node[i]->SoTrang/=10;
							DS.SoTrang=CapNhatSo(DSDS.node[i]->SoTrang,ChieuDaiDauSach[2],XThongBaoDauSach,YThongBaoDauSach,TIEU_DE,CDKhungThongBaoDauSach);
							if(DieuKienKiTu!=1)
							{
								DSDS.node[i]->SoTrang=DS.SoTrang;
							} 
							else if(DieuKienKiTu==1)
							{
								DSDS.node[i]->SoTrang=SoBanDau;
							}
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<"                              ";
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<DSDS.node[i]->SoTrang;
							break;
						case 10:
							ChuoiBanDau=DSDS.node[i]->TacGia;
							DSDS.node[i]->TacGia.pop_back();
							DS.TacGia=CapNhatKiTuKhongSo(DSDS.node[i]->TacGia,ChieuDaiDauSach[3],XThongBaoDauSach,YThongBaoDauSach,TIEU_DE,CDKhungThongBaoDauSach);
							if(DieuKienKiTu!=1)
							{
								DSDS.node[i]->TacGia=DS.TacGia;
							} 
							else if(DieuKienKiTu==1)
							{
								DSDS.node[i]->TacGia=ChuoiBanDau;	
							}
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<"                              ";
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<DSDS.node[i]->TacGia;
							break;
						case 12:
							SoBanDau=DSDS.node[i]->NamXuatBan;
							DSDS.node[i]->NamXuatBan/=10;
							DS.NamXuatBan=CapNhatSo(DSDS.node[i]->NamXuatBan,ChieuDaiDauSach[4],XThongBaoDauSach,YThongBaoDauSach,TIEU_DE,CDKhungThongBaoDauSach);
							if(DieuKienKiTu!=1 && (DS.NamXuatBan<=Nam && DS.NamXuatBan>=1582))
							{
								DSDS.node[i]->NamXuatBan=DS.NamXuatBan;
							}
							else if(DieuKienKiTu!=1 && (DS.NamXuatBan>Nam || DS.NamXuatBan<1582))
							{
								VeNoiDungThongBaoDauSach(LoiKhongHopLe);
								DSDS.node[i]->NamXuatBan=SoBanDau;
							}
							else if(DieuKienKiTu==1)
							{
								DSDS.node[i]->NamXuatBan=SoBanDau;
							}
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<"                              ";
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<DSDS.node[i]->NamXuatBan;
							break;
						case 14:
							ChuoiBanDau=DSDS.node[i]->TheLoai;
							DSDS.node[i]->TheLoai.pop_back();
							DS.TheLoai=CapNhatKiTuKhongSo(DSDS.node[i]->TheLoai,ChieuDaiDauSach[5],XThongBaoDauSach,YThongBaoDauSach,TIEU_DE,CDKhungThongBaoDauSach);
							if(DieuKienKiTu!=1)
							{
								DSDS.node[i]->TheLoai=DS.TheLoai;
							} 
							else if(DieuKienKiTu==1)
							{
								DSDS.node[i]->TheLoai=ChuoiBanDau;
							}
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<"                              ";
							gotoxy(XDauSach+TongCDDauSach+3+13,YDauSach+2+j);
							cout<<DSDS.node[i]->TheLoai;
							break;
					}
				}
				else if(a==Esc)
				{
					if(DS.TenSach!=DSDS.node[i]->TenSach && count==6)
					{
						QuickSortTen(DSDS,0,DSDS.n-1);
						DauSach c;
						c=*DSDS.node[i];
						int x;
						int y; 
						for(x=0; x<DSDS.n && DSDS.node[x]->TenSach < DS.TenSach; x++);
						for(y=DSDS.n-1; y>=x; y--)
						{
							DSDS.node[y+1]=DSDS.node[y];
						} 
						DSDS.node[x]=new DauSach;	
						*DSDS.node[x]=c;
						DSDS.node[x]->TenSach=DS.TenSach;
						DSDS.n++;
						
						for(int z=0; z<DSDS.n; z++)
						{
							if(c.TenSach==DSDS.node[z]->TenSach)
							{
								delete DSDS.node[z];
								for(int k=z+1; k<DSDS.n; k++)
								{
									DSDS.node[k-1]=DSDS.node[k];
								}
								DSDS.n--;
								break;
							}
						}
					}
					return find;
				}
			}
		}
	}
	return find;
}
void SapXep(List &DSDS){
	QuickSortTheLoai(DSDS,0,DSDS.n-1);
	string ChuoiDau;
	int left=0;
	int right=-1;
	int k=0;
	int count;
	int j;
	while(right<DSDS.n-1)
	{
		count=0;
		ChuoiDau=DSDS.node[k]->TheLoai;
		for(int i=0; i<DSDS.n; i++)
		{
			if(ChuoiDau==DSDS.node[i]->TheLoai)
			{
				count++;
			}
		}
		int j=0;
		while(j<count)
		{
			j++;
			k++;
		}
		left=right+1;
		right=k-1;
		QuickSortTen(DSDS,left,right);
	}
} 
void UpDownDauSach(List &DSDS){
	ShowCur(0);
	int m=0;
	int i=0;
	SoTrangDauSach=1;
	int Xoa;
	int CapNhat;
	char b;
	Xuat1DauSach(DSDS,i,0,TIEU_DE);
	while(1)
	{
		b=getch();
		
////	LEN, XUONG, XOA	
		if(b==-32)
		{
			b=getch();
			if(b==Delete)
			{	
				ViTriDauDauSach=i;
				Xoa=XoaDauSach(DSDS);
				if(Xoa==0 && DieuKienISBN==0)
				{
					VeNoiDungThongBaoDauSach(KhongCoThongTin);
					XoaKhungChinhSua(XDauSach+TongCDDauSach+3,YDauSach+2);
				}
				else if(Xoa==0 && DieuKienISBN==1)
				{
					string s="Xoa Khong Thanh Cong";
					VeNoiDungThongBaoDauSach(s);
					XoaKhungChinhSua(XDauSach+TongCDDauSach+3,YDauSach+2);
				}
				else if(Xoa==-1)
				{
					i=(ViTriDauDauSach-1)-ChieuRongDauSach*(SoTrangDauSach-1);
					string s="Khong The Xoa Khi Doc Gia Dang Muon Hoac Da Thanh Ly";
					VeNoiDungThongBaoDauSach(s);
					XoaKhungChinhSua(XDauSach+TongCDDauSach+3,YDauSach+2);
				}
				else if(Xoa>=1)
				{
					SapXep(DSDS); 
					i=(Xoa-1)-ChieuRongDauSach*(SoTrangDauSach-1);
					string s="Xoa Thanh Cong";
					VeNoiDungThongBaoDauSach(s);
					XoaKhungChinhSua(XDauSach+TongCDDauSach+3,YDauSach+2);
					XoaHetDSDS();
					if(DSDS.n%ChieuRongDauSach==0)
					{
						TongTrangDauSach--;
					}
					if(DSDS.n>ChieuRongDauSach)
					{
						if(SoTrangDauSach<TongTrangDauSach)
						{
							XuatDauSach(DSDS,NOI_DUNG,ChieuRongDauSach*(SoTrangDauSach-1),ChieuRongDauSach*SoTrangDauSach);
						}
						else if(SoTrangDauSach==TongTrangDauSach)
						{
							XuatDauSach(DSDS,NOI_DUNG,ChieuRongDauSach*(SoTrangDauSach-1),DSDS.n);
						}
					}
					else if(DSDS.n<=ChieuRongDauSach)
					{
						XuatDauSach(DSDS,NOI_DUNG,0,DSDS.n);
						TongTrangDauSach=1;
					}
					if(Xoa==DSDS.n+1)
					{
							if(DSDS.n==ChieuRongDanhMucSach)
						{
							i=ChieuRongDauSach-1;
							SoTrangDauSach--;
						}
						else
						{
							i--;
						}
					}
					Xuat1DauSach(DSDS,i,ChieuRongDauSach*(SoTrangDauSach-1)+i,TIEU_DE);
					VeTrangDauSach();
				}
			}
			else if(b==Up && DSDS.n>0)
			{
				if(DSDS.n>ChieuRongDauSach)
				{
					if(i==0 && SoTrangDauSach==1)
					{
						XoaHetDSDS();
						XuatDauSach(DSDS,NOI_DUNG,TongTrangDauSach*ChieuRongDauSach-ChieuRongDauSach,DSDS.n);
						i=(DSDS.n-1)%ChieuRongDauSach;
						Xuat1DauSach(DSDS,i,DSDS.n-1,TIEU_DE);
						SoTrangDauSach=TongTrangDauSach;
						VeTrangDauSach();
					}
					else if(i==0 && SoTrangDauSach!=1)
					{
						SoTrangDauSach--;
						XoaHetDSDS();
						XuatDauSach(DSDS,NOI_DUNG,SoTrangDauSach*ChieuRongDauSach-ChieuRongDauSach,SoTrangDauSach*ChieuRongDauSach);
						i=ChieuRongDauSach-1;
						Xuat1DauSach(DSDS,i,SoTrangDauSach*ChieuRongDauSach-1,TIEU_DE);
						VeTrangDauSach();
					}
					else if(i>0 && i<ChieuRongDauSach)
					{
						Xuat1DauSach(DSDS,i,(SoTrangDauSach*ChieuRongDauSach)-(ChieuRongDauSach-i),NOI_DUNG);
						i--;
						Xuat1DauSach(DSDS,i,(SoTrangDauSach*ChieuRongDauSach)-(ChieuRongDauSach-i),TIEU_DE);
					}
				}
				else if(DSDS.n<=ChieuRongDauSach)
				{
					TongTrangDauSach=1;
					SoTrangDauSach=1;
					VeTrangDauSach();
					if(i==0)
					{
						Xuat1DauSach(DSDS,i,i,NOI_DUNG);
						i=DSDS.n-1;
						Xuat1DauSach(DSDS,i,i,TIEU_DE);
					}
					else if(i>0 && i<DSDS.n)
					{
						Xuat1DauSach(DSDS,i,i,NOI_DUNG);
						i--;
						Xuat1DauSach(DSDS,i,i,TIEU_DE);
					}
				}
			}
			else if(b==Down && DSDS.n>0)
			{
				if(DSDS.n>ChieuRongDauSach)
				{
					if(i==(DSDS.n-1)%ChieuRongDauSach && SoTrangDauSach==TongTrangDauSach)
					{
						XoaHetDSDS();
						XuatDauSach(DSDS,NOI_DUNG,0,ChieuRongDauSach);
						i=0;
						Xuat1DauSach(DSDS,i,0,TIEU_DE);
						SoTrangDauSach=1;
						VeTrangDauSach();
					}
					else if(i==ChieuRongDauSach-1 && SoTrangDauSach!=TongTrangDauSach)
					{
						SoTrangDauSach++;
						XoaHetDSDS();
						if(SoTrangDauSach==TongTrangDauSach)
						{
							XuatDauSach(DSDS,NOI_DUNG,SoTrangDauSach*ChieuRongDauSach-ChieuRongDauSach,DSDS.n);
						}
						else if(SoTrangDauSach!=TongTrangDauSach)
						{
							XuatDauSach(DSDS,NOI_DUNG,SoTrangDauSach*ChieuRongDauSach-ChieuRongDauSach,SoTrangDauSach*ChieuRongDauSach);
						}
						i=0;
						Xuat1DauSach(DSDS,i,(SoTrangDauSach*ChieuRongDauSach)-(ChieuRongDauSach-i),TIEU_DE);
						VeTrangDauSach();
					}
					else if(i<ChieuRongDauSach && i>=0)
					{
						Xuat1DauSach(DSDS,i,(SoTrangDauSach*ChieuRongDauSach)-(ChieuRongDauSach-i),NOI_DUNG);
						i++;
						Xuat1DauSach(DSDS,i,(SoTrangDauSach*ChieuRongDauSach)-(ChieuRongDauSach-i),TIEU_DE);
					}
				}
				else if(DSDS.n<=ChieuRongDauSach)
				{
					TongTrangDauSach=1;
					SoTrangDauSach=1;
					VeTrangDauSach();
					if(i==DSDS.n-1)
					{
						Xuat1DauSach(DSDS,i,i,NOI_DUNG);
						i=0;
						Xuat1DauSach(DSDS,i,i,TIEU_DE);
					}
					else if(i<DSDS.n && i>=0)
					{
						Xuat1DauSach(DSDS,i,i,NOI_DUNG);
						i++;
						Xuat1DauSach(DSDS,i,i,TIEU_DE);
					}
				}
			}
		}
		
////	NHAP DAU SACH, SUA DAU SACH, NHAP DANH MUC SACH
		else if(b==0)
		{
			b=getch();
			if(b==F1)
			{
				Xuat1DauSach(DSDS,i,(SoTrangDauSach*ChieuRongDauSach)-(ChieuRongDauSach-i),NOI_DUNG);
				NhapDSDS(DSDS,NOI_DUNG);
				SapXep(DSDS); 
				XoaHetDSDS();
				SoTrangDauSach=1;
				if(DSDS.n>ChieuRongDauSach)
				{
					XuatDauSach(DSDS,NOI_DUNG,0,ChieuRongDauSach);
				}
				else if(DSDS.n<=ChieuRongDauSach)
				{
					XuatDauSach(DSDS,NOI_DUNG,0,DSDS.n);
					TongTrangDauSach=1;
				}
				VeTrangDauSach();
				i=0;
				Xuat1DauSach(DSDS,i,0,TIEU_DE);
				Nen();
			}
			else if(b==F2)
			{
				ViTriDauDauSach=i;
				CapNhat=CapNhatDauSach(DSDS);
				if(CapNhat==0 && DieuKienISBN==0)
				{
					VeNoiDungThongBaoDauSach(KhongCoThongTin);
					XoaKhungChinhSua(XDauSach+TongCDDauSach+3,YDauSach+2);
				}
				else if(CapNhat==0 && DieuKienISBN==1)
				{
					string s="Tim Khong Thanh Cong";
					VeNoiDungThongBaoDauSach(s);
					XoaKhungChinhSua(XDauSach+TongCDDauSach+3,YDauSach+2);
				}
				else if(CapNhat>=1)
				{
					SapXep(DSDS); 
					i=(CapNhat-1)-ChieuRongDauSach*(SoTrangDauSach-1);
					string s="Cap Nhat Thanh Cong";
					VeNoiDungThongBaoDauSach(s);
					XoaKhungCapNhat(XDauSach+TongCDDauSach+3, YDauSach+2,TongThongTinDauSach*2+3);
					XoaHetDSDS();
					if(DSDS.n>ChieuRongDauSach)
					{
						if(SoTrangDauSach<TongTrangDauSach)
						{
							XuatDauSach(DSDS,NOI_DUNG,ChieuRongDauSach*(SoTrangDauSach-1),ChieuRongDauSach*SoTrangDauSach);
						}
						else if(SoTrangDauSach==TongTrangDauSach)
						{
							XuatDauSach(DSDS,NOI_DUNG,ChieuRongDauSach*(SoTrangDauSach-1),DSDS.n);
						}
					}
					else if(DSDS.n<=ChieuRongDauSach)
					{
						XuatDauSach(DSDS,NOI_DUNG,0,DSDS.n);
						TongTrangDauSach=1;
					}
					Xuat1DauSach(DSDS,i,ChieuRongDauSach*(SoTrangDauSach-1)+i,TIEU_DE);
					VeTrangDauSach();
				}
			}
			else if(b==F3)
			{
				if(DSDS.n==0)
				{
					VeNoiDungThongBaoDauSach(Rong);
				}
				else
				{
					m=TimDauSachDeThem(DSDS);
					if(m==-1 && DieuKienISBN==0)
					{
						VeNoiDungThongBaoDauSach(KhongCoThongTin);
						XoaKhungChinhSua(TongCDDauSach+5,YDauSach+2);
					}
					else if(m==-1 && DieuKienISBN==1)
					{
						string s="Tim Khong Thanh Cong";
						VeNoiDungThongBaoDauSach(s);
						XoaKhungChinhSua(TongCDDauSach+5,YDauSach+2);
					}
					else if(m!=-1)
					{
						PTRDMS p;
						p=DSDS.node[m]->dms;
						XoaBangDanhSach();
						VeKhungThongBao(GocX+50,GocY,TIEU_DE,CDKhungThongBaoDauSach);
						BangDanhMucSach();
						VeKhungCapNhatDauSach(DSDS,2,17,m);
						VePhimDanhMucSach();
						SoTrangDanhMucSach=1;
						if(DSDS.node[m]->SoLuong>ChieuRongDanhMucSach)
						{
							XuatDanhMucSach(DSDS,m,NOI_DUNG,0,ChieuRongDanhMucSach);
							TinhSoTrangDanhMucSach(DSDS,m);
							if(DiemYDanhMucSach==ChieuRongDanhMucSach)
							{
								TongTrangDanhMucSach--;
							}
						}
						else if(DSDS.node[m]->SoLuong<=ChieuRongDanhMucSach)
						{
							XuatDanhMucSach(DSDS,m,NOI_DUNG,0,DSDS.node[m]->SoLuong);
							TongTrangDanhMucSach=1;
						}
						VeTrangDanhMucSach();
						UpDownDanhMucSach(DSDS,m);
						save_DanhMuc(DSDS);
						
////					Ve lai giao dien dau sach
						XoaBangDanhSach();
						VeKhungThongBao(GocX+5,GocY,TIEU_DE,CDKhungThongBaoDauSach);
						BangDauSach();
						VePhimDauSach();
						SoTrangDauSach=1;
						if(DSDS.n>ChieuRongDauSach)
						{
							XuatDauSach(DSDS,NOI_DUNG,0,ChieuRongDauSach);
						}
						else if(DSDS.n<=ChieuRongDauSach)
						{
							XuatDauSach(DSDS,NOI_DUNG,0,DSDS.n);
						}
						VeTrangDauSach();
						i=0;
						Xuat1DauSach(DSDS,i,0,TIEU_DE);
					}
				}
			}
		}
		
////	THOAT
		else if(b==Esc)
		{
			XoaBangDanhSach();
			break;
		}
	}
}
#endif
