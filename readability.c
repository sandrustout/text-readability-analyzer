#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *text;
} string;

int readability(string mystring);

int main(void)
{
    string mystring;
    int buffer_size = 1024;
    
    mystring.text = malloc(buffer_size * sizeof(char));
    
    if (mystring.text == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter a text: ");
    
    if (fgets(mystring.text, buffer_size, stdin) != NULL)
    {
        mystring.text[strcspn(mystring.text, "\n")] = '\0';
        
        int score = readability(mystring);
        
        if (score < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (score >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", score);
        }
    }
    
    free(mystring.text);
    return 0;
}

int readability(string mystring)
{
    int words = 0, letters = 0, sentences = 0;
    
    int len = strlen(mystring.text);
    
    for (int i = 0; i < len; i++)
    {
        if (isalpha(mystring.text[i]))
        {
            letters++;
        }
        else if (mystring.text[i] == ' ')
        {
            words++;
        }
        else if (mystring.text[i] == '.' || mystring.text[i] == '!' || mystring.text[i] == '?')
        {
            sentences++;
        }
    }
    
    if (len > 0)
    {
        words++; 
    }
    
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    return round(index);
}
