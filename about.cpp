#include <iostream>
#include <string>

using namespace std;
void checkLog(int psw, string login){
    if(login == "mukyt" && psw == 223311){
        cout << "Вхід дозволено!" << "\n";
    }
    else{
        cout << "Вхід заборонено!" << "\n";
    }

}
int main(){
    setlocale(LC_ALL, "UA");
    int psw = 223311;
    string login = "mukyt";
    cout << "Введіть логін: " << "\n";
    cin >> login;

    cout << "Введіть пароль: " << "\n";
    cin >> psw;

    checkLog(psw, login);
    return 0;
}