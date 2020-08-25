#include "DanhSachSinhVien.h"
#include "Something.h"

SV* KhoiTaoSinhVien(string maLop, string maSV, string ho, string ten, string phai, string sdt, int namNhapHoc)
{
	SV* p = new SV;
	p->ho = ho;
	p->maLop = maLop;
	p->maSV = maSV;
	p->namNhapHoc = namNhapHoc;
	p->phai = phai;
	p->sdt = sdt;
	p->ten = ten;
	p->pNext=NULL;
	return p;
}

void KhoiTaoDanhSachSinhVien(DSSV& dssv)
{
	dssv.pHead = NULL;
	dssv.pTail = NULL;
	dssv.sl = 0;
}

void NhapSinhVienTuFile(DSSV& dssv)
{
	ifstream filein;
	filein.open("SINHVIEN.txt", ios_base::in);
	while (!filein.eof()) {
		SV* sv = new SV;
		string namNhapHoc;
		getline(filein, sv->maLop, ',');
		getline(filein, sv->maSV, ',');
		getline(filein, sv->ho, ',');
		getline(filein, sv->ten, ',');
		getline(filein, sv->phai, ',');
		getline(filein, sv->sdt, ',');
		getline(filein, namNhapHoc);
		sv->namNhapHoc = toINT(namNhapHoc);
		sv->pNext = NULL;
		ThemSinhVien(dssv, sv);
	}
	filein.close();
}

void SaveDSSV(DSSV dssv) {
	ofstream fileout;
	fileout.open("SINHVIEN.TXT", ios_base::out);
	for (SV* k = dssv.pHead; k != NULL; k=k->pNext) {
		fileout << k->maLop << "," << k->maSV << "," << k->ho << "," << k->ten << "," << k->phai << "," << k->sdt << "," << k->namNhapHoc;
		if (k->pNext != NULL) fileout << endl;
	}
	fileout.close();
}

void ThemSinhVien(DSSV& dssv, SV* sv)
{
	if (dssv.pHead == NULL) {
		dssv.pHead = dssv.pTail = sv;
		dssv.sl++;
		cout << "\n*****Them sinh vien thanh cong*****";
	}
	else {
		dssv.pTail->pNext = sv;
		dssv.pTail = sv;
		dssv.sl++;
		cout << "\n*****Them sinh vien thanh cong*****";
	}
}

bool ThemSinhVienVaoLop(DSSV& dssv, string maLop)
{
	cout << "\n\t=========================Nhap Thong tin sinh vien=====================\n";
	cout << "\tNhap ma sinh vien: ";
	string maSV;
	cin.ignore();
	getline(cin, maSV);
	if (maSV == "") return false;
	while (MSSVDaTontaiTrongLop(dssv, maSV, maLop)) {
		cout << "\n\t*****Ma so sinh vien da ton tai, nhap lai: ";
		cin.ignore();
		getline(cin, maSV);
	}

	SV* p = NhapThongTinSinhVien(maLop, maSV);
	cout << "Check ne";
	system("pause");
	if (p == NULL) return false;
	if (LopDaTonTai(dssv, maLop)) ThemSinhVienVaoLopCu(dssv, maLop, p);
	else ThemSinhVien(dssv, p);
		
	
	return true;
}

bool SuaSVTrongLop(DSSV& l)
{
	if (l.pHead == NULL) {
		cout << "\n\tKhong co sinh vien de sua!";
		system("pause");
		return false;
	}
	string maSV;
	cout << "\n\tNhap ma sinh vien can sua: ";
	cin.ignore();
	getline(cin, maSV);

	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->maSV.compare(maSV) == 0) {
			ThayDoiThongTinSinhVien(k);
		}
	}
	return false;
}

bool MSSVDaTontai(DSSV l, string maSV) {
	if (l.pHead == NULL)
	{
		return false;
	}
	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->maSV.compare(maSV) == 0) return true;
	}
	return false;
}

bool MSSVDaTontaiTrongLop(DSSV& l, string maSV, string maLop)
{
	if (l.pHead == NULL)
	{
		return false;
	}
	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->maSV.compare(maSV) == 0 && k->maLop.compare(maLop) == 0) return true;
	}
	return false;
}

bool LopDaTonTai(DSSV& l, string maLop)
{
	if (l.pHead == NULL)
	{
		return false;
	}
	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->maLop.compare(maLop) == 0) return true;
	}
	system("pause");
	return false;
}

SV* NhapThongTinSinhVien(string maLop, string maSV) {
	SV* p = new SV;

	cout << "\tNhap ho: ";
	string ho;
	getline(cin, ho);

	cout << "\tNhap ten: ";
	string ten;
	getline(cin, ten);

	cout << "\tNhap phai: ";
	string phai;
	getline(cin, phai);


	cout << "\tNhap SDT: ";
	string sdt;
	getline(cin, sdt);

	cout << "\tNhap nam nhap hoc: ";
	int namNhapHoc;
	cin >> namNhapHoc;

	p->ho = ho;
	p->maLop = maLop;
	p->maSV = maSV;
	p->namNhapHoc = namNhapHoc;
	p->phai = phai;
	p->sdt = sdt;
	p->ten = ten;
	p->pNext = NULL;

	return p;
}

