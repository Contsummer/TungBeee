#include"Header.h"
void nhapPB(CongTy a ,PhongBan& PhongBan) {
	cout << "\nNhap ma phong: "; 
	cin >> PhongBan.maPhong;
	while (kiemTraMaTrungCTY(a, PhongBan.maPhong)) {
		cout << "\n Ma da ton tai!";
		cout << "\nNhap ma moi:";
		cin >> PhongBan.maPhong;
	}
	cout << "Nhap ten phong: ";
	cin.ignore();
	getline(cin, PhongBan.tenPhong);
	cout << "Nhap so luong nhan vien trong phong: ";
	NhanVien dsNV[100];
	cin >> PhongBan.soLuongNV;
}
void nhapNV(NhanVien& nv) {
	/*cout << "\n Nhap ma nhan vien: ";
	cin >> nv.maNV;*/
	cout << "\n Nhap ten nhan vien: ";
	cin.ignore();
	getline(cin, nv.tenNV);
	cout << "\nNhap gioi tinh (0|1): ";
	cin >> nv.gioiTinh;
	while(nv.gioiTinh != 1 && nv.gioiTinh != 0) {
		cout << "\nGioi tinh khong hop le! Nhap lai: ";
		cin >> nv.gioiTinh;
	}

	cout << "\nNhap ngay Sinh ";
	cout << "\nNgay: ";
	cin >> nv.NgaySinh.ngay;
	while (nv.NgaySinh.ngay <= 0 || nv.NgaySinh.ngay > 31) {
		cout << "\n Ngay khong hop le! Nhap lai: ";
		cin >> nv.NgaySinh.ngay;
	}
	cout << "Thang: ";
	cin >> nv.NgaySinh.thang;
	while (nv.NgaySinh.thang <= 0 || nv.NgaySinh.thang > 12) {
		cout << "\n Thang khong hop le! Nhap lai: ";
		cin >> nv.NgaySinh.thang;
	}
	cout << "Nam ";
	cin >> nv.NgaySinh.nam;
	while (nv.NgaySinh.nam <= 1950 || nv.NgaySinh.nam > 2023) {
		cout << "\nNam khong hop le! Nhap lai: ";
		cin >> nv.NgaySinh.nam;
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
	cout << "Nhap muc luong: ";
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
	cout << "\nNgay vao sinh: " << a.NgaySinh.ngay << "/" << a.NgaySinh.thang << "/" << a.NgaySinh.nam;

	cout << "\nNgay vao lam: " << a.ngayVaoLam.ngay << "/" << a.ngayVaoLam.thang << "/" << a.ngayVaoLam.nam;

	cout << "\nLuong nhan vien: " << a.luong;
	cout << "\nPhong ban: " << a.phongBan;
 }

void xuatPB(PhongBan phongBan) {
	cout << "\nMa phong ban: " << phongBan.maPhong;
	cout << "\nTen phong ban: " << phongBan.tenPhong;
	cout << "\nSo luong nhan vien: " << phongBan.soLuongNV;
}
void nhapNVTrongPB(PhongBan& b ) {
	bool trung; 
	string a;
	cout << "\n=============== " << " Phong ban " << b.tenPhong<< " ===============" ;
	for (int i = 0; i < b.soLuongNV;i++) {
		cout << "\n Nhap vao ma nhan vien "<<i+1  <<": " ;
		cin >> a;
		trung = kiemTraMaTrung(b,a);
		while (trung) {
			cout << "\n Ma da ton tai! :Nhap lai: ";
			cin >> a;
			trung = kiemTraMaTrung(b, a);
		}
		b.danhSachNV[i].maNV = a;
		nhapNV(b.danhSachNV[i]);
		b.danhSachNV[i].phongBan = b.tenPhong;
	}
}
void xuatNVTrongPB(PhongBan phongBan) {
	cout <<"\n============="<<phongBan.tenPhong<<"===========";
	for (int i = 0; i < phongBan.soLuongNV; i++) {
		cout << endl;
		xuatNV(phongBan.danhSachNV[i]);
	}
}
bool kiemTraMaTrung(PhongBan a , string ma  ) {
	for (int i = 0; i < a.soLuongNV; i++) {
		if (a.danhSachNV[i].maNV == ma) {
			return true ;
		}
	}
	return false;
}
bool kiemTraMaTrungCTY(CongTy a, string ma) {
	for (int i = 0; i < a.soLuongPB; i++) {
		if (a.danhSachPB[i].maPhong == ma) {
			return true;
		}
	}
	return false;
}
void nhapDSPB(CongTy& a) {
	int b,temp;
	cout << "\n Nhap vao so luong phong ban: ";
	cin >> b;
	//a.danhSachPB[a.soLuongPB];
	temp = a.soLuongPB;
	a.soLuongPB += b;
	string ma;
	for (int i = temp; i < a.soLuongPB; i++) {
		cout << "\n Phong Ban thu " << i + 1;
		nhapPB(a,a.danhSachPB[i]);
		cout << "\n=============== " << " Phong ban " << a.danhSachPB[i].tenPhong << " ===============";
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			cout << "\n Nhap vao ma nhan vien " << j + 1 << ": ";
			cin >> ma;
			while (kiemTraMaNhanVienTrung(a, ma)) {
				cout << "\nMa trung , Nhap lai : ";
				cin >> ma;
			}
			a.danhSachPB[i].danhSachNV[j].maNV = ma;
			nhapNV(a.danhSachPB[i].danhSachNV[j]);
			a.danhSachPB[i].danhSachNV[j].phongBan = a.danhSachPB[i].tenPhong;
		}
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
bool kiemTraMaNhanVienTrung(CongTy a, string ma) {
	for (int i = 0; i < a.soLuongPB; ++i) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; ++j) {
			if (a.danhSachPB[i].danhSachNV[j].maNV == ma) {
				return true;
			}
		}
	}
	// Không tìm thấy mã nhân viên trong công ty
	return false;
}

