#include "unity.h"
#include "Main.h"
#include "CException.h"
#include "ErrorObject.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_doThings(void)
{
	ErrorObject *err;

  Try {
    doSomething();
    TEST_FAIL_MESSAGE("Expect ERR_DUNNO_WHAT_HAPPEN to be thrown."  \
                      "But none thrown");
  } Catch(err){
    TEST_ASSERT_EQUAL_STRING("Hey! Something is really wrong here.", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_DUNNO_WHAT_HAPPEN, err->errorCode);
    printf("Error: %s\n",  err->errorMsg);
    freeError(err);
  }
}

void test_specialAdd_given_minus_5_and_11_should_return_6(void){
  int result = specialAdd(-5, 11);
  TEST_ASSERT_EQUAL(6, result);
}

void test_specialAdd_given_7_and_18_should_throw_ERR_NUMBER_NOT_NEGATIVE(void){
  ErrorObject *err;
  
  Try {
    specialAdd(7, 18);
    TEST_FAIL_MESSAGE("Expect ERR_NUMBER_NOT_NEGATIVE to be thrown."  \
                      "But none thrown");
  } Catch (err){
    TEST_ASSERT_EQUAL_STRING("Hey! It is not a negative number.", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_NEGATIVE, err->errorCode);
    printf("Error: %s\n",  err->errorMsg);
    freeError(err);
  }
}

void test_specialAdd_given_minus_5_and_56_should_throw_ERR_NUMBER_TOO_LARGE(void){
  ErrorObject *err;
  
  Try {
    specialAdd(-5, 56);
    TEST_FAIL_MESSAGE("Expect ERR_NUMBER_TOO_LARGE to be thrown."  \
                      "But none thrown");
  } Catch (err){
    TEST_ASSERT_EQUAL_STRING("Hey! Positive value is more than 50.", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_TOO_LARGE, err->errorCode);
    printf("Error: %s\n",  err->errorMsg);
    freeError(err);
  }
}