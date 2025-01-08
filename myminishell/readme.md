# MINISHELL PROJECT

Le but de ce projet est de recreer un shell en langage C.
L'utilisateur rentre des commandes comme dans bash et le programme doit se comporter de la meme maniere.

## PARTIE EXEC

Mon role dans ce projet a ete de faire la partie execution:
- execution des commande (Pipe, commande simple, redirections in-out-append-heredoc)
- gestion des signaux (ctrl +c, ctrl + d, ctrl + \)
- Renvoie des bons signaux de retour du programme
- Reproduction de certaines fonctions du shell comme echo, cd, unset, env, export, exit, pwd

--------------------Shell subsystems----------------------

- Variables d'environnements (globales) : la remplacer par sa vraie valeur
- Variables d'environnement (locales) : variables creer dans la session actuelle du shell
    => my_var="hello" que j'appelle avec $my_var
    => recuperation des variables avec la commande set


--------------------Builtins-----------------------------

cd : <direcoryname> || - || ....... || /../<direcoryname> || ~

- getcwd => obtenir le repertoir actuelle
- chdir => permet de changer le nouveau repertoire en specifiant en parametre le chemin

- Commande speciale
    cd - et cd -- => pas oblige    
    cd ~ => meme commande que cd mais marche quand meme sans l'env HOME 
    cd / => revient a la racine
    cd => retourne au home avec l'env. Si pas d'env HOME erreur "bash: cd: HOME not set"
- Erreur
    - No such file or directory
    - Permission Denied => Dossier ou j'ai pas les permissions
    - not a directory => rentrer dans un fichier

EXPORT

- ajouter une variable:
    - export salut=hello
    - export salut= hello => ceci ajoute seulement salut=
- modifier une variable existante
- afficher toutes les variables
- gerer le "export=" => qui ne fait rien
- Le nom de la variable export ne doit pas:
    - debuter par un chiffre 
    - Ne doit pas comporter de caracteres speciaux a par '_'

---------------------CODE------------------------

- creation d'un tableau de structure
    - chaque tableau contiendra la combinaison:
        => infile || redirection || commande || argument ||  redirection || outfile || pipe

---------------COMMANDE CHIANTE------------------

- Command1 < input.txt PAREIL QUE < input.txt command1
- Command1 < input.txt > output.txt => j'applique ma commande suivant l'entree input et j'ecris dans output
- Command1 >> output.txt < input.txt => Pareil que en haut mais j'append
- Command1 | Command2 >> output.txt < input.txt => Pareil que en haut mais avec PIPE
- Command1 < input.txt > output.txt 2>> error.txt => fichier avec deux redirections
- Command1 2> error.txt => redirection d'erreur
- Command1 2> error.txt > output.txt => je redirige deux fois (on peut redirection a l'infini)
- Si presence espace entre 2 et > bash interprete ca en tant que argument de la commande d'avant
    => Checker si c'est une redirection de stdin stdout ou stderr
- Heredoc << se comporte comme un redirin ou redirout

---------------MULTIPLE PIPE--------------

ls -l | head -n 2 | head -n 1

=> 2 pipes 3 redirections

redirection out vers l'ecriture du pipe1 

redirection in vers la lecture du pipe1
redirection out vers l'ecriture du pipe2

redirection in vers la lecture du pipe2

ls -l | head -n 1 | head -n 2 | head -n 2

=> 3 pipes 4 redirections

redirection out vers l'ecriture du pipe1

redirection in vers la lecture du pipe1
redirection out vers l'ecriture du pipe2

redirection in vers la lecture du pipe2
redirection out vers l'ecriture du pipe3

redirection in vers la lecture du pipe3

------------ PIPE ET REDIRECTIONS ------------------

- redirection OUT a gauche du pipe j'ecris fdans le file et pas dans le pipe
    - Quand je lis a droite j'aurai une entree vide
- Redirection IN a droite du pipe ne fait rien car je lis en priorite l'entree du pipe
    - Pipe en priorite sur redir IN
- les dernieres redirections IN ou OUT sont celles a prendre en compte
    - < output < output1 < cat -e => je cat le output1

------------ Les bon retours-----------

- Renvoyer le bon code de retour suivan l'erreur

------------- HEREDOC ---------------

- Rediriger au bon endroit si il y qune redirection out avec le Heredoc
- lire tant qu'il n'y a pas le caractere de fin de chaine
- quand je heredoc il faut que je check si j'ai bien une redirection
- <<eof << eof1 => il faut obligatoirement taper eof puis eof1 pour sortir

PROCEDURE

- Ecrire dans un document tampon => .heredoc
- Si il y a redirection rediriger ce document vers le nouveau
- le commande cat va ecrire le contenu du fichier heredoc dans la sortie

------------- GESTION ERREURS -----------

- Retourner le bon code erreur et le stocker
- Dans le cas d'une commande errone je n'ai pas forcement besoin de rentrer dans l'exe, pareil pour l'ouverture de fichier
- L'erreur de commandes doit arriver apres l'erreur de fichier
- Si la commande marche masi que le fichier ne s'ouvre pas je ne fais pas la commande
- 

Cas d'erreur

cmd pas bonne
file bon
 => Affichage commande pas bonne et creation du file 

cmd pas bonne 
file pas bon
=> affichage erreur file

cmd bonne
file pas bon
file 2 pas bon
=>erreur file1 pas le deux

TYPE D'ERREUR file

- no such file or directory => le fichier existe pas
- permission denied => Pas de permissions sur le fichier 
    - Pas les permissions
    - Un / pour signifier un chemin

si j'ai une commande
si j'ai une redirection

STATUS CODE $?

0 : success
127 : command not found
130 : equivalent au ctrl + c
131 : ctrl + \
1 : Permission Denied, no such file or directory
2 : Erreur syntaxe

cattt > output | ls -l => je retourne 0 car ls -l marche dans tous les cas
ls -l | catttttttt > output => je retourne 127 command not found

---------------------- SIGNAL ------------------------

- CTRL + C – SIGINT 2 => erreur 131
- CTRL + \ – SIGQUIT 3 => erreur 130
- CTRL + d – EOF => erreur 

- Faire des fonctions handler pour chaque SIGNAL

- ctrl + c :- nouvelle ligne 
            - heredoc => sort du heredoc et nouvelle ligne
            - process => sors et nouvelle ligne

- ctrl + d :- quitte le bash
            - si dans heredoc quitte en envoyant ce message d'erreur:
            Minishell: warning: here-document at line 1 delimited by end-of-file (wanted `eof')
            - si danc un process genre sleep => ne fait rien

- ctrl + \ :- Ne fais rien
            - process: quitte avec le message "Quit (core dumped)"
            - heredoc: ne fais rien

------------------- FREE -------------------

- t_env => qui correspond aux variables d'environnement env
- eofword => mots permettant la delimitation du heredoc
- fdpipe => nombre de fd alloue pour le pipe
- t_tree => Allocation de mon tree
- init_nodes => nouveau noeud 
- envp => qui correspond aux path de mes commandes

------------------- TESTS ------------------

ls -l
cat << eof
<< eof
ls -l << eof
cat << eof | ls -l
cat << eof << eof1
ls -l | cat << eof 
ls -l | head -n 2
ls -l | cat << eof | << aller
ls -l > output | cat << eof
cat << eof | cat << re
cat << eof | ls -l | cat << rien | cat << salut => leak

TESTER AVEC SIGNAUX CTRL + C / CTRL + D / CTRL + \

CTRL + \ dans le heredoc ne marche pas 