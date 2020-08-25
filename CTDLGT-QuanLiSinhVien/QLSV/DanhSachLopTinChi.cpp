#include "DanhSachLopTinChi.h"
#include "Something.h"

LopTinChi* KhoiTaoLopTinChi(int maLop, string maMH, string nienKhoa, int hocki, int nhom, int MAXsv, int MINsv, TREE ltcc)
{
	LopTinChi* ltc = new LopTinChi;
	ltc->maLop = TaoMaLopTinChi(ltcc);
	ltc->maMH = maMH;
	ltc->nienKhoa = nienKhoa;
	ltc->hocKy=hocki;
	ltc->nhom=nhom;
	ltc->MAXSv = MAXsv;
	ltc->MINSv = MINsv;
	ltc->pLeft = NULL;
	ltc->pRight = NULL;
	DSDK dsdk;
	KhoiTaoDanhSachDangKi(dsdk);
	ltc->dsDangki = dsdk;
	return ltc;
}

LopTinChi* NhapLopTinChi(TREE& dsltc, DSMH dsmh)
{
	int maLop = TaoMaLopTinChi(dsltc);
	string maMH;
	cout << "\tNhap ma mon hoc: ";
	do {
		cin.ignore();
		getline(cin, maMH);
		if (!MaMHTonTai(dsmh, maMH)) cout << "\tMa mon hoc khong ton tai. Nhap lai: ";
	} while (!MaMHTonTai(dsmh, maMH));
	string nienKhoa;
	cout << "\tNhap nien khoa: ";
	getline(cin, nienKhoa);

	int hocKy, nhom, MAXsv, MINsv;
	cout << "\tNhap hoc ky: "; cin >> hocKy;
	cout << "\tNhap nhom: "; cin >> nhom;
	cout << "\tNhap max sv: "; cin >> MAXsv;
	cout << "\tNhap min sv: "; cin >> MINsv;

	DSDK dsdk;
	KhoiTaoDanhSachDangKi(dsdk);

	return KhoiTaoLopTinChi(maLop, maMH, nienKhoa,  hocKy,  nhom,  MAXsv,  MINsv, dsltc);
}

void KhoiTaoDanhSachLopTinChi(DSLTC& dsltc)
{
	dsltc.DS = NULL;
	dsltc.SL = 0;
}

int LeftOf(const int maLop, const LopTinChi* root)
{
	return maLop < root->maLop;
}

int RightOf(const int maLop, const LopTinChi* root)
{
	return  maLop > root->maLop;
}

bool MaLopTrung(TREE ltc, int maLop)
{
	if (ltc == NULL) {
		return false;
	}
	else {
		if (ltc->maLop == maLop)
		{
			return true;
		}
		else if (RightOf(maLop, ltc)) {
			return MaLopTrung(ltc->pRight, maLop);
		}
		else
		{
			return MaLopTrung(ltc->pLeft, maLop);
		}
	}
	return false;
}

void HoanVi(LopTinChi *ltc1, LopTinChi *ltc2)
{
	LopTinChi* temp = new LopTinChi;
	copyLTC(ltc1, temp);
	copyLTC(ltc2, ltc1);
	copyLTC(temp, ltc2);
}

void copyLTC(LopTinChi* ltc, LopTinChi* temp)
{
	temp->dsDangki = ltc->dsDangki;
	temp->hocKy = ltc->hocKy;
	temp->maLop = ltc->maLop;
	temp->maMH = ltc->maMH;
	temp->MAXSv = ltc->MAXSv;
	temp->nhom = ltc->nhom;
	temp->nienKhoa = ltc->nienKhoa;
}

int TaoMaLopTinChi(TREE ltc)
{
	int ma = 1; //100-999
	do {
		ma = rand() % (999 - 100 + 1) + 100;
	} while (MaLopTrung(ltc, ma) != false);
	return ma;
}

void ThemLopTinChi(TREE& dsltc, LopTinChi* ltc)
{
	if (dsltc == NULL) {
		dsltc = ltc;
		cout << "\n*****Them lop tin chi thanh cong*****";
	}
	else {
		if (dsltc->maLop > ltc->maLop) {
			ThemLopTinChi(dsltc->pLeft, ltc);
		}
		else if (dsltc->maLop < ltc->maLop) {
			ThemLopTinChi(dsltc->pRight, ltc);
		}
	}
}

