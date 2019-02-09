//
//  acronym.c
//  acronym
//
//  Created by Brian on 2/9/19.
//  Copyright © 2019 Brian Bleck. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "acronym.h"

//
//  main.c
//  Acronym.c
//  A simple program to print the acronym of whatever string is passed in.
//
//  Created by Brian on 2/9/19.
//  Copyright © 2019 Brian Bleck. All rights reserved.
//

int main(int argc, const char * argv[]) {
  printf("%s\n", abbreviate("Sick: as fudge."));
  return 0;
}

char *abbreviate(const char *phrase){
  int wordCount = 0;
  int isFirstLetter = 1;
  int i = 0;
  char* resultString;
  char abbrString[30];
  
  //check for null and empty string
  if(phrase == NULL || strlen(phrase) < 1){
    return NULL;
  }
  //loop through phrase and put first letters into a string
  for(i = 0; i < (int)strlen(phrase); i++){
    if(isFirstLetter){
      if(isalpha(phrase[i])){
        isFirstLetter = 0;
        abbrString[wordCount] = (char)toupper(phrase[i]);
        wordCount++;
      }
    }else if(!isalpha(phrase[i]) && phrase[i] != '\''){
      isFirstLetter = 1;
    }
  }
  abbrString[wordCount] = '\0';
  
  //allocate correct space for a new string, fill it, and return it
  resultString = malloc((wordCount) * sizeof(char));
  for(i = 0; i < wordCount+1; i++){
    resultString[i] = abbrString[i];
  }
  return resultString;
}
