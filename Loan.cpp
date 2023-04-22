#include "Loan.h"
#include <cmath>
#include <iostream>

const std::string PATH = "Monthly report.txt";


 
Loan::Loan(double Credit, double Percent, double M, std::string loan_name)
{
    
    _loan_amount = Credit;
    _monthly_percent = (Percent / 12) / 100;
    _months = M;

    loan_money = Credit;
    loan_yr_percent = Percent;
    loan_months = M;
    _loan_name = loan_name;

    fout.open(_loan_name + ".txt");
    if (!fout.is_open()) {
        std::cout << "Error Path\n";
    }

    CalcX();
    CalcMonthlyDebt();
}
Loan::~Loan()
{
    fout.close();
}

double Loan::GetP()
{
    return _monthly_percent;
}
double Loan::GetRest()
{
    return _loan_amount;
}

double Loan::GetMonths()
{
    return _months;
}

double Loan::GetMonthlyPaid()
{
    return _monthly_paid;
}

void Loan::Export()
{
    fout << "Main Money   - " << (int)GetLoanAmount() << "\n";
    fout << "Loan Monthly - " << GetMonthlyPaid() << "\n";
    fout << "Monthly debt - " << GetMonthlyDebt() << "\n";
}

void Loan::ExportMSG(std::string msg) {
    fout << msg;
}

void Loan::Print()
{
    std::cout << "Main Money   - " << (int)_loan_amount << "\n";

    std::cout << "Loan Monthly - " << _monthly_paid << "\n";

    std::cout << "Monthly debt - " << _monthly_debt << "\n";
}



void Loan::CalcMonthlyDebt()
{
    _monthly_debt = _loan_amount * _monthly_percent;
    // debt_loan_amountum += _monthly_debt;
}

void Loan::CalcDebtSum()
{
    debt_sum += _monthly_debt;
}

double Loan::GetMonthlyDebt()
{
    return _monthly_debt;
}

void Loan::DecrMainMoney()
{
    CalcMonthlyDebt();
    CalcDebtSum();
    _loan_amount -= _monthly_paid - _monthly_debt;
}

double Loan::GetLoanAmount()
{
    return _loan_amount;
}

void Loan::PayMainMoney(double mny)
{
    // std::cout << "main\n";
    _loan_amount -= mny;
    //CalcMonthlyDebt();
    //CalcDebtSum();
}

double Loan::GetDebtSum()
{
    return debt_sum;
}

void Loan::CalcX()
{
    _monthly_paid = _loan_amount * (_monthly_percent + (_monthly_percent / (pow((1 + _monthly_percent), _months) - 1)));
}
