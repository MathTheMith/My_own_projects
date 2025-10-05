# Tetris - Jeu avec support manette Xbox

Un clone de Tetris moderne développé en C avec Raylib, incluant toutes les mécaniques classiques : système de bag 7, hold, hard drop, et preview des prochaines pièces.

## 📋 Prérequis

- **Windows 10/11**
- **MSYS2 MINGW64** OU **Make pour Windows** (via Chocolatey)
- **Manette Xbox** (USB ou Bluetooth)

## 🛠️ Installation et Compilation

### Option 1 : Avec MSYS2 (recommandé)

1. Télécharge MSYS2 depuis [https://www.msys2.org/](https://www.msys2.org/)
2. Installe-le (chemin par défaut : `C:\msys64`)
3. Lance **MSYS2 MINGW64** depuis le menu Démarrer (icône violette)
4. Installe les outils :
bash
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-raylib
   pacman -S make

Navigue vers le projet et compile :

bash   cd "/c/Users/VotreName/chemin/vers/tetris"
   make clean
   make
Option 2 : Avec PowerShell/CMD

Installe Chocolatey (gestionnaire de paquets Windows) :

Ouvre PowerShell en Administrateur
Exécute :

powershell   Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

Installe Make :

powershell   choco install make

Installe MinGW et Raylib (si pas déjà fait via MSYS2) :

Utilise MSYS2 pour installer gcc et raylib (étapes ci-dessus)
Ajoute C:\msys64\mingw64\bin au PATH Windows


Compile :

Redémarre PowerShell/CMD (mode normal)
Navigue vers le projet :



cmd   cd C:\Users\VotreName\chemin\vers\tetris

Compile :

cmd   make clean
   make

🚀 Lancer le jeu
Depuis l'Explorateur Windows :

Double-clique sur tetris.exe

Depuis un terminal :
	./tetris.exe

🎮 Contrôles Manette
ActionBoutonDéplacer gauche/droiteStick gauche ou D-padRotation horaireBouton A (bas)Rotation antihoraireBouton B (droite)Hard Drop (chute instantanée)D-pad hautSoft Drop (descente rapide)D-pad basHold (réserver une pièce)L1 / LB
📦 Distribution
Pour distribuer le jeu à d'autres personnes :

Copie les DLLs nécessaires :

bash   # Dans MSYS2
   cp /mingw64/bin/libraylib.dll .
   cp /mingw64/bin/glfw3.dll .

Crée un dossier avec :

   MonTetris/
   ├── tetris.exe
   ├── libraylib.dll
   └── glfw3.dll

Zippe et partage ce dossier
L'utilisateur final n'a qu'à extraire et lancer tetris.exe - aucune installation requise

🏗️ Structure du projet
tetris/
├── src/
│   ├── main.c
│   ├── game/          # Logique de jeu
│   │   ├── game_logic.c
│   │   └── input_handler.c
│   ├── render/        # Affichage
│   │   ├── draw_game.c
│   │   └── draw_pieces.c
│   ├── pieces/        # Gestion des pièces
│   │   ├── piece_collision.c
│   │   ├── piece_lock.c
│   │   └── piece_rotation.c
│   └── utils/         # Utilitaires
│       ├── bag_system.c
│       └── line_clear.c
├── include/           # Headers (.h)
├── obj/               # Fichiers objets (générés)
├── Makefile
└── README.md
✨ Fonctionnalités

Système de bag 7 (vraie génération aléatoire Tetris moderne)
Hold piece (garder une pièce en réserve)
Preview des 5 prochaines pièces
Hard drop et soft drop
Lock delay (1 seconde pour repositionner)
Wall kicks (rotation près des murs)
Détection de lignes complètes avec score
Support manette Xbox natif
Compte à rebours de 3 secondes au démarrage

🐛 Dépannage
"make: command not found" dans PowerShell :

Installe Make via Chocolatey (voir Option 2)
Redémarre PowerShell après l'installation

La manette n'est pas détectée :

Vérifie dans Paramètres Windows → Périphériques que la manette apparaît
Teste-la dans "joy.cpl" (tape dans la recherche Windows)
Débrancher/rebrancher peut aider

Erreurs de compilation :

Assure-toi que C:\msys64\mingw64\bin est dans ton PATH
Utilise MSYS2 MINGW64 si PowerShell pose problème
Vérifie que Raylib est installé : pacman -S mingw-w64-x86_64-raylib

"libraylib.dll manquante" au lancement :

Copie libraylib.dll et glfw3.dll depuis C:\msys64\mingw64\bin\ vers le dossier du jeu

Commandes Makefile :
bashmake           # Compile le projet
make clean     # Supprime les fichiers compilés
make rebuild   # Clean puis compile
📝 Notes techniques

Compilé avec GCC (MinGW)
Utilise Raylib 5.0+ pour le graphisme et l'input
FPS : 120 (pour une réactivité optimale)
Résolution : 900x1000

👤 Auteur
Mathéo - 2025

Bon jeu ! 🎮