#include <iostream>
#include <string>
#include <string_view>
/**
 * Copying String is expensive when we do
 * std::string s{"hello"} the program creates a c style char string
 * and then copies to string  which is expensive
 * string view provides a read only access to the string
 * Aviable from C++17 onwards
 * 
 * We could use constexpr with string view but not string
 */


 void printSV(std::string_view s)
 {
    std::cout << s << "\n";
 }

 int main()
 {
    std::string_vew s{"hello"};
    printSV(s);

    // Remove 1 character from the left side of the view
	s.remove_prefix(1);
   //the only way to reset the view is by reassigning the source string to it again.
	std::cout << s << '\n';
    s = "tello";
    printSV(s);
    std::string t{s};//can be done but not implicit
    /**
     * If the std::string reallocates memory in order to accommodate the new string data,
     *  it will return the memory used for the old string data back to the operating system.
     *  Since the std::string_view is still viewing the old string data, it is now dangling (pointing to a now-invalid object).
     */
    std::string_view st{t};//should be avoided . because if t is destroyed it is left dangling. better to do with c style string
    
 }