#include<bits/stdc++.h>

bool checkRedundantBrackets(string exp) {
	int len = exp.length();
	if(len == 0)
	   return true;
	stack<int> st;
    
	for(int i=0; i<len; i++){
		
		if(st.empty()){
			if(exp[i] == ')')
			   return true;
			st.push(exp[i]);   
		}
		else if(exp[i] == ')'){
			int charCount = 0;
			while(!st.empty()){
				if(st.top() == '(')
				   break;
				charCount++;
				st.pop();
			}
			if(charCount <2)
			   return true;
			st.pop();   
		}
		else
		   st.push(exp[i]);   
	}
	return false;
}