#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#define MONTHLY_EXTRA 53000 // 18000//100000//30000//500000 //1000000//1500000 // 1000000//400000//4500//220000//400000
#define UNTIL_MONTH 240
#define SINCE_MONTH 0
#define CREDIT 1205000
#define YEARLY_PERCENT 21.5
#define CREDIT_MONTHS 36
#define LOAN_NAME "TAB"

#include "Loan.h"

void UserInput(double& loan_money, double& loan_yr_percent, double& loan_months, double& extra_money)
{
    std::cout << "Enter loan amount\n";
    std::cin >> loan_money;
    std::cout << "Enter yearly percent\n";
    std::cin >> loan_yr_percent;
    std::cout << "Enter term of loan in months\n";
    std::cin >> loan_months;
    std::cout << "Enter extra money size if avalaible if not entern 0\n";
    std::cin >> extra_money;
}



void Scheduler()
{
    std::stringstream out;
    Loan loan(CREDIT, YEARLY_PERCENT, CREDIT_MONTHS, LOAN_NAME);
    int last_month = 0;

    for (int i = 1; loan.GetRest() > loan.GetMonthlyPaid(); ++i) {

        out << "Month - " << i << "\n";
        std::cout << out.str();
        loan.ExportMSG(out.str());
        loan.Print();
        loan.Export();
        if (i < UNTIL_MONTH && i >= SINCE_MONTH) {
            loan.PayMainMoney(MONTHLY_EXTRA);
        }
        loan.DecrMainMoney();
        last_month = i;
        out.str("");
    }
    out << "After    " << (last_month / 12) << " years " << (last_month % 12) << " month\n";
    std::cout << out.str();
    loan.ExportMSG(out.str());
    out.str("");


    out << "Debt Sum returned to bank " << (int)loan.GetDebtSum() << "\n";
    std::cout << out.str();
    loan.ExportMSG(out.str());
}

void Scheduler2()
{

    double loan_money = CREDIT;
    double loan_yr_percent = YEARLY_PERCENT;
    double loan_months = CREDIT_MONTHS;
    double extra_money = MONTHLY_EXTRA;
    // UserInput(loan_money, loan_yr_percent, loan_months, extra_money);
    Loan loan(loan_money, loan_yr_percent, loan_months, LOAN_NAME);
    float last_month = 0;
    // loan.CalcMonthlyDebt();
    loan.Print();

    for (int i = 0; loan.GetRest() >= loan.GetMonthlyPaid(); ++i) {
        std::cout << "Month - " << i + 1 << "\n";
        if (i == 0) {
            // loan.PayMainMoney(6000000);
        }
        if (i < UNTIL_MONTH && i >= SINCE_MONTH) {
            loan.PayMainMoney(extra_money);
        }
        loan.CalcMonthlyDebt();
        loan.CalcDebtSum();
        loan.DecrMainMoney();
        loan.Print();

        last_month = i;
    }

    std::cout << "After    " << (last_month / 12) << " years\n";
    std::cout << "Debt Sum returned to bank " << (int)loan.GetDebtSum() << "\n";
    // fout << "After    " << (last_month / 12) << " years\n";
    // fout << "Debt Sum returned to bank " << (int)loan.GetDebtSum() << " AMD\n";
    // Loan::Loan_Destruct();
}

int main()
{
    Scheduler();
    return 0;
}
