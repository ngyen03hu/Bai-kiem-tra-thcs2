#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// ham chua hoa ho ten 
string chuanHoa(string hoTen) {
    string result = "";
    bool capitalize = true; //  kiem tra co can viet hoa ky tu tiep theo hay khong 

    for (size_t i = 0; i < hoTen.length(); ++i) {
        char c = hoTen[i];
        if (isspace(c)) {
            if (!result.empty() && result[result.length() - 1] != ' ') {
                result += ' '; // them mot dau cach neu truoc do khong phai trang 
            }
            capitalize = true; // bat dau mot tu moi 
        } else {
            if (capitalize) {
                result += toupper(c); // viet hoa chu cai dau 
                capitalize = false;
            } else {
                result += tolower(c); // viet thuong cac chu cai khac 
            }
        }
    }

    // xao khoang trang thua o cuoi chuoi (neu co) 
    if (!result.empty() && result[result.length() - 1] == ' ') {
        result.erase(result.length() - 1);
    }

    return result;
}

int main() {
    int t;
    cout << " nhap ten  : ";
    cin >> t;
    cin.ignore(); // bo ky tu xuong dong sau khi nhap so 
	 
    while (t--) {
        string hoTen;
        cout << " nhap ho  ten: ";
        getline(cin, hoTen);

        // in ra ho ten da chuan hoa 
        cout << chuanHoa(hoTen) << endl;
    }

    return 0;
}

