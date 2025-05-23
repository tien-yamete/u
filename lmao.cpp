#include <bits/stdc++.h>
using namespace std;

struct lopHocPhan {
    char maLopHocPhan[50];
    char tenHocPhan[100];
    int soTinChi;
    long hocPhi;
};

bool soSanhHocPhi(lopHocPhan a, lopHocPhan b) {
    return a.hocPhi * a.soTinChi < b.hocPhi * b.soTinChi;
}

void in(lopHocPhan d[], int n) {
    for(int i = 0; i < n; i++) {
        cout <<left << setw(20) << d[i].maLopHocPhan << setw(30) << d[i].tenHocPhan 
             << setw(20) << d[i].soTinChi << setw(20) << d[i].hocPhi << endl;
    }
}

void inTieuDe() {
    cout <<left << setw(20) << "Ma Lop Hoc Phan" << setw(30) << "Ten Hoc Phan" 
         << setw(20) << "So Tin Chi" << setw(20) << "Hoc Phi" << endl;
}

struct ketqua1 {
    int count;
    int tongHocPhi;
    lopHocPhan ds[20];
};

ketqua1 giaiCau1(lopHocPhan ds[], int n, int p) {    
    ketqua1 kq = {};
    int tongPhi = 0;
    
    for (int i = 0; i < n; ++i) {
        int phi = ds[i].soTinChi * ds[i].hocPhi;
        if (tongPhi + phi <= p) {
            kq.ds[kq.count++] = ds[i];
            tongPhi += phi;
        }
    }
    
    kq.tongHocPhi = tongPhi;
    return kq;
}


struct ketqua2 {
    int count;
    lopHocPhan ds[20]; 
};

ketqua2 chonToiUu(lopHocPhan d[], int n, int p) {
	p = p/1000;
    int f[n+1][p+1] = {};
    
    for(int j = 0; j <= p; j++)
        f[0][j] = 0;
        
    for (int i = 1; i <= n; i++) {
        int phi = d[i-1].soTinChi * d[i-1].hocPhi/1000;
        for (int j = 0; j <= p; j++) {
            f[i][j] = f[i-1][j];
            if (j >= phi) {
                int temp = f[i-1][j - phi] + d[i-1].soTinChi;
                if (temp > f[i][j]) {
                    f[i][j] = temp;
                }
            }
        }
    }

    ketqua2 ans = {};
    int i = n, j = p;
    while (i > 0 && j >= 0) {
        int phi = d[i-1].soTinChi * d[i-1].hocPhi/1000;
        if (j >= phi && f[i][j] == f[i-1][j - phi] + d[i-1].soTinChi) {
            ans.ds[ans.count++] = d[i-1];
            j -= phi;
        }
        i--;
    }

    return ans;
}


int viTriXuatHienTrongXau(char p , char t[]){
	
	int n = strlen(t);
	for(int i = n -2 ; i >= 0 ; i --){
		if(t[i] == p ){
			return i ;
		}
	}
	return -1 ;
}


int timViTriXuatHien_BMH(char p[] , char t[]){
	
	int v = strlen(p);
	int i = v -1 ;
	while (i< strlen(t)){
		
		int k = v -1 ; 
		while( k > -1 && t[i] == p[k]){
			i--; 
			k--;
		}
		if(k< 0 ){
			return i + 1; 
		}
		int x = viTriXuatHienTrongXau(t[i] , p ); 
		if(x < 0 ){
			i += v ; 
		}
		else{
			i+= v - x - 1 ;
		}
	}
	return -1 ;
	
}

int main(int argc, char** argv) {
    int tongPhi = 0;
    int n = 6;
    int p = 4000000;
    lopHocPhan kq[6];
    lopHocPhan d[6] = {
        {"20241IT20061", "Java", 3, 475000},
        {"20242IT20061", "He Thong Co So Du Lieu", 4, 500000},
        {"20243IT20061", "Phan Tich Dac Ta", 3, 450000},
        {"20244IT20061", ".Net", 3, 460000},
        {"20245IT20061", "Python", 4, 490000},
        {"20246IT20061", "Tri Tue Nhan Tao", 3, 440000},
    };
    
    sort(d, d+n, soSanhHocPhi);
    ketqua1 kq1 = giaiCau1(d, n, p);
	cout << "So lop co the dang ky: " << kq1.count << endl;
	inTieuDe();
	in(kq1.ds, kq1.count);
	cout << "Tong chi phi: " << kq1.tongHocPhi << endl;

    
    ketqua2 kq2 = chonToiUu(d, n, p);
    cout << "\nKet qua toi uu:" << endl;
    inTieuDe();
    in(kq2.ds, kq2.count);
    
    char P[] = "lap trinh" ; 
	char T[] = "Ngon ngu lap trinh C++";
	
	int index =  timViTriXuatHien_BMH(P , T);
	
	if(index != -1){
		cout<<"vi tri dau tien xuat hien cuoi p("<<P<< ") trong xau t("<<T<<") la: "<<index <<endl ; 
	}
	else{
		cout<<"khong tim thay vi tri xuat hien cua p trong t \n";
	}
	

	
    return 0;
}
