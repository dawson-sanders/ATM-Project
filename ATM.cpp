//------------------------------------------------------------
// Purpose: Program to simulate an ATM application
// Author:  Dawson Sanders 
//------------------------------------------------------------
#include <iostream>
using namespace std;


// Purpose: Function for main menu options
void mainMenu()
{
    cout << "********MAIN MENU********" << endl;
    cout << "1. Check Balences" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Transfer Money" << endl;
    cout << "5. Exit" << endl;    
    cout << "*************************" << endl;
}

// Purpose: Function for balence menu options
void balenceMenu()
{
    cout << "********BALENCE MENU********" << endl;
    cout << "1. Checking Account Balence" << endl;
    cout << "2. Savings Account Balence" << endl;
    cout << "****************************" << endl;
}

// Purpose: Function for deposit menu options
void depositMenu()
{
    cout << "********DEPOSIT MENU********" << endl;
    cout << "1. Deposit Money to Checking Account" << endl;
    cout << "2. Deposit Money to Savings Account" << endl;
    cout << "****************************" << endl;
}

// Purpose: Function for withdraw menu options
void withdrawMenu()
{
    cout << "********WITHDRAW MENU********" << endl;
    cout << "1. Withdraw Money from Checking Account" << endl;
    cout << "2. Withdraw Money from Savings Account" << endl;
    cout << "****************************" << endl;
}

// Purpose: Function for transfer menu options
void transferMenu()
{
    cout << "********TRANSFER MENU********" << endl;
    cout << "1. Transfer Money from Checking Account to Savings Account" << endl;
    cout << "2. Transfer Money from Savings Account to Checking Account" << endl;
    cout << "****************************" << endl;
}

//------------------------------------------------------------------------------------

    //Global Variable Declarations
    float checkingBalence = 100.00;
    float savingsBalence = 1000.00;
    float depositAmount = 0.00;
    float withdrawAmount = 0.00;
    float transferAmount = 0.00;
    bool isTrue = true;
    int pin = 0;
    int password = 123; 

int main()
{
    int mainOption = 0;
    cout << "****Welcome to ATM****" << endl;
    cout << "Enter pin number: ";
    cin >> pin;
    
    do
    {
        if (pin == password)
        {
            mainMenu();
            cout << "Please select a option from the menu provided: ";
            cin >> mainOption;
            system("clear");
            
            do
            {    
                switch(mainOption)
                {
                    case 1: 
                    balenceMenu();
                    int balenceOption;
                    cout << "Please select a choice from the menu provided: ";
                    cin >> balenceOption;
                    
                    if (balenceOption == 1)
                    {
                        system("clear");
                        cout << "Checking Account Balence: $" << checkingBalence << endl;
                    }
                    else if (balenceOption == 2)
                    {
                        system("clear");
                        cout << "Savings Account Balence: $" << savingsBalence << endl;
                    }
                    else
                    {
                        system("clear");
                        cout << "Invalid Option. Back to Main Menu" << endl;
                    }
                    break;
                
                    case 2:
                    depositMenu();
                    int depositOption;
                    cout << "Please select a choice from the menu provided: ";
                    cin >> depositOption;
                    
                    if (depositOption == 1)
                    {
                        system("clear");
                        cout << "Enter Deposit Amount: $";
                        cin >> depositAmount;
                        checkingBalence += depositAmount;
                        cout << "New Checking Balence: $" << checkingBalence << endl; 
                    }   
                    
                    if (depositOption == 2)
                    {
                        system("clear");
                        cout << "Enter Deposit Amount: $";
                        cin >> depositAmount;
                        savingsBalence += depositAmount;
                        cout << "New Savings Balence: $" << savingsBalence << endl;
                    }
                    break;
                
                    case 3:
                    withdrawMenu();
                    int withdrawOption;
                    cout << "Please select a choice from the menu provided: ";
                    cin >> withdrawOption;
                    
                    if (withdrawOption == 1)
                    {
                        system("clear");
                        cout << "Enter Withdraw Amount: ";
                        cin >> withdrawAmount;
                        if (withdrawAmount > checkingBalence)
                        {
                            cout << "Insufficient Funds! Back to Main Menu." << endl;
                        }
                        else
                        {
                            checkingBalence -= withdrawAmount;
                            cout << "New Checking Balence: $" << checkingBalence << endl;
                        }
                    }
                    
                    if (withdrawOption == 2)
                    {
                        system("clear");
                        cout << "Enter Withdraw Amount: ";
                        cin >> withdrawAmount;
                        if (withdrawAmount > savingsBalence)
                        {
                            cout << "Insufficient Funds! Back to Main Menu." << endl;
                        }
                        else 
                        {
                            savingsBalence -= withdrawAmount;
                            cout << "New Savings Balence: $" << savingsBalence << endl;
                        }
                    }
                    break;
                
                    case 4:
                    transferMenu();
                    int transferOption;
                    cout << "Please select a choice from the menu provided: ";
                    cin >> transferOption;
                    
                    if (transferOption == 1)
                    {
                        system("clear");
                        cout << "Enter Amount for Transfer: $";
                        cin >> transferAmount;
                        if (transferAmount <= checkingBalence)
                        {
                            checkingBalence -= transferAmount;
                            savingsBalence += transferAmount;
                            cout << "New Checking Balence: $" << checkingBalence << endl;
                            cout << "New Savings Balence: $" << savingsBalence << endl;
                        }
                        else 
                        {
                            cout << "Insufficient funds. Back to Main Menu" << endl;
                        }
                    }
                    
                    if (transferOption == 2)
                    {
                        system("clear");
                        cout << "Enter Amount for Transfer: $";
                        cin >> transferAmount;
                        if (transferAmount <= savingsBalence)
                        {
                            savingsBalence -= transferAmount;
                            checkingBalence += transferAmount;
                            cout << "New Savings Balence: $" << savingsBalence << endl;
                            cout << "New Checking Balence: $" << checkingBalence << endl;
                        }  
                        else 
                        {
                            cout << "Insufficient funds. Back to Main Menu" << endl;
                        }
                    }
                    break;
                
                    case 5:
                    return 0;
                    break;
                }
            }while(isTrue == false);
        }   
        else 
        {
            system("clear");
            cout << "Incorrect pin!" << endl;
            cout << "Please Enter Pin: ";
            cin >> pin;
            system("clear");
        }
        
    }while(mainOption != 5); 
}            
                