void SuaLopTinChi(DSLTC& dsltc, DSMH dsmh)
{
	cout << "\tNhap Ma lop can sua: ";
	int maLop; cin >> maLop;
	while (!MaLopTrung(dsltc.DS, maLop)) {
		cout << "*****\tMa lop khong ton tai! Nhap lai: ";
		cin >> maLop;
	}
	SuaLop(dsltc.DS, dsmh, maLop);
}

void SuaLop(TREE& dsltc, DSMH dsmh, int maLop) {
	if (dsltc->maLop == maLop) {
		InThongTinLop(dsltc);
		LopTinChi* ltc = NhapLopTinChi(dsltc, dsmh);
		ltc->maLop = maLop;
		dsltc = ltc;
		cout << "\n\t*****Sua du lieu lop tin chi thanh cong!\n";
		return;
	}
	else {
		if (LeftOf(maLop, dsltc)) SuaLop(dsltc->pLeft, dsmh, maLop);
		if (RightOf(maLop, dsltc)) SuaLop(dsltc->pRight, dsmh, maLop);
	}
}

void XoaLopTinChi(DSLTC &dsltc) {
	cout << "\tNhap Ma lop can xoa: ";
	int maLop; cin >> maLop;
	while (!MaLopTrung(dsltc.DS, maLop)) {
		cout << "*****\tMa lop khong ton tai! Nhap lai: ";
		cin >> maLop;
	}
	XoaLop(dsltc.DS, maLop);
	dsltc.SL--;
	cout << "\t*****Xoa thanh cong*****";
}

void XoaLop(TREE& dsltc, int maLop) {
	if (dsltc != NULL) {
		if (dsltc->maLop == maLop) {
			LopTinChi* x = dsltc;
			if (dsltc->pLeft == NULL) {
				dsltc = dsltc->pRight;
			}
			else if (dsltc->pRight == NULL) {
				dsltc = dsltc->pLeft;
			}
			else if (dsltc->pLeft != NULL && dsltc->pRight != NULL) {
				LTCThayThe(dsltc->pRight, x);
			}
			delete x;
		}
		else if (LeftOf(maLop, dsltc)) {
			XoaLop(dsltc->pLeft, maLop);
		}
		else if (RightOf(maLop, dsltc)) {
			XoaLop(dsltc->pRight, maLop);
		}
	}
}

void LTCThayThe(TREE dsltc, LopTinChi *x) {
	if (dsltc->pLeft != NULL) {
		LTCThayThe(dsltc->pLeft, x);
	}
	else {
		HoanVi(dsltc, x);
		x = dsltc;
		dsltc = dsltc->pRight;
	}

}

void InThongTinLop(TREE t) {
	cout << "Ma lop: " << t->maLop << "\tMa mon hoc: " << t->maMH << "\tNien khoa: " << t->nienKhoa << "\tNhom: " << t->nhom << "\tHoc ky: " << t->hocKy << "\tMAX: " << t->MAXSv << "\tMIN: " << t->MINSv << endl;
}

void NhapDanhSachLopTinChiTuFile(DSLTC& dsltc)
{	
	ifstream filein;
	filein.open("LOPTINCHI.txt", ios_base::in);
	while (!filein.eof()) {
		string maLop, hocky, nhom, MAXsv, MINsv, maMH, nienKhoa;
		LopTinChi* ltc = new LopTinChi;
		getline(filein, maLop, ',');
		getline(filein, maMH, ',');
		getline(filein, nienKhoa, ',');
		getline(filein, hocky, ',');
		getline(filein, nhom, ',');
		getline(filein, MAXsv, ',');
		getline(filein, MINsv);
		ltc->maLop = toINT(maLop);
		ltc->maMH = maMH;
		ltc->nienKhoa = nienKhoa;
		ltc->hocKy = toINT(hocky);
		ltc->nhom = toINT(nhom);
		ltc->MAXSv = toINT(MAXsv);
		ltc->MINSv = toINT(MINsv);
		DSDK dsdk;
		KhoiTaoDanhSachDangKi(dsdk);
		ltc->dsDangki = dsdk;
		ltc->pLeft = NULL;
		ltc->pRight = NULL;
		ThemLopTinChi(dsltc.DS, ltc);
		dsltc.SL++;
	}
	filein.close();
}


