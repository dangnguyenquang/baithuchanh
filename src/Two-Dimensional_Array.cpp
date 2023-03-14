#include <iostream>
#include <stdio.h>
using namespace std;

#define maxc 100

int MAX(int a[][maxc], int m, int n){
    int max = a[0][0];
    for (int i = 0; i < m; i++){
        for (int j = 1; j < n; j++){
            if (a[i][j] > max){
                max = a[i][j];
            }        
        }
    }
    return max;
}

int MIN(int a[][maxc], int m, int n){
    int min = a[0][0];
    for (int i = 0; i < m; i++){
        for (int j = 1; j < n; j++){
            if (a[i][j] < min){
                min = a[i][j];
            }        
        }
    }
    return min;
}

int laSNT(int a){
    if (a == 2) return 0;
    else {
        for (int i = 2; i < a; i++){
            if (a%i == 0) return 1;
        }
    }
    return 0;
}

int laSCP(int a){
    int i = 1;
    while(i*i <= a){
        if (i*i == a) return 0;
        else i++;
    }
    return 1;
}

void inraSNT(int a[][maxc], int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (laSNT(a[i][j]) == 0) cout << a[i][j] << " ";
        }
    }
    cout << endl;
}

void inraSCP(int a[][maxc], int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (laSCP(a[i][j]) == 0) cout << a[i][j] << " ";
        }
    }
    cout << endl;
}

int doixung(int a[][maxc], int m, int n){
    for (int i = 0; i < m; i++){
        for(int j = 0; j <= n/2; j++){
            if (a[i][j] != a[i][(n-1)-j]) return 1;
        }
    }
    return 0;
}

int doixungquaduongcheochinh(int a[][maxc], int m, int n){
    for (int i = 0; i < m; i++){
        for(int j = 0; j <= n; j++){
            if (a[i][j] != a[j][i]) return 1;
        }
    }
    return 0;
}

int matrandonvi(int a[][maxc], int m, int n){
    for (int i = 0; i < m; i++){
        for(int j = 0; j <= n; j++){
            if (i == j && a[i][j] != 1) return 1;
            else if (i != j && a[i][j] != 0) return 1;
        }
    }
    return 0;   
}

void nhapmang(int a[][maxc], int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << "Nhap phan tu a [" << i << "][" << j << "]: "; cin >> a[i][j];
        }
    }
}

int main(){
    int a[100][maxc], n, luachon = 99, m;
    while(luachon != 0){
        cout << "Co tiep tuc thuc hien chuong trinh khong?(Co: 1, Khong: 0): "; cin >> luachon;
        if (luachon == 1) luachon = 99;
        else return 0;
        cout << "Nhap so dong, so cot cua mang " << endl;
        cin >> m; cin >> n;
        nhapmang(a, m, n);
        cout << "--------------- MENU --------------" << endl;
        cout << "Tim phan tu lon nhat cua mang (chon 1): " << endl;
        cout << "Tim phan tu nho nhat cua mang (chon 2): " << endl;
        cout << "In ra so nguyen to co trong mang (chon 3): " << endl;
        cout << "In ra so chinh phuong co trong mang (chon 4): " << endl;
        cout << "Xet su doi xung cua mang (chon 5): " << endl;
        cout << "Kiem tra su doi xung qua duong cheo chinh (chon 6): " << endl;
        cout << "Kiem tra ma tran don vi (chon 7): " << endl;
        cout << "Nhap lua chon: "; cin >> luachon;
        if (luachon == 1){
            cout << "Phan tu lon nhat trong mang la: " << MAX(a, m, n) << endl;
        } else if (luachon == 2){
            cout << "Phan tu nho nhat trong mang la: " << MIN(a, m, n) << endl;
        } else if (luachon == 3){
            cout << "So nguyen to co trong mang la: ";
            inraSNT(a, m, n);
        } else if (luachon == 4){
            cout << "So chinh phuong co trong mang la: ";
            inraSCP(a, m, n);
        } else if (luachon == 5){
            if (doixung(a, m, n) == 0) cout << "Mang nhap vao doi xung" << endl;
            else cout << "Mang nhap vao khong doi xung" << endl;
        } else if (luachon == 6) {
            while (n != m){
                cout << "Ma tran nhap vao phai la ma tran vuong, nhap lai: " << endl;
                cout << "Nhap so dong, so cot cua mang " << endl;
                cin >> m; cin >> n;
                nhapmang(a, m, n);        
            }
            if (doixungquaduongcheochinh(a, m, n) == 0) cout << "Mang nhap vao doi xung qua duong cheo chinh" << endl;
            else cout << "Mang nhap vao khong doi xung qua duong cheo chinh" << endl;        
        } else if (luachon == 7){
            while (n != m){
                cout << "Ma tran nhap vao phai la ma tran vuong, nhap lai: " << endl;
                cout << "Nhap so dong, so cot cua mang " << endl;
                cin >> m; cin >> n;
                nhapmang(a, m, n);        
            }
            if (matrandonvi(a, m, n) == 0) cout << "Mang nhap vao la ma tran don vi" << endl;
            else cout << "Mang nhap vao khong phai la ma tran don vi" << endl;  
        }
    }    
    return 0; 
}
