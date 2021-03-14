#pragma once
//Director Class Responisbe for asking builders for creating
//A Car

class TeslaDirector
{
  public:

    TeslaDirector();

    void setTeslaBuilder(class TeslaBuilder*builder);

    //Manufactures and return a final Product
    class TeslaCarProduct* manufactureCar();

  private:
    class TeslaBuilder *builder;

};
