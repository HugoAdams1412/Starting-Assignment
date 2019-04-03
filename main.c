/*.....
 This Program will hopefully take a sentence input from the user
 and also a rotation value, then convert the input sentence
 into a encrypted version with a roation cipher......
 */

#include<stdio.h>

char r(int letter);

int main() {
    char sentence[26]; //using entire alphabet as test string
    int i = 0, result;
    
    sentence[26] = ABCDEFGHIJKLMNOPQRSTUVWXYZ;
    
    for(i = 0; i<26; i++)
    {
        sentence[i] = 'sentence[i]' - 65;
        result = r(i);
        printf("%c", result);
    }
    
    //create string with ABCD...Z
    //shift each letter to zero and 25
    //pass each letter into the function "e(x)" returning 0 - 25
    
    
    
    
    /*for(i = 0; i <= 25; i++) //loop will continue until done 0-25 values i.e. entire alphabet
    {
        newLetter = sentence[i]; //take each letter from message and assign it a new letter 
        
    }*/
    
    return 0;
}

char r(int letter)
{
    int result;
    char sentence[26] =

    result = (sentence[letter] + 1)%26;
    return result;
}