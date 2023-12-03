#include"Header.h"
void nhapPB(PhongBan& PhongBan) {
	cout << "\n Nhap ma phong: "; 
	cin >> PhongBan.maPhong;
	cout << "\n Nhap ten phong: ";
	cin >> PhongBan.tenPhong;
	cout << "\n Nhap so luong nhan vien trong phong: ";
	NhanVien dsNV[100];
	cin >> PhongBan.soLuongNV;
}
void nhapNV(NhanVien& nv) {
	/*cout << "\n Nhap ma nhan vien: ";
	cin >> nv.maNV;*/
	cout << "\n Nhap ten nhan vien: ";
	cin >> nv.tenNV;
	cout << "\nNhap gioi tinh (0|1): ";
	cin >> nv.gioiTinh;
	while(nv.gioiTinh != 1 && nv.gioiTinh != 0) {
		cout << "\nGioi tinh khong hop le! Nhap lai: ";
		cin >> nv.gioiTinh;
	}
	cout << "\nNhap ngay vao lam ";
	cout << "\nNgay: ";
	cin >> nv.ngayVaoLam.ngay;
	while (nv.ngayVaoLam.ngay <= 0 || nv.ngayVaoLam.ngay > 31) {
		cout << "\n Ngay khong hop le! Nhap lai: ";
		cin >> nv.ngayVaoLam.ngay;
	}
	cout << "Thang: ";
	cin >> nv.ngayVaoLam.thang;
	while (nv.ngayVaoLam.thang <= 0 || nv.ngayVaoLam.thang > 12) {
		cout << "\n Thang khong hop le! Nhap lai: ";
		cin >> nv.ngayVaoLam.thang;
	}
	cout << "Nam ";
	cin >> nv.ngayVaoLam.nam;
	while (nv.ngayVaoLam.nam<= 1950 || nv.ngayVaoLam.nam > 2023) {
		cout << "\nNam khong hop le! Nhap lai: ";
		cin >> nv.ngayVaoLam.nam;
	}
	cout << "\nNhap muc luong: ";
	cin >> nv.luong;
	while (nv.luong <= 0) {
		cout << "\n luong khong hop le! Nhap lai:";
		cin >> nv.luong;
	}

}
void xuatNV(NhanVien a) {
	cout << "\nMa nhan vien: " << a.maNV;
	cout << "\nTen nhan vien: " << a.tenNV;
	cout << "\nGioi tinh nhan vien: ";
	if (a.gioiTinh == 1)cout << "nam";
	else cout<<"nu";
	cout << "\nNgay vao lam: " << a.ngayVaoLam.ngay << "/" << a.ngayVaoLam.thang << "/" << a.ngayVaoLam.nam;

	cout << "\nLuong nhan vien: " << a.luong;
 }

void xuatPB(PhongBan phongBan) {
	cout << "\n Ma phong ban: " << phongBan.maPhong;
	cout << "\nTen phong ban: " << phongBan.tenPhong;
	cout << "\nSo luong nhan vien: " << phongBan.soLuongNV;
}
void nhapNVTrongPB(PhongBan& phongBan) {
	bool trung; 
	for (int i = 0; i < phongBan.soLuongNV;i++) {
		cout << "\n Nhap vao ma nhan vien";
		cin >> phongBan.danhSachNV[i].maNV;
		trung = kiemTraMaTrung(phongBan, phongBan.danhSachNV[i].maNV,i);
		while (trung) {
			cout << "\n Ma da ton tai! :Nhap lai: ";
			cin >> phongBan.danhSachNV[i].maNV;
			trung = kiemTraMaTrung(phongBan, phongBan.danhSachNV[i].maNV,i);
		}
		nhapNV(phongBan.danhSachNV[i]);
	}
}
void xuatNVTrongPB(PhongBan phongBan) {
	for (int i = 0; i < phongBan.soLuongNV; i++) {
		xuatNV(phongBan.danhSachNV[i]);
	}
}
bool kiemTraMaTrung(PhongBan a , string ma ,int hienTai ) {
	for (int i = 0; i < a.soLuongNV; i++) {
		if (a.danhSachNV[i].maNV == ma&& i!=hienTai) {
			return true ;
		}
	}
	return false;
}
void nhapDSPB(CongTy& a) {
	cout << "\n Nhap vao so luong phong ban: ";
	cin >> a.soLuongPB;
	//a.danhSachPB[a.soLuongPB];
	for (int i = 0; i < a.soLuongPB; i++) {
		nhapPB(a.danhSachPB[i]);
	}
}
void xuatDSPB(CongTy a){
	cout << "\n============================================ ";
	cout << "\nSo luong phong ban cua cong ty: " << a.soLuongPB;
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n===========" << a.danhSachPB[i].tenPhong << "===========";
		xuatPB(a.danhSachPB[i]);
	}
}