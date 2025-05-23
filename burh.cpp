#include <bits/stdc++.h>
using namespace std;

struct tamTham {
    char tenHang[50];
    int dienTich;
    long giaTri;
    char mauSac[20];
};

void inTieuDe() {
    cout << left << setw(20) << "Ten Hang" 
         << setw(20) << "Dien Tich" 
         << setw(20) << "Gia Tri" 
         << setw(20) << "Mau Sac" << endl;
}

void inDL(tamTham t[], int n) {
    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << t[i].tenHang 
             << setw(20) << t[i].dienTich 
             << setw(20) << t[i].giaTri 
             << setw(20) << t[i].mauSac << endl;
    }
}

bool soSanh(tamTham a, tamTham b) {
    return a.giaTri < b.giaTri;
}

struct ketQua1 {
    int count;
    int tongDienTich;
    tamTham d[6];
};

ketQua1 a_thamLam(tamTham d[], int n, int m) {
    ketQua1 kq = {};
    int tong = 0, tongDT = 0;
    for (int i = 0; i < n; i++) {
        if (tong + d[i].giaTri <= m) {
            kq.d[kq.count++] = d[i];
            tong += d[i].giaTri;
            tongDT += d[i].dienTich;
        }
    }
    kq.tongDienTich = tongDT;
    return kq;
}

struct ketQua2{
	int count;
	int tongGiaTri;
	tamTham t[6];
};
ketQua2 b_qhd(tamTham d[], int n, int s){
	int f[n+1][s+1] = {};
	for(int j = 0; j<= s; j++){
		f[0][j] = 0;
	}
	for(int i = 1; i<n; i++){
		for(int j = 0; j<= s; j++){
			f[i][j] = f[i-1][j];
			if(j>= d[i-1].dienTich){
				int temp = f[i-1][j-d[i-1].dienTich]+ d[i-1].giaTri;
				if(temp> f[i][j]){
					f[i][j]= temp;
				}
			}
		}
	}
	
	ketQua2 kq = {};
	int i = n; int j = s;
	while(i>0 && j>0){
		if(f[i][j] != f[i-1][j]){
			kq.t[kq.count++] = d[i-1]; 
			kq.tongGiaTri += d[i-1].giaTri;
			j -= d[i-1].dienTich ;
		}
		i--;
	}
	return kq;
}
int main() {
    int n = 6;
    int m = 300000; // ngân sách
    tamTham d[6] = {
        {"lmao", 45, 100000, "xanh"},
        {"burh", 50, 150000, "do"},
        {"dark", 35, 80000, "tim"},
        {"chemr", 20, 40000, "vang"},
        {"nguu", 29, 190000, "hong"},
        {"lao", 42, 120000, "den"},
    };

    sort(d, d + n, soSanh);
    ketQua1 kq1 = a_thamLam(d, n, m);

    cout << "\nDanh sach tam tham da chon:\n";
    inTieuDe();
    inDL(kq1.d, kq1.count);

    cout << "\nSo luong tam tham da chon: " << kq1.count << endl;
    cout << "Tong dien tich: " << kq1.tongDienTich << endl;
	
	int s = 100;
	ketQua2 kq2 = b_qhd(d, n, s);
    cout << "\nKet qua toi uu:" << endl;
    inTieuDe();
    inDL(kq2.t, kq2.count);
    return 0;
}

