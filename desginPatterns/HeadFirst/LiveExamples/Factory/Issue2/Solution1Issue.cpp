
//Moving to the issue.
//SUppose User make start using my factory class and skips other important fucntionality
//like it needs challan id to be displayed
//Then that is the issue 
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

//-------------------------------------SIMPLEFACTORIES-------------------------------
//although it seems we are just moving new to another function which is correct
//but now it is seperated we dont need to change multiple places
class SimpleFactory
{
    public:
    virtual BaseScreen *GetBaseScreen(std::string clickLabel) = 0;
};


class AHDFactory : public SimpleFactory
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


class VIZFactory : public SimpleFactory
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


class VADFactory : public SimpleFactory
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

//FACTORY END ---------------------------------------------------------------------


//-------------------------------------CLIENT--------------------------------------
class ChallanMainMenu
{

    public:
    ChallanMainMenu(SimpleFactory *Factory)
    {
        m_factory = Factory;
    }
    void OnClose()
    {
        //this->hide();
        delete this;
    }


    void PreviewPrintScreen(std::string clickLabel)
    {
        BaseScreen *baseScreen = m_factory->GetBaseScreen(clickLabel);
        if(baseScreen == nullptr)
        {
            std::cout << "\n Cannot Open Preview Print Screen \n";
            return;
        }
        baseScreen->SetChallanIDs({1,2,3,4,5});
        baseScreen->Show();
        baseScreen->Print();
    }

    //other functions
    private:
    SimpleFactory *m_factory;
};

class ChallanMainMenuDeceptive
{

    public:
    ChallanMainMenuDeceptive(SimpleFactory *Factory)
    {
        m_factory = Factory;
    }
    void OnClose()
    {
        //this->hide();
        delete this;
    }


    void PreviewPrintScreen(std::string clickLabel)
    {
        BaseScreen *baseScreen = m_factory->GetBaseScreen(clickLabel);
        if(baseScreen == nullptr)
        {
            std::cout << "\n Cannot Open Preview Print Screen \n";
            return;
        }
        //baseScreen->SetChallanIDs({1,2,3,4,5});
        baseScreen->Show();
        baseScreen->Print();
    }

    //other functions
    private:
    SimpleFactory *m_factory;
};


// CONCRETE CREATOR -------------------------------------------------------------


// CONCRETE CREATOR -------------------------------------------------------------

//Elegant Solution each concrete creator handles specfic concrete product. Very GOod
int main()
{
    AHDFactory ahdFactory;
#if 1
    ChallanMainMenu *menu = new ChallanMainMenu(&ahdFactory);
#endif
    menu->PreviewPrintScreen("HISTORY");
}