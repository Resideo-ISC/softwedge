#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "winaccess.h"

char* extractAndConvert(const char* input, int startIndex, int numberOfChars) {
    int inputLength = strlen(input);
  
    // Check for valid indices
    if (startIndex < 0 || numberOfChars >= inputLength ) {
        return NULL;
    }

    // Extract the substring
    char extractedSubstring[numberOfChars + 2];
    strncpy(extractedSubstring, input + startIndex, numberOfChars);
    
    extractedSubstring[numberOfChars] = '\0';
    //printf("Extracted string: %s\n", extractedSubstring);

    int decimalValue = (int)strtol(extractedSubstring, NULL, 16);
    
    // Allocate memory for the result string
    char* result = (char*)malloc(32); // Assuming a reasonable length for the decimal value
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    // Convert the decimal value back to a string
    snprintf(result, 32, "%d", decimalValue);

    return result;
}

int main() {
  const char* inputString = "0133000002C7FD\n";
  int startIndex = 4;
  int numberOfChars = 8;
 
  int i = 0;
  int inputLen = strlen(inputString);
  char* inputBuff = (char*)malloc(32);
  char* result = (char*)malloc(32);
  
  printf("Start\n\n");
  printf("length:%d\n", strlen(inputString));
  
  for(i=0;i<inputLen;i++){
           
    if (inputString[i] == 0x02 || inputString[i] == 0x03 || inputString[i] == 0x0D) {
      continue;
    }
			
    inputBuff[i] = inputString[i];
    
    printf("cnt: %d\n", i);

    if(inputString[i] == 0x0A){	
			result = extractAndConvert(inputBuff, startIndex, numberOfChars);
            
      printf("Scanned: %s\n", result);
      printf("Result: ");
			
			for(i=0;i<strlen(result);i++){
        printf("%c", result[i]);
			}
			
			break;
			
			printf("\n");
		}
  }
    
  free(inputBuff);
  free(result);

  return 0;
}
