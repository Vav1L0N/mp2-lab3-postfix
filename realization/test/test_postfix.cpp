#include "postfix.h"

TEST(TArithmeticExpression, can_create_empty_expression)
{
	ASSERT_NO_THROW(TArithmeticExpression expr);
}

TEST(TArithmeticExpression, can_create_expression)
{
	string exprStr = "1+2";
	TArithmeticExpression expr(exprStr);
	ASSERT_NO_THROW();
}


TEST(TArithmeticExpression, can_get_infix)
{
	string exprStr = "1+2";
	TArithmeticExpression expr(exprStr);
	ASSERT_NO_THROW(expr.GetInfix());
}


TEST(TArithmeticExpression, can_get_postfix)
{
	string exprStr = "1+2";
	TArithmeticExpression expr(exprStr);
	ASSERT_NO_THROW(expr.GetPostfix());
}


TEST(TArithmeticExpression, can_get_operands)
{
	string exprStr = "1+2";
	TArithmeticExpression expr(exprStr);
	ASSERT_NO_THROW(expr.GetOperands());
}

TEST(TArithmeticExpression, can_calculate_correct_expression)
{
	string exprStr = "1+2";
	TArithmeticExpression expr(exprStr);
	ASSERT_NO_THROW(expr.Calculate());
}


TEST(TArithmeticExpression, cant_calculate_incorrect_expression)
{
	string exprStr = "+1+2";
	TArithmeticExpression expr(exprStr);
	ASSERT_ANY_THROW(expr.Calculate());
}

TEST(TArithmeticExpression, cant_calculate_expression_with_unary_minus)
{
	string exprStr = "-1+2";
	TArithmeticExpression expr(exprStr);
	ASSERT_ANY_THROW(expr.Calculate());
}


TEST(TArithmeticExpression, infix_correct)
{
	string exprStr = "1+2+3";
	TArithmeticExpression expr(exprStr);
	ASSERT_EQ(expr.GetInfix(), "1+2+3");
}

TEST(TArithmeticExpression, postfix_correct)
{
	string exprStr = "1+2+3";
	TArithmeticExpression expr(exprStr);
	ASSERT_EQ(expr.GetPostfix(), "12+3+");
}

TEST(TArithmeticExpression, calculate_correct)
{
	string exprStr = "1+2+3";
	TArithmeticExpression expr(exprStr);
	ASSERT_EQ(expr.Calculate(), 6);
}

TEST(TArithmeticExpression, brackets_operator_correct)
{
	string exprStr = "7*(4+3)";
	TArithmeticExpression expr(exprStr);
	ASSERT_EQ(expr.Calculate(), 49);
}

TEST(TArithmeticExpression, plus_operator_correct)
{
	string exprStr = "4+3";
	TArithmeticExpression expr(exprStr);
	ASSERT_EQ(expr.Calculate(), 7);
}

TEST(TArithmeticExpression, minus_operator_correct)
{
	string exprStr = "4-3";
	TArithmeticExpression expr(exprStr);
	ASSERT_EQ(expr.Calculate(), 1);
}

TEST(TArithmeticExpression, mul_operator_correct)
{
	string exprStr = "4*3";
	TArithmeticExpression expr(exprStr);
	ASSERT_EQ(expr.Calculate(), 12);
}


TEST(TArithmeticExpression, div_operator_correct)
{
	string exprStr = "4/2";
	TArithmeticExpression expr(exprStr);
	ASSERT_EQ(expr.Calculate(), 2);
}

TEST(TArithmeticExpression, div_operator_by_zero)
{
	string exprStr = "4/0";
	TArithmeticExpression expr(exprStr);
	ASSERT_ANY_THROW(expr.Calculate());
}

TEST(TArithmeticExpression, dividing_zero_by_zero)
{
	string exprStr = "0/0";
	TArithmeticExpression expr(exprStr);
	ASSERT_ANY_THROW(expr.Calculate());
}