void swapSV(SV* sv1, SV* sv2)
{
	string ho = sv1->ho;
	string maSV = sv1->maSV;
	int namNhapHoc = sv1->namNhapHoc;
	string phai = sv1->phai;
	string sdt = sv1->sdt;
	string ten = sv1->ten;

	sv1->ho = sv2->ho;
	sv1->maSV = sv2->maSV;
	sv1->namNhapHoc = sv2->namNhapHoc;
	sv1->phai = sv2->phai;
	sv1->sdt = sv2->sdt;
	sv1->ten = sv2->ten;

	sv2->ho = ho;
	sv2->maSV = maSV;
	sv2->namNhapHoc = namNhapHoc;
	sv2->phai = phai;
	sv2->sdt = sdt;
	sv2->ten = ten;
}

void ThayDoiThongTinSinhVien(SV* p)
{
	cout << "\tNhap ho:";
	string ho;
	getline(cin, ho);

	cout << "\tNhap ten:";
	string ten;
	getline(cin, ten);

	cout << "\tNhap phai:";
	string phai;
	getline(cin, phai);

	cout << "\tNhap SDT:";
	string sdt;
	getline(cin, sdt);

	cout << "\tNhap ma lop:";
	string maLop;
	getline(cin, maLop);

	cout << "\tNhap nam nhap hoc";
	int namNhapHoc;
	cin >> namNhapHoc;

	p->ho = ho;
	p->maLop = maLop;
	p->namNhapHoc = namNhapHoc;
	p->phai = phai;
	p->sdt = sdt;
	p->ten = ten;
}

void XoaSinhVien(DSSV& l, string maLop)
{
	if (!LopDaTonTai(l, maLop)|| l.pHead==NULL) {
		cout<<"\t*****Lop khong co sinh vien de xoa*****n";
		return;
	}
	string maSV;
	cout << "\n\tNhap ma sinh vien can xoa: ";
	cin.ignore();
	getline(cin, maSV);
	if (l.pHead->maSV.compare(maSV) == 0) {
		XoaSVDau(l);
		return;
	}
	if (l.pTail->maSV.compare(maSV) == 0) {
		XoaSVCuoi(l);
		return;
	}
	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pNext->maSV.compare(maSV)) {
			SV* p = k->pNext;
			SV* q = k->pNext->pNext;
			k->pNext = q;
			delete p;
			l.sl--;
			break;
		}
	}
}

void XoaSVDau(DSSV& l)
{
	SV* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}

void XoaSVCuoi(DSSV& l)
{
	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pNext == l.pTail) {
			SV* p = l.pTail;
			l.pTail = k;
			delete p;
			break;
		}
	}
}

void ThemSinhVienVaoLopCu(DSSV& l, string maLop, SV* sv)
{
	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->maLop.compare(maLop) == 0)
			if (k->pNext == NULL) ThemSinhVien(l, sv);
		if (k->pNext->maLop.compare(maLop) != 0)  ThemSinhVienPsauSinhVienQ(l, sv, k);
	}
	
}




void SapXepDanhSachSV(DSSV& l)
{
	for (SV* i = l.pHead; i != l.pTail; i = i->pNext) {
		for (SV* j = i->pNext; j != NULL; j = j->pNext) {
			if (i->maSV.compare(j->maSV) == 1 && i->maSV.compare(j->maLop)) swapSV(i, j);
		}
	}
}

void ThemSinhVienPsauSinhVienQ(DSSV& l, SV* p, SV* q)
{
	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k == q) {
			SV* g = k->pNext;
			k->pNext = p;
			p->pNext = g;
		}
	}
	l.sl++;

}

bool SVThuocLopA(SV* sv, string maLop)
{
	if (sv->maLop.compare(maLop) == 0) return true;
	return false;
}

void InSinhVien(SV* sv)
{
	cout << "\tLop: " << sv->maLop;
	cout << "\tMSSV: " << sv->maSV;
	cout << "\tHo: " << sv->ho;
	cout << "\tTen: " << sv->ten;
	cout << "\tPhai: " << sv->phai;
	cout << "\tSoDT: " << sv->sdt;
	cout << "\tNam nhap hoc: " << sv->namNhapHoc;
}

void InSinhVienKa(SV* sv)
{
	cout << "\tMSSV: " << sv->maSV;
	cout << "\tHo: " << sv->ho;
	cout << "\tTen: " << sv->ten;
}

void InSinhVienTheoMSSV(DSSV l, string MSSV)
{
	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->maSV.compare(MSSV) == 0) InSinhVienKa(k);
	}
}


void InSinhVienThuocLopA(DSSV& l)
{
	cout << "\n\tNhap ma lop can in danh sach: ";
	string maLop;
	cin.ignore();
	getline(cin, maLop);
	if (!LopDaTonTai(l, maLop)) {
		cout << "\n\tLop khong ton tai\n";
	}

	for (SV* k = l.pHead; k != NULL; k = k->pNext) {
		if (SVThuocLopA(k, maLop)) InSinhVien(k);
	}

}