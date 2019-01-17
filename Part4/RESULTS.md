Results

Python:
The Python program always gives a random value for i. This might be due to the GIL and the fact that i is a global variable. So both threads change the value of i concurrently, this might corrupt the data.

C: ()
The result is always i = 0. This might be due to the fact, that both threads are finishing their work and i is therefore incremented and decremented 1000000 times. (Even though a random value for i was expected.)

Go:
The result for i is always 0. (Also here, random value was expected.)
