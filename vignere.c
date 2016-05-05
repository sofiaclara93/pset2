#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>

int newk(int newl, string k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere\n");
        return 1;
    }
    
    //obtains keyword from user
    string k = argv[1];
    
    // obtains message from user
    string s = GetString();
    
    // checks that keyword only contains letters
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isalpha(k[i]) == 0)
        {   
            printf("nonvalid key\n");
            return 1;
        }
        
    }
    
    int newl = 0; 
    
     //changes letters while keeping the case and reprints other characters
     for (int i = 0, n = strlen(s); i < n; i++)
    {
        char c = s[i];

        if (isupper(c))
        {
            char d = (((c - 65) + newk(newl,k)) % 26) + 65; newl++;
            printf("%c", d);
        }
       
        else if (islower(c))
        {
            char d = (((c - 97) + newk(newl,k)) % 26) + 97;  newl++;
            printf("%c", d);
        }
            
        else
        {
            printf("%c", c);
        }
    }
    
    printf("\n");
    return 0;
}

int newk(int newl, string k)
{
    int n = strlen(k);
    return tolower(k[newl %n])-97; 
    
}
