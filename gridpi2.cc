#include <iostream>
#include <cmath>

constexpr double gridpi2(unsigned npoints) {
	const auto total_points = npoints * npoints;
	double circle_points = 0;
	for (double j = 0; j < npoints; j++) {
		const auto y = j / npoints;
		for (double i = 0; i < npoints; i++) {
			const auto x = i / npoints;
			const auto distance = std::hypot(x, y);
			if (distance <= 1) {
				circle_points++;
			}
		}
	}
	const auto ratio = circle_points / total_points;
	const double pi_ish = ratio * 4;
	return pi_ish;
}

int main() {
	const unsigned npoints = 1000;
	constexpr auto comp_time_estimate = gridpi2(npoints);
	std::cout << "Our compile-time approximation of pi with " << npoints << " points is " << comp_time_estimate << ".";
	return 0;
}