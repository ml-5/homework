/**26. The prefix is should be used for boolean variables and methods.

26. ��������/����������Ӧʹ��ǰ׺��is��
**/
#include <iostream> 
int main()
{
    bool isAlpha;
    isAlpha = false;
    if (!isAlpha)
    {
        std::cout << "isAlpha=" << isAlpha << std::endl;
        std::cout << std::boolalpha << "isAlpha=" << isAlpha << std::endl;
    }
    return 0;
}