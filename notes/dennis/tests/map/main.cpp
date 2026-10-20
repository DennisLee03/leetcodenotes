#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {

  string s = "bbcc", t = "ccbc";

  size_t n = s.size();

  if(s.size() != t.size()) {
    cout << "NOT anagram\n";     
    return 0;
  }

  unordered_map<char, int> um1, um2;

  for(size_t i=0; i<n; i++) {
    if(um1.find(s[i]) != um1.end()) {
      um1[s[i]]++;
    } else {
      um1[s[i]] = 1;
    }
    if(um2.find(t[i]) != um2.end()) {
      um2[t[i]]++;
    } else {
      um2[t[i]] = 1;
    }
  }

  cout << "String s: \n";
  for(auto it = um1.begin(); it != um1.end(); it++) {
    cout << (*it).first << ": " << (*it).second << endl;
  }
  cout << "String t: \n";
  for(auto it = um2.begin(); it != um2.end(); it++) {
    cout << (*it).first << ": " << (*it).second << endl;
  }

  for(auto it = um1.begin(); it != um1.end(); it++) {
    // not found or not equal
    if(um2.find(it->first) == um2.end() || um2[it->first] != it->second) {
      cout << "NOT anagram\n";     
      return 0;
    }
  }
  cout << "anagram\n"; 

  return 0;
}