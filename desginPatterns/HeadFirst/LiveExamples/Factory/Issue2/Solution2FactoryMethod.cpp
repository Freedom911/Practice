// Factory Method to the Rescue
// and we derive classes from the ChallanMainMenu
// Basically we make an interface and let subclass decide which product to initialize
//the solution talks about controlling that basically it gives the freedom of choosing which object to create
//but the overall process is same as it only abstracts the part which is changing


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

//-------------------------------------CREATOR--------------------------------------
class ChallanMainMenu
{

public:
    void OnClose()
    {
        // this->hide();
        delete this;
    }

    virtual BaseScreen *GetBaseScreen(std::string clickLabel) = 0;
    void PreviewPrintScreen(std::string clickLabel)
    {
        BaseScreen *baseScreen = GetBaseScreen(clickLabel); //this is abstract
        //The order is ensured
        baseScreen->SetChallanIDs({1, 2, 3, 4, 5});
        baseScreen->Show();
        baseScreen->Print();
    }

    // other functions

};

// CONCRETE CREATOR -------------------------------------------------------------
class AHDChallanMainMenu : public ChallanMainMenu
{
    public:
     BaseScreen  *GetBaseScreen(std::string clickLabel) override
    {
        BaseScreen *baseScreen = nullptr;
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

        return nullptr;
    }
};

class VIZChallanMainMenu : public ChallanMainMenu
{
    public:
     BaseScreen  *GetBaseScreen(std::string clickLabel) override
    {
        BaseScreen *baseScreen = nullptr;
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

        return nullptr;
    }
};

class VADChallanMainMenu : public ChallanMainMenu
{
    public:
     BaseScreen  *GetBaseScreen(std::string clickLabel) override
    {
        BaseScreen *baseScreen = nullptr;
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

        return nullptr;
    }
};



//Elegant Solution each concrete creator handles specfic concrete product. Very GOod we are only encapuslating the varying part 
//that is the varying function getBaseScren
int main()
{
#if 1
    ChallanMainMenu *menu = new AHDChallanMainMenu();
#endif
    menu->PreviewPrintScreen("HISTORY");
}