void xuatNVToanCTy(CongTy a) {
	cout << "\nNhan vien toan cong ty " << endl;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			xuatNV(a.danhSachPB[i].danhSachNV[j]);
			cout << endl;
		}
		
	}
}
void xuatNVHon20Nam(CongTy a) {
	cout << "\nNhan vien hon 20 nam" <<endl;

	bool tonTai = false; 
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (2023 - a.danhSachPB[i].danhSachNV[j].ngayVaoLam.nam > 20) {
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				cout << endl;

				tonTai = true;
			}
			
		}

	}
	if (tonTai == false)cout << "\nCong ty khong co nhan vien co tham nien hon 20 nam ";
}
void xuatNVLam6Thang(CongTy a) {
	cout << "\nNhan vien lam  <6 thang";
	bool tonTai = false;
	time_t hienTai = time(0);
	tm* diaPhuong = localtime(&hienTai);
	int namHienTai = 1900 + diaPhuong->tm_year;
	int thangHienTai = 1 + diaPhuong->tm_mon;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (namHienTai - a.danhSachPB[i].danhSachNV[j].ngayVaoLam.nam == 0 && thangHienTai - a.danhSachPB[i].danhSachNV[j].ngayVaoLam.thang <=6) {
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				cout << endl;
				tonTai = true;
			}
		}

	}
	if (tonTai == false)cout << "\nKhong ton tai nhan vien lam  <6 thang";

}
void xuatNVTu20Den45(CongTy a) {
	cout << "\nNhan vien do tuoi 20 ->45";
	bool tonTai = false; 
	time_t hienTai = time(0);
	tm* diaPhuong = localtime(&hienTai);
	int namHienTai = 1900 + diaPhuong->tm_year;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if(namHienTai - a.danhSachPB[i].danhSachNV[j].NgaySinh.nam >=20 && namHienTai - a.danhSachPB[i].danhSachNV[j].NgaySinh.nam <= 45){
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				cout << endl;

				tonTai = true;  
			}
		}

	}
	if (tonTai == false)cout << "\nKhong ton tai nhan vien do tuoi 20 ->45";
}
void xuatNVNu(CongTy a){
	cout << "\nNhan vien la nu " << endl;
	bool tonTai = false;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].gioiTinh == 0)
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
			cout << endl;
				tonTai = true;
			}
		}
	if(tonTai == false)cout << "\nKhong ton tai nhan vien nu";
}
void suaThongTin(CongTy& a) {
	string ma;
	cout << "\nNhap vao ma nhan vien ";
	cin >> ma; 
	int m, n;
	bool trung = false;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].maNV == ma ) {
				trung = true;
				m = i;
				n = j;
			}
		}
	}
	if (trung == true) {
	xuatNV(a.danhSachPB[m].danhSachNV[n]);
	nhapNV(a.danhSachPB[m].danhSachNV[n]);
	xuatNV(a.danhSachPB[m].danhSachNV[n]);

	}
	else  cout << "\nKhong ton tai nhan vien";
 }
