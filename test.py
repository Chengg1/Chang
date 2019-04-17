import pyttsx3 as pys
import speech_recognition as sr
import pocketsphinx
import pyaudio
import random,os
import webbrowser
import smtplib
import requests
import time
import wikipedia
import datetime
from weather import Weather
hello = ['hi','hey','what\'s up','yuh','hello']
var1 = ['who made you', 'who created you']
var3 = ['what time is it', 'what is the time', 'time']
var4 = ['who are you', 'what is your name']
cmd1 = ['open browser', 'open google','open website']
cmd2 = ['play music', 'play songs', 'play a song', 'open music player']
cmd3 = ['open youtube', 'i want to watch a video']
cmd4 = ['tell me the weather', 'weather', 'what about the weather']
cmd5 = ['exit', 'close', 'goodbye', 'nothing']
repfr = ['youre welcome', 'glad i could help you']
responses = ['Okay', "I'm fine"]
engine = pys.init()
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)
rate = engine.getProperty('rate')
engine.setProperty('rate', rate - 25)
def listen():
    r = sr.Recognizer()
    print("1")
    with sr.Microphone() as source:
        r.pause_threshold = 1
        r.adjust_for_ambient_noise(source, duration=1)
        audio = r.listen(source)
    try:
        command = r.recognize_google(audio).lower()
        print('You said: ' + command + '\n')
    except sr.UnknownValueError:
        speak('Your last command couldn\'t be heard')
        command = listen();
    return command
def gooffline():
    speak('ok sir')
    speak('closing all systems')
    speak('disconnecting to servers')
    speak('going offline')
    quit()
def speak(text):
	engine.say(text)
	engine.runAndWait()
def media():
	speak('ok_sir')
	speak('starting required application')
	speak('what do you want me to play for you')
	k = listen()
	speak('ok sir playing'+k+'for you')
	os.startfile('F:/Javis/MP3'+k+'.mp3')
def online():
	speak('ok sir')
	speak('all systems have been started')
	speak('now i am online sir')
	speak("what can I do for you?")
def shutdown():
    speak('understood sir')
    speak('connecting to command prompt')
    speak('shutting down your computer')
    os.system('shutdown -s')
def mainfunction(command):
	if command in var1:
		speak("I was created by Chang right in his computer.")
	elif command in hello:
		speak('Hi.I am Vivant.Please call me by my name.')
	elif command in var3:
		speak(d.strftime("%A %d. %B %Y"))
	elif command in var4:
		speak("I am Vivant")
	elif command in cmd1:
		speak('opening google')
		webbrowser.open('www.google.com')
	elif 'open facebook' in command:
		speak('opening facebook')
		webbrowser.open('www.facebook.com')
	elif command in cmd3:
		speak('opening youtube')
		webbrowser.open('www.youtube.com')
	elif command in cmd5:
		gooffline()
	elif 'shutdown' in command:
		shutdown()
	else:
		webbrowser.open('www.google.com/search?q='+command)


if __name__ == "__main__":
	online()
	while True:
			mainfunction(listen()) 
