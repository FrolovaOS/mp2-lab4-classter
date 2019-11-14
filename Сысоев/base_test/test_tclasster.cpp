
#include "TClasster.h"
#include "TClasster.cpp"
#include <gtest.h>

TEST(TClasster, can_create_Classter)
{
	TClasster p;
	
  ASSERT_NO_THROW(p.RunNewJob(8,40, 20,0.8););
}
