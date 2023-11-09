#include <iostream>
#include <string>
using namespace std;

bool card_inserted = false;         // Flag that indiciates card is inserted
bool pin_correct = false;           // Flag that PIN Number is correct or not

string PIN_Number("1234");          // Card`s PIN number example
const int accounts_number = 3;      // Card`s Accounts number example
int AccountNumber = 0;              // Index of account
int work = 0;                       // Index of work 

typedef struct{                     // Structure that stores each account`s balance
    int balance = 300;              // This should be read by Card Reader
} Account;
Account acc[accounts_number];       // Array of accounts. 

bool PIN_Check();
int selectAccount();
void disbalance(int account_index);
int dismenu();
void deposit(int AccountNumber);
void withdraw(int AccountNumber);

int main(){

    card_inserted = true;                       // Card is inserted

    pin_correct = PIN_Check();                  // Check the PIN Number

    AccountNumber = selectAccount();            // Select the account to use

    while(card_inserted == true && pin_correct == true){              

            work = dismenu();                   // Select work to do

            switch(work){
            case 1:
                disbalance(AccountNumber);      // Display the Account`s balance
                break;
            case 2:
                deposit(AccountNumber);         // Deposit the money to account
                break;
            case 3:
                withdraw(AccountNumber);        // Withdraw the money in account
                break;
            case 4:
                exit(-1);                       // End the Program
            default:
                cout << "Please Enter the number again" << endl;
                break;
            }
        }

    return 0;
}


bool PIN_Check(){        // Function that check PIN Number   
    string PIN_input;;
    int count = 3;

    while(count > 0){
        cout << "Enter PIN Number : ";
        getline(cin, PIN_input);

        if(PIN_input != PIN_Number){
            cout << "You entered the wrong PIN number. Please enter the PIN number again" << endl;
            continue;
        }
        return true;   
    }
}

int selectAccount(){               // Select the account to use
    int num;
    cout << "Select Account to Access : ";
    cin >> num;
    return num;
}

int dismenu(){                      // Function that displays and selects the work to use
    int num = 0;
    cout << endl;
    cout << "Select the work to use in Account" << AccountNumber << " : " << endl;
    cout << "1. See Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. End" << endl;
    cin >> num;

    return num;
}

void disbalance(int account_index){   // Display the Account`s Balance
    cout << endl;
    cout << "Balance : " << acc[account_index].balance << "$" << endl;
}

void deposit(int AccountNumber){      // Deposit the money to account
    int amount = 0;

    cout << "Enter the amount to deposite : ";
    cin >> amount;
    
    acc[AccountNumber].balance += amount;
    cout << "Deposited " << amount << "$" << endl;
}

void withdraw(int AccountNumber){     // Withdraw the money in account
    int amount = 0;
    int flag = 1;

    while(flag == 1){
        cout << "Enter the amount to withdraw : ";
        cin >> amount;

        if(amount > acc[AccountNumber].balance){
            cout << "Amount to withdraw exceeds the balance. Please enter the amount less than the balance" << endl;
            continue;
        }
        else{
            acc[AccountNumber].balance -= amount;
            cout << "Withdrew " << amount << "$" << endl;
            flag = 0;
        }
    }
}