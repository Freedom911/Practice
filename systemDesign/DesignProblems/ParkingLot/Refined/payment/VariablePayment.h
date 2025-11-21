#pragma once

#include "PaymentStrategy.h"
#include <sstream>
#include <cmath>

class VariablePayment: public PaymentStrategy
{
    public:
    VariablePayment()
    {
        m_baseFees = 50;
    }
    void CalculateCost(TokenDetails &details) 
    {
        double totalHours = GetHourDuration(details.InTime,details.OutTime);

        if(totalHours < 1)
        {
            details.TotalPayment = std::round(m_baseFees);
        }
        else
        {
            details.TotalPayment = std::round(totalHours * m_baseFees);
        }
    }

    private:
    double TimeToHours(const std::string &time)
    {
        double hours,minutes;
        char colon;
        std::stringstream ss(time);
        ss >> hours >> colon >> minutes;
        return hours + (minutes / 60.0);
    }
    double GetHourDuration(std::string time1,std::string time2)
    {
        double hour1 = TimeToHours(time1);
        double hour2 = TimeToHours(time2);
        return hour2 - hour1;//
    }

    int m_baseFees;


};
