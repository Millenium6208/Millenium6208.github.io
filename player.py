from microbit import *
import radio

# Cerca il canale della Microbit Nascosta nel Laboratorio.
# Prova a cercare dal canale 20 al canale 25, cambiando il numero della variabile.
# Se troverai il canale giusto, cliccando sul Bottone A, sentirai un suono che ti guiderà alla Microbit

canale = 23

radio.config(channel=canale)
radio.on()

while True:
    if button_a.is_pressed():
        radio.send('Find')