#include <iostream>
#include <string>

using namespace std;
void math(int* ptr1, int* ptr2, char sym, int* ptr3){
    switch(sym){
        case '+':
            *ptr3 = *ptr1 + *ptr2;
        break;
        case '-':
            *ptr3 = *ptr1 - *ptr2;
        break;
        case '*':
            *ptr3 = *ptr1 * *ptr2;
        break;
        case '/':
        
        if(*ptr2 == 0){
            cout << "you cannot divide by zero" << "\n";
        }
            *ptr3 = *ptr1 / *ptr2;
        break;
 
    }
    cout << *ptr3;
}
int main(){
    setlocale(LC_ALL, "UA");
    int num1;
    int num2;
    
    int result;
    char sym;
    cout << "enter 2 numbers: " << "\n";
    cin >> num1;
    cin >> num2;

    cout << "enter the operation: " << "\n";
    cin >> sym;
    
    int* ptr1 = new int(num1);
    int* ptr2 = new int(num2);
    int* ptr3 = new int(result);
    
    math(ptr1, ptr2, sym, ptr3);

    delete ptr1, ptr2, ptr3;

    return 0;
}