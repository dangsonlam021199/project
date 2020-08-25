#include "DanhSachDangKi.h"
#include "Something.h"

DK* KhoiTaoDangKi(string MSSV, float diem)
{
	DK* dk = new DK;
	dk->MSSV = MSSV;
	dk->diem = diem;
	dk->pNext = NULL;
	return dk;
}

void KhoiTaoDanhSachDangKi(DSDK& dsdk)
{
	dsdk.pHead = NULL;
	dsdk.pTail = NULL;
	dsdk.SL = 0;
}

void ThemDangKi(DSDK& dsdk, DK* dk)
{
	if (dsdk.pHead == NULL) {
		dsdk.pHead = dk;
		dsdk.pTail = dk;
		dsdk.SL++;
		cout << "\n*****Dang ki thanh cong*****";
		return;
	}
	else {
		dsdk.pTail->pNext = dk;
		dsdk.pTail = dk;
		dsdk.SL++;
		cout << "\n*****Dang ki thanh cong*****";
		return;
	}
}

void XoaDKDau(DSDK& l)
{
	if (l.pHead == NULL) {
		return;
	}
	DK* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	return;
}

void XoaDKCuoi(DSDK& l)
{
	if (l.pTail == NULL) {
		return;
	}
	for (DK* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pNext == l.pTail) {
			DK* p = l.pTail;
			l.pTail = k;
			delete p;
			return;
		}
	}
}

void XoaDangKi(DSDK& l, string maSV)
{
	if (l.pHead->MSSV.compare(maSV) == 0) {
		XoaDKDau(l);
		return;
	}
	if (l.pTail->MSSV.compare(maSV) == 0) {
		XoaDKCuoi(l);
		return;
	}
	for (DK* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pNext->MSSV.compare(maSV)) {
			DK* p = k->pNext;
			DK* q = k->pNext->pNext;
			k->pNext = q;
			delete p;
			l.SL--;
			break;
		}
	}
}