void timNVTheoMa(CongTy a) {
	string ma;

	cout << "\nNhap vao ma nhan vien ";
	cin >> ma;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].maNV == ma) {
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				return;
			}
		}
	}
	cout << "\nKhong ton tai nhan vien co ma  la " << ma;
}

void timNVTheoTen(CongTy a) {
	string ten;
	bool tonTai = false;

	cout << "\nNhap vao ten nhan vien ";
	cin >> ten; 
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (layTen(a.danhSachPB[i].danhSachNV[j].tenNV) == ten) {
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				tonTai = true;
				cout << endl;

			}
		}
	}
	if (tonTai == false)cout << "Khong ton tai nhan vien co ten la " <<ten ;
}
void timNVTheoMucLuong(CongTy a) {

	bool tonTai = false;

	int luong;
	cout << "\nNhap vao muc luong nhan vien ";
	cin >> luong;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].luong == luong) {
				tonTai = true;
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				cout << endl;
			}
		}
	}
	if (tonTai == false)cout << "Khong ton tai nhan vien co muc luong la " << luong;
}
string layTen(string  name) {
	string ten ="";
	for(int i = name.length()-1; i >= 0; i--) {
		if (name[i] == ' ')break;
		ten += name[i];
	}
	string ten2 ="";
	for(int i = ten.length()-1; i >= 0; i--) {
		ten2 += ten[i];
	}
	return ten2;
}
void timNVTheoThamNien(CongTy a) {
	time_t hienTai = time(0);
	tm* diaPhuong = localtime(&hienTai);
	int namHienTai = 1900 + diaPhuong->tm_year;
	int nam;
	bool tonTai = false;
	cout << "\nNhap vao so nam lam viec :" ;
	cin >> nam;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (namHienTai- a.danhSachPB[i].danhSachNV[j].ngayVaoLam.nam == nam ) {
				tonTai = true;

				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				cout << endl;
			}
		}
	}
	if(tonTai==false)cout << "\nKhong ton tai nhan vien co tham nien " << nam << " nam";
}
void demSoNVTungPhong(CongTy a) {
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n<(" << i + 1 << ")" << a.danhSachPB[i].tenPhong <<" so nhan vien : "<<a.danhSachPB[i].soLuongNV;
	}
}
void demSoNVCTY(CongTy a) {
	int tong = 0; 
	for (int i = 0; i < a.soLuongPB; i++) {
		tong += a.danhSachPB[i].soLuongNV;
	}
	cout << "\nSo luong nhan vien cua cong ty la " << tong;
}
void xuatNVLuongThap(CongTy a) {
	int min = a.danhSachPB[0].danhSachNV[0].luong;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].luong < min)min = a.danhSachPB[i].danhSachNV[j].luong;
		}
	}
	cout <<"\nNhan vien luong thap :" ;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].luong == min) {
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				cout << endl;
			}
				
		}
	}
}
void xuatNVLuongCao(CongTy a) {
	int max = a.danhSachPB[0].danhSachNV[0].luong;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].luong > max)max = a.danhSachPB[i].danhSachNV[j].luong;
		}
	}
	cout << "\nNhan vien luong cao :";
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].luong == max) {
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				cout << endl;
			}

		}
	}
}
void thongKeBanLuong(CongTy a) {
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			cout << left << setw(20) << "\nHo Ten : " << a.danhSachPB[i].danhSachNV[j].tenNV << "\t Muc Luong : " << a.danhSachPB[i].danhSachNV[j].luong;
			}
		}
}
void tongLuong(CongTy a) {
	int tong = 0;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			tong += a.danhSachPB[i].danhSachNV[j].luong;
		}
	}
	cout << "\nTong  luong cua cong ty la: " << tong;
}
void sapXepNVTheoTen(CongTy& a) {
	int chon; 
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n(" << i + 1 << ")";
		cout << a.danhSachPB[i].tenPhong;

	}
	cout << "\n Nhap vao phong ban mun sap xep: ";
	cin >> chon; 
	cout << "\n danh sach phong chua sap xep ";
	chon -= 1;
	xuatNVTrongPB(a.danhSachPB[chon]);
	NhanVien temp;
	for (int i = 0; i < a.danhSachPB[chon].soLuongNV-1; i++) {
		for (int j = i + 1; j < a.danhSachPB[chon].soLuongNV; j++) {
			if (layTen(a.danhSachPB[chon].danhSachNV[j].tenNV)[0] < layTen(a.danhSachPB[chon].danhSachNV[i].tenNV)[0]) {
				temp = a.danhSachPB[chon].danhSachNV[i];
				a.danhSachPB[chon].danhSachNV[i] = a.danhSachPB[chon].danhSachNV[j];
				a.danhSachPB[chon].danhSachNV[j] = temp;
			}
		}
	}
	cout << "\n danh sach phong da sap xep ";
	xuatNVTrongPB(a.danhSachPB[chon]);
}


