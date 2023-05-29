#!/bin/bash
blih -u gaetan.depin@epitech.eu repository create $1
blih -u gaetan.depin@epitech.eu repository setacl $1 ramassage-tek r
blih -u gaetan.depin@epitech.eu repository getacl $1
