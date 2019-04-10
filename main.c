#include<stdio.h>
 
//int main()
//{
//    #include <stdio.h>

int main()
{
    char string[100];
    int i=0, key =1;
    
   // printf("Input a Key: \n");
    //scanf("%d", &key);
    
    printf("Input a Word: \n");
    
    while(i <100)
    {
    scanf("%c", string);
    printf("%c ", string[0]);
    
    if(string[0] == 10 || string [0] == 13)
    break;
    
    string[0] = string[0] - 65;
    string[0] = (string[0] + key) % 26;
    string[0] = string[0] + 65;
    
    printf("%c\n", string[0]);
    i++;
    }
    
    
    /*for(i = 0; string[i] != '\0'; i++){
    
    string[i] = string[i] - 65;
    string[i] = (string[i] + key) % 26;
    string[i] = string[i] + 65;
    
    }
    
    printf("%s\n", string);*/
    
        printf("blah");
    return 0;
}
    
    
    
//	char message[100], ch;
//	int i, key;
//	
//	printf("Enter a message to encrypt: \n");
//	scanf("%c", message);
//	printf("Enter key: ");
//	scanf("%d", &key);
//	
//	for(i = 0; message[i] != '\0'; ++i){
//		ch = message[i];
//		
//		if(ch >= 'a' && ch <= 'z'){
//			ch = ch + key;
//			
//			if(ch > 'z'){
//				ch = ch - 'z' + 'a' - 1;
//			}
//			
//			message[i] = ch;
//		}
//		else if(ch >= 'A' && ch <= 'Z'){
//			ch = ch + key;
//			
//			if(ch > 'Z'){
//				ch = ch - 'Z' + 'A' - 1;
//			}
//			
//			message[i] = ch;
//		}
//	}
//	
//	printf("Encrypted message: %s", message);
	
//	return 0;
//}
    
    //create string with ABCD...Z
    //shift each letter to zero and 25
    //pass each letter into the function "e(x)" returning 0 - 25
    