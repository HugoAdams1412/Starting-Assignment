/*.....
 This Program will hopefully take a sentence input from the user
 and also a rotation value, then convert the input sentence
 into a encrypted version with a roation cipher......
 */

#include<stdio.h>

char r(char 'sentence[int i]')

int main() {
    char sentence[100], newLetter; //the message can only have maximum of 100 characters
    int i, rotations; //counter and value of rotation cipher respectively
    
    printf("Rotation Cipher: \n\n\n");
    
    
    //create string with ABCD...Z
    //shift each letter to zero and 25
    //pass each letter into the function "e(x)" returning 0 - 25
    
    
    
    
    for(i = 0; sentence[i] != '\0'; i++) //keep loop going until runs into '\0' which stops the char array
    {
        newLetter = sentence[i]; //take each letter from message and assign it a new letter
        
        if(newLetter >= 'a' && newLetter <= 'z') 
        {
           newLetter = newLetter + rotations; 
        }
    }
    
    
    
    
    return 0;
}

char r(char 'sentence[int i]')
{
    
    for (i = 0; i<=25; i++) 
    {
        ('sentence[i]' + 1) % 26
    }
}