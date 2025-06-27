#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int c = get_cents();

    int q = calculate_quarters(c);
    c = c - q * 25;

    int d = calculate_dimes(c);
    c = c - d * 10;

    int n = calculate_nickels(c);
    c = c - n * 5;

    int p = calculate_pennies(c);
    c = c - p * 1;

    int coins = q + d + n + p;

    printf("%i\n", coins);
}

int get_cents(void)
{
    int c;
    do
    {
        c = get_int("Change owed: ");
    }
    while (c < 0);
    return c;
}

int calculate_quarters(int cents)
{

    int q = 0;
    while (cents >= 25)
    {
        q++;
        cents = cents - 25;
    }
    return q;
}

int calculate_dimes(int cents)
{
    int d = 0;
    while (cents >= 10)
    {
        d++;
        cents = cents - 10;
    }
    return d;
}

int calculate_nickels(int cents)
{
    int n = 0;
    while (cents >= 5)
    {
        n++;
        cents = cents - 5;
    }
    return n;
}

int calculate_pennies(int cents)
{
    int p = 0;
    while (cents >= 1)
    {
        p++;
        cents = cents - 1;
    }
    return p;
}
