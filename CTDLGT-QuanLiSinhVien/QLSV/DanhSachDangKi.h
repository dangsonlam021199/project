#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>


using namespace std;

//===============Dang Ki==========
struct DangKi
{
	string MSSV{""};
	float diem{ 0.0 };
	struct DangKi* pNext{ NULL };
};
typedef struct DangKi DK;
//================================

//===============DS DangKi========
struct DanhSachDangKi
{
	DK* pHead;
	DK* pTail;
	int SL;
};
typedef struct DanhSachDangKi DSDK;
//===============================
DK* KhoiTaoDangKi(string MSSV, float diem);
void KhoiTaoDanhSachDangKi(DSDK& dsdk);
void ThemDangKi(DSDK& dsdk, DK* dk);
void XoaDangKi(DSDK& dsdk, string maSV);
void XoaDKCuoi(DSDK& l);
void XoaDKDau(DSDK& l);
