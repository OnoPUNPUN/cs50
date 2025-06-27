#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int P[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int s_letters[] = {97,  98,  99,  100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
                   110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

int c_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77,
                   78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int temp_Points[] = {};

int get_score(string word);

int main(void)
{
    string w1 = get_string("Player 1: ");
    string w2 = get_string("Player 2: ");

    int s1 = get_score(w1);
    int s2 = get_score(w2);

    if (s1 > s2)
    {
        printf("Player 1 wins!\n");
    }
    else if (s2 > s1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(string word)
{
    int s = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            for (int f = 0; f < sizeof(c_letters); f++)
            {
                if (word[i] == c_letters[f])
                {
                    temp_Points[i] = P[f];
                    s += temp_Points[i];
                }
            }
        }
        else if (islower(word[i]))
        {
            for (int f = 0; f < sizeof(s_letters); f++)
            {
                if (word[i] == s_letters[f])
                {
                    temp_Points[i] = P[f];
                    s += temp_Points[i];
                }
            }
        }
        else
        {
            i += 1;
        }
    }
    return s;
}
