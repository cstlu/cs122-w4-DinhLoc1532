#include <iostream>
#include <iomanip>
using namespace std;

class NhanVien
{
protected:
	string id;
	string fullname;
	string taxcode;
	int luong_cung;
public:
	void nhap();
	void xuat();
	void nhapLuong_cung();
	void xuatLuong_cung();
};

class NhanVienBC : public NhanVien
{
public:
	void nhap();
	void xuat();
};

class NhanVienHD : public NhanVien
{
private:
	int gio;
	int luong_1_gio;
public:
	void nhap();
	void xuat();
};

class NhanVienHH : public NhanVien
{
protected:
	int tongdoanhthu;
public:
	void nhap();
	void xuat();
};

class NhanVienHHDB : public NhanVienHH
{
public:
	void nhap();
	void xuat();
};

//NHANVIEN
void NhanVien::nhap()
{
	cout << "Nhap ID: ";				fflush(stdin);		cin >> id;
	cout << "Nhap ten nhan vien: ";			fflush(stdin);		getline(cin,fullname);
	cout << "Nhap ma so thue: ";			fflush(stdin);		cin >> taxcode;
}

void NhanVien::xuat()
{
	cout << "ID " << id << endl;
	cout << "Ho va ten nhan vien: " << fullname << endl;
	cout << "Ma so thue: " << taxcode << endl;
}

void NhanVien::nhapLuong_cung()
{
	cout << "Nhap luong cung: ";	fflush(stdin);		cin >> luong_cung;
}

void NhanVien::xuatLuong_cung()
{
	cout << "Luong cua ban: " << luong_cung << endl;	
}

//NHANVIEN BIEN CHE
void NhanVienBC::nhap()
{
	NhanVien::nhap();
	NhanVien::nhapLuong_cung();
}

void NhanVienBC::xuat()
{
	NhanVien::xuat();
	NhanVien::xuatLuong_cung();
}

//NHANVIEN HOP DONG
void NhanVienHD::nhap()
{
	NhanVien::nhap();
	cout << "Nhap luong 1 gio: ";		fflush(stdin);		cin >> luong_1_gio;
	cout << "Nhap so gio lam duoc: ";	fflush(stdin);		cin >> gio;
}

void NhanVienHD::xuat()
{
	int luong = 0;
	NhanVien::xuat();
	if(gio > 40)
	{
		luong = luong_1_gio * 40 + 1000000;
		cout << "Luong cua ban: " << luong << endl;
	}	
	else 
	{
		luong = luong_1_gio * gio;
		cout << "Luong cua ban: " << luong << endl;
	}
}

//NHANVIEN HOA HONG
void NhanVienHH::nhap()
{
	NhanVien::nhap();
	cout << "Nhap tong so doanh thu: ";	fflush(stdin);		cin >> tongdoanhthu;
}

void NhanVienHH::xuat()
{
	NhanVien::xuat();
	cout << "Luong cua ban: " << tongdoanhthu << endl;
}

//NHANVIEN HOA HONG DAC BIET
void NhanVienHHDB::nhap()
{
	NhanVienHH::nhap();
	NhanVien::nhapLuong_cung();
}

void NhanVienHHDB::xuat()
{
	NhanVien::xuat();
	int luong = 0;
	luong = tongdoanhthu + 0.1*luong_cung; 
	cout << "Luong cua ban: " << luong << endl;
}

int main()
{
	NhanVienBC a;	NhanVienHD b;	NhanVienHH c;	NhanVienHHDB d;
	
	cout << setw(30) << "NHAP THONG TIN NV BC" << endl;
	a.nhap();
	cout << endl;
	cout << setw(30) << "NHAP THONG TIN NV HD" << endl;
	b.nhap();
	cout << endl;
	cout << setw(30) << "NHAP THONG TIN NV HH" << endl;
	c.nhap();
	cout << endl;
	cout << setw(30) << "NHAP THONG TIN NV HHDB" << endl;
	d.nhap();
	cout << endl;
	
	cout << setw(30) << "THONG TIN NV BC" << endl;
	a.xuat();
	cout << endl;
	cout << setw(30) << "THONG TIN NV HD" << endl;
	b.xuat();
	cout << endl;
	cout << setw(30) << "THONG TIN NV HH" << endl;
	c.xuat();
	cout << endl;
	cout << setw(30) << "THONG TIN NV HHDB" << endl;
	d.xuat();
	cout << endl;
	return 0;
}
