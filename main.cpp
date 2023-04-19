#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>

#define MONTHLY_EXTRA 0//18000//100000//30000//500000 //1000000//1500000 // 1000000//400000//4500//220000//400000
#define UNTIL_MONTH 240
#define SINCE_MONTH 0
#define CREDIT 33720000
#define YEARLY_PERCENT 13.3
#define CREDIT_MONTHS 240

std::ofstream fout;
const std::string PATH = "Monthly report.txt";
class Loan {
public:
    Loan(double Credit, double Percent, double M)
    {
        fout.open(PATH);
        if (!fout.is_open()) {
            std::cout << "Error Path\n";
        }
        _S
            = Credit;
        _P = (Percent / 12) / 100;
        _N = M;

        loan_money = Credit;
        loan_yr_percent = Percent;
        loan_months = M;

        CalcX();
    }
    ~Loan() {
        fout.close();
    }

    double GetP()
    {
        return _P;
    }
    double GetRest()
    {
        return _S;
    }

    double GetMonths()
    {
        return _N;
    }

    double GetMonthlyPaid()
    {
        return _X;
    }

    void Print()
    {
        std::cout << "Main Money   - " << (int)_S << "\n";
        fout << "Main Money   - " << (int)_S << "\n";
        std::cout            << "Loan Monthly - " << _X << "\n";
        fout << "Loan Monthly - " << _X << "\n";
        std::cout << "Monthly debt - " << _monthly_debt << "\n";
        fout << "Monthly debt - " << _monthly_debt << "\n";
    }

    void CalcMonthlyDebt()
    {
        _monthly_debt = _S * _P;
        // debt_sum += _monthly_debt;
    }

    void CalcDebtSum()
    {
        debt_sum += _monthly_debt;
    }

    void DecrMainMoney()
    {
        _S -= _X - _monthly_debt;
    }

    void PayMainMoney(double mny)
    {
        std::cout << "main\n";
        _S -= mny;
    }

    double GetDebtSum()
    {
        return debt_sum;
    }

private:
    void CalcX()
    {
        _X = _S * (_P + (_P / (pow((1 + _P), _N) - 1)));
    }
    double _P = 0;
    double _S = 0;
    double _N = 0;
    double _X = 0;

    double _monthly_debt = 0;

    double loan_money = 0;
    double loan_yr_percent = 0;
    double loan_months = 0;

    double debt_sum = 0;
};

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

int main()
{

    double loan_money = CREDIT;
    double loan_yr_percent = YEARLY_PERCENT;
    double loan_months = CREDIT_MONTHS;
    double extra_money = MONTHLY_EXTRA;
    //UserInput(loan_money, loan_yr_percent, loan_months, extra_money);
    Loan loan(loan_money, loan_yr_percent, loan_months);
    float last_month = 0;
    loan.CalcMonthlyDebt();
    loan.Print();


    for (int i = 0; loan.GetRest() >= loan.GetMonthlyPaid(); ++i) {
        std::cout << "Month - " << i + 1 << "\n";
        fout << "Month - " << i + 1 << "\n";
        if (i == 0) {
            //loan.PayMainMoney(6000000);
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
    fout << "After    " << (last_month / 12) << " years\n";
    fout << "Debt Sum returned to bank " << (int)loan.GetDebtSum() << " AMD\n";

    return 0;
}
