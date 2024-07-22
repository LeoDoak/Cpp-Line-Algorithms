# Cpp-Line-Algorithms
* Completed for CSC-370 @ UNCW
* Used C++m & CImg Library, compiled on a Mac M1 

## Line - Drawing Algorithms: 
### Bezier: (Description)
* A Bezier curve can be calculated by using De Casteljau’s algorithm. I implemented this equation, $New\ point\ at\ t-level=(t-1)p_i+\ t\ \ast\ p_{i+1}$, in my code. A Bezier curve is a parametric curve that has smooth edges. It is calculated by starting at a t-level, finding along each edge, connecting those together and then finding a point along that connected line at the t-level, this point is the point along the curve. The equation is used to calculate the point for each step size along the curve. In my code I go through and get the step size points along each line of the point. Then I keep on running the equation above until I’m left with two points remaining, then I can do a modified midpoint equation with the step size to get the point along that curve at that step value. it pretty much just calculates the points for a degree less each time so each iteration I lose a degree and then when the degree is 2, I can find the point along the curve. Some of the challenges included segmentation errors, and problems with not clearing vectors or not adding to the vector correctly. I also had a big issue with trying to figure out a good way to start and was stuck on just being able to create a 3-point curve for a little while. Once I figured out that the end goal was to just have two points remaining then it became a lot easier to understand. 
### Chaikins: (Description)
* In Chaikins algorithm, the formula is to find the points is  $p_{new(1)}=\frac{3}{4}p_i\ +\ \frac{1}{4}p_{i+1}$, and then to find the next point can be found using $p_{new(2)}=\frac{1}{4}p_i\ +\ \frac{3}{4}p_{i+1}$. The algorithm keeps on running these equations with the new points and eventually a curve begins to appear. My implementation would draw the line between the points, get the new points from the formula, clear the temp vectors, and draw the lines with the new lines. This process would get repeated whoever many times is necessary in our case, 6 times. Most of my problems with this came with the clearing of the vectors and making sure that everything happened in the correct for loop. As it was very easy to put a bracket in the wrong place messing up the loops completely. 


## How to compile: 
* Make sure to have XQuartz donwloaded (Mac)
* Compile with a path to include XQuartz




