from microbit import *
import radio, music

radio.config(channel=23)
radio.on()

def find():
    set_volume(255)
    music.play(['b5:1', 'b5:2'])
    set_volume(127)
    music.play(['b5:2', 'b5:2', 'b5:2'])
    sleep(1000)

while True:
    msg = radio.receive()
    # When receive a msg
    if msg:
        for i in range(3):
            find()
        msg = False