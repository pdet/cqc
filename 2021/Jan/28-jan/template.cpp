
/* Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so
that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

*/

// Constraints:
// 1 <= s.length <= 10^5
// s[i] is one of  '(' , ')' and lowercase English letters

#include <string>

using namespace std;

string minRemoveToMakeValid(string s) {

}

int main(){

	//! First Test
	string test1 = "lee(t(c)o)de)";
	assert(minRemoveToMakeValid(test1) == "lee(t(c)o)de");

	//! Second Test
	string test2 = "a)b(c)d";
	assert(minRemoveToMakeValid(test2) == "ab(c)d");

	//! Third Test
	string test3 = "))((";
	assert(minRemoveToMakeValid(test3) == "");

    //! Fourth Test
	string test4 = "(a(b(c)d)";
	assert(minRemoveToMakeValid(test3) == "a(b(c)d)");

}
