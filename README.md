# webbot
<<<<<<< HEAD

This is a rover that can be controlled by a web interface, and displays a real-time video feed to the user. 

This guide is intended to get you started setting up the WebBot. There are a lot of gaps that haven't been filled
by this guide, so it'll require a little work.

### REQUIRED PACKAGES ###
Lightweight Communications and Marshalling (LCM)
- Internal messaging between software components. Allows canned messages to be send from the cgi handler
    to the motor controller.

LIGHTTPD
- Web server to serve the controls and video feed.
- Must be installed with Fast CGI enabled. 

Motion
- Real-time video server to process video data from a USB webcam and make it available to LIGHTTPD.

### SETUP INSTRUCTIONS ###
See the wiring guide to wire the WebBot.

Copy the html file into the /var/www/ directory, or wherever lighttpd looks for the index.html file.
Make sure the motion server IP address and port in the html page match the motion server configuration files. 

Compile the .lcm file in the lib directory into one python and one cpp lcm classes (two compiles total). Make sure
the paths to these files in the dataHandler script and the cpp code is correct.

Compile the code in the cpp directory using g++ or another compiler. Some edits to the file names and paths in the 
beginning of the files may be necessary. Once the code is successfully compiled, make sure the files are executable
(chmod +x) and change the extension to .cgi. Copy the .cgi files to /var/www/cgi-bin.

I like to make the dataHandler script run on startup (copy the executable dataHandler script into /etc/init.d). 
This way you don't have to start the script manually before using the WebBot.

Load the .ino sketch file to the arduino. This is easy from a PC but can be done on the RPi.

### USAGE ###
Open your browser and enter the IP address of your RPi in the address bar. You should see the WebBot interface
come up. Use the on-screen buttons to control the WebBot. Enjoy!

=======
>>>>>>> 2c2705b1013424c26335d7c31e2df213b54d473a
