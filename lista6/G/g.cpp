#include <iostream>
#include <cmath>

using namespace std;

double f(double p, double q, double r, double s, double t, double u, double x);

int main(){
	// ios::sync_with_stdio(false);
	double p, q, r, s, t, u;
	double left, right, x;

	while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6){
		left = 0.0;
		right = 1.0;
    double fl = f(p, q, r, s, t, u, left);
    double fr = f(p, q, r, s, t, u, right);

    if(fl == 0.0) {
      printf("%.4f\n", left);
      continue;
    }

    if(fr == 0.0) {
			printf("%.4f\n", right);
      continue;
    }

		if(fl * fr > 0) {
			printf("No solution\n");
			continue;
		} 
		
		for(int i = 0; i < 100; i++) {
			x = (left + right) / 2.0;
			double fx = f(p, q, r, s, t, u, x);
			
			if(fl * fx < 0) {
				right = x;
			} else if(fr * fx < 0) {
				left = x;
			} else {
				break;
			}
		}
		printf("%.4f\n", x);
	}

	return 0;
}

double f(double p, double q, double r, double s, double t, double u, double x) {
	return (p * exp(-x)) + (q * sin(x)) + (r * cos(x)) + (s * tan(x)) + (t * x * x) + u;
}
