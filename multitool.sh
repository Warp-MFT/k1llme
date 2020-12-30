#!/bin/bash

source setupDb.sh

function help
{
    echo "===================================================================================================="
    echo ""
    echo "Available options"
    echo ""
    echo "[ -d --setup-db ]             Setup local database"
    echo "[ --remove-db ]               Removes all created database schemas and users"
    echo ""
    echo "===================================================================================================="
}

echo
while [ -n "$1" ]
do
    case "$1" in
        -d) setupDataBase ;;
        --setup-db) setupDataBase ;;
        --remove-db) removeDataBase ;;
        -h) help ;;
        --help) help ;;
        *) echo "$1 is not an option" && help ;;
        
    esac
    shift
done
