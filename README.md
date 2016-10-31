
#Usage

<pre><code>
gr-fchdetection$ mkdir build
gr-fchdetection/build$ cd build
gr-fchdetection/build$ cmake ../
gr-fchdetection/build$ make
gr-fchdetection/build$ cd ../python
gr-fchdetection/python$ ./detect.py -I input.cfile > somefile.output
</code></pre>

Then you can plot the "somefile.output" with any tools (matlab,matplotlib...) you like.

#Reminder
This program implements the algorithm of "Robust Frequency Burst Detection Algorithm for 
GSM/GPRS",G. Narendra Varma, Usha Sahu, G. Prabhu Charan. The copyright of this algorithm
remains to them. Be careful when you use it.
