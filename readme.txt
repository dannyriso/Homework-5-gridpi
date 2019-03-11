gridpi.cc aproximates the value of pi using a grid method;
gridpi2.cc does the same, but all during compile time.

The gridpi and gridpi2 functions take in an unsigned, npoints,
of the number of points in one dimension of a grid. They then
calculate each point's distance from one corner of the grid;
each point that is 1 or less away from the corner is counted as
a circle point. Then, all the circle points are divided by the
total number of points. This total is multiplied by 4, and the
result is returned.

The main function tests the gridpi function for different values
of npoints; the results are listed below.
	npoints = 10; estimate = 3.52
	npoints = 100; estimate = 3.1812
	npoints = 1000; estimate = 3.14554
	npoints = 10,000; estimate = 3.14199

Since the gridpi function uses two for loops, each running for
npoints iterations, O(npoints^2).

Runtimes for the same npoints values:
	npoints = 10; time = 0.007s
	npoints = 100; time = 0.008s
	npoints = 1000; time = 0.077s
	npoints = 10,000; time = 4.472s

These runtimes aren't representative of O(npoints^2). When
npoints increases by a factor of 10, runtime should increase
by a factor of 100, which obviously doesn't happen except
loosely when npoints increases from 100 to 1000. It does take
progressively more time to compute as npoints increases, just 
ot at the predicted rate.

Creating a new constexpr function which ran at compile time
resulted in the following runtimes:
	npoints = 10; time = 0.006s; estimate = 3.52
	npoints = 100; time = 0.019s; estimate = 3.1812
	npoints = 1000; time = 0.049s; estimate = 3.14554

With the gridpi2 function, although all the estimates remained
the same, there's obviously a big difference in runtimes. This
is because none of the calculations were changed, only adjusted
so they could be carried out during compilation and then
reported during runtime. Correspondingly, although the runtimes
for all values of npoints are roughly the same, it did take
longer for the program to compile as npoints increased, since
all the results were fully calculated before running.