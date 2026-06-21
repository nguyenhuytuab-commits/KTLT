#include <bits/stdc++.h>
using namespace std;

vector<string> wrap_text(string s, int width) {
    vector<string> lines;

    for(int i = 0; i < s.length(); i += width) {
        lines.push_back(s.substr(i, width));
    }

    return lines;
}

class Sach {
private:
    string tac_gia;
    string the_loai;
    string ma_sach;
    string ten_sach;
    int so_luong;
    int so_lan_muon; 

public:
    Sach() {
        tac_gia = "";
        the_loai = "";
        ma_sach = "";
        ten_sach = "";
        so_luong = 0;
        so_lan_muon = 0;
    }

    void nhap_thong_tin() {
        cout << "Nhap ten sach: ";
        getline(cin, ten_sach);
        cout << "Nhap ten tac gia: ";
        getline(cin, tac_gia);
        cout << "Nhap the loai: ";
        getline(cin, the_loai);
        while (true) {
            cout << "Nhap so luong: ";

            if (!(cin >> so_luong)) {
                cout << "Vui long nhap so nguyen!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (so_luong < 0) {
                cout << "So luong phai > 0!\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    string get_ten_sach()     { return ten_sach; }
    string get_ma_sach()      { return ma_sach; }
    string get_tac_gia()      { return tac_gia; }
    string get_the_loai()     { return the_loai; }
    int get_so_luong()        { return so_luong; }
    int get_so_lan_muon()     { return so_lan_muon; }

    void set_so_luong(int q)      { so_luong = q; }
    void set_ten_sach(string q)   { ten_sach = q; }
    void set_tac_gia(string q)    { tac_gia = q; }
    void set_the_loai(string q)   { the_loai = q; }
    void set_ma_sach(string q)    { ma_sach = q; }
    void set_so_lan_muon(int q)   { so_lan_muon = q; }

    void in_bang_tieu_de() {
        cout << left
             << setw(15) << "Ma sach"
             << setw(30) << "Ten sach"
             << setw(25) << "The loai"
             << setw(25) << "Tac gia"
             << setw(25) << "So luong"
             << '\n';
        cout << string(105, '-') << '\n';
    }

    void in_thong_tin() {
        vector<string> ten_lines = wrap_text(ten_sach, 25);
        vector<string> loai_lines = wrap_text(the_loai, 20);
        vector<string> tg_lines = wrap_text(tac_gia, 20);

        int rows = max({
            (int)ten_lines.size(),
            (int)loai_lines.size(),
            (int)tg_lines.size()
        });

        for(int i = 0; i < rows; i++) {
            cout << left;

            if(i == 0)
                cout << setw(15) << ma_sach;
            else
                cout << setw(15) << "";

            cout << setw(30)
                 << (i < ten_lines.size() ? ten_lines[i] : "");

            cout << setw(25)
                 << (i < loai_lines.size() ? loai_lines[i] : "");

            cout << setw(25)
                 << (i < tg_lines.size() ? tg_lines[i] : "");

            if(i == 0)
                cout << setw(3) << so_luong;

            cout << '\n';
        }
    }

    void tang_so_lan_muon() {
        so_lan_muon++;
    }

    bool kiem_tra_tinh_trang() {
        return so_luong > 0;
    }
};

class BanDoc {
private:
    string ma_so;
    string ten_ban_doc;
    int vai_tro; 

public:
    void nhap_thong_tin() {
        cout << "Nhap ten: ";
        getline(cin, ten_ban_doc);
        cout << "Ban la:\n";
        cout << "1. Sinh vien\n";
        cout << "2. Giang vien\n";
        cout << "Xin moi nhap lua chon: ";
        cin >> vai_tro;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string get_ma_so()       { return ma_so; }
    string get_ten_ban_doc() { return ten_ban_doc; }
    int get_vai_tro()        { return vai_tro; }

    void set_ma_so(string x)       { ma_so = x; }   
    void set_ten_ban_doc(string x) { ten_ban_doc = x; }
    void set_vai_tro(int x)        { vai_tro = x; }

    string in_vai_tro(){
        if(vai_tro == 1){
            return "Sinh vien";
        }
        return "Giang vien";
    }

    void in_bang_tieu_de(){
        cout << setw(10) << "Ma so" << setw(5) << "|";
        cout << setw(20) << "Ten" << setw(5) << "|";
        cout << setw(20) << "Vai tro";
        cout << '\n';
        cout << string(55, '-') << '\n';
    }

    void in_thong_tin() {
        cout << left;
        cout << setw(10) << ma_so << setw(5) << "|" ;
        cout << setw(20) << ten_ban_doc << setw(5) << "|";
        cout << setw(20) << in_vai_tro();
        cout << '\n';
    }
    
    bool kiem_tra_gioi_han_muon(int count) {
        // Sinh vien muon toi da 3 quyen
        if(vai_tro == 1) {
            return count <= 3;        
        }
        // Giang vien muon toi da 5 quyen
        return count <= 5;
    }
};

class PhieuMuon {
private:
    string ma_nguoi_doc;
    string ma_sach;
    int so_luong_muon;
    time_t ngay_muon;
    time_t han_tra;
    time_t ngay_tra;
    bool da_tra_sach;

public:
    PhieuMuon() {
        ngay_muon = 0;
        han_tra = 0;
        ngay_tra = 0;
        da_tra_sach = false;
        so_luong_muon = 0;
    }

    double tinh_tien_phat() {
         //Ngay ket thuc chon thoi diem hien tai neu chua tra hoac thoi diem da tra sach truoc thoi han
        time_t ngay_ket_thuc = da_tra_sach ? ngay_tra : time(nullptr);
       
        int qua_han = (ngay_ket_thuc - han_tra) / (60*1);// nhom de thoi gian han la 1 phut de phu hop voi dieu kien thuc hien testcase 27 cua bao cao
        if(qua_han <= 0) return 0;
        return qua_han * 5000 * so_luong_muon;
    }

    string get_ma_sach()        { return ma_sach; }
    string get_ma_nguoi_doc()   { return ma_nguoi_doc; }
    int get_so_luong_muon()     { return so_luong_muon; }
    bool get_da_tra_sach()      { return da_tra_sach; }
    time_t get_han_tra()        { return han_tra; }
    time_t get_ngay_muon()      { return ngay_muon; }
    time_t get_ngay_tra()       { return ngay_tra; }

    void set_ma_sach(string q)        { ma_sach = q; }
    void set_ma_nguoi_doc(string q)   { ma_nguoi_doc = q; }
    void set_ngay_muon(time_t q)      { ngay_muon = q; }
    void set_han_tra(time_t q)        { han_tra = q; }
    void set_ngay_tra(time_t q)       { ngay_tra = q; }
    void set_so_luong_muon(int q)     { so_luong_muon = q; }
    void set_da_tra_sach(bool q)      { da_tra_sach = q; }
};

class QuanLyThuVien {
private:
    vector<Sach> danh_sach_sach;
    vector<BanDoc> danh_sach_ban_doc;
    vector<PhieuMuon> danh_sach_phieu;

public:
    void them_sach() {
        Sach b;
        string masach;
        cout << "Nhap ma sach: ";
        getline(cin, masach);
        for(auto &x : danh_sach_sach) {
            if(x.get_ma_sach() == masach) {
                cout << "Ma sach da ton tai\n";
                return; 
            }
        }
        b.set_ma_sach(masach);
        
        b.nhap_thong_tin();
        cout << string(40, '-') << "\n";
        cout << "Them thanh cong\n";
        b.in_bang_tieu_de();
        danh_sach_sach.push_back(b);
        for(auto &x : danh_sach_sach){
            x.in_thong_tin();
        }
    }

    void xoa_sach() {
        cout << "Nhap ma sach muon xoa: ";
        string id;
        getline(cin, id);
        for(auto it = danh_sach_sach.begin(); it != danh_sach_sach.end(); it++) {
            if(it->get_ma_sach() == id) {
                // Khong cho phep xoa sach dang co nguoi muon
                for(auto &p : danh_sach_phieu) {
                    if(p.get_ma_sach() == id && !p.get_da_tra_sach()) {
                        cout << "Khong the xoa! Sach nay dang co nguoi muon.\n";
                        return;
                    }
                }
                cout << "Xoa thanh cong\n";
                danh_sach_sach.erase(it);
                return;
            }
        }
        cout << "Ma sach khong ton tai\n";
    }

    void sua_sach() {
        string ma;
        cout << "Nhap ma sach can sua: ";
        getline(cin, ma);
        for(auto &x : danh_sach_sach) {
            if(x.get_ma_sach() == ma) {
                cout << "Chon thuoc tinh muon sua:\n";
                cout << "1. Ten sach\n";
                cout << "2. Tac gia sach\n";
                cout << "3. The loai\n";
                cout << "4. So Luong\n";
                cout << "Vui long lua chon (1-4): ";
                char choice;
                cin >> choice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                int soluong;
                string input_str;

                if(choice == '4') {
                    cout << "Nhap so luong muon sua: ";
                    cin >> soluong;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    x.set_so_luong(soluong);
                    cout << "Sua thanh cong!\n";
                } else if(choice == '1') {
                    cout << "Nhap ten sach muon sua: ";
                    getline(cin, input_str);
                    x.set_ten_sach(input_str);
                    cout << "Sua thanh cong!\n";
                } else if(choice == '2') {
                    cout << "Nhap ten tac gia muon sua: ";
                    getline(cin, input_str);
                    x.set_tac_gia(input_str);
                    cout << "Sua thanh cong!\n";
                } else if(choice == '3') {
                    cout << "Nhap the loai muon sua: ";
                    getline(cin, input_str);
                    x.set_the_loai(input_str); 
                    cout << "Sua thanh cong!\n";
                } else {
                    cout << "Lua chon khong hop le\n";
                }
                return;
            }
        }
        cout << "Ma sach khong ton tai!\n";
    }

    void them_ban_doc() {
        BanDoc r;
        string ms;
        cout << "Nhap ma ban doc: ";
        getline(cin, ms);
        for(auto &x : danh_sach_ban_doc) {
            if(x.get_ma_so() == ms) {
                cout << "Nguoi dung da ton tai\n";
                return;
            }
        }
        r.set_ma_so(ms);
        r.nhap_thong_tin();
        danh_sach_ban_doc.push_back(r);
        cout << "Them ban doc thanh cong!\n";
        r.in_bang_tieu_de();
        for(auto &x : danh_sach_ban_doc){
            x.in_thong_tin();
        }
    }

    void xoa_ban_doc() {
        cout << "Nhap ma nguoi dung muon xoa: ";
        string id;
        getline(cin, id);
        for(auto it = danh_sach_ban_doc.begin(); it != danh_sach_ban_doc.end(); it++) {
            if(it->get_ma_so() == id) {
                for(auto &p : danh_sach_phieu) {
                    if(p.get_ma_nguoi_doc() == id && !p.get_da_tra_sach()) {
                        // Khong the xoa khi ban doc con sach chua tra
                        cout << "Khong the xoa! Ban doc nay dang muon sach chua tra.\n";
                        return;
                    }
                }
                cout << "Da xoa thanh cong\n";
                danh_sach_ban_doc.erase(it);
                return;
            }
        }
        cout << "Nguoi dung khong ton tai!\n";
    }

    void muon_sach() {
        cout << "Nhap ma nguoi doc: ";
        string ma;
        getline(cin, ma);
        // TIm ban doc theo ma so
        BanDoc* r = nullptr;
        for(auto &x : danh_sach_ban_doc) {
            if(x.get_ma_so() == ma) {
                r = &x;
                break;
            }
        }
        if(r == nullptr) {
            cout << "Nguoi doc khong ton tai\n";
            return;
        }
        cout << "Thong tin nguoi doc\n";
        r->in_thong_tin();
        // Kiem tra nguoi doc co sach qua han khong
        for(auto &t : danh_sach_phieu) {
            if(t.get_ma_nguoi_doc() == ma && !t.get_da_tra_sach() && time(nullptr) > t.get_han_tra()) {
                cout << "Ban doc dang co sach qua han! Khong the muon tiep.\n";
                return;
            }
        }

        cout << "Nhap ma sach: ";
        string masach;
        getline(cin, masach);
        // Tim sach theo ma sach
        Sach* b = nullptr;
        for(auto &x : danh_sach_sach) {
            if(x.get_ma_sach() == masach) {
                b = &x;
                break;
            }
        }
        if(b == nullptr) {
            cout << "Khong tim thay sach\n";
            return;
        }
        if(b->get_so_luong() <= 0) {
            cout << "Sach da het\n";
            return;
        }

        int dem;
        string vaitro;
        if(r->get_vai_tro() == 1){
            vaitro = "Sinh vien";
        }else{
            vaitro = "Giang vien";
        }
        while(true) {
            cout << "Sinh vien toi da 3 || Giang vien toi da 5\n";
            cout << "Ban doc la: "<< vaitro << '\n';
            cout << "Nhap so luong muon muon: ";
            cin >> dem;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Kiem tra so luong muon co qua gioi han vai tro
            if(r->kiem_tra_gioi_han_muon(dem)) {
                // Kiem tra con du so luong sach
                if(dem > b->get_so_luong()) {
                    cout << "Qua so luong dang co trong thu vien!\n";
                } else {
                    break;
                }
            } else {
                cout << "Ban khong the muon qua so sach cho phep theo vai tro!\n";
                return;
            }
        }

        PhieuMuon t;
        t.set_so_luong_muon(dem);
        t.set_ma_nguoi_doc(ma);
        t.set_ma_sach(masach);
        t.set_ngay_muon(time(nullptr));
        t.set_han_tra(time(nullptr) + 60*1); 
        t.set_da_tra_sach(false);
        danh_sach_phieu.push_back(t);
        // Giam so luong sach trong kho
        b->set_so_luong(b->get_so_luong() - dem);
        for(int i = 0; i < dem; i++) b->tang_so_lan_muon();
        // Tang so lan duoc muon cua sach
        cout << "Muon sach thanh cong!\nSo luong muon: " << dem << "\n";
    }

    void tra_sach() {
        string maNguoiDoc;
        cout << "Nhap ma nguoi doc: ";
        getline(cin, maNguoiDoc);
        // Luu danh sach cac phieu muon chua tra
        vector<int> dsPhieu;
        cout << "\nDanh sach phieu muon chua tra:\n";
        for(size_t i = 0; i < danh_sach_phieu.size(); i++) {
            if(danh_sach_phieu[i].get_ma_nguoi_doc() == maNguoiDoc && !danh_sach_phieu[i].get_da_tra_sach()) {
                dsPhieu.push_back(i);
                cout << dsPhieu.size() << ". Ma sach: " << danh_sach_phieu[i].get_ma_sach()
                     << " | So luong con muon: " << danh_sach_phieu[i].get_so_luong_muon() << '\n';
            }
        }
        if(dsPhieu.empty()) {
            cout << "Khong co phieu muon nao chua tra!\n";
            return;
        }

        int luaChon;
        cout << "Chon phieu muon: ";
        cin >> luaChon;
        if(luaChon < 1 || luaChon > (int)dsPhieu.size()) {
            cout << "Lua chon khong hop le!\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        PhieuMuon &t = danh_sach_phieu[dsPhieu[luaChon - 1]];
        int soLuongTra;
        cout << "Nhap so luong tra: ";
        cin >> soLuongTra;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(soLuongTra <= 0 || soLuongTra > t.get_so_luong_muon()) {
            cout << "So luong tra khong hop le!\n";
            return;
        }

        double tienPhat = t.tinh_tien_phat();
        // Tra lai so luong sach muon
        for(auto &x : danh_sach_sach) {
            if(x.get_ma_sach() == t.get_ma_sach()) {
                x.set_so_luong(x.get_so_luong() + soLuongTra);
                break;
            }
        }
        // Giam so luong con dang muon trong phieu
        t.set_so_luong_muon(t.get_so_luong_muon() - soLuongTra);
        // Neu da tra het thi dong phieu muo
        if(t.get_so_luong_muon() == 0) {
            t.set_ngay_tra(time(nullptr));
            t.set_da_tra_sach(true);
        }

        cout << "\nTra sach thanh cong!\n";
        if(tienPhat > 0) {
            cout << "Tien phat: " << tienPhat << " VND\n";
        }
    }

    void tim_sach() {
        cout << "===== PHAN MEM TIM SACH =====\n";
        cout << "1. Tim theo ten sach\n";
        cout << "2. Tim theo ma sach\n";
        cout << "3. Tim theo the loai\n";
        cout << "4. Tim theo ten tac gia\n";
        cout << "Vui long nhap lua chon: ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string name;
        cout << "Vui long nhap thong tin can tim: ";
        getline(cin, name);
        // Danh dau co tim thay sach hay khong
        bool found = false;
        Sach helper; 

        for(auto &x : danh_sach_sach) {
            bool match = false;
            if(choice == '1' && x.get_ten_sach() == name) match = true;
            else if(choice == '2' && x.get_ma_sach() == name) match = true;
            else if(choice == '3' && x.get_the_loai() == name) match = true;
            else if(choice == '4' && x.get_tac_gia() == name) match = true;

            if(match) {
                if(!found) {
                    helper.in_bang_tieu_de(); 
                    found = true;
                }
                x.in_thong_tin();
            }
        }

        if(!found) {
            cout << "Sach khong ton tai!\n";
        }
    }
    // Hien thi danh sach cac phieu muon chua tra
    void sach_dang_muon() {
        cout << "Nhung cuon sach dang duoc muon: \n";
        Sach b;
        b.in_bang_tieu_de();
        for(auto &x : danh_sach_phieu) {
            if(!x.get_da_tra_sach()) {
                for(auto &y : danh_sach_sach) {
                    if(x.get_ma_sach() == y.get_ma_sach()) {
                        y.in_thong_tin();
                    }
                }
            }
        }
    }
    // Hien thi danh sach sach qua han
    void sach_qua_han() {
        cout << "Nhung cuon sach dang qua han tra: \n";
        Sach b;
        b.in_bang_tieu_de();
        for(auto &x : danh_sach_phieu) {
            if(x.tinh_tien_phat() > 0) {
                for(auto &y : danh_sach_sach) {
                    if(y.get_ma_sach() == x.get_ma_sach()) {
                        y.in_thong_tin();
                    }
                }
            }
        }
    }
    // Danh dau sach da duoc chon vao top
    void top_5_cuon_sach() {
        vector<bool> muon(danh_sach_sach.size(), false);
        // TIm lan luot 5 cuon duoc muon nhieu nhat
        cout << "Top 5 sach duoc muon nhieu nhat: \n";
        for(int k = 0; k < 5; k++) {
            int maxdem = -1;
            int maxin = -1;
            for(size_t i = 0; i < danh_sach_sach.size(); i++) {
                if(!muon[i] && danh_sach_sach[i].get_so_lan_muon() > maxdem) {
                    maxdem = danh_sach_sach[i].get_so_lan_muon();
                    maxin = i;
                }
            }
            if(maxin == -1) {
                break;
            }
            muon[maxin] = true;
            cout << k + 1 << ". ";
            danh_sach_sach[maxin].in_thong_tin();
            cout << "   -> So lan muon: " << danh_sach_sach[maxin].get_so_lan_muon() << '\n';
        }
    }

    bool save_data(){
        // Luu du lieu sach
        ofstream foutBook("sach.txt");

        if(!foutBook.is_open())
            return false;

        foutBook << danh_sach_sach.size() << '\n';
        // Ghi tung thuoc tinh theo tung dong
        for(auto &x : danh_sach_sach){
            foutBook << x.get_ma_sach() << '\n';
            foutBook << x.get_ten_sach() << '\n';
            foutBook << x.get_so_luong() << '\n';
            foutBook << x.get_so_lan_muon() << '\n';
            foutBook << x.get_tac_gia() << '\n';
            foutBook << x.get_the_loai() << '\n';
        }   

        foutBook.close();
        // Luu du lieu ban doc
        ofstream foutReader("bandoc.txt");

        if(!foutReader.is_open())
            return false;

        foutReader << danh_sach_ban_doc.size() << '\n';
        // Luu du lieu phieu muon
        for(auto &x : danh_sach_ban_doc){
            foutReader << x.get_ma_so() << '\n';
            foutReader << x.get_ten_ban_doc() << '\n';
            foutReader << x.get_vai_tro() << '\n';
        }

        foutReader.close();
        
        ofstream foutBorrow("phieumuon.txt");

        if(!foutBorrow.is_open())
        return false;

        foutBorrow << danh_sach_phieu.size() << '\n';

        for(auto &x : danh_sach_phieu){
            foutBorrow << x.get_ma_nguoi_doc() << '\n';
            foutBorrow << x.get_ma_sach() << '\n';
            foutBorrow << x.get_so_luong_muon() << '\n';
            foutBorrow << x.get_ngay_muon() << '\n';
            foutBorrow << x.get_han_tra() << '\n';
            foutBorrow << x.get_ngay_tra() << '\n';
            foutBorrow << x.get_da_tra_sach() << '\n';
        }

        foutBorrow.close();
        
        return true;
    }

    bool load_data(){
        // Xoa du lieu truoc khi tai du lieu tu file
        danh_sach_sach.clear();
        danh_sach_ban_doc.clear();
        danh_sach_phieu.clear();

        ifstream finBook("sach.txt");

        if(!finBook.is_open())
            return false;

        int n;
        finBook >> n;
        finBook.ignore();
        // Doc danh sach tu file
        for(int i=0;i<n;i++){
            Sach s;
            string ma;
            string ten;
            string tacgia;
            string theloai;
            int soluong;
            int solanmuon;

            getline(finBook, ma);
            getline(finBook, ten);
            getline(finBook, tacgia);
            getline(finBook, theloai);

            finBook >> soluong;
            finBook >> solanmuon;
            finBook.ignore();

            s.set_ma_sach(ma);
            s.set_ten_sach(ten);
            s.set_tac_gia(tacgia);
            s.set_the_loai(theloai);
            s.set_so_luong(soluong);
            s.set_so_lan_muon(solanmuon);

            danh_sach_sach.push_back(s);
        }

        finBook.close();

        ifstream finReader("bandoc.txt");

        if(!finReader.is_open())
            return false;

        int m;
        finReader >> m;
        finReader.ignore();
        // Doc danh sach ban doc tu file
        for(int i=0;i<m;i++){
            BanDoc r;
            string ms;
            string ten;
            int vaitro;

            getline(finReader, ms);
            getline(finReader, ten);

            finReader >> vaitro;
            finReader.ignore();

            r.set_ma_so(ms);
            r.set_ten_ban_doc(ten);
            r.set_vai_tro(vaitro);

            danh_sach_ban_doc.push_back(r);
        }

        finReader.close();

        ifstream finBorrow("phieumuon.txt");

        if(finBorrow.is_open()){
            int p;
            finBorrow >> p;
            finBorrow.ignore();
            // Doc danh sach phieu muon tu file
            for(int i=0;i<p;i++){
                PhieuMuon pm;
                string maNguoiDoc;
                string maSach;
                int soLuong;
                long long ngayMuon;
                long long hanTra;
                long long ngayTra;
                bool daTra;

                getline(finBorrow, maNguoiDoc);
                getline(finBorrow, maSach);

                finBorrow >> soLuong;
                finBorrow >> ngayMuon;
                finBorrow >> hanTra;
                finBorrow >> ngayTra;
                finBorrow >> daTra;
                finBorrow.ignore();

                pm.set_ma_nguoi_doc(maNguoiDoc);
                pm.set_ma_sach(maSach);
                pm.set_so_luong_muon(soLuong);
                pm.set_ngay_muon((time_t)ngayMuon);
                pm.set_han_tra((time_t)hanTra);
                pm.set_ngay_tra((time_t)ngayTra);
                pm.set_da_tra_sach(daTra);

                danh_sach_phieu.push_back(pm);
            }
            finBorrow.close();
        }
        return true;
    }
};
//Hien thi giao dien
class Menu {
private:
    QuanLyThuVien ql;

public:
    void run() {
        while (true) {
            cout << "\n          ========== QUAN LY THU VIEN ==========\n";
            cout << string(62, '-') << '\n';
            cout << left;
            cout << setw(30) << "1. Them sach"                  << setw(5) << "|" << setw(25) << "8. Tim sach" << '\n';
            cout << setw(30) << "2. Xoa sach"                  << setw(5) << "|" << setw(25) << "9. Danh sach sach dang muon" << '\n';
            cout << setw(30) << "3. Sua thong tin sach"        << setw(5) << "|" << setw(25) << "10. Danh sach sach qua han" << '\n';
            cout << setw(30) << "4. Them nguoi doc"            << setw(5) << "|" << setw(25) << "11. Luu du lieu"  << '\n';
            cout << setw(30) << "5. Xoa nguoi doc"            << setw(5) << "|" << setw(25) << "12. Tai du lieu" << '\n';
            cout << setw(30) << "6. Muon sach"                << setw(5) << "|" << setw(25) << "13. Top 5 cuon sach duoc muon" << '\n';
            cout << setw(30) << "7. Tra sach"                  << setw(5) << "|" << setw(25) << "0. Thoat" << '\n';
            cout << string(62, '-') << '\n';
            
            int choice;
            cout << "Nhap lua chon (0-13): ";
            if (!(cin >> choice)) {
                cout << "Du lieu nhap khong hop le!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (choice) {
                case 1:  ql.them_sach(); break;
                case 2:  ql.xoa_sach(); break;
                case 3:  ql.sua_sach(); break;
                case 4:  ql.them_ban_doc(); break;
                case 5:  ql.xoa_ban_doc(); break;
                case 6:  ql.muon_sach(); break;
                case 7:  ql.tra_sach(); break;
                case 8:  ql.tim_sach(); break;
                case 9:  ql.sach_dang_muon(); break;
                case 10: ql.sach_qua_han(); break;
                case 11: 
                    if (ql.save_data()) cout << "Luu du lieu thanh cong!\n";
                    else cout << "Luu du lieu that bai!\n";
                    break;
                case 12: 
                    if (ql.load_data()) cout << "Tai du lieu thanh cong!\n";
                    else cout << "Tai du lieu that bai!\n";
                    break;
                case 13: ql.top_5_cuon_sach(); break;
                case 0:  cout << "Tam biet!\n"; return;
                default: cout << "Lua chon khong hop le!\n";
            }
        }
    }
};

int main() {
	//Khoi tao thuc the quan ly menu
    Menu menu;
    //Kich hoat luong chay va vong lap
    menu.run();
    return 0;
}
