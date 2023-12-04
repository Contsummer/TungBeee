#include"Header.h"
void nhapPB(PhongBan& PhongBan) {
	cout << "\nNhap ma phong: "; 
	cin >> PhongBan.maPhong;
	cout << "Nhap ten phong: ";
	cin >> PhongBan.tenPhong;
	cout << "Nhap so luong nhan vien trong phong: ";
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
void nhapNVTrongPB(PhongBan& b , CongTy cty) {
	bool trung; 
	string a;
	cout << "\n===============" << " Phong ban " << b.tenPhong<< "===============" ;
	for (int i = 0; i < b.soLuongNV;i++) {
		cout << "\n Nhap vao ma nhan vien";
		cin >> a;
		trung = kiemTraMaTrungCTY(cty,a);
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
void nhapDSPB(CongTy& a) {
	cout << "\n Nhap vao so luong phong ban: ";
	cin >> a.soLuongPB;
	//a.danhSachPB[a.soLuongPB];
	
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n Phong Ban thu " << i + 1;
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
bool kiemTraMaTrungCTY(CongTy a, string ma) {
	bool trung;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (ma == a.danhSachPB[i].danhSachNV[j].maNV)return true; 
		}
	}
	return false ;
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
void xuatNVTu20Den45(CongTy a) {
	cout << "\nNhan vien do tuoi 20 ->45";
	bool tonTai = false; 
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if(2023 - a.danhSachPB[i].danhSachNV[j].NgaySinh.nam >=20 && 2023 - a.danhSachPB[i].danhSachNV[j].NgaySinh.nam <= 45){
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
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (a.danhSachPB[i].danhSachNV[j].maNV == ma ) {
				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				nhapNV(a.danhSachPB[i].danhSachNV[j]);
				return;
			}
		}
	}
	cout << "\nKhong ton tai nhan vien"; 
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
	int nam;
	bool tonTai = false;
	cout << "\nNhap vao so nam lam viec :" ;
	cin >> nam;
	for (int i = 0; i < a.soLuongPB; i++) {
		for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
			if (2023- a.danhSachPB[i].danhSachNV[j].ngayVaoLam.nam == nam ) {
				tonTai = true;

				xuatNV(a.danhSachPB[i].danhSachNV[j]);
				cout << endl;
			}
		}
	}
	if(tonTai==false)cout << "\nKhong ton tai nhan vien co tham nien " << nam << " nam";
}
void demSoNVTungPhong(CongTy a) {
	int chon;
	for (int i = 0; i < a.soLuongPB; i++) {
		cout << "\n(" << i+1 << ")" << a.danhSachPB[i].tenPhong << endl;;
		
	}
	cout << "\nChon phong : "; 
	cin >> chon;
	cout << "So nhan vien cua phong " << a.danhSachPB[chon-1].tenPhong << " la " << a.danhSachPB[chon-1].soLuongNV;
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
			cout << "\nHo Ten : " << a.danhSachPB[i].danhSachNV[j].tenNV << "\t Muc Luong : " << a.danhSachPB[i].danhSachNV[j].luong;
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


void displayMenu() {
	system("cls");
	cout << "------- MENU -------" << endl;
	cout << "1. Nhap thong tin phong ban" << endl;
	cout << "2. Xuat danh sach nhan vien toan cong ty" << endl;
	cout << "3. Xuat nhan vien theo tung phong" << endl;
	cout << "4. Xuat nhan vien co tham nien > 20 nam" << endl;
	cout << "5. Xuat danh sach nhan vien co do tuoi 20->45" << endl;
	cout << "6. Xuat nhan vien la nu" << endl;
	cout << "7. Xuat nhan vien da nghi viec" << endl;
	cout << "8. Sua thong tin cua nhan vien" << endl;
	cout << "9. Sap xep theo ten" << endl;
	cout << "10. Sap xep theo luong" << endl;
	cout << "11. Tim kiem nhan vien ma si" << endl;
	cout << "12. Tim kiem nhan vien theo ten" << endl;
	cout << "13. Tim kiem nhan vien muc luong" << endl;
	cout << "14. Tim kiem nhan vien theo tham nien" << endl;
	cout << "15. Dem so luong nhan vien theo tung phong" << endl;
	cout << "16. Dem so luong nhan vien toan cong ty" << endl;
	cout << "17. Danh sach nhan vien co luong thap nhat" << endl;
	cout << "18. Danh sach nhan vien co luong cao nhat" << endl;
	cout << "19. Nhan vien co thoi gian lam viec < 6 thang" << endl;
	cout << "20. Bang luong cua ca con ty" << endl;
	cout << "21. Luong cua toan cong ty" << endl;
	cout << "22. Xoa nhan vien" << endl;
	cout << "23. Di chuyen nhan vien tu phong nay sang phong khac" << endl;
	cout << "24. Tach 1 phong thanh 2 phong" << endl;
	cout << "25. Ghep 2 phong thanh 1 phong" << endl;
	cout << "0. Thoat" << endl;
	cout << "---------------------" << endl;
}








void ghi(string fileName ,CongTy a ) {
	ofstream file(fileName);
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


void doc(string fileName, CongTy& a) {
	ifstream file(fileName);
	if (file.is_open()) {
		file >> a.soLuongPB;
		for (int i = 0; i < a.soLuongPB; i++) {
			getline(file, a.danhSachPB[i].maPhong);
			getline(file, a.danhSachPB[i].maPhong);
			getline(file, a.danhSachPB[i].tenPhong);
			file >> a.danhSachPB[i].soLuongNV;
			for (int j = 0; j < a.danhSachPB[i].soLuongNV; j++) {
				file >> a.danhSachPB[i].danhSachNV[j].maNV;
				file >> a.danhSachPB[i].danhSachNV[j].tenNV;
				file >> a.danhSachPB[i].danhSachNV[j].gioiTinh;
				file >> a.danhSachPB[i].danhSachNV[j].NgaySinh.ngay;
				file >> a.danhSachPB[i].danhSachNV[j].NgaySinh.thang;
				file >> a.danhSachPB[i].danhSachNV[j].NgaySinh.nam;
				file >> a.danhSachPB[i].danhSachNV[j].ngayVaoLam.ngay;
				file >> a.danhSachPB[i].danhSachNV[j].ngayVaoLam.thang;
				file >> a.danhSachPB[i].danhSachNV[j].ngayVaoLam.nam;
				file >> a.danhSachPB[i].danhSachNV[j].luong;
			//	file >> a.danhSachPB[i].danhSachNV[j].phongBan;
			}
		}
	}
}
