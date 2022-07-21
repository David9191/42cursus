#!/bin/bash

cd ~/goinfre

mkdir homebrew && curl -L https://github.com/Homebrew/brew/tarball/master | tar xz --strip 1 -C homebrew

cd ~/goinfre

eval "$(homebrew/bin/brew shellenv)"
brew update --force --quiet
chmod -R go-w "$(brew --prefix)/share/zsh"

export PATH=$HOME/goinfre/homebrew/bin:$PATH

cd ~/goinfre/homebrew && brew install readline && brew info readline