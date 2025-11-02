//Lets Move To Solution No 1
//I Srajan Along with Akhilesh Sir and Anoop discussed and brain stormed
//After Thinking Throughly I moved the New object Creation to a new Class
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


class Challan : public BaseScreen
{
    public:
    virtual void Show() override
    {
        for(int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== Challan ->" << m_challanIDs[i] << " ======= \n";
        }
    }



};

class Report : public BaseScreen
{
    public:
    virtual void Show() override
    {
        for(int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== Report ->" << m_challanIDs[i] << " ======= \n";
        }
    }

};

class History:public BaseScreen
{
    public:
    virtual void Show() override
    {
        for(int i = 0; i < m_challanIDs.size(); i++)
        {
            std::cout << "\n  ==== History ->" << m_challanIDs[i] << " ======= \n";
        }
    }

};

//-------------------------------------PRODUCTS------------------------------------


//-------------------------------------SIMPLEFACTORY-------------------------------
//although it seems we are just moving new to another function which is correct
//but now it is seperated we dont need to change multiple places
class SimpleFactory
{
    public:
    BaseScreen *GetBaseScreen(std::string clickLabel)
    {
        if(clickLabel == "CHALLAN")
        {
            return new Challan();
        }
        else if(clickLabel == "REPORT")
        {
            return  new Report();
        }
        else if(clickLabel == "HISTORY")
        {
            return new History();
        }

        return nullptr;
    }
};

//-------------------------------------CLIENT--------------------------------------
class ChallanMainMenu
{

    public:
    void OnClose()
    {
        //this->hide();
        delete this;
    }


    //Now our client code is not needing new and it can forget about specific class. Already Dependency Inversion
    //our high level componentthat is challan Main menu is depending on abstract that is base screen and not lower
    void PreviewPrintScreen(std::string clickLabel)
    {
        BaseScreen *baseScreen = factory.GetBaseScreen(clickLabel);
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
    SimpleFactory factory;
};


int main()
{
    ChallanMainMenu menu;
    menu.PreviewPrintScreen("HISTORY");
}