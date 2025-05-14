#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

vector<int> vet_to_vector(int* v, int n) {
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(v[i]);
    }
    return vec;
}

list<int> vet_to_flist(int* v, int n){
    list<int> list;

    for (int i = 0; i < n; i++)
    {
        list.push_back(v[i]);
    }
    return list;
}

stack<int> vet_to_stack(int* v, int n){
    stack<int> stack;

    for (int i = 0; i < n; i++)
    {
        stack.push(v[i]);
    }
    return stack;
}

vector<int> list_concat(list<int>& list1,list<int>& list2){
    vector<int> vec;
    for(int e : list1) {
        vec.push_back(e);
    }
    for(int e : list2) {
        vec.push_back(e);
    }
    return vec;
}

bool check_brackets(string expression){
    stack<char> stack;
    for(char c : expression){
        if(c == '[' || c == '{' || c == '(') stack.push(c);
        if((c == ']' && stack.top() != '[') || stack.empty()) return false;
        else stack.pop();
        if((c == '}' && stack.top() != '{') || stack.empty()) return false;
        else stack.pop();
        if((c == ')' && stack.top() != '(') || stack.empty()) return false;
        else stack.pop();
    }
    return stack.empty();
}

vector<string> vectorize_expression(string expression){
	vector<string> vec;
	string aux = "";
	for(char c : expression){
		if(c != ' ') aux += c;
		else{
			vec.push_back(aux);
			aux = "";
		}
	}
	if(aux != "" ) vec.push_back(aux);
	return vec;
}

float calc_posfix(string expression){
    stack<float> stack;

    float a = 0;
    float b = 0;

    vector<string> vec = vectorize_expression(expression);
    for(string e : vec){
        if(isdigit(e[0])) stack.push(stof(e));
        else{
            switch (e[0])
            {
                case '+':
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(a + b);
                    break;
                case '-':
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(a - b);
                    break;
                case '*':
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(a * b);
                    break;
                case '/':
                    a = stack.top();
                    stack.pop();
                    b = stack.top();
                    stack.pop();
                    stack.push(a / b);
                    break;
            default:
                break;
            }
        }
    }
    return stack.top();
}

bool check_posfix(string expression){
    stack<float> stack;

    vector<string> vec = vectorize_expression(expression);
    for(string e : vec){
        if(isdigit(e[0])){
            stack.push(stof(e));
            continue;
        }
        if(stack.size() < 2){
            return false;
        }
        stack.pop();
    }
    cout<<stack.top()<<endl;
    return stack.size() == 1;
}

float calc_infix(string expression){
    vector<string> vec = vectorize_expression(expression);
    stack<float> numbers;
    stack<char> operadores;

    for(string e : vec){
        if(isdigit(e[0])){
            numbers.push(stof(e));
        }
        if(e[0] == '(') operadores.push(e[0]);
    }
}

string posfix_to_infix(string expression);

int main() {
    int v[4] = {1,2,3,4};
    vector<int> vec = vet_to_vector(v, 4);
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;

    list<int> list = vet_to_flist(v, 4);
    for (int e : list)
    {
        cout<<e<<" ";
    }
    cout<<endl;


    string expression = "10 + 20 / 2 = ";
    vector<string> vec2 = vectorize_expression(expression);
    cout<<"[ ";
    for(string e : vec2){
        cout<<e<<", ";
    }
    cout<<" ]"<<endl;

    cout<<check_brackets("{[()]}")<<endl;

    cout<<calc_posfix("12 20 + 0.5 *")<<endl;

    cout<<check_posfix("12 20 + 0.5 *")<<endl;

    cout<<calc_infix("( ( ( 6 + 9 ) / 3 ) * ( 6 - 4) )")<<endl;


    
    return 0;
}