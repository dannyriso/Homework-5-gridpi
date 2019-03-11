gridpi.cc aproximates the value of pi using a grid method.

The gridpi function takes in an unsigned, npoints, of the
number of points in one dimension of the grid. It then
calculates each point's distance from one corner of the grid;
each point that is 1 or less away from the corner is counted as
a circle point. Then, all the circle points are divided by the
total number of points. This total is multiplied by 4, and the
result is returned.

The main function tests the gridpi function for different values
of npoints; the results are listed below.
	npoints = 10; estimate = 3.52
	npoints = 100; estimate = 3.1812
	npoints = 500; estimate = 3.14938
	npoints = 1000; estimate = 3.14554
	npoints = 10,000; estimate = 3.14199