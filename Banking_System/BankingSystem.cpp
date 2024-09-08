#include<iostream>
#include<map>
#include<fstream>
#include<cstdlib>

using namespace std;

class InsufficientFunds{};

class Account{
 private:
  long AccountNumber;
  string FirstName;
  string LastName;
  string Email;
  float Balance;
  static long NextAccountNumber;
 public:
  Account(){}
  Account(string fName,string lName,string email,float bal);
  
  long getAccountNumber(){return AccountNumber;}
  string getFirstName(){return FirstName;}
  string getLastName(){return LastName;}
  string getEmail(){return Email;}
  float getbalance(){return Balance;}

  void Deposit(long AccountNumber,float Amount);
  void Withdraw(long AccountNumber,float Amount);

  static void setLastAccountNumber(long AccountNumber);
  static long getLastAccountNumber();

  friend ostream &operator<<(ostream &os,Account &acc);
  friend ofstream &operator<<(ofstream &ofs,Account &acc);
  friend ifstream &operator>>(ifstream &ifs,Account &acc);
};
long Account::NextAccountNumber = 0;


class Bank{
 private:
  map<long,Account> accounts;
 public:
  Bank();
  Account OpenAccount(string fName,string lName,string email,float bal);
  Account Deposit(long AccountNumber,float amt);
  Account Withdraw(long AccountNumber,float amt);
  Account CheckBalance(long AccountNumber);
  void CloseAccount(long AccountNumber);
  void showAllAccounts();
  ~Bank();
};

int main(){
 Bank bnk;
 Account acc;

 int UserChoice;
 string fname,lname,email;
 float bal,amt;
 long accntnum;

 cout<<"#### Dev's Banking System ####"<<endl;
  do{
   cout<<"\n\tPlease choose your Desired Option ";
   cout<<"\n\t1. Open An Account";
   cout<<"\n\t2. Check Account Balance";
   cout<<"\n\t3. Deposit Amount";
   cout<<"\n\t4. Withdraw Amount";
   cout<<"\n\t5. Close An Account";
   cout<<"\n\t6. Show All Accounts";
   cout<<"\n\t7. Exit";
   cout<<"\nPlease Enter Desired Option : ";
   cin>>UserChoice;
   switch(UserChoice){
    case 1:
     cout<<"First Name : ";cin>>fname;
     cout<<"Last Name : ";cin>>lname;
     cout<<"Email Address : ";cin>>email;
     cout<<"Opening Balance : ";cin>>bal;
     acc = bnk.OpenAccount(fname,lname,email,bal);
     cout<<"\nCongrats!!! Your Account has been created"<<endl;
     cout<<acc;
     break;
    case 2:
     cout<<"Enter Account Number : ";cin>>accntnum;
     acc = bnk.CheckBalance(accntnum);
     cout<<"\nYour Account Details\n";
     cout<<acc;
     break;
   }
  }while(UserChoice!=7);
}
