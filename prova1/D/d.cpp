#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int ni;
  scanf("%d", &ni);
  vector<int> vetor;

  for(int i = 0; i < ni; i++)
  {
    int si;
    scanf("%d", &si);
    vetor.push_back(si);
  }
  
  sort(vetor.begin(), vetor.end());

  int k = 0;
  int l = ni / 2;
  int sum = 0;

  while(true){
    if(k == ni / 2 || l == ni)
    {
      break;
    }

    if(2 * vetor[k] <= vetor[l])
    {
      sum++;
      k++;
      l++;
    }
    else
    {
      l++;
    }
  }

  cout << ni - sum;

  return 0;
}