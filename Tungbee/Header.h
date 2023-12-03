#pragma once
#include <iostream>
using namespace std;
struct NgayVaoLam {
	int ngay; 
	int thang;
	int nam;

};
struct NhanVien
{
	string maNV;
	string tenNV;
	int gioiTinh;
	NgayVaoLam ngayVaoLam;
	int luong;

	
};
struct PhongBan {
	string maPhong;
	string tenPhong;
	NhanVien danhSachNV[20];
	int soLuongNV;
};
struct CongTy {
	PhongBan danhSachPB[10];
	int soLuongPB;
};
void nhapPB(PhongBan& PhongBan);
void nhapNV(NhanVien& nv);
void xuatNV(NhanVien a);
void nhapNVTrongPB(PhongBan& phongBan);
void xuatPB(PhongBan phongBan);
void xuatNVTrongPB(PhongBan phongBan);
bool kiemTraMaTrung(PhongBan a, string ma, int hienTai);
void xuatDSPB(CongTy a);
void nhapDSPB(CongTy& a);