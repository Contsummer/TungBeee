#include"Header.h"
int main() {

	string fileName = "employee_data.txt";
	string fileNameXoa = "xoa.txt";
	CongTy a ;
	doc(fileName,a);
	int choice;
    PhongBan b; 
    system("cls");
    do {
        displayMenu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice){
        case 0:
            cout << "Thoat chuong trinh..." << endl;
            
            break;
        case 1:
            system("cls");
            nhapDSPB(a); 
            ghi(fileName,a);
            break;
        case 2:
            system("cls");
            if (a.soLuongPB == 0) {
                cout << "\nChua co nhan vien nao !";
                break;
            }
            xuatNVToanCTy(a); 
            break;
        case 3:
            system("cls");
            int vitri;
            cout << "\nChon ten phong muon xuat : " <<endl ;
            for (int i = 0; i < a.soLuongPB; i++) {
                cout << "(" << i + 1 << ")" << a.danhSachPB[i].tenPhong<<endl ;
            }
            cin >> vitri;
            xuatNVTrongPB(a.danhSachPB[vitri-1  ]); 
            break;
        case 4:
            system("cls");
            xuatNVHon20Nam(a);
            break;
        case 5:
            system("cls");
            xuatNVTu20Den45(a); 
            break;
        case 6:
            system("cls");
            xuatNVNu(a);
            break;
        case 7:
            cout << "\n danh sach nhan vien da xoa";
            docNVDaxoa(fileNameXoa, b);
            xuatNVTrongPB(b);
            break;
        case 8:

            suaThongTin(a); 
            break;
        case 9:
            system("cls");
            sapXepNVTheoTen(a); 
            break;
        case 10:
            system("cls");
            sapXepNVTheoLuong(a);
            break;
        case 11:
            timNVTheoMa(a);
            break;
        case 12:
            timNVTheoTen(a); 
            break;
        case 13:
            timNVTheoMucLuong(a); 
            break;
        case 14:
            timNVTheoThamNien(a); 
            break;
        case 15:
            system("cls");
            demSoNVTungPhong(a); 
            break;

        case 16:
            system("cls");
            demSoNVCTY(a);
            break;
        case 17:
            system("cls");
            xuatNVLuongThap(a); 
            break;
        case 18:
            system("cls");
            xuatNVLuongCao(a); 
            break;
        case 19:
            xuatNVLam6Thang(a);
            break;
        case 20:
            system("cls");

            thongKeBanLuong(a); 
            break;
        case 21:
            system("cls");

            tongLuong(a); 
            break;
        case 22:
            xoa(fileNameXoa, a);
            break;
        case 23:
            diChuyenNV(a);
            break;
        case 24:
            // Xử lý tách 1 phòng thành 2 phòng
            // tachPhong(a);
            break;
        case 25:
            // Xử lý ghép 2 phòng thành 1 phòng
            // ghepPhong(a);
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
            break;
        }
    }while (choice != 0);
	return 0; 
}
