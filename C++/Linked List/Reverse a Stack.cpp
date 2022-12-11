/*
Reverse a Stack

You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.
For Example:
Alt txt

Input Format :
The first line of input contains an integer N, denoting the total number of elements in the stack.

The second line of input contains N integers separated by a single space, representing the order in which the elements are pushed into the stack.
Output Format:
The only line of output prints the order in which the stack elements are popped, all of them separated by a single space. 
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input stack itself.
Constraints:
1 <= N <= 10^3
-2^31 <= data <= 2^31 - 1

Time Limit: 1sec 
Sample Input 1:
6
1 2 3 4 5 10
Note:
Here, 10 is at the top of the stack.
Sample Output 1:
1 2 3 4 5 10
Note:
Here, 1 is at the top of the stack.
Sample Input 2:
5
2 8 15 1 10
Sample Output 2:
2 8 15 1 10
*/

#include <stack>
//time: O(n^2), space: O(n)
void reverseStack(stack<int> &input, stack<int> &extra) {
	if(input.empty()) return;

    int temp=input.top();
    input.pop();
    
    reverseStack(input,extra);
    while(input.size()>0){
        extra.push(input.top());
        input.pop();
    }
    
    input.push(temp);
    while(extra.size()>0){
        input.push(extra.top());
        extra.pop();
    }

}
