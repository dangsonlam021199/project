#pragma once
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

//=====================SinhVien==========
struct SinhVien
{
	string maSV{ "" };
	string maLop{ "" };
	string phai{ "" };
	string ho{ "" };
	string ten{ "" };
	string sdt{ "" };
	int namNhapHoc{ 0 };
	struct SinhVien* pNext;
};
typedef struct SinhVien SV;
//======================================
//=========DS SinhVien==================
struct DanhSachSinhVien {
	SV* pHead;
	SV* pTail;
	int sl{ 0 };
};
typedef struct DanhSachSinhVien DSSV;
//=======================================
SV* KhoiTaoSinhVien(string maLop, string maSV, string ho, string ten, string phai, string sdt, int namNhapHoc);
SV* NhapThongTinSinhVien(string maLop, string maSV);
void KhoiTaoDanhSachSinhVien(DSSV& dssv);
void NhapSinhVienTuFile(DSSV& dssv);
void SaveDSSV(DSSV dssv);
bool SuaSVTrongLop(DSSV& l);
void ThemSinhVien(DSSV& dssv, SV* sv);
bool ThemSinhVienVaoLop(DSSV& dssv, string maLop);
bool MSSVDaTontai(DSSV l, string maSV);
bool MSSVDaTontaiTrongLop(DSSV& l, string maSV, string maLop);
bool LopDaTonTai(DSSV& l, string maLop);
void ThemSinhVienVaoLopCu(DSSV& l, string maLop, SV* sv);
void XoaSinhVien(DSSV& l, string maLop);
void XoaSVDau(DSSV& l);
void XoaSVCuoi(DSSV& l);
void ThemSinhVienPsauSinhVienQ(DSSV& l, SV* p, SV* q);
void SapXepDanhSachSV(DSSV& l);
void ThayDoiThongTinSinhVien(SV* p);
void InSinhVienThuocLopA(DSSV& l);
bool SVThuocLopA(SV* sv, string maLop);
void InSinhVien(SV* sv);
void InSinhVienTheoMSSV(DSSV l, string MSSV);
