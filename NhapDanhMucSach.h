#ifndef NHAPDANHMUCSACH_H
#define NHAPDANHMUCSACH_H
#include "LenhNhap.h"
#include "GiaoDienDanhMucSach.h"
using namespace std;
string tmp;
int DiemYDanhMucSach;
int ViTriDauDanhMucSach;
int TimDauSachDeThem(List &DSDS){
	int ViTriDauSach=-1;
	string ISBNCanTim;
	string TieuDe="NHAP DANH MUC SACH";
	string s="Nhap ISBN: ";
	VeKhungChinhSua(TieuDe,s,TongCDDauSach+5,YDauSach+2,KHUNG,TIEU_DE,TieuDe.length()+4);
	ISBNCanTim=NhapISBN(XThongBaoDauSach,YThongBaoDauSach,NOI_DUNG,CDKhungThongBaoDauSach); 
	if(DieuKienISBN==1)
	{
		return ViTriDauSach;
	}
	for(int i=0; i<DSDS.n; i++)
	{
		if(DSDS.node[i]->ISBN==Upper(ISBNCanTim))
		{
			ViTriDauSach=i;
		} 
	} 
	return ViTriDauSach;
}
//	Nhap Danh Muc Sach 
void NhapDSDMS(List &DSDS, int MauChu, int i){
	SetColor(MauChu);
	char s;
	int DiemX;
	if(DSDS.node[i]->SoLuong%ChieuRongDanhMucSach==0)
	{
		DiemYDanhMucSach=0;
	}
	else
	{
		DiemYDanhMucSach=DSDS.node[i]->SoLuong%ChieuRongDanhMucSach;
	}
	string SoMaSach;
	PTRDMS q;
	int SoThuTu;
	int TrangThai;
	TinhSoTrangDanhMucSach(DSDS,i);
	SoTrangDanhMucSach=TongTrangDanhMucSach;
	VeTrangDanhMucSach();
	for(q=DSDS.node[i]->dms; q!=NULL; q=q->ptnext)
	{
		if(q->ptnext==NULL)
		{
			tmp=q->dm.ViTri;
		}
	}
	if(TongTrangDanhMucSach>1)
	{
		XoaHetDSDMS();
		XuatDanhMucSach(DSDS,i,NOI_DUNG,TongTrangDanhMucSach*ChieuRongDanhMucSach-ChieuRongDanhMucSach,DSDS.node[i]->SoLuong);
		DiemYDanhMucSach=((DSDS.node[i]->SoLuong-1)%ChieuRongDanhMucSach)+1;
	}
	while(1)
	{
		if(DiemYDanhMucSach==ChieuRongDanhMucSach)
		{
			TinhSoTrangDanhMucSach(DSDS,i);
			SoTrangDanhMucSach=TongTrangDanhMucSach;
			DiemYDanhMucSach=0;
			XoaHetDSDMS();
			VeTrangDanhMucSach();
		}
		PTRDMS p=new NodeDMS;
		DiemX=XDanhMucSach+1;
////	MA SACH
		ShowCur(1);
		SetColor(MauChu);
		if(DSDS.node[i]->dms==NULL)
		{
			p->dm.MaSach=DSDS.node[i]->ISBN+"001";
		}
		else if(DSDS.node[i]->dms!=NULL)
		{
			for(q=DSDS.node[i]->dms; q!=NULL; q=q->ptnext)
			{
				if(q->ptnext==NULL)
				{
					SoMaSach=q->dm.MaSach;
				}
			}
			SoThuTu=stoi(SoMaSach.substr(4,3));
			if(SoThuTu==999)
			{
				if(DSDS.node[i]->SoLuong>=999)
				{
					return;
				}
				else if(DSDS.node[i]->SoLuong<999)
				{
					int j=1;
					for(q=DSDS.node[i]->dms; q!=NULL; q=q->ptnext)
					{
						SoThuTu=stoi(q->dm.MaSach.substr(4,3));
						if(j!=SoThuTu)
						{
							if(SoThuTu>0 && SoThuTu<10)
							{
								SoMaSach=to_string(SoThuTu);
								p->dm.MaSach=DSDS.node[i]->ISBN+"00"+SoMaSach;
							} 
							else if(SoThuTu>=10 && SoThuTu<=99)
							{
								SoMaSach=to_string(SoThuTu); 
								p->dm.MaSach=DSDS.node[i]->ISBN+"0"+SoMaSach;
							} 
							else if(SoThuTu>=100 && SoThuTu<=999)
							{
								SoMaSach=to_string(SoThuTu); 
								p->dm.MaSach=DSDS.node[i]->ISBN+SoMaSach;
							} 
							break;	
						}
						j++;
					}
				}
			}
			else if(SoThuTu<999)
			{
				if(SoThuTu+1>0 && SoThuTu+1<10)
				{
					SoMaSach=to_string(SoThuTu+1);
					p->dm.MaSach=DSDS.node[i]->ISBN+"00"+SoMaSach;
				} 
				else if(SoThuTu+1>=10 && SoThuTu+1<=99)
				{
					SoMaSach=to_string(SoThuTu+1); 
					p->dm.MaSach=DSDS.node[i]->ISBN+"0"+SoMaSach;
				} 
				else if(SoThuTu+1>=100 && SoThuTu+1<=999)
				{
					SoMaSach=to_string(SoThuTu+1); 
					p->dm.MaSach=DSDS.node[i]->ISBN+SoMaSach;
				} 
			}
		}
		gotoxy(DiemX,YDanhMucSach+3+DiemYDanhMucSach);
		cout<<p->dm.MaSach;
		while(1)
		{
			s=getch();
			if(s==13)
			{
				break;
			}
			else if(s!=13 && s!=Esc)
			{
				ShowCur(0);
				string s="Phim Khong Hop Le";
				VeNoiDungThongBaoDanhMucSach(s);
				gotoxy(DiemX+p->dm.MaSach.length(),YDanhMucSach+3+DiemYDanhMucSach);
				ShowCur(1);
			}
			else if(s==Esc)
			{
				if(DSDS.node[i]->SoLuong!=0 && DiemYDanhMucSach==0)
				{
					DiemYDanhMucSach=ChieuRongDanhMucSach;
					TongTrangDanhMucSach--;
					VeTrangDanhMucSach();
				}
				XoaThongTinDanhMucSach();
				ShowCur(0);
				return;
			}
		}
		
		
////		TRANG THAI SACH	
		SetColor(MauChu);
		DiemX+=ChieuDaiDanhMucSach[0]+1;
		p->dm.TrangThaiSach=0;
		gotoxy(DiemX,YDanhMucSach+3+DiemYDanhMucSach);
		cout<<"Cho Muon Duoc"; 
		while(1)
		{
			s=getch();
			if(s==13)
			{
				break;
			}
			else if(s!=13 && s!=Esc)
			{
				ShowCur(0);
				string s="Phim Khong Hop Le";
				VeNoiDungThongBaoDanhMucSach(s);
				gotoxy(DiemX+1,YDanhMucSach+3+DiemYDanhMucSach);
				ShowCur(1);
			}
			else if(s==Esc)
			{
				if(DSDS.node[i]->SoLuong!=0 && DiemYDanhMucSach==0)
				{
					DiemYDanhMucSach=ChieuRongDanhMucSach;
					TongTrangDanhMucSach--;
					VeTrangDanhMucSach();
				}
				XoaThongTinDanhMucSach();
				ShowCur(0);
				return;
			}
		}
	
////	VI TRI SACH
		DiemX+=ChieuDaiDanhMucSach[1]+1;
		if(DSDS.node[i]->dms==NULL)
		{
			SetColor(MauChu);
			VeQuyDinhNhapChuSo(TongCDDanhMucSach+XDanhMucSach+8,YDanhMucSach+6);
			gotoxy(DiemX,YDanhMucSach+3+DiemYDanhMucSach);
			tmp=NhapKiTuCoSo(ChieuDaiDanhMucSach[2],XThongBaoDanhMucSach,YThongBaoDanhMucSach,NOI_DUNG,CDKhungThongBaoDanhMucSach); 
			p->dm.ViTri=tmp;
			XoaQuyDinh(TongCDDanhMucSach+XDanhMucSach+8,YDanhMucSach+6);
			if(DieuKienKiTu==1)
			{
				XoaThongTinDanhMucSach();
				ShowCur(0);
				return;
			}
		}
		else if(DSDS.node[i]->dms!=NULL)
		{
			for(PTRDMS q=DSDS.node[i]->dms; q!=NULL; q=q->ptnext)
			{
				if(q->dm.ViTri!="" && q!=NULL)
				{
					tmp=q->dm.ViTri;
				}
			}
			SetColor(MauChu);
			gotoxy(DiemX,YDanhMucSach+3+DiemYDanhMucSach);
			cout<<tmp;
			while(1)
			{
				s=getch();
				if(s==BackSpace)
				{
					for(int j=0; j<ChieuDaiDanhMucSach[2]; j++)
					{
						gotoxy(DiemX+j,YDanhMucSach+3+DiemYDanhMucSach);
						cout<<" ";
					}
					VeQuyDinhNhapChuSo(TongCDDanhMucSach+XDanhMucSach+3,YDanhMucSach+3);
					gotoxy(DiemX,YDanhMucSach+3+DiemYDanhMucSach);
					tmp=NhapKiTuCoSo(ChieuDaiDanhMucSach[2],XThongBaoDanhMucSach,YThongBaoDanhMucSach,NOI_DUNG,CDKhungThongBaoDanhMucSach); 
					if(DieuKienKiTu==1)
					{
						if(DSDS.node[i]->SoLuong!=0 && DiemYDanhMucSach==0)
						{
							DiemYDanhMucSach=ChieuRongDanhMucSach;
							TongTrangDanhMucSach--;
							VeTrangDanhMucSach();
						}
						XoaThongTinDanhMucSach();
						ShowCur(0);
						return;
					}
					p->dm.ViTri=tmp;
					XoaQuyDinh(TongCDDanhMucSach+XDanhMucSach+3,YDanhMucSach+3);
				}
				else if(s!=13 && s!=Esc)
				{
					ShowCur(0);
					string s="Phim Khong Hop Le";
					VeNoiDungThongBaoDanhMucSach(s);
					gotoxy(DiemX+tmp.length(),YDanhMucSach+3+DiemYDanhMucSach);
					ShowCur(1);
				}
				else if(s==13)
				{
					p->dm.ViTri=tmp;
					break;
				}
				else if(s==Esc)
				{
					if(DSDS.node[i]->SoLuong!=0 && DiemYDanhMucSach==0)
					{
						DiemYDanhMucSach=ChieuRongDanhMucSach;
						TongTrangDanhMucSach--;
						VeTrangDanhMucSach();
					}
					XoaThongTinDanhMucSach();
					ShowCur(0);
					return;	
				}
			}
		}
		
			
		p->ptnext=NULL;
		
		if(DSDS.node[i]->dms==NULL) 
		{
			DSDS.node[i]->dms=p; 
		} 
		else
		{
			PTRDMS Last;
			for(Last=DSDS.node[i]->dms; Last->ptnext!=NULL; Last=Last->ptnext);
			Last->ptnext=p; 
		} 
		DSDS.node[i]->SoLuong++;
		DiemYDanhMucSach++;
		ShowCur(0);
	}
} 
int XoaDanhMucSach(List &DSDS, int n){
	ShowCur(0);
	if(DSDS.node[n]->dms==NULL)
	{
		VeNoiDungThongBao(Rong,XThongBaoDanhMucSach,YThongBaoDanhMucSach,TIEU_DE);
		Sleep(3000);
		XoaNoiDungThongBao(XThongBaoDanhMucSach,YThongBaoDanhMucSach,CDKhungThongBaoDanhMucSach);
		return -1;
	}
	PTRDMS p;
	string MS;
	int SoTrang;
	int So;
	string TieuDe="XOA THONG TIN DANH MUC SACH";
	string s="Nhap Ma Sach:";
	int find=0;
	VeKhungChinhSua(TieuDe,s,XDanhMucSach+TongCDDanhMucSach+10,YDanhMucSach+5,KHUNG,TIEU_DE,TieuDe.length()+4);
	gotoxy(wherex()+1,wherey());
	SetColor(NOI_DUNG); 
	cout<<DSDS.node[n]->ISBN;
	So=NhapSo(3,XThongBaoDanhMucSach,YThongBaoDanhMucSach,NOI_DUNG,CDKhungThongBaoDanhMucSach);
	if(DieuKienKiTu==1)
	{
		return find;
	}
	if(So>0 && So<10)
	{
		MS=DSDS.node[n]->ISBN+"00"+to_string(So);
	} 
	else if(So>=10 && So<=99)
	{
		MS=DSDS.node[n]->ISBN+"0"+to_string(So);
	} 
	else if(So>=100 && So<=999)
	{
		MS=DSDS.node[n]->ISBN+to_string(So);
	} 
	p=DSDS.node[n]->dms;
	
//// Xoa Phan Tu Dau	
	if(p->dm.MaSach==MS)
	{
		if(TongTrangDanhMucSach>1)
		{
			Xuat1DanhMucSach(DSDS,n,ViTriDauDanhMucSach,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1)+ViTriDauDanhMucSach,NOI_DUNG);
		}
		else
		{
			Xuat1DanhMucSach(DSDS,n,ViTriDauDanhMucSach,ViTriDauDanhMucSach,NOI_DUNG);
		}
		find+=1;
		SoTrang=1;
		if(SoTrang!=SoTrangDanhMucSach)
		{
			SoTrangDanhMucSach=SoTrang;
			XoaHetDSDMS();
			if(TongTrangDanhMucSach>1)
			{
				XuatDanhMucSach(DSDS,n,NOI_DUNG,0,ChieuRongDanhMucSach*SoTrangDanhMucSach);
			}
			else
			{
				XuatDanhMucSach(DSDS,n,NOI_DUNG,0,DSDS.node[n]->SoLuong);
			}
			Xuat1DanhMucSach(DSDS,n,find-1,find-1,TIEU_DE);
			VeTrangDanhMucSach();
		}
		else
		{
			Xuat1DanhMucSach(DSDS,n,find-1,find-1,TIEU_DE);
		}
		if(p->dm.TrangThaiSach==1 || p->dm.TrangThaiSach==2)
		{
			ViTriDauDanhMucSach=find;
			find=-1;
			return find;
		}
		PTRDMS q;
		q=DSDS.node[n]->dms;
		DSDS.node[n]->dms=q->ptnext;
		delete q;
		DSDS.node[n]->SoLuong--;
		return find;
	}
	
