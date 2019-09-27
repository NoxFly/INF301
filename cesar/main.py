# fonction pour decrypter (pour encrypter on aurait du mettre un + au lieu d'un - pour le -key)
def uncrypt(txt, key):
    return ''.join(list(map(lambda x: x if not x.isalpha() else chr((((ord(x.lower())-key)-97)%26)+97), txt)))

def crypt(txt, key):
    return ''.join(list(map(lambda x: x if not x.isalpha() else chr((((ord(x.lower())+key)-97)%26)+97), txt)))

# trouve et retourne la cle de cryptage en fonction de cles predefinies de recherche
def  find_key(txt, keys, cryptage=False):
    key = 0

    keys_in_txt = False

    while not keys_in_txt:
        key += 1
        if cryptage:
            txt2 = crypt(txt, key)
        else:
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
message = "Vaxk Uhu,\nMn tl ktblhg, et iknwxgvx whbm xmkx wx fblx, g'axlbmhgl itl t itllxk tn ietg\nU jnb t xmx ikxon ihnk vx zxgkx wx lbmntmbhgl. Cx kxlmx obzbetgmx, ikxobxgl\nfhb lb exl vahlxl xohenxgm wx mhg vhmx. Tn ytbm, jnx lx itllxkt-m-be lb ghmkx\nlxvhgwx fxmahwx wx vabyykxfxgm gx mbxgm itl ?\nFxbeexnkl lxgmbfxgml,\nTebvx.\nIL : c'tb wxmhnkgx et yhgvmbhg wx vxm xqxkvbvx, ihnk fxmmkx mhg fxlltzx t et\nlnbmx, be ytnm kxihgwkx 'atlmt et kxohenvbhg' ftbl wxvtex t e'hiihlx wx vx\nfxlltzx. Itk xqxfiex, lb vx fxlltzx xlm ng wxvtetzx wx vxltk wx 5 exmmkxl,\nbe ytnm wxvtexk et kxihglx wx -5 exmmkxl."
message2 = 'qjbcj uj anexudlrxw'
KEYS = ('bob','alice')


#print("key: ",find_key(message, KEYS, True))

# code le message de comment le crypter
i = 1
print("code: ", end="")
while crypt(message2, i) != 'hasta la revolucion':
    i -= 1
print(i)

# decode le message de comment le crypter
i = 1
print("decode: ", end="")
while uncrypt(message2, i) != 'hasta la revolucion':
    i += 1
print(i)

print(uncrypt("hasta la revolucion", 9))