void SaveDSLTC(DSLTC& dsltc) {
	ofstream fileout;
	fileout.open("LOPTINCHI.txt", ios_base::out);
	fileout.clear();
	XuatDSLTCRaFile(dsltc.DS, fileout);
	fileout.close();
}


void XuatDSLTCRaFile(TREE dsltc, ofstream& fileout) {
	if (dsltc != NULL) {
		fileout << dsltc->maLop << "," << dsltc->maMH << "," << dsltc->nienKhoa << "," << dsltc->hocKy << "," << dsltc->nhom << "," << dsltc->MAXSv << "," << dsltc->MINSv << endl;
		XuatDSLTCRaFile(dsltc->pLeft, fileout);
		XuatDSLTCRaFile(dsltc->pRight, fileout);
	}

}

void ThemDangKiVaoLop(TREE& ltc, int maLop, DK *dk)
{
	if (ltc == NULL) return;
	if (ltc->maLop == maLop) {
		ThemDangKi(ltc->dsDangki, dk);
		return;
	}
	else {
		if (LeftOf(maLop, ltc)) ThemDangKiVaoLop(ltc->pLeft, maLop, dk);
		else  ThemDangKiVaoLop(ltc->pRight, maLop, dk);
	}
}

void NhapDanhSachDangKiTuFile(DSLTC& dsltc)
{
	ifstream filein;
	filein.open("DANGKI.txt", ios_base::in);
	while (!filein.eof()) {
		string maLop, diem;
		DK* dk = new DK;
		getline(filein, maLop, ',');
		if (maLop == "") break;
		getline(filein, dk->MSSV, ',');
		getline(filein, diem);
		dk->diem = toFloat(diem);
		dk->pNext = NULL;
		ThemDangKiVaoLop(dsltc.DS, toINT(maLop), dk);
	}
	filein.close();
}

void SaveDSDK(DSLTC& dsltc) {
	ofstream fileout;
	fileout.open("DANGKI.txt", ios_base::out);
	fileout.clear();
	LuuDSDKVaoFile(dsltc.DS, fileout);
	fileout.close();
}

void LuuDSDKVaoFile(TREE dsltc, ofstream &fileout) {
	if (dsltc != NULL) {
		if (dsltc->dsDangki.SL != 0) {
			for (DK* k = dsltc->dsDangki.pHead; k != NULL; k = k->pNext) {
				fileout << dsltc->maLop << "," << k->MSSV << "," << k->diem << endl;
			}
		}
		LuuDSDKVaoFile(dsltc->pLeft, fileout);
		LuuDSDKVaoFile(dsltc->pRight, fileout);
	}
}

void InDanhSach(DSLTC& ds)
{
	cout << "=======================Danh sach lop tin chi===================\n";
	LietKe(ds.DS);
}

void InDanhSachCacLopCoTheDangKi(TREE dsltc, string nienKhoa, int hocKy, string MSSV)
{
	if (dsltc == NULL) {
		return;
	}
	if (dsltc->nienKhoa.compare(nienKhoa) == 0 && dsltc->hocKy == hocKy && !LopCoSinhVienX(dsltc,MSSV,dsltc->maLop)) {
		InThongTinLop(dsltc);
	}
	InDanhSachCacLopCoTheDangKi(dsltc->pLeft, nienKhoa, hocKy,MSSV);
	InDanhSachCacLopCoTheDangKi(dsltc->pRight, nienKhoa, hocKy,MSSV);

}

bool LopCoTheDangKi(TREE dsltc, int maLop, string nienKhoa, int hocKy)
{
	if (dsltc != NULL) {
		if (dsltc->maLop == maLop && dsltc->nienKhoa.compare(nienKhoa) == 0 && dsltc->hocKy == hocKy) return true;
		else if (LeftOf(maLop, dsltc)) return LopCoTheDangKi(dsltc->pLeft, maLop, nienKhoa, hocKy);
		else return LopCoTheDangKi(dsltc->pRight, maLop, nienKhoa, hocKy);
	}
	else return false;
}

