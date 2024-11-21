#include <stdio.h>
#include <string.h>
#define max 50  // gioi han cac so thi sinh 

struct ThiSinh {
    int ma; // ma cua cac thi sinh thi 
    char ten[50]; // ten cua cac thi sinh thi 
    char ngaySinh[10]; // ngay sinh cua cac thi sinh  
    int diem1, diem2, diem3; // diem cua cac mon  
    int tongDiem; // tong diem cua cac môn 
};
int main() {
    int o; // So luong cac  thi sinh
    struct ThiSinh thiSinh[max];
    
    // Doc so luong thi sinh
    scanf("%d", &o);
    
    // Nhap thong tin cac  thi sinh
    for (int n = 0; n < o; n++) {
        thiSinh[n].ma = n + 1; // Ma thi sinh tu 1 d? lên 
        
        // Nhap ten
        getchar(); 
        fgets(thiSinh[n].ten, sizeof(thiSinh[n].ten), stdin);
        thiSinh[n].ten[strcspn(thiSinh[n].ten, "\n")] = '\0';
        
        // Nhap ngay sinh cua cac thi sinh 
        fgets(thiSinh[n].ngaySinh, sizeof(thiSinh[n].ngaySinh), stdin);
        thiSinh[n].ngaySinh[strcspn(thiSinh[n].ngaySinh, "\n")] = '\0'; 
        
        // Nhap diem cua 3 mon 
        scanf("%d %d %d", &thiSinh[n].diem1, &thiSinh[n].diem2, &thiSinh[n].diem3);
        
        // Tinh tong diem thi cua 3 mon 
        thiSinh[n].tongDiem = thiSinh[n].diem1 + thiSinh[n].diem2 + thiSinh[n].diem3;
    }
    // Tim thu khoa (thi sinh co tong diem 3 mon cao nhat)
    int maxDiem = -1;
    for (int n = 0; n < o; n++) {
        if (thiSinh[n].tongDiem > maxDiem) {
            maxDiem = thiSinh[n].tongDiem;
        }
    }
    // In ra tat ca thi sinh co tong diem 3 mon  cao nhat  
    for (int n = 0; n < o; n++) {
        if (thiSinh[n].tongDiem == maxDiem) {
            printf("%d %s %s %d\n", thiSinh[n].ma, thiSinh[n].ten, thiSinh[n].ngaySinh, thiSinh[n].tongDiem);
        }
    }
    
    return 0;
}
