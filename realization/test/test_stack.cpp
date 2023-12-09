#include "postfix.h"

TEST(TDynamicStackTest, can_create_stack) {
    ASSERT_NO_THROW(TDynamicStack<int> stack);
}

TEST(TDynamicStackTest, can_create_stack_with_positive_size) {
    ASSERT_NO_THROW(TDynamicStack<int> stack(2));
}

TEST(TDynamicStackTest, throws_when_create_stack_with_negative_size)
{
    ASSERT_ANY_THROW(TDynamicStack<int> stack(-2));
}

TEST(TDynamicStackTest, can_create_copied_stack)
{
    TDynamicStack<int> stack(10);

    ASSERT_NO_THROW(TDynamicStack<int> stack_1(stack));
}


TEST(TDynamicStack, copied_stack_has_its_own_memory)
{
    TDynamicStack<int> stack_1(5);

    TDynamicStack<int> stack_2(stack_1);
    EXPECT_NE(&stack_1, &stack_2);
}

TEST(TDynamicStack, copied_stack_is_equal_to_source_one)
{
    TDynamicStack<int> stack_1(5);
    stack_1.Push(1);
    TDynamicStack<int> stack_2(stack_1);
    EXPECT_TRUE(stack_1==stack_2);
}

TEST(TDynamicStack, push_method) {
    TDynamicStack<int> stack;
    ASSERT_NO_THROW(stack.Push(1));
}

TEST(TDynamicStack, copied_stack_is_a_new_object) {
    TDynamicStack<int> stack;
    stack.Push(1);
    stack.Push(2);
    TDynamicStack<int> stack_2(stack);
    stack.Pop();
    EXPECT_NE(stack_2.Peek(), stack.Peek());
}

TEST(TDynamicStack, size_returns_correct_length) {
    TDynamicStack<int> stack(5);
    stack.Push(1); stack.Push(2);
    EXPECT_EQ(2, stack.size());
}

TEST(TDynamicStack, overflowing_stack) {
    TDynamicStack<int> stack(2);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    
    EXPECT_NE(2, stack.size());
}
TEST(TDynamicStack, stack_is_empty) {
    TDynamicStack<int> stack;
    EXPECT_EQ(stack.IsEmpty(), true);
}
TEST(TDynamicStack, stack_is_full) {
    TDynamicStack<int> stack(1);
    stack.Push(1);
    EXPECT_EQ(stack.IsFull(), true);
}
TEST(TDynamicStack, stack_is_not_empty) {
    TDynamicStack<int> stack(1);
    stack.Push(1);
    EXPECT_NE(stack.IsEmpty(), true);
}
TEST(TDynamicStack, stack_is_not_full) {
    TDynamicStack<int> stack(1);
    EXPECT_NE(stack.IsFull(), true);
}

TEST(TDynamicStack, throws_when_call_peek_on_empty_stack) {
    TDynamicStack<int> stack;
    ASSERT_ANY_THROW(stack.Peek());
}

TEST(TDynamicStack, throws_when_call_pop_on_empty_stack) {
    TDynamicStack<int> stack;
    ASSERT_ANY_THROW(stack.Pop());
}


TEST(TDynamicStack, peek_method) {
    TDynamicStack<int> stack(2);
    stack.Push(1);
    stack.Push(2);
    EXPECT_EQ(stack.Peek(),2);
}

TEST(TDynamicStack, pop_method) {
    TDynamicStack<int> stack(2);
    stack.Push(1);
    stack.Push(2);
    stack.Pop();
    EXPECT_EQ(stack.Peek(),1);
}



TEST(TDynamicStack, equality_operator_returns_true_on_same_stacks_of_same_size) {
    TDynamicStack<int> stack_1(2), stack_2(2);
    stack_1.Push(1);
    stack_2.Push(1);
    EXPECT_TRUE(stack_1 == stack_1);
}

TEST(TDynamicStack, equality_operator_returns_true_on_same_stacks_of_different_size) {
    TDynamicStack<int> stack_1(2), stack_2(3);
    stack_1.Push(1);
    stack_2.Push(1);
    EXPECT_TRUE(stack_1 == stack_2);
}


TEST(TDynamicStack, equality_operator_returns_false_on_different_stacks_of_same_size) {
    TDynamicStack<int> stack_1(2), stack_2(2);
    stack_1.Push(1);
    stack_2.Push(1);
    stack_2.Push(1);
    EXPECT_FALSE(stack_1 == stack_2);
}

TEST(TDynamicStack, equality_operator_returns_false_on_different_stacks_of_different_size) {
    TDynamicStack<int> stack_1(2), stack_2(3);
    stack_1.Push(1);
    stack_2.Push(1);
    stack_2.Push(1);   
    EXPECT_FALSE(stack_1 == stack_2);
}

TEST(TDynamicStack, assign_operator_returns_true_on_different_stacks_of_different_size) {
    TDynamicStack<int> stack_1(2), stack_2(3);
    stack_1.Push(1);
    stack_2.Push(2);
    stack_2 = stack_1;
    EXPECT_TRUE(stack_1 == stack_2);
}

TEST(TDynamicStack, getmemSize) {
    TDynamicStack<int> stack(2);    
    EXPECT_EQ(2,stack.getmemSize());
}

TEST(TDynamicStack, stacks_with_different_size_are_not_equal)
{
    TDynamicStack<int> stack_1(2), stack_2(3);
    stack_1.Push(1);
    stack_2.Push(1);
    stack_2.Push(2);
    EXPECT_TRUE(stack_1 != stack_2);
}
