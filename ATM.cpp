//------------------------------------------------------------
// Purpose: Program to simulate an ATM application
// Name: Dawson Sanders 
//------------------------------------------------------------
#include <iostream>

// Function for main menu options
void mainMenu()
{
    std::cout << "********MAIN MENU********" << std::endl;
    std::cout << "1. Check Balences" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Transfer Money" << std::endl;
    std::cout << "5. Exit" << std::endl;    
    std::cout << "*************************" << std::endl;
}

// Function for balence menu options
void balenceMenu()
{
    std::cout << "********BALENCE MENU********" << std::endl;
    std::cout << "1. Checking Account Balence" << std::endl;
    std::cout << "2. Savings Account Balence" << std::endl;
    std::cout << "****************************" << std::endl;
}

// Function for deposit menu options
void depositMenu()
{
    std::cout << "********DEPOSIT MENU********" << std::endl;
    std::cout << "1. Deposit Money to Checking Account" << std::endl;
    std::cout << "2. Deposit Money to Savings Account" << std::endl;
    std::cout << "****************************" << std::endl;
}

// Function for withdraw menu options
void withdrawMenu()
{
    std::cout << "********WITHDRAW MENU********" << std::endl;
    std::cout << "1. Withdraw Money from Checking Account" << std::endl;
    std::cout << "2. Withdraw Money from Savings Account" << std::endl;
    std::cout << "****************************" << std::endl;
}

// Function for transfer menu options
void transferMenu()
{
    std::cout << "********TRANSFER MENU********" << std::endl;
    std::cout << "1. Transfer Money from Checking Account to Savings Account" << std::endl;
    std::cout << "2. Transfer Money from Savings Account to Checking Account" << std::endl;
    std::cout << "****************************" << std::endl;
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
    int count = 0;
    

int main()
{
    int mainOption = 0;
    std::cout << "******************************************************" << std::endl;
    std::cout << "*                  Welcome to ATM                    *" << std::endl;
    std::cout << "******************************************************" << std::endl << std::endl;
    std::cout << "Enter Pin Number: ";
    std::cin >> pin;
    std::cout << std::endl;
    
    do
    {
        if (pin == password)
        {
            mainMenu();
            std::cout << "Please select a option from the menu provided: ";
            std::cin >> mainOption;
            system("clear");
            
            do
            {    
                switch(mainOption)
                {
                    case 1: 
                    balenceMenu();
                    int balenceOption;
                    std::cout << "Please select a choice from the menu provided: ";
                    std::cin >> balenceOption;
                    
                    if (balenceOption == 1)
                    {
                        system("clear");
                        std::cout << "Checking Account Balence: $" << checkingBalence << std::endl << std::endl;
                    }
                    else if (balenceOption == 2)
                    {
                        system("clear");
                        std::cout << "Savings Account Balence: $" << savingsBalence << std::endl << std::endl;
                    }
                    else
                    {
                        system("clear");
                        std::cout << "Invalid Option. Back to Main Menu" << std::endl << std::endl;
                    }
                    break;
                
                    case 2:
                    depositMenu();
                    int depositOption;
                    std::cout << "Please select a choice from the menu provided: ";
                    std::cin >> depositOption;
                    
                    if (depositOption == 1)
                    {
                        system("clear");
                        std::cout << "Enter Deposit Amount: $";
                        std::cin >> depositAmount;
                        checkingBalence += depositAmount;
                        std::cout << "New Checking Balence: $" << checkingBalence << std::endl << std::endl; 
                    }   
                    else if (depositOption == 2)
                    {
                        system("clear");
                        std::cout << "Enter Deposit Amount: $";
                        std::cin >> depositAmount;
                        savingsBalence += depositAmount;
                        std::cout << "New Savings Balence: $" << savingsBalence << std::endl << std::endl;
                    }
                    else
                    {
                        system("clear");
                        std::cout << "Invalid Option. Back to Main Menu" << std::endl << std::endl;
                    }
                    break;
                
                    case 3:
                    withdrawMenu();
                    int withdrawOption;
                    std::cout << "Please select a choice from the menu provided: ";
                    std::cin >> withdrawOption;
                    
                    if (withdrawOption == 1)
                    {
                        system("clear");
                        std::cout << "Enter Withdraw Amount: ";
                        std::cin >> withdrawAmount;
                        if (withdrawAmount > checkingBalence)
                        {
                            std::cout << "Insufficient Funds! Back to Main Menu." << std::endl << std::endl;
                        }
                        else
                        {
                            checkingBalence -= withdrawAmount;
                            std::cout << "New Checking Balence: $" << checkingBalence << std::endl << std::endl;
                        }
                    }
                    else if (withdrawOption == 2)
                    {
                        system("clear");
                        std::cout << "Enter Withdraw Amount: ";
                        std::cin >> withdrawAmount;
                        if (withdrawAmount > savingsBalence)
                        {
                            std::cout << "Insufficient Funds! Back to Main Menu." << std::endl << std::endl;
                        }
                        else 
                        {
                            savingsBalence -= withdrawAmount;
                            std::cout << "New Savings Balence: $" << savingsBalence << std::endl << std::endl;
                        }
                    }
                    else
                    {
                        system("clear");
                        std::cout << "Invalid Option. Back to Main Menu" << std::endl << std::endl;
                    }
                    break;
                
                    case 4:
                    transferMenu();
                    int transferOption;
                    std::cout << "Please select a choice from the menu provided: ";
                    std::cin >> transferOption;
                    
                    if (transferOption == 1)
                    {
                        system("clear");
                        std::cout << "Enter Amount for Transfer: $";
                        std::cin >> transferAmount;
                        if (transferAmount <= checkingBalence)
                        {
                            checkingBalence -= transferAmount;
                            savingsBalence += transferAmount;
                            std::cout << "New Checking Balence: $" << checkingBalence << std::endl;
                            std::cout << "New Savings Balence: $" << savingsBalence << std::endl << std::endl;
                        }
                        else 
                        {
                            std::cout << "Insufficient funds. Back to Main Menu" << std::endl << std::endl;
                        }
                    }
                    else if (transferOption == 2)
                    {
                        system("clear");
                        std::cout << "Enter Amount for Transfer: $";
                        std::cin >> transferAmount;
                        if (transferAmount <= savingsBalence)
                        {
                            savingsBalence -= transferAmount;
                            checkingBalence += transferAmount;
                            std::cout << "New Savings Balence: $" << savingsBalence << std::endl;
                            std::cout << "New Checking Balence: $" << checkingBalence << std::endl << std::endl;
                        }  
                        else 
                        {
                            std::cout << "Insufficient funds. Back to Main Menu" << std::endl << std::endl;
                        }
                    }
                    else
                    {
                        system("clear");
                        std::cout << "Invalid Option. Back to Main Menu" << std::endl << std::endl;
                    }
                    break;
                
                    case 5:
                    return 0;
                    break;
                }
            }while(isTrue = false);
        }   
        else 
        {
            std::cout << "Incorrect pin!" << std::endl;
            std::cout << "Please Enter Pin: ";
            std::cin >> pin;
            std::cout << std::endl;
        }
        
    }while(mainOption != 5); 
}            
                
                
                
                
                
                
                
                
                
            


