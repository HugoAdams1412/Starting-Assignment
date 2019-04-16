/*.......
This program should take an input from the user
as an array of characters, or a string, and rotate
each letter to the right by a given amount, making
the text that was inputted, encrypted so that it is 
unreadable by someone without the key.

Included as well is the decryption function which will 
be able to turn an encrypted message with the caeser 
cipher, back to readable text....
.....
*/

#include <stdio.h>

int main()
{
    
    //declare key and string variables
    int key = 0;
    char plainText[101];
    
    
    //Get key input from the user
    printf("Input an integer for a key: \n");
    scanf("%d", &key);
    
    //string counter
    int i = 0;
    
    //open the text file
    FILE *input;
    input = fopen("input.txt", "r");
  
    
    //Scan each character in string until end of string is reached
    while(!feof(input))
    {
        fscanf(input, "%c", plainText); //store in plainText array
    }
    
    printf("The Sentence to be Encrypted: %s\n", plainText);
    
    //encrypt each letter one at a time
    for(i = 0; plainText[i] != '\0'; i++)
    {
        if(plainText[i] == 32) //when there is a space, do not change
        {
            continue;
        }
        else if(plainText[i] == 10 || plainText[i] == 13) //when there is a tab or backspace, break loop
        {
            break;
        }
       else //otherwise, do the encryption
       {
            plainText[i] = ((plainText[i] - 64 + key) % 26) + 64;
            printf("%c", plainText[i]);
       }    
    }
    
    
    //print the string of encrypted text
    printf("%s", plainText);
   
}

