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
message2 = "Hmjw Gtg, Stzx sj utzatsx uqzx stzx jhmfsljw ij rjxxfljx xnruqjrjsy ufw jrfnq. H'jxy ywtu wnxvzj. O'fn unwfyj qj xjwajzw i'jyzinfsyx utzw js kfnwj zs qnjz i'jhmfsljx uqzx inxhwjy, nq x'flny iz xjwajzw i'jcjwhnhjx 'FuutQfg'. O'fn jkkfhj ytzyjx qjx ywfhjx ijwwnjwj rtn jy gnjs rfqnsx xjwtsy hjzc vzn ijhtzawnwtsy rts xywfyfljrj. Oj y'fn hwjj zs htruyj xzw qj xjwajzw, oj hwtnx vzj ujwxtssj s'zynqnxj hj xjwajzw js hj rtrjsy jy stzx xjwtsx ywfsvznqqjx. Utzw xj htssjhyjw fz xjwajzw, nq d f ijx uwtlwfrrjx H, Ofaf tz Udymts vzn jcnxyjsy. Hmtnxnx qj qfslflj vzj yz uwjkjwjx jy yjqjhmfwlj qj .enu htwwjxutsifsy:\nmyyu://nr2fl-fuutqfg.z-lf.kw/xyfynh/itbsqtfi/FuutQfg-H.enu\nmyyu://nr2fl-fuutqfg.z-lf.kw/xyfynh/itbsqtfi/FuutQfg-Ofaf.enu\nmyyu://nr2fl-fuutqfg.z-lf.kw/xyfynh/itbsqtfi/FuutQfg-Udymts.enu\nOj yj htsxjnqqj ij yj kfrnqnfwnxjw fajh qf uqfyjktwrj FuutQfg. Utzw hjqf, qfshj  qj uwtlwfrrj 'hqnjsy-nsywtizhynts' vzj yz ywtzajwfx ifsx qj .enu. Hj uwtlwfrrj xj htssjhyjwf fz xjwajzw FuutQfg xzw qj utwy 9999. Zsj ktnx vzj yz xjwfx f q'fnxj, yz utzwwfx qfshjw q'jcjwhnhj 'uwtojyC' fajh qf htrrfsij 'qtfi'. H'jxy zs jcjwhnhj hfhmj vzj o'fn wfotzyj. Nq jxy nsanxngqj utzw qjx jyzinfsy·jx, jy oj q'fn ij uqzx uwtyjlj ufw zs rty ij ufxxj : 'xjhwjy'. Qfnxxj-d yts uwthmfns rjxxflj utzw rtn. S'tzgqnj ufx ij qj hwduyjw fajh qf rjymtij mfgnyzjqqj... Rjnqqjzwx xjsynrjsyx, Fqnhj."

KEYS = ('bob','alice')

print(uncrypt(message, find_key(get_first_line(message), KEYS)))
print(uncrypt(message2, find_key(get_first_line(message2), KEYS)))