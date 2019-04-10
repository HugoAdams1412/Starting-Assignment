#include <stdio.h>

int main()
{
    char string[100];
    int i = 0, key = 5;
    
    printf("Input a Rotation: \n");
    scanf("%d", &key);
    getchar();
    printf("Input a Sentence in Capitals: \n");
    
    while(i < 100) {
    scanf("%c", string);
    
    if(string[0] == 10 || string [0] == 13)
    break;
    
    if(string[0] == 32)
    {
       printf("%c", string[0]);
        continue;
    }
    
    string[0] = string[0] - 65;
    string[0] = (string[0] + key) % 26;
    string[0] = string[0] + 65;
    
    printf("%c", string[0]);
    
    i++;
    }
    
    
    return 0;
}