void sapXepNVTheoLuong(CongTy& a) {
	int chon;
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n(" << i + 1 << ")";
		cout << a.danhSachPB[i].tenPhong;

	}
	cout << "\n Nhap vao phong ban mun sap xep: ";
	cin >> chon;
	cout << "\n danh sach phong chua sap xep ";
	chon -= 1;
	xuatNVTrongPB(a.danhSachPB[chon]);
	NhanVien temp;
	for (int i = 0; i < a.danhSachPB[chon].soLuongNV - 1; i++) {
		for (int j = i + 1; j < a.danhSachPB[chon].soLuongNV; j++) {
			if (a.danhSachPB[chon].danhSachNV[j].luong > a.danhSachPB[chon].danhSachNV[i].luong) {
				temp = a.danhSachPB[chon].danhSachNV[i];
				a.danhSachPB[chon].danhSachNV[i] = a.danhSachPB[chon].danhSachNV[j];
				a.danhSachPB[chon].danhSachNV[j] = temp;
			}
		}
	}
	cout << "\n danh sach phong da sap xep ";
	xuatNVTrongPB(a.danhSachPB[chon]);
}

void displayMenu() {
	int columnWidth = 40;
	cout << "\n--------------------------------------------------------------- MENU ----------------------------------------------------" << endl;
	cout << left << setw(columnWidth) << "| 1. Nhap thong tin phong ban" << setw(columnWidth) << "| 2. Xuat DSNV toan cong ty" << setw(columnWidth) << "| 3. Xuat nhan vien theo tung phong" << "|" << endl;
	cout << left << setw(columnWidth) << "| 4. Nhan vien co tham nien > 20 nam" << setw(columnWidth) << "| 5. DSNV co do tuoi 20->45" << setw(columnWidth) << "| 6. Xuat nhan vien la nu" << "|" << endl;
	cout << left << setw(columnWidth) << "| 7. Xuat nhan vien da nghi viec" << setw(columnWidth) << "| 8. Sua thong tin cua nhan vien" << setw(columnWidth) << "| 9. Sap xep theo ten" << "|" << endl;
	cout << left << setw(columnWidth) << "| 10. Sap xep theo luong" << setw(columnWidth) << "| 11. Tim kiem nhan vien ma si" << setw(columnWidth) << "| 12. Tim kiem nhan vien theo ten" << "|" << endl;
	cout << left << setw(columnWidth) << "| 13. Tim kiem nhan vien muc luong" << setw(columnWidth) << "| 14. Tim kiem nhan vien theo tham nien" << setw(columnWidth) << "| 15. So luong nhan vien theo tung phong" << "|" << endl;
	cout << left << setw(columnWidth) << "| 16. So luong nhan vien toan cong ty" << setw(columnWidth) << "| 17. DSNV co luong thap nhat" << setw(columnWidth) << "| 18. DSNV co luong cao nhat" << "|" << endl;
	cout << left << setw(columnWidth) << "| 19. NV thoi gian lam viec < 6 thang" << setw(columnWidth) << "| 20. Bang luong cua ca con ty" << setw(columnWidth) << "| 21. Luong cua toan cong ty" << "|" << endl;
	cout << left << setw(columnWidth) << "| 22. Xoa nhan vien" << setw(columnWidth) << "| 23. chuyen nhan vien  sang phong khac" << setw(columnWidth) << "| 24. Tach 1 phong thanh 2 phong" << "|" << endl;
	cout << left << setw(columnWidth) << "| 25. Ghep 2 phong thanh 1 phong" << setw(columnWidth) << "| 0. Thoat" << "| 26 ghi file " << setw(columnWidth) << "27. Doc" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

}



