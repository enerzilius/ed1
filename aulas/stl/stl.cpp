#include <iostream>
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

}

bool check_posfix(string expression);

float calc_infix(string expression);

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
    
    return 0;
}