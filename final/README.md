This is ny mark down file for my final project.

I started by creating a new folder in my github account and cpying the files from lab10.2 into it because that
is the lab that my library will be modeled after (the google earth lab)

I then spant alot of time going over and refreshing mysekf on the material from lab 12.1 amd 11.1
because those were the labs that we learned makefiles in and went over how to impliment libraries

I reworked my lab10.2 to make the .cpp file into a library. I did this by changing the extensions in the make file
and adding in section to install and run the new library in the project. I also got rid of the old parts of the code 
that I did not need for the final project.

I ran into some issues connecting my need main.cpp and utils.cpp to the make file, but I say that in the example
from the lessons we uses a seperare folder for each .cpp file, and once I added those in it was a simple fix.

I then added in an adition parameter to all the functions to allow the logging function to write into the logg.txt
file. it was just a simple ofstream variable.

I wanted to add in some interactive options for the user, so I implimented the options library, but ran into
an issue where the file thought than any information added in (like the -k option for the CSV file) was also 
an option choice entered by the user, so I decided to go a different route.

I wanted the user to be able to create a logged list, like a flight record where they could document the order in which
they wanted to visit each city. I did this by creating a struct for the city name, and the order to visit in.
I had a very hard time passing the Stuct back and forth between the unit.cpp and the main driver. I tried having it be a global
variable, and an extern but niether worked correctly so I declared it as static and passed it in as a parameter as well.

Finally I added the section for the user to imput their desired number options. I had them orignally enter the long string of 
numbers all at once, then I decided to enter them one at a time would be simpler. I created a second struct array to allow
the new order of cities visited to be added back into the log file after the user changes them.

Im happy with how my final project turned out, even if I ran into some issues and had to step away from my computer 
quite a few times.
