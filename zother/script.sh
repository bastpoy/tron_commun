#!/bin/sh

MOUNT_POINT="/home/bastpoy/sda_disk"

# Vérifie que le point de montage existe et est monté
while [ ! -d "$MOUNT_POINT" ] || ! grep -qs "$MOUNT_POINT" /proc/mounts; do
    echo "Le disque n'est pas encore monté, en attente..."
    sleep 5
done

echo "Le disque est monté, lancement du script."

cd /home/bastpoy/sda_disk/42/tron_commun/m4/cpp
code .

firefox

gnome-terminal