bool LopCoSinhVienX(TREE ds, string MSSVX, int maLop)
{
	if (ds == NULL)
		return false;
	if (ds->maLop == maLop) {
		if (ds->dsDangki.pHead == NULL) return false;
		for (DK* k = ds->dsDangki.pHead; k != NULL; k = k->pNext)
			if (k->MSSV.compare(MSSVX) == 0) return true;
	}
	else if (LeftOf(maLop, ds)) {
		return LopCoSinhVienX(ds->pLeft, MSSVX, maLop);
	}
	else if (RightOf(maLop, ds)) {
		return LopCoSinhVienX(ds->pRight, MSSVX, maLop);
	}
	return false;
}

void SinhVienDangKiLop(TREE& ds, int maLop, string MSSV)
{
	if (ds->maLop == maLop) {
		float diem = 0;
		DK* DKi = KhoiTaoDangKi(MSSV,diem);
		ThemDangKi(ds->dsDangki, DKi);
		return;
	}
	else if (LeftOf(maLop, ds)) {
		return SinhVienDangKiLop(ds->pLeft, maLop, MSSV);
	}
	else if (RightOf(maLop, ds)) {
		return SinhVienDangKiLop(ds->pRight, maLop, MSSV);
	}
}

void InCacLopDaDangKi(TREE ds, string MSSV, int& check)
{
	if (ds == NULL) return;
	if (LopCoSinhVienX(ds, MSSV, ds->maLop)) {
		InThongTinLop(ds);
		check = 1;
	}
	InCacLopDaDangKi(ds->pLeft, MSSV, check);
	InCacLopDaDangKi(ds->pRight, MSSV, check);
}

bool LopDaFULL(TREE dsltc, int maLop)
{
	if (dsltc != NULL) {
		if (dsltc->maLop == maLop) {
			if (dsltc->MAXSv <= dsltc->dsDangki.SL) return true;
		}
		else if (LeftOf(maLop, dsltc)) return LopDaFULL(dsltc->pLeft, maLop);
		else return LopDaFULL(dsltc->pRight, maLop);
	}
	return false;
}

void XoaDangKiSinhVien(TREE& dsltc, int maLop, string MSSV)
{
	if (dsltc != NULL) {
		if (dsltc->maLop == maLop) {
			XoaDangKi(dsltc->dsDangki, MSSV);
		}
		else if (LeftOf(maLop, dsltc)) XoaDangKiSinhVien(dsltc->pLeft, maLop, MSSV);
		else XoaDangKiSinhVien(dsltc->pRight, maLop, MSSV);
	}
}

void InDanhSachDK(DSDK& l, DSSV dssv)
{
	for (DK* k = l.pHead; k != NULL; k = k->pNext) {
		InSinhVienTheoMSSV(dssv, k->MSSV);
	}
}

void InDanhSachTheoNienKhoa(TREE dsltc, DSSV dssv, string nienKhoa)
{
	if (dsltc != NULL) {
		if (dsltc->nienKhoa.compare(nienKhoa) == 0 && dsltc->dsDangki.SL != 0) {
			cout << "============Lop tin chi: ";
			InThongTinLop(dsltc);
			InDanhSachDK(dsltc->dsDangki, dssv);
		}
		InDanhSachTheoNienKhoa(dsltc->pLeft, dssv, nienKhoa);
		InDanhSachTheoNienKhoa(dsltc->pRight, dssv, nienKhoa);
	}
}

void InDanhSachTheoMaMon(TREE dsltc, DSSV dssv, string maMon)
{
	if (dsltc != NULL) {
		if (dsltc->maMH.compare(maMon) == 0 && dsltc->dsDangki.SL != 0) {
			cout << "============Lop tin chi:";
			InThongTinLop(dsltc);
			InDanhSachDK(dsltc->dsDangki, dssv);
		}
		InDanhSachTheoMaMon(dsltc->pLeft, dssv, maMon);
		InDanhSachTheoMaMon(dsltc->pRight, dssv, maMon);
	}
}

