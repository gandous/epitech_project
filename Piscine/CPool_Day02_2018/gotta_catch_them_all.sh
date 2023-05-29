#!/bin/bash
cut -d: -f 5 | grep " $1" -i | wc -l
