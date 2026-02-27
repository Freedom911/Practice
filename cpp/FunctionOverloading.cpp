    //What if we want to restrict a function to take only int
    //because implicit conversion may happen
    #include <iostream>

    // This function will take precedence for arguments of type int
    void printInt(int x)
    {
        std::cout << x << '\n';
    }

    // This function template will take precedence for arguments of other types
    // Since this function template is deleted, calls to it will halt compilation
    template <typename T>
    void printInt(T x) = delete;

    int main()
    {
        printInt(97);   // okay
        //printInt('a');  // compile error
        //printInt(true); // compile error

        return 0;
    }