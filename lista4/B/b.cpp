#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void handleInsert();
void handleGetMin();
void handleRemoveMin();

// priority_queue<int, int*, greater<int>> heap;
priority_queue<int, vector<int>, greater<int>> heap;
vector<string> logs;

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  string command;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> command;

    if(command == "insert") {
      handleInsert();
    } else if(command == "getMin") {
      handleGetMin();
    } else { // command == "removeMin"
      handleRemoveMin();
    }
  }

  cout << logs.size() << endl;

  for(string& log : logs) {
    cout << log << endl;
  }

  return 0;
}

void handleInsert() {
  int elem;
  cin >> elem;
  heap.push(elem);
  logs.push_back("insert " + to_string(elem));
  return;
}

void handleGetMin() {
  int elem;
  cin >> elem;
      
  while(true) {
    if(heap.empty()) {
      heap.push(elem);
      logs.push_back("insert " + to_string(elem));
      logs.push_back("getMin " + to_string(elem));
      break;
    }
    
    if(elem == heap.top()) {
      logs.push_back("getMin " + to_string(elem));
      break;
    } else if(elem < heap.top()) {
      heap.push(elem);
      logs.push_back("insert " + to_string(elem));
      logs.push_back("getMin " + to_string(elem));
      break;
    } else {
      heap.pop();
      logs.push_back("removeMin");
    }
  }

  return;
}

void handleRemoveMin() {
  if(heap.empty()){
    logs.push_back("insert 0");
    logs.push_back("removeMin");
  } else {
    heap.pop();
    logs.push_back("removeMin");
  }

  return;
}
