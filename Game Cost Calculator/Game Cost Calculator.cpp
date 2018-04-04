/*Game Cost Calculator
Author: Jamie Pollock
Date: 7/8/2016  3:51 PM Eastern Time
Edited: 7/9/2016 8:11 AM Eastern Time
Edited 2: 7/29/2016 11:05 AM Eastern Time*/

#include <iomanip> // Allows the output of monetary values to contain only TWO (2) decimal points.
#include <istream>
#include <string>
#include <stdlib.h> // Allows program to clear screen.
#include <fstream> // Allows writing to a text file.
#include <iostream>

using namespace std;

int main()
{

// Variables
    string gameTitle, gameXtra1, gameXtra2;
    char insuranceAnswer, saveFileAnswer;
    float fullPrice, deposit, gameXtraCost1, gameXtraCost2, insurance, salesTax, currentBalance, remainingBalance, spendingMoney;
    float fullPriceWTax, xtra1WTax, xtra2WTax, insuranceWTax, totalPrice, totalTax, totalPriceWTax, priceWDeposit, priceWDepWTax;

// Program code begins here.
    cout << "Please enter the TITLE of the game you would like to buy." << endl;
    getline(cin, gameTitle);
    cout << endl;

    cout << "Please enter the full cost of " << gameTitle << " (WITHOUT tax)." << endl;
    cout << "$";
    cin >> fullPrice;
    cout << endl;

    cout << "Please enter the cost of the DEPOSIT placed to secure your copy of the game." << endl;
    cout << "$";
    cin >> deposit;
    cout << endl;

    cout << "Please enter the FIRST type of extra content you will be purchasing." << endl;
    cin.ignore();
    getline(cin, gameXtra1);
    cout << endl;

    cout << "Please enter the cost of " << gameXtra1 << "." << endl;
    cout << "$";
    cin >> gameXtraCost1;
    cout << endl;

    cout << "Please enter the SECOND type of extra content you will be purchasing." << endl;
    cin.ignore();
    getline(cin, gameXtra2);
    cout << endl;

    cout << "Please enter the cost of " << gameXtra2 << "." << endl;
    cout << "$";
    cin >> gameXtraCost2;
    cout << endl;

    cout << "Will you be purchasing insurance for " << gameTitle << " ?" << endl;
    cout << "Please type (Y) or (y) for (YES) or (N) or (n) for (NO)." << endl;
    cin >> insuranceAnswer;
        if (insuranceAnswer == 'Y' || 'y')
        {
            insuranceAnswer == 'y';
        }
        if (insuranceAnswer == 'N' || 'n')
        {
            insuranceAnswer == 'n';
        }
        switch (insuranceAnswer)
        {
        case 'y':
            {
                cout << endl;
                cout << "Please enter the cost of the insurance for the " << gameTitle << " game." << endl;
                cout << "$";
                cin >> insurance;
                cout << endl;
                break;
            }
        case 'n':
            {
                cout << endl;
                cout << "You have chosen NOT to purchase insurance for the " << gameTitle << " game." << endl;
                cout << endl;
                insurance = 0;
                break;
            }
        default:
            {
                cout << endl;
                cout << "Invalid answer. Please try again." << endl;
                cin >> insuranceAnswer;
            }
        }

    cout << "Please enter the SALES TAX for your state (WITHOUT % SYMBOL)." << endl;
    cin >> salesTax;
    cout << endl;

    cout << "Please enter the current balance you have saved for the " << gameTitle << " game." << endl;
    cout << "$";
    cin >> currentBalance;
    cout << endl;

    cout << "We will now calculate your remaining necessary balance or, if you have reached the required total amount, the amount of spending money you have left." << endl;
    cout << endl;

    // The following prevents the program from automatically clearing the screen.
    do
    {
        cout << '\n' << "Press any key to continue.";
        cin.get();
    }
    while (cin.get() != '\n');


    system("cls");


// This prevents the program from showing more than 2 decimal points in the output.
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout.precision(2);

// Necessary equations for the final output.
    totalPrice = (((fullPrice-deposit)+insurance) + (gameXtraCost1 + gameXtraCost2));
    priceWDeposit = (fullPrice - deposit);

    salesTax = (salesTax/100);

    fullPriceWTax = ((fullPrice*salesTax) + fullPrice);
    xtra1WTax = ((gameXtraCost1*salesTax) + gameXtraCost1);
    xtra2WTax = ((gameXtraCost2*salesTax) + gameXtraCost2);
    insuranceWTax = ((insurance*salesTax) + insurance);

    totalPriceWTax = (((fullPriceWTax-deposit)+insuranceWTax) + (xtra1WTax + xtra2WTax));
    totalTax = (totalPriceWTax-totalPrice);
    priceWDepWTax = (fullPriceWTax - deposit);

    remainingBalance = (totalPriceWTax - currentBalance);
    spendingMoney = (currentBalance - totalPriceWTax);

    cout << "WITHOUT SALES TAX:" << endl;
    cout << endl;
    cout << gameTitle << ": $" << fullPrice << endl;
    cout << "Deposit: -$" << deposit << endl;
    cout << "Price After Deposit: $" << priceWDeposit << endl;
    cout << gameXtra1 << ": $" << gameXtraCost1 << endl;
    cout << gameXtra2 << ": $" << gameXtraCost2 << endl;

    switch (insuranceAnswer)
    {
    case 'y':
        {
            cout << "Game Insurance: $" << insurance << endl;
            break;
        }
    case 'n':
        {
            break;
        }
    default:
        {
            break;
        }
    }

    cout << "____________________________________________________" << endl;
    cout << "TOTAL PRICE: $" << totalPrice << endl;
    cout << "====================================================" << endl;
    cout << endl;

    cout << "WITH SALES TAX:" << endl;
    cout << endl;
    cout << gameTitle << ": $" << fullPriceWTax << endl;
    cout << "Deposit: -$" << deposit << endl;
    cout << "Price After Deposit: $" << priceWDepWTax << endl;
    cout << gameXtra1 << ": $" << xtra1WTax << endl;
    cout << gameXtra2 << ": $" << xtra2WTax << endl;
    switch (insuranceAnswer)
    {
    case 'y':
        {
            cout << "Game Insurance: $" << insuranceWTax << endl;
            break;
        }
    case 'n':
        {
            break;
        }
    default:
        {
            break;
        }
    }
    cout << "Tax: $" << totalTax << endl;
    cout << "____________________________________________________" << endl;
    cout << "TOTAL PRICE: $" << totalPriceWTax << endl;
    cout << "====================================================" << endl;
    cout << endl;

    cout << "Your current balance:" << endl;
    cout << "$" << currentBalance << endl;
    cout << endl;

    if (currentBalance >= totalPriceWTax)
    {
        cout << "You have reached the required amount to purchase " << gameTitle << " and the extra content!" << endl;
        cout << "Spending Money: $" << spendingMoney << endl;
        cout << endl;
    }
    else if (currentBalance <= totalPriceWTax)
    {
        cout << "REMAINING FUNDS REQUIRED: $" << remainingBalance << endl;
        cout << endl;
    }

    cout << "Would you like to save this information to a file?" << endl;
    cout << "Please type (Y) or (y) for (YES) or (N) or (n) for (NO)." << endl;
    cin >> saveFileAnswer;
        if (saveFileAnswer == 'Y' || 'y')
        {
            saveFileAnswer == 'y';
        }
        if (saveFileAnswer == 'N' || 'n')
        {
            saveFileAnswer == 'n';
        }
        switch (saveFileAnswer)
        {
        case 'y':
            {
                cout << "Writing to file..." << endl << endl;
                ofstream SaveFile;
                SaveFile.open("Game Cost Calculator.txt");
                        SaveFile << "WITHOUT SALES TAX:" << endl;
                        SaveFile << endl;
                        SaveFile << gameTitle << ": $" << fullPrice << endl;
                        SaveFile << "Deposit: -$" << deposit << endl;
                        SaveFile << "Price After Deposit: $" << priceWDeposit << endl;
                        SaveFile << gameXtra1 << ": $" << gameXtraCost1 << endl;
                        SaveFile << gameXtra2 << ": $" << gameXtraCost2 << endl;
                            switch (insuranceAnswer)
                            {
                            case 'y':
                                {
                                SaveFile << "Game Insurance: $" << insurance << endl;
                                break;
                                }
                            case 'n':
                                {
                                break;
                                }
                            default:
                                {
                                break;
                                }
                            }
                        SaveFile << "____________________________________________________" << endl;
                        SaveFile << "TOTAL PRICE: $" << totalPrice << endl;
                        SaveFile << "====================================================" << endl;
                        SaveFile << endl;

                        SaveFile << "WITH SALES TAX:" << endl;
                        SaveFile << endl;
                        SaveFile << gameTitle << ": $" << fullPriceWTax << endl;
                        SaveFile << "Deposit: -$" << deposit << endl;
                        SaveFile << "Price After Deposit: $" << priceWDepWTax << endl;
                        SaveFile << gameXtra1 << ": $" << xtra1WTax << endl;
                        SaveFile << gameXtra2 << ": $" << xtra2WTax << endl;
                            switch (insuranceAnswer)
                            {
                            case 'y':
                            {
                                SaveFile << "Game Insurance: $" << insuranceWTax << endl;
                                break;
                            }
                            case 'n':
                            {
                                break;
                            }
                            default:
                            {
                                break;
                            }
                            }
                        SaveFile << "Tax: $" << totalTax << endl;
                        SaveFile << "____________________________________________________" << endl;
                        SaveFile << "TOTAL PRICE: $" << totalPriceWTax << endl;
                        SaveFile << "====================================================" << endl;
                        SaveFile << endl;

                        SaveFile << "Your current balance:" << endl;
                        SaveFile << "$" << currentBalance << endl;
                        SaveFile << endl;

                        if (currentBalance >= totalPriceWTax)
                        {
                        SaveFile << "You have reached the required amount to purchase " << gameTitle << " and the extra content!" << endl;
                        SaveFile << "Spending Money: $" << spendingMoney << endl;
                        SaveFile << endl;
                        }
                        else if (currentBalance <= totalPriceWTax)
                        {
                        SaveFile << "REMAINING FUNDS REQUIRED: $" << remainingBalance << endl;
                        SaveFile << endl;
                        }
                        SaveFile.close();
                        cout << "Done! Your file \"Game Cost Calculator\" is saved!" << endl;
                        break;
            }
        case 'n':
            {
                cout << "You have chosen NOT to save this information." << endl << endl;
                break;
            }
        default:
            {
                cout << "Invalid answer. Please try again." << endl;
                cin >> insuranceAnswer;
            }
        }


// The following prevents the program from automatically closing its window before the user can see the output.
    do
    {
        cout << '\n' << "Press any key to exit the program.";
        cin.get();
    }
    while (cin.get() != '\n');

    return 0;
}
