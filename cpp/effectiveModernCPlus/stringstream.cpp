//Stringstream allows to read from a string as it was stream
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string s = "chal baz ki chali yaha na koi chal";
    std::stringstream ss(s);
    std::string buf;
    while(ss >> buf)
    {
        std::cout << buf << ",";
    }

    //splitting
    std::string str = "aaj;utha;ke;le;chalbaz;ko;kaal";
    std::stringstream sstream(str);

    std::vector<std::string> tokens;

    while(std::getline(sstream,buf,';'))
    {
        tokens.push_back(buf);
    }
    std::cout << "\n Token Content = ";
    std::for_each(tokens.begin(),tokens.end(),[](const std::string &elem){
        std::cout << elem << ",";
    });

    std::cout << "\n";



}
