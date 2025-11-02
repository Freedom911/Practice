//Lets Start with the Issue
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

//-------------------------------------CLIENT--------------------------------------
class ChallanMainMenu
{

    public:
    void OnClose()
    {
        //this->hide();
        delete this;
    }

    //Issue with this is we are having new here and if we want to add more screens then we have to 
    //edit the code thus the code is open for modification as well
    //Issue is if open the base screen elsewhere then also we have to check for conditions
    //PRINCIPLE WE BREAK oF SOLID is O principle
    void PreviewPrintScreen(std::string clickLabel)
    {
        BaseScreen *baseScreen = nullptr;
        if(clickLabel == "CHALLAN")
        {
            baseScreen = new Challan();
        }
        else if(clickLabel == "REPORT")
        {
            baseScreen = new Report();
        }
        else if(clickLabel == "HISTORY")
        {
            baseScreen = new History();
        }

        baseScreen->SetChallanIDs({1,2,3,4,5});
        baseScreen->Show();
        baseScreen->Print();
    }

    //other functions
};


int main()
{
    ChallanMainMenu menu;
    menu.PreviewPrintScreen("HISTORY");
}