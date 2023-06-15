#include <iostream>
#include <cmath>
using namespace std;

double p, q, r, s, t, u;

double f(double x) {
  return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
  while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6) {
    double left = 0.0;
    double right = 1.0;
    double mid;
    for(int i = 0; i < 100; i++) {
      mid = (left + right) / 2.0;

      double fl = f(left);
      double fr = f(right);
      double fm = f(mid);
      
      if(fl == 0) {
        printf("%.4lf\n", left); 
        break;
      }

      if(fr == 0) {
        printf("%.4lf\n", right); 
        break;
      } 
      
      if(fm == 0) {
        printf("%.4lf\n", mid); 
        break;
      } 

      if(fl * fr > 0) {
        printf("No solution\n");
        break;
      }

      if(fl * fm < 0) {
          right = mid;
      } else if(fm * fr < 0) {
          left = mid;
      }

      if(i == 99) printf("%.4lf\n", mid); 
    }
  }

  return 0;
}