void diChuyenNV(CongTy& a) {
	int phongHT, phongChuyenDen,nhanVienChuyen;
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "(" << i + 1 << ") " << a.danhSachPB[i].tenPhong<<endl;
	}
	cout << "\n ban muon chuyen nhan vien o phong nao ";
	cin >> phongHT;
	phongHT -= 1;
	for (int i = 0; i < a.danhSachPB[phongHT].soLuongNV; i++) {
		cout << "(" << i + 1 << ") " << a.danhSachPB[phongHT].danhSachNV[i].maNV << "\t" << a.danhSachPB[phongHT].danhSachNV[i].tenNV <<endl;
	}
	cout << "\n ban muon chi chuyen nhan vien nao ";
	cin >> nhanVienChuyen;
	nhanVienChuyen -= 1;
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "(" << i + 1 << ") " << a.danhSachPB[i].tenPhong << endl;
	}
	cout << "\n ban muon chuyen nhan vien den phong  nao ";
	cin >> phongChuyenDen;
	phongChuyenDen -= 1;
	NhanVien b = a.danhSachPB[phongHT].danhSachNV[nhanVienChuyen];
	b.phongBan = a.danhSachPB[phongChuyenDen].tenPhong;
	int temp = a.danhSachPB[phongChuyenDen].soLuongNV;
	a.danhSachPB[phongChuyenDen].danhSachNV[temp] = b;
	a.danhSachPB[phongChuyenDen].soLuongNV++;

	for (int i = nhanVienChuyen; i < a.danhSachPB[phongHT].soLuongNV - 1; ++i) {
		a.danhSachPB[phongHT].danhSachNV[i] = a.danhSachPB[phongHT].danhSachNV[i + 1];

	}
	a.danhSachPB[phongHT].soLuongNV--;
	cout << "Da chuyen nhan vien " << b.maNV << " den phong " << a.danhSachPB[phongChuyenDen].tenPhong << endl;
}



void ghi(string fileName ,CongTy a ) {
	ofstream file(fileName,ios::trunc);
	if (file.is_open()) {
		file << a.soLuongPB << endl;
		for (int i = 0; i < a.soLuongPB; i++) {
			file << a.danhSachPB[i].maPhong <<"\n";
			file << a.danhSachPB[i].tenPhong << "\n";
			file << a.danhSachPB[i].soLuongNV << "\n";
			file << "\n";
			for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
				file << a.danhSachPB[i].danhSachNV[j].maNV << "\n"; 
				file << a.danhSachPB[i].danhSachNV[j].tenNV << "\n";
				file << a.danhSachPB[i].danhSachNV[j].gioiTinh << "\n";
				file << a.danhSachPB[i].danhSachNV[j].NgaySinh.ngay << "\n";
				file << a.danhSachPB[i].danhSachNV[j].NgaySinh.thang << "\n";
				file << a.danhSachPB[i].danhSachNV[j].NgaySinh.nam << "\n";
				file << a.danhSachPB[i].danhSachNV[j].ngayVaoLam.ngay << "\n";
				file << a.danhSachPB[i].danhSachNV[j].ngayVaoLam.thang << "\n";
				file << a.danhSachPB[i].danhSachNV[j].ngayVaoLam.nam << "\n";
				file << a.danhSachPB[i].danhSachNV[j].luong << "\n";
				file << a.danhSachPB[i].danhSachNV[j].phongBan << "\n";
				file << "\n";
			}
			file << "\n";
		}
	}
}

