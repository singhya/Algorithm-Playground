#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	long long int a = 500000;
	long long int b = 1000000000;
	long long int c;
	scanf("%d", &a);
	scanf("%d", &b);
	c = a*b;
	long long int imin = std::numeric_limits<long long int>::min(); // minimum value
	long long int imax = std::numeric_limits<long long int>::max();
	cout<<c;
	//cout << imin << " " << imax << endl;
	return 0;
}
