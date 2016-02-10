#include <iostream>
#include <cmath>

using namespace std;

int get_curr_bit(int num, int whichBit)
{
    if (whichBit >= 0 && whichBit <= 8)
        return ( (num >> whichBit) & 1 );
    else
        return 0;
}

int check_bit_value(int firstBit, int secondBit){

    int bit = firstBit + secondBit;

    if(bit == 2){
        return 0;
    }

    return bit;
}

int binary_to_decimal(int n)
{
    int decimal = 0;
    int deg = 0;
    int digit;

    while (n!=0)
    {
        digit = n % 10;
        n /= 10;
        decimal += digit * pow(2,deg);
        ++deg;
    }

    return decimal;
}

int main()
{
    unsigned long number = binary_to_decimal(11010);

    for(int i = 0; i < 32; i++){
        int firstBit = get_curr_bit(number, 3);
        int secondBit = get_curr_bit(number, 6);

        int bit = check_bit_value(firstBit, secondBit);

        number = number << 1;

        if(bit != 0){
            number |= (1 << 0);
        }
    }

    cout << number << endl;
}
