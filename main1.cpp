#include <iostream>
#include <string>

using namespace std;
void len(const string& text1, const string& text2){
    if(text1.length() > text2.length()){
        cout << text1 << " " << "longer: " << text1.length() %  << "\n";
    }
    else if(text1.length() < text2.length()){
        cout << text2 << " " << "longer: " << text2.length() % 2 << "\n";
    }
    else
        cout << "same length" << "\n";
}
int main() {
    setlocale(LC_ALL, "UA");
    string text1;
    string text2;

    cout << "enter 2 words" << "\n";
    cin >> text1;
    cin >> text2;

    len(text1, text2);

    return 0;
}