//// Xoa Phan Tu Giua Va Cuoi	
	for(p=DSDS.node[n]->dms; p->ptnext!=NULL && p->ptnext->dm.MaSach!=MS; p=p->ptnext)
	{
		find++; 
	}
	if(TongTrangDanhMucSach>1)
	{
		Xuat1DanhMucSach(DSDS,n,ViTriDauDanhMucSach,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1)+ViTriDauDanhMucSach,NOI_DUNG);
	}
	else
	{
		Xuat1DanhMucSach(DSDS,n,ViTriDauDanhMucSach,ViTriDauDanhMucSach,NOI_DUNG);
	}
	find+=2;
	if(TongTrangDanhMucSach>1)
	{
		SoTrang=SoTrangDanhMucSach;
		SoTrangDanhMucSach=(find-1)/ChieuRongDanhMucSach+1;
		if(SoTrang==SoTrangDanhMucSach)
		{
			Xuat1DanhMucSach(DSDS,n,(find-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),find-1,TIEU_DE);
		}
		else
		{
			XoaHetDSDMS();
			if(SoTrangDanhMucSach==TongTrangDanhMucSach)
			{
				XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),DSDS.node[n]->SoLuong);
			}
			else
			{
				XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),ChieuRongDanhMucSach*SoTrangDanhMucSach);
			}
			Xuat1DanhMucSach(DSDS,n,(find-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),find-1,TIEU_DE);
			VeTrangDanhMucSach();
		}
	}
	else
	{
		SoTrangDanhMucSach=1; 
		Xuat1DanhMucSach(DSDS,n,find-1,find-1,TIEU_DE);
		VeTrangDanhMucSach();
	}
	if(p->ptnext->dm.TrangThaiSach==1 || p->ptnext->dm.TrangThaiSach==2)
	{
		ViTriDauDanhMucSach=find;
		find=-1;
		return find;
	}
	if(p->ptnext!=NULL)
	{
		PTRDMS q;
		q=p->ptnext;
		p->ptnext=q->ptnext;
		delete q;
	}
	DSDS.node[n]->SoLuong--;
	DiemYDanhMucSach--;
	return find;
}
int CapNhatDanhMucSach(List &DSDS, int n){
	ShowCur(0);
	if(DSDS.node[n]->dms==NULL)
	{
		VeNoiDungThongBao(Rong,XThongBaoDanhMucSach,YThongBaoDanhMucSach,TIEU_DE);
		Sleep(3000);
		XoaNoiDungThongBao(XThongBaoDanhMucSach,YThongBaoDanhMucSach,CDKhungThongBaoDanhMucSach);
		return -1;
	}
	PTRDMS p;
	DanhMuc DM;
	string MS;
	int So;
	string TieuDe="CAP NHAT THONG TIN DANH MUC SACH";
	string s="Nhap Ma Sach:";
	int find=0;
	int j=6;
	int c;
	int SoTrang;
	VeKhungChinhSua(TieuDe,s,XDanhMucSach+TongCDDanhMucSach+3,YDanhMucSach+2,KHUNG,TIEU_DE,TieuDe.length()+4);
	gotoxy(wherex()+1,wherey());
	SetColor(NOI_DUNG); 
	cout<<DSDS.node[n]->ISBN;
	So=NhapSo(3,XThongBaoDanhMucSach,YThongBaoDanhMucSach,NOI_DUNG,CDKhungThongBaoDanhMucSach);
	if(DieuKienKiTu==1)
	{
		return find;
	}
	if(So>0 && So<10)
	{
		MS=DSDS.node[n]->ISBN+"00"+to_string(So);
	} 
	else if(So>=10 && So<=99)
	{
		MS=DSDS.node[n]->ISBN+"0"+to_string(So);
	} 
	else if(So>=100 && So<=999)
	{
		MS=DSDS.node[n]->ISBN+to_string(So);
	} 
	for(p=DSDS.node[n]->dms; p!=NULL; p=p->ptnext)
	{
		if(p->dm.MaSach==MS)
		{
			if(TongTrangDanhMucSach>1)
			{
				Xuat1DanhMucSach(DSDS,n,ViTriDauDanhMucSach,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1)+ViTriDauDanhMucSach,NOI_DUNG);
			}
			else
			{
				Xuat1DanhMucSach(DSDS,n,ViTriDauDanhMucSach,ViTriDauDanhMucSach,NOI_DUNG);
			}
			find++;
			if(TongTrangDanhMucSach>1)
			{
				SoTrang=SoTrangDanhMucSach;
				SoTrangDanhMucSach=(find-1)/ChieuRongDanhMucSach+1;
				if(SoTrang==SoTrangDanhMucSach)
				{
					Xuat1DanhMucSach(DSDS,n,(find-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),find-1,TIEU_DE);
				}
				else
				{
					XoaHetDSDMS();
					if(SoTrangDanhMucSach==TongTrangDanhMucSach)
					{
						XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),DSDS.node[n]->SoLuong);
					}
					else
					{
						XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),ChieuRongDanhMucSach*SoTrangDanhMucSach);
					}
					Xuat1DanhMucSach(DSDS,n,(find-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),find-1,TIEU_DE);
					VeTrangDanhMucSach();
				}
			}
			else
			{
				SoTrangDanhMucSach=1; 
				Xuat1DanhMucSach(DSDS,n,find-1,find-1,TIEU_DE);
				VeTrangDanhMucSach();
			}
			
			if(p->dm.TrangThaiSach==2)
			{
				ViTriDauDanhMucSach=find;
				find=-2;
				return find;
			}
			
			XoaKhungChinhSua(XDanhMucSach+TongCDDanhMucSach+3,YDanhMucSach+2);
			VeKhungCapNhat(ThongTinDanhMucSach,XDanhMucSach+TongCDDanhMucSach+3,YDanhMucSach+2,40,TongThongTinDanhMucSach*2+3,KHUNG,TIEU_DE,TIEU_DE);
			
			if(TongTrangDanhMucSach>1)
			{
				SoTrang=SoTrangDanhMucSach;
				SoTrangDanhMucSach=(find-1)/ChieuRongDanhMucSach+1;
				if(SoTrang==SoTrangDanhMucSach)
				{
					Xuat1DanhMucSach(DSDS,n,(find-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),find-1,TIEU_DE);
				}
				else
				{
					XoaHetDSDMS();
					if(SoTrangDanhMucSach==TongTrangDanhMucSach)
					{
						XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),DSDS.node[n]->SoLuong);
					}
					else
					{
						XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),ChieuRongDanhMucSach*SoTrangDanhMucSach);
					}
					Xuat1DanhMucSach(DSDS,n,(find-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),find-1,TIEU_DE);
					VeTrangDanhMucSach();
				}
			}
			else
			{
				SoTrangDanhMucSach=1; 
				Xuat1DanhMucSach(DSDS,n,find-1,find-1,TIEU_DE);
				VeTrangDanhMucSach();
			}
			
			SetColor(NOI_DUNG);
			gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+4);
			cout<<p->dm.MaSach;
			gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+8);
			cout<<p->dm.ViTri;
			SetColor(TIEU_DE);
			gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+6);
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
			while(1)
			{
				char a;
				a=getch();
				if(a==-32)
				{
					a=getch();
					if(a==Up || a==Down)
					{
						if(j==6)
						{
							SetColor(NOI_DUNG);
							gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
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
							j=8;
							SetColor(TIEU_DE);
							gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
							cout<<p->dm.ViTri;
						}
						else if(j==8)
						{
							SetColor(NOI_DUNG);
							gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
							cout<<p->dm.ViTri;	
							j=6;
							SetColor(TIEU_DE);
							gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
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
						}
					}
				}
				else if(a==BackSpace)
				{
					switch(j)
					{
						case 6:
						{
							gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
							cout<<"               ";
							gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
							DM.TrangThaiSach=NhapSo(15,XThongBaoDanhMucSach,YThongBaoDanhMucSach,TIEU_DE,CDKhungThongBaoDanhMucSach);
							if((DM.TrangThaiSach>=0 && DM.TrangThaiSach<=2) && DM.TrangThaiSach!=p->dm.TrangThaiSach && DieuKienKiTu!=1)
							{
								p->dm.TrangThaiSach=DM.TrangThaiSach;
							}
							else if((DM.TrangThaiSach<0 || DM.TrangThaiSach>2))
							{
								VeNoiDungThongBao(LoiKhongHopLe,XThongBaoDanhMucSach,YThongBaoDanhMucSach,TIEU_DE);
								Sleep(3000);
								XoaNoiDungThongBao(XThongBaoDanhMucSach,YThongBaoDanhMucSach,CDKhungThongBaoDanhMucSach);
							}
							gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
							cout<<"                          ";
							gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
							if(p->dm.TrangThaiSach==0)
							{
								cout<<"Cho Muon Duoc";
							}
							else if(p->dm.TrangThaiSach==1)
							{
								cout<<"Da Cho Muon";
							}
							else if(p->dm.TrangThaiSach==2)
							{
								cout<<"Da Thanh Ly";
							}
							break;
						}
						case 8:
							if(p->dm.TrangThaiSach==0)
							{
								string ChuoiBanDau;
								ChuoiBanDau=p->dm.ViTri;
								c=wherex();
								gotoxy(c-1,YDanhMucSach+2+j);
								cout<<" ";
								cout<<"\b";
								p->dm.ViTri.pop_back();
								DM.ViTri=CapNhatKiTuCoSo(p->dm.ViTri,15,XThongBaoDanhMucSach,YThongBaoDanhMucSach,TIEU_DE,CDKhungThongBaoDanhMucSach);	
								if(DM.ViTri!=ChuoiBanDau && DieuKienKiTu!=1)
								{
									p->dm.ViTri=DM.ViTri;
								}
								else if(DieuKienKiTu==1)
								{
									p->dm.ViTri=ChuoiBanDau;
								}
								gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
								cout<<"                          ";
								gotoxy(XDanhMucSach+TongCDDanhMucSach+3+3+12,YDanhMucSach+2+j);
								cout<<p->dm.ViTri;
							}
							break;
					}	
				}
				else if(a==Esc)
				{
					return find;
				}
			}
		}
		find++; 
	}
	find=0;
	return find;
}
void UpDownDanhMucSach(List &DSDS, int n){
	ShowCur(0);
	PTRDMS p;
	p=DSDS.node[n]->dms;
	int i=0;
	int Xoa;
	int CapNhat;
	Xuat1DanhMucSach(DSDS,n,i,0,TIEU_DE);
	while(1)
	{
		char b;
		b=getch();
		if(b==-32)
		{
			b=getch();
			if(b==Delete)
			{
				ViTriDauDanhMucSach=i;
				Xoa=XoaDanhMucSach(DSDS,n);	
				if(Xoa==0 && DieuKienKiTu==0)
				{
					VeNoiDungThongBaoDanhMucSach(KhongCoThongTin);
					XoaKhungChinhSua(XDanhMucSach+TongCDDanhMucSach+10,YDanhMucSach+5);
				}
				else if(Xoa==0 && DieuKienKiTu==1)
				{
					string s="Xoa Khong Thanh Cong";
					VeNoiDungThongBaoDanhMucSach(s);
					XoaKhungChinhSua(XDanhMucSach+TongCDDanhMucSach+10,YDanhMucSach+5);	
				}
				else if(Xoa==-1)
				{
					i=(ViTriDauDanhMucSach-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1);
					string s="Khong The Xoa Khi Doc Gia Dang Muon Hoac Da Thanh Ly";
					VeNoiDungThongBaoDanhMucSach(s);
					XoaKhungChinhSua(XDanhMucSach+TongCDDanhMucSach+10,YDanhMucSach+5);	
				}
				if(Xoa>=1)
				{
					i=(Xoa-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1);
					string s="Xoa Thanh Cong";
					VeNoiDungThongBaoDanhMucSach(s);
					XoaKhungChinhSua(XDanhMucSach+TongCDDanhMucSach+10,YDanhMucSach+5);
					XoaHetDSDMS();
					if(DSDS.node[n]->SoLuong%ChieuRongDanhMucSach==0)
					{
						TongTrangDanhMucSach--;
					}
					if(DSDS.node[n]->SoLuong>ChieuRongDanhMucSach)
					{
						if(SoTrangDanhMucSach<TongTrangDanhMucSach)
						{
							XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),ChieuRongDanhMucSach*SoTrangDanhMucSach);
						}
						else if(SoTrangDanhMucSach==TongTrangDanhMucSach)
						{
							XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),DSDS.node[n]->SoLuong);
						}
					}
					else if(DSDS.node[n]->SoLuong<=ChieuRongDanhMucSach)
					{
						XuatDanhMucSach(DSDS,n,NOI_DUNG,0,DSDS.node[n]->SoLuong);
						TongTrangDanhMucSach=1;
					}
					if(Xoa==DSDS.node[n]->SoLuong+1)
					{
						if(DSDS.node[n]->SoLuong==ChieuRongDanhMucSach)
						{
							i=ChieuRongDanhMucSach-1;
							SoTrangDanhMucSach--;
						}
						else
						{
							i--;
						}
					}
					Xuat1DanhMucSach(DSDS,n,i,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1)+i,TIEU_DE);
					VeTrangDanhMucSach();
				}
			}
			else if(b==Up && DSDS.node[n]->SoLuong>0)
			{
				if(DSDS.node[n]->SoLuong>ChieuRongDanhMucSach)
				{
					if(i==0 && SoTrangDanhMucSach==1)
					{
						XoaHetDSDMS();
						XuatDanhMucSach(DSDS,n,NOI_DUNG,TongTrangDanhMucSach*ChieuRongDanhMucSach-ChieuRongDanhMucSach,DSDS.node[n]->SoLuong);
						i=(DSDS.node[n]->SoLuong-1)%ChieuRongDanhMucSach;
						Xuat1DanhMucSach(DSDS,n,i,DSDS.node[n]->SoLuong-1,TIEU_DE);
						SoTrangDanhMucSach=TongTrangDanhMucSach;
						VeTrangDanhMucSach();
					}
					else if(i==0 && SoTrangDanhMucSach!=1)
					{
						SoTrangDanhMucSach--;
						XoaHetDSDMS();
						XuatDanhMucSach(DSDS,n,NOI_DUNG,SoTrangDanhMucSach*ChieuRongDanhMucSach-ChieuRongDanhMucSach,SoTrangDanhMucSach*ChieuRongDanhMucSach);
						i=ChieuRongDanhMucSach-1;
						Xuat1DanhMucSach(DSDS,n,i,SoTrangDanhMucSach*ChieuRongDanhMucSach-1,TIEU_DE);
						VeTrangDanhMucSach(); 
					}	
					else if(i>0 && i<ChieuRongDanhMucSach)
					{
						Xuat1DanhMucSach(DSDS,n,i,(SoTrangDanhMucSach*ChieuRongDanhMucSach)-(ChieuRongDanhMucSach-i),NOI_DUNG);
						i--;
						Xuat1DanhMucSach(DSDS,n,i,(SoTrangDanhMucSach*ChieuRongDanhMucSach)-(ChieuRongDanhMucSach-i),TIEU_DE);
					}
				}
				else if(DSDS.node[n]->SoLuong<=ChieuRongDanhMucSach)
				{
					TongTrangDanhMucSach=1;
					SoTrangDanhMucSach=1;
					VeTrangDanhMucSach();
					if(i==0)
					{
						Xuat1DanhMucSach(DSDS,n,i,i,NOI_DUNG);
						i=DSDS.node[n]->SoLuong-1;
						Xuat1DanhMucSach(DSDS,n,i,i,TIEU_DE);
					}
					else if(i>0 && i<DSDS.node[n]->SoLuong)
					{
						Xuat1DanhMucSach(DSDS,n,i,i,NOI_DUNG);
						i--;
						Xuat1DanhMucSach(DSDS,n,i,i,TIEU_DE);
					}
				} 
			}
			else if(b==Down && DSDS.node[n]->SoLuong>0)
			{
				if(DSDS.node[n]->SoLuong>ChieuRongDanhMucSach)
				{
					if(i==(DSDS.node[n]->SoLuong-1)%ChieuRongDanhMucSach && SoTrangDanhMucSach==TongTrangDanhMucSach)
					{
						XoaHetDSDMS();
						XuatDanhMucSach(DSDS,n,NOI_DUNG,0,ChieuRongDanhMucSach);
						i=0;
						Xuat1DanhMucSach(DSDS,n,i,0,TIEU_DE);
						SoTrangDanhMucSach=1;
						VeTrangDanhMucSach();
					}
					else if(i==ChieuRongDanhMucSach-1 && SoTrangDanhMucSach!=TongTrangDanhMucSach)
					{
						SoTrangDanhMucSach++;
						XoaHetDSDMS();
						if(SoTrangDanhMucSach==TongTrangDanhMucSach)
						{
							XuatDanhMucSach(DSDS,n,NOI_DUNG,SoTrangDanhMucSach*ChieuRongDanhMucSach-ChieuRongDanhMucSach,DSDS.node[n]->SoLuong);
						}
						else if(SoTrangDanhMucSach!=TongTrangDanhMucSach)
						{
							XuatDanhMucSach(DSDS,n,NOI_DUNG,SoTrangDanhMucSach*ChieuRongDanhMucSach-ChieuRongDanhMucSach,SoTrangDanhMucSach*ChieuRongDanhMucSach);
						}
						i=0;
						Xuat1DanhMucSach(DSDS,n,i,(SoTrangDanhMucSach*ChieuRongDanhMucSach)-(ChieuRongDanhMucSach-i),TIEU_DE);
						VeTrangDanhMucSach();
					}
					else if(i<ChieuRongDanhMucSach && i>=0)
					{
						Xuat1DanhMucSach(DSDS,n,i,(SoTrangDanhMucSach*ChieuRongDanhMucSach)-(ChieuRongDanhMucSach-i),NOI_DUNG);
						i++;
						Xuat1DanhMucSach(DSDS,n,i,(SoTrangDanhMucSach*ChieuRongDanhMucSach)-(ChieuRongDanhMucSach-i),TIEU_DE);
					}
				}
				else if(DSDS.node[n]->SoLuong<=ChieuRongDanhMucSach)
				{	
					TongTrangDanhMucSach=1;
					SoTrangDanhMucSach=1;
					VeTrangDanhMucSach();
					if(i==DSDS.node[n]->SoLuong-1)
					{
						Xuat1DanhMucSach(DSDS,n,i,i,NOI_DUNG);
						i=0;
						Xuat1DanhMucSach(DSDS,n,i,i,TIEU_DE);
					}
					else if(i<DSDS.node[n]->SoLuong && i>=0)
					{
						Xuat1DanhMucSach(DSDS,n,i,i,NOI_DUNG);
						i++;
						Xuat1DanhMucSach(DSDS,n,i,i,TIEU_DE);
					}
				}
			}
		}
		else if(b==0)
		{
			b=getch();
			if(b==F1)
			{
				Xuat1DanhMucSach(DSDS,n,i,(SoTrangDanhMucSach*ChieuRongDanhMucSach)-(ChieuRongDanhMucSach-i),NOI_DUNG);
				NhapDSDMS(DSDS,NOI_DUNG,n);
				XoaHetDSDMS();
				SoTrangDanhMucSach=1;
				if(DSDS.node[n]->SoLuong>ChieuRongDanhMucSach)
				{
					XuatDanhMucSach(DSDS,n,NOI_DUNG,0,ChieuRongDanhMucSach);
				}
				else if(DSDS.node[n]->SoLuong<=ChieuRongDanhMucSach)
				{
					XuatDanhMucSach(DSDS,n,NOI_DUNG,0,DSDS.node[n]->SoLuong);
					TongTrangDanhMucSach=1;
				}
				VeTrangDanhMucSach();
				i=0;
				Xuat1DanhMucSach(DSDS,n,i,0,TIEU_DE);
				Nen();
			}
			else if(b==F2)
			{
				ViTriDauDanhMucSach=i;
				CapNhat=CapNhatDanhMucSach(DSDS,n);	
				if(CapNhat==0 && DieuKienKiTu==0)
				{
					VeNoiDungThongBaoDanhMucSach(KhongCoThongTin);
					XoaKhungChinhSua(XDanhMucSach+TongCDDanhMucSach+3,YDanhMucSach+2);
				}	
				else if(CapNhat==0 && DieuKienKiTu==1)
				{
					string s="Tim Khong Thanh Cong";
					VeNoiDungThongBaoDanhMucSach(s);
					XoaKhungChinhSua(XDanhMucSach+TongCDDanhMucSach+3,YDanhMucSach+2);
				}
				else if(CapNhat==-2)
				{
					i=(ViTriDauDanhMucSach-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1);
					string s="Khong The Cap Nhat Sach Da Thanh Ly";
					VeNoiDungThongBaoDanhMucSach(s);
					XoaKhungChinhSua(XDanhMucSach+TongCDDanhMucSach+3,YDanhMucSach+2);
				}
				else if(CapNhat>=1)
				{
					i=(CapNhat-1)-ChieuRongDanhMucSach*(SoTrangDanhMucSach-1);
					string s="Cap Nhat Thanh Cong";
					VeNoiDungThongBaoDanhMucSach(s);
					XoaKhungCapNhat(XDanhMucSach+TongCDDanhMucSach+3,YDanhMucSach+2,TongThongTinDanhMucSach*2+3);
					XoaHetDSDMS();
					if(DSDS.node[n]->SoLuong>ChieuRongDanhMucSach)
					{
						if(SoTrangDanhMucSach<TongTrangDanhMucSach)
						{
							XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),ChieuRongDanhMucSach*SoTrangDanhMucSach);
						}
						else if(SoTrangDanhMucSach==TongTrangDanhMucSach)
						{
							XuatDanhMucSach(DSDS,n,NOI_DUNG,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1),DSDS.node[n]->SoLuong);
						}
					}
					else if(DSDS.node[i]->SoLuong<=ChieuRongDanhMucSach)
					{
						XuatDanhMucSach(DSDS,n,NOI_DUNG,0,DSDS.node[n]->SoLuong);
						TongTrangDanhMucSach=1;
					}
					Xuat1DanhMucSach(DSDS,n,i,ChieuRongDanhMucSach*(SoTrangDanhMucSach-1)+i,TIEU_DE);
					VeTrangDanhMucSach();
				}			
			}
		}
		else if(b==Esc)
		{
			break;
		}
	}
}
#endif
