# ESP32 Web Server LED Control Documentation

## Overview
This code creates a WiFi access point using an ESP32 microcontroller and sets up a web server to control two LEDs remotely. The server provides a web interface with ON/OFF buttons for each LED.

## Features
- Creates a WiFi access point named "ESP32" with password "12345678"
- Assigns static IP address 192.168.1.1 to the ESP32
- Web server running on port 80
- Web interface to control two LEDs (GPIO 26 and 27)
- Responsive HTML design for mobile and desktop browsers

## Hardware Setup
- Connect two LEDs to GPIO pins 26 and 27
- Add appropriate current-limiting resistors (typically 220Ω)

## Web Interface
The server provides these endpoints:
- `/` - Main control page (shows LED status and control buttons)
- `/led1on` - Turns LED1 (GPIO26) ON
- `/led1off` - Turns LED1 OFF
- `/led2on` - Turns LED2 (GPIO27) ON
- `/led2off` - Turns LED2 OFF

## Usage
1. Power on the ESP32
2. Connect to the "ESP32" WiFi network from any device
3. Open a browser and navigate to http://192.168.1.1
4. Use the web interface buttons to control the LEDs

## Customization
- Change `ssid` and `password` constants to modify WiFi credentials
- Modify `LED1pin` and `LED2pin` to use different GPIO pins
- Adjust the HTML in `SendHTML()` function to change the web interface appearance

## Dependencies
- WiFi.h (ESP32 WiFi library)
- WebServer.h (ESP32 WebServer library)



Note: For security in production environments, use stronger WiFi credentials than the default ones provided.
