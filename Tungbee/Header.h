#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <ctime>
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
	string phongBan;
	
};
struct PhongBan {
	string maPhong;
	string tenPhong;
	NhanVien danhSachNV[20];
	int soLuongNV;
};
struct CongTy {
	PhongBan danhSachPB[10];
	int soLuongPB = 0;
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
void sapXepNVTheoLuong(CongTy& a);
void demSoNVCTY(CongTy a);
void xuatNVLuongThap(CongTy a);
void xuatNVLuongCao(CongTy a);
void thongKeBanLuong(CongTy a);
void tongLuong(CongTy a);
void sapXepNVTheoTen(CongTy& a);
void displayMenu();
void ghi(string fileName, CongTy a);
void doc(string fileName, CongTy& a);
void xoa(string fileXoa, CongTy& a);
void docNVDaxoa(string fileXoa, PhongBan& a);
void xuatNVLam6Thang(CongTy a);
void diChuyenNV(CongTy& a);
bool kiemTraMaNhanVienTrung(CongTy a, string ma);