#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "DanhSachDangKi.h"
#include "DanhSachMonHoc.h"
#include "DanhSachSinhVien.h"
using namespace std;

//===========LopTinChi============
struct LopTinChi {
	int maLop{ 0 };
	string maMH{ "" };
	string nienKhoa{ "" };
	int hocKy{ 0 };
	int nhom{ 0 };
	int MAXSv{ 0 };
	int MINSv{ 0 };

	DSDK dsDangki{ NULL };

	struct LopTinChi* pLeft{ NULL };
	struct LopTinChi* pRight{ NULL };
};
typedef struct LopTinChi* TREE;
//=====================================

//===============DS LopTinChi==========
struct DanhSachLopTinChi
{
	TREE DS{ NULL };
	int SL{ 0 };
};
typedef struct DanhSachLopTinChi DSLTC;
//===================================
LopTinChi* KhoiTaoLopTinChi(int maLop, string maMH, string nienKhoa, int hocki, int nhom, int MAXsv, int MINsv);
LopTinChi* NhapLopTinChi(TREE& dsltc, DSMH dsmh);
void KhoiTaoDanhSachLopTinChi(DSLTC& dsltc);
int LeftOf(const int maLop, const LopTinChi* root);
int RightOf(const int maLop, const LopTinChi* root);
bool MaLopTrung(TREE ltc, int maLop);
void HoanVi(LopTinChi* ltc1, LopTinChi* ltc2);
void copyLTC(LopTinChi* ltc, LopTinChi* temp);
int TaoMaLopTinChi(TREE ltc);
void ThemLopTinChi(TREE& dsltc, LopTinChi* ltc);
void SuaLopTinChi(DSLTC& dsltc, DSMH dsmh);
void XoaLopTinChi(DSLTC& dsltc);
void SuaLop(TREE& dsltc, DSMH dsmh, int maLop);
void NhapDanhSachLopTinChiTuFile(DSLTC& dsltc);
void InThongTinLop(TREE ltc);
void LTCThayThe(TREE dsltc, LopTinChi* x);
void XoaLop(TREE& dsltc, int maLop);
void ThemDangKiVaoLop(TREE& ltc, int maLop, DK* dk);
void NhapDanhSachDangKiTuFile(DSLTC& dsltc);
void SaveDSLTC(DSLTC& dsltc);
void SaveDSDK(DSLTC& dsltc);
void XuatDSLTCRaFile(TREE dsltc, ofstream& fileout);
void LietKe(TREE t);
void InDanhSach(DSLTC& ds);
void InDanhSachCacLopCoTheDangKi(TREE dsltc, string nienKhoa, int hocKy, string MSSV);
bool LopCoTheDangKi(TREE dsltc, int maLop, string nienKhoa, int hocKy);
bool LopCoSinhVienX(TREE ds, string MSSVX, int maLop);
void SinhVienDangKiLop(TREE& ds, int maLop, string MSSV);
void InCacLopDaDangKi(TREE ds, string MSSV, int& check);
bool LopDaFULL(TREE dsltc, int maLop);
void LuuDSDKVaoFile(TREE dsltc, ofstream& fileout);
void XoaDangKiSinhVien(TREE& dsltc, int maLop, string MSSV);
void InDanhSachDK(DSDK& l, DSSV dssv);
void InDanhSachTheoNienKhoa(TREE dsltc,DSSV dssv, string nienKhoa);
void InDanhSachTheoNhom(TREE dsltc, DSSV dssv, int nhom);
void InDanhSachTheoHocKy(TREE dsltc, DSSV dssv, int hocKy);
void InDanhSachTheoMaMon(TREE dsltc, DSSV dssv, string maMon);
void NhapDiemChoCacSinhVien(TREE &dsltc,DSSV dssv, string nienKhoa, int hocKi, int nhom, string maMH);
void InDiemChoCacSinhVien(TREE& dsltc, DSSV dssv, string nienKhoa, int hocKi, int nhom, string maMH);
double TinhDiemTB1SV(TREE dsltc,DSMH dsmh, string MSSV);
void TinhDiemVaTinChi(TREE dsltc, DSMH dsmh, string MSSV, int& diem, int& tinchi);