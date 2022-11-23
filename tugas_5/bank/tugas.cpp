#include <iostream>
#include <string>
using namespace std;

// class bankAccount definition
class bankAccount
{
protected:
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
    set_balance(balance);
    // get_balance();
}

double bankAccount::withdraw(double minus)
{
    balance -= minus;
    set_balance(balance);
    // get_balance();
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

/***********************************************************************************/
// class checkingAccount definition
class checkingAccount : public bankAccount
{
protected:
    double interest = 0.05;
    double min_balance = 500;
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
    checkingAccount(int acc, double bal);
};

double checkingAccount::get_interest()
{
    return interest;
}

double checkingAccount::get_balance()
{
    return balance;
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
    else
    {
        return true;
    }
}

double checkingAccount::withdraw(double minus)
{
    double vessel = balance;
    vessel -= minus;
    set_balance(vessel);
}

void checkingAccount::display_acc()
{
    bankAccount::display_acc();
}

checkingAccount::checkingAccount()
{
    acc_num = 0;
    balance = 0;
}

checkingAccount::checkingAccount(int acc, double bal)
{
    acc_num = acc;
    balance = bal;
}

/***********************************************************************************/
// class savingsAccout definiton
class savingsAccount : public bankAccount
{
protected:
    double interest = 0.05;

public:
    double get_interest();
    double withdraw(double minus);
    double deposit(double add);
    void display_acc();

    savingsAccount();
    savingsAccount(int acc, double bal);
};

double savingsAccount::get_interest()
{
    return interest;
}

double savingsAccount::withdraw(double minus)
{
    double vessel = balance;
    vessel -= minus;
    set_balance(vessel);
}

double savingsAccount::deposit(double add)
{
    double vessel = balance;
    vessel += add;
    set_balance(vessel);
}

savingsAccount::savingsAccount()
{
    acc_num = 0;
    balance = 0;
}

savingsAccount::savingsAccount(int acc, double bal)
{
    acc_num = acc;
    balance = bal;
}

void savingsAccount::display_acc()
{
    bankAccount::display_acc();
}

// main program
int main()
{
    int choice, an;
    double cb, wd, dp;
    bool sentinel = true;

    cout << "Selamat datang di Bank Lalalilu" << endl;
    cout << "Silahkan buat akun terlebih dahulu" << endl;

    cout << "Masukkan nomor rekening: ";
    cin >> an;
    cout << "Masukkan saldo: ";
    cin >> cb;
    checkingAccount ca(an, cb);
    savingsAccount sa(an, cb);

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
            int ch, ans;
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
                if (ca.verify_balance())
                {
                    ca.withdraw(wd);
                    cout << "Silahkan ambil uang anda. Anda akan diarahkan kembali ke menu utama" << endl;
                    break;
                }
                else
                {
                    cout << "Saldo anda tidak mencukupi. Anda akan diarahkan kembali ke menut utama" << endl;
                }
                cout << endl;
                break;
            case 2:
                ca.display_acc();
                cout << "Anda akan diarahkan kembali ke menu utama" << endl;
                cout << endl;
                break;
            }
        }
        else if (choice == 2)
        {
            int ch, ans;
            cout << "Silahkan pilih menu yang anda inginkan: " << endl;
            cout << "1. Withdraw Money" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "Pilihan: ";
            cin >> ch;

            switch (ch)
            {
            case 1:

                cout << "Masukkan nominal uang yang akan diambil: ";
                cin >> wd;
                if (ca.verify_balance())
                {
                    sa.withdraw(wd);
                    cout << "Silahkan ambil uang anda. Anda akan diarahkan kembali ke menu utama" << endl;
                    break;
                }
                else
                {
                    cout << "Saldo anda tidak mencukupi. Anda akan diarahkan kembali ke menut utama" << endl;
                }
                cout << endl;
                break;
            case 2:
                cout << "Masukkan nominal uang yang akan dideposit: ";
                cin >> dp;
                sa.deposit(dp);
                sa.display_acc();
                cout << "Proses transaksi berhasil. Anda akan diarahkan kembali ke menu utama" << endl;
                cout << endl;
                break;
            }
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
