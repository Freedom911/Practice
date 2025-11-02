// Now Moving To Issue Number 2
// Our Product was very successful and govt of many states started noticing
// Ahmedabad,ViZag,Vadodora all wanted our ANPR challan system
// The Issue was Each City had their own Format of pdf

#include <iostream>
#include <vector>

//-------------------------------------PRODUCTS------------------------------------
class BaseScreen
{
protected:
    std::vector<int> m_challanIDs;

public:
    virtual void Show() = 0;

    void SetChallanIDs(const std::vector<int> &challanIds)
    {
        m_challanIDs = challanIds;
    }

    void Print()
    {
        std::cout << "\n Printing \n";
    }
};

class AHDChallan : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== AHD Challan ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

class VIZChallan : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== VIZ Challan ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

class VADChallan : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== VAD Challan ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

class AHDReport : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== AHD Report ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

class VIZReport : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== VIZ Report ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

class VADReport : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== VAD Report ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

class AHDHistory : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== AHD History ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

class VIZHistory : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== VIZ History ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

class VADHistory : public BaseScreen
{
public:
    virtual void Show() override
    {
        for (int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== VAD History ->" << m_challanIDs[i] << " ======= \n";
        }
    }
};

//-------------------------------------PRODUCTS------------------------------------

//-------------------------------------SIMPLEFACTORY-------------------------------
class SimpleFactory
{
public:
    //SO MUCH THINGY and adding new  cities would require more if else
    BaseScreen *GetBaseScreen(std::string city, std::string clickLabel)
    {
        if (city == "AHD")
        {
            if (clickLabel == "CHALLAN")
            {
                return new AHDChallan();
            }
            else if (clickLabel == "REPORT")
            {
                return new AHDReport();
            }
            else if (clickLabel == "HISTORY")
            {
                return new AHDHistory();
            }
        }
        else if (city == "VAD")
        {
            if (clickLabel == "CHALLAN")
            {
                return new VADChallan();
            }
            else if (clickLabel == "REPORT")
            {
                return new VADReport();
            }
            else if (clickLabel == "HISTORY")
            {
                return new VADHistory();
            }
        }

        else if (city == "VIZ")
        {
            if (clickLabel == "CHALLAN")
            {
                return new VIZChallan();
            }
            else if (clickLabel == "REPORT")
            {
                return new VIZReport();
            }
            else if (clickLabel == "HISTORY")
            {
                return new VIZHistory();
            }
        }

        return nullptr;
    }
};

//-------------------------------------CLIENT--------------------------------------
class ChallanMainMenu
{

public:
    ChallanMainMenu(std::string state)
    {
        m_state = state;
    }
    void OnClose()
    {
        // this->hide();
        delete this;
    }

    void PreviewPrintScreen(std::string clickLabel)
    {
        BaseScreen *baseScreen = factory.GetBaseScreen(m_state,clickLabel);
        if (baseScreen == nullptr)
        {
            std::cout << "\n Cannot Open Preview Print Screen \n";
            return;
        }
        baseScreen->SetChallanIDs({1, 2, 3, 4, 5});
        baseScreen->Show();
        baseScreen->Print();
    }

    // other functions
private:
    SimpleFactory factory;
    std::string m_state;
};

int main()
{
    ChallanMainMenu menu("AHD");
    menu.PreviewPrintScreen("HISTORY");
}