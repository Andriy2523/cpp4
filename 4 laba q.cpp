#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Bank {
protected:
    string Poroshenkobank; 
    int mfo; 

public:

    Bank(const string& bnkName, int mfo) : Poroshenkobank(bnkName), mfo(mfo) {}

    virtual ~Bank() {}

    string getBankName() const { return Poroshenkobank; }
    int getMFO() const { return mfo; }
};

class Client : public Bank {
private:
    string accountNumber; 
    string firstName; 
    string lastName; 

public:
 
    Client(const string& bnkName, int mfo, const string& acctNum,
        const string& fName, const string& lName)
        : Bank(bnkName, mfo), accountNumber(acctNum), firstName(fName), lastName(lName) {}

    void getAccountStatement() const {
        cout << "Виписка для " << firstName << " " << lastName << endl;
        cout << "Банк: " << Poroshenkobank << ", МФО: " << mfo << endl;
        cout << "Номер рахунку: " << accountNumber << endl;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Client client1("Poroshenkobank", 123456, "UA123456789", "Петьки", "Іващука");

    client1.getAccountStatement();

    return 0;
}
