#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

double calculateExpences(const vector<double>& expence);

void addExpence(vector<double>& expence, vector<string>& names, double budget){
    string name;
    double price;

    cout << "name expences: \n";
    cin >> name;

    cout << "sum expences: \n";
    cin >> price;

     if(calculateExpences(expence) + price > budget){
        cout << "Error! Budget exceeded!\n";
        exit(1);
    }
    else{
         names.push_back(name);
         expence.push_back(price);
    }
   
}
double calculateExpences(const vector<double>& expence){
    double sum = 0;
    for(int i = 0; i < expence.size(); i++){
        sum += expence[i];
    }
    return sum;
}
void findMostExpensive(vector<double>& expence, vector<string>& names){
    double mostExpence = expence[0];
    int mostIndex = 0;
    for(int j = 0; j < expence.size(); j++){
        if(expence[j] > mostExpence){
            mostExpence = expence[j];
            mostIndex = j;
        }
        
    }
    cout << "Most expensive: " << names[mostIndex] << "\n";
    cout << "Price: " << mostExpence << "\n";
}
void showBalance(double budget, const vector<double>& expence){
    double totalExpence = calculateExpences(expence);
    double balance = budget - totalExpence;

    cout << "balance: " << balance << "\n";
}

void removeExpence(vector<double>& expence, vector<string>& names){
    int vectorIndex = 0;

    if(names.empty()){
        cout << "No expences to remove!\n";
        exit(1);
    }

    for(int n = 0; n < names.size(); n++){
        cout << n + 1 << ". " << names[n] << " - " << expence[n] << "\n";
    }
    cout << "Enter the number of expense to remove: " << "\n";
    cin >> vectorIndex;
   
        if(vectorIndex < 1 || vectorIndex > names.size()){
            cout << "Invalid Index!\n";
            exit(1);
        }
        else{
            names.erase(names.begin() + (vectorIndex - 1));
            expence.erase(expence.begin() + (vectorIndex - 1));
            cout << "Expense removed successfully!\n";
        }
    
}

void addMoney(double& budget){
    double addBudget;
    cout << "Enter the amount you want to add: \n";
    cin >> addBudget;
    budget += addBudget;
    cout << "Succesfully added!\n";
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
        
        cout << "==(1)Add expense==\n";
        cout << "==(2)Add to budget==\n";
        cout << "==(3)Calculate All Expenses==\n";
        cout << "==(4)Find The most Expensive expense==\n";
        cout << "==(5)View Remaining Money==\n";
        cout << "==(6)Remove Expense==\n";
        cout << "==(7)Close==\n";
        
        int operation;
        cin >> operation;
        
        switch(operation){
            case 1:
            addExpence(expence, names, budget);
            break;
            case 2:
            addMoney(budget);
            break;
            case 3:
            cout << "==Total costs==\n"
            << calculateExpences(expence) << "\n";
            break;
            case 4:
            if(expence.empty()){
                cout << "==There are no expenses yet==\n";
            }
            else{
                cout << "==Most Expences==\n";
                findMostExpensive(expence, names); 
            }
            break;
            case 5:
            showBalance(budget, expence);
            break;
            case 6:
            removeExpence(expence, names);
            break;
            case 7:
            cout << "Program is closing..\n";
            return 0;

            default:
                cout << "Invalid Command\n";
                return 1;
        }
    } 
    return 0;
}