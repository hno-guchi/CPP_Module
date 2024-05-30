// Jacobsthal number
// n  = 0; J(0) = 0
// n  = 1; J(1) = 1
// n >= 2; J(n) = J(n - 1) + 2 * J(n - 2)

#include <iostream>
int	jacobsthalNumber(int n) {
	if (n == 0) {
		return (0);
	}
	if (n == 1) {
		return (1);
	}
	int	twoPrev = 0;
	int	onePrev = 1;
	int	numN = 0;
	for (int i = 2; i <= n; i++) {
		numN = onePrev + 2 * twoPrev;
		twoPrev = onePrev;
		onePrev = numN;
	}
	return (numN);
}

int	main() {
	for (int i = 1; i < 20; i++) {
		std::cout << jacobsthalNumber(i) * 2 << ", " << std::flush;
	}
	return (0);
}
