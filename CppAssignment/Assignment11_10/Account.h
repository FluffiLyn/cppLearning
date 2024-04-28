using namespace std;

class Account
{
public:
    Account(double);
    void credit(double&);//Adds amount to the current balance
    bool debit(double&);//Withdraws money from the account and doesn't exceed
    double getBalance();

private:
    double balance;//Should be >= 0.0
};