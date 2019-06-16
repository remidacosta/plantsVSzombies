======== PVZ : Plant VS Zombies ========
Membres du projet : 
-Rémi Dacosta, chef de projet,  numéro d'étudiant : 11605744
-Matthieu Lacôte, développeur, numéro d'étudiant : 1151688
-Ruben Grousset, développeur, numéro d'étudiant :11609646

Tutrice du projet: Elodie Desseree

Nous sommes des étudiants de Polytech Lyon en cursus préparatoire intégré ayant pour spécialité l'informatique.
Dans le cadre de LIFAP4 nous avons été invité à tester nos connaissances en programmation dans le langage C/C++
en menant à bout un projet, nous avos choisi de recréer le jeu Plante VS Zombie un jeu mobile bien connu. 
Le projet se déroule sur une période d'environ du 08/03/2018 au 24/04/2018.

Nom du projet sur la forge: 

-https://forge.univ-lyon1.fr/p1605744/PVZ.git



	=Description=
SPECIFICITE : l'utilisateur doit installer la bibliothèque SFML dans le dossier extern de l'archive pour pouvoir compiler.

-Commande de compilation : via CodeBlock (création d'un projet et spécification des options de compilation laissées à la discrétion de l'utilisateur, ne pas oublier de préciser qu'il faut compiler sous C++11) ou make (utilisation du Makefile)
-Execution : via CodeBlock ou ./bin/jeu.out dans la console

-Règle du jeu : 
Le jeu oppose les plantes aux zombies, ces derniers cherchent à envahir le jardin des plantes et celles-ci se défendent.
Le joueur contrôle les plantes et les zombies sont contrôlés par le jeu. 

Le jeu se déroule sur un terrain constitué de cases. Les zombies arrivent sur 5 lignes différentes de manières aléatoires 
et se déplacent de la droite vers la gauche. Sur chaque ligne il y a une tondeuse qui tue tous les zombies sur la ligne dès qu'un zombie 
la touche et disparaît définitivement ensuite, c'est une sorte de vie bonus. Le joueur peut placer des plantes sur les cases pour ralentir
la progression des zombies, les plantes coûtent un certain nombre de « soleils » qui sont des ressources. Chaque plante a un effet différent 
et donc un coût en ressource différent. Ces soleils sont générés de manières automatiques et aléatoires mais le joueur peut aussi planter des 
tournesols qui en produisent de manière régulière. 

Le joueur choisit la plante qu’il veut placer dans une interface proposant tous les types de plantes accessibles au joueur en fonction de sa progression. 
Il clique sur le type qui lui convient et doit à nouveau cliquer sur la case où il souhaite placer sa plante. Deux plantes ne peuvent pas être placées
sur une même case mais le joueur peut placer des plantes sur des cases ou se trouve des zombies. 

Le jeu suit une progression linéaire, à chaque nouveau niveau la difficulté augmente.

Chaque niveau se termine lorsque le joueur à éliminer tous les zombies ou lorsque les zombies ont envahi le jardin des plantes avec succès. 
Le jeu se termine lorsque le joueur a complété l’ensemble des niveaux. 



	=Archives=
il y a 4 dossiers dans l'archives :
data -> contient les sprites du jeu et les fichiers textes responsables de la configuration des niveaux,de celle des zombies et plante, du tutoriel et enfin du niveau actuel
extern -> contient la librairie sfml A INSTALLER
src -> contient tous les fichiers .h et cpp
doc -> contient ce README.txt, le diaporama de notre présentation, le diagramme des modules, le diagramme de GANTT et la documentation de notre code générée par doxygen dans le répertoire html (pour ouvrir le doxygen du projet, veuillez rentrer cette commande dans la console: firefox doc/html/index.html)
bin -> contient l'exécutable du jeu (généré par CodeBlocks) et l'ensemble des .dll nécessaire pour pouvoir lancer l'exécutable

Dans le dossier racine vous trouverez aussi un Makefile pour compiler notre jeu.				
