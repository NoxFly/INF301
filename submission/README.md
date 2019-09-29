# Apprentissage Par Problèmes 1 : Ydana Wheya (Chere Alice)

Voici le rendu final de notre code pour l'APP1. Ce dernier est composé d'un dossier contenant tout les fichiers nécessaires a la compilation de notre exécutable APP1 qui valide de lui même tout les exercices que nous avons réussi. Nous avons décider de regrouper tout les exercices dans un seul exécutable pour plus de clarté et une plus grande simplicité d'utilisation.


## Groupe d'APP

Nom du groupe : **Caesar Salad**

Membres (par ordre alphabétique):

Avrilionis Photis, Moussolna Adam, Russo Lilian, Thivolle Dorian, Wicaksono Pradityo, Zhan Jizong


## Installation & utilisation

Pour compiler les programmes, exécutez la commande

```sh
make
```

Un exécutable sera crée dans le même répertoire. Pour lancer le programme, vous devez indiquer vos identifiants AppoLab en arguments comme ceci :

```sh
./app1 <identifiant_appolab> <mot_de_passe_appolab>
```

Ce programme validera automatiquement les exercices suivants sur AppoLab: _projetX_, _decrypte-v1_, _planB_, _crypteSeq_, (Nothwoods partiellement implémenté - voir section Bugs connus ci-dessous).


## Description des packetages

Pour garder les implémentations des différentes techniques de cryptage séparés et d’éviter de surcharger notre fichier principal, nous avons séparés leurs implémentations des différentes en packetages. Ceux-ci sont décrits ci-dessous :

- `main.c` contient la logique nécessaire pour faire valider les exercice sur AppoLab.

  Rem: Vous pouvez configurer les paramètres relatifs à AppoLab aux lignes 15 et 16.

- `client.h` et `client.c` contiennent la logique nécessaire pour se connecter et interagir avec le serveur AppoLab.

- `caesar.h` et `caesar.c` contiennent la logique nécessaire au cryptage et décryptage de Codes César.

- `type_char_seq.h` et `type_char_seq.c` contiennent l'implémentation du type et des fonctions de manipulation de séquences de caractères, nécessaire pour implémenter les algorithmes crypteSeq.

  Rem: Afin d’éviter des conflits entre les séquences de caractères et les séquences de couples, nous avons préfixé toutes les fonction de manipulation des séquences de caractères par `char_seq_`.

- `char_seq.h` et `char_sec.c` contiennent les fonction additionnel nécessaire à l'algorithme cryptseq 

- `type_pair_sec.h` et `type_pair_sec.c` contienne l'implémentation du type et des fonctions de manipulation de séquences de pair de caractères, nécessaire pour l'implémentation de l'algorithme Northwoods

- `pair_sec.h` et `pair_sec.c` contiennent les fonction additionnelles nécessaire pour la réalisation de l'exercice Northwoods
\TO BE COMPLETED

## Bugs connus

Un bug récurent apparaît au caractère 1433 de notre algorithme d'encryptage de Nothwoods qui ne nous permet pas de valider l’exercice Nothwoods sur AppoLab. Cependant cet algorithme produit le bon résultat pour les chaînes suivantes: `abcbcca`.
