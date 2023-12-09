
#include "postfix.h"


int main()
{
	string s = "7-1+3/4-5*(5-2)/3*(4-5)";
	cout << "Example of calculating an expression: " << s << endl;
	TArithmeticExpression ex(s);
	cout << "Result: " << ex.Calculate()<< endl;

	string exprStr;
	cout << "Enter expression: ";
	cin >> exprStr;
	TArithmeticExpression expr(exprStr);
	cout <<"Infix: " << expr.GetInfix() << endl;
	cout <<"Postfix: " << expr.GetPostfix() << endl;
	cout <<"Result: " << expr.Calculate() << endl;
}