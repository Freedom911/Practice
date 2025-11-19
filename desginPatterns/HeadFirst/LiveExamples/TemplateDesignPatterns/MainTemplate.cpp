#include <iostream>


class MainMenuTemplate
{
    public:

    void OpenChallan()
    {
        std::string str = CreateChallan();
        OpenChallanScreen(str);
        PrintChallan(str);
    }

    //COmmon Method
    void OpenChallanScreen(std::string str)
    {
        std::cout << "\n OPENING Challan Screen =";
    }

    //Only these two virtual
    virtual std::string CreateChallan() = 0;
    virtual void PrintChallan(std::string str) = 0;
};


class AHDTemplate : public MainMenuTemplate
{
    public:
    std::string CreateChallan() override
    {
        return "PDF";
    }
    void PrintChallan(std::string str) override
    {
        std::cout << "PDF = " << str ;
    }
};


class VIZTemplate : public MainMenuTemplate

{
    public:
    std::string CreateChallan() override
    {
        return "EXCEL";
    }
    void PrintChallan(std::string str) override
    {
        std::cout << "EXCEL  = " << str ;
    }
};



int main()
{
    std::cout << "\n ENTER 1.AHD or 2.VIZ = ";
    int i;
    std::cin >> i;
    MainMenuTemplate *menu;
    if(i == 1)
    {
        menu = new AHDTemplate();
        menu->OpenChallan();
    }
    else
    {
        menu = new VIZTemplate();
        menu->OpenChallan();
    }
}