void xoa(string fileXoa, CongTy& a) {
	ofstream file(fileXoa,ios::app );
	xuatDSPB(a);
	int chon,chon2;
		NhanVien c; 
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n(" << i + 1 << ")" << a.danhSachPB[i].tenPhong << endl;
	}
	cout << "\nNhap vao phong ban co nhan vien muon xoa ";
	cin >> chon;
	chon -= 1;
	for (int i = 0; i < a.danhSachPB[chon].soLuongNV; i++) {
		cout << "(" << i + 1 << ")" << "Ma nhan vien " << a.danhSachPB[chon].danhSachNV[i].maNV << " ten nhan vien :" << a.danhSachPB[chon].danhSachNV[i].tenNV << endl;
	}cout << "\n chon nhan vien muon xoa ";
	cin >> chon2;
	chon2 -= 1;
	 c = a.danhSachPB[chon].danhSachNV[chon2];
	if (file.is_open()) {
		file << c.maNV<<"\n";
		file << c.tenNV<<"\n";
		file << c.gioiTinh<<"\n";
		file << c.NgaySinh.ngay<<"\n";
		file << c.NgaySinh.thang<<"\n";
		file << c.NgaySinh.nam<<"\n";
		file << c.ngayVaoLam.ngay<<"\n";
		file << c.ngayVaoLam.thang<<"\n";
		file << c.ngayVaoLam.nam<<"\n";
		file << c.luong<<"\n";
		file << c.phongBan<<"\n";

		file.close();
	}
	for (int i = 0; i < a.danhSachPB[chon].soLuongNV; i++) {
		if (a.danhSachPB[chon].danhSachNV[chon2].maNV == c.maNV) {
			for (int j = i + 1; j < a.danhSachPB[chon].soLuongNV; j++) {
				a.danhSachPB[chon].danhSachNV[i] = a.danhSachPB[chon].danhSachNV[j];
			}
			a.danhSachPB[chon].soLuongNV--;
			cout << "\n Da xoa nhanh vien";
			return;
		}
	}
}






void docNVDaxoa(string fileXoa, PhongBan& a) {
	ifstream file(fileXoa);
	a.soLuongNV = 0;
	int i = 0;
	if (file.is_open()) {
		while (file.eof() != true) {
			switch (i)
			{
			case 0:
				file >> a.danhSachNV[a.soLuongNV].maNV;
				i++;
				break;
			case 1:
				getline(file, a.danhSachNV[a.soLuongNV].tenNV);
				getline(file, a.danhSachNV[a.soLuongNV].tenNV);
				i++;
				break;
			case 2: 
				file >> a.danhSachNV[a.soLuongNV].gioiTinh;
				i++;
				break;
			case 3:
				file >> a.danhSachNV[a.soLuongNV].NgaySinh.ngay;
				i++; break;
			case 4:
				file >> a.danhSachNV[a.soLuongNV].NgaySinh.thang;
				i++; break;
			case 5:
				file >> a.danhSachNV[a.soLuongNV].NgaySinh.nam;
				i++; break;
			case 6:
				file >> a.danhSachNV[a.soLuongNV].ngayVaoLam.ngay;
				i++; break;
			case 7:
				file >> a.danhSachNV[a.soLuongNV].ngayVaoLam.thang;
				i++; break;
			case 8:
				file >> a.danhSachNV[a.soLuongNV].ngayVaoLam.nam;
				i++; break;
			case 9:
				file >> a.danhSachNV[a.soLuongNV].luong;
				i++; break;
			case 10:
				file >> a.danhSachNV[a.soLuongNV].phongBan;
				i=0; 
				a.soLuongNV++;
				break;

			default:
				break;
			}
		}
	}

}




