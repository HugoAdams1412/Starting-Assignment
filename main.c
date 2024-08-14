/*.......
THIS PROGRAM INCLUDES A MENU WHERE THE USER
DECIDES IF THEY WANT TO DO A SUBSTITUTION OR
ROTATION CIPHER. THEY THEN DECIDE WEATHER THEY
WANT TO ENCRYPT OR DECRYPT THE MESSAGE IN THE 
EXTERNAL .TXT FILE
.....
*/

#include <stdio.h>

void rotationEncryption(char plainLetter, int key);
void rotationDecryption(char plainLetter, int key);
void substitutionEncryption(char plainLetter);
void substitutionDecryption(char plainLetter);


int main()
{
    
    //declare key and letter variables
    int key = 63;
    char plainLetter;
    int selection1 = 0;
    int selection2 = 0;
    
    //open the input text file with the plain / encrypted text
    FILE *input;
    input = fopen("input.txt", "r");
    
    if(input == NULL)
    {
     printf("Cannot open File");  
     return 0;
    }
    
   
   //ask user if it is a rotation or substitution cipher
   printf("\nPress 0 for rotation cipher or 1 for substitution cipher: ");
   //scan input into selection1 variable
   scanf("%d", &selection1);
   
   switch(selection1)
   {   
   //for the case of rotation cipher
   case 0:
   
   //TITLE
   printf("\nROTATION ENCRYPTION/DECRYPTION:\n\n");
   printf("git branch test") // git branch test 2
   
   //user decides wheather to encrypt of decrypt
    printf("\nPress 1 to Encrypt or 0 to Decrypt: ");
    scanf("%d", &selection2);
    
    //getting input from the user about the amount of shift in letters
    /*printf("\n\nInput an integer for the key.\nIf the key is not known, press '?': ");
    scanf("%d", &key);*/
    
    
    switch(selection2)
    {
        
        //if they want to encrypt
        case 1:
        
        //getting input about the key
        printf("\n\nInput an integer for the key: ");
        scanf("%d", &key);
    
    //ensuring the file is reading from beginning
    //fseek(input, 0 , SEEK_SET);
    
    //read each character in the file and encrypt it one at a time
    while(feof(input) == 0) //this keeps the loop going until it has reached the end of the file
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
     
     //get input about the key and also if it is unknown
     printf("Input an integer for the key,\nIf the key is unknown, press '?': ");
     scanf("%d", &key);
    
    //ensuring the file location is at the beginning
    //fseek(input, 0 , SEEK_SET);
    
    //if the key is not known, print every rotation
    if(key == 63) //63 is the ascii value of a question mark
    {
        key = 1; //set the key to 1
        for(key = 1; key <= 26; key++) //this will print out 26 versions of the message
        {
           while(feof(input) == 0) 
           {
            fscanf(input, "%c", &plainLetter); //perform the decryption
            rotationDecryption(plainLetter, key);
           }
           printf("\n\n"); //print next message on new line
           //set to beginning of file again
           fseek(input, 0 , SEEK_SET);
        }

    }
    else
    {
       //read each character in the file and decrypt it one at a time
       while(feof(input) == 0)
       {
        //scan the letter into the plainLetter variable
        fscanf(input, "%c", &plainLetter);
        //call the decryption function
        rotationDecryption(plainLetter, key); //NOTE: Function already prints the encrypted letter
        //move to next position on file
       } 
       
    }

        break;

    //if accidentally presses anything else
    default:
    printf("Error, Please Try Again\n");
    break;

    }
    
    break;
    
    //if they want to do a substitution cipher
    case 1:
    //TITLE
    printf("\nSUBSTITUTION ENCRYPTION/DECRYPTION\n");
    
    //ask the user if they want to encrypt or decrypt
    printf("\nPress 0 to Encrypt or 1 to Decrypt: ");
    scanf("%d", &selection2);
    
    switch(selection2)
    {    
    //if they choose to encrypt
    case 0:
    //define a variable to keep track of location along file

    //ensuring the file is reading from beginning
    //fseek(input, 0 , SEEK_SET);
    //fseek(input, SEEK_SET, SEEK_CUR);
    
    //changing each letter in the file
    while(feof(input) == 0)
    {
        //read the letter
        fscanf(input, "%c", &plainLetter);
        //perform the encryption
        substitutionEncryption(plainLetter);
        //print the encrypted letter to the console
        //NOTE: the encryption function already prints to the console
    }
    
    break;
    
    //if they choose to decrypt
    case 1:
    
    //ensuring the file is reading from beginning
    //fseek(input, 0 , SEEK_SET);
    //fseek(input, SEEK_SET, SEEK_CUR);
    
    //changing each letter in the file
    while(feof(input) == 0)
    {
        //read the letter
        fscanf(input, "%c", &plainLetter);
        //perform the decryption
        substitutionDecryption(plainLetter);
        //print the decrypted letter to the console
        //NOTE: the decryption function already prints to the console
    
    }
    break;

   default:
   printf("\nError, Try Again!\n");
   break;
    }
    
    break;
    
    default:
    printf("\nError, Please Try Again");
    break;

    }

   return 0;
}

