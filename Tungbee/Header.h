#pragma once
#include <iostream>
using namespace std;
struct NgayThang {
	int ngay; 
	int thang;
	int nam;

};
struct NhanVien
{
	string maNV;
	string tenNV;
	int gioiTinh;
	NgayThang NgaySinh;
	NgayThang ngayVaoLam;
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
void nhapNVTrongPB(PhongBan& phongBan,CongTy cty);
void xuatPB(PhongBan phongBan);
void xuatNVTrongPB(PhongBan phongBan);
bool kiemTraMaTrung(PhongBan a, string ma);
void xuatDSPB(CongTy a);
void nhapDSPB(CongTy& a);
bool kiemTraMaTrungCTY(CongTy a, string ma);
void xuatNVToanCTy(CongTy a);
void xuatNVHon20Nam(CongTy a);
void xuatNVTu20Den45(CongTy a);
void xuatNVNu(CongTy a);
void suaThongTin(CongTy& a);
void timNVTheoMa(CongTy a);
void timNVTheoTen(CongTy a);
string layTen(string  name);
void timNVTheoMucLuong(CongTy a);
void timNVTheoThamNien(CongTy a);
void demSoNVTungPhong(CongTy a);
void demSoNVCTY(CongTy a);
void xuatNVLuongThap(CongTy a);
void xuatNVLuongCao(CongTy a);
void thongKeBanLuong(CongTy a);
void tongLuong(CongTy a);