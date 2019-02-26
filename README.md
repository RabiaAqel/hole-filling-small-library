



## Hole Filling Small Library
Small image processing library that fills holes in images.
The library supports Grayscale images, while the CMD Utility accepts
two RGB images: an input image and another image which marks the hole mask.


![input](/sample_images/hole-filling_screenshot.jpg?raw=true "Input Image")

## Requirements

> C++11

> OpenCV 4.0.0

## Usage:
##### HoleFilling >

##### HoleFilling > fill image-path mask-path z epsilon connectivity-type
### Example:
##### HoleFilling > fill ../sample_images/cat.jpg ../sample_images/cat_mask.jpg 20 0.0001 4

## Modules

* image
	* pixel
		* Pixel : represents a pixel
		* PixelConnectivity : supports 4 and 8 connectivity
	* HoleFillingImage : abstract image with hole
	* GrayscaleImage : implements HoleFillingImage

* utils
	* ImageUtil : utils reading, writing, float normalization, and converting 	images

* weightfunction
	* WeightFunction : abstract weightfunction for two coordinates (pixels).
	In order to support arbitrary weightfunction as strategy
	* EucledianDistance : implements a WeightFunction

* filler
	* FillingStrategy : abstract filling class to support various filling strategies.
	* DefaultFillingStrategy : implements a FillingStrategy
	* HoleFiller : a hole filler which works with HoleFillingImage, WeightFunction, and FillingStrategy
* exception
	* EmptyImage : input image is empty
	* IllegalEpsilon : smaller or equals to 0
	* IllegalZ : smaller or equals to 0
	* IllegalPixelConnectivity : unimplemented connectivity
	* SizeMismatch : image and mask differ in size


## Algorithm Complexity

In order to calculate the filling color for each hole pixel, we iterate all boundary pixels.

> Consider the Boundary pixels set as B and denote |B| = n,

> Consider the Hole pixels set as H and denote |H| = m,

Therefore, we get O(n x m)

> Note that all areas of two-dimensional shapes are bounded by O(s\^2) if s is the perimeter.

We can express the complexity as O(n ^ 3)

## Approximate O(n) Algorithm Complexity


In order to acheive linear time, we need to estimate the interpolation for each hole pixel in constant time instead of running over all of the boundary pixels for each hole pixel.
One way to acheive such approximation is to go over only connected boundary components in a circular manner.

First iteration is to calculate internal maximum boundary (inside the hole).
For each, instead of iterating over all the boundary pixels, we iterate over its connected pixels to estimate the intensity. (Either 4 or 8)
The next iteration woul be iterating the inner boundary of the previous while for each pixel we o the same.
We continue in the described manner till we reach the centroid of the 2D hole.




