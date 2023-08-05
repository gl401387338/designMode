/*
 * @Author: gl401387338@gmail.com gl5644838
 * @Date: 2023-08-05 15:41:07
 * @LastEditors: gl401387338@gmail.com gl5644838
 * @LastEditTime: 2023-08-05 16:28:23
 * @FilePath: \designMode\exercise\2.strategy.cpp
 * @Description: <get salary>
 * 
 * Copyright (c) 2023 by 毛利的野望, All Rights Reserved. 
 */
// ctrl+win+i
#include <iostream>

class Company
{
public:
    virtual double sendSalary() = 0;
};

class Tencent : public Company
{
public:
    double sendSalary() override
    {
        double curMonthSalary = 30000;
        return curMonthSalary;
    }
};

class Ali : public Company
{
public:
    double sendSalary() override
    {
        double curMonthSalary = 35000;
        return curMonthSalary;
    } 
};

class Kingsoft : public Company
{
public:
    double sendSalary() override
    {
        double curMonthSalary = 20000;
        return curMonthSalary;
    } 
};

class SalaryManager
{
public:
    void workCompany(Company* cpn)
    {
        curCompany = cpn;
    }

    double salaryDay()
    {
        return curCompany->sendSalary();
    }

private:
    Company* curCompany;
};


int main()
{
    SalaryManager mySalary;
    mySalary.workCompany(new Kingsoft());
    std::cout << "今天发工资：" << mySalary.salaryDay() << std::endl;

    mySalary.workCompany(new Ali());
    std::cout << "今天发工资：" << mySalary.salaryDay() << std::endl;

    mySalary.workCompany(new Tencent());
    std::cout << "今天发工资：" << mySalary.salaryDay() << std::endl;

    system("pause");
    return 0;
}