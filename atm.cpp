#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class ATM										
{
    private:									
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobile_No;

    public:
        ATM(long int account_No, string name, int PIN, double balance, string mobile_No) {
            this->account_No = account_No;	 
            this->name = name;
            this->PIN = PIN;
            this->balance = balance;
            this->mobile_No = mobile_No;
        }
        
        long int getAccountNo() {
            return account_No;
        }
        
        string getName() {
            return name;
        }

        int getPIN() {
            return PIN;
        }

        double getBalance() {
            return balance;
        }

        string getMobileNo() {
            return mobile_No;
        }

        void setMobile(string mob_prev, string mob_new) {
            if (mob_prev == mobile_No) {
                mobile_No = mob_new;						
                cout << endl << "Sucessfully Updated Mobile Number.";
                _getch();																					
            } else {
                cout << endl << "Your Old Mobile Number is INVALID.";
                _getch();			  
            }
        }

        void setPIN(int pin_prev, int pin_new) {
            if (pin_prev == PIN) {
                PIN = pin_new;						
                cout << endl << "Sucessfully Updated PIN.";
                _getch();																					
            } else {
                cout << endl << "Your Old PIN is INVALID.";
                _getch();			  
            }
        }

        void cashWithDraw(int amount) {
            if (amount > 0 && amount < balance) {
                balance -= amount;		
                cout << endl << "Please Collect Your Cash : Rs. "<<amount<<endl;
                cout << endl << "Available Balance : Rs. " << balance;
                _getch();				
            } else {
                cout << endl << "Invalid Input or Insufficient Balance";
                _getch();				
            }
        }

		static bool isAccountNoExists(const vector<ATM>& user, const long int& accountNo) {
			for (const ATM& details : user) {
				if (details.account_No == accountNo) {
					return true;
				}
			}
			return false;
		}
};

int main()
{
	vector<ATM> users;
 	users.push_back(ATM(123456, "Alice", 1111, 45000.90, "9087654321"));
    users.push_back(ATM(456789, "Bob", 2222, 45000.00, "9876543215"));

    next_user:
        do {
            system("cls");
            int option;
            cout << endl << "***** Welcome to ATM *****" << endl;
            cout << endl << "1. New User.";
            cout << endl << "2. Old User." << endl;
            cout << endl << "Select Options : ";
            cin >> option;
            switch(option) {
                case 1: {
                            system("cls");
                            cout << endl << "***** Welcome to ATM *****" << endl;
                            long int account_No;
                            string name, mobile_No;
                            int PIN;
                            double balance;
							
                            cout << endl << "Enter your details :" << endl;
                            cout << endl;
                            cout << "Account No. : ";
                            cin >> account_No;

                            if(ATM::isAccountNoExists(users, account_No)) {
								cout << endl << "User already exists..." << endl;
							} else {
								cout << "Name : ";
								cin >> name;
								cout << "PIN : ";
								cin >> PIN;
								cout << "Balance : ";
								cin >> balance;
								cout << "Mobile No. : ";
								cin >> mobile_No;
								users.push_back(ATM(account_No, name, PIN, balance, mobile_No));
							}
                            break;
                        }
                case 2: {
                            do {
                                int choice = 0, enterPIN;		
                                long int enterAccountNo;
                                system("cls");

                                cout << endl << "***** Welcome to ATM *****" << endl;
                                cout << endl << "Enter Your Account No : ";	  
                                cin >> enterAccountNo;
                                cout << endl << "Enter PIN : ";				 
                                cin >> enterPIN;
                                for(int i = 0; i < users.size(); i++) 
                                {
                                    if(users[i].getAccountNo() == enterAccountNo && users[i].getPIN() == enterPIN)
                                    {
                                        do
                                        {
                                            int amount = 0;
                                            string oldMobileNo, newMobileNo;
                                            int oldPin, newPin;
                                            system("cls");
                                        
                                            cout << endl << "***** Welcome to ATM *****" << endl;
                                            cout << endl << "1. Check Balance";
                                            cout << endl << "2. Cash withdraw";
                                            cout << endl << "3. Show User Details";
                                            cout << endl << "4. Update Mobile no.";
                                            cout << endl << "5. Update PIN";
                                            cout << endl << "6. Exit User";
                                            cout << endl << "7. Exit" << endl;
                                            cout << endl << "Select Options : ";
                                            cin >> choice;						

                                            switch (choice)						
                                            {
                                                case 1: cout << endl << "Your Bank balance is : Rs. " << users[i].getBalance(); 
                                                        _getch();
                                                        break;
                                                case 2:	cout << endl << "Enter the amount : ";		
                                                        cin >> amount;
                                                        users[i].cashWithDraw(amount);			
                                                        break;
                                                case 3:	cout << endl << "***** User Details *****" << endl;
                                                        cout << endl << "-> Account no : " << users[i].getAccountNo();
                                                        cout << endl << "-> Name       : " << users[i].getName();
                                                        cout << endl << "-> Balance    : " << users[i].getBalance();
                                                        cout << endl << "-> Mobile No. : " << users[i].getMobileNo();
                                                        _getch();
                                                        break;
                                                case 4:	cout << endl << "Enter Old Mobile No. : ";
                                                        cin >> oldMobileNo;							
                                                        cout << endl << "Enter New Mobile No. : ";
                                                        cin >> newMobileNo;							
                                                        users[i].setMobile(oldMobileNo, newMobileNo);	
                                                        break;
                                                case 5: cout << endl << "Enter Old PIN : ";
                                                        cin >> oldPin;							
                                                        cout << endl << "Enter New PIN : ";
                                                        cin >> newPin;							
                                                        users[i].setPIN(oldPin, newPin);	
                                                        break;                           
                                                case 6: goto next_user;
                                                case 7: exit(0);						
                                                default:cout << endl << "Enter Valid Data !!!";
                                            } 
											_getch();
                                        } while (1);				\
                                    }
                                }
                                cout << endl << "User Details are Invalid !!! ";
                                _getch();
                            } while(1);
                            break;
                        }
                default:cout << endl << "Enter Valid Data !!!";
            }
            _getch();
        } while(1);
    /*
		CODE TO PRINT ALL VALUES STORED IN ATM's OBJECT 'users' 

        for(int i = 0; i < users.size(); i++) {
            cout << endl << "-> Account Number : " << users[i].getAccountNo();
            cout << endl << "-> Name           : " << users[i].getName();
            cout << endl << "-> Balance        : " << users[i].getBalance();
            cout << endl << "-> Mobile No.     : " << users[i].getMobileNo() << endl;
        }
    */
    return 0;
}