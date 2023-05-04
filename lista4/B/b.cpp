#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;
vector<string> logs;

int main() {
  int n, elem;
  string command;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> command;

    if(command == "insert") {
      cin >> elem;
      heap.push(elem);
      logs.push_back(command + " " + to_string(elem));
    
    } else if(command == "getMin") {
      cin >> elem;
      
      while(true) {
        if(heap.empty()) {
          heap.push(elem);
          logs.push_back("insert " + to_string(elem));
          logs.push_back(command + " " + to_string(elem));
          break;
        }
        
        if(elem == heap.top()) {
          logs.push_back(command + " " + to_string(elem));
          break;
        } else if(elem < heap.top()) {
          heap.push(elem);
          logs.push_back("insert " + to_string(elem));
          logs.push_back(command + " " + to_string(elem));
          break;
        } else {
          heap.pop();
          logs.push_back("removeMin");
        }
      }
    } else { // removeMin
      if(heap.empty()){
        // heap.push(0);
        logs.push_back("insert 0");
        // heap.pop();
        logs.push_back(command);
      } else {
        heap.pop();
        logs.push_back(command);
      }
    }
  }

  cout << logs.size() << endl;

  for(string& log : logs) {
    cout << log << endl;
  }

  return 0;
}
