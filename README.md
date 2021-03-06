# ASCII Image Converter

Convert BMP images to TXT images by using ASCII art.

## Compile and Run

<h3>To compile:</h3>

> make

<h3>To generate all sample outputs from images under <code>in/</code> directory:</h3>

> make run_all

<h3>Or just generate a single sample:</h3>

> make run_<code>image</code>

or

> 	./ascii "input file" M N > "output file" // M and N are the dimensions of each pixel

<h3> Example: </h3>

> make run_woman

Before|After
|---|---|
![bmp](in/woman.bmp) | ![png](assets/woman.png)

## Bonus

Bonus part includes a short and fun code that generates a donut.

But this donut rotates around x, y and z axes.  

Please run and enjoy!

> make run_bonus

![video](assets/donut.gif)
