#include "TQueue.h"

#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> st(5));
}

TEST(TQueue, cannot_create_queue_with_negetive_length)
{
	ASSERT_ANY_THROW(TQueue<int> st(-5));
}

TEST(TQueue, cannot_create_queue_with_length_larger_MaxStackSize)
{
	ASSERT_ANY_THROW(TQueue<int> st(101));
}

TEST(TQueue, can_push_element)
{
	TQueue<int> st(2);
	st.Push(1);
	EXPECT_EQ(st.GetTop(), 1);
}


TEST(TQueue, can_delete_element)
{
	TQueue<int> st(2);
	st.Push(1);
	st.Push(2);
	st.Pop();

	EXPECT_EQ(st.GetTop(), 2);
}

TEST(TQueue, can_get_lenght_of_queue)
{
	TQueue<int> st(2);
	st.Push(1);
	st.Push(2);
	EXPECT_EQ(2, st.TQueueLength());
}

TEST(TQueue, check_IsEmpty_if_Queue_IsEmpty)
{
	TQueue<int> st(2);

	EXPECT_TRUE(st.IsEmpty());
}

TEST(TQueue, check_IsEmpty_if_Queue_not_IsEmpty)
{
	TQueue<int> st(2);
	st.Push(1);

	EXPECT_FALSE(st.IsEmpty());
}

TEST(TQueue, check_IsFull_if_Queue_IsFull)
{
	TQueue<int> st(2);
	st.Push(1);
	st.Push(2);

	EXPECT_TRUE(st.IsFull());
}

TEST(TQueue, check_IsFull_if_not_Queue_IsFull)
{
	TQueue<int> st(2);

	EXPECT_FALSE(st.IsFull());
}









