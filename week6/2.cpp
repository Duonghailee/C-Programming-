#include <iostream>
using namespace std;
int main(void)
{
    FILE *opening = fopen("int.s", "r");
    int num1, num2, num3, num4, sum;
    if (opening == NULL)
    {
        cout << "Fil not found" << endl;
    }
    fscanf(opening, "%d %d %d %d", &num1, &num2, &num3, &num4);
    sum = num1 + num2 + num3 + num4;
    fclose(opening);
    printf("Numbers in file int.s are:\n%d, %d, %d and %d\n\n", num1, num2, num3, num4);
    printf("Sum of integers is %d\n", sum);
    return 0;
}