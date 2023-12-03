import RPi.GPIO as GPIO
from flask import Flask, render_template, request
app = Flask(__name__)
GPIO.setmode (GPIO.BCM)
GPIO.setwarnings(False)
ledRed = 13
ledYellow = 19
ledGreen = 26
ledRedSts = 0
ledYellowsts = 0
ledGreenSts = 0
GPIO.setup(ledRed, GPIO.OUT)
GPIO.setup(ledYellow, GPIO.OUT)
GPIO.setup(ledGreen, GPIO.OUT)
GPIO.output (ledRed, GPIO. LOW)
GPIO.output (ledYellow, GPIO.LOW)
GPIO.output (ledGreen, GPIO.LOW)
@app.route('/')
def index():
ledRedSts = GPIO.inout(ledRed)
ledYellowsts = GPIO.input(ledYellow)
ledGreenSts = GPIO. input (ledGreen)
templateData = { 'ledRed' : ledRedSts, 'ledYellow': ledYellowsts,
'ledGreen': ledGreenSts }
return render_template('index.html', **templateData)
@app.route('/<deviceName>/<action>')
def do(deviceName, action):
if deviceName == "ledRed": actuator = ledRed
if deviceName == "ledYellow": actuator = ledYellow
if deviceName == "ledGreen": actuator = ledGreen
if action == "on": GPIO.output (actuator, GPIO.HIGH)
if action == "off": GPIO.output (actuator, GPIO.LOW)
ledRedSts = GPIO. input (ledRed)
ledYellowsts = GPIO. input(ledYellow)
ledGreenSts = GPIO. input (ledGreen)
templateData = { 'ledRed': ledRedSts,'ledYellow': ledYellowsts, 'ledGreen' : ledGreenSts }
return render_template('index1.html',**templateData)
if __name__ == '__main__':
app.run(debug=True, port=80, host='0.0.0.0')
→ HTML File: index.html
<!DOCTYPE html>
<html>
<head>
<title> GPIO Control Web App</title>
<link rel="styleSheet" href="/home/pi/Documents/rpiWebServers/templates/style.css"/>
</head>
<body>
<img src="/home/pi/Documents/rpiWebServers/templates/img.jpeg" width="349px" height="193px" />
<h1>SMART HOME AUTOMATION USING RASPBERRY PI</h1>
<h2>STATUS OF ACTUATORS</h2>
<h3> RED LED --> {{ledRed}}</h3>
<h3> YELLOW LED--> {{ledYellow}}</h3>
<h3> GREEN LED --> {{ledGreen}}</h3>
<h2>LED CONTROL</h2>
<h3> RED LED CONTROL ==> <a href="/ledRed/on" class="button">TURN ON</a>
<a href="/ledRed/off" class="button">TURN OFF</a></h3>
<h3> YELLOW LED CONTROL ==> <a href="/ledYellow/on" class="button">TURN ON</a>
<a href="/ledYellow/off" class="button">TURN OFF</a></h3>
<h3> GREEN LED CONTROL ==> <a href="/ledGreen/on" class="button">TURN ON</a>
<a href="/ledGreen/off" class="button">TURN OFF</a></h3>
</body>
</html>
→ HTML File: style.css
body {
text-align: center;
background: #54ff9f; color: #fff5ee;
}
.button{
font: bold 16px Arial;
background-color:#EEEEEE;
padding: 1px;
border: 1px solid #CCCCCC;
}
