#!/bin/bash

FILE="/etc/shadow"

#to check the file's existence
if [ -e $FILE ]
then
    echo "Shadow passwords are enabled"
fi

#to check the file can be writable 
if [ -w $FILE ]
then
    echo "You have permission to edit $FILE"
else
    echo "You do NOT have permissions to edit $FILE"
fi
