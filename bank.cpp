//Libraries

#include<iostream>
#include<cstdlib>
using namespace std;


//Class
class BankAccount
{
    char openDate[20];
    char accName[20];
    int accNumber;
    char accType;
    float balance;
    float interest;

    public:

        static int count;

        BankAccount()
        {
            cout << "---NEW ACCOUNT DETAILS---\n";

            cout << "Opening Date   : ";
            cin >> openDate;

            cout << "Account name   : ";
            cin >> accName;

            cout << "Account Number : ";
            cin >> accNumber;

            cout << "Account Type   : ";
            cin >> accType;

            cout << "Account Balance: ";
            cin >> balance;

            interest=4;

            count++;
        }

        friend int search(BankAccount **b,int num)
        {
            for(int i=0;i<BankAccount::count;i++)
            {
                if(b[i]->accNumber==num)
                    return i;
            }
            return -1;
        }

        friend void deposit(BankAccount **b,int num,float amount)
        {
            num=search(b,num);

            if(num==-1)
                cout << "Error: Account Number Invalid\n";
            else
                b[num]->balance+=amount;
        }

        friend void withdraw(BankAccount **b,int num,float amount)
        {
            num=search(b,num);

            if(num==-1)
                cout << "Error: Account Number Invalid\n";
            else
            {
                if( b[num]->balance-amount >1000)
                    b[num]->balance-=amount;
                else
                    cout << "Transaction Error: Balance below Rs.1000\n";
            }
        }

        friend void details(BankAccount **b,int num)
        {
            num=search(b,num);

            if(num==-1)
                cout << "Error: Account Number Invalid\n";
            else
            {
                cout << "---ACCOUNT DETAILS---\n";
                cout << "Account Name   :"<<b[num]->accName<<endl;
                cout << "Account Number :"<<b[num]->accNumber<<endl;
                cout << "Account Type   :"<<b[num]->accNumber<<endl;
                cout << "Opening Date   :"<<b[num]->openDate<<endl;
                cout << "Account Balance:Rs."<<b[num]->balance<<endl;
            }
        }

        // friend void interest(BankAccount &b)
        // {
        //     b.balance+=(interest/100)*balance;
        // }
};

int BankAccount::count=0;


int main()
{
    int n=-1,num;
    float amount;

    BankAccount **acc=NULL;

    do
    {

    cout << "-----BANKING SYSTEM-----\n";
    cout << "1.New Account\n2.Deposit\n3.Withdraw\n4.Bal Enquiry\n5.Exit\n>>";

    cin  >> n;

    cout << "\x1B[2J\x1B[H";

    switch(n)
    {
        case 1: acc=(BankAccount**)realloc(acc,sizeof(BankAccount*)
                                                *(BankAccount::count+1));

                acc[BankAccount::count-1]=new BankAccount();

                break;

        case 2: cout << "Enter Account Number:";
                cin >> num;

                cout << "Enter Amount:";
                cin >> amount;

                deposit(acc,num,amount);

                break;

        case 3: cout << "Enter Account Number:";
                cin >> num;

                cout << "Enter Amount:";
                cin >> amount;

                withdraw(acc,num,amount);
                break;

        case 4: cout << "Enter Account Number:";
                cin >> num;

                details(acc,num);

                break;
    }
    cout << endl;
    }while(n!=5);


    free(acc);
}