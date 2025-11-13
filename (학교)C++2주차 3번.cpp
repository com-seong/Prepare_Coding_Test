#include<iostream>
using namespace std;
class Account{
	private:
		string name;
		int remain;
	public:
		Account(string name);
		void deposit(int money);
		string getOwner();
		int inquiry();
		int withdraw(int money);
};
Account::Account(string name) : name(name) {}
void Account::deposit(int money){
	remain = money;
}
string Account::getOwner(){
	return name;
}
int Account::inquiry(){
	if(remain >= 0)
	  return remain;
	else return 0;
}
int Account::withdraw(int money){
	remain -= money;
	return money;
}
int main()
{
	Account a("È²¼öÈñ");
	a.deposit(20000);
	cout << a.getOwner() << "ÀÜ¾×Àº " << a.inquiry() << endl;
	int money = a.withdraw(15000);
	cout << money << "¿ø Ãâ±İ, ";
	cout << a.getOwner() << "ÀÜ¾×Àº " << a.inquiry() << endl;
	money = a.withdraw(8000);
	cout << money << "¿ø Ãâ±İ, ";
	cout << a.getOwner() << " ÀÜ¾×Àº " << a.inquiry() << endl;
	return 0;
}
