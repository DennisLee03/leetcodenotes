#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

int main() {

  cout << "Test unordered_set.\n";
  unordered_set<int> us1 = {1, 2, 4, 3, 5};

  // iterate elements
  for(auto it = us1.begin(); it != us1.end(); it++) {
    cout << (*it) << " ";
  } 
  cout << endl;

  // test insertion
  unordered_set<int> us2;
  us2.insert(87);
  us2.insert(100);
  us2.insert(14);
  for(auto it = us2.begin(); it != us2.end(); it++) {
    cout << (*it) << " ";
  } cout << endl;

  // find a key
  if(us1.find(1) != us1.end()) cout << "Found!\n";
  if(us1.find(87) == us1.end()) cout << "NOT Found!\n";

  cout << "Test set.\n";

  set<int> s1 = {6, 5, 4, 5, 7, 6, 8, 9};

  // iterate elements
  for(auto it = s1.begin(); it != s1.end(); it++) {
    cout << (*it) << " ";
  } 
  cout << endl;

  if(s1.find(6) != s1.end()) cout << "Found!\n";
  if(s1.find(87) == s1.end()) cout << "NOT Found!\n";

  return 0;
}