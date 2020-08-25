#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

#define MAXMON 300
using namespace std;
//====================MonHoc=============
struct monHoc
{
	string maMH{ "" };
	string tenMH{ "" };
	int sTCLT{ 0 };
	int sTCTH{ 0 };
};
typedef struct monHoc MH;
//======================================

//=============DS MonHoc===============
struct DanhSachMonHoc
{
	MH* ds[MAXMON]{ NULL };
	int slMonHoc{ 0 };
};
typedef struct DanhSachMonHoc DSMH;
//=====================================
MH* KhoiTaoMonHoc(string maMH, string tenMH, int sTCLT, int sTCTH);
void KhoiTaoDanhSachMonHoc(DSMH& dsmh);
void ThemMonHoc(DSMH& dsmh, MH* mh);
void NhapMonHocTuFile(DSMH& dsmh);
void SaveDSMH(DSMH dsmh);
bool MaMHTonTai(DSMH dsmh, string maMH);
void SapXepMonHoc(DSMH& dsmh);
void InDSMonHoc(DSMH& dsmh);
void InMonHoc(MH* Mon);
MH* NhapThongTinMonHoc(DSMH dsmh);
void SuaMonHoc(DSMH& dsmh);
void XoaMonHoc(DSMH& dsmh);
int LaySoTinChi(DSMH dsmh, string maMH);