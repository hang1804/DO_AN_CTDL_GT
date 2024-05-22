#ifndef SAVELOADFILE_H
#define SAVELOADFILE_H
#include "Define.h"


void save_DauSach(List &dauSach)
{
    ofstream of;
    of.open("dausach.txt",ios::out);
    if(!of.is_open()){ cout<<"file couldn't be open"<<endl; return ; }
    if (dauSach.n == 0) return;
    for (int i = 0; i < dauSach.n; i++)
    {
        of <<dauSach.node[i]->ISBN<<", "
           <<dauSach.node[i]->TenSach<<", "
           <<dauSach.node[i]->SoTrang<<", "
           <<dauSach.node[i]->TacGia<<", "
           <<dauSach.node[i]->NamXuatBan<<", "
           <<dauSach.node[i]->TheLoai<<endl;
    }
    of.close();
}
void save_DanhMuc(List dauSach)
{
    ofstream of;
    of.open("danhmucsach.txt",ios::out);
    if(!of.is_open()){
        cout<<"file couldn't be open"<<endl;
        return;
    }
    if (dauSach.n == 0) return;
    PTRDMS p;
    for (int i = 0; i < dauSach.n; i++)
    {
        p = dauSach.node[i]->dms;
    	if (p != NULL){
    		for (p;p != NULL; p = p->ptnext)
	        {
	            of <<p->dm.MaSach<<", "
	               <<p->dm.TrangThaiSach<<", "
	               <<p->dm.ViTri<<"; ";
	        }
		}
		of <<endl;
    }
    of.close();
}

void load_DauSach(List &dauSach)
{
    ifstream ifs;
    ifs.open("dausach.txt");
    if(!ifs.is_open()) {
        cout<<"file couldn't be open."<<endl;
        return;
    }
    char c;
    while(ifs.get(c))
    {	
    	ifs.putback(c);
    	if(c == ifs.eof()) break;
		dauSach.node[dauSach.n] = new DauSach;
        getline(ifs,dauSach.node[dauSach.n]->ISBN,',');
        ifs.ignore();
        getline(ifs,dauSach.node[dauSach.n]->TenSach,',');
        ifs.ignore();
        ifs>>dauSach.node[dauSach.n]->SoTrang;
        ifs.ignore();
        ifs.ignore();
        getline(ifs,dauSach.node[dauSach.n]->TacGia,',');
        ifs.ignore();
        ifs>>dauSach.node[dauSach.n]->NamXuatBan;
        ifs.ignore();
        ifs.ignore();
        getline(ifs,dauSach.node[dauSach.n]->TheLoai);
        dauSach.n++;
    }
	if(dauSach.n % ChieuRongDauSach == 0)
	{
		TongTrangDauSach=(dauSach.n/ChieuRongDauSach)+1;
	}
    ifs.close();
}

void Insert_Last_DMS(PTRDMS &First, PTRDMS p) {
	    p->ptnext=NULL;
		if (First==NULL) First = p;
		else { 
			PTRDMS Last;
		    for (Last = First;Last->ptnext !=NULL; Last=Last->ptnext) ;		
		    Last->ptnext = p;
	    }
}
void load_DanhMuc(List &dauSach){

    ifstream ifs;
    ifs.open("danhmucsach.txt");
    if(!ifs.is_open()) {
        cout<<"file couldn't be open."<<endl;
        return;
    }
    char c;
    for (int i = 0 ;i < dauSach.n;i++)
    {
    	while(ifs.get(c)){
        	ifs.putback(c);
        	if(c != '\n')
		    {
		    	PTRDMS p=new NodeDMS;
		        getline(ifs, p->dm.MaSach,',');
		        ifs.ignore();
		        ifs >>p->dm.TrangThaiSach;
		        ifs.ignore();
		        ifs.ignore();
		    	getline(ifs, p->dm.ViTri,';');
		    	ifs.ignore();
		    	Insert_Last_DMS(dauSach.node[i]->dms, p);
		    	
				dauSach.node[i]->SoLuong++;
				if(dauSach.node[i]->SoLuong % ChieuRongDanhMucSach == 0)
				{
					TongTrangDanhMucSach=(dauSach.node[i]->SoLuong/ChieuRongDanhMucSach)+1;
				}
		    }else if (c == '\n'){
		    	ifs.ignore();
		    	break;
			}
		} 	
	}
    ifs.close();
}

void save_date(ofstream &of,Date date)
{
    of<<date.ngay<<"/"<<date.thang<<"/"<<date.nam<<", ";
}

void save_DocGia_CNP(ofstream &of, PTRCNP docGia)
{
    DocGia Dg;
    if(docGia != NULL)
    {
        Dg = docGia->dg;
        of << Dg.MaThe<<", "
           <<Dg.ho<<", "
           <<Dg.ten<<", "
           <<Dg.phai<<", "
           <<Dg.TrangThaiThe<<endl;
        save_DocGia_CNP(of, docGia->left);
        save_DocGia_CNP(of, docGia->right);
    }
}
void save_DocGia(PTRCNP docGia)
{
    ofstream of;
    of.open("danhsachdocgia.txt",ios::out);
    if(!of.is_open()){
        cout<<"file couldn't be open"<<endl;
        return;
    }
    save_DocGia_CNP(of, docGia);
    of.close();
}

