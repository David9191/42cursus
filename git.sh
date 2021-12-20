#!/bin/bash

echo ">>\"status before add\""
git status

git add .
echo ">>\"complete add all\""

echo ">>\"status after add\""
git status

git commit -m "$(date +%Y)-$(date +%m)-$(date +%d)_$(date +%H):$(date +%M):$(date +%S)"
echo ">>\"complete commit\""

git push
echo ">>\"complete push\""

