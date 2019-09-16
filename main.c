#include <stdio.h>

// on defini une longueur max de chaine de caractere par defaut
#define MAX_LENGTH 1000

// initialisation des différentes fonctions
int is_alpha(char c); // retourne si oui ou non le charactere est une lettre
int is_upper(char c); // retourne si c'est une majuscule
int normalize_index(char c); // permet de revenir dans l'alphabet si on en sort avec le decalage
void decrypt(int key, char encoded[MAX_LENGTH], char decoded[MAX_LENGTH]); // decrypt le message encoded grace a la cle donnee dans decoded


int main(int argc, char *argv[]) {

  int key = 5; // index trouve
  char decoded[MAX_LENGTH]; // message decode, on a besoin d'allouer de la memoire pour ce qu'on stockera
  char encoded[] = "Hmjw Gtg, Stzx sj utzatsx uqzx stzx jhmfsljw ij rjxxfljx xnruqjrjsy ufw jrfnq. H'jxy ywtu wnxvzj. O'fn unwfyj qj xjwajzw i'jyzinfsyx utzw js kfnwj zs qnjz i'jhmfsljx uqzx inxhwjy, nq x'flny iz xjwajzw i'jcjwhnhjx 'FuutQfg'. O'fn jkkfhj ytzyjx qjx ywfhjx ijwwnjwj rtn jy gnjs rfqnsx xjwtsy hjzc vzn ijhtzawnwtsy rts xywfyfljrj. Oj y'fn hwjj zs htruyj xzw qj xjwajzw, oj hwtnx vzj ujwxtssj s'zynqnxj hj xjwajzw js hj rtrjsy jy stzx xjwtsx ywfsvznqqjx. Utzw xj htssjhyjw fz xjwajzw, nq d f ijx uwtlwfrrjx H, Ofaf tz Udymts vzn jcnxyjsy. Hmtnxnx qj qfslflj vzj yz uwjkjwjx jy yjqjhmfwlj qj .enu htwwjxutsifsy:\nmyyu://nr2fl-fuutqfg.z-lf.kw/xyfynh/itbsqtfi/FuutQfg-H.enu\nmyyu://nr2fl-fuutqfg.z-lf.kw/xyfynh/itbsqtfi/FuutQfg-Ofaf.enu\nmyyu://nr2fl-fuutqfg.z-lf.kw/xyfynh/itbsqtfi/FuutQfg-Udymts.enu\nOj yj htsxjnqqj ij yj kfrnqnfwnxjw fajh qf uqfyjktwrj FuutQfg. Utzw hjqf, qfshj  qj uwtlwfrrj 'hqnjsy-nsywtizhynts' vzj yz ywtzajwfx ifsx qj .enu. Hj uwtlwfrrj xj htssjhyjwf fz xjwajzw FuutQfg xzw qj utwy 9999. Zsj ktnx vzj yz xjwfx f q'fnxj, yz utzwwfx qfshjw q'jcjwhnhj 'uwtojyC' fajh qf htrrfsij 'qtfi'. H'jxy zs jcjwhnhj hfhmj vzj o'fn wfotzyj. Nq jxy nsanxngqj utzw qjx jyzinfsy·jx, jy oj q'fn ij uqzx uwtyjlj ufw zs rty ij ufxxj : 'xjhwjy'. Qfnxxj-d yts uwthmfns rjxxflj utzw rtn. S'tzgqnj ufx ij qj hwduyjw fajh qf rjymtij mfgnyzjqqj... Rjnqqjzwx xjsynrjsyx, Fqnhj."; // message encode

  decrypt(key, encoded, decoded); // on decrypt le message

  // on affiche les deux versions
  printf("Encoded: %s\n\n", encoded);
  printf("Decoded: %s\n\n", decoded);

  return 0;
}

void decrypt(int key, char encoded[MAX_LENGTH], char decoded[MAX_LENGTH]) {

  int i = 0;
  char c;

  // pour chaque charactere
  while (encoded[i] != '\0') {
    c = encoded[i];

    if (is_alpha(c)) { // si c'est une lettre, on decode
      char a = 'a';
      if(is_upper(c)) a = 'A'; 
      c = normalize_index((c - a) - key % 26) + a;
    }

    // on ajoute la lettre decodee
    decoded[i] = c;
    i++;
  }

  // on "ferme" la chaine de caratere
  decoded[i] = '\0';

}

int normalize_index(char c) {
  if (c < 0) { // si l'index de la lettre sort de l'alphabet, on le fait revenir dedans
    return c + 26;
  }
  return c;
}

int is_alpha(char c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'); // retourne si lettre est dans l'alphabet minuscule ou majuscule
}

int is_upper(char c) {
  return 'A' <= c && c <= 'Z';
}