void save_MT_CNP(ofstream &of, PTRCNP docGia)
{
    PTRMT dsmt;
    if (docGia != NULL)
    {
        dsmt = docGia->dg.dsmuon;
        if (dsmt != NULL)
        {
        	for (dsmt; dsmt != NULL; dsmt = dsmt->next)
	        {
			        of <<dsmt->mt.MaSach<<", ";
			        save_date(of, dsmt->mt.NgayMuon);
			        save_date(of, dsmt->mt.NgayTra);
			        of <<dsmt->mt.TrangThai<<"; ";
			}
		}
	    of <<endl;
        save_MT_CNP(of, docGia->left);
        save_MT_CNP(of, docGia->right);
    }
}

void save_MuonTra(PTRCNP docGia)
{
    PTRMT dsmt; 
    ofstream of;
    of.open("danhsachmuontra.txt");
    if(!of.is_open()){
        cout<<"file couldn't be open"<<endl;
        return;
    }
    save_MT_CNP(of, docGia);
    of.close();
}

void Insert_NODE(PTRCNP &t,DocGia x)
{
    if(t == NULL)
    {
        t = new NodeCNP;
        t->dg = x;
        t->left = NULL;
        t->right = NULL;
    }else{
        if(x.MaThe < t->dg.MaThe){
            Insert_NODE(t->left, x);
        }else if(x.MaThe > t->dg.MaThe){
            Insert_NODE(t->right, x);
        }
    }
}

void Insert_First_MT(PTRMT &dsmt, MuonTra Mt)
{
    PTRMT q = new NodeMT;
	q->mt = Mt;
	q->next = NULL;
	q->prev = NULL;  
    if(dsmt != NULL) q->next = dsmt;
    dsmt = q;
}
void load_date(ifstream &ifs, Date &t)
{
    ifs >>t.ngay;
    ifs.ignore();
    ifs >>t.thang;
    ifs.ignore();
    ifs >>t.nam;
}
void load_docgia_CNP(ifstream &ifs, PTRCNP &docGia)
{
	DocGia Dg;
	char c;
    while (ifs.get(c))
    {
    	ifs.putback(c);
    	if (c == ifs.eof()) return;
        ifs >>Dg.MaThe; ifs.ignore(); ifs.ignore();
        getline(ifs, Dg.ho, ','); ifs.ignore();
        getline(ifs, Dg.ten, ','); ifs.ignore();
        getline(ifs, Dg.phai, ','); ifs.ignore();
        ifs >>Dg.TrangThaiThe; ifs.ignore(); 
        Insert_NODE(docGia, Dg);
    }
}
void load_DocGia(PTRCNP &docGia)
{
    ifstream ifs;
    ifs.open("danhsachdocgia.txt");
    if(!ifs.is_open()){
        cout<<"file couldn't be open"<<endl;
        return ;
    }
    load_docgia_CNP(ifs, docGia);
    ifs.close();
}

void duyet_MT_CNP_NLR(ifstream &ifs, PTRCNP &docGia)
{
    MuonTra Mt;
    if(docGia != NULL)
    {
        char c;
        while(ifs.get(c))
        {
        	ifs.putback(c);
            if (c != '\n') {
            	getline(ifs, Mt.MaSach, ',');
	            ifs.ignore();
	            load_date(ifs, Mt.NgayMuon);
	            ifs.ignore();
	            load_date(ifs, Mt.NgayTra);
	            ifs.ignore();
	            ifs >>Mt.TrangThai;
	            ifs.ignore();
	            ifs.ignore();
	            Insert_First_MT(docGia->dg.dsmuon, Mt);
			}else {
				ifs.ignore();
            	break;
			}
        }
        duyet_MT_CNP_NLR(ifs,docGia->left);
        duyet_MT_CNP_NLR(ifs,docGia->right);
    }
}

void load_MuonTra(PTRCNP &docGia)
{
    ifstream ifs;
    ifs.open("danhsachmuontra.txt");
    if(!ifs.is_open()){
        cout<<"file couldn't be open"<<endl;
        return;
    }
    duyet_MT_CNP_NLR(ifs, docGia);
    ifs.close();
}

void load_file(List &dauSach, PTRCNP &docGia)
{
    load_DauSach(dauSach);
    load_DanhMuc(dauSach);
    load_DocGia(docGia);
    load_MuonTra(docGia);
}

void save_file(List dauSach, PTRCNP docGia)
{
    save_DauSach(dauSach);
    save_DanhMuc(dauSach);
    save_DocGia(docGia);
    save_MuonTra(docGia);
}

#endif

