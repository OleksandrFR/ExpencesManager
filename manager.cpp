#include <iostream>
#include <vector>
#include <string>

using namespace std;

void addExpence(vector<double>& expence, vector<string>& names){
    string name;
    double price;

    cout << "name expences: \n";
    cin >> name;

    cout << "sum expences: \n";
    cin >> price;

    names.push_back(name);
    expence.push_back(price);
}
double calculateExpences(const vector<double>& expence){
    double sum = 0;
    for(int i = 0; i < expence.size(); i++){
        sum += expence[i];
    }
    return sum;
}
double findMostExpensive(vector<double>& expence){
    double mostExpence = expence[0];
    for(int j = 0; j < expence.size(); j++){
        if(expence[j] > mostExpence){
            mostExpence = expence[j];
        }
    }
    return mostExpence;
}
void showBalance(double budget, const vector<double>& expence){
    double total = calculateExpences(expence);
    double balance = budget - total;

    cout << "balance: " << balance << "\n";
}

int main(){
    vector<double> expence;
    vector<string> names;
    double budget;
    cout << "==Expence Tracker==\n" << "\n";
    cout << "==Enter Your Budget==\n";
    cin >> budget;
    while(true){
        cout << "\nWhat do you want to do?\n";
        cout << "Add expense(1), Calculate all expenses(2), Find the most expensive expense(3), View remaining money(4)\n";
        int operation;
        cin >> operation;
        
        switch(operation){
            case 1:
            addExpence(expence, names);
            break;
            case 2:
            cout << "==Total costs==\n"
            << calculateExpences(expence) << "\n";
            break;
            case 3:
            if(expence.empty()){
                cout << "==There are no expenses yet==\n";
            }
            else{
                cout << "==Most Expences==\n" << findMostExpensive(expence); 
            }
            break;
            case 4:
            showBalance(budget, expence);
            break;

            default:
                cout << "Invalid Command\n";
                return 1;
        }
    } 
    return 0;
}