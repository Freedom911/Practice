//Const Variable ensures that value cant be changed.
//const variable or functions can be evaluated at compile or run time
#include <iostream>

int main()
{
    //1.const variable
    const int h = 300; 

    //2.const variable as pointer

    //2a. Pointer to const variable
    int x {10};
    int val { 500};
    const int *j = &x;  //j is a pointer to int of const type
    
    x = 34;
    j++; //we can mmodify j
    //(*j) = 100;//we cant modify x via j as j thinks x is const
    std::cout << x << " " << *j << "\n";

    j = &val; //allowed

    //2b. Const pointer to variable

    //j is const pointer to int
    //we wontbe able to modify j
    int* const cp = &x;
    *cp = 500; // allowed
    //cp++;//notallowed

    //cp = &val;//not allowd
    std::cout << *cp << "\n";

    //2c. Const pointer to const variable
    const int * const ccp = &x;

    x = 123; //allowed
    //ccp++;not allowed
    //*ccp = 33;not allowed

    std::cout << x << " " << *ccp << "\n";

}
