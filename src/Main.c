#include <malloc.h>
#include "Main.h"
#include "CException.h"
#include "ErrorObject.h"

int shouldFail = 1;

void doThings(){
  // ErrorObject *err;

  // Try {
    doSomething();
  // } Catch(err){
    // printf("Error: %s\n",  err->errorMsg);
    // freeError(err);
  // }
}

int doSomething(){

  if(shouldFail){
    throwError("Hey! Something is really wrong here.",  \
                ERR_DUNNO_WHAT_HAPPEN);
  }

  return 1;
}

/**
 * Add two numbers. The first number must be negative.
 * The second number must be positive number and no more than 50.
 */
int specialAdd(int negVal, int posVal){
  int result;
  
  if (negVal > 0){
    throwError("Hey! It is not a negative number.", ERR_NUMBER_NOT_NEGATIVE);
  }
  else if (posVal > 50){
    throwError("Hey! Positive value is more than 50.", ERR_NUMBER_TOO_LARGE);
  }
  else
    result = negVal + posVal;
  
  return result;
}