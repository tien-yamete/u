#include <bits/stdc++.h>
using namespace std;
struct lopHocPhan{
	char maLop[50];
	char tenLop[100];
	int soTinChi;
	long hocPhi;
};
void inTieuDe(){
	cout<<left<<setw(20)<<"Ma Lop"<<setw(20)<<"Ten Lop"<<setw(20)<<"So Tin Chi"<<setw(20)<<"Hoc Phi/1 Tin"<<setw(20)<<"Hoc Phi"<<endl;
}
void inDL(lopHocPhan d[], int n){
	for(int i = 0; i<n; i++){
		cout<<left<<setw(20)<<d[i].maLop<<setw(20)<<d[i].tenLop<<setw(20)<<d[i].soTinChi<<setw(20)<<d[i].hocPhi<<setw(20)<<d[i].soTinChi*d[i].hocPhi<<endl;
	}
}
bool soSanh(lopHocPhan a, lopHocPhan b){
	return a.soTinChi*a.hocPhi<b.soTinChi*b.hocPhi;
}
struct ketQua1{
	int count;
	int tongHocPhi;
	lopHocPhan d[6];
};
ketQua1 a(lopHocPhan d[], int n, int p){
	ketQua1 kq = {};
	int tong = 0;
	for(int i =0; i<n; i++){
		if(tong+d[i].soTinChi*d[i].hocPhi <= p){
			kq.d[kq.count++] = d[i];
			kq.tongHocPhi += d[i].soTinChi*d[i].hocPhi;
			tong+= d[i].soTinChi*d[i].hocPhi;
		}
	}
	return kq;
}
struct ketQua2{
	int count;
	int tongHocPhi;
	lopHocPhan d[6];
};
ketQua2 b(lopHocPhan d[], int n, int m){
	m = m/1000;
	int f[n+1][m+1]={};
	for(int i = 0; i<=m;i++){
		f[0][i] = 0;
	}
	for(int i = 1; i<=n; i++){
		int phi = d[i-1].soTinChi*d[i-1].hocPhi/1000;
		for(int j = 0; j<=m; j++){
			f[i][j] = f[i-1][j];
			if(j>=phi){
				int temp = f[i-1][j-phi]+d[i-1].soTinChi;
				if(temp>f[i][j]){
					f[i][j] = temp;
				}
			}
		}
	}
	ketQua2 kq = {};
	int i = n;
	int j = m;
	while(i>0 && j>0){
		if(f[i][j] != f[i-1][j]){
			kq.d[kq.count++] = d[i-1];
			kq.tongHocPhi += d[i-1].soTinChi*d[i-1].hocPhi;
			j-= d[i-1].soTinChi*d[i-1].hocPhi/1000;
		}
		i--;
	}
	return kq;
}

int vtri(char p, char t[]){
	int d = strlen(t);
	for(int i = d-2; d>=0; i--){
		if(t[i] == p)
			return i;
	}
	return -1;
}
int bmh(char p[], char t[]){
	int v = strlen(p);
	int i = v- 1;
	while (i<strlen(t)){
		int k = v-1;
		while (k> -1 && t[i] == p[k]){
			i--;
			k--;
		}
		if(k<0)
			return i+1;
		int x = vtri(t[i], p);
		if(x<0)
			i+= v;
		else
			i+=v -x -1;
	}
	return -1;
}
int main(int argc, char** argv) {
	int n = 6;
	lopHocPhan d[6] = {
        {"20241IT20061", "Java", 3, 475000},
        {"20242IT20061", "He Thong Co So Du Lieu", 4, 500000},
        {"20243IT20061", "Phan Tich Dac Ta", 3, 450000},
        {"20244IT20061", ".Net", 3, 460000},
        {"20245IT20061", "Python", 4, 490000},
        {"20246IT20061", "Tri Tue Nhan Tao", 3, 440000},
    };
    sort(d, d+n, soSanh);
    int p = 4000000;
    ketQua1 kq = a(d, n, p);
    cout<<kq.tongHocPhi<<endl;
    cout<<kq.count<<endl;
    inTieuDe();
    inDL(kq.d, kq.count);
    
    int m = 6000000;
    ketQua2 kq2 = b(d, n, m);
    cout<<kq2.tongHocPhi<<endl;
    cout<<kq2.count<<endl;
    inTieuDe();
    inDL(kq2.d, kq2.count);
    char P[] = "lap trinh" ; 
	char T[] = "Ngon ngu lap trinh C++";
	
	int index =  bmh(P , T);
	cout<<index;
	return 0;
}
