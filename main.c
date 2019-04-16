/*.......
This program should take an input from the user
as an array of characters, or a string, and rotate
each letter to the right by a given amount (key), making
the text that was inputted, encrypted so that it is 
unreadable by someone without the key.

Included as well is the decryption function which will 
be able to turn an encrypted message with the caeser 
cipher, back to readable text....
.....
*/

#include <stdio.h>
#include<string.h> //for strlen function

int main()
{
    
    //declare key and string variables
    int key = 0;
    char plainText[101];
    int arrayPosition = 0;
    int selection = 0;
    
    //open the text file
    FILE *input;
    input = fopen("input.txt", "r");
    
   
   printf("Enter 0 to Encrypt and 1 to decrypt: ");
    scanf("%d", &selection);
    
    switch(selection){
        
        case 0: //performing encryption
        
        //Get key input from the user
    printf("Input an integer for a Rotation key: \n");
    scanf("%d", &key);
  
    //Scan each character in string until end of string is reached
    while(!feof(input))
    {
        fscanf(input, "%c", &plainText[arrayPosition]); //store in plainText array
        arrayPosition++;
    }
    
    printf("The Sentence to be Encrypted: %s\n", plainText);
    
    fseek(input, SEEK_SET, SEEK_CUR);
    
    //initialising the string counter to 0
    int i = 0;
    
    //encrypt each letter one at a time
    for(i = 0; i < strlen(plainText); i++)
    {
            //if character is a space, leave unchanged
            if(plainText[i] < 65 || plainText[i] > 90)
            {
             printf("%c", plainText[i]);
            }
            //otherwise, perform encryption       
           else if (65 <= plainText[i] && 90 >= plainText[i])
            {
            plainText[i] = ((plainText[i] - 65 + key) % 26) + 65;
            printf("%c", plainText[i]);
            }
    } 
    break;
        
        
        case 1: //performing decryption
        
        //Get key input from the user
    printf("Input an integer for a Rotation key: \n");
    scanf("%d", &key);
  
    //Scan each character in string until end of string is reached
    while(!feof(input))
    {
        fscanf(input, "%c", &plainText[arrayPosition]); //store in plainText array
        arrayPosition++;
    }
    
    printf("The Sentence to be Decrypted: %s\n", plainText);
    
    fseek(input, SEEK_SET, SEEK_CUR);
    
    //re-initialising the string counter to 0
    i = 0;
    
    //encrypt each letter one at a time
    for(i = 0; i < strlen(plainText); i++)
    {
            //if character is a space, leave unchanged
            if(plainText[i] < 65 || plainText[i] > 90)
            {
             printf("%c", plainText[i]);
            }
            //otherwise, perform encryption       
           else if (65 <= plainText[i] && 90 >= plainText[i])
            {
            plainText[i] = ((plainText[i] - 65 - key) % 26) + 65;
            printf("%c", plainText[i]);
            }
    } 
    break;
        
        default:
        printf("Error, Please Try Again\n");
        break;
    }
    
    
    
   return 0;
}

