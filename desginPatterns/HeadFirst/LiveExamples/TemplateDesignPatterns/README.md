## Template Design Pattern
Template Design Pattern Defines a skeleton of an algorithm and lets subclass decide some of the steps
to vary unlike Strategy Pattern which lets sublclass allows whole algorithm to vary


### Difference between Template and Strategy
Template Pattern Uses Inheritance but Strategy Pattern uses composition. With Strategy we can change
functionality at runtime unlike template which happens compile time . 


Example
We Take Example of our challan Screen Main Menu. Subhash Chugh Sir Came and told me that
Like AHD we will be having new site which is VIJ but in VIJ on clicking open challan the functionality
was different
like for AHD we had
1. Create Challan PDF
2. Open Challan Screen
3. Print PDF

for VIZ we want to have Excel so
1. Create Challan Excel
2. Open CHallan SCreen -> Same Step
3. Print Excel

So Nikhil said Let me try I said ok he used strategy pattern like this

He Declared MainMenuStrategy and made pure virtual function

class MainMenuStragtey
{
    public:
    virtual void OpenChallan() = 0;
}

class AHDMainMenu and VIZ implemented the function in their own class.

Now I told this could be done better so I presented solution using TemplateDesignPattern

I used MainMenuTemplate
{
    public:

    //Fix the algo skeleton
    void OpenChallan()
    {
        str = CreateChallan();
        OpenChallanScreen(str);
        PrintChallan(str);
    }

    void OpenChallanScreen(string)
    {
        ChallanScreen * screen = new CHallanScreen(string);
        screen->show();
    }

    //Only these two virtual
    virtual std::string CreateChallan() = 0;
    virtual void PrintChallan(std::String) = 0;
}

class AHDTemplate : MainMenuTemplate
{
    publlic:
    std::string CreateChallan() override
    {
        return "PDF";
    }
    void PrintChallan(string) override
    {
        printing string + pdf;
    }
};

class VIZTemplate :MainMenuTemplate
{
    publlic:
    std::string CreateChallan() override
    {
        return "EXCEL";
    }
    void PrintChallan(string) override
    {
        printing string excel;
    }
};

The benfit of this we can fix the algo structure and the code duplication is also reduced.

So I presented the solution to Anoop and Akhilesh they said welldone. I told nikhil deserves clapping
we both got 20 percent increment