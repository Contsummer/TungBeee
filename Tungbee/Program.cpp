#include"Header.h"
//làm xog sửa lại kiểm tra ma nhan vien cho toan công ty   cả công ty 
// xử lý cho số lượng phòng ban nằm ở menu ;
//lưu tên phòng ban vào thông tin nhân vie
int main() {

	CongTy a;
	///*nhapDSPB(a);
	a.soLuongPB = 2; 
	a.danhSachPB[0].maPhong = "1";
	a.danhSachPB[0].tenPhong = "Nguyen Tien Tung";
	a.danhSachPB[0].soLuongNV = 2;
	a.danhSachPB[1].maPhong = "2";
	a.danhSachPB[1].tenPhong = "Tung2";
	a.danhSachPB[1].soLuongNV = 2;
	a.danhSachPB[0].danhSachNV[0].maNV = "1";
	a.danhSachPB[0].danhSachNV[0].tenNV = "Minh  Quan";
	a.danhSachPB[0].danhSachNV[0].gioiTinh = 1; 
	a.danhSachPB[0].danhSachNV[0].ngayVaoLam.ngay = 1;
	a.danhSachPB[0].danhSachNV[0].ngayVaoLam.thang = 1;
	a.danhSachPB[0].danhSachNV[0].ngayVaoLam.nam = 2022;
	a.danhSachPB[0].danhSachNV[0].NgaySinh.ngay = 1;
	a.danhSachPB[0].danhSachNV[0].NgaySinh.thang = 1;
	a.danhSachPB[0].danhSachNV[0].NgaySinh.nam = 2022;
	a.danhSachPB[0].danhSachNV[0].luong =5; 
	a.danhSachPB[0].danhSachNV[1].maNV = "2";
	a.danhSachPB[0].danhSachNV[1].tenNV = "Quan2";
	a.danhSachPB[0].danhSachNV[1].gioiTinh = 0;
	a.danhSachPB[0].danhSachNV[1].ngayVaoLam.ngay = 1;
	a.danhSachPB[0].danhSachNV[1].NgaySinh.thang = 1;
	a.danhSachPB[0].danhSachNV[1].NgaySinh.nam = 2022;
	a.danhSachPB[0].danhSachNV[1].NgaySinh.ngay = 1;
	a.danhSachPB[0].danhSachNV[1].ngayVaoLam.thang = 1;
	a.danhSachPB[0].danhSachNV[1].ngayVaoLam.nam = 2022;
	a.danhSachPB[0].danhSachNV[1].luong = 1;
	a.danhSachPB[1].danhSachNV[0].maNV = "11";
	a.danhSachPB[1].danhSachNV[0].tenNV = "Quan3";
	a.danhSachPB[1].danhSachNV[0].gioiTinh = 0;
	a.danhSachPB[1].danhSachNV[0].ngayVaoLam.ngay = 1;
	a.danhSachPB[1].danhSachNV[0].ngayVaoLam.thang = 1;
	a.danhSachPB[1].danhSachNV[0].ngayVaoLam.nam = 2022;
	a.danhSachPB[1].danhSachNV[0].NgaySinh.ngay = 1;
	a.danhSachPB[1].danhSachNV[0].NgaySinh.thang = 1;
	a.danhSachPB[1].danhSachNV[0].NgaySinh.nam = 2022;
	a.danhSachPB[1].danhSachNV[0].luong = 5;
	a.danhSachPB[1].danhSachNV[1].maNV = "12";
	a.danhSachPB[1].danhSachNV[1].tenNV = "Quan4";
	a.danhSachPB[1].danhSachNV[1].gioiTinh = 1;
	a.danhSachPB[1].danhSachNV[1].NgaySinh.ngay = 1;
	a.danhSachPB[1].danhSachNV[1].NgaySinh.thang = 1;
	a.danhSachPB[1].danhSachNV[1].NgaySinh.nam = 2001;
	a.danhSachPB[1].danhSachNV[1].ngayVaoLam.ngay = 1;
	a.danhSachPB[1].danhSachNV[1].ngayVaoLam.thang = 1;
	a.danhSachPB[1].danhSachNV[1].ngayVaoLam.nam = 2001;

	a.danhSachPB[1].danhSachNV[1].luong = 1;
	xuatDSPB(a);
	//for (int i = 0; i < a.soLuongPB; i++) {
	//	cout << "\n=================================";
	//	//cout << "\n Danh sach phong  ban " << a.danhSachPB[i].tenPhong;
	//	nhapNVTrongPB(a.danhSachPB[i],a);
	//}
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n=================================";
		xuatNVTrongPB(a.danhSachPB[i]);
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	xuatNVToanCTy(a);
	//xuatNVHon20Nam(a);
	//xuatNVTu20Den45(a);
	//xuatNVNu(a);
	////suaThongTin(a);
	////xuatNVToanCTy(a);
	//timNVTheoTen(a);
	//timNVTheoMucLuong(a);
	//timNVTheoThamNien(a);
	//demSoNVTungPhong(a);
	//demSoNVCTY(a);
	xuatNVLuongThap(a);
	xuatNVLuongCao(a);
	thongKeBanLuong(a);
	tongLuong(a);
	return 0; 
}
