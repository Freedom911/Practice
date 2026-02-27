#include <iostream>

//Solution 1 using Stragey
class MainMenuStrategy
{
    public:
    virtual void OpenChallan() = 0;
};


class AHDMainMenuStrategy: public MainMenuStrategy
{
    public:
    void OpenChallan() override
    {
        std::string str = CreatePDF();
        OpenChallanScreen(str);
        PrintPDF(str);
    }

    private:
    std::string CreatePDF()
    {
        return "PDF + CHALLAN";
    }
    void OpenChallanScreen(std::string str)
    {
        std::cout << "\n OPENING CHALLAN SCREEN \n";
    }

    void PrintPDF(std::string str)
    {
        std::cout << "\n " << str << "\n";
    }
};


class VIZMainMenuStrategy: public MainMenuStrategy
{
    public:

    //Proiblem User may accidently Change the algo structure ----------------
    void OpenChallan() override
    {
        std::string str = CreateExcel();
        OpenChallanScreen(str);
        PrintExcel(str);
    }
    
    private:
    std::string CreateExcel()
    {
        return "Excel + CHALLAN";
    }
    //Code Duplicated is there----------------------------------------
    void OpenChallanScreen(std::string str)
    {
        std::cout << "\n OPENING CHALLAN SCREEN \n";
    }

    void PrintExcel(std::string str)
    {
        std::cout << "\n MICROSOFT EXCEL " << str << "\n";
    }
};


class MainMenu
{
    public:
    MainMenu(MainMenuStrategy *stra)
    {
        m_obj = stra;
    }
    void HandleOnClickChallanScreen()
    {
        m_obj->OpenChallan();
    }
    private:
    MainMenuStrategy * m_obj;
};

int main()
{
    std::cout << "\n ENTER 1.AHD or 2.VIZ = ";
    int i;
    std::cin >> i;
    MainMenuStrategy *strategy;
    if(i == 1)
    {
        strategy = new AHDMainMenuStrategy();
    }
    else
    {
        strategy = new VIZMainMenuStrategy();
    }

    MainMenu menu(strategy);
    menu.HandleOnClickChallanScreen();
}

