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
 }

void xuatPB(PhongBan phongBan) {
	cout << "\nMa phong ban: " << phongBan.maPhong;
	cout << "\nTen phong ban: " << phongBan.tenPhong;
	cout << "\nSo luong nhan vien: " << phongBan.soLuongNV;
}
void nhapNVTrongPB(PhongBan& phongBan , CongTy cty) {
	bool trung; 
	string a;
	cout << "\n===============" << " Phong ban " << phongBan.tenPhong<< "===============" ;
	for (int i = 0; i < phongBan.soLuongNV;i++) {
		cout << "\n Nhap vao ma nhan vien";
		cin >> a;
		trung = kiemTraMaTrungCTY(cty,a);
		while (trung) {
			cout << "\n Ma da ton tai! :Nhap lai: ";
			cin >> a;
			trung = kiemTraMaTrung(phongBan, a);
		}
		phongBan.danhSachNV[i].maNV = a;
		nhapNV(phongBan.danhSachNV[i]);
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
void sapXepNVTheoTen(CongTy a) {
	
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