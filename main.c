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

void rotationEncryption(char plainLetter, int key);
void rotationDecryption(char plainLetter, int key);

int main()
{
    
    //declare key and letter variables
    int key = 0;
    char plainLetter;
    int selection = 0;
    
    //open the text file
    FILE *input;
    input = fopen("input.txt", "r");
   
   //TITLE
   printf("\nROTATION ENCRYPTION/DECRYPTION:\n\n");
   
   //user decides wheather to encrypt of decrypt
    printf("\nPress 1 to Encrypt or 0 to Decrypt: ");
    scanf("%d", &selection);
    
    //getting input from the user about the amount of shift in letters
    printf("\n\nInput an integer for the key: ");
    scanf("%d", &key);
    
    switch(selection)
    {
        
        //if they want to encrypt
        case 1:
    
    //ensuring the file is reading from beginning
    fseek(input, SEEK_SET, SEEK_CUR);
    
    //read each character in the file and encrypt it one at a time
    while(!feof(input))
    {
        //scan the letter into the plainLetter variable
        fscanf(input, "%c", &plainLetter);
        //call the encryption function
        rotationEncryption(plainLetter, key); //NOTE: Function already prints the encrypted letter
        //move to next position on file
    }
    break;
    
     //if they want to decrypt
     case 0:
    
    //ensuring the file location is at the beginning
    fseek(input, SEEK_SET, SEEK_CUR);
    
    
    //read each character in the file and decrypt it one at a time
    while(!feof(input))
    {
        //scan the letter into the plainLetter variable
        fscanf(input, "%c", &plainLetter);
        //call the decryption function
        rotationDecryption(plainLetter, key); //NOTE: Function already prints the encrypted letter
        //move to next position on file
    }
     
     break;
    
    //if accidentally presses anything else
    default:
    printf("Error, Please Try Again\n");
    break;

    }

    
   return 0;
}

//function defintion
//returns no value, only prints letters, hence must have void return type
void rotationEncryption(char plainLetter, int key)
{
            
            //if character is not a capital letter, leave unchanged
            if(plainLetter < 65 || plainLetter > 90)
            {
             printf("%c", plainLetter);
            }
            
            //if character is a lower case, convert to upper case
            else if(97 <= plainLetter && 122 >= plainLetter)
            {
                plainLetter = plainLetter - 32;
            }
            
            //otherwise, perform encryption       
           else if (65 <= plainLetter && 90 >= plainLetter)
            {
            plainLetter = ((plainLetter - 65 + key) % 26) + 65;
            //print the letter
            printf("%c", plainLetter);
            }
}

//function defintion
//returns no value, only prints letters, hence must have void return type
void rotationDecryption(char plainLetter, int key)
{
            
            //if character is not a capital letter, leave unchanged
            if(plainLetter < 65 || plainLetter > 90)
            {
             printf("%c", plainLetter);
            }
            
            //if character is a lower case, convert to upper case
            else if(97 <= plainLetter && 122 >= plainLetter)
            {
                plainLetter = plainLetter - 32;
            }
            
            //otherwise, perform decryption       
           else if (65 <= plainLetter && 90 >= plainLetter)
            {
            plainLetter = (plainLetter - 65 - key);
            
            //plain letter may be negative because of '- key' so add 26
            if(plainLetter < 0)
            {
                plainLetter += 26;
            }
            
            plainLetter = (plainLetter % 26) + 65;
    
            //print the letter
            printf("%c", plainLetter);
            }
}

