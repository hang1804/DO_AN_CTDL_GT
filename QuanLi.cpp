#include "NhapDauSach.h"
#include "DocGia.h"
#include "MuonTraDocGia.h"

using namespace std;

int main(){
	List DSDS;
	PTRCNP tree = NULL;
	load_file(DSDS, tree);
	SetColor(9);
	cout <<"Load file thanh cong!"<<endl;
	Sleep(1000);
	clrscr();
	ShowCur(0);
	VeMenuThuVien();
	TieuDe();
	int ChonThuVien;
	int ChonDauSach;
	int ChonDocGia;
	while(1)
	{
		chon=0;
		ChonThuVien=UpDownMenu(MenuThuVien,CHU,NEN_GOC,NEN_CHON,20,3,3,ViTriMenuThuVien);
		if(ChonThuVien==0)
		{	
			chon=0;
			XoaMenuThuVien();
			VeLe(); 
			VeMenuDauSach();
			while(1)
			{
				ChonDauSach=UpDownMenu(MenuDauSach,CHU,NEN_GOC,NEN_CHON,38,3,4,ViTriMenuDauSach);
				if(ChonDauSach==0)
				{
					BangDauSach();
					SoTrangDauSach=1;
					if(DSDS.n>ChieuRongDauSach)
					{
						QuickSortTheLoai(DSDS,0,DSDS.n-1);
						XuatDauSach(DSDS,NOI_DUNG,0,ChieuRongDauSach);
						TinhSoTrangDauSach(DSDS);
						if(DiemYDauSach==ChieuRongDauSach)
						{
							TongTrangDauSach--;
						}
					}
					else if(DSDS.n<=ChieuRongDauSach)
					{
						QuickSortTheLoai(DSDS,0,DSDS.n-1);
						XuatDauSach(DSDS,NOI_DUNG,0,DSDS.n);
						TongTrangDauSach=1;
					}
					VeKhungThongBao(GocX+5,GocY,TIEU_DE,CDKhungThongBaoDauSach);
					VePhimDauSach();
					VeTrangDauSach();
					UpDownDauSach(DSDS);
					save_DauSach(DSDS);
					XoaBangDanhSach();
					Nen();
				}
				else if(ChonDauSach==1)
				{
					TimDauSach(DSDS);
				}
				else if(ChonDauSach==2)
				{
					Sach_Muon_Nhieu_Nhat(DSDS, tree);
					XoaBangDanhSach();
				}
				else if(ChonDauSach==3)
				{
					XoaBangDanhSach();
					XoaMenu();
					XoaLe();
					VeMenuThuVien();
					break;
				}	
			}
		}else if(ChonThuVien==1)
		{
			chon=0;
			XoaMenuThuVien();
			VeLe();
			VeMenuDocGia();
			while(1)
			{
				ChonDocGia=UpDownMenu(MenuDocGia,CHU,NEN_GOC,NEN_CHON,30,3,5,ViTriMenuDocGia);
				if(ChonDocGia==0)
				{
					Docgia(tree);
				}
				else if(ChonDocGia==1)
				{
					MTBT(DSDS, tree);
					XoaBangDanhSach();
				}
				else if(ChonDocGia==2)
				{
					LK_SDM(DSDS, tree);
					XoaBangDanhSach();
				}
				else if(ChonDocGia==3)
				{
					DocGia_QuaHan(DSDS, tree);
					XoaBangDanhSach();
				}
				else if(ChonDocGia==4)
				{
					XoaBangDanhSach();
					XoaMenu();
					XoaLe();
					VeMenuThuVien();
					break;
				}
			}
		}
		else if(ChonThuVien==2)
		{
			break;
		}
	}
	Nen();
	gotoxy(0,45);
	return 0;
}
