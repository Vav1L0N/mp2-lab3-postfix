 #include "stack.h"

class TArithmeticExpression
{
	string infix;
	string postfix;
	vector<char> lexems;
	map<char, int> priority;
	map<char, double> operands;
	void Parse() 
	{
		for (char c : infix)
			lexems.push_back(c);
	}
	void ToPostfix() {
		Parse();
		TDynamicStack<char> st;
		char stackItem;
		for (char item : lexems) {
			switch (item) {
			case '(':
				st.Push(item);
				break;
			case ')':
				stackItem = st.Pop();
				while (stackItem != '(') {
					postfix += stackItem;
					stackItem = st.Pop();
				}
				break;
			case '+':case '-':case '*':case '/':
				while (!st.IsEmpty()) {
					stackItem = st.Pop();
					if (priority[item] <= priority[stackItem])
						postfix += stackItem;
					else {
						st.Push(stackItem);
						break;
					}
				}
				st.Push(item);
				break;
			default:
				operands.insert({ item,item - '0' });
				postfix += item;
			}
		}
		while (!st.IsEmpty()) {
			stackItem = st.Pop();
			postfix += stackItem;
		}
	}
public:
	TArithmeticExpression(string infx) : infix(infx)
	{
		priority = { {'(', 0} , {'+',1},{'-',1},{'*',2} ,{'/',2}};
		ToPostfix();
	}

	TArithmeticExpression() : infix(""), postfix(""){}

	string GetInfix() const 
	{
		return infix;
	}
	string GetPostfix() const 
	{
		return postfix;
	}
	vector<char> GetOperands() const {
		vector<char> op;
		for (const auto& item : operands)
			op.push_back(item.first);
		return op;
	}

	double Calculate()
	{
		TDynamicStack<double> st;
		double leftOperands, rightOperands;
		for (char lexem : postfix)
		{
			switch (lexem)
			{
			case '+':
				rightOperands = st.Pop();
				leftOperands = st.Pop();
				st.Push(leftOperands + rightOperands);
				break;
			case '-':
				rightOperands = st.Pop();
				leftOperands = st.Pop();
				st.Push(leftOperands - rightOperands);
				break;
			case '*':
				rightOperands = st.Pop();
				leftOperands = st.Pop();
				st.Push(leftOperands * rightOperands);
				break;
			case '/':
				rightOperands = st.Pop();
				leftOperands = st.Pop();
				if (rightOperands == 0) {
					cout << "Invalid input => Div by 0" << endl;
					throw invalid_argument("Div by 0");
				}
				st.Push(leftOperands / rightOperands);
				break;
			case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
				st.Push(operands[lexem]);
				break;
			default:
				cout << "Invalid input " << endl;
				throw invalid_argument("Invalid input");
			}
		}
		return st.Pop();
	}
	
};