void NhapDiemChoCacSinhVien(TREE &dsltc, DSSV dssv, string nienKhoa, int hocKi, int nhom, string maMH)
{
	if (dsltc != NULL) {
		if (dsltc->nienKhoa.compare(nienKhoa) == 0 && dsltc->hocKy == hocKi && dsltc->nhom == nhom && dsltc->maMH.compare(maMH) == 0) {
			for (DK* k = dsltc->dsDangki.pHead; k != NULL; k = k->pNext) {
				InSinhVienTheoMSSV(dssv,k->MSSV);
				cout << "\tDiem: "; cin >> k->diem;
			}
		}
		NhapDiemChoCacSinhVien(dsltc->pLeft,dssv, nienKhoa, hocKi, nhom, maMH);
		NhapDiemChoCacSinhVien(dsltc->pRight,dssv, nienKhoa, hocKi, nhom, maMH);
	}
}

void InDiemChoCacSinhVien(TREE& dsltc, DSSV dssv, string nienKhoa, int hocKi, int nhom, string maMH)
{
	if (dsltc != NULL) {
		if (dsltc->nienKhoa.compare(nienKhoa) == 0 && dsltc->hocKy == hocKi && dsltc->nhom == nhom && dsltc->maMH.compare(maMH) == 0) {
			cout << "\t\t\t\t\t\t\t\tBANG DIEM MON HOC " << dsltc->maMH << endl;
			cout << "\t\t\t\t\t\t\tNien khoa: " << nienKhoa << "\tHoc ky: " << hocKi << "\tNhom: " << nhom << endl;
			int i = 0;
			for (DK* k = dsltc->dsDangki.pHead; k != NULL; k = k->pNext) {
				cout << "STT: " << ++i;
				InSinhVienTheoMSSV(dssv, k->MSSV); 
				cout <<"\tDiem: "<< k->diem << endl;
			}
		}
		InDiemChoCacSinhVien(dsltc->pLeft, dssv, nienKhoa, hocKi, nhom, maMH);
		InDiemChoCacSinhVien(dsltc->pRight, dssv, nienKhoa, hocKi, nhom, maMH);
	}
}

double TinhDiemTB1SV(TREE dsltc,DSMH dsmh, string MSSV)
{
	int diem = 0;
	int tinchi = 0;
	TinhDiemVaTinChi(dsltc, dsmh, MSSV, diem, tinchi);
	if (tinchi == 0)return 0;
	return (double)diem/tinchi;
}

void TinhDiemVaTinChi(TREE dsltc,DSMH dsmh, string MSSV, int& diem, int& tinchi) {
	if (dsltc != NULL) {
		for (DK* k = dsltc->dsDangki.pHead; k != NULL; k = k->pNext) {
			if (k->MSSV.compare(MSSV) == 0) {
				diem = diem + k->diem;
				tinchi = tinchi + LaySoTinChi(dsmh, dsltc->maMH);
			}
		}
		TinhDiemVaTinChi(dsltc->pLeft, dsmh, MSSV, diem, tinchi);
		TinhDiemVaTinChi(dsltc->pRight, dsmh, MSSV, diem, tinchi);
	}
	else return;
}

void InDanhSachTheoNhom(TREE dsltc, DSSV dssv, int nhom)
{
	
	if (dsltc != NULL) {
		if (dsltc->nhom == nhom && dsltc->dsDangki.SL != 0) {
			cout << "============Lop tin chi: ";
			InThongTinLop(dsltc);
			InDanhSachDK(dsltc->dsDangki, dssv);
		}
		InDanhSachTheoNhom(dsltc->pLeft, dssv, nhom);
		InDanhSachTheoNhom(dsltc->pRight, dssv, nhom);
	}
	
}

void InDanhSachTheoHocKy(TREE dsltc, DSSV dssv, int hocKy)
{
	if (dsltc != NULL) {
		if (dsltc->hocKy == hocKy && dsltc->dsDangki.SL!=0) {
			cout << "============Lop tin chi: ";
			InThongTinLop(dsltc);
			InDanhSachDK(dsltc->dsDangki, dssv);
		}
		InDanhSachTheoNhom(dsltc->pLeft, dssv, hocKy);
		InDanhSachTheoNhom(dsltc->pRight, dssv, hocKy);
	}
}

void LietKe(TREE t)
{
	if (t != NULL) {
		InThongTinLop(t);
		LietKe(t->pLeft);
		LietKe(t->pRight);
	}
}