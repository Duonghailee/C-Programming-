#include <iostream>
using namespace std;

int main()
{
    FILE *fp;
    fp = fopen("hello.usr", "w");
    if (fp != NULL)
    {
        fputs("Hello world", fp);
        fclose(fp);
        cout << "Writing to a file managed.\nThe program is closed." << endl;
    }
    return 0;
}