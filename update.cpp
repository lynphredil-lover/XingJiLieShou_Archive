#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string get_file_path() {
    string file_path;
    int chac_num, flag=0;
    cout << "Choose a character: 1.烬行 2.铃弗瑞迪尔 3.斯沃德麦伦 4.谶 5.度漪 6.塔拉撒里昂 7.赛博恩 8.无可奉告哥" << endl;
    while (flag == 0)
    {    
        cout << "Enter the number: ";
        cin >> chac_num;
        switch(chac_num) {
            case 1:
                file_path = "html/JinXing.html";
                flag = 1;
                break;
            case 2:
                file_path = "html/LingLan.html";
                flag = 1;
                break;
            case 3:
                file_path = "html/SwordMelon.html";
                flag = 1;
                break;
            case 4:
                file_path = "html/Chen.html";
                flag = 1;
                break;
            case 5:
                file_path = "html/DoYi.html";
                flag = 1;
                break;
            case 6:
                file_path = "html/TaTa.html";
                flag = 1;
                break;
            case 7:
                file_path = "html/Cyborn.html";
                flag = 1;
                break;
            case 8:
                file_path = "html/Unknown.html";
                flag = 1;
                break;
            case 0:
                return 0;
            default:
                cout << "invalid input." << endl;
                break;
        }
    }

    return file_path;
}

struct UpdateContent
{
    string date;
    string img_file_path;
    string content;
};

UpdateContent get_content(){
    UpdateContent new_content;
    string img_name;
    cout << "Enter date(yyyy.mm.dd): "; cin >> new_content.date;
    cout << "Enter image file path: "; cin >> img_name;
    new_content.img_file_path = "../images/img/" + img_name;
    cout << "Enter content: "; cin >> new_content.content;
    return new_content;
}

int conformation() {
    int choice = 100;
    int flag = 0;
    while (flag == 0) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {  // not an integer
            cin.clear();   // clear error flags
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Invalid input, please enter 0 or 1." << endl;
            continue;
        }

        if (choice == 0 || choice == 1) {
            cout << choice << endl;
            flag = 1;
        } else {
            cout << "Invalid input," << endl;
        }
    }
    return choice;
}


int update_file(string file_path, UpdateContent new_content) {
    string full_content;
    ofstream outfile;
    full_content =
        "<tbody>\n"
        "    <tr>\n"
        "        <td>" + new_content.date + "</td>\n"
        "        <td style='text-align:center; vertical-align:middle;'>\n"
        "            <img src='" + new_content.img_file_path + "' "
        "style='max-width:100%; max-height:100%; display:block; margin:auto;'>\n"
        "        </td>\n"
        "        <td>" + new_content.content + "</td>\n"
        "    </tr>\n"
        "</tbody>";
    
        cout << "Confirm update? 1.Yes 0.No" << endl;
    if (conformation() == 1) {
        outfile.open(file_path, ios::app);
        if (!outfile) {
            cerr << "Error: Could not open file for appending!" << endl;
            return 1;
        }
        outfile << full_content;

        outfile.close();
        cout << "Done update" << endl;
    }
    
}


int main() {
    string file_path;
    ofstream outfile;
    UpdateContent new_content;
    int flag;
    flag = 1;

    while (flag == 1)
    {
        file_path = get_file_path();
        cout << file_path << endl;

        new_content = get_content();
        cout << new_content.date << endl << new_content.img_file_path << endl << new_content.content << endl;

        update_file(file_path, new_content);

        cout << "Continue update?" << endl;
        flag = conformation();
    }
    
    

}