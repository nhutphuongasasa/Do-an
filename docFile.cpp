#include "docFile.h" 
string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
void docDuLieuTuCSVsangMang( vector<SV> &danhSachSV, string filePath,unordered_set<string> &daMaSV){
    
    
    ifstream file(filePath);
    if (file.is_open())
    {
        string line;
        // Bỏ qua dòng đầu tiên (tiêu đề cột)
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            vector<string> fields;

            // Tách các trường dữ liệu
            while (getline(ss, token, ','))
            {
                fields.push_back(token);
            }

            // Kiểm tra số lượng trường dữ liệu
            if (fields.size() == 6)
            {
                SV sv;
                sv.id = fields[1];
                
                sv.id = toUpperCase(sv.id);
                sv.ho = fields[2];
                sv.name = fields[3];
                sv.className = fields[4];
                sv.GPA = stod(fields[5]);
                
                if (daMaSV.find(sv.id)!= daMaSV.end()) //kiem tra ma sinh vien co bi trung hay ko  
                {
                    cout << "Loi: Ma sinh vien '" << sv.id << "' bi trung!" << endl;
                }
                else
                {
                    daMaSV.insert(sv.id);
                    danhSachSV.push_back(sv);
                }
            }
            else
            {
                cout << "Loi: Dong du lieu khong hop le: " << line << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "Khong the mo file: " << filePath << endl;
    }
}

void docDuLieuTuCSVsangDon( singleLinkedList *&head, string filePath,unordered_set<string> &daMaSV){
   
    ifstream file(filePath);
    if (file.is_open())
    {
        string line;
        // Bỏ qua dòng đầu tiên (tiêu đề cột)
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            vector<string> fields;

            // Tách các trường dữ liệu
            while (getline(ss, token, ','))
            {
                fields.push_back(token);
            }

            // Kiểm tra số lượng trường dữ liệu
            if (fields.size() == 6)
            {
                SV sv;
                sv.id = fields[1];
                
                sv.id = toUpperCase(sv.id);
                sv.ho = fields[2];
                sv.name = fields[3];
                sv.className = fields[4];
                sv.GPA = stod(fields[5]);
                
                if (daMaSV.find(sv.id)!= daMaSV.end()) //kiem tra ma sinh vien co bi trung hay ko  
                {
                    cout << "Loi: Ma sinh vien '" << sv.id << "' bi trung!" << endl;
                }
                else
                {
                    daMaSV.insert(sv.id);
                    pushBackDon(head,sv);
                }
            }
            else
            {
                cout << "Loi: Dong du lieu khong hop le: " << line << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "Khong the mo file: " << filePath << endl;
    }

}
void docDuLieuTuCSVsangKep( doubleLinkedList *&head, string filePath,unordered_set<string> &daMaSV){
   
    ifstream file(filePath);
    if (file.is_open())
    {
        string line;
        // Bỏ qua dòng đầu tiên (tiêu đề cột)
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            vector<string> fields;

            // Tách các trường dữ liệu
            while (getline(ss, token, ','))
            {
                fields.push_back(token);
            }

            // Kiểm tra số lượng trường dữ liệu
            if (fields.size() == 6)
            {
                SV sv;
                sv.id = fields[1];
                
                sv.id = toUpperCase(sv.id);
                sv.ho = fields[2];
                sv.name = fields[3];
                sv.className = fields[4];
                sv.GPA = stod(fields[5]);
                
                if (daMaSV.find(sv.id)!= daMaSV.end()) //kiem tra ma sinh vien co bi trung hay ko  
                {
                    cout << "Loi: Ma sinh vien '" << sv.id << "' bi trung!" << endl;
                }
                else
                {
                    daMaSV.insert(sv.id);
                    pushBackDoi(head,sv);
                }
            }
            else
            {
                cout << "Loi: Dong du lieu khong hop le: " << line << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "Khong the mo file: " << filePath << endl;
    }

}

void docDuLieuTuCSVsangVong(circleLinkedList *&head, string filePath,unordered_set<string> &daMaSV){

    ifstream file(filePath);
    if (file.is_open())
    {
        string line;
        // Bỏ qua dòng đầu tiên (tiêu đề cột)
        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            vector<string> fields;

            // Tách các trường dữ liệu
            while (getline(ss, token, ','))
            {
                fields.push_back(token);
            }

            // Kiểm tra số lượng trường dữ liệu
            if (fields.size() == 6)
            {
                SV sv;
                sv.id = fields[1];
                
                sv.id = toUpperCase(sv.id);
                sv.ho = fields[2];
                sv.name = fields[3];
                sv.className = fields[4];
                sv.GPA = stod(fields[5]);
                
                if (daMaSV.find(sv.id)!= daMaSV.end()) //kiem tra ma sinh vien co bi trung hay ko  
                {
                    cout << "Loi: Ma sinh vien '" << sv.id << "' bi trung!" << endl;
                }
                else
                {
                    daMaSV.insert(sv.id);
                    pushBackVong(head,sv);
                }
            }
            else
            {
                cout << "Loi: Dong du lieu khong hop le: " << line << endl;
            }
        }
        file.close();
    }
    else
    {
        cout << "Khong the mo file: " << filePath << endl;
    }
}
