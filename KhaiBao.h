#ifndef KHAIBAO_H
#define KHAIBAO_H 
#include <iostream>
#include <cstring>
#define MAXLIST 10000
using namespace std; 
struct Date{
	int ngay;
	int thang;
	int nam;
};

struct DanhMuc{
	string MaSach;
	int TrangThaiSach; //0-Muon duoc; 1-Da muon; 2-Da thanh ly
	string ViTri;
};

struct NodeDMS{
	DanhMuc dm;
	NodeDMS *ptnext;
};
typedef struct NodeDMS *PTRDMS; 

struct DauSach{
	string ISBN;
	string TenSach;
	int SoTrang;
	string TacGia;
	int NamXuatBan;
	string TheLoai;
	PTRDMS dms=NULL;
	int SoLuong=0; // Bien them de kiem tra so luong
};

struct List{
	int n = 0;
	DauSach *node[MAXLIST];
};

struct MuonTra{
	string MaSach;
	Date NgayMuon;
	Date NgayTra;
	int TrangThai; //1-Da tra; 2-Lam mat
};

struct NodeMT{
	MuonTra mt;
	struct NodeMT *next;
	struct NodeMT *prev;
};
typedef struct NodeMT *PTRMT;

struct DocGia{
	int MaThe;
	string ho;
	string ten;
	string phai;
	int TrangThaiThe;//0-Bi khoa >= 7 ngày; 1-Dang hoat dong
	PTRMT dsmuon=NULL;
};

struct NodeCNP{
	DocGia dg;
	struct NodeCNP *left;
	struct NodeCNP *right;
};
typedef struct NodeCNP *PTRCNP;
#endif
