#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    const char *arr[] = {"Robert", "John", "Julie", "Lora"};
    std::vector<std::string> v(arr, std::end(arr));
    vector<string>::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << v.size() << endl;
    return 0;
}
