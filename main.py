# fonction pour decrypter (pour encrypter on aurait du mettre un + au lieu d'un - pour le -key)
def uncrypt(txt, key):
    return ''.join(list(map(lambda x: x if not x.isalpha() else chr((((ord(x.lower())-key)-97)%26)+97), txt)))

# trouve et retourne la cle de cryptage en fonction de cles predefinies de recherche
def  find_key(txt, keys):
    key = 0

    keys_in_txt = False

    while not keys_in_txt:
        key += 1
        txt2 = uncrypt(txt, key)

        for i in keys:
            if i in txt2:
                keys_in_txt = True

    return key

# retourne les characteres avant le premier \n
def get_first_line(txt):
    line = ''
    c = txt[0]
    i = 0

    while c != '\n':
        line += c
        i += 1
        c = txt[i]
    
    return line


# le message et les cles predefinis de recherche
message = 'Hmjw Gtg,\nStzx sj utzatsx uqzx stzx jhmfsljw ij rjxxfljx xnruqjrjsy ufw jrfnq. H\'jxy ywtu wnxvzj. O\'fn unwfyj qj xjwajzw i\'jyzinfsyx utzw js kfnwj zs qnjz i\'jhmfsljx uqzx inxhwjy. O\'fn jkkfhj ytzyjx qjx ywfhjx'
KEYS = ('bob','alice')

print(uncrypt(message, find_key(get_first_line(message), KEYS)))