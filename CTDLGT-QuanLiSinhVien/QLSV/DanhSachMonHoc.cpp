#include "DanhSachMonHoc.h"
#include "Something.h"

MH* KhoiTaoMonHoc(string maMH, string tenMH, int sTCLT, int sTCTH)
{
	MH* mh = new MH;
	mh->maMH = maMH;
	mh->tenMH = tenMH;
	mh->sTCLT = sTCLT;
	mh->sTCTH = sTCTH;
	return mh;
}

void KhoiTaoDanhSachMonHoc(DSMH &dsmh)
{
	dsmh.slMonHoc = 0;
}

void ThemMonHoc(DSMH& dsmh, MH* mh)
{
	dsmh.ds[dsmh.slMonHoc++] = mh;
	cout << "\n*****Them mon hoc thanh cong*****";
}

void NhapMonHocTuFile(DSMH& dsmh)
{
	ifstream filein;
	filein.open("MONHOC.txt", ios_base::in);
	while (!filein.eof()) {
		MH* mh = new MH;
		getline(filein, mh->maMH, ',');
		getline(filein, mh->tenMH, ',');
		string STCLT, STCTH;
		getline(filein, STCLT, ',');
		getline(filein, STCTH);
		mh->sTCLT = toINT(STCLT);
		mh->sTCTH = toINT(STCTH);
		ThemMonHoc(dsmh, mh);
	}
	filein.close();
}

void SuaMonHoc(DSMH& dsmh) {
	cout << "\n\tNhap ma mon hoc can sua: ";
	string maMH;
	cin.ignore();
	getline(cin, maMH);
	while (!MaMHTonTai(dsmh, maMH)) {
		cout << "\n\t*****Mon hoc khong ton tai! Nhap lai: ";
		cin.ignore();
		getline(cin, maMH);
	}
	for (int i = 0; i < dsmh.slMonHoc; i++) {
		if (dsmh.ds[i]->maMH.compare(maMH) == 0) {
			MH* mon = NhapThongTinMonHoc(dsmh);
			dsmh.ds[i] = mon;
			return;
		}
	}
}

void XoaMonHoc(DSMH& dsmh)
{
	cout << "\n\tNhap ma mon hoc can xoa: ";
	string maMH;
	cin.ignore();
	getline(cin, maMH);
	if (!MaMHTonTai(dsmh, maMH)) {
		cout << "\n\t*****Mon hoc khong ton tai! Nhap lai: ";
		cin.ignore();
		getline(cin, maMH);
	}
	for (int i = 0; i < dsmh.slMonHoc; i++) {
		if (dsmh.ds[i]->maMH.compare(maMH) == 0) {
			for (int j = i; j < dsmh.slMonHoc - 1; j++) {
				dsmh.ds[j] = dsmh.ds[j + 1];
			}
			dsmh.ds[dsmh.slMonHoc-1] = NULL;
			dsmh.slMonHoc--;
			break;
		}
	}
}

int LaySoTinChi(DSMH dsmh, string maMH)
{
	for (int i = 0; i < dsmh.slMonHoc; i++) {
		if (dsmh.ds[i]->maMH.compare(maMH) == 0) return dsmh.ds[i]->sTCTH+dsmh.ds[i]->sTCLT;
	}
	return 0;
}

void SaveDSMH(DSMH dsmh) {
	ofstream fileout;
	fileout.open("MONHOC.txt", ios_base::out);
	for (int i = 0; i < dsmh.slMonHoc; i++) {
		fileout << dsmh.ds[i]->maMH << "," << dsmh.ds[i]->tenMH << "," << dsmh.ds[i]->sTCLT << "," << dsmh.ds[i]->sTCTH;
		if (dsmh.ds[i + 1] != NULL) fileout << endl;
	}
	fileout.close();
}



MH* NhapThongTinMonHoc(DSMH dsmh) {
	MH* mon = new MH;
	cout << "\n\t==========Nhap thong tin mon hoc=============\n";
	cout << "\n\tMa mon hoc: ";
	string maMH;
	cin.ignore();
	getline(cin, maMH);
	while (MaMHTonTai(dsmh,maMH))
	{
		cout << "\tMa mon hoc da ton tai. Nhap lai: ";
		getline(cin, maMH);
	}

	cout << "\n\tTen mon hoc: ";
	string tenMH;
	getline(cin, tenMH);

	cout << "\n\tSo tin chi ly thuyet: ";
	int sTCLT;
	cin >> sTCLT;

	cout << "\n\tSo tin chi thuc hanh: ";
	int sTCTH;
	cin >> sTCTH;

	mon->maMH = maMH;
	mon->sTCLT = sTCLT;
	mon->sTCTH = sTCTH;
	mon->tenMH = tenMH;

	return mon;

}

bool MaMHTonTai(DSMH dsmh, string maMH)
{
	for (int i = 0; i < dsmh.slMonHoc; i++) {
		if (dsmh.ds[i]->maMH.compare(maMH) == 0) return true;
	}
	return false;
}

void SapXepMonHoc(DSMH& dsmh)
{
	for (int i = 0; i < dsmh.slMonHoc - 1; i++) {
		for (int j = i + 1; j < dsmh.slMonHoc; j++) {
			if (dsmh.ds[i]->tenMH.compare(dsmh.ds[j]->tenMH) == 1) swap(dsmh.ds[i], dsmh.ds[j]);
		}
	}
}

void InDSMonHoc(DSMH& dsmh)
{
	if (dsmh.slMonHoc == 0) {
		cout << "\n\t******Khong co mon hoc nao de hien thi*********\n";
		return;
	}
	cout << "\n\t=================Danh sach mon hoc==============";
	for (int i = 0; i < dsmh.slMonHoc; i++) {
		InMonHoc(dsmh.ds[i]);
	}
}
void InMonHoc(MH* Mon)
{
	cout << "\n\tMa mon hoc: " << Mon->maMH << "\tTen mon hoc: " << Mon->tenMH << "\tSTCLT: " << Mon->sTCLT << "\tSTCTH: " << Mon->sTCTH;
}