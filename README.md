# webbot

This is a rover that can be controlled by a web interface, and displays a real-time video feed to the user. 

### REQUIRED PACKAGES ###
Lightweight Communications and Marshalling (LCM)
- Internal messaging between software components. Allows canned messages to be send from the cgi handler
    to the motor controller.

LIGHTTPD
- Web server to serve the controls and video feed.
- Must be installed with Fast CGI enabled. 

Motion
- Real-time video server to process video data from a USB webcam and make it available to LIGHTTPD.