void doc(string fileName, CongTy& a) {
	ifstream file(fileName);
	if (file.is_open()) {
		file >> a.soLuongPB;
		for (int i = 0; i < a.soLuongPB; i++) {
			file >> a.danhSachPB[i].maPhong;
			getline(file, a.danhSachPB[i].tenPhong);
			getline(file, a.danhSachPB[i].tenPhong);
			file >> a.danhSachPB[i].soLuongNV;
			for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
				file >> a.danhSachPB[i].danhSachNV[j].maNV;
				getline(file, a.danhSachPB[i].danhSachNV[j].tenNV);
				getline(file, a.danhSachPB[i].danhSachNV[j].tenNV);
				file >> a.danhSachPB[i].danhSachNV[j].gioiTinh;
				file >> a.danhSachPB[i].danhSachNV[j].NgaySinh.ngay;
				file >> a.danhSachPB[i].danhSachNV[j].NgaySinh.thang;
				file >> a.danhSachPB[i].danhSachNV[j].NgaySinh.nam;
				file >> a.danhSachPB[i].danhSachNV[j].ngayVaoLam.ngay;
				file >> a.danhSachPB[i].danhSachNV[j].ngayVaoLam.thang;
				file >> a.danhSachPB[i].danhSachNV[j].ngayVaoLam.nam;
				file >> a.danhSachPB[i].danhSachNV[j].luong;
				getline(file, a.danhSachPB[i].danhSachNV[j].phongBan);
				getline(file, a.danhSachPB[i].danhSachNV[j].phongBan);

			}
		}
	}
}


void tachPhong(CongTy& a) {
	int chon;
	int chonNV;
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "(" << i + 1 << ")" << a.danhSachPB[i].tenPhong << endl;
	}
	cout << "\nChon phong muon tach:";
	cin >> chon;
	int cuoi = a.soLuongPB;
	a.soLuongPB++;
	for (int i = 0; i < a.danhSachPB[chon - 1].soLuongNV; i++) {
		cout << "\n(" << i + 1 << ")" << a.danhSachPB[chon - 1].danhSachNV[i].maNV 
			<< " " << a.danhSachPB[chon - 1].danhSachNV[i].tenNV;
	}
	cout << "\nTach tu nhan vien thu :";
	cin >> chonNV;
	while (chonNV > a.danhSachPB[chon - 1].soLuongNV + 1||chonNV <= 0 ) {
		cout << "\nNhan vien khong ton tai! Nhap lai: ";
		cin >> chonNV;
	}
	cout << "\n nhap thong tin phong moi";
	nhapPB(a, a.danhSachPB[cuoi]);
	a.danhSachPB[cuoi].soLuongNV = a.danhSachPB[chon - 1].soLuongNV-(chonNV-1) ;
	for(int i = 0; i < a.danhSachPB[cuoi].soLuongNV; i++) {
		a.danhSachPB[cuoi].danhSachNV[i] = a.danhSachPB[chon - 1].danhSachNV[chonNV - 1 + i];
		a.danhSachPB[cuoi].danhSachNV[i].phongBan = a.danhSachPB[cuoi].tenPhong;
	}
	a.danhSachPB[chon - 1].soLuongNV -= a.danhSachPB[cuoi].soLuongNV+1;
}

void gopPhong(CongTy& a) {
	int phong1, phong2;
	cout << "\n Chon 2 phong muon gop";
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n(" << i + 1 << ") " << a.danhSachPB[i].tenPhong << endl;
	}
	cout << "\nPhong1: ";
	cin >> phong1;
	 phong1--;
	cout << "\nPhong2: ";
	cin >> phong2;
	 phong2--;
	int temp = a.danhSachPB[phong1].soLuongNV;
	a.danhSachPB[phong1].soLuongNV += a.danhSachPB[phong2].soLuongNV;
	for (int i = 0; i < a.danhSachPB[phong1].soLuongNV; i++) {
		a.danhSachPB[phong2].danhSachNV[i].phongBan = a.danhSachPB[phong1].tenPhong;
		a.danhSachPB[phong1].danhSachNV[temp++] = a.danhSachPB[phong2].danhSachNV[i];

	}
	for (int i = phong2; i < a.soLuongPB; i++) {
		a.danhSachPB[i] = a.danhSachPB[i + 1];
	}
	a.soLuongPB--;
}