#pragma once

#include <fstream>

class Loan {
public:

    void Export();
    void ExportMSG(std::string msg);
    Loan(double Credit, double Percent, double M, std::string loan_name);
    ~Loan();
    double GetP();
    double GetRest();
    double GetMonths();
    double GetMonthlyPaid();
    void Print();
    void CalcMonthlyDebt();
    void CalcDebtSum();
    void DecrMainMoney();
    void PayMainMoney(double mny);
    double GetLoanAmount();
    double GetMonthlyDebt();
    double GetDebtSum();
    

private:
    void CalcX();
    double _monthly_percent = 0;
    double _loan_amount = 0;
    double _months = 0;
    double _monthly_paid = 0;
    double _monthly_debt = 0;
    double loan_money = 0;
    double loan_yr_percent = 0;
    double loan_months = 0;
    double debt_sum = 0;
    std::string _loan_name = "";
    std::ofstream fout;
};





//std::ofstream Loan::fout;