//function defintion
//returns no value, only prints letters, hence must have void return type
void rotationEncryption(char plainLetter, int key)
{
    
     //open the input text file with the plain / encrypted text so we may write to it
    FILE *output;
    output = fopen("output.txt", "w");
    
            //if character is not a capital letter, leave unchanged
            if(plainLetter < 65 || plainLetter > 90)
            {
             printf("%c", plainLetter);
             fprintf(output, "%c", plainLetter);
            }
            
            else if (plainLetter >= 91 && plainLetter < 97)
            {
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
            }
            
            else if(plainLetter > 122)
            {
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
            }
            
            //if character is a lower case, convert to upper case
            else if(97 <= plainLetter && 122 >= plainLetter)
            {
                plainLetter = plainLetter - 32;
                plainLetter = ((plainLetter - 65 + key) % 26) + 65;
                printf("%c", plainLetter);
                //print the letter also to a file output
                fprintf(output, "%c", plainLetter);
            }
            
            //otherwise, perform encryption       
           else if (65 <= plainLetter && 90 >= plainLetter)
            {
            plainLetter = ((plainLetter - 65 + key) % 26) + 65;
            //print the letter
            printf("%c", plainLetter);
            fprintf(output, "%c", plainLetter);
            }
}

//function defintion
//returns no value, only prints letters, hence must have void return type
void rotationDecryption(char plainLetter, int key)
{
    
    //open the input text file with the plain / encrypted text
    FILE *output;
    output = fopen("output.txt", "w");
            
             //if character is not a capital letter, leave unchanged
            if(plainLetter < 65 || plainLetter > 90)
            {
             printf("%c", plainLetter);
             fprintf(output, "%c", plainLetter);
            }
            
            //if character is between upper and lower case
            else if (plainLetter >= 91 && plainLetter < 97)
            {
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
            }
            
            else if(plainLetter > 122)
            {
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
            }
            
            //if character is a lower case, convert to upper case
            else if(97 <= plainLetter && 122 >= plainLetter)
            {
                plainLetter = plainLetter - 32;
                plainLetter = plainLetter - 65 - key;
                //if this value is negative, add 26 to make positive but not change the result
                if(plainLetter < 0)
                   plainLetter = plainLetter + 26;
                
                plainLetter = (plainLetter % 26) + 65;
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
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
            fprintf(output, "%c", plainLetter);
            }        

}

//encryption function definition
void substitutionEncryption(char plainLetter)
{
    //if the input has a lower case letter, convert to an uppercase
    if(97 <= plainLetter && 122 >= plainLetter)
    {
        plainLetter = plainLetter - 32;
    }
    
     //open the output text file to write to
    FILE *output;
    output = fopen("output.txt", "w");
    
    if(output == NULL)
    {
      printf("File Cannot be Opened");
      return;
    }

    
    //hard code the alternative for each letter
    switch(plainLetter)
    {
      case 'A': plainLetter = 'M';
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
        break;
      case 'B': plainLetter = 'O';
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
        break;
      case 'C': plainLetter = 'C';
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
        break;
      case'D': plainLetter = 'N';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'E': plainLetter = 'W';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'F': plainLetter = 'D';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'G': plainLetter = 'L';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'H': plainLetter = 'A';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'I': plainLetter = 'V';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'J': plainLetter = 'B';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'K': plainLetter = 'U';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'L': plainLetter = 'G';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'M': plainLetter = 'P';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'N': plainLetter = 'H';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'O': plainLetter = 'E';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'P': plainLetter = 'T';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'Q': plainLetter = 'F';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'R': plainLetter = 'Q';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'S': plainLetter = 'I';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'T': plainLetter = 'K';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'U': plainLetter = 'X';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'V': plainLetter = 'J';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'W': plainLetter = 'R';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'X': plainLetter = 'S';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'Y': plainLetter = 'Z';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'Z': plainLetter = 'Y';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      default: printf("%c", plainLetter);
      fprintf(output, "%c", plainLetter);
        break;
      
    }

}

void substitutionDecryption(char plainLetter)
{
     //if the input has a lower case letter, convert to an uppercase
    if(97 <= plainLetter && 122 >= plainLetter)
    {
        plainLetter = plainLetter - 32;
    }
    
    //open the input text file with the plain / encrypted text
    FILE *output;
    output = fopen("output.txt", "w");
    
    switch(plainLetter)
    {
      case 'M': plainLetter = 'A';
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
        break;
      case 'O': plainLetter = 'B';
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
        break;
      case 'C': plainLetter = 'C';
                printf("%c", plainLetter);
                fprintf(output, "%c", plainLetter);
        break;
      case'N': plainLetter = 'D';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'W': plainLetter = 'E';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'D': plainLetter = 'F';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'L': plainLetter = 'G';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'A': plainLetter = 'H';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'V': plainLetter = 'I';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'B': plainLetter = 'J';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'U': plainLetter = 'K';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'G': plainLetter = 'L';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'P': plainLetter = 'M';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'H': plainLetter = 'N';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'E': plainLetter = 'O';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'T': plainLetter = 'P';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'F': plainLetter = 'Q';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'Q': plainLetter = 'R';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'I': plainLetter = 'S';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'K': plainLetter = 'T';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'X': plainLetter = 'U';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'J': plainLetter = 'V';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'R': plainLetter = 'W';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'S': plainLetter = 'X';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'Z': plainLetter = 'Y';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      case'Y': plainLetter = 'Z';
               printf("%c", plainLetter);
               fprintf(output, "%c", plainLetter);
        break;
      default: printf("%c", plainLetter);
      fprintf(output, "%c", plainLetter);
        break;
      
    }
    
    
}
