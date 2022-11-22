#include <iostream>
#include <string>
using namespace std;

// class bankAccount definition
class bankAccount
{
public:
    int acc_num;
    double balance;

public:
    int set_acc_num(int input_num);
    double set_balance(double input_balance);
    int get_acc_num();
    double get_balance();
    double deposit(double add);
    double withdraw(double minus);
    void display_acc();

    bankAccount();
};
int bankAccount::set_acc_num(int input_num)
{
    acc_num = input_num;
}

double bankAccount::set_balance(double input_balance)
{
    balance = input_balance;
}

int bankAccount::get_acc_num()
{
    return acc_num;
}

double bankAccount::get_balance()
{
    return balance;
}

double bankAccount::deposit(double add)
{
    balance += add;
    get_balance();
}

double bankAccount::withdraw(double minus)
{
    balance -= minus;
    get_balance();
}

void bankAccount::display_acc()
{
    cout << "Account Number: " << get_acc_num() << endl;
    cout << "Remaining Balance: " << get_balance() << endl;
}

bankAccount::bankAccount()
{
    set_acc_num(0);
    set_balance(0);
}

// class checkingAccount definition
class checkingAccount : public bankAccount
{
public:
    double interest = 0.05;
    double min_balance = 50000;
    double sg = 2500;

public:
    double get_interest();
    double get_balance();
    double minimum_balance();
    double service_charge();
    bool verify_balance();
    double withdraw(double minus);
    void display_acc();

    checkingAccount();
};

double checkingAccount::get_interest()
{
    return interest;
}

double checkingAccount::get_balance()
{
    bankAccount::get_balance();
}

double checkingAccount::minimum_balance()
{
    return min_balance;
}

double checkingAccount::service_charge()
{
    return sg;
}

bool checkingAccount::verify_balance()
{
    double a = minimum_balance();
    double b = get_balance();
    if (b < a)
    {
        return false;
    }
}

double checkingAccount::withdraw(double minus)
{
    bankAccount::withdraw(minus);
}

void checkingAccount::display_acc()
{
    bankAccount::display_acc();
}

checkingAccount::checkingAccount()
{
}

class savingsAccount : public bankAccount
{
public:
    double interest = 0.05;

public:
    double get_interest();
    double withdraw(double minus);
    double deposit(double add);
    void display_acc();

    savingsAccount();
};

double savingsAccount::get_interest()
{
    return interest;
}

double savingsAccount::withdraw(double minus)
{
    bankAccount::withdraw(minus);
}

double savingsAccount::deposit(double add)
{
    bankAccount::deposit(add);
}

savingsAccount::savingsAccount()
{
}

// main program
int main()
{
    int choice, ves1;
    double cb, wd, dp;
    bool sentinel = true;
    bankAccount tes1;

    cout << "Selamat datang di Bank Lalalilu" << endl;
    cout << "Silahkan buat akun terlebih dahulu" << endl;

    cout << "Masukkan nomor rekening: ";
    cin >> ves1;
    tes1.set_acc_num(ves1);
    cout << "Masukkan saldo: ";
    cin >> cb;
    tes1.set_balance(cb);

    while (sentinel)
    {
        cout << "Silahkan pilih menu yang anda inginkan: " << endl;
        cout << "1. Checking Account" << endl;
        cout << "2. Saving Account" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilihan: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            int ch;
            checkingAccount choice1;
            choice1.display_acc();
            cout << "Silahkan pilih menu yang anda inginkan: " << endl;
            cout << "1. Withdraw Money" << endl;
            cout << "2. Check Account" << endl;
            cout << "Pilihan: ";
            cin >> ch;

            switch (ch)
            {
            case 1:
                cout << "Masukkan nominal uang yang akan diambil: ";
                cin >> wd;
                choice1.withdraw(wd);
                choice1.display_acc();
                break;
            }
        }
        else if (choice == 2)
        {
            savingsAccount choice2;
        }
        else if (choice == 3)
        {
            cout << "Terima kasih dan sampai jumpa kembali" << endl;
            sentinel = false;
        }
        else
        {
            cout << "Input invalid. Silahkan masukkan kembali pilihan anda ";
            cin >> choice;
        }
    }
    return 0;
}