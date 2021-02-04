
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
#include <assert.h>
#include <iostream>

using namespace std;

static char result[10000];

string minRemoveToMakeValid(const string &s) {
  int counter = 0;
  int result_idx = 0;
  for(auto c : s){
    if(c == '('){
      counter++;
    }
    else if(c == ')'){
      if(counter == 0){
        continue;
      }
      counter--;
    }

    result[result_idx] = c;
    result_idx++;
  }

  if(counter > 0){
    int found_parens = 0;
    int paren_idx;
    for(paren_idx = result_idx; paren_idx > 0; paren_idx--) {
      if (result[paren_idx - 1] == '(') {
        found_parens++;
        if (found_parens == counter) {
          break;
        }
      }
    }
    int new_result_idx = paren_idx - 1;
    for(int idx = new_result_idx; idx < result_idx; idx++) {
      if (result[idx] != '(') {
        result[new_result_idx++] = result[idx];
      }
    }
    result_idx = new_result_idx;    
  }

  return string(result, result_idx);
}
/*
int positions[10000];

string minRemoveToMakeValid2(const string &s) {
  int paren_count = 0;
  for(int i = 0; i < s.size(); i++) {
    auto c = s[i];
    if(c == '('){
      positions[paren_count++] = i;
    } else if(c == ')'){
      if (paren_count == 0) {
        // this ones
        continue;
      }
      paren_count--;
    }
  }
  return string(result, result_idx);
}*/

int main(){

	//! First Test
	string test1 = "lee(t(c)o)de)";
	assert(valid(minRemoveToMakeValid(test1)));

	//! Second Test
	string test2 = "a)b(c)d";
	assert(minRemoveToMakeValid(test2) == "ab(c)d");

	//! Third Test
	string test3 = "))((";
	assert(minRemoveToMakeValid(test3) == "");

    //! Fourth Test
	string test4 = "(a(b(c)d)";
	assert(minRemoveToMakeValid(test4) == "(a(bc)d)");

	string test5 = "(a)(((((b";
	assert(minRemoveToMakeValid(test5) == "(a)b");

	string test6 = "(a)(opwke(pa(q(r(b";
	assert(minRemoveToMakeValid(test6) == "(a)opwkepaqrb");

  string test7 = "((a)((a)";
	assert(minRemoveToMakeValid(test7) == "((a)a)");

  string test8 = "(a))(b))";
	assert(minRemoveToMakeValid(test8) == "(a)(b)");

    string test9 = "(iwjrajewriojaerwioajwerojaweorijaweoijaweeriojawer";
	assert(minRemoveToMakeValid(test9) == "iwjrajewriojaerwioajwerojaweorijaweoijaweeriojawer");

  string test10 = "";
	assert(minRemoveToMakeValid(test10) == "");

  string test11 = "))abc";
	assert(minRemoveToMakeValid(test11) == "abc");

}
